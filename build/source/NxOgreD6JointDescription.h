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

                                                                                       

/*! class. D6JointDescription
    desc.
        Initial properties for a D6Joint.
*/
class NxOgrePublicClass D6JointDescription : public JointDescription
{
 
  public: // Functions
  
  /*! constructor. D6JointDescription
      desc.
           Calls reset.
  */
  D6JointDescription();
  
  /*! destructor. D6JointDescription
  */
  ~D6JointDescription();
  
  /*! function. reset
      desc.
           Sets the properties of the description to their default values.
  */
  void  reset();
  
  /*! function. isValid
      desc.
          Is the description properties in within range of allowed values.
      return.
          **bool** -- If the properties are within valid range of allowed values.
  */
  bool  isValid() const;
  
  /*! variable. mXMotion
      desc.
          The linear degrees of freedom for the X axis.
      default.
          D6Motion_Free
  */
  Enums::D6JointMotion          mXMotion;
  
  /*! variable. mYMotion
      desc.
          The linear degrees of freedom for the Y axis.
      default.
          D6Motion_Free
  */
  Enums::D6JointMotion          mYMotion;
  
  /*! variable. mZMotion
      desc.
          The linear degrees of freedom for the Z axis.
      default.
          D6Motion_Free
  */
  Enums::D6JointMotion          mZMotion;
  
  /*! variable. mSwing1Motion
      desc.
          Defines the angular degrees of freedom
      default.
          D6Motion_Free
  */
  Enums::D6JointMotion          mSwing1Motion;
  
  /*! variable. mSwing2Motion
      desc.
          Defines the angular degrees of freedom
      default.
          D6Motion_Free
  */
  Enums::D6JointMotion          mSwing2Motion;
  
  /*! variable. mTwistMotion
      desc.
          Defines the angular degrees of freedom
      default.
          D6Motion_Free
  */
  Enums::D6JointMotion          mTwistMotion;
  
  /*! variable. mLinearLimit
      desc.
          If some linear DOF are limited, this defines the characteristics of these limits.
      default.
          JointLimitSoftDescription()
  */
  JointLimitSoftDescription     mLinearLimit;
  
  /*! variable. mSwing1Limit
      desc.
          If mSwing1Motion is Enums::D6JointMotion_Limited, this defines the characteristics of these limits.
      default.
          JointLimitSoftDescription()
  */
  JointLimitSoftDescription     mSwing1Limit;
  
  /*! variable. mSwing2Limit
      desc.
          If mSwing2Motion is Enums::D6JointMotion_Limited, this defines the characteristics of these limits.
      default.
          JointLimitSoftDescription()
  */
  JointLimitSoftDescription     mSwing2Limit;
  
  /*! variable. mTwistLimit
      desc.
          If mTwistLimit is Enums::D6JointMotion_Limited, this defines the characteristics of these limits.
      default.
          JointLimitSoftDescription()
  */
  JointLimitPairSoftDescription  mTwistLimit;
  
  /*! variable. mXDrive
      desc.
          Drive the X linear DOF.
      default.
          JointDriveDescription()
  */
  JointDriveDescription  mXDrive;
  
  /*! variable. mYDrive
      desc.
          Drive the Y linear DOF.
      default.
          JointDriveDescription()
  */
  JointDriveDescription  mYDrive;
  
  /*! variable. mZDrive
      desc.
          Drive the Z linear DOF.
      default.
          JointDriveDescription()
  */
  JointDriveDescription  mZDrive;

  /*! variable. mSwingDrive
      desc.
          These drives are used if the flag Enums::D6Joint_SlerpDrive is not set.
      default.
          JointDriveDescription()
  */
  JointDriveDescription  mSwingDrive;

  /*! variable. mTwistDrive
      desc.
          These drives are used if the flag Enums::D6Joint_SlerpDrive is not set.
      default.
          JointDriveDescription()
  */
  JointDriveDescription  mTwistDrive;
  
  /*! variable. mSlerpDrive
      desc.
          These drives are used if the flag Enums::D6Joint_SlerpDrive is not set.
      default.
          JointDriveDescription()
  */
  JointDriveDescription  mSlerpDrive;
  
  /*! variable. mDrivePosition
      desc.
          If the type of drive (mXDrive, mYDrive or mZDrive) is Enums::D6JointDriveType_Position, this defines the goal position.
      default.
          Vec3::ZERO
  */
  Vec3  mDrivePosition;

  /*! variable. mDriveOrientation
      desc.
          If the type of drive (mXDrive, mYDrive or mZDrive) is Enums::D6JointDriveType_Position, this defines the goal orientation.
      default.
          Quat::IDENTITY
  */
  Quat  mDriveOrientation;

  /*! variable. mDriveLinearVelocity
      desc.
           If the type of drive (mXDrive, mYDrive or mZDrive) is Enums::D6JointDriveType_Velocity, this defines the goal linear velocity.
      default.
          Vec3::ZERO
  */
  Vec3  mDriveLinearVelocity;

  /*! variable. mDriveAngularVelocity
      desc.
            If the type of drive (mXDrive, mYDrive or mZDrive) is Enums::D6JointDriveType_Velocity, this defines the goal linear velocity.
            
            The Angular velocities are;
            
            |_. Velocity Axis |_. Drive Axis |
            |x|mTwistAxis|
            |y|mSwing1Axis|
            |z|mSwing2Axis|
             
      default.
        Vec3::ZERO
  */
  Vec3                         mDriveAngularVelocity;

  /*! variable. mProjectionMode
      desc.
          Enable joint projection.
      default.
          JointProjectionMode_None
  */
  Enums::JointProjectionMode   mProjectionMode;

  /*! variable. mProjectionDistance
      desc.
          Distance above which to project joint.
      default.
          0.1
  */
  Real  mProjectionDistance;
  
  /*! variable. mProjectionAngle
      desc.
          Angle (in  radians) that is beyond the joint is projected.
      default.
          0.0872 (~5 degrees)
  */
  Radian  mProjectionAngle;
  
  /*! variable. mGearRatio
      desc.
          when the flag NX_D6JOINT_GEAR_ENABLED is set, the angular velocity
          of the second actor is driven towards the angular velocity of the
          first actor times gearRatio (both w.r.t. their primary axis)
      \default 1.0
  */
  Real  mGearRatio;
  
  /*! variable. mD6Flags
      desc.
          Combination using the @|@ (or) operator of the Enums::D6JointFlag
      default.
          0
  */
  unsigned int  mD6Flags;
  
}; // class D6JointDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
