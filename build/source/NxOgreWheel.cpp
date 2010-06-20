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

                                                                                       

Wheel::Wheel(NxWheelShape* wheel_shape, bool isDirty)
: Shape(wheel_shape, isDirty), mWheelShape(wheel_shape)
{
}

Wheel::~Wheel()
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

Real Wheel::getRadius() const
{
  return mWheelShape->getRadius();
}

void Wheel::setSuspensionTravel(Real travel)
{
 mWheelShape->setSuspensionTravel(travel);
}

Real Wheel::getSuspensionTravel() const
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

SpringDescription Wheel::getSuspension() const
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

TireFunction Wheel::getLateralTireForceFunction() const
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

TireFunction Wheel::getLongitudalTireForceFunction() const
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

Real Wheel::getInverseWheelMass() const
{
  return mWheelShape->getInverseWheelMass();
}

void  Wheel::setWheelFlags(int flags)
{
  mWheelShape->setWheelFlags(flags);
}

int Wheel::getWheelFlags() const
{
  return mWheelShape->getWheelFlags();
}

void Wheel::setMotorTorque(Real torque)
{
  mWheelShape->setMotorTorque(torque);
}

Real Wheel::getMotorTorque() const
{
 return mWheelShape->getMotorTorque();
}

void Wheel::setBrakeTorque(Real torque)
{
 mWheelShape->setBrakeTorque(torque);
}

Real Wheel::getBrakeTorque() const
{
 return mWheelShape->getBrakeTorque();
}

void Wheel::setSteeringAngle(Radian angle)
{
 mWheelShape->setSteerAngle(angle);
}

Radian Wheel::getSteeringAngle() const
{
 return mWheelShape->getSteerAngle();
}

void Wheel::setAxleSpeed(Real speed)
{
 mWheelShape->setAxleSpeed(speed);
}

Real Wheel::getAxleSpeed() const
{
 return mWheelShape->getAxleSpeed();
}
#if 0
void Wheel::setCallback()
{
}

Callback* Wheel::getCallback()
{
}
#endif

NxWheelShape* Wheel::getWheelShape()
{
 return mWheelShape;
}


                                                                                       

} // namespace NxOgre

                                                                                       
