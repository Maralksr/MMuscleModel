// My Functions

/* Tendon force
* Input: normalized tendon length
* output: normalized tendon force
*/
#include <stdio.h>      /* printf */
#include <math.h> 

double getTendonForce(NormTendonLength)
{
	double cT= 27.8;
	double kT= 0.0047;
	double LrT= 0.964;
	TendonForce= cT * kT * log(exp((NormTendonLength- LrT)/kT)+ 1 ));
	return TendonForce;
}

/* Thick Filament Compression Force (Parallel element)
* input: Normalized Muscle Length
* output: Normalized passive element Force (0-1)
*/

double getThickFilamentCompressionForce(NormMuscleLength)
{
	double c2= -0.02;
	double k2= -21;
	double Lr2=0.70;
	ThickFilamentCompressionForce= c2 * exp((k2 * (NormMuscleLength-Lr2))-1);
	return ThickFilamentCompressionForce;
}

/* Parallel Elastic Element Force
* input:Normalized Muscle Length, and Muscle Velocity
* output: Normalized Passove element Force
*/

double getParallelElasticElementForce(NormMuscleLength, MuscleVelocity)
{
	double c1=23;
	double k1= 0.046;
	double Lr1= 1.17;
	double eta= 0.01;
	ParallelElasticElementForce= c1 * k1 * log(exp(NormMuscleLength-Lr1)/k1 + 1) + eta * MuscleVelocity;
	return ThickFilamentCompressionForce;
}

/*
*Force Velocity Curve
*input: Slow/Fast , NormMuscleLength, MuscleVelocity
*output: Force- Velocity Factor (0-1)
*/
double getForceVelocityCurve(NormMuscleLength, Velocity,FiberType);
{
	if (Velocity >= 0):
	{
		if (MuscleFiber== SlowTwitch):
		{
			double av0= -4.7;
			double av1= 8.41;
			double av1=-5.34;
			double bv= 0.35;
		}
		if (MuscleFiber== SlowTwitch):
		{
			double av0= -1.53;
			double av1=0;
			double av1=0;
			double bv= 0.69;
		}
		ForceVelocityCurve= (bv- (av0 + av1 * NormMuscleLength +av2 * NormMuscleLength ^ 2) * Velocity)/ (bv+ Velocity);
		
	
	
	else if (Velocity < 0):
	{
		if (MuscleFiber== SlowTwitch):
		{
			double MaximumVelocity= -7.88;
			double cv0= 5.88;
			double cv1= 0;
		}
		if (MuscleFiber== SlowTwitch):
		{
			double MaximumVelocity= -9.15;
			double cv0= -5.7;
			double cv1= 9.18;
		}
			
		ForceVelocityCurve= (MaximumVelocity- Velocity)/(MaximumVelocity +(cv0 + cv1 * NormalMuscleLength) * Velocity);
    }

/*
* Force-Length Curve
* input: Normalized Muscle Length, Fiber Type
* output: Force-Length Factor (0-1)
*/
double getForceLengthCurve(NormMuscleLength, FiberType);
{
	if (FiberType== FastTwitch):
	{
		double beta = 1.55;
		double omega = 0.75;
		double rho = 2.12;
	}
	else if (FiberType== SlowTwitch):
	{
		double beta = 2.3;
		double omega = 1.12;
		double rho = 1.62;
    }
	ForceLengthCurve= exp(- abs((NormMuscleLength ^ beta-1)/ omega)^ rho);
	return ForceLengthCurve;
}
