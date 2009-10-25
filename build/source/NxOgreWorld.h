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

#include "NxOgreWorldDescription.h"
#include "NxOgreScene.h"
#include "NxOgreSceneDescription.h"

                                                                                       

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
  
  typedef ptr_multihashmap<Scene>             Scenes;
  typedef ptr_multihashmap<Scene>::iterator_t SceneIterator;
  
  /*! function. precreateSingletons
      Pre-create singletons of NxOgre (ResourceSystem, MeshManager, HeightFieldManager, ErrorStream, etc.)
      
      example.
       NxOgre::ResourceSystem::getSingleton(); // == 0
       NxOgre::World::precreateSingletons();
       NxOgre::ResourceSystem::getSingleton(); // != 0
  */
  static               void                   precreateSingletons(void);

  /*! function. createWorld
      Create the World instance, and Singletons (if they aren't created).
      
      example.
       World* world = World::createWorld();
      
      args.
        const WorldDescription& = WorldDescription() -- Description of the World to use.
        
      note. If null is returned then you should check the log for the reason why it wasn't created.
      
      return. World* -- The World instance, or NULL if created.
  */
  static               World*                 createWorld(const WorldDescription& = WorldDescription());

  /*! function. destroyWorld
      Destroyer of World, Scenes and everything within.
      note. If you destroy the singletons, then World::destroySingletons does not need to be called.#

      args.
      bool _also_destroy_singletons_ -- Destroy the Singletons along with the world.
  */
  static               void                   destroyWorld(bool also_destroy_singletons = true);
  
  /*! function. destroySingletons
      Destroy singletons. This should be called AFTER destroyWorld.
      
      example.
      NxOgre::ResourceSystem::getSingleton(); // != 0
      NxOgre::World::precreateSingletons();
      NxOgre::ResourceSystem::getSingleton(); // == 0
      
  */
  static               void                   destroySingletons(void);

  /*! function. getWorld
      Get a copy of the World pointer.

      return. World* -- The World instance, or NULL if the World has not been created yet.
  */
  static               World*                 getWorld();

  /*! function. isDead
      Is the associated NxPhysicsSDK not created, or a serious error has happened that has made it unusable.

      return. bool -- If the NxPhysicsSDK is not created or a critical error has happened.
  */
                       bool                   isDead(void) const;

  /*! function. createScene
      Create a single scene with a SceneDescription as it's initial properties.

      example.
      Scene* scene = World::getWorld()->createScene();

      args.
      const SceneDescription&  = SceneDescription() -- SceneDescription to create the Scene with.

      return. Scene* -- The Scene, or NULL if the Scene was not created properly.
  */
                       Scene*                 createScene(const SceneDescription& = SceneDescription());

  /*! function. destroyScene
      Destroys a single scene and the contents within.
      
      args.
      Scene* -- The Scene to destroy
      
  */
                       void                   destroyScene(Scene*);

  /*! function. hasHardware
      Does the current computer have a PhysX accelerator, or a GPU capable of PhysX acceleration?
      
      return. bool -- If the hardware has a PhysX accelerator or capable GPU.
      
  */
                       bool                   hasHardware() const;

  /*! function. getNullCallback
      Get a copy of the Null Callback. Used for parts of NxOgre that don't have a user callback but still recieve events.
      note. This OWNED by NxOgre. Do not delete it.
      return. Callback* -- The callback
  */
                       Callback*              getNullCallback(void);
  
  /*! function. getVisualDebugger
      Get a copy of the VisualDebugger pointer.
      note. This OWNED by NxOgre. Do not delete it.
      return. VisualDebugger* -- The VisualDebugger
  */
                       VisualDebugger*        getVisualDebugger(void);
  
  /*! function. getRemoteDebugger
      Get a copy of the RemoteDebugger pointer.
      note. This OWNED by NxOgre. Do not delete it.
      return. RemoteDebugger* -- The RemoteDebugger
  */
                       RemoteDebugger*        getRemoteDebugger(void);
  
  /*! function. getScenes
      Get an iterator to the current Scenes in World.
      return. SceneIterator* -- A iterator to the Scenes.
  */
                       SceneIterator          getScenes(void);
  
  /*! function. getPhysXSDK
      Get a copy of the NxPhysicsSDK pointer.
      !physx
      note. This OWNED by NxOgre. Do not delete it.
      return. NxPhysicsSDK* -- The NxPhysicsSDK pointer
  */
                       NxPhysicsSDK*          getPhysXSDK(void);
  
  /*! function. getPhysXCookingInterface
      Get a copy of the NxCookingInterface pointer.
      !physx
      note. This OWNED by NxOgre. Do not delete it.
      return. NxCookingInterface* -- The NxCookingInterface pointer
  */
                       NxCookingInterface*    getPhysXCookingInterface(void);
  
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
                                             ~World(void);
  
  
  protected: // Variables
  
  /* Singleton
  */
  static              World*                  sWorldInstance;

  /* PhysX SDK instance
  */
                      NxPhysicsSDK*           mSDK;

  /* Cooking instance
  */
  static              NxCookingInterface*     mCookingInterface;

  /* If the SDK is dead or not
  */
                      bool                    mDeadSDK;

  /* World's PhysX output stream instance
  */
                      PhysXOutputStream*      mPhysXOutputStream;

  /* World's PhysX user allocator instance
  */
                      PhysXUserAllocator*     mPhysXUserAllocator;

  /* Master copy of all the Scenes in the World.
  */
                      Scenes                  mScenes;

  /* World's time controller instance
  */
                      TimeController*         mTimeController;

  /* Shared callback between classes that don't have a user callback.
  */
                      Callback*               mNullCallback;
  
  /* Global VisualDebugger.
  */
                      VisualDebugger*         mVisualDebugger;
  
  /* Global RemoteDebugger.
  */
                      RemoteDebugger*         mRemoteDebugger;
  
}; // class World

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
