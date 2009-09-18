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
#include "NxOgrePhysXCallback.h"
#include "NxOgreCallback.h"

#include "NxOgreVolume.h"
#include "NxOgreShape.h"
#include "NxOgreBox.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreRigidBody.h"
#include "NxOgreContactPair.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXCallback::PhysXCallback(Scene* scene) : mScene(scene)
{
}

PhysXCallback::~PhysXCallback()
{
}

void PhysXCallback::onTrigger(NxShape& triggerShape, NxShape& physxCollisionShape, NxTriggerFlag status)
{
 
 if (!triggerShape.getActor().userData && !physxCollisionShape.getActor().userData)
  return;
 
 Shape* volume_shape = pointer_representive_cast<Shape>(triggerShape.userData);
 RigidBody* rb_volume = pointer_parent_cast<RigidBody>(triggerShape.userData);
 Volume* volume = static_cast<Volume*>(rb_volume);
 
 Shape* collision_shape = 0;
 RigidBody* collision_body = 0;

 if (physxCollisionShape.userData)
 {
  collision_shape = pointer_representive_cast<Shape>(physxCollisionShape.userData);
  collision_body  = pointer_parent_cast<RigidBody>(physxCollisionShape.userData);
 }
 
 volume->getVolumeCallback()->onVolumeEvent(volume, volume_shape, collision_body, collision_shape, status);
 
}

void PhysXCallback::onContactNotify(NxContactPair &pair, NxU32 events)
{
 
 if (pair.isDeletedActor[0] || pair.isDeletedActor[1])
  return;
 
 if (!pair.actors[0]->userData && !pair.actors[1]->userData)
  return;
 
 RigidBody* rbody_a = pointer_representive_cast<RigidBody>(pair.actors[0]->userData);
 RigidBody* rbody_b = pointer_representive_cast<RigidBody>(pair.actors[1]->userData);
 
 ContactPair contact_pair;
 contact_pair.mFirst = rbody_a;
 contact_pair.mSecond = rbody_b;
 contact_pair.mSumFrictionForce = pair.sumFrictionForce;
 contact_pair.mSumNormalForce = pair.sumNormalForce;
 
 if (rbody_a->getContactCallback() != 0)
  rbody_a->getContactCallback()->onContact(contact_pair);
 
 if (rbody_b->getContactCallback() != 0)
  rbody_b->getContactCallback()->onContact(contact_pair);
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
