/*
    
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

                                                                                       

#ifndef NXOGRE_WORLD_H
#define NXOGRE_WORLD_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreEnums.h"

#include "NxOgreWorldDescription.h"
#include "NxOgreScene.h"
#include "NxOgreSceneDescription.h"
#include "NxOgreSceneLink.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. World
    
    World is the main singleton class of NxOgre. Always created first and destroyed last.
    
    example.
    #include "NxOgre.h"
    
    class myApp
    {
     public:
     
    	myApp()
    	{
    	 mWorld = NxOgre::World::createWorld();
    	}
    
     protected:
    	NxOgre::World* mWorld;
    };
*/
class NxOgrePublicClass World : public BigClassAllocatable
{
  
  public: // Functions
  
  NXOGRE_GC_FRIEND_NEW1
  NXOGRE_GC_FRIEND_DELETE

  typedef multihashmap<Scene*, GC::HasGarbageCollection> Scenes;
  typedef multihashmap_iterator<Scene*>                  SceneIterator;

  typedef vector<Scene*, GC::NoGarbageCollection>        SceneBuffer;
  typedef vector_iterator<Scene*>                        SceneBufferIterator;
  
  typedef vector<SceneLink*, GC::HasGarbageCollection>   SceneLinks;
  typedef vector_iterator<SceneLink*>                    SceneLinkIterator;

  /*! function. precreateSingletons
      Pre-create singletons of NxOgre (ResourceSystem, MeshManager, HeightFieldManager, ErrorStream, etc.)
      
      example.
       NxOgre::ResourceSystem::getSingleton(); // == 0
       NxOgre::World::precreateSingletons();
       NxOgre::ResourceSystem::getSingleton(); // != 0
  */
  static  void  precreateSingletons();

  /*! function. createWorld
      Create the World instance, and Singletons (if they aren't created).
      
      example.
       World* world = World::createWorld();
      
      args.
        const WorldDescription& = WorldDescription() -- Description of the World to use.
        
      note. If null is returned then you should check the log for the reason why it wasn't created.
      
      return. World* -- The World instance, or NULL if created.
  */
  static  World*  createWorld(const WorldDescription& = WorldDescription());

  /*! function. destroyWorld
      Destroyer of World, Scenes and everything within.
      note. If you destroy the singletons, then World::destroySingletons does not need to be called.#

      args.
      bool _also_destroy_singletons_ -- Destroy the Singletons along with the world.
  */
  static  void  destroyWorld(bool also_destroy_singletons = true);
  
  /*! function. destroySingletons
      Destroy singletons. This should be called AFTER destroyWorld.
      
      example.
      NxOgre::ResourceSystem::getSingleton(); // != 0
      NxOgre::World::precreateSingletons();
      NxOgre::ResourceSystem::getSingleton(); // == 0
      
  */
  static  void  destroySingletons();

  /*! function. getWorld
      Get a copy of the World pointer.

      return. World* -- The World instance, or NULL if the World has not been created yet.
  */
  static  World*  getWorld();

  /*! function. getSingleton
      Get a copy of the World pointer.

      return. World* -- The World instance, or NULL if the World has not been created yet.
  */
  static  World*  getSingleton();

  /*! function. isDead
      Is the associated NxPhysicsSDK not created, or a serious error has happened that has made it unusable.

      return. bool -- If the NxPhysicsSDK is not created or a critical error has happened.
  */
  bool  isDead() const;

  /*! function. createScene
      Create a single scene with a SceneDescription as it's initial properties.

      example.
      Scene* scene = World::getWorld()->createScene();

      args.
       const SceneDescription&  = SceneDescription() -- SceneDescription to create the Scene with.
       Enums::SceneType = Enums:SceneType_Principal -- Create a Principal or Auxiliary Scene.
       Enums::SceneSource = Enums::SceneType_Prinicipal -- Internal. Do not use.
      return. Scene* -- The Scene, or NULL if the Scene was not created properly.
  */
  Scene*  createScene(const SceneDescription& = SceneDescription(), Enums::SceneType = Enums::SceneType_Prinicipal);
  
  /*! function. destroyScene
      Destroys a single scene and the contents within.
      
      args.
      Scene* -- The Scene to destroy
      
  */
  void  destroyScene(Scene*);


  /*! function. hasHardware
      desc.
          Does the current computer have a PhysX accelerator, or a GPU capable of PhysX acceleration?
      
      return.
          bool -- If the hardware has a PhysX accelerator or capable GPU.
      
  */
  bool  hasHardware() const;

  /*! function. getNullCallback
      Get a copy of the Null Callback. Used for parts of NxOgre that don't have a user callback but still recieve events.
      note. This OWNED by NxOgre. Do not delete it.
      return. Callback* -- The callback
  */
  Callback*  getNullCallback() const;

  /*! function. getVisualDebugger
      Get a copy of the VisualDebugger pointer.
      note. This OWNED by NxOgre. Do not delete it.
      return. VisualDebugger* -- The VisualDebugger
  */
  VisualDebugger*  getVisualDebugger() const;

  /*! function. getRemoteDebugger
      Get a copy of the RemoteDebugger pointer.
      note. This OWNED by NxOgre. Do not delete it.
      return. RemoteDebugger* -- The RemoteDebugger
  */
  RemoteDebugger*  getRemoteDebugger() const;

  /*! function. getScenes
      Get an iterator to the current Scenes in World.
      return. SceneIterator* -- A iterator to the Scenes.
  */
  SceneIterator  getScenes() const;
  
  /*! function. getPhysXSDK
      Get a copy of the NxPhysicsSDK pointer.
      !physx
      note. This OWNED by NxOgre. Do not delete it.
      return. NxPhysicsSDK* -- The NxPhysicsSDK pointer
  */
  NxPhysicsSDK*  getPhysXSDK() const;
  
  /*! function. getPhysXCookingInterface
      Get a copy of the NxCookingInterface pointer.
      !physx
      note. This OWNED by NxOgre. Do not delete it.
      return. NxCookingInterface* -- The NxCookingInterface pointer
  */
  NxCookingInterface*  getPhysXCookingInterface() const;


#if NxOgreHasCharacterController == 1
  
  /*! function. getPhysXControllerManager
      Get a copy of the NxControllerManager pointer.
      !physx
      note. This OWNED by NxOgre. Do not delete it.
      return. NxControllerManager* -- The NxControllerManager pointer
  */
  NxControllerManager*  getPhysXControllerManager();
#endif

  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;

  /*! function. advance
      desc.
          Advance all scenes by deltaTime
  */
  void advance(Real deltaTime);

  /*! function. setSkinWidth
      desc.
          Set default value for shape skin width.
  */
  void  setSkinWidth(float value = 0.025f);

  /*! function. setSkinWidth
      desc.
          Get default value for shape skin width.
  */
  float  getSkinWidth() const;

  /*! function. setDefaultSleepLinearVelocitySquared
      desc.
          Set default linear velocity (squared), before objects start
          going to sleep.
  */
  void setDefaultSleepLinearVelocitySquared(float value = 0.15 * 0.15);

  /*! function. getDefaultSleepLinearVelocitySquared
      desc.
          Set default linear velocity (squared), before objects start
          going to sleep.
  */
  float getDefaultSleepLinearVelocitySquared() const;

  /*! function. setDefaultSleepAngularVelocitySquared
      desc.
          Set default angular velocity (squared), before objects start
          going to sleep.
  */
  void setDefaultSleepAngularVelocitySquared(float value = 0.14 * 0.14);

  /*! function. getDefaultSleepAngularVelocitySquared
      desc.
          Set default angular velocity (squared), before objects start
          going to sleep.
  */
  float getDefaultSleepAngularVelocitySquared() const;

  /*! function. setBounceThreshold
      desc.
          A contact with a relative velocity below this should not
          bounce.
      note.
          range: [-inf, 0)
  */
  void setBounceThreshold(float = -2.0f);

  /*! function. getBounceThreshold
      desc.
          A contact with a relative velocity below this should not
          bounce.
  */
  float getBounceThreshold() const;

  /*! function. setDynamicFrictionScaling
      desc.
          Scale the magnitude of dynamic friction to all objects.
      note.
          range: [-inf, 0)
  */
  void setDynamicFrictionScaling(float = 1.0f);

  /*! function. getDynamicFrictionScaling
      desc.
          Scale the magnitude of dynamic friction to all objects.
  */
  float getDynamicFrictionScaling() const;

  /*! function. setStaticFrictionScaling
      desc.
          Scale the magnitude of dynamic friction to all objects.
      note.
          range: [-inf, 0)
  */
  void setStaticFrictionScaling(float = 1.0f);

  /*! function. getStaticFrictionScaling
      desc.
          Scale the magnitude of dynamic friction to all objects.
  */
  float getStaticFrictionScaling() const;

  /*! function. setMaxAngularVelocity
      desc.
          Set's the max angular velocity of a dynamic RigidBody.
      note.
          range: [-inf, 0)
  */
  void setMaxAngularVelocity(float = 7.0f);

  /*! function. getMaxAngularVelocity
      desc.
          Set's the max angular velocity of a dynamic RigidBody.
  */
  float getMaxAngularVelocity() const;

  /*! function. setCCDEnabled
      desc.
          Set CCD to be enabled or disabled.
  */
  void  setCCDEnabled(bool = false);

  /*! function. getCCDEnabled
      desc.
          Is CCD enabled?
  */
  bool  getCCDEnabled() const;

  /*! function. setCCDEnabled
      desc.
          Set the distance epsilion for the CCD algorithm.
  */
  void  setCCDEpsilon(float = 0.01f);

  /*! function. getCCDEnabled
      desc.
          Get the distance epsilion for the CCD algorithm.
  */
  float  getCCDEpilson() const;

  /*! function. setAdaptiveForce
      desc.
          Used to enable adaptive forces to accelerate convergence of the solver.
  */
  void  setAdaptiveForce(float = 1.0);

  /*! function. getAdaptiveForce
      desc.
          Used to enable adaptive forces to accelerate convergence of the solver.
  */
  float  getAdaptiveForce() const;

  /*! function. setJointCollisionsEnabled
      desc.
          Controls default filtering for jointed bodies. True means collision is disabled.
  */
  void  setJointCollisionsEnabled(bool);

  /*! function. getJointCollisionsEnabled
      desc.
          Controls default filtering for jointed bodies. True means collision is disabled.
  */
  bool  getJointCollisionsEnabled() const;

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Controls whether two touching triggers generate a callback or not.
  */
  void  setTriggerTriggerCallbackEnabled(bool = true);

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Controls whether two touching triggers generate a callback or not.
  */
  bool  getTriggerTriggerCallbackEnabled() const;

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Used to accelerate the solver.
  */
  void  setSolverConvergenceThreshold(float = 0);

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Controls whether two touching triggers generate a callback or not.
  */
  float  getSolverConvergenceThreshold() const;

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Used to accelerate HW Broad Phase.

  */
  void  setBoundingBoxNoiseLevel(float = 0.001f);

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Used to accelerate HW Broad Phase.
  */
  float  getBoundingBoxNoiseLevel() const;

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Used to set the sweep cache size.
  */
  void  setImplicitSweepCacheSize(float = 5.0f);

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Used to set the sweep cache size.
  */
  float  getImplicitSweepCacheSize() const;

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          The default sleep energy threshold, when 
NxOgre::DynamicRigidbodyFlags::EnergySleepTest is set.
  */
  void  setDefaultSleepEnergy(float = 0.005f);

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          The default sleep energy threshold, when 
NxOgre::DynamicRigidbodyFlags::EnergySleepTest is set.
  */
  float  getDefaultSleepEnergy() const;

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          [Experimental] Disables scene locks when creating/releasing meshes.
  */
  void  setAsynchronousMeshCreation(bool = false);

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          [Experimental] Disables scene locks when creating/releasing meshes.
  */
  bool  getAsynchronousMeshCreation() const;

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Epsilon for custom force field kernels.
  */
  void  setForceFieldCustomKernelEpsilon(float = 0.001f);

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Epsilon for custom force field kernels.
  */
  float  getForceFieldCustomKernelEpsilon() const;

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Enable/disable improved spring solver for joints and wheelshapes.
  */
  void  setImprovedSpringSolver(bool = false);

  /*! function. setTriggerTriggerCallbackEnabled
      desc.
          Enable/disable improved spring solver for joints and wheelshapes.
  */
  bool  getImprovedSpringSolver() const;


  protected: // Functions
  
  /*! function. Constructor
      !private
      see. World::createWorld
  */
  World(const WorldDescription&);
  
  /*! function. Destructor
      !private
      see. World::destroyWorld
  */
  ~World();
  
  protected: // Under construction
  
  /*! function. createSceneLink
      desc.
          Internal do not use.
  */
  SceneLink*  createSceneLink(PrincipalScene* first, AuxiliaryScene* second);

  /*! function. createSceneLink
      desc.
          Internal do not use.
  */
  SceneLink*  createSceneLink(PrincipalScene* first);

  /*! function. createSceneLink
      desc.
          Internal do not use.
  */
  void  destroySceneLink(SceneLink*);
  
  protected: // Variables
  
  /* Singleton
  */
  static  World*  sWorldInstance;

  /* PhysX SDK instance
  */
  NxPhysicsSDK*  mSDK;

  /* Cooking instance
  */
  static  NxCookingInterface*     mCookingInterface;

  /* If the SDK is dead or not
  */
  bool  mDeadSDK;

  /* World's PhysX output stream instance
  */
  PhysXOutputStream*  mPhysXOutputStream;

  /* World's PhysX user allocator instance
  */
  PhysXUserAllocator*  mPhysXUserAllocator;

  /* Master copy of all the Scenes in the World.
  */
  Scenes  mScenes;

  /* Master copy of all the Scenes in the World.
  */
  SceneLinks  mSceneLinks;

  /* Shared callback between classes that don't have a user callback.
  */
  Callback*  mNullCallback;
  
  /* Global VisualDebugger.
  */
  VisualDebugger*  mVisualDebugger;
  
  /* Global RemoteDebugger.
  */
  RemoteDebugger*  mRemoteDebugger;
  
  /* Scenes that are still processing.
  */
  SceneBuffer  mSceneSecondaryBuffer;
  
  /* Scenes that are STILL processing, I mean really!
  */
  SceneBuffer  mSceneTertiaryBuffer;

#if NxOgreHasCharacterController == 1
  /*
  */
  NxControllerManager*   mControllerManager;
#endif

}; // class World

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
