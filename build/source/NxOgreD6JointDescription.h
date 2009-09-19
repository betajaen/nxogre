/** File: NxOgreD6JointDescription.h
    Created on: 16-Apr-09
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
