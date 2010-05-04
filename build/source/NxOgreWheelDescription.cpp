/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
*/

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreWheelDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

WheelDescription::WheelDescription()
{
 reset();
}

WheelDescription::~WheelDescription()
{
}


void WheelDescription::reset()
{
 ShapeDescription::reset();
 
 mRadius = 1.0;
 mInverseWheelMass = 1.0;
 mSuspensionTravel = 0;
 mWheelFlags = 0;
 mMotorTorque = 0;
 mBrakeTorque = 0;
 mSteeringAngle = 0;
 mContactModifier = 0;
}


NxShapeDesc* WheelDescription::createShapeDescription() const
{
 
 NxWheelShapeDesc* description = NXOGRE_NEW_PHYSX(NxWheelShapeDesc, PhysXClassAllocator);
 setShapeDescription(description);
 
  description->radius = mRadius;
  description->suspensionTravel = mSuspensionTravel;
  description->suspension.damper = mSuspension.mDamper;
  description->suspension.spring = mSuspension.mSpring;
  description->suspension.targetValue = mSuspension.mTargetValue;
  description->longitudalTireForceFunction.asymptoteSlip = mLongitudalTireFunction.mAsymptoteSlip;
  description->longitudalTireForceFunction.asymptoteValue = mLongitudalTireFunction.mAsymptoteValue;
  description->longitudalTireForceFunction.extremumSlip = mLongitudalTireFunction.mExtremumSlip;
  description->longitudalTireForceFunction.extremumValue = mLongitudalTireFunction.mExtremumValue;
  description->longitudalTireForceFunction.stiffnessFactor = mLongitudalTireFunction.mStiffnessFactor;
  description->lateralTireForceFunction.asymptoteSlip = mLateralTireFunction.mAsymptoteSlip;
  description->lateralTireForceFunction.asymptoteValue = mLateralTireFunction.mAsymptoteValue;
  description->lateralTireForceFunction.extremumSlip = mLateralTireFunction.mExtremumSlip;
  description->lateralTireForceFunction.extremumValue = mLateralTireFunction.mExtremumValue;
  description->lateralTireForceFunction.stiffnessFactor = mLateralTireFunction.mStiffnessFactor;
  description->inverseWheelMass = mInverseWheelMass;
  description->wheelFlags = mWheelFlags;
  description->motorTorque = mMotorTorque;
  description->brakeTorque = mBrakeTorque;
  description->steerAngle = mSteeringAngle;


 return description;

}

                                                                                       

} // namespace NxOgre

                                                                                       
