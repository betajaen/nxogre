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

         

#ifndef NXOGRE_WHEEL_H
#define NXOGRE_WHEEL_H

         

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreShape.h"
#include "NxOgreShapeFunctions.h"

         

namespace NxOgre
{

         

/** \brief  
*/ 
class NxOgrePublicClass Wheel : public Shape
{
  
  NXOGRE_GC_FRIEND_NEW2
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  
  unsigned int getShapeType() const;


  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
  Enums::ShapeFunctionType  getShapeFunctionType() const;
    
  /*! function. saveToDescription
      desc.
          Save to a BoxDescription
  */
  void saveToDescription(WheelDescription& description);
  
  /** \brief Sets the radius (distance from axle to contact surface) of the wheel.
      \note  Does not wake up the RigidBody.
  */
  void  setRadius(Real radius);
  
  
  /** \brief Gets the radius (distance from axle to contact surface) of the wheel.
  */
  Real  getRadius() const;
  
  
  /** \brief Sets the maximum extension distance of suspension along shape's -Y axis.
      \note  Does not wake up the RigidBody.
  */
  void  setSuspensionTravel(Real radius);
  
  
  /** \brief Gets the maximum extension distance of suspension along shape's -Y axis.
  */
  Real  getSuspensionTravel() const;
  
  /** \brief Sets the spring intended for the wheel suspension effects.
      \note  Does not wake up the RigidBody.
  */
  void  setSuspension(const SpringDescription&);
  
  
  /** \brief Gets the spring intended for the wheel suspension effects.
  */
  SpringDescription       getSuspension() const;
  
  /** \brief 
      \note  Does not wake up the RigidBody.
  */
  void  setLateralTireForceFunction(const TireFunction&);
  
  
  /** \brief 
  */
  TireFunction            getLateralTireForceFunction() const;
  
  
  /** \brief 
      \note  Does not wake up the RigidBody.
  */
  void  setLongitudalTireForceFunction(const TireFunction&);
  
  
  /** \brief 
  */
  TireFunction  getLongitudalTireForceFunction() const;
  
  /** \brief 
      \note  Does not wake up the RigidBody.
  */
  void  setInverseWheelMass(Real);
  
  
  /** \brief 
  */
  Real  getInverseWheelMass() const;
  
  /** \brief 
      \note  Does not wake up the RigidBody.
  */
  void  setWheelFlags(int);
  
  
  /** \brief 
  */
  int   getWheelFlags() const;
  
  /** \brief Sets the motor torque. Torque must be positive. Body must be awake for this to make any effect.
      \note  Does not wake up the RigidBody.
  */
  void  setMotorTorque(Real);
  
  
  /** \brief Gets the motor torque.
  */
  Real  getMotorTorque() const;
  
  /** \brief Sets the brake torque. Torque must be positive.
      \note  Does not wake up the RigidBody.
  */
  void  setBrakeTorque(Real);
  
  
  /** \brief Gets the brake torque.
  */
  Real  getBrakeTorque() const;
  
  /** \brief Sets the steering angle (in radians)
      \note  Does not wake up the RigidBody.
  */
  void  setSteeringAngle(Radian);
  
  
  /** \brief Gets the steering angle (in radians)
  */
  Radian  getSteeringAngle() const;
  
  /** \brief Set Axle Speed.
      \warning This is an internal state variable. For any effect, the WheelFlags_AxleSpeedOverride must be enabled.
      \note  Does not wake up the RigidBody.
  */
  void  setAxleSpeed(Real);
  
  /** \brief Gets the axle speed.
  */
  Real  getAxleSpeed() const;
#if 0
  /** \brief Set the contact callback.
  */
  void  setCallback();
  
  /** \brief Get the contact callback.
  */
  Callback*               getCallback();
#endif

  /** \brief
  */
  NxWheelShape*           getWheelShape();

  protected:


  protected:

  /*
  */
  Wheel(NxWheelShape*, bool isDirty);
  
  /*
  */
  ~Wheel();
  
  protected:

  NxWheelShape*           mWheelShape;

  
}; // class Wheel

         

} // namespace NxOgre

         

#endif
