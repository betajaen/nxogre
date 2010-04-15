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
#include "NxOgreForceField.h"
#include "NxOgreForceFieldDescription.h"
#include "NxOgreForceFieldKernel.h"
#include "NxOgreScene.h"

#include "NxOgreRigidBody.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       


ForceField::ForceField(const ForceFieldDescription& description, ForceFieldKernel* kernel, Scene* scene)
: mKernel(kernel), mScene(scene), mForceField(0)
{
 mName = description.mName;
 mNameHash = Strings::hash(mName);
 
 create(description, kernel, scene);
}

ForceField::ForceField(Scene* scene)
: mKernel(0), mScene(scene), mForceField(0)
{
}

ForceField::~ForceField(void)
{
 destroy();
}

void ForceField::create(const ForceFieldDescription& description, ForceFieldKernel* kernel, Scene* scene)
{
 NxForceFieldDesc desc;
 
 if (description.mRigidBody)
  desc.actor = description.mRigidBody->getNxActor();
 
#if 0
 desc.clothType = description.mClothType;
 desc.coordinates = description.mCoordinates;
 desc.flags = description.mFlags;
 desc.fluidType = description.mFluidType;
 desc.forceFieldVariety = description.mVariety;
 desc.group = description.mGroup;
 desc.groupsMask = description.mGroupsMask;
 desc.name = mName.c_str();
 desc.globalPose.setRowMajor44(description.mPose.ptr());
 desc.rigidBodyType = description.mRigidBodyType;
 desc.softBodyType = description.mSoftBodyType;
#endif
 mForceField = scene->getScene()->createForceField(desc);
 
 if (mKernel)
  mKernel->increaseReference();
 
}


void ForceField::destroy()
{
 if (mForceField == 0)
  return;
 
 if (mKernel)
  mKernel->decreaseReference();
}

String  ForceField::getName() const
{
 return mName;
}

StringHash  ForceField::getNameHash() const
{
 return mNameHash;
}

String ForceField::to_s() const
{
 return String("ForceField");
}

                                                                                       

} // namespace NxOgre

                                                                                       
