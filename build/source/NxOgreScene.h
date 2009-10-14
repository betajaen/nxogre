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

                                                                                       

#ifndef NXOGRE_SCENE_H
#define NXOGRE_SCENE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreActor.h"
#include "NxOgreSceneGeometry.h"
#include "NxOgreKinematicActor.h"
#include "NxOgreVolume.h"
#include "NxOgreKinematicController.h"
#include "NxOgreShape.h"
#include "NxOgreFluid.h"

#include "NxOgrePointerClass.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreMaterialDescription.h"
#include "NxOgreJointDescription.h"
#include "NxOgreSphericalJointDescription.h"
#include "NxOgreRevoluteJointDescription.h"
#include "NxOgreClothDescription.h"
#include "NxOgreCompartmentDescription.h"
#include "NxOgreCompartment.h"
#include "NxOgreFluidDescription.h"

#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Scene : public PointerClass<Classes::_Scene>, public TimeListener
{
  
  friend class World;
  friend class Functions::ArrayFunctions<Scene*>::Write;
  template<class T> friend inline void ::NxOgre::Functions::safe_delete(T*);
  
  public: // Functions
  
  typedef  ptr_multihashmap<Actor>                            Actors;
  typedef  ptr_multihashmap<Actor>::iterator_t                ActorIterator;

  typedef  ptr_multihashmap<SceneGeometry>                    SceneGeometries;
  typedef  ptr_multihashmap<SceneGeometry>::iterator_t        SceneGeometryIterator;

  typedef  ptr_multihashmap<KinematicActor>                   KinematicActors;
  typedef  ptr_multihashmap<KinematicActor>::iterator_t       KinematicActorIterator;

  typedef  ptr_multihashmap<KinematicController>              KinematicControllers;
  typedef  ptr_multihashmap<KinematicController>::iterator_t  KinematicControllerIterator;

  typedef  ptr_multihashmap<Volume>                           Volumes;
  typedef  ptr_multihashmap<Volume>::iterator_t               VolumeIterator;

  typedef  ptr_multihashmap<Fluid>                            Fluids;
  typedef  ptr_multihashmap<Fluid>::iterator_t                FluidIterator;

  
  /** \brief Get the name of the Scene if it has one; otherwise NULL is returned.
  */
                       String                 getName(void) const;
  
  /** \brief Get the hash of the name of the Scene.
  */
                       StringHash             getNameHash(void) const;
  
  /** \brief
  */
                       unsigned int           getNbRigidBodies(void) const;
  
  /** \brief
  */
                       unsigned int           getNbActors(void) const;
  
  /** \brief
  */
                       ActorIterator          getActors(void);
  
  /** \brief Create an actor somewhere in the scene
  */
                       Actor*                 createActor(Shape*, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /** \brief Create an actor somewhere in the scene
  */
                       Actor*                 createActor(Shapes&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /** \brief
  */
                       void                   destroyActor(Actor*);
  
  /** \brief
  */
                       SceneGeometry*         createSceneGeometry(Shapes&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /** \brief
  */
                       SceneGeometry*         createSceneGeometry(Shape*, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());


  /** \brief
  */
                       KinematicActor*        createKinematicActor(Shape*, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /** \brief
  */
                       KinematicActor*        createKinematicActor(Shapes&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());

  /** \brief Create a volume for collision detection in a shape, based on the PhysX Trigger system.
      \note  Volumes are RigidBodies can be treated as so, but can never be moved via forces.
  */
                       Volume*                createVolume(Shape*, const Matrix44&, Callback*, Enums::VolumeCollisionType = Enums::VolumeCollisionType_All);
  
  /** \brief;
  */
                       Volume*                createVolume(Shapes&, const Matrix44&, Callback*, Enums::VolumeCollisionType = Enums::VolumeCollisionType_All);
  
  /** \brief
  */
                       KinematicController*   createKinematicController(const Vec3& size, const Vec3& globalPosition);

  /** \brief
  */
                       Material*              createMaterial(const MaterialDescription& = MaterialDescription());
  
  /** \brief
  */
                       Material*              createMaterial(MaterialPrototype*);
  
  /** \brief
  */
                       void                   registerMachine(Machine*);
  
  /** \brief
  */
                       void                   unregisterMachine(Machine*);
  
  /** \brief
  */
                       void                   destroyJoint(Joint*);

  /** \brief
  */
                       SphericalJoint*        createSphericalJoint(RigidBody* first, const SphericalJointDescription& = SphericalJointDescription());
  
  /** \brief
  */
                       SphericalJoint*        createSphericalJoint(RigidBody* first, RigidBody* second, const SphericalJointDescription& = SphericalJointDescription());

  /** \brief
  */
                       FixedJoint*            createFixedJoint(RigidBody* first, const FixedJointDescription& = FixedJointDescription());
  
  /** \brief
  */
                       FixedJoint*            createFixedJoint(RigidBody* first, RigidBody* second, const FixedJointDescription& = FixedJointDescription());

  /** \brief
  */
                       RevoluteJoint*         createRevoluteJoint(RigidBody* first, const RevoluteJointDescription& = RevoluteJointDescription());
  
  /** \brief
  */
                       RevoluteJoint*         createRevoluteJoint(RigidBody* first, RigidBody* second, const RevoluteJointDescription& = RevoluteJointDescription());

  /** \brief
  */
                       void                   destroyMaterial(Material*);
  
  /** \brief
  */
                       Material*              getMaterial(const MaterialIdentifier&);
  
  /** \brief
  */
                       Cloth*                 createCloth(const ClothDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /** \brief
  */
                       void                   destroyCloth(Cloth*);
  
  /** \brief
  */
                       SoftBody*              createSoftBody(const SoftBodyDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /** \brief
  */
                       void                   destroySoftBody(SoftBody*);
  
  /** \brief
  */
                       Fluid*                 createFluid(const FluidDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /** \brief
  */
                       void                   destroyFluid(Fluid*);

  /** \brief
  */
                       Compartment*           createCompartment(const CompartmentDescription&);

  /** \brief Find a NxOgre Compartment based upon it's PhysX pointer equilvent.
  */
                       Compartment*           getCompartment(NxCompartment*);

  /** \brief
  */
                       void                   setGravity(const Vec3&);
  
  /** \brief
  */
                       Vec3                   getGravity(void) const;

  /** \brief Returns true if any aligned bounding box is hit by the ray, but not what the box is and where it is relation to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
                       bool                   raycastAnyBounds(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax) const;

  /** \brief Returns true if any aligned bounding box is hit by the ray, but not what the box is and where it is relation to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
                       bool                   raycastAnyBounds(const Ray&, Enums::ShapesType, int4 groupsMask, Real maxDistance = NxOgreRealMax) const;

  /** \brief A more accurate version of raycastAnyBounds, but again does not give what shape was hit, or the distance to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
                       bool                   raycastAnyShape(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, RaycastCache = 0) const;
  
  /** \brief Call the report's hitCallback
      \warning This is not thread safe.
  */
                       unsigned int           raycastAllBounds(const Ray&, Callback*,  Enums::ShapesType, unsigned int group = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;
  
  /** \brief Call the report's hitCallback
  */
                       unsigned int           raycastAllBounds(const Ray&, Callback*,  Enums::ShapesType, int4 groupsMask, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;

  /** \brief Return the closest RigidBody (and hit information), to accuracy of the bounds of the RigidBody.
  */
                       RaycastHit             raycastClosestBounds(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;

  /** \brief Return the closest RigidBody, to shape accuracy, to the accuracy of the shape(s) of the RigidBody.
  */
                       RaycastHit             raycastClosestShape(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1, RaycastCache = 0) const;

  /** \brief Block all parallel raycast/overlap queries.
  */
                       void                   lockQueries();
  
  /** \brief Unlock all parallel raycast/overlap queries.
  */
                       void                   unlockQueries();


  /** \brief Required by TimeController. Advances the simulation state of this scene.
      \note Do not use manually.
  */
                       bool                   advance(float user_deltaTime, const Enums::Priority&);
  
  /** \brief Is the scene currently processing the physics for the next time step. You cannot
             adjust the scene's state whilst it is processing.
  */
                       bool                   isProcessing(void) const;
  
  /** \brief Get this timestep's debug renderable of the scene.
  */
                       DebugRenderable        getDebugRenderable(void);
  
  /** \internal
  */
                       NxScene*               getScene(void);
  
  /** \internal
  */
                       PhysXCallback*         getPhysXCallback(void);
  
  /** \brief
  */
                       void                   setActorFlags(RigidBody*, RigidBody*, unsigned int contact_flags);
  
  
  /** \brief Create a cache for sweep queries.
      \note  Remember to destroy the cache after use or before the Scene is destroyed!
  */
                       SweepCache*            createSweepCache();
  
  /** \brief Destroy a cache that was used for sweep queries.
  */
                       void                   destroySweepCache(SweepCache*);

  /** \brief
  */
                       unsigned int           linearOBBSweep(const SimpleBox&, const Vec3& motion, unsigned int sweep_flags, unsigned int maxShapes, SweepQueryHits&, unsigned int activeGroups=0xffffffff);

  /*! function. getTimeStep
      desc.
           Get the timestep class for this timestep.
  */
  const                TimeStep&               getTimeStep();
  
  protected: // Functions
  
  /** \internal Use World::createScene()
  */
                                              Scene(const SceneDescription&, NxPhysicsSDK*);
  
  /** \internal Use World::destroyScene()
  */
                                             ~Scene(void);
  
  protected: // Variables
  
  /** \brief Name as a String. Use Scene::getName() to fetch, or Scene::setName() to set.
  */
                       String                           mName;
  
  /** \brief Name as a String as a hash.
  */
                       StringHash                       mNameHash;
  
  /** \internal What Scene is associated with
  */
                       NxScene*                         mScene;
  
  /** \internal Local SDK pointer
  */
                       NxPhysicsSDK*                    mSDK;
   
  /** \internal Master actors array
  */
                       Actors                           mActors;
  
  /** \internal Master scene geometries array
  */
                       SceneGeometries                  mSceneGeometries;
  
  /** \internal Master kinematic actors array
  */
                       KinematicActors                  mKinematicActors;
  
  /** \internal Master kinematic controllers array
  */
                       KinematicControllers             mKinematicControllers;
  
  /** \internal Master volumes array
  */
                       Volumes                          mVolumes;
  
  /** \internal Master materials array
  */
                       Array<Material*>                 mMaterials;
  
  /** \internal Master joints array
  */
                       Array<Joint*>                    mJoints;
  
  /** \internal Master machines array
  */
                       Array<Machine*>                  mMachines;

  /** \internal
  */
                       Array<Machine*>::Iterator        mMachineIterator;

  /** \internal
  */
                       Array<Cloth*>                    mCloths;

  /** \internal
  */
                       Array<SoftBody*>                 mSoftBodies;

  /** \internal
  */
                       Array<Compartment*>              mCompartments;

  /** \brief
  */
                       Fluids                           mFluids;

  /** \internal
  */
                std::map<NxCompartment*, Compartment*>  mCompartmentPairs;

  /** \internal Is Scene processing flag
  */
                       bool                             mProcessing;
  
  /** \internal Scene processing priority
  */
                       Enums::Priority                  mProcessingPriority;
  
  /** \internal Scene fetching priority
  */
                       Enums::Priority                  mFetchingPriority;
  
  /** \internal Scene user callback.
  */
                       PhysXCallback*                   mPhysXCallback;
  
  /** \internal Current SceneTimer
  */
                       SceneTimer*                      mSceneTimer;
  
  /** \internal Can the scene be rendered
  */
                       bool                             mCanRender;
  
}; // class Scene

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
