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
#include "NxOgreForceFieldLinearKernel.h"
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

ForceField::~ForceField()
{
 destroy();
}

void ForceField::create(const ForceFieldDescription& description, ForceFieldKernel* kernel, Scene* scene)
{
 NxForceFieldDesc desc;
 
 if (description.mRigidBody)
  desc.actor = description.mRigidBody->getNxActor();
 
 desc.clothType = (NxForceFieldType) (int) description.mClothType;
 desc.coordinates = (NxForceFieldCoordinates) (int) description.mCoordinates;
 desc.flags = description.mFlags;
 desc.fluidType = (NxForceFieldType) (int) description.mFluidType;
 desc.forceFieldVariety = (NxForceFieldVariety) (int) description.mVariety;
 desc.group = description.mGroup;
 desc.groupsMask.bits0 = description.mGroupsMask.bits0;
 desc.groupsMask.bits1 = description.mGroupsMask.bits1;
 desc.groupsMask.bits2 = description.mGroupsMask.bits2;
 desc.groupsMask.bits3 = description.mGroupsMask.bits3;
 desc.name = mName.c_str();
 desc.pose.setRowMajor44(description.mPose.ptr());
 desc.rigidBodyType = (NxForceFieldType) (int) description.mRigidBodyType;
 desc.softBodyType = (NxForceFieldType) (int) description.mSoftBodyType;
 
 desc.kernel = mKernel->getKernel();

 
 for(SimpleShapes::const_iterator shape = description.mIncludeGroupShapes.begin(); shape != description.mIncludeGroupShapes.end(); ++shape)
 {
  NxForceFieldShapeDesc* shape_desc = (*shape)->to_ff_shape();
  if (shape_desc)
   desc.includeGroupShapes.push_back(shape_desc);
 }
 
 mForceField = scene->getScene()->createForceField(desc);
 
 // Delete includeShapesDescriptions.
 for (unsigned int i=0; i < desc.includeGroupShapes.size(); i++)
 {
  NxForceFieldShapeDesc* ptr = desc.includeGroupShapes[i];
  GC::safe_allocated_delete<NxForceFieldShapeDesc, PhysXClassAllocator>(ptr, NXOGRE_GC_THIS);
 }
 
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

                                                                                       
