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
#include "NxOgreForceFieldDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ForceFieldDescription::ForceFieldDescription()
{
 reset();
}

void ForceFieldDescription::reset()
{
 mPose.identity();
 mRigidBody = NULL;
 mCoordinates = Enums::CoordinateSystem_Cartesian;
 mGroup = 0;
 mGroupsMask.zero();
 mFlags = Enums::ForceFieldFlag_ScalingFluid | Enums::ForceFieldFlag_ScalingCloth | Enums::ForceFieldFlag_ScalingSoftBody | Enums::ForceFieldFlag_ScalingRigidBody;
 mVariety = 0;
 mFluidType = Enums::ForceFieldType_Other;
 mClothType = Enums::ForceFieldType_Other;
 mSoftBodyType = Enums::ForceFieldType_Other;
 mRigidBodyType = Enums::ForceFieldType_Other;
 mName.clear();
}

void ForceFieldDescription::clone(ForceFieldDescription& target) const
{
 target.mPose = mPose;
 target.mRigidBody = mRigidBody;
 target.mCoordinates = mCoordinates;
 target.mGroup = mGroup;
 target.mGroupsMask = mGroupsMask;
 target.mFlags = mFlags;
 target.mVariety = mVariety;
 target.mFluidType = mFluidType;
 target.mClothType = mClothType;
 target.mSoftBodyType = mSoftBodyType;
 target.mRigidBodyType = mRigidBodyType;
 target.mName.assign(mName);
}

bool ForceFieldDescription::valid()
{
 if (mGroup >= 32)
  return false;
 return true;
}

                                                                                       

} // namespace NxOgre

                                                                                       
