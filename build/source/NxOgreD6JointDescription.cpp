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

                                                                                       
