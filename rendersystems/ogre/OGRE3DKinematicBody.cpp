/** File: OGRE3DKinematicBody.cpp
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

                                                                                       

#include "OGRE3DKinematicBody.h"
#include "OGRE3DRigidBodyDescription.h"
#include "OGRE3DRenderSystem.h"
#include "Ogre.h"
#include "NxOgreFunctions.h"
#include "NxOgreTimeController.h"

unsigned int OGRE3DKinematicBody::mNextBodyID = 0;

                                                                                       

OGRE3DKinematicBody::OGRE3DKinematicBody(NxOgre::Shape* shape, const NxOgre::Matrix44& pose, const OGRE3DRigidBodyDescription& description, OGRE3DRenderSystem* rendersystem)
: KinematicActor(rendersystem->getScene()),
                                   // Take notice of the constructor we are using, it's designed for
                                   // classes that inherit from Actor. 
 mNode(0),
 mSceneManager(0),
 mRenderPriority(description.mRenderPriority), 
 mSceneNodeDestructorBehaviour(description.mSceneNodeDestructorBehaviour)
{
 // Implement the prototype (it's being casted back into a RigidBodyPrototype) so it's treated
 // as a normal RigidBody. 
 
 createDynamic(pose, description, rendersystem->getScene(), shape);
 
 // Since NxOgre doesn't know or care about our Ogre stuff, we copy it over. This is the correct time to create
 // or turn on things related to the OGRE3DKinematicBody.
 
 mSceneManager = rendersystem->getSceneManager();
 
 mNode = description.mNode;
 
 // And let the time controller, that this is a timelistener that needs to be listened.
 NxOgre::TimeController::getSingleton()->addTimeListener(this, mRenderPriority);
}

OGRE3DKinematicBody::~OGRE3DKinematicBody()
{
 
 NxOgre::TimeController::getSingleton()->removeTimeListener(this, mRenderPriority);
 
 // In here, we would clean up any rendering stuff.
 _destructNode(mSceneNodeDestructorBehaviour);
 
 // We leave the physics stuff to the Actors destructor, including freeing the shapes.
}

void OGRE3DKinematicBody::_destructNode(OGRE3DSceneNodeDestructorBehaviour behaviour)
{
 
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
  mNode = 0;
 }
 
 
}

unsigned int OGRE3DKinematicBody::getClassType() const
{
 return _OGRE3DKinematicBody;
}

Ogre::SceneManager* OGRE3DKinematicBody::getSceneManager()
{
 return mSceneManager;
}

Ogre::SceneNode* OGRE3DKinematicBody::getSceneNode()
{
 return mNode;
}


bool OGRE3DKinematicBody::advance(float, const NxOgre::Enums::Priority&)
{
 // "Rendering" in Ogre merely means just moving a scenenode to it's new position and orientation.
 Ogre::Matrix4 m4 = toMatrix44(getGlobalPose());
 mNode->setPosition(m4.getTrans());
 mNode->setOrientation(m4.extractQuaternion());
 return true;
}

                                                                                       
