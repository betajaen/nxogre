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
#include "NxOgreVisualDebugger.h"
#include "NxOgreWorld.h"
#include "NxOgreScene.h"
#include "NxOgreRenderable.h"
#include "NxOgreVisualDebuggerMeshData.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

VisualDebugger::VisualDebugger(World* world)
: mWorld(world), mRenderable(0), mMeshData(0)
{
 mMeshData = NxOgre_New(VisualDebuggerMeshData)();
}

VisualDebugger::~VisualDebugger(void)
{
 NxOgre_Delete(mMeshData);
}

void VisualDebugger::setRenderable(Renderable* renderable)
{
 mRenderable = renderable;
}

Renderable* VisualDebugger::getRenderable(void)
{
 return mRenderable;
}

void VisualDebugger::setVisualisationMode(NxOgre::Enums::VisualDebugger dm)
{

 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 if (dm == NxOgre::Enums::VisualDebugger_ShowNone)
 {
  sdk->setParameter(NX_VISUALIZATION_SCALE, 0);
  return;
 }

 sdk->setParameter(NX_VISUALIZATION_SCALE, 1.0f);
 sdk->setParameter(NX_VISUALIZE_WORLD_AXES, true);
 sdk->setParameter(NX_VISUALIZE_BODY_AXES, true);
 sdk->setParameter(NX_VISUALIZE_BODY_MASS_AXES, true);
 sdk->setParameter(NX_VISUALIZE_BODY_LIN_VELOCITY, true);
 sdk->setParameter(NX_VISUALIZE_BODY_ANG_VELOCITY, true);
 sdk->setParameter(NX_VISUALIZE_BODY_JOINT_GROUPS, true);
 sdk->setParameter(NX_VISUALIZE_JOINT_LOCAL_AXES, true);
 sdk->setParameter(NX_VISUALIZE_JOINT_WORLD_AXES, true);
 sdk->setParameter(NX_VISUALIZE_JOINT_LIMITS, true);
 sdk->setParameter(NX_VISUALIZE_CONTACT_POINT, true);
 sdk->setParameter(NX_VISUALIZE_CONTACT_NORMAL, true);
 sdk->setParameter(NX_VISUALIZE_CONTACT_ERROR, true);
 sdk->setParameter(NX_VISUALIZE_CONTACT_FORCE, true);
 sdk->setParameter(NX_VISUALIZE_ACTOR_AXES, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_AABBS, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_SHAPES, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_AXES, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_COMPOUNDS, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_VNORMALS, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_FNORMALS, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_EDGES, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_SPHERES, true);
#if (NX_SDK_VERSION_NUMBER < 280)
 sdk->setParameter(NX_VISUALIZE_COLLISION_SAP, true);
#endif
 sdk->setParameter(NX_VISUALIZE_COLLISION_STATIC, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_DYNAMIC, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_FREE, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_CCD, true);
 sdk->setParameter(NX_VISUALIZE_COLLISION_SKELETONS, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_EMITTERS, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_POSITION, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_VELOCITY, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_KERNEL_RADIUS, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_BOUNDS, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_PACKETS, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_MOTION_LIMIT, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_DYN_COLLISION, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_STC_COLLISION, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_MESH_PACKETS, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_DRAINS, true);
 sdk->setParameter(NX_VISUALIZE_FLUID_PACKET_DATA, true);
 sdk->setParameter(NX_VISUALIZE_CLOTH_MESH, true);
 sdk->setParameter(NX_VISUALIZE_CLOTH_COLLISIONS, true);
 sdk->setParameter(NX_VISUALIZE_CLOTH_SELFCOLLISIONS, true);
 sdk->setParameter(NX_VISUALIZE_CLOTH_WORKPACKETS, true);
 sdk->setParameter(NX_VISUALIZE_CLOTH_SLEEP, true);
 sdk->setParameter(NX_VISUALIZE_CLOTH_TEARABLE_VERTICES, true);
 sdk->setParameter(NX_VISUALIZE_CLOTH_TEARING, true);
 sdk->setParameter(NX_VISUALIZE_CLOTH_ATTACHMENT, true);
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_MESH, true);
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_COLLISIONS, true);
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_WORKPACKETS, true);
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_SLEEP, true);
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_TEARABLE_VERTICES, true);
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_TEARING, true);
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_ATTACHMENT, true); 

}

void VisualDebugger::draw()
{
 
 World::SceneIterator iterator = mWorld->getScenes();
 //ArrayIterator<Scene*> iterator = mWorld->getScenes();
 mMeshData->mLines.clear();
 mMeshData->mColours.clear();
 mMeshData->mNbLines = 0;

 //for (Scene* scene = iterator.begin(); scene = iterator.next();)
 for (; iterator != iterator.end(); ++iterator)
 {
  const NxDebugRenderable* renderable = iterator->getScene()->getDebugRenderable();
  
  if (renderable == 0)
   continue;
  
  unsigned int nbLines = renderable->getNbLines();
  const NxDebugLine* lines = renderable->getLines();
  while(nbLines--)
  {
   mMeshData->mLines.append(lines->p0.x);
   mMeshData->mLines.append(lines->p0.y);
   mMeshData->mLines.append(lines->p0.z);
   mMeshData->mLines.append(lines->p1.x);
   mMeshData->mLines.append(lines->p1.y);
   mMeshData->mLines.append(lines->p1.z);
   mMeshData->mColours.append(lines->color);
   mMeshData->mColours.append(lines->color);
   lines++;
  }
  mMeshData->mNbLines += renderable->getNbLines();
 }

 
 mRenderable->drawVisualDebugger(mMeshData);
}

                                                                                       

} // namespace NxOgre

                                                                                       
