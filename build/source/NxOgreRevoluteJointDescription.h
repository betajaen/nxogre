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

                                                                                       

#ifndef NXOGRE_REVOLUTEJOINTDESCRIPTION_H
#define NXOGRE_REVOLUTEJOINTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJointDescription.h"
#include "NxOgreJointLimitDescription.h"
#include "NxOgreSpringDescription.h"
#include "NxOgreMotorDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass RevoluteJointDescription : public JointDescription
{
 
  public: // Functions
  
  /** \brief Text
  */
                                              RevoluteJointDescription();
  
  /** \brief Text
  */
                                             ~RevoluteJointDescription();
  
  /** \brief Text
  */
  void                                        reset();
  
  /** \brief
  */
  bool                                        isValid() const;
  
  /** \brief Distance above which to project joint.
      \default 1.0
      \see NxRevoluteJointDesc::projectionDistance
  */
                Real                      mProjectionDistance;

  /** \brief Angle (in  radians) that is beyond the joint is projected.
      \default 0.0872 (~5 degrees)
      \see NxRevoluteJointDesc::projectionDistance
  */
                Radian                    mProjectionAngle;

  /** \brief Limits rotation around twist axis
      \default JointLimitDescription::reset()
      \see NxRevoluteJointDesc::limit
  */
                JointLimitPairDescription mLimit;

  /** \brief Optional motor
      \default JointLimitDescription::reset()
      \see NxRevoluteJointDesc::motor
  */
                MotorDescription          mMotor;

  /** \brief Optional Spring
      \default SpringDescription::reset()
      \see NxRevoluteJointDesc::spring
  */
                SpringDescription         mSpring;

  /** \brief Combination of Enums::RevoluteJointFlags using the OR | operator.
      \default 0
      \see NxRevoluteJointDesc::jointSpring
  */
                unsigned int              mRevoluteJointFlags;

  /** \brief Enable joint projection.
      \default JointProjectionMode_None
      \see NxRevoluteJointDesc::projectionMode
  */
             Enums::JointProjectionMode   mProjectionMode;

  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
