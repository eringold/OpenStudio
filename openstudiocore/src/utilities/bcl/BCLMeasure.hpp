/**********************************************************************
*  Copyright (c) 2008-2015, Alliance for Sustainable Energy.  
*  All rights reserved.
*  
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*  
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*  
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**********************************************************************/

#ifndef UTILITIES_BCL_BCLMEASURE_HPP
#define UTILITIES_BCL_BCLMEASURE_HPP

#include "BCLXML.hpp"
#include "../core/Optional.hpp"
#include "../core/Path.hpp"
#include "../core/Deprecated.hpp"
#include "../data/Attribute.hpp"
#include "../UtilitiesAPI.hpp"

#include <vector>

namespace openstudio{

  class FileReferenceType;

  /** \class MeasureType
   *  \brief Enumeration of the types of BCLMeasure, by input file type.
   *  \details ModelMeasures accept OpenStudio Models as input; EnergyPlusMeasures accept 
   *  EnergyPlus IDF files as input; and UtilityMeasures do not operate on any sort of energy
   *  model. See the OPENSTUDIO_ENUM documentation in utilities/core/Enum.hpp. The actual macro 
   *  call is: 
   *  \code
  OPENSTUDIO_ENUM( MeasureType,
    ((ModelMeasure)(Model Measure)) 
    ((EnergyPlusMeasure)(EnergyPlus Measure)) 
    ((UtilityMeasure)(Utility Measure))
    ((ReportingMeasure)(Reporting Measure)) 
  );
   *  \endcode */
  OPENSTUDIO_ENUM( MeasureType,
    ((ModelMeasure)(Model Measure)) 
    ((EnergyPlusMeasure)(EnergyPlus Measure)) 
    ((UtilityMeasure)(Utility Measure))
    ((ReportingMeasure)(Reporting Measure)) 
  );

  OPENSTUDIO_ENUM( MeasureBadgeType,
    ((BCLMeasure))
    ((MyMeasure))
  );

  


  /** BCLMeasure is a class for managing the contents of a BCL Measure directory including the xml description file.
  **/
  class UTILITIES_API BCLMeasure {
  public:

    /** @name Constructors */
    //@{

    /// Constructor for a new measure with required data
    /// Will throw exception unless dir is a directory that does not exist or an empty directory.
    /// A template measure will be created, including a blank user script.
    BCLMeasure(const std::string& name,
               const std::string& className,
               const openstudio::path& dir,
               const std::string& taxonomyTag,
               MeasureType measureType, 
               const std::string& description,
               const std::string& modelerDescription);

    /// Constructor for downloaded measures, path is to directory containing "measure.xml" file
    /// Will throw exception if directory does not exist or does not represent a valid measure.
    BCLMeasure(const openstudio::path& dir);

    /// Convert a measure name to a valid Ruby class name
    static std::string makeClassName(const std::string& name);

    /// Try to load a BCLMeasure from a directory containing a "measure.xml" file.
    static boost::optional<BCLMeasure> load(const openstudio::path& dir);

    /// Load all measures in the PAT application's measures directory.
    static std::vector<BCLMeasure> patApplicationMeasures();

    static BCLMeasure alternativeModelMeasure();

    static BCLMeasure reportRequestMeasure();

    static BCLMeasure standardReportMeasure();

    static BCLMeasure calibrationReportMeasure();

    /// Returns the path to the PAT application's measures directory.
    static openstudio::path patApplicationMeasuresDir();

    /// Load all measures in the local BCL.
    static std::vector<BCLMeasure> localBCLMeasures();

    /// Load all measures in the user measures directory.
    static std::vector<BCLMeasure> userMeasures();

    /// Returns the path to the user measures directory stored in settings.
    static openstudio::path userMeasuresDir();

    /// Changes the path to the user measures directory stored in settings.
    static bool setUserMeasuresDir(const openstudio::path& userMeasuresDir);

    /// Clears the path to the user measures directory stored in settings.
    static void clearUserMeasuresDir();

    /// Suggested values for "Intended Software Tool" attribute
    static std::vector<std::string> suggestedIntendedSoftwareTools();

    /// Suggested values for "Intended Use Case" attribute
    static std::vector<std::string> suggestedIntendedUseCases();

    //@}
    /** @name Destructor */
    //@{

    /// Virtual destructor
    virtual ~BCLMeasure();

    //@}
    /** @name Getters */
    //@{

    openstudio::path directory() const;

    boost::optional<std::string> error() const;

    std::string uid() const;

    UUID uuid() const;

    std::string versionId() const;

    UUID versionUUID() const;

    std::string xmlChecksum() const;

    std::string name() const;

    std::string displayName() const;

    std::string className() const;

    std::string description() const;

    std::string modelerDescription() const;

    std::vector <BCLMeasureArgument> arguments() const;

    // ETH: provenance?
    // DLM: we can do this later

    std::vector<std::string> tags() const;

    std::vector<Attribute> attributes() const;

    std::vector<BCLFileReference> files() const;


    //@}
    /** @name Setters */
    //@{

    void setError(const std::string& error);

    void resetError();

    void setName(const std::string& name);

    void setDisplayName(const std::string& displayName);

    void setClassName(const std::string& className);

    void setDescription(const std::string& description);

    void setModelerDescription(const std::string& modelerDescription);

    void setArguments(const std::vector<BCLMeasureArgument>& arguments);


    //@}
    /** @name Operators */
    //@{

    /// Returns the single taxonomy tag allowed
    std::string taxonomyTag() const;

    // DLM: might want to deprecate this as this is set manually in XML
    /// Sets the single taxonomy tag allowed
    void setTaxonomyTag(const std::string& taxonomyTag);

    /// Returns value of the "Measure Type" attribute
    MeasureType measureType() const;

    /// Sets value of the "Measure Type" attribute
    void setMeasureType(const MeasureType& measureType);

    /// Returns values of any "Intended Software Tool" attributes
    std::vector<std::string> intendedSoftwareTools() const;

    /// Returns values of any "Intended Use Case" attributes
    std::vector<std::string> intendedUseCases() const;

    /** Returns the path of the primary Ruby script if the file exists and is
    *  a regular file. Otherwise returns boost::none. */
    boost::optional<openstudio::path> primaryRubyScriptPath() const;

    /// Returns the input file type for this measure
    FileReferenceType inputFileType() const;

    /// Returns the output file type for this measure
    FileReferenceType outputFileType() const;

    /// Clears all files
    void clearFiles();

    /// Adds attribute to attribute list
    void addAttribute(const Attribute& attribute);

    /// get attributes by name
    std::vector<Attribute> getAttributes(const std::string& name) const;

    /// Removes attribute by name, returns true if attribute was found and removed
    bool removeAttributes(const std::string& name);

    /// Removes all attributes
    void clearAttributes();

    /// Check for updates to files, will increment versionID and return true
    /// if any files have changed, been added, or removed from the measure
    /// The measure must still be saved to disk to preserve the new versionID
    /// Typical usage is 1) checkForUpdatesFiles, 2) update content using embedded ruby interpreter, 3) checkForUpdatesXML
    bool checkForUpdatesFiles();

    /// Check for updates to the xml, will increment versionID and xmlChecksum then return true
    /// if any xml fields (other than uid, version id, or xml checksum) have changed 
    /// The xml file must still be saved to disk to preserve the new versionID
    bool checkForUpdatesXML();

    /// Equality test - Compares the uids and versionIds of two separate measures
    bool operator==(const BCLMeasure& other) const;

    bool operator!=(const BCLMeasure& other) const;

    /// Save the measure.xml back to the directory
    bool save() const;

    /// Clone the measure from the original location to the new location
    /// newDir is a directory which either does not exist or is empty
    /// If the copy is successful a new BCLMeasure is returned
    boost::optional<BCLMeasure> clone(const openstudio::path& newDir) const;

    /// Change the UID for this measure
    void changeUID();

    /// Change the Version ID for this measure
    void incrementVersionId();

    /// Update's the ruby measure script to have this new information
    bool updateMeasureScript(const MeasureType& oldMeasureType, const MeasureType& newMeasureType,
                             const std::string& oldClassName, const std::string& newClassName,
                             const std::string& name, const std::string& description, const std::string& modelerDescription);

    /// Update's the ruby measure tests to have this new information
    bool updateMeasureTests(const std::string& oldClassName, const std::string& newClassName);

  //@}
  private:
    // configure logging
    REGISTER_LOGGER("utilities.bcl.BCLMeasure");

    static std::vector<BCLMeasure> getMeasuresInDir(openstudio::path dir);

    void createDirectory(const openstudio::path& dir);

    std::string computeXMLChecksum() const;

    openstudio::path m_directory;
    BCLXML m_bclXML;
  };

  typedef boost::optional<BCLMeasure> OptionalBCLMeasure;

  typedef std::vector<BCLMeasure> BCLMeasureVector;

} // openstudio

#endif // UTILITIES_BCL_BCLMEASURE_HPP
