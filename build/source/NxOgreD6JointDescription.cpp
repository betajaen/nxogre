/** File: NxOgreD6JointDescription.cpp
    Created on: 20-Apr-09
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreD6JointDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

D6JointDescription::D6JointDescription(void)
{
 reset();
}

D6JointDescription::~D6JointDescription(void)
{
}

void D6JointDescription::reset(void)
{
 JointDescription::reset();

 mXMotion = Enums::D6JointMotion_Free;
 mYMotion = Enums::D6JointMotion_Free;
 mZMotion = Enums::D6JointMotion_Free;
 mTwistMotion = Enums::D6JointMotion_Free;
 mSwing1Motion = Enums::D6JointMotion_Free;
 mSwing2Motion = Enums::D6JointMotion_Free;

 mDrivePosition.zero();
 mDriveOrientation.set(1,0,0,0);

 mDriveLinearVelocity.set(0,0,0);
 mDriveAngularVelocity.set(0,0,0);

 mProjectionMode = Enums::JointProjectionMode_None;
 mProjectionDistance = 0.1f;
 mProjectionAngle = 0.0872f;

 mD6Flags = 0;
 mGearRatio = 1.0f;
}

bool D6JointDescription::isValid(void) const
{
 if (mD6Flags & Enums::D6JointFlag_SlerpDrive)
 {
  if (mSwing1Motion == Enums::D6JointMotion_Locked ||
      mSwing2Motion == Enums::D6JointMotion_Locked ||
      mTwistMotion == Enums::D6JointMotion_Locked)
  return false;
 }

 if (mSwing1Motion == Enums::D6JointMotion_Limited)
 {
  if (mSwing1Limit.mValue < 0.0f) return false;
  if (mSwing1Limit.mValue > Constants::Pi) return false;
 }

 if (mSwing2Motion == Enums::D6JointMotion_Limited)
 {
  if (mSwing2Limit.mValue < 0.0f) return false;
  if (mSwing2Limit.mValue > Constants::Pi) return false;
 }

 if (mTwistMotion == Enums::D6JointMotion_Limited)
 {
  if (mTwistLimit.first.mValue < -Constants::Pi) return false;
  if (mTwistLimit.second.mValue > Constants::Pi) return false;
  if (mTwistLimit.first.mValue > mTwistLimit.second.mValue) return false;
 }

 return true; // temp.
}

                                                                                       

} // namespace NxOgre

                                                                                       
