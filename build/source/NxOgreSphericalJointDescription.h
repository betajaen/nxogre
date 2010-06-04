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

                                                                                       

#ifndef NXOGRE_SPHERICALJOINTDESCRIPTION_H
#define NXOGRE_SPHERICALJOINTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJointDescription.h"
#include "NxOgreJointLimitDescription.h"
#include "NxOgreSpringDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SphericalJointDescription : public JointDescription
{
 
  public: // Functions
  
  /** \brief Text
  */
                                              SphericalJointDescription();
  
  /** \brief Text
  */
                                             ~SphericalJointDescription();
  
  /** \brief Text
  */
  void                                        reset();
  
  /** \brief
  */
  bool                                        isValid() const;


  /** \brief Swing limit axis (directional vector) defined in the joint space of RigidBody 0.
      \default Vec3::POS_Z
      \see NxSphericalJointDesc::swingAxis
  */
                Vec3                     mSwingAxis;
  
  /** \brief Distance above which to project joint.
      \default 1.0
      \see NxSphericalJointDesc::projectionDistance
  */
                Real                      mProjectionDistance;

  /** \brief Limits rotation around twist axis
      \default JointLimitDescription::reset()
      \see NxSphericalJointDesc::twistLimit
  */
                JointLimitPairDescription mTwistLimit;

  /** \brief Limits swing of twist axis
      \default JointLimitDescription::reset()
      \see NxSphericalJointDesc::swingLimit
  */
                JointLimitDescription     mSwingLimit;

  /** \brief Spring that works against twisting.
      \default SpringDescription::reset()
      \see NxSphericalJointDesc::twistSpring
  */
                SpringDescription         mTwistSpring;

  /** \brief Spring that works against swinging
      \default SpringDescription::reset()
      \see NxSphericalJointDesc::swingSpring
  */
                SpringDescription         mSwingSpring;

  /** \brief Spring that lets the joint get pulled apart
      \default SpringDescription::reset()
      \see NxSphericalJointDesc::jointSpring
  */
                SpringDescription         mJointSpring;

  /** \brief Combination of Enums::SphericalJointFlags using the OR | operator.
      \default 0
      \see NxSphericalJointDesc::jointSpring
  */
                unsigned int              mSphericalJointFlags;

  /** \brief Enable joint projection.
      \default JointProjectionMode_None
      \see NxSphericalJointDesc::projectionMode
  */
             Enums::JointProjectionMode   mProjectionMode;

  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
