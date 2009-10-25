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
#include "NxOgreShapeBlueprint.h"
#include "NxOgreWheelBlueprint.h"
#include "NxOgreSpringDescription.h"
#include "NxOgreTireFunction.h"
#include "NxOgreFunctions.h"
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

NxOgre::WheelBlueprint NxOgre::Wheel::DefaultWheelBlueprint;

                                                                                       

namespace NxOgre
{

                                                                                       

Wheel::Wheel(WheelBlueprint* blueprint)
: Shape(blueprint), mWheelShape(0)
{
}

Wheel::~Wheel(void)
{
}

unsigned int Wheel::getShapeType() const
{
 return Classes::_Wheel;
}

NxShapeDesc* Wheel::create(void)
{
 
 NxWheelShapeDesc* wheel = new NxWheelShapeDesc();
  
 createAbstract(wheel);

 WheelBlueprint* blueprint = static_cast<WheelBlueprint*>(mBlueprint);

 wheel->radius = blueprint->mRadius;

 wheel->suspensionTravel = blueprint->mSuspensionTravel;

 wheel->inverseWheelMass = blueprint->mInverseWheelMass;

 wheel->wheelFlags = blueprint->mWheelFlags;
 wheel->motorTorque = blueprint->mMotorTorque;
 wheel->brakeTorque = blueprint->mBrakeTorque;
 wheel->steerAngle = blueprint->mSteeringAngle;

 wheel->wheelContactModify = 0; //!< \brief TO IMPLEMENT.
 wheel->suspension.damper = blueprint->mSuspension.mDamper;
 wheel->suspension.spring = blueprint->mSuspension.mSpring;
 wheel->suspension.targetValue = blueprint->mSuspension.mTargetValue;

 wheel->longitudalTireForceFunction.asymptoteSlip = blueprint->mLongitudalTireFunction.mAsymptoteSlip;
 wheel->longitudalTireForceFunction.asymptoteValue = blueprint->mLongitudalTireFunction.mAsymptoteValue;
 wheel->longitudalTireForceFunction.extremumSlip = blueprint->mLongitudalTireFunction.mExtremumSlip;
 wheel->longitudalTireForceFunction.asymptoteValue = blueprint->mLongitudalTireFunction.mExtremumValue;
 wheel->longitudalTireForceFunction.stiffnessFactor = blueprint->mLongitudalTireFunction.mStiffnessFactor;

 wheel->lateralTireForceFunction.asymptoteSlip = blueprint->mLateralTireFunction.mAsymptoteSlip;
 wheel->lateralTireForceFunction.asymptoteValue = blueprint->mLateralTireFunction.mAsymptoteValue;
 wheel->lateralTireForceFunction.extremumSlip = blueprint->mLateralTireFunction.mExtremumSlip;
 wheel->lateralTireForceFunction.asymptoteValue = blueprint->mLateralTireFunction.mExtremumValue;
 wheel->lateralTireForceFunction.stiffnessFactor = blueprint->mLateralTireFunction.mStiffnessFactor;

 return wheel;
}

void Wheel::assign(NxShape* wheel)
{
 assignAbstract(wheel);
 mWheelShape = wheel->isWheel();
}

Enums::ShapeFunctionType Wheel::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Wheel;
}

void Wheel::setRadius(Real radius)
{
 if (mWheelShape)
  mWheelShape->setRadius(radius);
 else
  static_cast<WheelBlueprint*>(mBlueprint)->mRadius = radius;
}

Real Wheel::getRadius(void) const
{
 if (mWheelShape)
  return mWheelShape->getRadius();
 else
  return static_cast<WheelBlueprint*>(mBlueprint)->mRadius;
}

void Wheel::setSuspensionTravel(Real travel)
{
 if (mWheelShape)
  mWheelShape->setSuspensionTravel(travel);
 else
  static_cast<WheelBlueprint*>(mBlueprint)->mSuspensionTravel = travel;
}

Real Wheel::getSuspensionTravel(void) const
{
 if (mWheelShape)
  return mWheelShape->getSuspensionTravel();
 else
  return static_cast<WheelBlueprint*>(mBlueprint)->mSuspensionTravel;
}

void Wheel::setSuspension(const SpringDescription& description)
{
 if (mWheelShape)
 {
  NxSpringDesc desc;
  desc.damper = description.mDamper;
  desc.spring = description.mSpring;
  desc.targetValue = description.mTargetValue;
  mWheelShape->setSuspension(desc);
 }
 else
 {
  static_cast<WheelBlueprint*>(mBlueprint)->mSuspension = description;
 }
}

SpringDescription Wheel::getSuspension(void) const
{
 if (mWheelShape)
 {
  NxSpringDesc description = mWheelShape->getSuspension();
  SpringDescription desc;
  desc.mDamper = description.damper;
  desc.mSpring = description.spring;
  desc.mTargetValue = description.targetValue;
  return desc;
 }
 else
 {
  return static_cast<WheelBlueprint*>(mBlueprint)->mSuspension;
 }
}

void Wheel::setLateralTireForceFunction(const TireFunction& function)
{
 if (mWheelShape)
 {
  NxTireFunctionDesc func;
  func.asymptoteSlip = function.mAsymptoteSlip;
  func.asymptoteValue = function.mAsymptoteValue;
  func.extremumSlip = function.mExtremumSlip;
  func.extremumValue = function.mExtremumValue;
  func.stiffnessFactor = function.mStiffnessFactor;
  mWheelShape->setLateralTireForceFunction(func);
 }
 else
 {
  static_cast<WheelBlueprint*>(mBlueprint)->mLateralTireFunction = function;
 }
}

TireFunction Wheel::getLateralTireForceFunction(void) const
{
 if (mWheelShape)
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
 else
 {
  return static_cast<WheelBlueprint*>(mBlueprint)->mLateralTireFunction;
 }
}

void Wheel::setLongitudalTireForceFunction(const TireFunction& function)
{
 if (mWheelShape)
 {
  NxTireFunctionDesc func;
  func.asymptoteSlip = function.mAsymptoteSlip;
  func.asymptoteValue = function.mAsymptoteValue;
  func.extremumSlip = function.mExtremumSlip;
  func.extremumValue = function.mExtremumValue;
  func.stiffnessFactor = function.mStiffnessFactor;
  mWheelShape->setLongitudalTireForceFunction(func);
 }
 else
 {
  static_cast<WheelBlueprint*>(mBlueprint)->mLongitudalTireFunction = function;
 }
}

TireFunction Wheel::getLongitudalTireForceFunction(void) const
{
 if (mWheelShape)
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
 else
 {
  return static_cast<WheelBlueprint*>(mBlueprint)->mLongitudalTireFunction;
 }
}

void Wheel::setInverseWheelMass(Real invMass)
{
 if (mWheelShape)
  mWheelShape->setInverseWheelMass(invMass);
 else
  static_cast<WheelBlueprint*>(mBlueprint)->mInverseWheelMass = invMass;
}

Real Wheel::getInverseWheelMass(void) const
{
 if (mWheelShape)
  return mWheelShape->getInverseWheelMass();
 else
  return static_cast<WheelBlueprint*>(mBlueprint)->mInverseWheelMass;
}

void  Wheel::setWheelFlags(int flags)
{
 if (mWheelShape)
  mWheelShape->setWheelFlags(flags);
 else
  static_cast<WheelBlueprint*>(mBlueprint)->mWheelFlags = flags;
}

int Wheel::getWheelFlags(void) const
{
 if (mWheelShape)
  return mWheelShape->getWheelFlags();
 else
  return static_cast<WheelBlueprint*>(mBlueprint)->mWheelFlags;
}

void Wheel::setMotorTorque(Real torque)
{
 if (mWheelShape)
  mWheelShape->setMotorTorque(torque);
 else
  static_cast<WheelBlueprint*>(mBlueprint)->mMotorTorque = torque;
}

Real Wheel::getMotorTorque(void) const
{
 if (mWheelShape)
  return mWheelShape->getMotorTorque();
 else
  return static_cast<WheelBlueprint*>(mBlueprint)->mMotorTorque;
}

void Wheel::setBrakeTorque(Real torque)
{
 if (mWheelShape)
  mWheelShape->setBrakeTorque(torque);
 else
  static_cast<WheelBlueprint*>(mBlueprint)->mBrakeTorque = torque;
}

Real Wheel::getBrakeTorque(void) const
{
 if (mWheelShape)
  return mWheelShape->getBrakeTorque();
 else
  return static_cast<WheelBlueprint*>(mBlueprint)->mBrakeTorque;
}

void Wheel::setSteeringAngle(Real angle)
{
 if (mWheelShape)
  mWheelShape->setSteerAngle(angle);
 else
  static_cast<WheelBlueprint*>(mBlueprint)->mSteeringAngle = angle;
}

Real Wheel::getSteeringAngle(void) const
{
 if (mWheelShape)
  return mWheelShape->getSteerAngle();
 else
  return static_cast<WheelBlueprint*>(mBlueprint)->mSteeringAngle;
}

void Wheel::setAxleSpeed(Real speed)
{
 if (mWheelShape)
  mWheelShape->setAxleSpeed(speed);
}

Real Wheel::getAxleSpeed(void) const
{
 if (mWheelShape)
  return mWheelShape->getAxleSpeed();
 return 0;
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

                                                                                       

} // namespace NxOgre

                                                                                       
