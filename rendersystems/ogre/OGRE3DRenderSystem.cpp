/** File: OGRE3DRenderSystem.cpp
    Created on: 9-Nov-08
    Author: Robin Southern "betajaen"
    

    Copyright (c) 2008-2009 Robin Southern

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
#include "OGRE3DRigidBodyDescription.h"
#include "OGRE3DRenderable.h"
#include "OGRE3DPointRenderable.h"
#include "OGRE3DParticleRenderable.h"
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
 
 mBodies.clear();
 mRenderables.destroyAll();
 mPointRenderables.destroyAll();
}

NxOgre::Scene* OGRE3DRenderSystem::getScene(void)
{
 return mScene;
}

OGRE3DBody* OGRE3DRenderSystem::createBody(NxOgre::Shape* shape, const NxOgre::Matrix44& pose, const Ogre::String& meshName, OGRE3DRigidBodyDescription& description)
{
 description.mNode = mSceneManager->getRootSceneNode()->createChildSceneNode(NxOgre::Vec3(pose).as<Ogre::Vector3>(), NxOgre::Quat(pose).as<Ogre::Quaternion>());
 if (meshName.length())
  description.mNode->attachObject(mSceneManager->createEntity(getUniqueName("entity"), meshName));
 
 OGRE3DBody* body = NxOgre_New(OGRE3DBody)(shape, pose, description, this);
 
 mBodies.insert(body->getNameHash(), body);

 return body;
}


OGRE3DBody* OGRE3DRenderSystem::createBody(NxOgre::Shapes& shapes, const NxOgre::Matrix44& pose, const Ogre::String& meshName, OGRE3DRigidBodyDescription& description)
{
 description.mNode = mSceneManager->getRootSceneNode()->createChildSceneNode(NxOgre::Vec3(pose).as<Ogre::Vector3>(), NxOgre::Quat(pose).as<Ogre::Quaternion>());
 if (meshName.length())
  description.mNode->attachObject(mSceneManager->createEntity(getUniqueName("entity"), meshName));
 
 OGRE3DBody* body = NxOgre_New(OGRE3DBody)(shapes, pose, description, this);
 
 mBodies.insert(body->getNameHash(), body);

 return body;
}

OGRE3DBody* OGRE3DRenderSystem::createBody(NxOgre::Shape* shape, const NxOgre::Matrix44& pose, OGRE3DRigidBodyDescription& description)
{

 OGRE3DBody* body = NxOgre_New(OGRE3DBody)(shape, pose, description, this);
 mBodies.insert(body->getNameHash(), body);

 return body;
}


OGRE3DBody* OGRE3DRenderSystem::createBody(NxOgre::Shapes& shapes, const NxOgre::Matrix44& pose, OGRE3DRigidBodyDescription& description)
{

 OGRE3DBody* body = NxOgre_New(OGRE3DBody)(shapes, pose, description, this);
 mBodies.insert(body->getNameHash(), body);

 return body;
}

void OGRE3DRenderSystem::destroyBody(OGRE3DBody* body)
{
 if (body == 0 || body->getRigidBodyType() != _OGRE3DBody)
  return;
 
 mBodies.erase(body->getNameHash());
}

OGRE3DRenderSystem::BodyIterator OGRE3DRenderSystem::getBodies()
{
 return BodyIterator(mBodies);
}

OGRE3DRenderable* OGRE3DRenderSystem::createRenderable(int type, const Ogre::String& materialName)
{
 OGRE3DRenderable* renderable = new OGRE3DRenderable(type);
 renderable->setMaterial(materialName);
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

OGRE3DKinematicBody* OGRE3DRenderSystem::createKinematicBody(NxOgre::Shape* shape, const NxOgre::Matrix44& pose, const Ogre::String& meshName, OGRE3DRigidBodyDescription& description)
{
 description.mNode = mSceneManager->getRootSceneNode()->createChildSceneNode(NxOgre::Vec3(pose).as<Ogre::Vector3>(), NxOgre::Quat(pose).as<Ogre::Quaternion>());
 if (meshName.length())
  description.mNode->attachObject(mSceneManager->createEntity(getUniqueName("entity"), meshName));
 
 OGRE3DKinematicBody* kb = NxOgre_New(OGRE3DKinematicBody)(shape, pose, description, this);
 
 mKinematicBodies.insert(kb->getNameHash(), kb);

 return kb;
}

void  OGRE3DRenderSystem::destroyKinematicBody(OGRE3DKinematicBody* kinematicBody)
{
 if (kinematicBody == 0 || kinematicBody->getRigidBodyType() != _OGRE3DKinematicBody)
  return;
 
 mKinematicBodies.erase(kinematicBody->getNameHash());
 
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

 if (Ogre::MaterialManager::getSingletonPtr()->resourceExists("OGRE3DRenderSystem.VisualDebugger") == false)
 {
  Ogre::MaterialPtr material = Ogre::MaterialManager::getSingletonPtr()->create("OGRE3DRenderSystem.VisualDebugger", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
  material->getTechnique(0)->getPass(0)->setDepthBias(1);
  material->getTechnique(0)->getPass(0)->setAmbient(1,1,1);
  material->getTechnique(0)->getPass(0)->setSelfIllumination(1,1,1);
  material->getTechnique(0)->setLightingEnabled(false);
 }

 if (mVisualDebuggerRenderable == 0)
 {
  mVisualDebuggerRenderable = createRenderable(NxOgre::Enums::RenderableType_VisualDebugger, "OGRE3DRenderSystem.VisualDebugger");
  ::NxOgre::World::getWorld()->getVisualDebugger()->setRenderable(mVisualDebuggerRenderable);
  mVisualDebuggerRenderable->setCastShadows(false);
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


NxOgre::Fluid* OGRE3DRenderSystem::createFluid(const NxOgre::FluidDescription& description, const Ogre::String& materialName, OGRE3DFluidRenderableType renderable_type)
{

 NxOgre::Fluid* fluid;

 if (renderable_type == OGRE3DFluidType_OgreParticle)
 {
  OGRE3DParticleRenderable* renderable = new OGRE3DParticleRenderable(materialName, this);
  fluid = mScene->createFluid(description, renderable);
  renderable->initialise(fluid);
 }
 else
 {
  OGRE3DRenderable* renderable = createRenderable(renderable_type);
  mSceneManager->getRootSceneNode()->attachObject(renderable);
  renderable->setMaterial(materialName);
  fluid = mScene->createFluid(description, renderable);
 }
 
 return fluid;
}

void OGRE3DRenderSystem::destroyFluid(NxOgre::Fluid* fluid)
{
 
 if (fluid == 0)
  return;
 
 NxOgre::Renderable* renderable = fluid->getRenderable();
 
 if (renderable->getType() == OGRE3DFluidType_OgreParticle)
 {
  delete renderable;
 }
 else
 {
  OGRE3DRenderable* ogre_renderable = static_cast<OGRE3DRenderable*>(renderable);
  mSceneManager->getRootSceneNode()->detachObject(ogre_renderable);
  destroyRenderable(ogre_renderable);
 }
 
 mScene->destroyFluid(fluid);
}


                                                                                       
