/** File: NxOgreActor.h
    Created on: 8-Nov-08
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

#ifndef NXOGRE_ACTOR_H
#define NXOGRE_ACTOR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreRigidBody.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Actor : public PointerClass<Classes::_Actor>, public RigidBody
{
  
  friend class Scene;
  friend class Functions::ArrayFunctions<Actor*>::Write;
  
  public:
  
  using ::NxOgre::PointerClass<Classes::_Actor>::operator new;

  using ::NxOgre::PointerClass<Classes::_Actor>::operator delete;

  using ::NxOgre::PointerClass<Classes::_Actor>::getClassType;

  /** \brief
  */
  virtual                             unsigned int           getClassType() const;

  /** \brief Assigns the actor to a user defined group of rigid bodies. 
  */
                                      void                   setGroup(GroupIdentifier actorGroup); 

  /** \brief Retrieves the value set with setGroup(). 
  */
                                      GroupIdentifier        getGroup(void) const;

  /** \brief Assigns dynamic actors a dominance group identifier. 
  */
                                      void                   setDominanceGroup(GroupIdentifier dominanceGroup); 
  
  /** \brief Retrieves the value set with setDominanceGroup(). 
  */
                                      GroupIdentifier        getDominanceGroup(void) const;
 
  /**  \brief Reset the user actor pair filtering state for this actor. This will cause filtering callbacks
       to be called again for any pairs involving this actor. Use this method when you wish to change
       the filtering policy of an actor that may already be in contact with other actors. 
  */
                                      void                   resetPairFiltering(void); 

  /** \brief Computes the total kinetic (rotational and translational) energy of the object.
  */
                                      Real                   computeKineticEnergy(void) const;

  /** \brief Sets the solver iteration count for the body. 
  */
                                      void                   setSolverIterationCount(unsigned int iterCount);

  /** \brief Retrieves the solver iteration count.
  */
                                      unsigned int           getSolverIterationCount(void) const; 

  /** \brief Retrieves the force threshold for contact reports. 
  */
                                      Real                   getContactReportThreshold(void) const;

  /** \brief Sets the force threshold for contact reports. 
  */
                                      void                   setContactReportThreshold(Real threshold);
  
  /** \brief Retrieves the actor's contact report flags. 
  */
                                      unsigned int           getContactReportFlags(void) const;
 
  /** \brief Sets the actor's contact report flags.
  */
                                      void                   setContactReportFlags(unsigned int flags);
   
  /// /** \brief Performs a linear sweep through space with the actor. 
  /// */
  ///                   NxU32                  linearSweep (const Vec3& motion, NxU32 flags, void *userData, NxU32 nbShapes, NxSweepQueryHit *shapes, NxUserEntityReport< NxSweepQueryHit > *callback, const NxSweepCache *sweepCache=NULL)=0 
 
  /// /** \brief  Retrieves the actor's simulation compartment, if any. 
  /// */
  ///                   NxCompartment*         getCompartment(void) const;
 
  /** \brief Retrieves the actor's force field material index, default index is 0. 
  */
                                      unsigned short         getForceFieldMaterial(void) const; 
 
  /** \brief Sets the actor's force field material index, default index is 0. 
  */
                                      void                   setForceFieldMaterial(unsigned short); 
  
  /** \brief Methods for setting a dynamic actor's pose in the world. 
  */
                                      void                   setGlobalPose(const Matrix44&);
 
  /** \brief Sets a dynamic actor's position in the world.
   */
                                      void                   setGlobalPosition (const Vec3&);
  
  /** \brief Sets a dynamic actor's orientation in the world.
  */
                                      void                   setGlobalOrientation(const Matrix33&);
 
  /** \brief Sets a dynamic actor's orientation in the world.
  */
                                      void                   setGlobalOrientationQuat(const Quat&);
 
  /** \brief Retrieves the actors world space transform.
  */
                                      Matrix44               getGlobalPose(void) const;

  /** \brief Retrieves the actors world space position.
  */
                                      Vec3                   getGlobalPosition(void) const;

  /** \brief Retrieves the actors world space orientation.
  */
                                      Matrix33               getGlobalOrientation(void) const;
  
  /** \brief Retrieves the actors world space orientation.
  */
                                      Quat                   getGlobalOrientationQuat(void) const;
  
  /** \brief Returns the number of shapes assigned to the actor.
  */
                                      unsigned int           getNbShapes(void) const;

  /** \brief The setCMassOffsetLocal*() methods set the pose of the center of mass relative to the actor.
  */
                                        void                 setCMassOffsetLocalPose(const Matrix44&);
  
  /** \brief The setCMassOffsetLocal*() methods set the pose of the center of mass relative to the actor.
  */
                                        void                 setCMassOffsetLocalPosition(const Vec3& );
  
  /** \brief The setCMassOffsetLocal*() methods set the pose of the center of mass relative to the actor.
  */
                                        void                 setCMassOffsetLocalOrientation(const Matrix33&);
  
  /** \brief The setCMassOffsetGlobal*() methods set the pose of the center of mass relative to world space.
  */
                                        void                 setCMassOffsetGlobalPose(const Matrix44&);
  
  /** \brief The setCMassOffsetGlobal*() methods set the pose of the center of mass relative to world space.
  */
                                        void                 setCMassOffsetGlobalPosition(const Vec3&); 

  /** \brief The setCMassOffsetGlobal*() methods set the pose of the center of mass relative to world space.
  */
                                        void                 setCMassOffsetGlobalOrientation(const Matrix33&);

  /** \brief The setCMassGlobal*() methods move the actor by setting the pose of the center of mass.
  */
                                        void                 setCMassGlobalPose(const Matrix44&);

  /** \brief The setCMassGlobal*() methods move the actor by setting the pose of the center of mass.
  */
                                        void                 setCMassGlobalPosition(const Vec3& );
  
  /** \brief The setCMassGlobal*() methods move the actor by setting the pose of the center of mass.
  */
                                        void                 setCMassGlobalOrientation (const Matrix33&);
  
  /** \brief The getCMassLocal*() methods retrieve the center of mass pose relative to the actor.
  */
                                        Matrix44             getCMassLocalPose(void) const; 
  
  /** \brief The getCMassLocal*() methods retrieve the center of mass pose relative to the actor.
  */
                                        Vec3                 getCMassLocalPosition(void) const;
  
  /** \brief The getCMassLocal*() methods retrieve the center of mass pose relative to the actor. 
  */
                                        Matrix33             getCMassLocalOrientation(void) const; 
  
  /** \brief The getCMassGlobal*() methods retrieve the center of mass pose in world space. 
  */
                                        Matrix44             getCMassGlobalPose(void) const; 
  
  /** \brief The getCMassGlobal*() methods retrieve the center of mass pose in world space. 
  */
                                        Vec3                 getCMassGlobalPosition(void) const;
  
  /** \brief The getCMassGlobal*() methods retrieve the center of mass pose in world space.
  */
                                        Matrix33             getCMassGlobalOrientation(void) const;
   
  /** \brief Sets the mass of a dynamic actor. 
  */
                                        void                 setMass(Real mass); 
  
  /** \brief Retrieves the mass of the actor. 
  */
                                        Real                 getMass(void) const; 
  
  /** \brief Sets the inertia tensor, using a parameter specified in mass space coordinates. 
  */
                                       void                  setMassSpaceInertiaTensor(const Vec3&); 
  
  /** \brief Retrieves the diagonal inertia tensor of the actor relative to the mass coordinate frame. 
  */
                                       Vec3                  getMassSpaceInertiaTensor(void) const; 
  
  /** \brief Retrieves the inertia tensor of the actor relative to the world coordinate frame.
  */
                                       Matrix33              getGlobalInertiaTensor(void) const; 
 
  /** \brief Retrieves the inverse of the inertia tensor of the actor relative to the world coordinate frame. 
  */
                                       Matrix33              getGlobalInertiaTensorInverse(void) const;
  
  /** \brief   Recomputes a dynamic actor's mass properties from its shapes. 
  */
                                       bool                  updateMassFromShapes(Real density, Real totalMass) const;

  /** \brief Sets the linear damping coefficient.
  */
                                       void                  setLinearDamping(Real linDamp);
   
  /** \brief Retrieves the linear damping coefficient.
  */
                                       Real                  getLinearDamping(void) const; 
  
  /** \brief Sets the angular damping coefficient.
  */
                                       void                  setAngularDamping(Real angDamp); 
   
  /** \brief Retrieves the angular damping coefficient.
  */
                                       Real                  getAngularDamping(void) const;

  /** \brief Sets the linear velocity of the actor.
  */
                                       void                  setLinearVelocity(const Vec3& );
  
  /** \brief Sets the angular velocity of the actor.
  */
                                       void                  setAngularVelocity(const Vec3& angVel);
  
  /** \brief Retrieves the linear velocity of an actor. 
  */
                                       Vec3                  getLinearVelocity(void) const;

  /** \brief Retrieves the angular velocity of the actor. 
  */
                                       Vec3                  getAngularVelocity (void) const;
  
  /** \brief Lets you set the maximum angular velocity permitted for this actor. 
  */
                                       void                  setMaxAngularVelocity(Real maxAngVel); 
  
  /** \brief Retrieves the maximum angular velocity permitted for this actor.
  */
                                       Real                  getMaxAngularVelocity(void) const;

  /** \brief Sets the CCD Motion Threshold. 
  */
                                       void                  setCCDMotionThreshold(Real thresh); 
  
  /** \brief Retrieves the CCD Motion threshold for this actor. 
  */
                                       Real                  getCCDMotionThreshold(void) const;

  /** \brief Sets the linear momentum of the actor.
  */
                                       void                  setLinearMomentum(const Vec3&  linMoment);
  
  /** \brief Sets the angular momentum of the actor.
  */
                                       void                  setAngularMomentum(const Vec3 &angMoment);
  
  /** \brief Retrieves the linear momentum of an actor.
  */
                                       Vec3                  getLinearMomentum(void) const; 
  
  /** \brief Retrieves the angular momentum of an actor.
  */
                                       Vec3                  getAngularMomentum(void) const;

  /** \brief Applies a force (or impulse) defined in the global coordinate frame, acting at a particular point in global coordinates, to the actor. 
  */
                                       void                  addForceAtPos (const Vec3&  force, const Vec3&  pos, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true); 

  /** \brief Applies a force (or impulse) defined in the global coordinate frame, acting at a particular point in local coordinates, to the actor. 
   */
                                       void                  addForceAtLocalPos(const Vec3&  force, const Vec3&  pos, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true); 
  
  /** \brief Applies a force (or impulse) defined in the actor local coordinate frame, acting at a particular point in global coordinates, to the actor.
  */
                                       void                  addLocalForceAtPos (const Vec3& force, const Vec3& pos, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies a force (or impulse) defined in the actor local coordinate frame, acting at a particular point in local coordinates, to the actor. 
  */
                                       void                  addLocalForceAtLocalPos (const Vec3& force, const Vec3& pos, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies a force (or impulse) defined in the global coordinate frame to the actor.
  */
                                       void                  addForce (const Vec3& force, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies a force (or impulse) defined in the actor local coordinate frame to the actor.
   */
                                       void                  addLocalForce (const Vec3& force, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies an impulsive torque defined in the global coordinate frame to the actor.
  */
                                       void                  addTorque (const Vec3& torque, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);
  
  /** \brief Applies an impulsive torque defined in the actor local coordinate frame to the actor.
  */
                                       void                  addLocalTorque (const Vec3& torque, NxOgre::Enums::ForceMode mode = NxOgre::Enums::ForceMode_Force, bool wakeup = true);

  /** \brief Computes the velocity of a point given in world coordinates if it were attached to the actor and moving with it. 
  */
                                       Vec3                  getPointVelocity (const Vec3&  point) const;
  
  /** \brief Computes the velocity of a point given in body local coordinates as if it were attached to the actor and moving with it.
  */
                                       Vec3                  getLocalPointVelocity(const Vec3&  point) const; 

  /** \brief Returns true if this body and all the actors it is touching or is linked to with joints are sleeping. 
  */
                                       bool                  isGroupSleeping(void) const;

  /** \brief Returns true if this body is sleeping. 
  */
                                       bool                  isSleeping(void) const;
  
  /** \brief Returns the linear velocity below which an actor may go to sleep. 
  */
                                       Real                  getSleepLinearVelocity(void) const;

  /** \brief Sets the linear velocity below which an actor may go to sleep. 
  */
                                       void                  setSleepLinearVelocity(Real threshold);

  /** \brief Returns the angular velocity below which an actor may go to sleep. 
  */
                                       Real                  getSleepAngularVelocity(void) const;

  /** \brief Sets the angular velocity below which an actor may go to sleep. 
  */
                                       void                  setSleepAngularVelocity(Real threshold); 
  
  /** \brief Returns the energy below which an actor may go to sleep. 
  */
                                       Real                  getSleepEnergyThreshold(void) const;
  
  /** \brief Sets the energy threshold below which an actor may go to sleep. 
  */
                                       void                  setSleepEnergyThreshold(Real threshold); 
  
  /** \brief Wakes up the actor if it is sleeping.
      \default Real(20.0 * 0.02)
  */
                                       void                  wakeUp(Real wakeCounterValue);
  
  /** \brief   Forces the actor to sleep. 
  */
                                       void                  putToSleep(void);

  protected: // Functions
  
  /** \internal Classes that inherit from Actor should use this constructor.
  */
                                              Actor(Scene*);
  
  /** \internal Use Scene::createActor
  */
                                              Actor(RigidBodyPrototype*, Scene*);
  
  /** \internal Use Scene::destroyActor
  */
  virtual                                    ~Actor(void);
  
  protected: // Variables
  
  /** \brief Name of the Actor, otherwise a blank string.
  */
                       String          mName;
  
  /** \brief Actor's parent Scene
  */
                       Scene*                mScene;
  
  /** \brief
  */
                       Shapes                mShapes;
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
