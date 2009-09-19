/** File: NxOgreWheel.cpp
    Created on: 17-May-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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

                                                                                       
