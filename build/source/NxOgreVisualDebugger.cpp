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

                                                                                       

VisualDebuggerDescription::VisualDebuggerDescription()
{
 showLight();
}

void VisualDebuggerDescription::showMinimal()
{
 mWorld.axes = true;
 mRigidBody.actorAxes = true;
 mRigidBody.bodyAxes = true;
 mRigidBody.massAxes = false;
 mRigidBody.linearVelocity = false;
 mRigidBody.angularVelocity = false;
 mRigidBody.jointGroups = false;
 mJoint.limits = false;
 mJoint.worldAxes = false;
 mContact.point = false;
 mContact.normal = false;
 mContact.error = false;
 mContact.force = false;
 mCollision.AABB = false;
 mCollision.shapes = false;
 mCollision.axes = false;
 mCollision.compound = false;
 mCollision.vNormals = false;
 mCollision.fNormals = false;
 mCollision.edges = false;
 mCollision.spheres = false;
 mCollision.staticPruning = false;
 mCollision.dynamicPruning = false;
 mCollision.freePruning = false;
 mCollision.CCD = false;
 mCollision.skeletons = false;
 mFluid.emitters = true;
 mFluid.position = false;
 mFluid.kernelRadius = false;
 mFluid.bounds = true;
 mFluid.packets = false;
 mFluid.motionLimit = false;
 mFluid.dynamicCollision = false;
 mFluid.staticCollision = false;
 mFluid.meshPackets = false;
 mFluid.drains = true;
 mFluid.packetData = false;
 mCloth.mesh = false;
 mCloth.collisions = false;
 mCloth.selfCollisions = false;
 mCloth.workPackets = false;
 mCloth.sleeping = false;
 mCloth.sleepVertex = false;
 mCloth.tearableVertices = false;
 mCloth.tearing = false;
 mCloth.attachment = false;
 mCloth.validBounds = true;
 mCloth.hierarchy = false;
 mCloth.hardStretchingLimitation = false;
 mSoftBody.mesh = false;
 mSoftBody.collisions = false;
 mSoftBody.workPackets = false;
 mSoftBody.sleeping = false;
 mSoftBody.sleepVertex = false;
 mSoftBody.tearableVertices = false;
 mSoftBody.tearing = false;
 mSoftBody.attachment = false;
 mSoftBody.validBounds = true;
}


void VisualDebuggerDescription::showLight()
{
 mWorld.axes = true;
 mRigidBody.actorAxes = true;
 mRigidBody.bodyAxes = true;
 mRigidBody.massAxes = false;
 mRigidBody.linearVelocity = false;
 mRigidBody.angularVelocity = false;
 mRigidBody.jointGroups = false;
 mJoint.limits = false;
 mJoint.worldAxes = true;
 mContact.point = false;
 mContact.normal = false;
 mContact.error = false;
 mContact.force = false;
 mCollision.AABB = false;
 mCollision.shapes = false;
 mCollision.axes = false;
 mCollision.compound = false;
 mCollision.vNormals = false;
 mCollision.fNormals = false;
 mCollision.edges = false;
 mCollision.spheres = false;
 mCollision.staticPruning = false;
 mCollision.dynamicPruning = false;
 mCollision.freePruning = false;
 mCollision.CCD = false;
 mCollision.skeletons = false;
 mFluid.emitters = true;
 mFluid.position = false;
 mFluid.kernelRadius = false;
 mFluid.bounds = false;
 mFluid.packets = false;
 mFluid.motionLimit = false;
 mFluid.dynamicCollision = false;
 mFluid.staticCollision = false;
 mFluid.meshPackets = false;
 mFluid.drains = true;
 mFluid.packetData = false;
 mCloth.mesh = false;
 mCloth.collisions = false;
 mCloth.selfCollisions = false;
 mCloth.workPackets = false;
 mCloth.sleeping = false;
 mCloth.sleepVertex = false;
 mCloth.tearableVertices = false;
 mCloth.tearing = false;
 mCloth.attachment = true;
 mCloth.validBounds = true;
 mCloth.hierarchy = false;
 mCloth.hardStretchingLimitation = false;
 mSoftBody.mesh = false;
 mSoftBody.collisions = false;
 mSoftBody.workPackets = false;
 mSoftBody.sleeping = false;
 mSoftBody.sleepVertex = false;
 mSoftBody.tearableVertices = false;
 mSoftBody.tearing = false;
 mSoftBody.attachment = true;
 mSoftBody.validBounds = true;
}

void VisualDebuggerDescription::showDebug()
{
 mWorld.axes = true;
 mRigidBody.actorAxes = true;
 mRigidBody.bodyAxes = true;
 mRigidBody.massAxes = false;
 mRigidBody.linearVelocity = true;
 mRigidBody.angularVelocity = true;
 mRigidBody.jointGroups = false;
 mJoint.limits = true;
 mJoint.worldAxes = true;
 mContact.point = true;
 mContact.normal = false;
 mContact.error = false;
 mContact.force = false;
 mCollision.AABB = false;
 mCollision.shapes = true;
 mCollision.axes = true;
 mCollision.compound = false;
 mCollision.vNormals = false;
 mCollision.fNormals = false;
 mCollision.edges = false;
 mCollision.spheres = false;
 mCollision.staticPruning = false;
 mCollision.dynamicPruning = false;
 mCollision.freePruning = false;
 mCollision.CCD = true;
 mCollision.skeletons = true;
 mFluid.emitters = true;
 mFluid.position = true;
 mFluid.kernelRadius = false;
 mFluid.bounds = false;
 mFluid.packets = false;
 mFluid.motionLimit = false;
 mFluid.dynamicCollision = false;
 mFluid.staticCollision = false;
 mFluid.meshPackets = false;
 mFluid.drains = true;
 mFluid.packetData = false;
 mCloth.mesh = true;
 mCloth.collisions = false;
 mCloth.selfCollisions = false;
 mCloth.workPackets = false;
 mCloth.sleeping = false;
 mCloth.sleepVertex = false;
 mCloth.tearableVertices = false;
 mCloth.tearing = false;
 mCloth.attachment = true;
 mCloth.validBounds = true;
 mCloth.hierarchy = false;
 mCloth.hardStretchingLimitation = false;
 mSoftBody.mesh = true;
 mSoftBody.collisions = false;
 mSoftBody.workPackets = false;
 mSoftBody.sleeping = false;
 mSoftBody.sleepVertex = false;
 mSoftBody.tearableVertices = false;
 mSoftBody.tearing = false;
 mSoftBody.attachment = true;
 mSoftBody.validBounds = true;
}

void VisualDebuggerDescription::showAll()
{
 mWorld.axes = true;
 mRigidBody.actorAxes = true;
 mRigidBody.bodyAxes = true;
 mRigidBody.massAxes = true;
 mRigidBody.linearVelocity = true;
 mRigidBody.angularVelocity = true;
 mRigidBody.jointGroups = true;
 mJoint.limits = true;
 mJoint.worldAxes = true;
 mContact.point = true;
 mContact.normal = true;
 mContact.error = true;
 mContact.force = true;
 mCollision.AABB = true;
 mCollision.shapes = true;
 mCollision.axes = true;
 mCollision.compound = true;
 mCollision.vNormals = true;
 mCollision.fNormals = true;
 mCollision.edges = true;
 mCollision.spheres = true;
 mCollision.staticPruning = true;
 mCollision.dynamicPruning = true;
 mCollision.freePruning = true;
 mCollision.CCD = true;
 mCollision.skeletons = true;
 mFluid.emitters = true;
 mFluid.position = true;
 mFluid.kernelRadius = true;
 mFluid.bounds = true;
 mFluid.packets = true;
 mFluid.motionLimit = true;
 mFluid.dynamicCollision = true;
 mFluid.staticCollision = true;
 mFluid.meshPackets = true;
 mFluid.drains = true;
 mFluid.packetData = true;
 mCloth.mesh = true;
 mCloth.collisions = true;
 mCloth.selfCollisions = true;
 mCloth.workPackets = true;
 mCloth.sleeping = true;
 mCloth.sleepVertex = true;
 mCloth.tearableVertices = true;
 mCloth.tearing = true;
 mCloth.attachment = true;
 mCloth.validBounds = true;
 mCloth.hierarchy = true;
 mCloth.hardStretchingLimitation = true;
 mSoftBody.mesh = true;
 mSoftBody.collisions = true;
 mSoftBody.workPackets = true;
 mSoftBody.sleeping = true;
 mSoftBody.sleepVertex = true;
 mSoftBody.tearableVertices = true;
 mSoftBody.tearing = true;
 mSoftBody.attachment = true;
 mSoftBody.validBounds = true;
}


VisualDebugger::VisualDebugger(World* world)
: mWorld(world), mRenderable(0), mMeshData(0)
{
 loadFromDescription(VisualDebuggerDescription());
 mMeshData = GC::safe_new0<VisualDebuggerMeshData>(NXOGRE_GC_THIS);
}

VisualDebugger::~VisualDebugger()
{
 GC::safe_delete(mMeshData, NXOGRE_GC_THIS);
}

void VisualDebugger::setRenderable(Renderable* renderable)
{
 mRenderable = renderable;
}

Renderable* VisualDebugger::getRenderable()
{
 return mRenderable;
}

void VisualDebugger::enable()
{
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 sdk->setParameter(NX_VISUALIZATION_SCALE, 1.0f);
 return;
}

void VisualDebugger::disable()
{
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 sdk->setParameter(NX_VISUALIZATION_SCALE, 0.0f);
 return;
}

void VisualDebugger::draw()
{
 
 mMeshData->mLines.remove_all();
 mMeshData->mColours.remove_all();
 mMeshData->mNbLines = 0;
 
 for (World::SceneIterator iterator = mWorld->getScenes(); iterator != iterator.end(); iterator++)
 {
  const NxDebugRenderable* renderable = iterator->getScene()->getDebugRenderable();
  
  if (renderable == 0)
   continue;
  
  unsigned int nbLines = renderable->getNbLines();
  const NxDebugLine* lines = renderable->getLines();
  while(nbLines--)
  {
   mMeshData->mLines.push_back(lines->p0.x);
   mMeshData->mLines.push_back(lines->p0.y);
   mMeshData->mLines.push_back(lines->p0.z);
   mMeshData->mLines.push_back(lines->p1.x);
   mMeshData->mLines.push_back(lines->p1.y);
   mMeshData->mLines.push_back(lines->p1.z);
   mMeshData->mColours.push_back(lines->color);
   mMeshData->mColours.push_back(lines->color);
   lines++;
  }
  mMeshData->mNbLines += renderable->getNbLines();
 }

 
 mRenderable->drawVisualDebugger(mMeshData);
}

void VisualDebugger::loadFromDescription(const VisualDebuggerDescription& desc)
{

 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 sdk->setParameter(NX_VISUALIZE_WORLD_AXES, float(desc.mWorld.axes));
 sdk->setParameter(NX_VISUALIZE_ACTOR_AXES,  float(desc.mRigidBody.actorAxes));
 sdk->setParameter(NX_VISUALIZE_BODY_AXES, float(desc.mRigidBody.bodyAxes));
 sdk->setParameter(NX_VISUALIZE_BODY_MASS_AXES, float(desc.mRigidBody.bodyAxes));
 sdk->setParameter(NX_VISUALIZE_BODY_LIN_VELOCITY,  float(desc.mRigidBody.linearVelocity));
 sdk->setParameter(NX_VISUALIZE_BODY_ANG_VELOCITY,  float(desc.mRigidBody.angularVelocity));
 sdk->setParameter(NX_VISUALIZE_BODY_JOINT_GROUPS,  float(desc.mRigidBody.jointGroups));
 sdk->setParameter(NX_VISUALIZE_JOINT_WORLD_AXES,  float(desc.mJoint.worldAxes));
 sdk->setParameter(NX_VISUALIZE_JOINT_LIMITS,  float(desc.mJoint.limits));
 sdk->setParameter(NX_VISUALIZE_CONTACT_POINT,  float(desc.mContact.point));
 sdk->setParameter(NX_VISUALIZE_CONTACT_NORMAL,  float(desc.mContact.normal));
 sdk->setParameter(NX_VISUALIZE_CONTACT_ERROR,  float(desc.mContact.error));
 sdk->setParameter(NX_VISUALIZE_CONTACT_FORCE,  float(desc.mContact.force));
 sdk->setParameter(NX_VISUALIZE_COLLISION_AABBS,  float(desc.mCollision.AABB));
 sdk->setParameter(NX_VISUALIZE_COLLISION_SHAPES,  float(desc.mCollision.shapes));
 sdk->setParameter(NX_VISUALIZE_COLLISION_AXES,  float(desc.mCollision.axes));
 sdk->setParameter(NX_VISUALIZE_COLLISION_COMPOUNDS,  float(desc.mCollision.compound));
 sdk->setParameter(NX_VISUALIZE_COLLISION_VNORMALS,  float(desc.mCollision.vNormals));
 sdk->setParameter(NX_VISUALIZE_COLLISION_FNORMALS,  float(desc.mCollision.fNormals));
 sdk->setParameter(NX_VISUALIZE_COLLISION_EDGES,  float(desc.mCollision.edges));
 sdk->setParameter(NX_VISUALIZE_COLLISION_SPHERES,  float(desc.mCollision.spheres));
 sdk->setParameter(NX_VISUALIZE_COLLISION_STATIC,  float(desc.mCollision.staticPruning));
 sdk->setParameter(NX_VISUALIZE_COLLISION_DYNAMIC,  float(desc.mCollision.dynamicPruning));
 sdk->setParameter(NX_VISUALIZE_COLLISION_FREE,  float(desc.mCollision.freePruning));
 sdk->setParameter(NX_VISUALIZE_COLLISION_CCD,  float(desc.mCollision.CCD));
 sdk->setParameter(NX_VISUALIZE_COLLISION_SKELETONS,  float(desc.mCollision.skeletons));
 sdk->setParameter(NX_VISUALIZE_FLUID_EMITTERS,  float(desc.mFluid.emitters));
 sdk->setParameter(NX_VISUALIZE_FLUID_POSITION,  float(desc.mFluid.position));
 sdk->setParameter(NX_VISUALIZE_FLUID_KERNEL_RADIUS,  float(desc.mFluid.kernelRadius));
 sdk->setParameter(NX_VISUALIZE_FLUID_BOUNDS,  float(desc.mFluid.bounds));
 sdk->setParameter(NX_VISUALIZE_FLUID_PACKETS,  float(desc.mFluid.packets));
 sdk->setParameter(NX_VISUALIZE_FLUID_MOTION_LIMIT,  float(desc.mFluid.motionLimit));
 sdk->setParameter(NX_VISUALIZE_FLUID_DYN_COLLISION,  float(desc.mFluid.dynamicCollision));
 sdk->setParameter(NX_VISUALIZE_FLUID_STC_COLLISION,  float(desc.mFluid.staticCollision));
 sdk->setParameter(NX_VISUALIZE_FLUID_MESH_PACKETS,  float(desc.mFluid.meshPackets));
 sdk->setParameter(NX_VISUALIZE_FLUID_DRAINS,  float(desc.mFluid.drains));
 sdk->setParameter(NX_VISUALIZE_FLUID_PACKET_DATA,  float(desc.mFluid.packetData));
 sdk->setParameter(NX_VISUALIZE_CLOTH_MESH,  float(desc.mCloth.mesh));
 sdk->setParameter(NX_VISUALIZE_CLOTH_COLLISIONS,  float(desc.mCloth.collisions));
 sdk->setParameter(NX_VISUALIZE_CLOTH_SELFCOLLISIONS,  float(desc.mCloth.selfCollisions));
 sdk->setParameter(NX_VISUALIZE_CLOTH_WORKPACKETS,  float(desc.mCloth.workPackets));
 sdk->setParameter(NX_VISUALIZE_CLOTH_SLEEP,  float(desc.mCloth.sleeping));
 sdk->setParameter(NX_VISUALIZE_CLOTH_TEARABLE_VERTICES,  float(desc.mCloth.tearableVertices));
 sdk->setParameter(NX_VISUALIZE_CLOTH_TEARING,  float(desc.mCloth.tearing));
 sdk->setParameter(NX_VISUALIZE_CLOTH_ATTACHMENT,  float(desc.mCloth.attachment));
 sdk->setParameter(NX_VISUALIZE_CLOTH_HIERARCHY,  float(desc.mCloth.hierarchy));
 sdk->setParameter(NX_VISUALIZE_CLOTH_HARD_STRETCHING_LIMITATION,  float(desc.mCloth.hardStretchingLimitation));
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_MESH,  float(desc.mSoftBody.mesh));
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_COLLISIONS,  float(desc.mSoftBody.collisions));
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_WORKPACKETS,  float(desc.mSoftBody.workPackets));
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_SLEEP,  float(desc.mSoftBody.sleeping));
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_TEARABLE_VERTICES,  float(desc.mSoftBody.tearableVertices));
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_TEARING,  float(desc.mSoftBody.tearing));
 sdk->setParameter(NX_VISUALIZE_SOFTBODY_ATTACHMENT,  float(desc.mSoftBody.attachment)); 
}

void VisualDebugger::saveToDescription(VisualDebuggerDescription& desc)
{

 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 desc.mWorld.axes = (bool)  sdk->getParameter(NX_VISUALIZE_WORLD_AXES);
 desc.mRigidBody.actorAxes = (bool)  sdk->getParameter(NX_VISUALIZE_ACTOR_AXES);
 desc.mRigidBody.bodyAxes = (bool)  sdk->getParameter(NX_VISUALIZE_BODY_AXES);
 desc.mRigidBody.bodyAxes = (bool)  sdk->getParameter(NX_VISUALIZE_BODY_MASS_AXES);
 desc.mRigidBody.linearVelocity = (bool)  sdk->getParameter(NX_VISUALIZE_BODY_LIN_VELOCITY);
 desc.mRigidBody.angularVelocity = (bool)  sdk->getParameter(NX_VISUALIZE_BODY_ANG_VELOCITY);
 desc.mRigidBody.jointGroups = (bool)  sdk->getParameter(NX_VISUALIZE_BODY_JOINT_GROUPS);
 desc.mJoint.worldAxes = (bool)  sdk->getParameter(NX_VISUALIZE_JOINT_WORLD_AXES);
 desc.mJoint.limits = (bool)  sdk->getParameter(NX_VISUALIZE_JOINT_LIMITS);
 desc.mContact.point = (bool)  sdk->getParameter(NX_VISUALIZE_CONTACT_POINT);
 desc.mContact.normal = (bool)  sdk->getParameter(NX_VISUALIZE_CONTACT_NORMAL);
 desc.mContact.error = (bool)  sdk->getParameter(NX_VISUALIZE_CONTACT_ERROR);
 desc.mContact.force = (bool)  sdk->getParameter(NX_VISUALIZE_CONTACT_FORCE);
 desc.mCollision.AABB = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_AABBS);
 desc.mCollision.shapes = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_SHAPES);
 desc.mCollision.axes = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_AXES);
 desc.mCollision.compound = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_COMPOUNDS);
 desc.mCollision.vNormals = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_VNORMALS);
 desc.mCollision.fNormals = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_FNORMALS);
 desc.mCollision.edges = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_EDGES);
 desc.mCollision.spheres = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_SPHERES);
 desc.mCollision.staticPruning = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_STATIC);
 desc.mCollision.dynamicPruning = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_DYNAMIC);
 desc.mCollision.freePruning = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_FREE);
 desc.mCollision.CCD = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_CCD);
 desc.mCollision.skeletons = (bool)  sdk->getParameter(NX_VISUALIZE_COLLISION_SKELETONS);
 desc.mFluid.emitters = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_EMITTERS);
 desc.mFluid.position = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_POSITION);
 desc.mFluid.kernelRadius = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_KERNEL_RADIUS);
 desc.mFluid.bounds = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_BOUNDS);
 desc.mFluid.packets = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_PACKETS);
 desc.mFluid.motionLimit = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_MOTION_LIMIT);
 desc.mFluid.dynamicCollision = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_DYN_COLLISION);
 desc.mFluid.staticCollision = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_STC_COLLISION);
 desc.mFluid.meshPackets = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_MESH_PACKETS);
 desc.mFluid.drains = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_DRAINS);
 desc.mFluid.packetData = (bool)  sdk->getParameter(NX_VISUALIZE_FLUID_PACKET_DATA);
 desc.mCloth.mesh = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_MESH);
 desc.mCloth.collisions = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_COLLISIONS);
 desc.mCloth.selfCollisions = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_SELFCOLLISIONS);
 desc.mCloth.workPackets = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_WORKPACKETS);
 desc.mCloth.sleeping = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_SLEEP);
 desc.mCloth.tearableVertices = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_TEARABLE_VERTICES);
 desc.mCloth.tearing = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_TEARING);
 desc.mCloth.attachment = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_ATTACHMENT);
 desc.mCloth.hierarchy = (bool)  sdk->getParameter(NX_VISUALIZE_CLOTH_HIERARCHY);
 desc.mCloth.hardStretchingLimitation = (bool) sdk->getParameter(NX_VISUALIZE_CLOTH_HARD_STRETCHING_LIMITATION);
 desc.mSoftBody.mesh = (bool)  sdk->getParameter(NX_VISUALIZE_SOFTBODY_MESH);
 desc.mSoftBody.collisions = (bool)  sdk->getParameter(NX_VISUALIZE_SOFTBODY_COLLISIONS);
 desc.mSoftBody.workPackets = (bool)  sdk->getParameter(NX_VISUALIZE_SOFTBODY_WORKPACKETS);
 desc.mSoftBody.sleeping = (bool)  sdk->getParameter(NX_VISUALIZE_SOFTBODY_SLEEP);
 desc.mSoftBody.tearableVertices = (bool)  sdk->getParameter(NX_VISUALIZE_SOFTBODY_TEARABLE_VERTICES);
 desc.mSoftBody.tearing = (bool)  sdk->getParameter(NX_VISUALIZE_SOFTBODY_TEARING);
 desc.mSoftBody.attachment = (bool)   sdk->getParameter(NX_VISUALIZE_SOFTBODY_ATTACHMENT);

}


                                                                                       

} // namespace NxOgre

                                                                                       
