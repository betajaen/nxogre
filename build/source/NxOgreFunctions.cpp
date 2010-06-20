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
#include "NxOgreFunctions.h"
#include "NxOgreCallback.h"
#include "NxOgreActor.h"
#include "NxOgreScene.h"

#if NxOgreHasCharacterController == 1
#include "NxOgreCharacterController.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

class VolumePhysicsFunctionCallback : public Callback
{
 public:
  
  // takes care of garbage collection.
  bool shouldDelete() const
  {
   return true;
  }
  
  virtual void onVolumeEvent(Volume*, Shape*, RigidBody*, Shape*, unsigned int collisionEvent)
  { // virtual function.
  }
  
};


class VolumePhysicsFunctionRaiseClearFlags : public VolumePhysicsFunctionCallback
{
  
 public:
  
  VolumePhysicsFunctionRaiseClearFlags(NxOgre::DynamicRigidbodyFlags::Flags flag, 
           NxOgre::Enums::VolumeCollisionType volume_raise_event = NxOgre::Enums::VolumeCollisionType_OnEnter,
           NxOgre::Enums::VolumeCollisionType volume_clear_event = NxOgre::Enums::VolumeCollisionType_OnExit)
           : mFlag(flag), mRaiseEvent(volume_raise_event), mClearEvent(volume_clear_event)
  {
  }
  
  void onVolumeEvent(Volume*, Shape*, RigidBody* rbody, Shape*, unsigned int collisionEvent)
  {
   if (rbody->isActorBased() == false)
    return;
   
   Actor* actor = static_cast<Actor*>(rbody);
   if (collisionEvent & mRaiseEvent)
    actor->raiseDynamicFlag(mFlag);
   else if (collisionEvent & mClearEvent)
    actor->clearDynamicFlag(mFlag);
  }
  
  NxOgre::DynamicRigidbodyFlags::Flags mFlag;
  unsigned int                         mRaiseEvent;
  unsigned int                         mClearEvent;

};

Callback* VolumePhysicsFunction::raise_clear_flag(NxOgre::DynamicRigidbodyFlags::Flags flag, 
           NxOgre::Enums::VolumeCollisionType raise,
           NxOgre::Enums::VolumeCollisionType clear)
{
 return GC::safe_new3<VolumePhysicsFunctionRaiseClearFlags>(flag, raise, clear, NXOGRE_GC_THIS);
}

class VolumePhysicsFunctionMoveToGlobal : public VolumePhysicsFunctionCallback
{
  
 public:
  
  VolumePhysicsFunctionMoveToGlobal(const Vec3& globalPos, Real acceleration)
           : mGlobalPosition(globalPos), mAcceleration(acceleration)
  {
  }
  
  void onVolumeEvent(Volume*, Shape*, RigidBody* rbody, Shape*, unsigned int collisionEvent)
  {
   if ((collisionEvent & Enums::VolumeCollisionType_OnPresence) == false)
    return;
   
   if (rbody->isActorBased())
   {
     Actor* actor = static_cast<Actor*>(rbody);
     
     Vec3 V = mGlobalPosition - actor->getGlobalPosition(); // S
          V.normalise();       // Direction
          V *= mAcceleration;  // A
     
     actor->setLinearVelocity(V);
   }
   
#if NxOgreHasCharacterController == 1
   
   else if (rbody->isCharacterControllerBased())
   {
    CharacterController* controller = static_cast<CharacterController*>(rbody);
    
    Vec3  relX = mGlobalPosition - controller->getPosition(); // S
          relX.normalise();       // Direction
          relX *= mAcceleration;  // A

     Vec3 S = relX * _1_60;
    
    controller->move(S);
   }
   
#endif
   
  }
  
  Vec3 mGlobalPosition;
  Real mAcceleration;
};


Callback* VolumePhysicsFunction::move_to(const Vec3& globalPosition, Real acceleration)
{
 return GC::safe_new2<VolumePhysicsFunctionMoveToGlobal>(globalPosition, acceleration, NXOGRE_GC_THIS);
}


class VolumePhysicsFunctionTeleportToGlobal : public VolumePhysicsFunctionCallback
{
  
 public:
  
  VolumePhysicsFunctionTeleportToGlobal(const Vec3& globalPos, NxOgre::Enums::VolumeCollisionType teleport_event)
  : mGlobalPosition(globalPos), mEvent(teleport_event)
  {
  }
  
  void onVolumeEvent(Volume*, Shape*, RigidBody* rbody, Shape*, unsigned int collisionEvent)
  {
   if ((collisionEvent & mEvent) == false)
    return;
   
   if (rbody->isActorBased())
   {
    Actor* actor = static_cast<Actor*>(rbody);
    actor->setGlobalPosition(mGlobalPosition);
   }

#if NxOgreHasCharacterController == 1
   
   else if (rbody->isCharacterControllerBased())
   {
    CharacterController* controller = static_cast<CharacterController*>(rbody);
    controller->setPosition(mGlobalPosition);
   }
   
#endif

  }
  
  Vec3 mGlobalPosition;
  NxOgre::Enums::VolumeCollisionType mEvent;
};


Callback* VolumePhysicsFunction::teleport_to(const Vec3& globalPosition, NxOgre::Enums::VolumeCollisionType teleport_event)
{
 return GC::safe_new2<VolumePhysicsFunctionTeleportToGlobal>(globalPosition, teleport_event, NXOGRE_GC_THIS);
}

                                                                                       

} // namespace NxOgre

                                                                                       
