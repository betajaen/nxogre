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
#include "NxOgreMaterial.h"

#include "NxOgrePointerClass.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreMaterialDescription.h"
#include "NxOgreJointDescription.h"
#include "NxOgreSphericalJointDescription.h"
#include "NxOgreRevoluteJointDescription.h"
#include "NxOgreD6JointDescription.h"
#include "NxOgreClothDescription.h"
#include "NxOgreCompartmentDescription.h"
#include "NxOgreCompartment.h"
#include "NxOgreFluidDescription.h"

#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Scene
    desc.
        Scene's hold RigidBodies, Cloths, Fluids and so on. There can be upto 32 of them.
*/
class NxOgrePublicClass Scene : public BigClassAllocatable, public TimeListener
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
  typedef  ptr_multihashmap<Material>                         Materials;
  typedef  ptr_multihashmap<Material>::iterator_t             MaterialIterator;
  typedef  ptr_map<unsigned short, Material>                  IndexedMaterials;
  
  /*! function. getName
      desc.
           Get the name of the Scene if it has one; otherwise NULL is returned.
  */
  String  getName(void) const;
  
  /*! function. getName
      desc.
          HashGet the hash of the name of the Scene.
  */
  StringHash  getNameHash(void) const;
  
  /*! function. getNbRigidBodies
      desc.
  */
  unsigned int  getNbRigidBodies(void) const;
  
  /*! function. getNbActors
      desc.
          
  */
  unsigned int  getNbActors(void) const;
  
  /*! function. getActors
      desc.
          
  */
  ActorIterator  getActors(void);
  
  /*! function. createActor
      desc.
          Create an actor somewhere in the scene
  */
  Actor*  createActor(Shape*, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. createActor
      desc.
          Create an actor somewhere in the scene
  */
  Actor*  createActor(Shapes&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. destroyActor
      desc.
          
  */
  void  destroyActor(Actor*);
  
  /*! function. createSceneGeometry
      desc.
          
  */
  SceneGeometry*  createSceneGeometry(Shapes&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. createSceneGeometry
      desc.
          
  */
  SceneGeometry*  createSceneGeometry(Shape*, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. createKinematicActor
      desc.
          
  */
  KinematicActor*  createKinematicActor(Shape*, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. createKinematicActor
      desc.
          
  */
  KinematicActor*  createKinematicActor(Shapes&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());

  /*! function. createVolume
      desc.
          Create a volume for collision detection in a shape, based on the PhysX Trigger system.
      \note  Volumes are RigidBodies can be treated as so, but can never be moved via forces.
  */
  Volume*  createVolume(Shape*, const Matrix44&, Callback*, Enums::VolumeCollisionType = Enums::VolumeCollisionType_All);
  
  /*! function. createVolume
      desc.
          ;
  */
  Volume*  createVolume(Shapes&, const Matrix44&, Callback*, Enums::VolumeCollisionType = Enums::VolumeCollisionType_All);
  
  /*! function. createKinematicController
      desc.
          
  */
  KinematicController*  createKinematicController(const Vec3& size, const Vec3& globalPosition);

  /*! function. createMaterial
      desc.
          
  */
  Material*  createMaterial(const MaterialDescription& = MaterialDescription());
  
  /*! function. createMaterial
      desc.
          
  */
  Material*  createMaterial(MaterialPrototype*);
  
  /*! function. registerMachine
      desc.
          
  */
  void  registerMachine(Machine*);
  
  /*! function. unregisterMachine
  */
  void  unregisterMachine(Machine*);
  
  /*! function. destroyJoint
      desc.
          
  */
  void  destroyJoint(Joint*);

  /*! function. createSphericalJoint
      desc.
          
  */
  SphericalJoint*  createSphericalJoint(RigidBody* first, const SphericalJointDescription& = SphericalJointDescription());
  
  /*! function. createSphericalJoint
      desc.
          
  */
  SphericalJoint*  createSphericalJoint(RigidBody* first, RigidBody* second, const SphericalJointDescription& = SphericalJointDescription());

  /*! function. createFixedJoint
      desc.
          
  */
  FixedJoint*  createFixedJoint(RigidBody* first, const FixedJointDescription& = FixedJointDescription());
  
  /*! function. createFixedJoint
      desc.
          
  */
  FixedJoint*  createFixedJoint(RigidBody* first, RigidBody* second, const FixedJointDescription& = FixedJointDescription());

  /*! function. createRevoluteJoint
      desc.
          
  */
  RevoluteJoint*  createRevoluteJoint(RigidBody* first, const RevoluteJointDescription& = RevoluteJointDescription());
  
  /*! function. createRevoluteJoint
      desc.
          
  */
  RevoluteJoint*  createRevoluteJoint(RigidBody* first, RigidBody* second, const RevoluteJointDescription& = RevoluteJointDescription());

  /*! function. createRevoluteJoint
      desc.
          
  */
  D6Joint*  createD6Joint(RigidBody* first, const D6JointDescription& = D6JointDescription());
  
  /*! function. createRevoluteJoint
      desc.
          
  */
  D6Joint*  createD6Joint(RigidBody* first, RigidBody* second, const D6JointDescription& = D6JointDescription());

  /*! function. destroyMaterial
      desc.
          
  */
  void  destroyMaterial(Material*);
  
  /*! function. getMaterial
      desc.
          
  */
  Material*  getMaterial(const MaterialIdentifier&);
  
  /*! function. createCloth
      desc.
          
  */
  Cloth*  createCloth(const ClothDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /*! function. destroyCloth
      desc.
          
  */
  void  destroyCloth(Cloth*);
  
  /*! function. createSoftBody
      desc.
          
  */
  SoftBody*  createSoftBody(const SoftBodyDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /*! function. destroySoftBody
      desc.
          
  */
  void  destroySoftBody(SoftBody*);
  
  /*! function. createFluid
      desc.
          
  */
  Fluid*  createFluid(const FluidDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /*! function. destroyFluid
      desc.
          
  */
  void  destroyFluid(Fluid*);

  /*! function. createCompartment
      desc.
          
  */
  Compartment*  createCompartment(const CompartmentDescription&);

  /*! function. getCompartment
      desc.
          Find a NxOgre Compartment based upon it's PhysX pointer equilvent.
  */
  Compartment*  getCompartment(NxCompartment*);

  /*! function. setGravity
      desc.
          
  */
  void  setGravity(const Vec3&);
  
  /*! function. getGravity
      desc.
          
  */
  Vec3  getGravity(void) const;

  /*! function. raycastAnyBounds
      desc.
          Returns true if any aligned bounding box is hit by the ray, but not what the box is and where it is relation to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
  bool  raycastAnyBounds(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax) const;

  /*! function. raycastAnyBounds
      desc.
          Returns true if any aligned bounding box is hit by the ray, but not what the box is and where it is relation to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
  bool  raycastAnyBounds(const Ray&, Enums::ShapesType, int4 groupsMask, Real maxDistance = NxOgreRealMax) const;

  /*! function. raycastAnyShape
      desc.
          A more accurate version of raycastAnyBounds, but again does not give what shape was hit, or the distance to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
  bool  raycastAnyShape(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, RaycastCache = 0) const;
  
  /*! function. raycastAllBoundsCall the report's hitCallback
      \warning This is not thread safe.
  */
  unsigned int  raycastAllBounds(const Ray&, Callback*,  Enums::ShapesType, unsigned int group = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;
  
  /*! function. raycastAllBounds
      desc.
          Call the report's hitCallback
  */
  unsigned int  raycastAllBounds(const Ray&, Callback*,  Enums::ShapesType, int4 groupsMask, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;

  /*! function. raycastClosestBounds
      desc.
          Return the closest RigidBody (and hit information), to accuracy of the bounds of the RigidBody.
  */
  RaycastHit  raycastClosestBounds(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;

  /*! function. raycastClosestShape
      desc.
          Return the closest RigidBody, to shape accuracy, to the accuracy of the shape(s) of the RigidBody.
  */
  RaycastHit  raycastClosestShape(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1, RaycastCache = 0) const;

  /*! function. lockQueries
      desc.
          Block all parallel raycast/overlap queries.
  */
  void  lockQueries();
  
  /*! function. unlockQueries
      desc.
          Unlock all parallel raycast/overlap queries.
  */
  void  unlockQueries();


  /*! function. advance
      desc.
          Required by TimeController. Advances the simulation state of this scene.
      note.
          Do not use manually.
  */
  bool  advance(float user_deltaTime, const Enums::Priority&);
  
  /*! function. isProcessing
      desc.
          Is the scene currently processing the physics for the next time step. You cannot
             adjust the scene's state whilst it is processing.
  */
  bool  isProcessing(void) const;
  
  /*! function. getDebugRenderable
      desc.
          Get this timestep's debug renderable of the scene.
  */
  DebugRenderable  getDebugRenderable(void);
  
  /*! function. getScene
      desc.
          
  */
  NxScene*  getScene(void);
  
  /*! function. getPhysXCallback
      desc.
          
  */
  PhysXCallback*  getPhysXCallback(void);
  
  /*! function. setActorFlags
      desc.
          
  */
  void  setActorFlags(RigidBody*, RigidBody*, unsigned int contact_flags);
  
  /*! function. createSweepCache
      desc.
          Create a cache for sweep queries.
      \note  Remember to destroy the cache after use or before the Scene is destroyed!
  */
  SweepCache*  createSweepCache();
  
  /*! function. destroySweepCache
      desc.
          Destroy a cache that was used for sweep queries.
  */
  void  destroySweepCache(SweepCache*);

  /*! function. linearOBBSweep
      desc.
          
  */
  unsigned int  linearOBBSweep(const SimpleBox&, const Vec3& motion, unsigned int sweep_flags, unsigned int maxShapes, SweepQueryHits&, unsigned int activeGroups=0xffffffff);

  /*! function. getTimeStep
      desc.
           Get the timestep class for this timestep.
  */
  const  TimeStep&  getTimeStep();
  
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
  String  mName;

  /** \brief Name as a String as a hash.
  */
  StringHash  mNameHash;

  /** \internal What Scene is associated with
  */
  NxScene*  mScene;

  /** \internal Local SDK pointer
  */
  NxPhysicsSDK*  mSDK;

  /** \internal Master actors array
  */
  Actors  mActors;

  /** \internal Master scene geometries array
  */
  SceneGeometries  mSceneGeometries;

  /** \internal Master kinematic actors array
  */
  KinematicActors  mKinematicActors;

  /** \internal Master kinematic controllers array
  */
  KinematicControllers  mKinematicControllers;

  /** \internal Master volumes array
  */
  Volumes  mVolumes;

  /** \internal Master materials array
  */
  Materials  mMaterials;

  /** \internal Secondary materials array, ordered by material index.
  */
  IndexedMaterials  mIndexedMaterials;

  /** \internal Master joints array
  */
  Array<Joint*>  mJoints;

  /** \internal Master machines array
  */
  Array<Machine*>  mMachines;

  /** \internal
  */
  Array<Machine*>::Iterator  mMachineIterator;

  /** \internal
  */
  Array<Cloth*>  mCloths;

  /** \internal
  */
  Array<SoftBody*>  mSoftBodies;

  /** \internal
  */
  Array<Compartment*>  mCompartments;

  /** \brief
  */
  Fluids  mFluids;

  /** \internal
  */
  std::map<NxCompartment*, Compartment*>  mCompartmentPairs;

  /** \internal Is Scene processing flag
  */
  bool  mProcessing;

  /** \internal Scene processing priority
  */
  Enums::Priority  mProcessingPriority;

  /** \internal Scene fetching priority
  */
  Enums::Priority  mFetchingPriority;

  /** \internal Scene user callback.
  */
  PhysXCallback* mPhysXCallback;

  /** \internal Current SceneTimer
  */
  SceneTimer*  mSceneTimer;

  /** \internal Can the scene be rendered
  */
  bool  mCanRender;

}; // class Scene

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
