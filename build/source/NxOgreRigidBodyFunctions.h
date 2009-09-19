/** File: NxOgreRigidBodyFunctions.h
    Created on: 10-Nov-08
    Author: Robin Southern "betajaen"
    

    (c) Copyright, 2008 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option, NxActor*) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NXOGRE_RIGIDBODYFUNCTIONS_H
#define NXOGRE_RIGIDBODYFUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
namespace Functions
{

                                                                                       

namespace RigidBodyFunctions
{

                                                                                       


  /** \brief Assigns the actor to a user defined group of rigid bodies. 
  */
                        inline void                   setGroup(GroupIdentifier actorGroup, NxActor*); 

  /** \brief Retrieves the value set with setGroup(, NxActor*). 
  */
                        inline GroupIdentifier        getGroup(NxActor*) ;

  /** \brief Assigns dynamic actors a dominance group identifier. 
  */
                        inline void                   setDominanceGroup(GroupIdentifier dominanceGroup, NxActor*); 
  
  /** \brief Retrieves the value set with setDominanceGroup(, NxActor*). 
  */
                        inline GroupIdentifier        getDominanceGroup(NxActor*) ; 
 
  /**  \brief Reset the user actor pair filtering state for this actor. This will cause filtering callbacks
       to be called again for any pairs involving this actor. Use this method when you wish to change
       the filtering policy of an actor that may already be in contact with other actors. 
  */
                        inline void                   resetPairFiltering(NxActor*); 

  /** \brief Returns true if the actor is dynamic. 
  */
                        inline bool                   isDynamic(NxActor*) ; 

  /** \brief Computes the total kinetic (rotational and translational, NxActor*) energy of the object.
  */
                        inline Real                   computeKineticEnergy(NxActor*) ;

  /** \brief Sets the solver iteration count for the body. 
  */
                        inline void                   setSolverIterationCount(unsigned int iterCount, NxActor*);

  /** \brief Retrieves the solver iteration count.
  */
                        inline unsigned int           getSolverIterationCount(NxActor*) ; 

  /** \brief Retrieves the force threshold for contact reports. 
  */
                        inline Real                   getContactReportThreshold(NxActor*) ;

  /** \brief Sets the force threshold for contact reports. 
  */
                        inline void                   setContactReportThreshold(Real threshold, NxActor*);
  
  /** \brief Retrieves the actor's contact report flags. 
  */
                        inline unsigned int           getContactReportFlags(NxActor*) ;
 
  /** \brief Sets the actor's contact report flags.
  */
                        inline void                   setContactReportFlags(unsigned int flags, NxActor*);
   
  /// /** \brief Performs a linear sweep through space with the actor. 
  /// */
  ///                   NxU32                  linearSweep (const Vec3& motion, NxU32 flags, void *userData, NxU32 nbShapes, NxSweepQueryHit *shapes, NxUserEntityReport< NxSweepQueryHit > *callback, const NxSweepCache *sweepCache=NULL, NxActor*)=0 
 
  /// /** \brief  Retrieves the actor's simulation compartment, if any. 
  /// */
  ///                   NxCompartment*         getCompartment(NxActor*) ;
 
  /** \brief Retrieves the actor's force field material index, default index is 0. 
  */
                        inline unsigned short         getForceFieldMaterial(NxActor*) ; 
 
  /** \brief Sets the actor's force field material index, default index is 0. 
  */
                        inline void                   setForceFieldMaterial(unsigned short, NxActor*); 


/// Pose

  /** \brief Methods for setting a dynamic actor's pose in the world. 
  */
                        inline        void                   setGlobalPose(const Matrix44&, NxActor*);
 
  /** \brief Sets a dynamic actor's position in the world.
   */
                        inline        void                   setGlobalPosition (const Vec3&, NxActor*);
  
  /** \brief Sets a dynamic actor's orientation in the world.
  */
                        inline        void                   setGlobalOrientation(const Matrix33&, NxActor*);
 
  /** \brief Sets a dynamic actor's orientation in the world.
  */
                        inline        void                   setGlobalOrientationQuat(const Quat&, NxActor*);
 
  /** \brief Retrieves the actors world space transform.
  */
                        inline        Matrix44               getGlobalPose(NxActor*) ;

  /** \brief Retrieves the actors world space position.
  */
                        inline        Vec3                  getGlobalPosition(NxActor*) ;

  /** \brief Retrieves the actors world space orientation.
  */
                        inline        Matrix33               getGlobalOrientation(NxActor*) ;
  
  /** \brief Retrieves the actors world space orientation.
  */
                        inline        Quat                   getGlobalOrientationQuat(NxActor*);

  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
                        inline        void                   moveGlobalPose(const Matrix44&, NxActor*);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
                        inline        void                   moveGlobalPosition(const Vec3& , NxActor*);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
                        inline        void                   moveGlobalOrientation (const Matrix33&, NxActor*);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
                        inline        void                   moveGlobalOrientationQuat (const Quat&, NxActor*);

  /** \brief Creates a new shape and adds it to the list of shapes of this actor. 
  */
                        inline        void                   createShape(Shape*, NxActor*);
  
  /** \brief Deletes the specified shape.
  */
                        inline        void                   releaseShape(Shape*, NxActor*);
  
  /** \brief Returns the number of shapes assigned to the actor.
  */
                        inline        unsigned int           getNbShapes(NxActor*);

  /** \brief The setCMassOffsetLocal*(, NxActor*) methods set the pose of the center of mass relative to the actor.
  */
                          inline        void                 setCMassOffsetLocalPose(const Matrix44&, NxActor*);
  
  /** \brief The setCMassOffsetLocal*(, NxActor*) methods set the pose of the center of mass relative to the actor.
  */
                          inline        void                 setCMassOffsetLocalPosition(const Vec3& , NxActor*);
  
  /** \brief The setCMassOffsetLocal*(, NxActor*) methods set the pose of the center of mass relative to the actor.
  */
                          inline        void                 setCMassOffsetLocalOrientation(const Matrix33&, NxActor*);
  
  /** \brief The setCMassOffsetGlobal*(, NxActor*) methods set the pose of the center of mass relative to world space.
  */
                          inline        void                 setCMassOffsetGlobalPose(const Matrix44&, NxActor*);
  
  /** \brief The setCMassOffsetGlobal*(, NxActor*) methods set the pose of the center of mass relative to world space.
  */
                          inline        void                 setCMassOffsetGlobalPosition(const Vec3&, NxActor*); 

  /** \brief The setCMassOffsetGlobal*(, NxActor*) methods set the pose of the center of mass relative to world space.
  */
                          inline        void                 setCMassOffsetGlobalOrientation(const Matrix33&, NxActor*);

  /** \brief The setCMassGlobal*(, NxActor*) methods move the actor by setting the pose of the center of mass.
  */
                          inline        void                 setCMassGlobalPose(const Matrix44&, NxActor*);

  /** \brief The setCMassGlobal*(, NxActor*) methods move the actor by setting the pose of the center of mass.
  */
                          inline        void                 setCMassGlobalPosition(const Vec3& , NxActor*);
  
  /** \brief The setCMassGlobal*(, NxActor*) methods move the actor by setting the pose of the center of mass.
  */
                          inline        void                 setCMassGlobalOrientation (const Matrix33&, NxActor*);
  
  /** \brief The getCMassLocal*(, NxActor*) methods retrieve the center of mass pose relative to the actor.
  */
                          inline        Matrix44             getCMassLocalPose(NxActor*) ; 
  
  /** \brief The getCMassLocal*(, NxActor*) methods retrieve the center of mass pose relative to the actor.
  */
                          inline        Vec3                getCMassLocalPosition(NxActor*) ;
  
  /** \brief The getCMassLocal*(, NxActor*) methods retrieve the center of mass pose relative to the actor. 
  */
                          inline        Matrix33             getCMassLocalOrientation(NxActor*) ; 
  
  /** \brief The getCMassGlobal*(, NxActor*) methods retrieve the center of mass pose in world space. 
  */
                          inline        Matrix44             getCMassGlobalPose(NxActor*) ; 
  
  /** \brief The getCMassGlobal*(, NxActor*) methods retrieve the center of mass pose in world space. 
  */
                          inline        Vec3                getCMassGlobalPosition(NxActor*) ;
  
  /** \brief The getCMassGlobal*(, NxActor*) methods retrieve the center of mass pose in world space.
  */
                          inline        Matrix33             getCMassGlobalOrientation(NxActor*) ;
   
  /** \brief Sets the mass of a dynamic actor. 
  */
                          inline        void                 setMass(Real mass, NxActor*); 
  
  /** \brief Retrieves the mass of the actor. 
  */
                          inline        Real                 getMass(NxActor*); 
  
  /** \brief Sets the inertia tensor, using a parameter specified in mass space coordinates. 
  */
                         inline        void                  setMassSpaceInertiaTensor(const Vec3&, NxActor*); 
  
  /** \brief Retrieves the diagonal inertia tensor of the actor relative to the mass coordinate frame. 
  */
                         inline        Vec3                 getMassSpaceInertiaTensor(NxActor*) ; 
  
  /** \brief Retrieves the inertia tensor of the actor relative to the world coordinate frame.
  */
                         inline        Matrix33                getGlobalInertiaTensor(NxActor*) ; 
 
  /** \brief Retrieves the inverse of the inertia tensor of the actor relative to the world coordinate frame. 
  */
                         inline        Matrix33                getGlobalInertiaTensorInverse(NxActor*) ;
  
  /** \brief   Recomputes a dynamic actor's mass properties from its shapes. 
  */
                         inline        bool                  updateMassFromShapes(Real density, Real totalMass, NxActor*);

  /** \brief Sets the linear damping coefficient.
  */
                         inline        void                  setLinearDamping(Real linDamp, NxActor*);
   
  /** \brief Retrieves the linear damping coefficient.
  */
                         inline        Real                  getLinearDamping(NxActor*) ; 
  
  /** \brief Sets the angular damping coefficient.
  */
                         inline        void                  setAngularDamping(Real angDamp, NxActor*); 
   
  /** \brief Retrieves the angular damping coefficient.
  */
                         inline        Real                  getAngularDamping(NxActor*) ;

  /** \brief Sets the linear velocity of the actor.
  */
                         inline        void                  setLinearVelocity(const Vec3& , NxActor*);
  
  /** \brief Sets the angular velocity of the actor.
  */
                         inline        void                  setAngularVelocity(const Vec3& angVel, NxActor*);
  
  /** \brief Retrieves the linear velocity of an actor. 
  */
                         inline        Vec3                 getLinearVelocity(NxActor*) ;

  /** \brief Retrieves the angular velocity of the actor. 
  */
                         inline        Vec3                 getAngularVelocity (NxActor*) ;
  
  /** \brief Lets you set the maximum angular velocity permitted for this actor. 
  */
                         inline        void                  setMaxAngularVelocity(Real maxAngVel, NxActor*); 
  
  /** \brief Retrieves the maximum angular velocity permitted for this actor.
  */
                         inline        Real                  getMaxAngularVelocity(NxActor*) ;

  /** \brief Sets the CCD Motion Threshold. 
  */
                         inline        void                  setCCDMotionThreshold(Real thresh, NxActor*); 
  
  /** \brief Retrieves the CCD Motion threshold for this actor. 
  */
                         inline        Real                  getCCDMotionThreshold(NxActor*) ;

  /** \brief Sets the linear momentum of the actor.
  */
                         inline        void                  setLinearMomentum(const Vec3&  linMoment, NxActor*);
  
  /** \brief Sets the angular momentum of the actor.
  */
                         inline        void                  setAngularMomentum(const Vec3 &angMoment, NxActor*);
  
  /** \brief Retrieves the linear momentum of an actor.
  */
                         inline        Vec3                 getLinearMomentum(NxActor*) ; 
  
  /** \brief Retrieves the angular momentum of an actor.
  */
                         inline        Vec3                 getAngularMomentum(NxActor*) ;

  /** \brief Applies a force (or impulse, NxActor*) defined in the global coordinate frame, acting at a particular point in global coordinates, to the actor. 
  */
                         inline        void                  addForceAtPos (const Vec3&  force, const Vec3&  pos, Enums::ForceMode mode, bool wakeup, NxActor*); 

  /** \brief Applies a force (or impulse, NxActor*) defined in the global coordinate frame, acting at a particular point in local coordinates, to the actor. 
   */
                         inline        void                  addForceAtLocalPos(const Vec3&  force, const Vec3&  pos, Enums::ForceMode mode, bool wakeup, NxActor*); 
  
  /** \brief Applies a force (or impulse, NxActor*) defined in the actor local coordinate frame, acting at a particular point in global coordinates, to the actor.
  */
                         inline        void                  addLocalForceAtPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies a force (or impulse, NxActor*) defined in the actor local coordinate frame, acting at a particular point in local coordinates, to the actor. 
  */
                         inline        void                  addLocalForceAtLocalPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies a force (or impulse, NxActor*) defined in the global coordinate frame to the actor.
  */
                         inline        void                  addForce (const Vec3& force, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies a force (or impulse, NxActor*) defined in the actor local coordinate frame to the actor.
   */
                         inline        void                  addLocalForce (const Vec3& force, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies an impulsive torque defined in the global coordinate frame to the actor.
  */
                         inline        void                  addTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies an impulsive torque defined in the actor local coordinate frame to the actor.
  */
                         inline        void                  addLocalTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup, NxActor*);

  /** \brief Computes the velocity of a point given in world coordinates if it were attached to the actor and moving with it. 
  */
                         inline        Vec3                 getPointVelocity (const Vec3&  point, NxActor*) ;
  
  /** \brief Computes the velocity of a point given in body local coordinates as if it were attached to the actor and moving with it.
  */
                         inline        Vec3                 getLocalPointVelocity(const Vec3&  point, NxActor*) ; 

  /** \brief Returns true if this body and all the actors it is touching or is linked to with joints are sleeping. 
  */
                         inline        bool                  isGroupSleeping(NxActor*);

  /** \brief Returns true if this body is sleeping. 
  */
                         inline        bool                  isSleeping(NxActor*);
  
  /** \brief Returns the linear velocity below which an actor may go to sleep. 
  */
                         inline        Real                  getSleepLinearVelocity(NxActor*) ;

  /** \brief Sets the linear velocity below which an actor may go to sleep. 
  */
                         inline        void                  setSleepLinearVelocity(Real threshold, NxActor*);

  /** \brief Returns the angular velocity below which an actor may go to sleep. 
  */
                         inline        Real                  getSleepAngularVelocity(NxActor*);

  /** \brief Sets the angular velocity below which an actor may go to sleep. 
  */
                         inline        void                  setSleepAngularVelocity(Real threshold, NxActor*); 
  
  /** \brief Returns the energy below which an actor may go to sleep. 
  */
                         inline        Real                  getSleepEnergyThreshold(NxActor*);
  
  /** \brief Sets the energy threshold below which an actor may go to sleep. 
  */
                         inline        void                 setSleepEnergyThreshold(Real threshold, NxActor*); 
  
  /** \brief Wakes up the actor if it is sleeping.
      \default Real(20.0 * 0.02)
  */
                         inline        void                 wakeUp(Real wakeCounterValue, NxActor*);
  
  /** \brief   Forces the actor to sleep. 
  */
                         inline        void                 putToSleep(NxActor*);


                         inline        RigidBody*           NxShapeToRigidBody(NxShape&);

                                                                                       

} // namespace RigidBody

                                                                                       

} // namespace Function

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
