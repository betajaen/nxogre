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

                                                                                       

#ifndef NXOGRE_RIGIDBODYFUNCTIONS_H
#define NXOGRE_RIGIDBODYFUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

namespace NxOgre
{
namespace Functions
{

class NxOgrePublicClass NxActorFunctions
{
  
 public:
  
                                                                                       
  
  /*! function. raiseBodyFlag
      desc.
          Set a body flag.
  */
  static void raiseBodyFlag(int, NxActor*);
  
  /*! function. clearBodyFlag
      desc.
          Clear a body flag.
  */
  static void clearBodyFlag(int, NxActor*);
  
  /*! function. hasBodyFlag
      desc.
          Is a body flag set?
  */
  static bool hasBodyFlag(int, NxActor*);

  /** \brief Assigns the actor to a user defined group of rigid bodies.
  */
  static void setGroup(GroupIdentifier actorGroup, NxActor*);

  /** \brief Retrieves the value set with setGroup(, NxActor*).
  */
  static GroupIdentifier getGroup(NxActor*) ;

  /** \brief Assigns dynamic actors a dominance group identifier.
  */
  static void setDominanceGroup(GroupIdentifier dominanceGroup, NxActor*);
  
  /** \brief Retrieves the value set with setDominanceGroup(, NxActor*).
  */
  static GroupIdentifier getDominanceGroup(NxActor*) ;
 
  /** \brief Reset the user actor pair filtering state for this actor. This will cause filtering callbacks
  to be called again for any pairs involving this actor. Use this method when you wish to change
  the filtering policy of an actor that may already be in contact with other actors.
  */
  static void resetPairFiltering(NxActor*);

  /** \brief Returns true if the actor is dynamic.
  */
  static bool isDynamic(NxActor*) ;

  /** \brief Computes the total kinetic (rotational and translational, NxActor*) energy of the object.
  */
  static Real computeKineticEnergy(NxActor*) ;

  /** \brief Sets the solver iteration count for the body.
  */
  static void setSolverIterationCount(unsigned int iterCount, NxActor*);

  /** \brief Retrieves the solver iteration count.
  */
  static unsigned int getSolverIterationCount(NxActor*) ;

  /** \brief Retrieves the force threshold for contact reports.
  */
  static Real getContactReportThreshold(NxActor*) ;

  /** \brief Sets the force threshold for contact reports.
  */
  static void setContactReportThreshold(Real threshold, NxActor*);
  
  /** \brief Retrieves the actor's contact report flags.
  */
  static unsigned int getContactReportFlags(NxActor*) ;
 
  /** \brief Sets the actor's contact report flags.
  */
  static void setContactReportFlags(unsigned int flags, NxActor*);
   
  /// /** \brief Performs a linear sweep through space with the actor.
  /// */
  /// NxU32 linearSweep (const Vec3& motion, NxU32 flags, void *userData, NxU32 nbShapes, NxSweepQueryHit *shapes, NxUserEntityReport< NxSweepQueryHit > *callback, const NxSweepCache *sweepCache=NULL, NxActor*)=0
 
  /// /** \brief Retrieves the actor's simulation compartment, if any.
  /// */
  /// NxCompartment* getCompartment(NxActor*) ;
 
  /** \brief Retrieves the actor's force field material index, default index is 0.
  */
  static unsigned short getForceFieldMaterial(NxActor*) ;
 
  /** \brief Sets the actor's force field material index, default index is 0.
  */
  static void setForceFieldMaterial(unsigned short, NxActor*);


  /// Pose

  /** \brief Methods for setting a dynamic actor's pose in the world.
  */
  static void setGlobalPose(const Matrix44&, NxActor*);
 
  /** \brief Sets a dynamic actor's position in the world.
  */
  static void setGlobalPosition (const Vec3&, NxActor*);
  
  /** \brief Sets a dynamic actor's orientation in the world.
  */
  static void setGlobalOrientation(const Matrix33&, NxActor*);
 
  /** \brief Sets a dynamic actor's orientation in the world.
  */
  static void setGlobalOrientationQuat(const Quat&, NxActor*);
 
  /** \brief Retrieves the actors world space transform.
  */
  static Matrix44 getGlobalPose(NxActor*) ;

  /** \brief Retrieves the actors world space position.
  */
  static Vec3 getGlobalPosition(NxActor*) ;

  /** \brief Retrieves the actors world space orientation.
  */
  static Matrix33 getGlobalOrientation(NxActor*) ;
  
  /** \brief Retrieves the actors world space orientation.
  */
  static Quat getGlobalOrientationQuat(NxActor*);

  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world.
  */
  static void moveGlobalPose(const Matrix44&, NxActor*);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world.
  */
  static void moveGlobalPosition(const Vec3& , NxActor*);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world.
  */
  static void moveGlobalOrientation (const Matrix33&, NxActor*);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world.
  */
  static void moveGlobalOrientationQuat (const Quat&, NxActor*);
  
  /** \brief Returns the number of shapes assigned to the actor.
  */
  static unsigned int getNbShapes(NxActor*);

  /** \brief The setCMassOffsetLocal*(, NxActor*) methods set the pose of the center of mass relative to the actor.
  */
   static void setCMassOffsetLocalPose(const Matrix44&, NxActor*);
  
  /** \brief The setCMassOffsetLocal*(, NxActor*) methods set the pose of the center of mass relative to the actor.
  */
   static void setCMassOffsetLocalPosition(const Vec3& , NxActor*);
  
  /** \brief The setCMassOffsetLocal*(, NxActor*) methods set the pose of the center of mass relative to the actor.
  */
   static void setCMassOffsetLocalOrientation(const Matrix33&, NxActor*);
  
  /** \brief The setCMassOffsetGlobal*(, NxActor*) methods set the pose of the center of mass relative to world space.
  */
   static void setCMassOffsetGlobalPose(const Matrix44&, NxActor*);
  
  /** \brief The setCMassOffsetGlobal*(, NxActor*) methods set the pose of the center of mass relative to world space.
  */
   static void setCMassOffsetGlobalPosition(const Vec3&, NxActor*);

  /** \brief The setCMassOffsetGlobal*(, NxActor*) methods set the pose of the center of mass relative to world space.
  */
   static void setCMassOffsetGlobalOrientation(const Matrix33&, NxActor*);

  /** \brief The setCMassGlobal*(, NxActor*) methods move the actor by setting the pose of the center of mass.
  */
   static void setCMassGlobalPose(const Matrix44&, NxActor*);

  /** \brief The setCMassGlobal*(, NxActor*) methods move the actor by setting the pose of the center of mass.
  */
   static void setCMassGlobalPosition(const Vec3& , NxActor*);
  
  /** \brief The setCMassGlobal*(, NxActor*) methods move the actor by setting the pose of the center of mass.
  */
   static void setCMassGlobalOrientation (const Matrix33&, NxActor*);
  
  /** \brief The getCMassLocal*(, NxActor*) methods retrieve the center of mass pose relative to the actor.
  */
   static Matrix44 getCMassLocalPose(NxActor*) ;
  
  /** \brief The getCMassLocal*(, NxActor*) methods retrieve the center of mass pose relative to the actor.
  */
   static Vec3 getCMassLocalPosition(NxActor*) ;
  
  /** \brief The getCMassLocal*(, NxActor*) methods retrieve the center of mass pose relative to the actor.
  */
   static Matrix33 getCMassLocalOrientation(NxActor*) ;
  
  /** \brief The getCMassGlobal*(, NxActor*) methods retrieve the center of mass pose in world space.
  */
   static Matrix44 getCMassGlobalPose(NxActor*) ;
  
  /** \brief The getCMassGlobal*(, NxActor*) methods retrieve the center of mass pose in world space.
  */
   static Vec3 getCMassGlobalPosition(NxActor*) ;
  
  /** \brief The getCMassGlobal*(, NxActor*) methods retrieve the center of mass pose in world space.
  */
   static Matrix33 getCMassGlobalOrientation(NxActor*) ;
   
  /** \brief Sets the mass of a dynamic actor.
  */
   static void setMass(Real mass, NxActor*);
  
  /** \brief Retrieves the mass of the actor.
  */
   static Real getMass(NxActor*);
  
  /** \brief Sets the inertia tensor, using a parameter specified in mass space coordinates.
  */
  static void setMassSpaceInertiaTensor(const Vec3&, NxActor*);
  
  /** \brief Retrieves the diagonal inertia tensor of the actor relative to the mass coordinate frame.
  */
  static Vec3 getMassSpaceInertiaTensor(NxActor*) ;
  
  /** \brief Retrieves the inertia tensor of the actor relative to the world coordinate frame.
  */
  static Matrix33 getGlobalInertiaTensor(NxActor*) ;
 
  /** \brief Retrieves the inverse of the inertia tensor of the actor relative to the world coordinate frame.
  */
  static Matrix33 getGlobalInertiaTensorInverse(NxActor*) ;
  
  /** \brief Recomputes a dynamic actor's mass properties from its shapes.
  */
  static bool updateMassFromShapes(Real density, Real totalMass, NxActor*);

  /** \brief Sets the linear damping coefficient.
  */
  static void setLinearDamping(Real linDamp, NxActor*);
   
  /** \brief Retrieves the linear damping coefficient.
  */
  static Real getLinearDamping(NxActor*) ;
  
  /** \brief Sets the angular damping coefficient.
  */
  static void setAngularDamping(Real angDamp, NxActor*);
   
  /** \brief Retrieves the angular damping coefficient.
  */
  static Real getAngularDamping(NxActor*) ;

  /** \brief Sets the linear velocity of the actor.
  */
  static void setLinearVelocity(const Vec3& , NxActor*);
  
  /** \brief Sets the angular velocity of the actor.
  */
  static void setAngularVelocity(const Vec3& angVel, NxActor*);
  
  /** \brief Retrieves the linear velocity of an actor.
  */
  static Vec3 getLinearVelocity(NxActor*) ;

  /** \brief Retrieves the angular velocity of the actor.
  */
  static Vec3 getAngularVelocity (NxActor*) ;
  
  /** \brief Lets you set the maximum angular velocity permitted for this actor.
  */
  static void setMaxAngularVelocity(Real maxAngVel, NxActor*);
  
  /** \brief Retrieves the maximum angular velocity permitted for this actor.
  */
  static Real getMaxAngularVelocity(NxActor*) ;

  /** \brief Sets the CCD Motion Threshold.
  */
  static void setCCDMotionThreshold(Real thresh, NxActor*);
  
  /** \brief Retrieves the CCD Motion threshold for this actor.
  */
  static Real getCCDMotionThreshold(NxActor*) ;

  /** \brief Sets the linear momentum of the actor.
  */
  static void setLinearMomentum(const Vec3& linMoment, NxActor*);
  
  /** \brief Sets the angular momentum of the actor.
  */
  static void setAngularMomentum(const Vec3 &angMoment, NxActor*);
  
  /** \brief Retrieves the linear momentum of an actor.
  */
  static Vec3 getLinearMomentum(NxActor*) ;
  
  /** \brief Retrieves the angular momentum of an actor.
  */
  static Vec3 getAngularMomentum(NxActor*) ;

  /** \brief Applies a force (or impulse, NxActor*) defined in the global coordinate frame, acting at a particular point in global coordinates, to the actor.
  */
  static void addForceAtPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor*);

  /** \brief Applies a force (or impulse, NxActor*) defined in the global coordinate frame, acting at a particular point in local coordinates, to the actor.
  */
  static void addForceAtLocalPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies a force (or impulse, NxActor*) defined in the actor local coordinate frame, acting at a particular point in global coordinates, to the actor.
  */
  static void addLocalForceAtPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies a force (or impulse, NxActor*) defined in the actor local coordinate frame, acting at a particular point in local coordinates, to the actor.
  */
  static void addLocalForceAtLocalPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies a force (or impulse, NxActor*) defined in the global coordinate frame to the actor.
  */
  static void addForce (const Vec3& force, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies a force (or impulse, NxActor*) defined in the actor local coordinate frame to the actor.
  */
  static void addLocalForce (const Vec3& force, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies an impulsive torque defined in the global coordinate frame to the actor.
  */
  static void addTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup, NxActor*);
  
  /** \brief Applies an impulsive torque defined in the actor local coordinate frame to the actor.
  */
  static void addLocalTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup, NxActor*);

  /** \brief Computes the velocity of a point given in world coordinates if it were attached to the actor and moving with it.
  */
  static Vec3 getPointVelocity (const Vec3& point, NxActor*) ;
  
  /** \brief Computes the velocity of a point given in body local coordinates as if it were attached to the actor and moving with it.
  */
  static Vec3 getLocalPointVelocity(const Vec3& point, NxActor*) ;

  /** \brief Returns true if this body and all the actors it is touching or is linked to with joints are sleeping.
  */
  static bool isGroupSleeping(NxActor*);

  /** \brief Returns true if this body is sleeping.
  */
  static bool isSleeping(NxActor*);
  
  /** \brief Returns the linear velocity below which an actor may go to sleep.
  */
  static Real getSleepLinearVelocity(NxActor*) ;

  /** \brief Sets the linear velocity below which an actor may go to sleep.
  */
  static void setSleepLinearVelocity(Real threshold, NxActor*);

  /** \brief Returns the angular velocity below which an actor may go to sleep.
  */
  static Real getSleepAngularVelocity(NxActor*);

  /** \brief Sets the angular velocity below which an actor may go to sleep.
  */
  static void setSleepAngularVelocity(Real threshold, NxActor*);
  
  /** \brief Returns the energy below which an actor may go to sleep.
  */
  static Real getSleepEnergyThreshold(NxActor*);
  
  /** \brief Sets the energy threshold below which an actor may go to sleep.
  */
  static void setSleepEnergyThreshold(Real threshold, NxActor*);
  
  /** \brief Wakes up the actor if it is sleeping.
  \default Real(20.0 * 0.02)
  */
  static void wakeUp(Real wakeCounterValue, NxActor*);
  
  /** \brief Forces the actor to sleep.
  */
  static void putToSleep(NxActor*);
  
                                                                                       

}; // class NxActorFunctions

} // namespace Functions
} // namespace NxOgre

#endif
