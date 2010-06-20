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
#include "NxOgreShape.h"
#include "NxOgreFluid.h"
#include "NxOgreMaterial.h"
#include "NxOgreJoint.h"
#include "NxOgreSoftBody.h"
#include "NxOgreMachine.h"
#include "NxOgreCloth.h"
#include "NxOgreForceField.h"
#include "NxOgreForceFieldKernel.h"

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
#include "NxOgreForceFieldDescription.h"
#include "NxOgreForceFieldLinearKernelDescription.h"

#include "NxOgreTimeListener.h"

#if NxOgreHasCharacterController == 1

#include "NxOgreCharacterControllerDescription.h"

#endif

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Scene
    desc.
        Scene's hold RigidBodies, Cloths, Fluids and so on. There can be upto 32 of them.
*/
class NxOgrePublicClass Scene : public BigClassAllocatable
{
  
  friend class World;
  friend class PhysXCallback;
  template<class T> friend inline void ::NxOgre::GC::safe_delete(T*,const char*,int);
  
  public: // Functions
  
  typedef  multihashmap<Actor*, GC::HasGarbageCollection>                       Actors;
  typedef  multihashmap_iterator<Actor*>                                        ActorIterator;
  typedef  multihashmap<SceneGeometry*, GC::HasGarbageCollection>               SceneGeometries;
  typedef  multihashmap_iterator<SceneGeometry*>                                SceneGeometryIterator;
  typedef  multihashmap<KinematicActor*, GC::HasGarbageCollection>              KinematicActors;
  typedef  multihashmap_iterator<KinematicActor*>                               KinematicActorIterator;
  typedef  vector<Volume*, GC::HasGarbageCollection>                            Volumes;
  typedef  vector_iterator<Volume*>                                             VolumeIterator;
  typedef  multihashmap<Fluid*, GC::HasGarbageCollection>                       Fluids;
  typedef  multihashmap_iterator<Fluid*>                                        FluidIterator;
  typedef  multihashmap<Material*, GC::HasGarbageCollection>                    Materials;
  typedef  multihashmap_iterator<Material*>                                     MaterialIterator;
  typedef  multihashmap<ForceFieldKernel*, GC::HasGarbageCollection>            ForceFieldKernels;
  typedef  multihashmap_iterator<ForceFieldKernel*>                             ForceFieldKernelIterator;
  typedef  multihashmap<ForceField*, GC::HasGarbageCollection>                  ForceFields;
  typedef  multihashmap_iterator<ForceField*>                                   ForceFieldIterator;
  typedef  map<unsigned short, Material*, GC::NoGarbageCollection>              IndexedMaterials;
  typedef  map<Enums::Priority, TimeListenerGroup*, GC::HasGarbageCollection >  TimeListenerGroups;
  typedef  map_iterator<Enums::Priority, TimeListenerGroup*>                    TimeListenerGroupIterator;
  
  typedef  vector<Machine*>                                                     Machines;
  typedef  vector_iterator<Machine*>                                            MachineIterator;

#if NxOgreHasCharacterController == 1
  typedef  multihashmap<CharacterController*, GC::HasGarbageCollection>         CharacterControllers;
  typedef  multihashmap_iterator<CharacterController*>                          CharacterControllerIterator;
#endif

  /*! function. getType
      desc.
          Get type of scene.
  */
  virtual       Enums::SceneType getType() const = 0;
  
  /*! function. getName
      desc.
           Get the name of the Scene if it has one; otherwise NULL is returned.
  */
  String        getName() const;
  
  /*! function. getName
      desc.
          HashGet the hash of the name of the Scene.
  */
  StringHash    getNameHash() const;
  
  /*! function. getNbRigidBodies
      desc.
  */
  unsigned int  getNbRigidBodies() const;
  
  /*! function. getNbActors
      desc.
          
  */
  unsigned int  getNbActors() const;
  
  /*! function. getActors
      desc.
          
  */
  ActorIterator  getActors();
  
  /*! function. createActor
      desc.
          Create an actor somewhere in the scene
  */
  Actor*  createActor(const ShapeDescription&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. createActor
      desc.
          Create an actor somewhere in the scene
  */
  Actor*  createActor(const ShapeDescriptions&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. destroyActor
      desc.
          
  */
  bool  destroyActor(Actor*);
  
  /*! function. createSceneGeometry
      desc.
          
  */
  SceneGeometry*  createSceneGeometry(const ShapeDescription&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. createSceneGeometry
      desc.
          
  */
  SceneGeometry*  createSceneGeometry(const ShapeDescriptions&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
  /*! function. createKinematicActor
      desc.
          
  */
  KinematicActor*  createKinematicActor(const ShapeDescription&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());
  
#if NxOgreHasCharacterController == 1

  /*! function. createBoxCharacterController
      desc.
          Create a Character Controller.
  */
  CharacterController*  createCharacterController(const SimpleShape& shape, const Vec3& globalPosition, const CharacterControllerDescription& = CharacterControllerDescription());

  /*! function. destroyCharacterController
      desc.
          Destroy an existing Character Controller
  */
  void destroyCharacterController(CharacterController*);

#endif

  /*! function. createKinematicActor
      desc.
          
  */
  KinematicActor*  createKinematicActor(const ShapeDescriptions&, const Matrix44& = Matrix44::IDENTITY, const RigidBodyDescription& = RigidBodyDescription());

  /*! function. createVolume
      desc.
          Create a volume for collision detection in a shape, based on the PhysX Trigger system.
      \note  Volumes are RigidBodies can be treated as so, but can never be moved via forces.
  */
  Volume*  createVolume(const ShapeDescription&, const Matrix44&, Callback*, Enums::VolumeCollisionType = Enums::VolumeCollisionType_All);
  
  /*! function. createVolume
      desc.
          ;
  */
  Volume*  createVolume(const ShapeDescriptions&, const Matrix44&, Callback*, Enums::VolumeCollisionType = Enums::VolumeCollisionType_All);
  
  /*! function. createMaterial
      desc.
          
  */
  Material*  createMaterial(const MaterialDescription& = MaterialDescription());
  
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

#if NxOgreHasFluids == 1
  /*! function. createFluid
      desc.
          
  */
  Fluid*  createFluid(const FluidDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /*! function. destroyFluid
      desc.
          
  */
  void  destroyFluid(Fluid*);
#endif
  /*! function. createForceFieldLinearKernel
      desc.
  */
  ForceFieldKernel* createForceFieldLinearKernel(const ForceFieldLinearKernelDescription&);

  /*! function. createForceFieldLinearKernel
      desc.
          Attempst to destroy a forcefield linear kernel. It is deleted if it is no longer
          used with a ForceField.
      return.
          bool -- If the kernel was destroyed or not.
  */
  bool destroyForceFieldLinearKernel(ForceFieldLinearKernel*);

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
  Vec3  getGravity() const;

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

  /*! function. addSimulateListener
      desc.
          Add
  */
  void  addSimulateListener(TimeListener*, Enums::Priority = Enums::Priority_Medium);

  /*! function. removeSimulateListener
      desc.
          Remove a simulate time listener
  */
  void  removeSimulateListener(TimeListener*, Enums::Priority = Enums::Priority_Medium);

  /*! function. addSimulateListener
      desc.
          Add a render time listener
  */
  void  addRenderListener(TimeListener*, Enums::Priority = Enums::Priority_Medium);

  /*! function. removeSimulateListener
      desc.
          Remove a render time listener
  */
  void  removeRenderListener(TimeListener*, Enums::Priority = Enums::Priority_Medium);


  /*! function. advance
      desc.
          Advance the simulation by the deltaTime
      note.
          Do not use manually.
  */
  void  simulate(float deltaTime);
  
  /*! function. canRender
      desc.
          Has PhysX finished processing this scene?
      note.
          Do not use manually.
  */
  bool  canRender() const;
  
  /*! function. render
      desc.
          Render's the result of the simulation.
      note.
          Do not use manually.
  */
  void  render(float deltaTime);
  

  /*! function. isProcessing
      desc.
          Is the scene currently processing the physics for the next time step. You cannot
             adjust the scene's state whilst it is processing.
  */
  bool  isProcessing() const;
  
  /*! function. getDebugRenderable
      desc.
          Get this timestep's debug renderable of the scene.
  */
  DebugRenderable  getDebugRenderable();
  
  /*! function. getScene
      desc.
          
  */
  NxScene*  getScene();
  
  /*! function. getPhysXCallback
      desc.
          
  */
  PhysXCallback*  getPhysXCallback();
  
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

  /*! function. linearCapsuleSweep
      desc.
          
  */
  unsigned int  linearCapsuleSweep(const SimpleCapsule&, const Vec3& motion, unsigned int sweep_flags, unsigned int maxShapes, SweepQueryHits&, unsigned int activeGroups=0xffffffff);

  /*! function. linearOBBSweep
      desc.
          
  */
  unsigned int  linearOBBSweep(const SimpleBox&, const Vec3& motion, unsigned int sweep_flags, unsigned int maxShapes, SweepQueryHits&, unsigned int activeGroups=0xffffffff);

  /*! function. overlapSphereShapes
      desc.
  */
  unsigned int overlapSphereShape(const SimpleSphere&, Enums::ShapesType, unsigned int maxShapes, buffer<Shape*> shapes, unsigned int activeGroups=0xffffffff, bool accurateCollision=false);

  /*! function. overlapSphereShapes
      desc.
  */
  unsigned int overlapSphereShape(const SimpleSphere&, Enums::ShapesType, Callback*, unsigned int activeGroups=0xffffffff, bool accurateCollision=false);

  /*! function. getTimeStep
      desc.
           Get the timestep class for this timestep.
  */
  const  TimeStep&  getTimeStep();
  
  /*! function. setDominanceGroupPair 
      desc.
          Set the domaince constraint between two domaince groups
  */
  void setDominanceGroupPair(GroupIdentifier a, GroupIdentifier b, Real dominance0, Real domaince1);
  
  /*! function. setDominanceGroupPair 
      desc.
          Set the domaince constraint between two domaince groups
  */
  void setDominanceGroupPair(GroupIdentifier a, GroupIdentifier b, const ConstraintDominance&);
  
  /*! function. setDominanceGroupPair 
      desc.
          Set the domaince constraint between two domaince groups
  */
  ConstraintDominance getDominanceGroupPair(GroupIdentifier a, GroupIdentifier b);
  
  /*! function. setSleepCallback
      desc.
          Set the callback for sleep events.
  */
  void setSleepCallback(Callback*);
  
  /*! function. removeSleepCallback
      desc.
          Remove (but not delete) the callback for sleep events.
  */
  void removeSleepCallback();
  
  /*! function. hasSleepCallback
      desc.
          Does the scene have a sleep callback?
  */
  bool hasSleepCallback() const;

  /*! function. setGroupCollisionFlag
      desc.
          Does CollisionGroup (assigned to a shape) collides with another?
  */
  void setGroupCollisionFlag(GroupIdentifier first, GroupIdentifier second, bool collide);

  /*! function. getGroupCollisionFlag
      desc.
          Does CollisionGroup (assigned to a shape) collides with another?
  */
  void getGroupCollisionFlag(GroupIdentifier first, GroupIdentifier second) const;

  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  /*! function getNbSimulates
      desc.
          Get the number of times simulate has been called.
  */
  unsigned int getNbSimulates() const;
  
  /*! function getNbRenders
      desc.
          Get the number of times render has been called.
  */
  unsigned int getNbRenders() const;
  
  /*! function. setFilterOps
      desc.
          Setups filter operations. See NxGroupMask documentation.
  */
  void setFilterOps(NxOgre::Enums::FilterOp op0,NxOgre::Enums::FilterOp op1,NxOgre::Enums::FilterOp op2);
  
  /*! function. setFilterBool
      desc.
          Setups filtering's boolean value. See NxGroupMask documentation.
  */
  void setFilterBool(bool flag);

  /*! function. setFilterConstant0
      desc.
          Setups filtering's K0 value. See NxGroupMask documentation.
  */
  void setFilterConstant0(const GroupsMask& mask);
  
  /*! function. setFilterConstant1
      desc.
          Setups filtering's K1 value. See NxGroupMask documentation.
  */
  void setFilterConstant1(const GroupsMask& mask);
  
  /*! function. GetFilterOps
      desc.
          Retrieves filter operations. See NxGroupMask documentation.
  */
  void getFilterOps(NxOgre::Enums::FilterOp& op0,NxOgre::Enums::FilterOp& op1,NxOgre::Enums::FilterOp& op2) const;
  
  /*! function. setFilterBool
      desc.
          Retrieves filtering's boolean value. See NxGroupMask documentation.
  */
  bool getFilterBool() const;

  /*! function. setFilterConstant0
      desc.
          Retrieves filtering's K0 value. See NxGroupMask documentation.
  */
  GroupsMask getFilterConstant0() const;
  
  /*! function. setFilterConstant1
      desc.
          Retrieves filtering's K1 value. See NxGroupMask documentation.
  */
  GroupsMask setFilterConstant1() const;
  
  
  protected: // Functions
  
  /** \internal Use World::createScene()
  */
  Scene(const SceneDescription&, NxPhysicsSDK*);

  /** \internal Use World::destroyScene()
  */
  virtual ~Scene();
  
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

#if NxOgreHasCharacterController == 1
  /** \internal Master character controllers array
  */
  CharacterControllers mCharacterControllers;
#endif

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
  vector<Joint*> mJoints;

  /** \internal Master machines array
  */
  Machines          mMachines;
  
  MachineIterator   mMachineIterator;
  
  /** \internal
  */
  vector<Cloth*>  mCloths;

  /** \internal
  */
  vector<SoftBody*>  mSoftBodies;

  /** \internal
  */
  vector<Compartment*>  mCompartments;

  /** \internal Master kernels array
  */
  ForceFieldKernels  mForceFieldKernels;

#if NxOgreHasFluids == 1
  /** \brief
  */
  Fluids  mFluids;
#endif

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

  /**\ internal
  */
  Callback* mSleepCallback;

  /*\ internal Handy TimeListenerIterator
  */
  TimeListenerGroupIterator  mListenerIterator;
  
  /*\ internal  Before TimeListeners
  */
  TimeListenerGroups         mSimulateListenerGroups;

  /*\ internal  Before TimeListeners
  */
  TimeListenerGroups         mRenderListenerGroups;

  /*\ internal
  */
  TimeListenerGroup*         mSimulateWaitingListenerGroup;
  
  /*\ internal
  */
  TimeListenerGroup*         mRenderWaitingListenerGroup;

  /*\ internal
  */
  unsigned int               mNbSimulates;

  /*\ internal
  */
  unsigned int               mNbRenders;

}; // class Scene

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
