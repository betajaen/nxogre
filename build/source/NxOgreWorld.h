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

                                                                                       

/** \brief
*/
class NxOgrePublicClass World : public PointerClass<Classes::_World>
{
  
  public: // Functions
  
  typedef multimap<StringHash, Scene>::type          Scenes;
  typedef multimap<StringHash, Scene>::user_iterator SceneIterator;
  
  /** \brief Pre-create singletons of NxOgre (ResourceSystem, MeshManager, HeightFieldManager, ErrorStream, etc.)
  */
  static               void                   precreateSingletons(void);

  /** \brief Create a single World, if a world already exists then an Error will be
             raised and a NULL returned.
  */
  static               World*                 createWorld(const WorldDescription& = WorldDescription());
  
  /** \brief Create a single World using a WorldPrototype*, if a world already exists
             then an Error will be raised and a NULL returned.
  */
  static               World*                 createWorld(WorldPrototype*);
  
  
  /** \brief Destroyer of Worlds, Scenes and everything within.
      \note  If also_destroy_singletons is true, then destroySingletons does not need to be called.
  */
  static               void                   destroyWorld(bool also_destroy_singletons = true);
  
  /** \brief Destroy singletons. This should be called AFTER destroyWorld.
  */
  static               void                   destroySingletons(void);

  /** \brief Get a copy of the World pointer.
  */
  static               World*                 getWorld();

  /** \brief Is the associated NxPhysicsSDK not created, or a serious error has happened that has
             made it unusable.
  */
                       bool                   isDead(void) const;

  /** \brief Create a single scene with a SceneDescription as it's initial properties.
  */
                       Scene*                 createScene(const SceneDescription& = SceneDescription());

  /** \brief Create a single scene based of a ScenePrototype
  */
                       Scene*                 createScene(ScenePrototype*);

  /** \brief Destroys a single scene
  */
                       void                   destroyScene(Scene*);

  /** \brief Does the current computer have a PhysX accelerator, or a GPU capable of PhysX acceleration?
  */
                       bool                   hasHardware(void) const;

  /** \brief Get a copy of the Null Callback. Used for parts of NxOgre that don't have a user callback
             but still recieve events.
      \warning This OWNED by NxOgre. Do not delete it.
  */
                       Callback*              getNullCallback(void);
  
  /** \brief Get a copy of the VisualDebugger pointer.
  */
                       VisualDebugger*        getVisualDebugger(void);
  
  /** \brief Get a copy of the VisualDebugger pointer.
  */
                       RemoteDebugger*        getRemoteDebugger(void);
  
  /** \brief
  */
                       SceneIterator          getScenes(void);
  
  /** \brief
  */
                       NxPhysicsSDK*          getPhysXSDK(void);
  
#ifndef NXOGRE_OPTIONS_MINIMAL
  
  /** \brief
  */
                       NxCookingInterface*    getPhysXCookingInterface(void);
  
#endif
  
  protected: // Functions
  
  /** \internal Use World::createWorld();
  */
                                              World(WorldPrototype*);
  
  /** \internal Use World::destroyWorld();
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
