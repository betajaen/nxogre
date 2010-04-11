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
#include "NxOgreWheel.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreWheelDescription.h"
#include "NxOgreSpringDescription.h"
#include "NxOgreTireFunction.h"
#include "NxOgreFunctions.h"
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Wheel::Wheel(NxWheelShape* wheel_shape)
: Shape(wheel_shape), mWheelShape(wheel_shape)
{
}

Wheel::~Wheel(void)
{
}

unsigned int Wheel::getShapeType() const
{
 return Classes::_Wheel;
}

Enums::ShapeFunctionType Wheel::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Wheel;
}

void Wheel::setRadius(Real radius)
{
 mWheelShape->setRadius(radius);
}

Real Wheel::getRadius(void) const
{
  return mWheelShape->getRadius();
}

void Wheel::setSuspensionTravel(Real travel)
{
 mWheelShape->setSuspensionTravel(travel);
}

Real Wheel::getSuspensionTravel(void) const
{
 return mWheelShape->getSuspensionTravel();
}

void Wheel::setSuspension(const SpringDescription& description)
{
  NxSpringDesc desc;
  desc.damper = description.mDamper;
  desc.spring = description.mSpring;
  desc.targetValue = description.mTargetValue;
  mWheelShape->setSuspension(desc);
}

SpringDescription Wheel::getSuspension(void) const
{
  NxSpringDesc description = mWheelShape->getSuspension();
  SpringDescription desc;
  desc.mDamper = description.damper;
  desc.mSpring = description.spring;
  desc.mTargetValue = description.targetValue;
  return desc;
}

void Wheel::setLateralTireForceFunction(const TireFunction& function)
{
  NxTireFunctionDesc func;
  func.asymptoteSlip = function.mAsymptoteSlip;
  func.asymptoteValue = function.mAsymptoteValue;
  func.extremumSlip = function.mExtremumSlip;
  func.extremumValue = function.mExtremumValue;
  func.stiffnessFactor = function.mStiffnessFactor;
  mWheelShape->setLateralTireForceFunction(func);
}

TireFunction Wheel::getLateralTireForceFunction(void) const
{
  NxTireFunctionDesc function = mWheelShape->getLateralTireForceFunction();
  TireFunction func;
  func.mAsymptoteSlip = function.asymptoteSlip;
  func.mAsymptoteValue = function.asymptoteValue;
  func.mExtremumSlip = function.extremumSlip;
  func.mExtremumValue = function.extremumValue;
  func.mStiffnessFactor = function.stiffnessFactor;
  return func;
}

void Wheel::setLongitudalTireForceFunction(const TireFunction& function)
{
  NxTireFunctionDesc func;
  func.asymptoteSlip = function.mAsymptoteSlip;
  func.asymptoteValue = function.mAsymptoteValue;
  func.extremumSlip = function.mExtremumSlip;
  func.extremumValue = function.mExtremumValue;
  func.stiffnessFactor = function.mStiffnessFactor;
  mWheelShape->setLongitudalTireForceFunction(func);
}

TireFunction Wheel::getLongitudalTireForceFunction(void) const
{
  NxTireFunctionDesc function = mWheelShape->getLongitudalTireForceFunction();
  TireFunction func;
  func.mAsymptoteSlip = function.asymptoteSlip;
  func.mAsymptoteValue = function.asymptoteValue;
  func.mExtremumSlip = function.extremumSlip;
  func.mExtremumValue = function.extremumValue;
  func.mStiffnessFactor = function.stiffnessFactor;
  return func;
}

void Wheel::setInverseWheelMass(Real invMass)
{
  mWheelShape->setInverseWheelMass(invMass);
}

Real Wheel::getInverseWheelMass(void) const
{
  return mWheelShape->getInverseWheelMass();
}

void  Wheel::setWheelFlags(int flags)
{
  mWheelShape->setWheelFlags(flags);
}

int Wheel::getWheelFlags(void) const
{
  return mWheelShape->getWheelFlags();
}

void Wheel::setMotorTorque(Real torque)
{
  mWheelShape->setMotorTorque(torque);
}

Real Wheel::getMotorTorque(void) const
{
 return mWheelShape->getMotorTorque();
}

void Wheel::setBrakeTorque(Real torque)
{
 mWheelShape->setBrakeTorque(torque);
}

Real Wheel::getBrakeTorque(void) const
{
 return mWheelShape->getBrakeTorque();
}

void Wheel::setSteeringAngle(Radian angle)
{
 mWheelShape->setSteerAngle(angle);
}

Radian Wheel::getSteeringAngle(void) const
{
 return mWheelShape->getSteerAngle();
}

void Wheel::setAxleSpeed(Real speed)
{
 mWheelShape->setAxleSpeed(speed);
}

Real Wheel::getAxleSpeed(void) const
{
 return mWheelShape->getAxleSpeed();
}
#if 0
void Wheel::setCallback(void)
{
}

Callback* Wheel::getCallback(void)
{
}
#endif

NxWheelShape* Wheel::getWheelShape()
{
 return mWheelShape;
}

void Wheel::saveToDescription(WheelDescription& description)
{
 NxWheelShapeDesc desc;
 mWheelShape->saveToDesc(desc);
 description.mDensity = desc.density;
 description.mFlags = desc.shapeFlags;
 description.mGroup = desc.group;
 description.mGroupsMask.mBits0 = desc.groupsMask.bits0;
 description.mGroupsMask.mBits1 = desc.groupsMask.bits1;
 description.mGroupsMask.mBits2 = desc.groupsMask.bits2;
 description.mGroupsMask.mBits3 = desc.groupsMask.bits3;
 desc.localPose.getRowMajor44(description.mLocalPose.ptr());
 description.mMass = desc.mass;
 description.mMaterial = desc.materialIndex;
 description.mNonInteractingCompartmentTypes = desc.nonInteractingCompartmentTypes;
 description.mSkinWidth = desc.skinWidth;
 
 description.mRadius = desc.radius;
 description.mSuspensionTravel = desc.suspensionTravel;
 description.mSuspension.mDamper = desc.suspension.damper;
 description.mSuspension.mSpring = desc.suspension.spring;
 description.mSuspension.mTargetValue = desc.suspension.targetValue;
 description.mLongitudalTireFunction.mAsymptoteSlip = desc.longitudalTireForceFunction.asymptoteSlip;
 description.mLongitudalTireFunction.mAsymptoteValue = desc.longitudalTireForceFunction.asymptoteValue;
 description.mLongitudalTireFunction.mExtremumSlip = desc.longitudalTireForceFunction.extremumSlip;
 description.mLongitudalTireFunction.mExtremumValue = desc.longitudalTireForceFunction.extremumValue;
 description.mLongitudalTireFunction.mStiffnessFactor = desc.longitudalTireForceFunction.stiffnessFactor;
 description.mLateralTireFunction.mAsymptoteSlip = desc.lateralTireForceFunction.asymptoteSlip;
 description.mLateralTireFunction.mAsymptoteValue = desc.lateralTireForceFunction.asymptoteValue;
 description.mLateralTireFunction.mExtremumSlip = desc.lateralTireForceFunction.extremumSlip;
 description.mLateralTireFunction.mExtremumValue = desc.lateralTireForceFunction.extremumValue;
 description.mLateralTireFunction.mStiffnessFactor = desc.lateralTireForceFunction.stiffnessFactor;
 description.mInverseWheelMass = desc.inverseWheelMass;
 description.mWheelFlags = desc.wheelFlags;
 description.mMotorTorque = desc.motorTorque;
 description.mBrakeTorque = desc.brakeTorque;
 description.mSteeringAngle = desc.steerAngle;
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
