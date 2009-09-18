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

                                                                                       

#ifndef NXOGRE_D6JOINTDESCRIPTION_H
#define NXOGRE_D6JOINTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJointDescription.h"
#include "NxOgreJointLimitDescription.h"
#include "NxOgreSpringDescription.h"
#include "NxOgreJointDriveDescription.h"
#include "NxOgreJointLimitSoftDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass D6JointDescription : public JointDescription
{
 
  public: // Functions
  
  /** \brief Text
  */
                                              D6JointDescription(void);
  
  /** \brief Text
  */
                                             ~D6JointDescription(void);
  
  /** \brief Text
  */
  void                                        reset(void);
  
  /** \brief
  */
  bool                                        isValid(void) const;


  /** \brief The linear degrees of freedom per axis.
      \default D6Motion_Free
      \see NxD6JointDesc::xMotion, NxD6JointDesc::yMotion, NxD6JointDesc::zMotion
  */
                Enums::D6JointMotion          mXMotion, mYMotion, mZMotion;
  
  /** \brief Defines the angular degrees of freedom
      \default D6Motion_Free
      \see NxD6JointDesc::swingMotion, NxD6JointDesc::swing2Motion, NxD6JointDesc::twistMotion
  */
                Enums::D6JointMotion          mSwing1Motion, mSwing2Motion, mTwistMotion;
  
  /** \brief If some linear DOF are limited, this defines the characteristics of these limits.
  */
                JointLimitSoftDescription     mLinearLimit;
  
  /** \brief If mSwing1Motion is Enums::D6JointMotion_Limited, this defines the characteristics of these limits.
  */
                JointLimitSoftDescription     mSwing1Limit;

  /** \brief If mSwing2Motion is Enums::D6JointMotion_Limited, this defines the characteristics of these limits.
  */
                JointLimitSoftDescription     mSwing2Limit;

  /** \brief If mTwistLimit is Enums::D6JointMotion_Limited, this defines the characteristics of these limits.
  */
                JointLimitPairSoftDescription mTwistLimit;

  /** \brief Drive the three linear DOF.
  */
                JointDriveDescription         mXDrive, mYDrive, mZDrive;

  /** \brief These drives are used if the flag Enums::D6Joint_SlerpDrive is not set.
  */
                JointDriveDescription         mSwingDrive, mTwistDrive;

  /** \brief These drives are used if the flag Enums::D6Joint_SlerpDrive is set.
  */
                JointDriveDescription         mSlerpDrive;

  /** \brief If the type of drive (mXDrive, mYDrive or mZDrive) is Enums::D6JointDriveType_Position, this defines the goal position.
  */
                Vec3                         mDrivePosition;

  /** \brief If the type of drive (mXDrive, mYDrive or mZDrive) is Enums::D6JointDriveType_Position, this defines the goal orientation.
      \note  Vec4 represents a Quaternion.
  */
                Vec4                         mDriveOrientation;

  /** \brief If the type of drive (mXDrive, mYDrive or mZDrive) is Enums::D6JointDriveType_Velocity, this defines the goal linear velocity.

  */
                Vec3                         mDriveLinearVelocity;

  /** \brief If the type of drive (mXDrive, mYDrive or mZDrive) is Enums::D6JointDriveType_Velocity, this defines the goal linear velocity.
      \note  mDriveAngularVelocity.x = mTwistAxis
             mDriveAngularVelocity.y = mSwing1Axis
             mDriveAngularVelocity.z = mSwing2Axis
  */
                Vec3                         mDriveAngularVelocity;

  /** \brief Enable joint projection.
      \default JointProjectionMode_None
      \see NxSphericalJointDesc::projectionMode
  */
             Enums::JointProjectionMode   mProjectionMode;

  /** \brief Distance above which to project joint.
      \default 0.1
      \see NxSphericalJointDesc::projectionDistance
  */
                Real                      mProjectionDistance;

  /** \brief Angle (in  radians) that is beyond the joint is projected.
      \default 0.0872 (~5 degrees)
      \see NxRevoluteJointDesc::projectionDistance
  */
                Real                      mProjectionAngle;

  /** \see NxD6JointDesc::gearRatio
      \default 1.0
  */
                Real                      mGearRatio;

  /** \sbrief Combination using the OR operator | of the Enums::D6JointFlag
      \default 0
      \see Enums::D6JointFlag
  */
                unsigned int              mD6Flags;


}; // class D6JointDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
