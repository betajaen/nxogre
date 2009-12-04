/** File: NxOgreWorld.h
    Created on: 2-Nov-08
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NXOGRE_WORLD_H
#define NXOGRE_WORLD_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreWorldDescription.h"
#include "NxOgreSceneDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass World : public PointerClass<Classes::_World>
{
  
  public: // Functions
  
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
                       ArrayIterator<Scene*>  getScenes(void);
  
  /** \brief
  */
                       NxPhysicsSDK*          getPhysXSDK(void);
  
#ifndef NXOGRE_OPTIONS_MINIMAL
  
  /** \brief
  */
                       NxCookingInterface*    getPhysXCookingInterface(void);
  
#endif
  
  /** \brief
  */
                       PhysXUserAllocator*    getPhysXAllocator();
  
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
                      Array<Scene*>           mScenes;

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
