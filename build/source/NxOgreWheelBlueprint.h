/** File: NxOgreWheelBlueprint.h
    Created on: 5-Apr-09
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

#ifndef NXOGRE_WHEELBLUEPRINT_H
#define NXOGRE_WHEELBLUEPRINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeBlueprint.h"
#include "NxOgreSpringDescription.h"
#include "NxOgreTireFunction.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass WheelBlueprint : public ShapeBlueprint
{
  
  public:
  
  /** \brief Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
                                              WheelBlueprint();
  
  /** \brief Required destructor
  */
  virtual                                    ~WheelBlueprint();
  
  
  /** \brief Resets the member variables to their default values according to the PhysX SDK.
  */
                        void                 reset();
  
  /** \brief Radius of the wheel.
      \default 1.0
  */
                        Real                 mRadius;
  
  /** \brief Maxium distance along the wheel's -Y axis.
      \default 1.0
  */
                        Real                 mSuspensionTravel;
  
  /** \brief Data intended for car wheel suspension effects.
  */
                        SpringDescription    mSuspension;

  /** \brief Cubic hermite spline coefficients describing the longitudal tire force curve.
  */
                        TireFunction         mLongitudalTireFunction;

  /** \brief Cubic hermite spline coefficients describing the lateral tire force curve.
  */
                        TireFunction         mLateralTireFunction;

  /** \brief Determines the wheel velocity that wheel torques can achieve.
      \default 1.0
  */
                        Real                 mInverseWheelMass;

  /** \brief Wheel flags
      \see NxOgre::Enums::WheelFlags
      \default 0
  */
                        int                  mWheelFlags;
  
  /** \brief Initial motor torque
      \default 0
  */
                        Real                 mMotorTorque;
  
  /** \brief Initial breaking torque
      \default 0
  */
                        Real                 mBrakeTorque;
  
  /** \brief Initial Steering angle in radians.
      \default 0
      \range (-Pi, Pi)
  */
                        Real                 mSteeringAngle;
 
  /** \brief Callback used for modifying the wheel contact point before the wheel constraints are created. 
  */
                        Callback*            mContactModifier;
  
}; // class ShapeBlueprint

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
