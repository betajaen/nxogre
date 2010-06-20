/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

                                                                                       

#ifndef NXOGRE_ACTOR_H
#define NXOGRE_ACTOR_H

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShape.h"

#include "NxOgreRigidBody.h"
#include "NxOgreDynamicRigidBodyFlags.h"
#include "NxOgreString.h"
#include "NxOgreSweepQuery.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Actor
    desc.
        Actor is a dynamic(moving) RigidBody, that can collide with SceneGeometries and KinematicActors.
        
        p. It is normal to inherit from the Actor to support visualisation in a RenderSystem, broadly
        speaking any class that inherits the Actor class is called a *Body*.
        
        p. Actors uses RigidBodyDescriptions to create it's properities as well as a Matrix44 pose, a *Shape*
        or group of *Shapes*. The RigidBodyDescription is required to have a mass is at least zero, or otherwise
        a density of at least zero - but not both.
        
    example.
        RigidBodyDescription description;
        description.mMass = 15.0f; // 15 kg
    
        Actor* actor = mScene->createActor(shape, pose, description);
    
    see. RigidBody
*/
class NxOgrePublicClass Actor : public RigidBody
{
  
  
  NXOGRE_GC_FRIEND_NEW4
  NXOGRE_GC_FRIEND_DELETE
  
  public:
  
  /*! function. getRigidBodyType
      desc.
          Get the cpp type(see Classes namespace) as a unsigned integer.
      note.
          All classes that inherit from RigidBody, and classes that inherit from them, and them must implement getRigidBodyType
      return.
          **unsigned int** -- The class type, Classes::_Actor in this case.
  */
  virtual unsigned int  getRigidBodyType() const;
    
  /*! function. isActorBased
      desc.
          Returns true if this class is an Actor or inherits from it.
      return.
          **true** -- It is an Actor or Actor based class.
  */
  bool  isActorBased() const;

  /*! function. raiseDynamicFlag
      desc.
          Set a dynamic flag.
  */
  void raiseDynamicFlag(DynamicRigidbodyFlags::Flags);
  
  /*! function. clearDynamicFlag
      desc.
          Clear a dynamic flag.
  */
  void clearDynamicFlag(DynamicRigidbodyFlags::Flags);
  
  /*! function. hasDynamicFlag
      desc.
          Is a dynamic flag set?
  */
  bool hasDynamicFlag(DynamicRigidbodyFlags::Flags) const;
  
  /*! function. setGroup
      desc.
          Assigns the actor to a user defined group of rigid bodies.
      args.
          GroupIdentifier _actorGroup_ -- The actorGroup for the Actor to be assigned to.
      note. This wakes up the Actor.
  */
  void setGroup(GroupIdentifier actorGroup); 

  /*! function. getGroup
      desc.
           Retrieves the value set with setGroup()
      return.
           GroupIdentifier -- The actorGroup the Actor belongs too.
  */
  GroupIdentifier getGroup() const;

  /*! function. setDominanceGroup
      desc.
           Assigns dynamic actors a dominance group identifier.
      args.
           GroupIdentifier __dominanceGroup__ -- The domninance actorGroup for the Actor to be assigned to.
      note. This wakes up the Actor.
  */
  void setDominanceGroup(GroupIdentifier dominanceGroup); 
  
  /*! function. getDominanceGroup
      desc.
           Retrieves the value set with setDominanceGroup().
            
      return.
           GroupIdentifier -- The dominance actorGroup the Actor belongs too.
  */
  GroupIdentifier getDominanceGroup() const;
 
  /*! function. resetPairFiltering
      desc.
           Reset the user actor pair filtering state for this actor. This will cause filtering callbacks
           to be called again for any pairs involving this actor. Use this method when you wish to change
           the filtering policy of an actor that may already be in contact with other actors.
  */
  void resetPairFiltering(); 

  /*! function. computeKineticEnergy
      desc.
           Computes the total kinetic(rotational and translational) energy of the actor.
           
      return.
           Real -- The total kinetic energy of the actor.
  */
  Real computeKineticEnergy() const;

  /*! function. setSolverIterationCount
      desc.
           Sets the solver iteration count for the actor.
      args.
           unsigned int _iterCount_ -- New Solver iteration count.
  */
  void setSolverIterationCount(unsigned int iterCount);

  /*! function. getSolverIterationCount
      desc.
           Retrieves the solver iteration count.
      return.
           unsigned int -- Solver iteration count for the actor.
  */
  unsigned int getSolverIterationCount() const; 

  /*! function. getContactReportThreshold
      desc.
           Retrieves the force threshold for contact reports.
      return.
           Real -- The force threshold
  */
  Real getContactReportThreshold() const;

  /*! function. setContactReportThreshold
      desc.
           Sets the force threshold for contact reports.
      args.
            Real __threshold__ -- New force threshold
  */
  void setContactReportThreshold(Real threshold);
  
  /*! function. getContactReportFlags
      desc.
           Retrieves the actor's contact report flags.
      return.
           Actor contact report flags
  */
  unsigned int getContactReportFlags() const;
 
  /*! function. setContactReportFlags
      desc.
           Sets the actor's contact report flags.
      args.
           unsigned int __flags__ -- New contact report flags.
  */
  void setContactReportFlags(unsigned int flags);
   
  /*! function. linearSweep
      desc.
           Performs a linear sweep through space with the actor's shape(s).
           
      args.
           const Vec3& __motion__ -- Motion to sweep
           unsigned int __sweepFlags__  -- Sweep Flags, see *Enums::SweepFlags*
           unsigned int __size__ -- Maximum shapes to sweep through
           SweepQueryHits& -- Hits found once swept.
           SweepCache* -- Sweeping Cache to perform any future linearSweeps with this actor.
           
      return.
           unsigned int -- Number of SweepHits
  */
  unsigned int linearSweep(const Vec3& motion, unsigned int sweepFlags, unsigned int size, SweepQueryHits&, SweepCache* = 0); 

  /*! function. getCompartment
      desc.
            Retrieves the actor's simulation compartment, if any.
      return.
            Compartment* -- The Actors compartment, or *NULL*.
  */
  Compartment* getCompartment();
 
  /*! function. getForceFieldMaterial
      desc.
            Retrieves the actor's force field material index.
      return.
            unsigned short -- Force field material index.
  */
  unsigned short getForceFieldMaterial() const; 
 
  /*! function. setForceFieldMaterial
      desc. 
            Sets the actor's force field material index
      args.
            unsigned short __material__ -- New forcefield material to use.
  */
  void setForceFieldMaterial(unsigned short material); 
  
  /*! function. setGlobalPose
      desc.
           Set the global pose of the Actor
      args.
           const Matrix44& __globalPose__ -- New Actor pose.
  */
  void setGlobalPose(const Matrix44& globalPose);
 
  /*! function. setGlobalPosition
      desc.
           Set's the global position of the Actor.
      args.
           const Vec3& __position__ -- New Actor position.
  */
  void setGlobalPosition(const Vec3& position);
  void setGlobalPosition(Real x, Real y, Real z);
  
  /*! function. setGlobalOrientation
      desc.
           Set's the global orientation of the Actor.
      args.
           const Matrix33& __orientation__ -- New Actor orientation.
  */
  void setGlobalOrientation(const Matrix33& orientation);
 
  
  /*! function. setGlobalOrientationQuat
      desc.
           Set's the global orientation of the Actor.
      args.
           const Quat& __orientation__ -- New Actor orientation.
  */
  void setGlobalOrientationQuat(const Quat&);
  void setGlobalOrientationQuat(Real w, Real x, Real y, Real z);
  
  /*! function. getGlobalPose
      desc.
           Get the global pose of the Actor.
      return.
           Matrix44 -- The global pose of the Actor.
  */
  Matrix44 getGlobalPose() const;
  
  /*! function. getGlobalPosition
      desc.
           Get the global position of the Actor.
      return.
           Matrix44 -- The global pose of the Actor.
  */
  Vec3 getGlobalPosition() const;

  /*! function. getGlobalOrientation
      desc.
           Get the global orientation of the Actor.
      return.
           Matrix33 -- The global pose of the Actor.
  */
  Matrix33 getGlobalOrientation() const;

  /*! function. getGlobalOrientation
      desc. 
           Get the global orientation of the Actor.
      return.
           Quat -- The global pose of the Actor.
  */
  Quat getGlobalOrientationQuat() const;
  
  /*! function. setCMassOffsetLocalPose
      desc.
           Set the center of mass offset 
      args.
           const Matrix44& __pose__ -- New COM pose
      note. This wakes up the Actor.
  */
  void setCMassOffsetLocalPose(const Matrix44&);
  
  /*! function. setCMassOffsetLocalPosition
      desc.
           Set the center of mass offset
      args.
           const Vec3& __position__ -- New COM position
      note. This wakes up the Actor.
  */
  void setCMassOffsetLocalPosition(const Vec3& position);
  void setCMassOffsetLocalPosition(Real x, Real y, Real z);
  
  /*! function. setCMassOffsetLocalOrientation
      desc.
           Set the center of mass offset
      args.
           const Matrix33& __orientation__ -- New COM orientation
      note. This wakes up the Actor.
  */
  void setCMassOffsetLocalOrientation(const Matrix33&);
  
  /*! function. setCMassOffsetGlobalPose
      desc.
           Set the center of mass offset
      args.
           const Matrix44& __pose__ -- New COM pose
      note. This wakes up the Actor.
  */
  void setCMassOffsetGlobalPose(const Matrix44&);
  
  /*! function. setCMassOffsetGlobalPosition
      desc.
           Set the center of mass offset
      args.
           const Vec3& __position__ -- New COM position
      note. This wakes up the Actor.
  */
  void setCMassOffsetGlobalPosition(const Vec3&); 
  void setCMassOffsetGlobalPosition(Real x, Real y, Real z); 
  
  /*! function. setCMassOffsetGlobalOrientation
      desc.
           Set the center of mass offset
      args.
           const Matrix33& __orientation__ -- New COM orientation
      note. This wakes up the Actor.
  */
  void setCMassOffsetGlobalOrientation(const Matrix33&);
  
  /*! function. setCMassGlobalPose
      desc.
           Set the center of mass
      args.
           const Matrix44& __pose__ -- New COM pose
      note. This wakes up the Actor.
  */
  void setCMassGlobalPose(const Matrix44&);
  
  /*! function. setCMassGlobalPosition
      desc.
           Set the center of mass
      args.
           const Vec3& __position__ -- New COM position
      note. This wakes up the Actor.
  */
  void setCMassGlobalPosition(const Vec3&);
  void setCMassGlobalPosition(Real x, Real y, Real z); 
  
  /*! function. setCMassGlobalOrientation
      desc.
           Set the center of mass
      args.
           const Matrix33& __orientation__ -- New COM orientation
      note. This wakes up the Actor.
  */
  void setCMassGlobalOrientation(const Matrix33&);
  
  /*! function. getCMassLocalPose
      desc.
           Get the center of mass as a local pose
      return.
           Matrix44 -- Local COM pose
  */
  Matrix44 getCMassLocalPose() const; 
  
  /*! function. getCMassLocalPose
      desc.
           Get the center of mass as a local pose
      return.
           Vec3 -- Local COM position
  */
  Vec3   getCMassLocalPosition() const;
  
  /*! function. getCMassLocalPose
      desc.
           Get the center of mass as a local orientation
      return.
           Matrix33 -- Local COM orientation
  */
  Matrix33 getCMassLocalOrientation() const; 
  
  /*! function. getCMassLocalPose
      desc.
           Get the center of mass as a global pose
      return.
           Matrix44 -- Global COM pose
  */
  Matrix44 getCMassGlobalPose() const; 
  
  /*! function. getCMassLocalPose
      desc.
           Get the center of mass as a global position
      return.
           Vec3 -- Global COM position
  */
  Vec3 getCMassGlobalPosition() const;
  
  /*! function. getCMassLocalPose
      desc.
           Get the center of mass as a global orientation
      return.
           Matrix33 -- Global COM orientation
  */
  Matrix33 getCMassGlobalOrientation() const;
  
  /*! function. setMass
      desc.
           Set the mass of the Actor
      args.
           Real __mass__ -- New mass of the Actor
      !no_wake
  */
  void setMass(Real mass); 
  
  /*! function. getMass
      Retrieves the mass of the actor. 
      return Real -- Mass of the actor.
  */
  Real getMass() const; 
  
  /*! function. setMassSpaceInertiaTensor
      desc.
           Sets the inertia tensor, using a parameter specified in mass space coordinates.
      args.
           const Vec3& __tensor__ -- New Mass Space Inertia Tensor
      !no_wake
  */
  void setMassSpaceInertiaTensor(const Vec3& tensor); 
  
  /*! function. getMassSpaceInertiaTensor
      desc.
           Retrieves the diagonal inertia tensor of the actor relative to the mass coordinate frame. 
      return.
           Vec3 -- Mass Space Inertia tensor
  */
  Vec3 getMassSpaceInertiaTensor() const; 
  
  /*! function. getGlobalInertiaTensor
      desc.
           Retrieves the inertia tensor of the actor relative to the world coordinate frame.
      return.
           Matrix33 -- Inertia Tensor
  */
  Matrix33 getGlobalInertiaTensor() const; 
 
  /*! function. getGlobalInertiaTensorInverse
      desc.
           Retrieves the inverse of the inertia tensor of the actor relative to the world coordinate frame.
      return.
           Matrix33 -- Inverse Inertia Tensor
  */
  Matrix33 getGlobalInertiaTensorInverse() const;
  
  /*! function. updateMassFromShapes
      desc.
           Recomputes a dynamic actor's mass properties from its shapes
           
           p. Given a constant density or total mass, the actors mass properties can be recomputed
           using the shapes attached to the actor. 
           
           p. The mass of each shape is either the shape's local density(default 1.0)  multiplied by the shape's volume
           or a directly specified shape mass. 
           
           p. The inertia tensor, mass frame and center of mass will always be recomputed. If there are no
           shapes in the actor, the mass will be totalMass, and the mass frame will be set to the center
           of the actor.
           
           p. If you supply a non-zero total mass, the actor's mass and inertia will first be computed as
           above and then scaled to fit this total mass.
           
           p. If you supply a non-zero density, the actor's mass and inertia will first be computed as above
           and then scaled by this factor.
           
           note. Either totalMass or density must be non-zero.
           
      args.
           float __density__ -- Density scale factor of the shapes belonging to the actor
           float __totalMass__ -- Total mass of the actor(or zero)
      return.
           bool -- True if succesful
  */
  bool updateMassFromShapes(Real density, Real totalMass) const;

  /*! function. setLinearDamping
      desc.
           Sets the linear(translational movement) damping coefficient.
      args.
           Real __linDamp__ -- New linear damping
  */
  void setLinearDamping(Real linDamp);
   
  /*! function. getLinearDamping
      desc.
           Retrieves the linear damping coefficient.
      return.
           Real -- Current linear damping
  */
  Real getLinearDamping() const; 
  
  /*! function. setAngularDamping
      desc.
           Sets the angular(angular movement) damping coefficient.
      args.
           Real __angDamp__ -- New angular damping
  */
  void setAngularDamping(Real angDamp); 
   
  /*! function. getAngularDamping
      desc.
           Retrieves the angular damping coefficient.
      return.
           Real -- Current angular damping
  */
  Real getAngularDamping() const;

  /*! function. setLinearVelocity
      Sets the linear velocity of the actor.
      note.
           That if you continuously set the velocity of an actor yourself, forces such
           as gravity or friction will not be able to manifest themselves, because forces
           directly influence only the velocity/momentum of an actor.
      note. This wakes up the Actor.
      args.
           const Vec3& __linVel__ -- New linear velocity of the actor.
  */
  void setLinearVelocity(const Vec3& linVel);
  void setLinearVelocity(Real x, Real y, Real z);
  
  /*! function. setAngularVelocity
      desc.
           Sets the angular velocity of the actor.
      note.
           That if you continuously set the velocity of an actor yourself, forces such
           as gravity or friction will not be able to manifest themselves, because forces
           directly influence only the velocity/momentum of an actor.
      note. This wakes up the Actor.
      args.
           const Vec3& __angVel__ -- New angular velocity of the actor.
      
  */
  void setAngularVelocity(const Vec3& angVel);
  void setAngularVelocity(Real x, Real y, Real z);
  
  /*! function. getLinearVelocity
      desc.  
             Retrieves the linear velocity of an actor.
      return. 
             Vec3 -- Current linear velocity
  */
  Vec3 getLinearVelocity() const;
  
  /*! function. getAngularVelocity
      desc.
             Retrieves the angular velocity of an actor.
      return.
             Vec3 -- Current angular velocity
  */
  Vec3 getAngularVelocity() const;
  
  /*! function. setMaxAngularVelocity
      desc.
           Lets you set the maximum angular velocity permitted for this actor. 
           
           p. Because for various internal computations, very quickly rotating actors introduce error 
           into the simulation, which leads to undesired results.
           
           p. However, because some actors, such as car wheels, should be able to rotate quickly, you can override the default setting
           on a per-actor basis with the below call. Note that objects such as wheels which are approximated with spherical or 
           other smooth collision primitives can be simulated with stability at a much higher angular velocity than, say, a box that
           has corners.
           
      note.
           The angular velocity is clamped to the set value _before_ the solver, which means that
           the limit may still be momentarily exceeded.
           
      args.
           Real __maxAngVel__ -- Max allowable angular velocity for actor
  */
  void setMaxAngularVelocity(Real maxAngVel); 
  
  /*! function. getMaxAngularVelocity
      desc.
              Retrieves the maximum angular velocity permitted for this actor.
      return.
              Real -- The maximum allowed angular velocity for this actor.
  */
  Real getMaxAngularVelocity() const;

  /*! function. setCCDMotionThreshold
      desc.  
             Sets the CCD Motion Threshold.
             
             p. If CCD is globally enabled, it is still skipped for bodies
             which have no point on any of their shapes moving more than CCDMotionThreshold distance in 
             one time step.  
             
             p. Hence, CCD is always performed if the threshold is 0.
             
             p. The actor must be dynamic and the CCD motion threshold must be non-negative.
             
      args.  
           Real __thresh__ -- CCD Motion threshold
  */
  void setCCDMotionThreshold(Real thresh); 
  
  /*! function. getCCDMotionThreshold
      desc.  
             Retrieves the CCD Motion threshold for this actor.
      return.
             Real - Motion threshold
  */
  Real getCCDMotionThreshold() const;

  /*! function. setLinearMomentum
      desc. 
            Sets the linear momentum of the actor.
            
      note. That if you continuously set the linear momentum of an actor yourself, 
            forces such as gravity or friction will not be able to manifest themselves, because forces directly
            influence only the velocity/momentum of a actor.
      args.
            const Vec3& __linMoment__ -- New linear momentum
      note. This wakes up the Actor.
  */
  void setLinearMomentum(const Vec3& linMoment);
  void setLinearMomentum(Real x, Real y, Real z);

  /*! function. setAngularMomentum
      desc. 
            Sets the angular momentum of the actor.
            
      note. That if you continuously set the angular momentum of an actor yourself, 
            forces such as gravity or friction will not be able to manifest themselves, because forces directly
            influence only the velocity/momentum of a actor.
      args.
            const Vec3& __angMoment__ -- New angular momentum
      note. This wakes up the Actor.
  */
  void setAngularMomentum(const Vec3& angMoment);
  void setAngularMomentum(Real x, Real y, Real z);

  /*! function. getLinearMomentum
      desc.  
             Retrieves the linear momentum(velocity * mass) of an actor.
             
      return.
             Vec3 - Linear momentum of the Actor.
  */
  Vec3 getLinearMomentum() const; 

  /*! function. getAngularMomentum
      desc.  
             Retrieves the angular momentum(angular velocity * global space inertia) of an actor.
             
      return.
             Vec3 - angular momentum of the Actor.
  */
  Vec3 getAngularMomentum() const;

  /** \brief Applies a force(or impulse) defined in the global coordinate frame, acting at a particular point in global coordinates, to the actor. 
  */
  void addForceAtPos(const Vec3&  force, const Vec3&  pos, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true); 

  /** \brief Applies a force(or impulse) defined in the global coordinate frame, acting at a particular point in local coordinates, to the actor. 
   */
  void addForceAtLocalPos(const Vec3&  force, const Vec3&  pos, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);

  /** \brief Applies a force(or impulse) defined in the actor local coordinate frame, acting at a particular point in global coordinates, to the actor.
  */
  void addLocalForceAtPos(const Vec3& force, const Vec3& pos, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);

  /** \brief Applies a force(or impulse) defined in the actor local coordinate frame, acting at a particular point in local coordinates, to the actor.
  */
  void addLocalForceAtLocalPos(const Vec3& force, const Vec3& pos, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies a force(or impulse) defined in the global coordinate frame to the actor.
  */
  void addForce(const Vec3& force, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies a force(or impulse) defined in the actor local coordinate frame to the actor.
   */
  void addLocalForce(const Vec3& force, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies an impulsive torque defined in the global coordinate frame to the actor.
  */
  void addTorque(const Vec3& torque, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies an impulsive torque defined in the actor local coordinate frame to the actor.
  */
  void addLocalTorque(const Vec3& torque, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);

  /** \brief Computes the velocity of a point given in world coordinates if it were attached to the actor and moving with it. 
  */
  Vec3 getPointVelocity(const Vec3&  point) const;

  /** \brief Computes the velocity of a point given in body local coordinates as if it were attached to the actor and moving with it.
  */
  Vec3 getLocalPointVelocity(const Vec3&  point) const; 

  /** \brief Returns true if this body and all the actors it is touching or is linked to with joints are sleeping. 
  */
  bool isGroupSleeping() const;

  /** \brief Returns true if this body is sleeping. 
  */
  bool isSleeping() const;

  /** \brief Returns the linear velocity below which an actor may go to sleep. 
  */
  Real getSleepLinearVelocity() const;

  /** \brief Sets the linear velocity below which an actor may go to sleep. 
  */
  void setSleepLinearVelocity(Real threshold);

  /** \brief Returns the angular velocity below which an actor may go to sleep. 
  */
  Real getSleepAngularVelocity() const;

  /** \brief Sets the angular velocity below which an actor may go to sleep. 
  */
  void setSleepAngularVelocity(Real threshold); 

  /** \brief Returns the energy below which an actor may go to sleep. 
  */
  Real getSleepEnergyThreshold() const;

  /** \brief Sets the energy threshold below which an actor may go to sleep. 
  */
  void setSleepEnergyThreshold(Real threshold); 

  /** \brief Wakes up the actor if it is sleeping.
      \default Real(20.0 * 0.02)
  */
  void wakeUp(Real wakeCounterValue);

  /** \brief Forces the actor to sleep. 
  */
  void putToSleep();

  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;

  protected: // Functions

  /*! function. createDynamic.0
      desc.
          Become a Dynamic RigidBody (Actors) based on the arguments.
      note.
          User classes that inherit Actor should call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           const ShapeDescription& __shape__ -- The Single shape for the RigidBody to use. Cannot be NULL.
      !protected
  */
  void  createDynamic(const Matrix44& matrix_pose, const RigidBodyDescription& description, const ShapeDescription& shape);
  
  /*! function. createDynamic.1
      desc.
          Become a Dynamic RigidBody (Actor) based on the arguments.
      note.
          User classes that inherit Actor should call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createDynamic(const Matrix44& matrix_pose, const RigidBodyDescription&, const ShapeDescriptions& shapes);

  /*! constructor. Actor
      desc.
          Classes that inherit from Actor should use this constructor.
  */
  Actor(Scene*);

  /*! constructor. Actor
      desc.
          Use Scene::createActor
  */
  Actor(const ShapeDescription&, const Matrix44& pose, const RigidBodyDescription&, Scene*);

  /*! constructor. Actor
      desc.
          Use Scene::createActor
  */
  Actor(const ShapeDescriptions&, const Matrix44& pose, const RigidBodyDescription&, Scene*);

  /*! destructor. Actor
      desc.
          Use Scene::destroyActor
  */
  virtual ~Actor();
  
}; // class Actor

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
