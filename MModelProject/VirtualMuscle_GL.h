
// INCLUDE
#include <OpenSim/Actuators/osimActuatorsDLL.h>

#include <OpenSim/Simulation/Model/Muscle.h>
/*
The parent class, Muscle.h, provides 
    1. max_isometric_force
    2. optimal_fiber_length
    3. tendon_slack_length
    4. pennation_angle_at_optimal
    5. max_contraction_velocity
*/

//All of the sub-models required for a muscle model:
#include <OpenSim/Actuators/MuscleFirstOrderActivationDynamicModel.h>
#include <OpenSim/Actuators/MuscleFixedWidthPennationModel.h>

#include <OpenSim/Actuators/ActiveForceLengthCurve.h>
#include <OpenSim/Actuators/ForceVelocityCurve.h>
#include <OpenSim/Actuators/FiberForceLengthCurve.h>
#include <OpenSim/Actuators/FiberCompressiveForceLengthCurve.h>
#include <OpenSim/Actuators/FiberCompressiveForceCosPennationCurve.h>
#include <OpenSim/Actuators/TendonForceLengthCurve.h>

namespace OpenSim {

class VirtualMuscle_GL : public Muscle {

//==============================================================================
//                        VirtualMusle_GeraldLoeb
//==============================================================================
{

public:

//==============================================================================
// PROPERTIES
//==============================================================================







//=============================================================================
// Construction
//=============================================================================
VirtualMuscle();

VirtualMuscle(const std::string @aName,
             double aMaxIsometricForce,
			 double aOptimalFiberLength,
			 double aTendonSlackLength,
			 double aPennationAngle,
			 double FastToSlowTwitchProportion= 0.33);
			 
//==============================================================================
// Get Properties
//==============================================================================


double getFiberCompressiveForceLengthMultiplier(SimTK::State& s) const;
double getFiberCompressiveForceCosPennationMultiplier(SimTK::State& s) const;
double getTendonForceMultiplier(SimTK::State& s) const;
double getMass() const;
const MuscleFirstOrderActivationDynamicModel& getActivationModel() const;   //This must be second order

const MuscleFixedWidthPennationModel& getPennationModel() const;  //use millard's model

const ActiveForceLengthCurve& getActiveForceLengthCurve() const;
const ForceVelocityCurve& getForceVelocityCurve() const;
const FiberForceLengthCurve& getFiberForceLengthCurve() const;
const TendonForceLengthCurve& getTendonForceLengthCurve() const;
const FiberCompressiveForceLengthCurve&
        getFiberCompressiveForceLengthCurve() const;

const FiberCompressiveForceCosPennationCurve& 
        getFiberCompressiveForceCosPennationCurve() const;

double getFiberStiffnessAlongTendon(const SimTK::State& s) const;

//==============================================================================
// Set Properties
//==============================================================================


 
    void setActivationModel(
            MuscleFirstOrderActivationDynamicModel& aActivationMdl);  // Second order

 
    void setActiveForceLengthCurve(
            ActiveForceLengthCurve& aActiveForceLengthCurve);


    void setForceVelocityCurve(ForceVelocityCurve& aForceVelocityCurve);


    
    void setFiberForceLengthCurve(
            FiberForceLengthCurve& aFiberForceLengthCurve);
    

    void setTendonForceLengthCurve(
            TendonForceLengthCurve& aTendonForceLengthCurve);

  
    void setFiberCompressiveForceLengthCurve(
            FiberCompressiveForceLengthCurve& 
            aFiberCompressiveForceLengthCurve);

 
    void setFiberCompressiveForceCosPennationCurve(
            FiberCompressiveForceCosPennationCurve& 
            aFiberCompressiveForceCosPennationCurve);


    void setMass(double mass);
	
	
	
	
	
	
	
	
	
	
	
	   void calcAccelerationMuscleInfo(
                  AccelerationMuscleInfo& ami,
                                             double lce, 
                                             double dlce_dt,
                                             double phi,
                                             double dphi_dt,
                                             double tl,
                                             double dtl_dt,
                                             double fal,
                                             double fv,
                                             double fpe,
                                             double fk,
                                             double fcphi,
                                             double fse) const;

private:

}

}