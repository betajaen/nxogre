/** File: NxOgreVisualDebugger.cpp
    Created on: 15-Feb-09
    Author: Robin Southern "betajaen"
    SVN: $Id$

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
#include "NxOgreVisualDebugger.h"
#include "NxOgreWorld.h"
#include "NxOgreScene.h"
#include "NxOgreRenderable.h"
#include "NxOgreVisualDebuggerMeshData.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre_Namespace
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
 
 ArrayIterator<Scene*> iterator = mWorld->getScenes();
 mMeshData->mLines.clear();
 mMeshData->mPoints.clear();
 mMeshData->mTriangles.clear();

 for (Scene* scene = iterator.begin(); scene = iterator.next();)
 {
  const NxDebugRenderable* renderable = scene->getScene()->getDebugRenderable();
  
  if (renderable == 0)
   continue;
  
  mMeshData->mLines.append(VisualDebuggerMeshData::DebugLine(Vec3(0,0,0), Vec3(0, 10, 0)));
  mMeshData->mLines.appendMany(renderable->getNbLines(),renderable->getLines());
  
//  mMeshData->mLines.append(renderable->getLines(), renderable->getNbLines() * sizeof(NxDebugLine));
//  mMeshData->mLines.reserve(renderable->getNbLines() * sizeof(NxDebugLine));
//  mMeshData->mLines.append(
//  mMeshData->mLines.merge(renderable->getLines(), renderable->getNbLines() * sizeof(NxDebugLine));

 }

 mRenderable->drawVisualDebugger(mMeshData);
#if 0
 ArrayIterator<Scene*> iterator = mWorld->getScenes();

 // Scout ahead to see if the Scenes are writable if not return early.
// for (Scene* scene = iterator.begin(); scene = iterator.next(); )
//  if (!scene->getScene()->isWritable())
//   return;

 mRenderable->begin();
 {

  for (Scene* scene = iterator.begin(); scene = iterator.next(); )
  {
   const NxDebugRenderable* renderable = scene->getScene()->getDebugRenderable();

   if (renderable == 0)
   {
    mRenderable->addVertex(0,0,0);
    mRenderable->addVertex(0,1,0);
    continue; // Just to be safe.
   }
   else
   {
    mRenderable->addVertex(0,0,0);
    mRenderable->addVertex(0,0,1);
   }

   // LINES PASS
   unsigned int nbLines = renderable->getNbLines();
   const NxDebugLine* line = renderable->getLines();
   while(nbLines--)
   {
    mRenderable->addVertex(line->p0.x, line->p0.y, line->p0.z);
    mRenderable->addColour(line->color);
    mRenderable->addVertex(line->p1.x, line->p1.y, line->p1.z);
    mRenderable->addColour(line->color);
    line++;
   }
   
  }
 }
 mRenderable->end();
#endif
}

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       
