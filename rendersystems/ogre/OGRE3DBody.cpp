/** File: OGRE3DBody.cpp
    Created on: 10-Nov-08
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

                                                                                       

#include "OGRE3DBody.h"
#include "OGRE3DRigidBodyDescription.h"
#include "OGRE3DRenderSystem.h"
#include "Ogre.h"
#include "NxOgreFunctions.h"
#include "NxOgreTimeController.h"

unsigned int OGRE3DBody::mNextBodyID = 0;

                                                                                       

OGRE3DBody::OGRE3DBody(NxOgre::Shape* shape, const NxOgre::Matrix44& pose, OGRE3DRigidBodyDescription& description, OGRE3DRenderSystem* rendersystem)
: Actor(rendersystem->getScene()), // Take notice of the constructor we are using, it's designed for
                                   // classes that inherit from Actor. 
 mSceneNodeDestructorBehaviour(description.mSceneNodeDestructorBehaviour),
 mRenderPriority(description.mRenderPriority),
 mRenderSystem(rendersystem)
{
 
 // Create a dynamic RigidBody with the pose, scene and shape.
 // We can pass on the OGRE3DRigidBodyDescription as a RigidBodyDescription because it inherits from it,
 createDynamic(pose, description, rendersystem->getScene(), shape);

 // Obviously NxOgre won't know about the Ogre bits, so this is what the next lines are for:
 mSceneManager = rendersystem->getSceneManager();
 mNode = description.mNode;

 // And let the time controller know about it. So it will call the advance function every frame.
 NxOgre::TimeController::getSingleton()->addTimeListener(this, mRenderPriority);
}

OGRE3DBody::OGRE3DBody(NxOgre::Shapes& shapes, const NxOgre::Matrix44& pose, OGRE3DRigidBodyDescription& description, OGRE3DRenderSystem* rendersystem)
: Actor(rendersystem->getScene()), // Take notice of the constructor we are using, it's designed for
                                   // classes that inherit from Actor. 
 mSceneNodeDestructorBehaviour(description.mSceneNodeDestructorBehaviour),
 mRenderPriority(description.mRenderPriority),
 mRenderSystem(rendersystem)
{
 
 // Create a dynamic RigidBody with the pose, scene and shape.
 // We can pass on the OGRE3DRigidBodyDescription as a RigidBodyDescription because it inherits from it,
 createDynamic(pose, description, rendersystem->getScene(), shapes);
 mAlphaPose = pose;
 
 // Obviously NxOgre won't know about the Ogre bits, so this is what the next lines are for:
 mSceneManager = rendersystem->getSceneManager();
 mNode = description.mNode;

 // And let the time controller know about it. So it will call the advance function every frame.
 NxOgre::TimeController::getSingleton()->addTimeListener(this, mRenderPriority);
}

OGRE3DBody::~OGRE3DBody()
{
 
 // Stop NxOgre calling the advance function in the future, otherwise bad things would happen.
 NxOgre::TimeController::getSingleton()->removeTimeListener(this, mRenderPriority);
 
 // In here, we would clean up any rendering stuff, and things that Actor couldn't possiblty know about.
 _destructNode(mSceneNodeDestructorBehaviour);
 
 // As we inherit from Actor, it's destructor will be called now. Including the "destroy()" function which
 // cleans up the Physics.
}

void OGRE3DBody::_destructNode(OGRE3DSceneNodeDestructorBehaviour behaviour)
{
 
 if (mNode == 0)
  return;
 
 if (behaviour == OGRE3DSceneNodeDestructorBehaviour_Inherit)
  behaviour = mSceneNodeDestructorBehaviour;
 
 if (behaviour == OGRE3DSceneNodeDestructorBehaviour_Destroy)
 {
  // Remove all attachments.
  if (mNode->numAttachedObjects())
   mNode->detachAllObjects();
  
  // Destroy all child scenenodes.
  if (mNode->numChildren())
   mNode->removeAndDestroyAllChildren();
  
  // Destroy this Scene node.
  mNode->getParentSceneNode()->removeAndDestroyChild(mNode->getName());
  mNode = 0;
 }
 else
 {
  mNode->getParentSceneNode()->removeChild(mNode);
  mNode;
 }
 
}

unsigned int OGRE3DBody::getRigidBodyType() const
{
 return _OGRE3DBody;
}

Ogre::SceneManager* OGRE3DBody::getSceneManager()
{
 return mSceneManager;
}

Ogre::SceneNode* OGRE3DBody::getSceneNode()
{
 return mNode;
}

void OGRE3DBody::setSceneNode(Ogre::SceneNode* node, OGRE3DSceneNodeDestructorBehaviour behaviour)
{
 _destructNode(behaviour);
 mNode = node;
}

OGRE3DSceneNodeDestructorBehaviour OGRE3DBody::getSceneNodeDestructorBehaviour() const
{
 return mSceneNodeDestructorBehaviour;
}

void OGRE3DBody::setSceneNodeDestructorBehaviour(OGRE3DSceneNodeDestructorBehaviour behaviour)
{
 mSceneNodeDestructorBehaviour = behaviour;
}

bool OGRE3DBody::advance(float step, const NxOgre::Enums::Priority&)
{
#if 0
 
 NxOgre::TimeStep& ts = mScene->getTimeStep();
 NxOgre::Matrix44 current_pose(getGlobalPose());
 
 if (mScene->getTimeStep().mSubSteps) // Did simulate this frame?
  mAlphaPose = current_pose;
 
 NxOgre::Matrix44 render_pose;
 NxOgre::Math::interpolate(mAlphaPose, current_pose, render_pose, ts.mAlpha);
 
 mNode->setPosition(NxOgre::Vec3(render_pose).as<Ogre::Vector3>());
 mNode->setOrientation(NxOgre::Quat(render_pose).as<Ogre::Quaternion>());
 
#else
 mNode->setPosition(NxOgre::Vec3(getGlobalPose()).as<Ogre::Vector3>());
 mNode->setOrientation(NxOgre::Quat(getGlobalPose()).as<Ogre::Quaternion>());
#endif
 
 return true;
}

                                                                                       
