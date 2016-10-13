/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2016, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#ifndef MODEL_GENERATORFUELCELLSTACKCOOLER_IMPL_HPP
#define MODEL_GENERATORFUELCELLSTACKCOOLER_IMPL_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject_Impl.hpp"

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class Connection;
class Connection;

namespace detail {

  /** GeneratorFuelCellStackCooler_Impl is a ModelObject_Impl that is the implementation class for GeneratorFuelCellStackCooler.*/
  class MODEL_API GeneratorFuelCellStackCooler_Impl : public ModelObject_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    GeneratorFuelCellStackCooler_Impl(const IdfObject& idfObject,
                                      Model_Impl* model,
                                      bool keepHandle);

    GeneratorFuelCellStackCooler_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                      Model_Impl* model,
                                      bool keepHandle);

    GeneratorFuelCellStackCooler_Impl(const GeneratorFuelCellStackCooler_Impl& other,
                                      Model_Impl* model,
                                      bool keepHandle);

    virtual ~GeneratorFuelCellStackCooler_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    // TODO: Check return type. From object lists, some candidates are: Connection.
    boost::optional<Connection> heatRecoveryWaterInletNode() const;

    // TODO: Check return type. From object lists, some candidates are: Connection.
    boost::optional<Connection> heatRecoveryWaterOutletNode() const;

    boost::optional<double> nominalStackTemperature() const;

    boost::optional<double> actualStackTemperature() const;

    boost::optional<double> coefficientr0() const;

    boost::optional<double> coefficientr1() const;

    boost::optional<double> coefficientr2() const;

    boost::optional<double> coefficientr3() const;

    boost::optional<double> stackCoolantFlowRate() const;

    boost::optional<double> stackCoolerUFactorTimesAreaValue() const;

    boost::optional<double> fscogenAdjustmentFactor() const;

    boost::optional<double> stackCogenerationExchangerArea() const;

    boost::optional<double> stackCogenerationExchangerNominalFlowRate() const;

    boost::optional<double> stackCogenerationExchangerNominalHeatTransferCoefficient() const;

    boost::optional<double> stackCogenerationExchangerNominalHeatTransferCoefficientExponent() const;

    boost::optional<double> stackCoolerPumpPower() const;

    boost::optional<double> stackCoolerPumpHeatLossFraction() const;

    boost::optional<double> stackAirCoolerFanCoefficientf0() const;

    boost::optional<double> stackAirCoolerFanCoefficientf1() const;

    boost::optional<double> stackAirCoolerFanCoefficientf2() const;

    //@}
    /** @name Setters */
    //@{

    // TODO: Check argument type. From object lists, some candidates are: Connection.
    bool setHeatRecoveryWaterInletNode(const Connection& connection);

    void resetHeatRecoveryWaterInletNode();

    // TODO: Check argument type. From object lists, some candidates are: Connection.
    bool setHeatRecoveryWaterOutletNode(const Connection& connection);

    void resetHeatRecoveryWaterOutletNode();

    void setNominalStackTemperature(double nominalStackTemperature);

    void resetNominalStackTemperature();

    void setActualStackTemperature(double actualStackTemperature);

    void resetActualStackTemperature();

    void setCoefficientr0(double coefficientr0);

    void resetCoefficientr0();

    void setCoefficientr1(double coefficientr1);

    void resetCoefficientr1();

    void setCoefficientr2(double coefficientr2);

    void resetCoefficientr2();

    void setCoefficientr3(double coefficientr3);

    void resetCoefficientr3();

    void setStackCoolantFlowRate(double stackCoolantFlowRate);

    void resetStackCoolantFlowRate();

    void setStackCoolerUFactorTimesAreaValue(double stackCoolerUFactorTimesAreaValue);

    void resetStackCoolerUFactorTimesAreaValue();

    void setFscogenAdjustmentFactor(double fscogenAdjustmentFactor);

    void resetFscogenAdjustmentFactor();

    void setStackCogenerationExchangerArea(double stackCogenerationExchangerArea);

    void resetStackCogenerationExchangerArea();

    void setStackCogenerationExchangerNominalFlowRate(double stackCogenerationExchangerNominalFlowRate);

    void resetStackCogenerationExchangerNominalFlowRate();

    void setStackCogenerationExchangerNominalHeatTransferCoefficient(double stackCogenerationExchangerNominalHeatTransferCoefficient);

    void resetStackCogenerationExchangerNominalHeatTransferCoefficient();

    void setStackCogenerationExchangerNominalHeatTransferCoefficientExponent(double stackCogenerationExchangerNominalHeatTransferCoefficientExponent);

    void resetStackCogenerationExchangerNominalHeatTransferCoefficientExponent();

    void setStackCoolerPumpPower(double stackCoolerPumpPower);

    void resetStackCoolerPumpPower();

    bool setStackCoolerPumpHeatLossFraction(double stackCoolerPumpHeatLossFraction);

    void resetStackCoolerPumpHeatLossFraction();

    void setStackAirCoolerFanCoefficientf0(double stackAirCoolerFanCoefficientf0);

    void resetStackAirCoolerFanCoefficientf0();

    void setStackAirCoolerFanCoefficientf1(double stackAirCoolerFanCoefficientf1);

    void resetStackAirCoolerFanCoefficientf1();

    void setStackAirCoolerFanCoefficientf2(double stackAirCoolerFanCoefficientf2);

    void resetStackAirCoolerFanCoefficientf2();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.GeneratorFuelCellStackCooler");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_GENERATORFUELCELLSTACKCOOLER_IMPL_HPP

