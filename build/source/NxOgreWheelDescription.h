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

                                                                                       

#ifndef NXOGRE_WHEELBLUEPRINT_H
#define NXOGRE_WHEELBLUEPRINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreSpringDescription.h"
#include "NxOgreTireFunction.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass WheelDescription : public ShapeDescription
{
  
  public:
  
  /** \brief Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
                                              WheelDescription();
  
  /** \brief Required destructor
  */
  virtual                                    ~WheelDescription();
  
  virtual NxShapeDesc* createShapeDescription() const;
  
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
                        Radian               mSteeringAngle;
 
  /** \brief Callback used for modifying the wheel contact point before the wheel constraints are created. 
  */
                        Callback*            mContactModifier;
  
}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
