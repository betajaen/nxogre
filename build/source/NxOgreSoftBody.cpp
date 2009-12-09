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
#include "NxOgreSoftBody.h"
#include "NxOgreSoftBodyDescription.h"
#include "NxOgreMesh.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreScene.h"
#include "NxOgreReason.h"
#include "NxOgrePhysXMeshData.h"
#include "NxOgreRenderable.h"
#include "NxOgreTimeController.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBody.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

SoftBody::SoftBody(const SoftBodyDescription& description, Renderable* renderable, Enums::Priority priority, Scene* scene)
: mName(description.mName), mMesh(description.mMesh), mScene(scene), mMeshData(0), mRenderable(renderable), mPriority(priority)
{

 NxSoftBodyDesc desc;
 ::NxOgre::Functions::PrototypeFunctions::SoftBodyDescriptionToNxSoftBodyDesc(description, desc);

 mMeshData = NXOGRE_NEW_NXOGRE(PhysXMeshData)(mMesh);
 
 desc.meshData = mMeshData->getMeshData();
 
 if (desc.isValid() == false)
 {
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(desc), Classes::_SoftBodyDescription);
  return;
 }
 
 mSoftBody = mScene->getScene()->createSoftBody(desc);
 
 TimeController::getSingleton()->addTimeListener(this, mPriority);
 
}

SoftBody::~SoftBody()
{
 TimeController::getSingleton()->removeTimeListener(this, mPriority);
 NXOGRE_DELETE_NXOGRE(mMeshData);
}

bool SoftBody::advance(float deltaTime, const Enums::Priority&)
{
 if (mRenderable && mMeshData)
 {
  NxBounds3 bounds;
  mSoftBody->getWorldBounds(bounds);
  mRenderable->drawSoftBodySimple(mMeshData, Bounds3::from(bounds));
 }
 return true;
}

Renderable*  SoftBody::getRenderable()
{
 return mRenderable;
}

Mesh*  SoftBody::getMesh()
{
 return mMesh;
}

NxSoftBody*  SoftBody::getPhysXSoftBody()
{
 return mSoftBody;
}

PhysXMeshData*  SoftBody::getPhysXMeshData()
{
 return mMeshData;
}

String SoftBody::getName()
{
 return mName;
}



                                                                                       

} // namespace NxOgre

                                                                                       
