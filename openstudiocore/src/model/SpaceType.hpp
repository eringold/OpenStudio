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

#ifndef MODEL_SPACETYPE_HPP
#define MODEL_SPACETYPE_HPP

#include "ModelAPI.hpp"
#include "ResourceObject.hpp"

namespace openstudio {
namespace model {

// forward declarations
class Schedule;
class Space;
class InternalMass;
class People;
class Lights;
class Luminaire;
class ElectricEquipment;
class GasEquipment;
class HotWaterEquipment;
class SteamEquipment;
class OtherEquipment;
class SpaceInfiltrationDesignFlowRate;
class SpaceInfiltrationEffectiveLeakageArea;
class DefaultConstructionSet;
class DefaultScheduleSet;
class DefaultScheduleType;
class RenderingColor;
class DesignSpecificationOutdoorAir;

namespace detail {

  class SpaceType_Impl;

} // detail

/** SpaceType is a ResourceObject that wraps the OpenStudio IDD object 'OS_SpaceType'. */
class MODEL_API SpaceType : public ResourceObject {
 public:
  /** @name Constructors and Destructors */
  //@{

  explicit SpaceType(const Model& model);

  virtual ~SpaceType() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{

  /// Returns the default construction set.
  boost::optional<DefaultConstructionSet> defaultConstructionSet() const;

  /// Returns the default schedule set.
  boost::optional<DefaultScheduleSet> defaultScheduleSet() const;

  /// Returns the rendering color.
  boost::optional<RenderingColor> renderingColor() const;

  /// Returns the standards building type. This is a freeform field used to identify the building type for standards.
  /// Standards applied to this model will use this field to determine correct levels for lighting, occupancy, etc.
  /// More information can be found at https://github.com/NREL/openstudio-standards.
  boost::optional<std::string> standardsBuildingType() const;

  /// If standardsBuildingType is empty, returns a list of suggestions.  If standardsBuildingType is not empty,
  /// returns standardsBuildingType.
  std::vector<std::string> suggestedStandardsBuildingTypes() const;

  /// Returns the standards space type. This is a freeform field used to identify the space type for standards.
  /// Standards applied to this model will use this field to determine correct levels for lighting, occupancy, etc.
  /// More information can be found at https://github.com/NREL/openstudio-standards.
  boost::optional<std::string> standardsSpaceType() const;

  /// If standardsSpaceType is empty, returns a list of suggestions based on standardsBuildingType.  If standardsSpaceType is not empty,
  /// returns standardsSpaceType.
  std::vector<std::string> suggestedStandardsSpaceTypes() const;

  //@}
  /** @name Setters */
  //@{

  /// Sets the default construction set.
  bool setDefaultConstructionSet(const DefaultConstructionSet& defaultConstructionSet);
  
  /// Resets the default construction set.
  void resetDefaultConstructionSet();

  /// Sets the default schedule set.
  bool setDefaultScheduleSet(const DefaultScheduleSet& defaultScheduleSet);

  /// Resets the default schedule set.
  void resetDefaultScheduleSet();

  /// Sets the rendering color.
  bool setRenderingColor(const RenderingColor& renderingColor);

  /// Resets the rendering color.
  void resetRenderingColor();

  /// Sets the standards building type. This is a freeform field used to identify the building type for standards.
  /// Standards applied to this model will use this field to determine correct levels for lighting, occupancy, etc.
  /// More information can be found at https://github.com/NREL/openstudio-standards.
  bool setStandardsBuildingType(const std::string& standardsBuildingType);
  void resetStandardsBuildingType();

  /// Sets the standards space type. This is a freeform field used to identify the space type for standards.
  /// Standards applied to this model will use this field to determine correct levels for lighting, occupancy, etc.
  /// More information can be found at https://github.com/NREL/openstudio-standards.
  bool setStandardsSpaceType(const std::string& standardsSpaceType);
  void resetStandardsSpaceType();

  //@}
  /** @name Other */
  //@{

  /// Get all spaces of this space type, includes spaces that inherit this space type
  std::vector<Space> spaces() const;

  /// Returns the default schedule set for the specified type if available by searching (in order):
  /// This space types's default schedule set
  /// The building's default schedule set
  /// The building's space type's default schedule set
  boost::optional<Schedule> getDefaultSchedule(const DefaultScheduleType& defaultScheduleType) const;

  /// Returns all InternalMass in this space type.
  std::vector<InternalMass> internalMass() const;

  /// Returns all People in this space type.
  std::vector<People> people() const;

  /// Returns all Lights in this space type.
  std::vector<Lights> lights() const;

  /// Returns all \link Luminaire Luminaires \endlink in this space type.
  std::vector<Luminaire> luminaires() const;

  /// Returns all ElectricEquipment in this space type.
  std::vector<ElectricEquipment> electricEquipment() const;

  /// Returns all GasEquipment in this space type.
  std::vector<GasEquipment> gasEquipment() const;

  /// Returns all HotWaterEquipment in this space type.
  std::vector<HotWaterEquipment> hotWaterEquipment() const;

  /// Returns all SteamEquipment in this space type.
  std::vector<SteamEquipment> steamEquipment() const;

  /// Returns all OtherEquipment in this space type.
  std::vector<OtherEquipment> otherEquipment() const;

  /// Returns all SpaceInfiltrationDesignFlowRate objects in this space type.
  std::vector<SpaceInfiltrationDesignFlowRate> spaceInfiltrationDesignFlowRates() const;

  /// Returns all SpaceInfiltrationEffectiveLeakageArea objects in this space type.
  std::vector<SpaceInfiltrationEffectiveLeakageArea> spaceInfiltrationEffectiveLeakageAreas() const;

  /// Returns DesignSpecificationOutdoorAir for this space type.
  boost::optional<DesignSpecificationOutdoorAir> designSpecificationOutdoorAir() const;

  /// Returns true if DesignSpecificationOutdoorAir is not directly specified for this space type.
  bool isDesignSpecificationOutdoorAirDefaulted() const;

  /// Sets DesignSpecificationOutdoorAir for this space type.
  bool setDesignSpecificationOutdoorAir(const DesignSpecificationOutdoorAir& designSpecificationOutdoorAir) ;

  /// Resets DesignSpecificationOutdoorAir for this space type.
  void resetDesignSpecificationOutdoorAir();

  /** Set all schedules for child space loads to their default value if there is one. */
  void hardApplySpaceLoadSchedules();

  /** Returns the total people per space floor area in this space type, if it can be calculated 
   *  directly from the underlying people() data (without knowing floorArea). */
  boost::optional<double> peoplePerFloorArea() const;

  /** Sets the peoplePerFloorArea, using people()[0], if it exists, as a template for the 
   *  remaining People and PeopleDefinition parameters. All other people() in this SpaceType will
   *  be removed. */
  bool setPeoplePerFloorArea(double peoplePerFloorArea);

  /** Sets the peoplePerFloorArea, using templatePeople as a template for the remaining 
   *  People and PeopleDefinition parameters. All people() in this SpaceType (except for 
   *  templatePeople, if applicable), will be removed. */
  bool setPeoplePerFloorArea(double peoplePerFloorArea, const People& templatePeople);

  /** Returns the floor area per person for this space type, if it can be calculated directly 
   *  from the underlying people() data (without knowing floorArea). */
  boost::optional<double> spaceFloorAreaPerPerson() const;

  /** Sets the spaceFloorAreaPerPerson, using people()[0], if it exists, as a template for the 
   *  remaining People and PeopleDefinition parameters. All other people() in this SpaceType will
   *  be removed. */
  bool setSpaceFloorAreaPerPerson(double spaceFloorAreaPerPerson);

  /** Sets the spaceFloorAreaPerPerson, using templatePeople as a template for the remaining 
   *  People and PeopleDefinition parameters. All people() in this SpaceType (except for 
   *  templatePeople, if applicable), will be removed. */
  bool setSpaceFloorAreaPerPerson(double spaceFloorAreaPerPerson, const People& templatePeople);

  double getNumberOfPeople(double floorArea) const;

  double getPeoplePerFloorArea(double floorArea) const;

  double getFloorAreaPerPerson(double floorArea) const;

  /** Returns the total lighting power per space floor area, if possible. Only works if there are
   *  no luminaires in the space type, and if all lights are defined on a per space floor area 
   *  basis. */
  boost::optional<double> lightingPowerPerFloorArea() const;

  /** Sets the lightingPowerPerFloorArea, using lights()[0], if it exists, as a template for
   *  the remaining Lights and LightsDefinition parameters. All other lights() and luminaires() 
   *  in this SpaceType will be removed. */
  bool setLightingPowerPerFloorArea(double lightingPowerPerFloorArea);

  /** Sets the lightingPowerPerFloorArea, using templateLights as a template for the remaining
   *  Lights and LightsDefinition parameters. All lights() and luminaires() in this SpaceType 
   *  (except for templateLights, if applicable), will be removed. */
  bool setLightingPowerPerFloorArea(double lightingPowerPerFloorArea, 
                                         const Lights& templateLights);

  /** Returns the total lighting power per person, if possible. Only works if there are no 
   *  luminaires in the space type, and if all lights are defined on a per person basis. */
  boost::optional<double> lightingPowerPerPerson() const;

  /** Sets the lightingPowerPerPerson, using lights()[0], if it exists, as a template for
   *  the remaining Lights and LightsDefinition parameters. All other lights() and luminaires() 
   *  in this SpaceType will be removed. */
  bool setLightingPowerPerPerson(double lightingPowerPerPerson);

  /** Sets the lightingPowerPerPerson, using templateLights as a template for the remaining
   *  Lights and LightsDefinition parameters. All lights() and luminaires() in this SpaceType 
   *  (except for templateLights, if applicable), will be removed. */
  bool setLightingPowerPerPerson(double lightingPowerPerPerson,const Lights& templateLights);

  /** Returns total lighting power for this space type, including lights and luminaires, assuming
   *  floorArea (m^2) and numPeople. */
  double getLightingPower(double floorArea, double numPeople) const;

  /** Returns the total lighting watts per space floor area for this space type, including lights
   *  and luminaires, assuming floorArea (m^2) and numPeople. */
  double getLightingPowerPerFloorArea(double floorArea, double numPeople) const;

  /** Returns the total lighting watts per person for this space type, including lights and 
   *  luminaires, assuming floorArea (m^2) and numPeople. */
  double getLightingPowerPerPerson(double floorArea, double numPeople) const;

  /** Returns the total electric equipment power per space floor area, if it can be calculated 
   *  directly from the underlying electricEquipment() data (without knowing floorArea and 
   *  numPeople). */
  boost::optional<double> electricEquipmentPowerPerFloorArea() const;

  /** Sets the electricEquipmentPowerPerFloorArea, using electricEquipment()[0], if it existss,
   *  as a template for the reamaining ElectricEquipment and ElectricEquipmentDefinition parameters.
   *  All other electricEquipment() in this SpaceType will be removed. */
  bool setElectricEquipmentPowerPerFloorArea(double electricEquipmentPowerPerFloorArea);

  /** Sets the electricEquipmentPowerPerFloorArea, using templateElectricEquipment as a template
   *  for the remaining ElectricEquipment and ElectricEquipmentDefinition parameters. All other 
   *  electricEquipment() in this SpaceType will be removed. */
  bool setElectricEquipmentPowerPerFloorArea(
      double electricEquipmentPowerPerFloorArea,
      const ElectricEquipment& templateElectricEquipment);

  /** Returns the total electric equipment power per person, if it can be calculated 
   *  directly from the underlying electricEquipment() data (without knowing floorArea and 
   *  numPeople). */
  boost::optional<double> electricEquipmentPowerPerPerson() const;

  /** Sets the electricEquipmentPowerPerPerson, using electricEquipment()[0], if it existss,
   *  as a template for the reamaining ElectricEquipment and ElectricEquipmentDefinition parameters.
   *  All other electricEquipment() in this SpaceType will be removed. */
  bool setElectricEquipmentPowerPerPerson(double electricEquipmentPowerPerPerson);

  /** Sets the electricEquipmentPowerPerPerson, using templateElectricEquipment as a template
   *  for the remaining ElectricEquipment and ElectricEquipmentDefinition parameters. All other 
   *  electricEquipment() in this SpaceType will be removed. */
  bool setElectricEquipmentPowerPerPerson(double electricEquipmentPowerPerPerson,
                                          const ElectricEquipment& templateElectricEquipment);

  double getElectricEquipmentDesignLevel(double floorArea, double numPeople) const;

  double getElectricEquipmentPowerPerFloorArea(double floorArea, double numPeople) const;

  double getElectricEquipmentPowerPerPerson(double floorArea, double numPeople) const;

  /** Returns the total gas equipment power per space floor area, if it can be calculated 
   *  directly from the underlying gasEquipment() data (without knowing floorArea and 
   *  numPeople). */
  boost::optional<double> gasEquipmentPowerPerFloorArea() const;

  /** Sets the gasEquipmentPowerPerFloorArea, using gasEquipment()[0], if it existss,
   *  as a template for the reamaining GasEquipment and GasEquipmentDefinition parameters.
   *  All other gasEquipment() in this SpaceType will be removed. */
  bool setGasEquipmentPowerPerFloorArea(double gasEquipmentPowerPerFloorArea);

  /** Sets the gasEquipmentPowerPerFloorArea, using templateGasEquipment as a template
   *  for the remaining GasEquipment and GasEquipmentDefinition parameters. All other 
   *  gasEquipment() in this SpaceType will be removed. */
  bool setGasEquipmentPowerPerFloorArea(double gasEquipmentPowerPerFloorArea,
                                             const GasEquipment& templateGasEquipment);

  /** Returns the total gas equipment power per person, if it can be calculated directly from 
   *  the underlying gasEquipment() data (without knowing floorArea and numPeople). */
  boost::optional<double> gasEquipmentPowerPerPerson() const;

  /** Sets the gasEquipmentPowerPerPerson, using gasEquipment()[0], if it existss,
   *  as a template for the reamaining GasEquipment and GasEquipmentDefinition parameters.
   *  All other gasEquipment() in this SpaceType will be removed. */
  bool setGasEquipmentPowerPerPerson(double gasEquipmentPowerPerPerson);

  /** Sets the gasEquipmentPowerPerPerson, using templateGasEquipment as a template
   *  for the remaining GasEquipment and GasEquipmentDefinition parameters. All other 
   *  gasEquipment() in this SpaceType will be removed. */
  bool setGasEquipmentPowerPerPerson(double gasEquipmentPowerPerPerson,
                                     const GasEquipment& templateGasEquipment);

  double getGasEquipmentDesignLevel(double floorArea, double numPeople) const;

  double getGasEquipmentPowerPerFloorArea(double floorArea, double numPeople) const;

  double getGasEquipmentPowerPerPerson(double floorArea, double numPeople) const;

  // Returns the floor area in the building using this SpaceType.  Includes Space multipliers.
  double floorArea() const;

  //@}
 protected:
  /// @cond
  typedef detail::SpaceType_Impl ImplType;

  friend class Model;
  friend class openstudio::IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  friend class detail::SpaceType_Impl;

  explicit SpaceType(std::shared_ptr<detail::SpaceType_Impl> impl);

  /// @endcond
 private:

  REGISTER_LOGGER("openstudio.model.SpaceType");
};

/** \relates SpaceType*/
typedef boost::optional<SpaceType> OptionalSpaceType;

/** \relates SpaceType*/
typedef std::vector<SpaceType> SpaceTypeVector;

} // model
} // openstudio

#endif // MODEL_SPACETYPE_HPP

