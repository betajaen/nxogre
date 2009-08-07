/** File: OGRE3DRenderSystem.cpp
    Created on: 9-Nov-08
    Author: Robin Southern "betajaen"
    SVN: $Id$

    Copyright (c) 2008 Robin Southern

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

                                                                                       

#include "OGRE3DRenderSystem.h"
#include "NxOgre.h"
#include "OGRE3DBody.h"
#include "OGRE3DKinematicBody.h"
#include "OGRE3DRigidBodyPrototype.h"
#include "OGRE3DRenderable.h"
#include "OGRE3DPointRenderable.h"
#include "Ogre.h"

                                                                                       

unsigned int OGRE3DRenderSystem::mUniqueIdentifier = 0;

                                                                                       

OGRE3DRenderSystem::OGRE3DRenderSystem(NxOgre::Scene* scene, Ogre::SceneManager* sceneMgr)
: mScene(scene), mVisualDebuggerRenderable(0), mVisualDebuggerNode(0), mVisualDebuggerShown(false), mSceneManager(sceneMgr)
{

 ::NxOgre::TimeController::getSingleton()->addTimeListener(this, ::NxOgre::Enums::Priority_MediumLow);
}

OGRE3DRenderSystem::~OGRE3DRenderSystem(void)
{
 ::NxOgre::TimeController::getSingleton()->removeTimeListener(this, ::NxOgre::Enums::Priority_MediumLow);
 
 if (mVisualDebuggerRenderable)
 {
  mVisualDebuggerNode->detachObject(mVisualDebuggerRenderable);
  mSceneManager->getRootSceneNode()->removeAndDestroyChild(mVisualDebuggerNode->getName());
  destroyRenderable(mVisualDebuggerRenderable);
 }
 
 mBodies.destroyAll();
 mRenderables.destroyAll();
 mPointRenderables.destroyAll();
}

NxOgre::Scene* OGRE3DRenderSystem::getScene(void)
{
 return mScene;
}

OGRE3DBody* OGRE3DRenderSystem::createBody(NxOgre::Shape* shape, NxOgre::Vec3 position, const Ogre::String& meshName,  const NxOgre::RigidBodyDescription& description)
{
 // Create a OGRE3DPrototype using the NxOgre_New macro, all NxOgre classes and classes that
 // use PointerClass should use NxOgre_New and NxOgre_Delete.
 OGRE3DRigidBodyPrototype* prototype = NxOgre_New(OGRE3DRigidBodyPrototype)();
 
 if (prototype->mSceneManager == 0)
  prototype->mSceneManager = mSceneManager;
 
 // Send the physics stuff from the description into the prototype. This is quite important.
 NxOgre::Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 
 // We want a dynamic rigid body, that jumps around in the fjords with other dynamic rigid bodies.
 prototype->mType = NxOgre::Enums::RigidBodyType_Dynamic;

 // Copy the position over to the prototype.
 prototype->mGlobalPose.identity();
 prototype->mGlobalPose.set(position);

 // Add the shape to the list of shapes in the prototype.
 prototype->mShapes.insert(shape);

 // And our bits.
 prototype->mMeshName = meshName;

 // Create the body using again the NxOgre_New macro. Passing on the prototype we just created and a copy
 // of the scene pointer. we are using.
 OGRE3DBody* body = NxOgre_New(OGRE3DBody)(prototype, this);

 // Since the OGRE3DBody and NxOgre no longer needs the prototype, and we don't either. It's time to clean up.
 NxOgre_Delete(prototype);

 // Make a local copy.
 mBodies.insert(body);

 // And we are done.
 return body;
}


OGRE3DBody* OGRE3DRenderSystem::createBody(NxOgre::Shapes shapes, NxOgre::Vec3 position, const Ogre::String& meshName,  const NxOgre::RigidBodyDescription& description)
{
 // Create a OGRE3DPrototype using the NxOgre_New macro, all NxOgre classes and classes that
 // use PointerClass should use NxOgre_New and NxOgre_Delete.
 OGRE3DRigidBodyPrototype* prototype = NxOgre_New(OGRE3DRigidBodyPrototype)();
 
 if (prototype->mSceneManager == 0)
  prototype->mSceneManager = mSceneManager;
 
 // Send the physics stuff from the description into the prototype. This is quite important.
 NxOgre::Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 
 // We want a dynamic rigid body, that jumps around in the fjords with other dynamic rigid bodies.
 prototype->mType = NxOgre::Enums::RigidBodyType_Dynamic;

 // Copy the position over to the prototype.
 prototype->mGlobalPose.identity();
 prototype->mGlobalPose.set(position);

 // Copy the shapes in the prototype.
 prototype->mShapes = shapes;

 // And our bits.
 prototype->mMeshName = meshName;

 // Create the body using again the NxOgre_New macro. Passing on the prototype we just created and a copy
 // of the scene pointer. we are using.
 OGRE3DBody* body = NxOgre_New(OGRE3DBody)(prototype, this);

 // Since the OGRE3DBody and NxOgre no longer needs the prototype, and we don't either. It's time to clean up.
 NxOgre_Delete(prototype);

 // Make a local copy.
 mBodies.insert(body);

 // And we are done.
 return body;
}

void OGRE3DRenderSystem::destroyBody(OGRE3DBody* body)
{
 if (body == 0 || body->getClassType() != _OGRE3DBody)
  return;
 
 mBodies.remove(body);
 
 NxOgre_Delete(body);
}

OGRE3DRenderable* OGRE3DRenderSystem::createRenderable(NxOgre::Enums::RenderableType type, const Ogre::String& materialName)
{
 OGRE3DRenderable* renderable = new OGRE3DRenderable(type);
 mRenderables.insert(renderable);
 return renderable;
}

void OGRE3DRenderSystem::destroyRenderable(OGRE3DRenderable* renderable)
{
 if (renderable == 0)
  return;
 mRenderables.remove(renderable);
 NxOgre_Delete(renderable);
}

OGRE3DKinematicBody* OGRE3DRenderSystem::createKinematicBody(NxOgre::Shape* shape, NxOgre::Vec3 position, const Ogre::String& meshName, const NxOgre::RigidBodyDescription& description)
{
 // Create a OGRE3DPrototype using the NxOgre_New macro, all NxOgre classes and classes that
 // use PointerClass should use NxOgre_New and NxOgre_Delete.
 OGRE3DRigidBodyPrototype* prototype = NxOgre_New(OGRE3DRigidBodyPrototype)();
 
 if (prototype->mSceneManager == 0)
  prototype->mSceneManager = mSceneManager;
 
 // Send the physics stuff from the description into the prototype. This is quite important.
 NxOgre::Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 
 // We want a kinematic rigid body, so it can laugh at the other bodies as it defies gravity and ignores conventional forces.
 prototype->mType = NxOgre::Enums::RigidBodyType_Kinematic;

 // Copy the position over to the prototype.
 prototype->mGlobalPose.identity();
 prototype->mGlobalPose.set(position);

 // Add the shape to the list of shapes in the prototype.
 prototype->mShapes.insert(shape);

 // And our bits.
 prototype->mMeshName = meshName;

 // Create the body using again the NxOgre_New macro. Passing on the prototype we just created and a copy
 // of the scene pointer. we are using.
 OGRE3DKinematicBody* kinematicBody = NxOgre_New(OGRE3DKinematicBody)(prototype, this);

 // Since the OGRE3DBody and NxOgre no longer needs the prototype, and we don't either. It's time to clean up.
 NxOgre_Delete(prototype);

 // Make a local copy.
 mKinematicBodies.insert(kinematicBody);

 // And we are done.
 return kinematicBody;
}

void  OGRE3DRenderSystem::destroyKinematicBody(OGRE3DKinematicBody* kinematicBody)
{
 if (kinematicBody == 0 || kinematicBody->getClassType() != _OGRE3DKinematicBody)
  return;
 
 mKinematicBodies.remove(kinematicBody);
 
 NxOgre_Delete(kinematicBody);
}

bool OGRE3DRenderSystem::advance(float, const NxOgre::Enums::Priority&)
{
 if (mVisualDebuggerRenderable && mVisualDebuggerShown)
 {
  ::NxOgre::World::getWorld()->getVisualDebugger()->draw();
  mVisualDebuggerNode->needUpdate();
 }
 return true;
}

void OGRE3DRenderSystem::setVisualisationMode(NxOgre::Enums::VisualDebugger type)
{

 if (mVisualDebuggerRenderable == 0)
 {
  mVisualDebuggerRenderable = createRenderable(NxOgre::Enums::RenderableType_VisualDebugger);
  ::NxOgre::World::getWorld()->getVisualDebugger()->setRenderable(mVisualDebuggerRenderable);
  mVisualDebuggerNode = mSceneManager->getRootSceneNode()->createChildSceneNode();
  mVisualDebuggerNode->attachObject(mVisualDebuggerRenderable);
 }
 
 ::NxOgre::World::getWorld()->getVisualDebugger()->setVisualisationMode(type);
 
 if (type == NxOgre::Enums::VisualDebugger_ShowNone)
  mVisualDebuggerNode->setVisible(false);
 else
  mVisualDebuggerNode->setVisible(true);
 
 mVisualDebuggerShown = (type != NxOgre::Enums::VisualDebugger_ShowNone);
 
}

bool OGRE3DRenderSystem::hasDebugVisualisation(void) const
{
 return mVisualDebuggerRenderable && mVisualDebuggerShown;
}

OGRE3DPointRenderable* OGRE3DRenderSystem::createPointRenderable(const Ogre::String& ogre_mesh_name)
{
 OGRE3DPointRenderable* renderable = new OGRE3DPointRenderable(this, ogre_mesh_name);
 mPointRenderables.insert(renderable);
 return renderable;
}

OGRE3DPointRenderable* OGRE3DRenderSystem::createPointRenderable(Ogre::MovableObject* movable_object)
{
 OGRE3DPointRenderable* renderable = new OGRE3DPointRenderable(this, movable_object);
 mPointRenderables.insert(renderable);
 return renderable;
}

void OGRE3DRenderSystem::destroyPointRenderable(OGRE3DPointRenderable* renderable)
{
 if (renderable == 0)
  return;
 mPointRenderables.remove(renderable);
 NxOgre_Delete(renderable);
}

Ogre::SceneManager* OGRE3DRenderSystem::getSceneManager()
{
 return mSceneManager;
}

Ogre::String OGRE3DRenderSystem::getUniqueName(const Ogre::String& prefix) const
{
 return prefix + "-" + Ogre::StringConverter::toString(mUniqueIdentifier++);
}

NxOgre::Cloth* OGRE3DRenderSystem::createCloth(const NxOgre::ClothDescription& description, const Ogre::String& materialName)
{
 OGRE3DRenderable* renderable = createRenderable(NxOgre::Enums::RenderableType_PhysXMesh);
 mSceneManager->getRootSceneNode()->attachObject(renderable);
 renderable->setMaterial(materialName);
 return mScene->createCloth(description, renderable, NxOgre::Enums::Priority_MediumLow);
}

void OGRE3DRenderSystem::destroyCloth(NxOgre::Cloth* cloth)
{
 if (cloth == 0)
  return;

 OGRE3DRenderable* renderable = static_cast<OGRE3DRenderable*>(cloth->getRenderable());

 mSceneManager->getRootSceneNode()->detachObject(renderable);
 destroyRenderable(renderable);
 mScene->destroyCloth(cloth);
}

NxOgre::SoftBody* OGRE3DRenderSystem::createSoftBody(const NxOgre::SoftBodyDescription& description, const Ogre::String& materialName)
{
 OGRE3DRenderable* renderable = createRenderable(NxOgre::Enums::RenderableType_SoftBody);
 mSceneManager->getRootSceneNode()->attachObject(renderable);
 renderable->setMaterial(materialName);
 return mScene->createSoftBody(description, renderable, NxOgre::Enums::Priority_MediumLow);
}

void OGRE3DRenderSystem::destroySoftBody(NxOgre::SoftBody* cloth)
{
 if (cloth == 0)
  return;

 OGRE3DRenderable* renderable = static_cast<OGRE3DRenderable*>(cloth->getRenderable());

 mSceneManager->getRootSceneNode()->detachObject(renderable);
 destroyRenderable(renderable);
 mScene->destroySoftBody(cloth);
}

                                                                                       
