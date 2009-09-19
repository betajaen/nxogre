/** File: NxOgreWheel.h
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

#ifndef NXOGRE_WHEEL_H
#define NXOGRE_WHEEL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass Wheel : public PointerClass<Classes::_Wheel>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_Wheel>::operator new;

  using ::NxOgre::PointerClass<Classes::_Wheel>::operator delete;

  using ::NxOgre::PointerClass<Classes::_Wheel>::getClassType;

  
  /** \brief Wheel constructor with width, height, depth size argument as a Vec3.
      \note  The Wheel class's dimensions are full diameter of the box, and not the radius
             as it is in PhysX.
  */
                                              Wheel(WheelBlueprint*);
  
  /** \brief Wheel destructor. 
      \warning Deleting the Wheel whilst it is attached to a shape will probably cause a nasty crash.
  */
                                             ~Wheel(void);

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
          Enums::ShapeFunctionType            getShapeFunctionType() const;
  
  /** \brief Default blueprint for shapes.
  */
  static              WheelBlueprint          DefaultWheelBlueprint;
  
  
  /** \brief Sets the radius (distance from axle to contact surface) of the wheel.
      \note  Does not wake up the RigidBody.
  */
                      void                    setRadius(Real radius);
  
  
  /** \brief Gets the radius (distance from axle to contact surface) of the wheel.
  */
                      Real                    getRadius(void) const;
  
  
  /** \brief Sets the maximum extension distance of suspension along shape's -Y axis.
      \note  Does not wake up the RigidBody.
  */
                      void                    setSuspensionTravel(Real radius);
  
  
  /** \brief Gets the maximum extension distance of suspension along shape's -Y axis.
  */
                      Real                    getSuspensionTravel(void) const;
  
  /** \brief Sets the spring intended for the wheel suspension effects.
      \note  Does not wake up the RigidBody.
  */
                      void                    setSuspension(const SpringDescription&);
  
  
  /** \brief Gets the spring intended for the wheel suspension effects.
  */
                      SpringDescription       getSuspension(void) const;
  
  /** \brief 
      \note  Does not wake up the RigidBody.
  */
                      void                    setLateralTireForceFunction(const TireFunction&);
  
  
  /** \brief 
  */
                      TireFunction            getLateralTireForceFunction(void) const;
  
  
  /** \brief 
      \note  Does not wake up the RigidBody.
  */
                      void                    setLongitudalTireForceFunction(const TireFunction&);
  
  
  /** \brief 
  */
                      TireFunction            getLongitudalTireForceFunction(void) const;
  
  /** \brief 
      \note  Does not wake up the RigidBody.
  */
                      void                    setInverseWheelMass(Real);
  
  
  /** \brief 
  */
                      Real                    getInverseWheelMass(void) const;
  
  /** \brief 
      \note  Does not wake up the RigidBody.
  */
                      void                    setWheelFlags(int);
  
  
  /** \brief 
  */
                      int                     getWheelFlags(void) const;
  
  /** \brief Sets the motor torque. Torque must be positive. Body must be awake for this to make any effect.
      \note  Does not wake up the RigidBody.
  */
                      void                    setMotorTorque(Real);
  
  
  /** \brief Gets the motor torque.
  */
                      Real                    getMotorTorque(void) const;
  
  /** \brief Sets the brake torque. Torque must be positive.
      \note  Does not wake up the RigidBody.
  */
                      void                    setBrakeTorque(Real);
  
  
  /** \brief Gets the brake torque.
  */
                      Real                    getBrakeTorque(void) const;
  
  /** \brief Sets the steering angle (in radians)
      \note  Does not wake up the RigidBody.
  */
                      void                    setSteeringAngle(Real);
  
  
  /** \brief Gets the steering angle (in radians)
  */
                      Real                    getSteeringAngle(void) const;
  
  /** \brief Set Axle Speed.
      \warning This is an internal state variable. For any effect, the WheelFlags_AxleSpeedOverride must be enabled.
      \note  Does not wake up the RigidBody.
  */
                      void                    setAxleSpeed(Real);
  
  /** \brief Gets the axle speed.
  */
                      Real                    getAxleSpeed(void) const;
#if 0
  /** \brief Set the contact callback.
  */
                      void                    setCallback(void);
  
  /** \brief Get the contact callback.
  */
                      Callback*               getCallback(void);
#endif

  /** \brief
  */
                      NxWheelShape*           getWheelShape();

  protected:
  
  /** \internal DO NOT USE.
  */
                      NxShapeDesc*            create();

  /** \internal DO NOT USE.
  */
                      void                    assign(NxShape*);

  protected:

                      NxWheelShape*           mWheelShape;

                      
}; // class Wheel

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
