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
    
*/
class NxOgrePublicClass World : public PointerClass<Classes::_World>
{
  
  public: // Functions
  
  typedef ptr_multihashmap<Scene>             Scenes;
  typedef ptr_multihashmap<Scene>::iterator_t SceneIterator;
  
  /*! function. precreateSingletons
      Pre-create singletons of NxOgre (ResourceSystem, MeshManager, HeightFieldManager, ErrorStream, etc.)
  */
  static               void                   precreateSingletons(void);

  /*! function. createWorld.WorldDescription
      Create the World instance, and Singletons (if they aren't created).
      example.
      World* world = World::createWorld();
      args.
      - const WorldDescription& := Description of the World to use.
      note. If null is returned then you should check the log for the reason why it wasn't created.
      return. **World** * -- The World instance, or NULL if created.
  */
  static               World*                 createWorld(const WorldDescription& = WorldDescription());
  
  /*! function. createWorld.WorldPrototype
      Create the World instance, and Singletons (if they aren't created).
      example.
      World* world = World::createWorld(prototype);
      args.
      - *WorldPrototype** prototype := Prototype to create from.
      note. If null is returned then you should check the log for the reason why it wasn't created.
      return. **World* * -- The World instance, or NULL if created.
  */
  static               World*                 createWorld(WorldPrototype* prototype);
  
  
  /*! function. destroyWorld
      Destroyer of World, Scenes and everything within.
      args.
      - **bool** also_destroy_singletons := Destroy the Singletons along with the world.
      note. If you destroy the singletons, then World::destroySingletons does not need to be called.
  */
  static               void                   destroyWorld(bool also_destroy_singletons = true);
  
  /*! function. destroySingletons
      Destroy singletons. This should be called AFTER destroyWorld.
  */
  static               void                   destroySingletons(void);

  /*! function. getWorld
      Get a copy of the World pointer.
      return. **World** * -- The World instance, or NULL if the World has not been created yet.
  */
  static               World*                 getWorld();

  /*! function. isDead
      Is the associated NxPhysicsSDK not created, or a serious error has happened that has made it unusable.
      return. **bool** -- If the NxPhysicsSDK is not created or a critical error has happened.
  */
                       bool                   isDead(void) const;

  /*! function. createScene
      Create a single scene with a SceneDescription as it's initial properties.
      example.
      Scene* scene = World::getWorld()->createScene();
      args.
      - *const SceneDescription&* := SceneDescription to create the Scene with.
      return. **Scene** * -- The Scene, or NULL if the Scene was not created properly.
  */
                       Scene*                 createScene(const SceneDescription& = SceneDescription());

  /*! function. destroyScene
      Destroys a single scene and the contents within.
      args.
      - **Scene** * := The Scene to destroy
  */
                       void                   destroyScene(Scene*);

  /*! function. hasHardware
      Does the current computer have a PhysX accelerator, or a GPU capable of PhysX acceleration?
      return. **bool** -- If the hardware has a PhysX accelerator or capable GPU.
  */
                       bool                   hasHardware() const;

  /*! function. getNullCallback
      Get a copy of the Null Callback. Used for parts of NxOgre that don't have a user callback but still recieve events.
      note. This OWNED by NxOgre. Do not delete it.
      return. **Callback** * -- The callback
  */
                       Callback*              getNullCallback(void);
  
  /*! function. getVisualDebugger
      Get a copy of the VisualDebugger pointer.
      note. This OWNED by NxOgre. Do not delete it.
      return. **VisualDebugger** * -- The VisualDebugger
  */
                       VisualDebugger*        getVisualDebugger(void);
  
  /*! function. getRemoteDebugger
      Get a copy of the RemoteDebugger pointer.
      note. This OWNED by NxOgre. Do not delete it.
      return. **RemoteDebugger** * -- The RemoteDebugger
  */
                       RemoteDebugger*        getRemoteDebugger(void);
  
  /*! function. getScenes
      Get an iterator to the current Scenes in World.
      return. **SceneIterator** * -- A iterator to the Scenes.
  */
                       SceneIterator          getScenes(void);
  
  /*! function. getPhysXSDK
      Get a copy of the NxPhysicsSDK pointer.
      !physx
      note. This OWNED by NxOgre. Do not delete it.
      return. **NxPhysicsSDK** * -- The NxPhysicsSDK pointer
  */
                       NxPhysicsSDK*          getPhysXSDK(void);
  
  /*! function. getPhysXCookingInterface
      Get a copy of the NxCookingInterface pointer.
      !physx
      note. This OWNED by NxOgre. Do not delete it.
      return. **NxCookingInterface** * -- The NxCookingInterface pointer
  */
                       NxCookingInterface*    getPhysXCookingInterface(void);
  
  protected: // Functions
  
  /* Internal. Use World::createWorld();
  */
                                              World(WorldPrototype*);
  
  /* Internal. Use World::destroyWorld();
  */
                                             ~World(void);
  
  
  protected: // Variables
  
  /** \internal Internal Singleton
  */
  static              World*                  sWorldInstance;

  /** \internal
  */
                      NxPhysicsSDK*           mSDK;

  /** \internal
  */
  static              NxCookingInterface*     mCookingInterface;

  /** \brief If the SDK is dead or not
  */
                      bool                    mDeadSDK;

  /** \brief World's PhysX output stream instance
  */
                      PhysXOutputStream*      mPhysXOutputStream;

  /** \brief World's PhysX user allocator instance
  */
                      PhysXUserAllocator*     mPhysXUserAllocator;

  /** \brief Master copy of all the Scenes in the World.
  */
                      Scenes                  mScenes;

  /** \brief World's time controller instance
  */
                      TimeController*         mTimeController;

  /** \brief Shared callback between classes that don't have a user callback.
  */
                      Callback*               mNullCallback;
  
  /** \brief Global VisualDebugger.
  */
                      VisualDebugger*         mVisualDebugger;
  
  /** \brief Global RemoteDebugger.
  */
                      RemoteDebugger*         mRemoteDebugger;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
