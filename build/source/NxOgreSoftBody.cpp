/** File: NxOgreSoftBody.cpp
    Created on: 31-May-09
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

 mMeshData = NxOgre_New(PhysXMeshData)(mMesh);
 
 desc.meshData = mMeshData->getMeshData();
 
 if (desc.isValid() == false)
 {
  SharedStringStream ss;
  ss << "SoftBody description is invalid. Reasons are:" << Reason::whyAsStream(desc);
  NxOgre_ThrowError(ss.get());
  return;
 }
 mSoftBody = mScene->getScene()->createSoftBody(desc);

 TimeController::getSingleton()->addTimeListener(this, mPriority);

}

SoftBody::~SoftBody()
{
 TimeController::getSingleton()->removeTimeListener(this, mPriority);
 NxOgre_Delete(mMeshData);
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

                                                                                       
