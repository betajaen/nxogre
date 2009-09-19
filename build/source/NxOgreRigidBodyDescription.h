/** File: NxOgreRigidBodyDescription.h
    Created on: 7-Nov-08
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

#ifndef NXOGRE_RIGIDBODYDESCRIPTION_H
#define NXOGRE_RIGIDBODYDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass RigidBodyDescription
{
  public: // Functions
  
  /** \brief RigidBodyDescription constructor, all it does is call RigidBodyDescription::reset.
  */
                                               RigidBodyDescription(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                         reset(void);
  
  /** \brief Returns if the variables are in a valid range or not
  */
                        bool                   valid(void);
  
  /** \brief Disable the inbuilt file resource system. Useful when you want override the existing one, with your own.
      \default false
  */
  bool                                         mNoFileResourceSystem;
  
  /** \brief Optional name of the RigidBody
      \note  Apart from Actors (and probably derivations of), names are ignored.
  */
                        String           mName;
  
  /** \brief Type of RigidBody
      \default RigidBodyType_Dynamic
      \note Properties of the RigidBody may not be available for the type of RigidBody. e.x. Geometry RigidBodies
            do not have any mass or density.
  */
  Enums::RigidBodyType                         mType;
  
  /** \brief Actor flags, which is to be used with the or operator (|, |=).
      \see Enums::ActorFlags
      \default 0 (No Flags)
      \example
       <code>
        description.mActorFlags |= Enums::ActorFlags_DisableCollision;
        description.mActorFlags |= Enums::ActorFlags_ContactModification;
       </code>
  */
                        unsigned int           mActorFlags;
  
  /** \brief Body flags, which is to be used with the or operator (|, |=).
      \see Enums::ActorFlags
      \default Enums::BodyFlags_Visualisation
      \example
       <code>
        description.mBodyFlags |= Enums::BodyFlags_DisableGravity;
        description.mBodyFlags |= Enums::BodyFlags_FrozenRot;
       </code>
      \note  If your RigidBody is a Volume or StaticGeometry then these flags are ignored.
  */
                        unsigned int           mBodyFlags;
  
  /** \brief Contact report flags
      \see Enums::ContactPairFlags
      \default 0 (No Flags)
      \example
       <code>
        description.mContactReportFlags |= Enums::ContactPairFlags_StartTouch;
        description.mContactReportFlags |= Enums::ContactPairFlags_Forces;
       </code>
  */
                        unsigned int           mContactReportFlags;
  
  /** \brief Compartment.
      \default NULL
  */
                        Compartment*           mCompartment;
  
  /** \brief Density (mass calculated by volume).
      \default 0
      \note When setting Density the mass must be set to zero, and when the mass is set the density must be zero.
  */
                        Real                   mDensity;

  /** \brief DominanceGroup
      \default 0
  */
                        unsigned short         mDominanceGroup;

  /** \brief ActorGroup this Actor belongs to.
      \default 0
  */
                        unsigned short         mGroup;

  /** \brief Angular Damping.
      \default 0.05f;
  */
                        Real                   mAngularDamping;

  /** \brief The initial angular velocity of the actor.
      \default Vec3::ZERO
  */
                        Vec3                  mAngularVelocity;

  /** \brief CCD Motion Threshold.
      \default 0
  */
                        Real                   mCCDMotionThreshold;

  /** \brief The force threshold for contact reports.
      \default NxOgreRealMax
  */
                        Real                   mContactReportThreshold;

  /** \brief Force Field Material Index.
      \default 0
  */
                        unsigned short         mForceFieldMaterial;

  /** \brief The number of SDK managed worker threads used when running the simulation in parallel.
      \default 0
  */
                        unsigned int           mInternalThreadCount;

  /** \brief Linear Damping of the Actor
      \default 0.0f
  */
                        Real                   mLinearDamping;

  /** \brief Initial linear velocity of the actor
      \default Vec3::ZERO
  */
                        Vec3                  mLinearVelocity;

  /** \brief Mass of a non-dynamic RigidBody
      \default 1.0
      \note When setting Mass the Density must be set to zero, and when the Density is set the Mass must be zero.
  */
                       Real                    mMass;

  /** \brief Mass Local Pose of the body portion of the Actor
      \default matrix44_identity
  */
                       Matrix44                mMassLocalPose;

  /** \brief Diagonal mass space inertia tensor in bodies mass frame.
      \default Vec3::ZERO
  */
                       Vec3                   mMassSpaceInertia;

  /** \brief Maximum angular velocity of the Actor
      \default -1.0f (PhysX assumes this to be a maximum linear velocity)
  */
                       Real                    mMaxAngularVelocity;

  /** \brief Maximum angular velocity at which body can go to sleep.
      \default -1.0f (No maximum)
  */
                       Real                    mSleepAngularVelocity;

  /** \brief Damping factor for bodies that are about to sleep.
      \default 0
  */
                       Real                    mSleepDamping;

  /** \brief Threshold for the energy-based sleeping algorithm.
      \default 0.005
      \note Only used when the mBodyFlags.mEnergySleepTest flag is set.
  */
                       Real                    mSleepEnergyThreshold;

  /** \brief Maximum linear velocity at which body can go to sleep.
      \default -1.0f (No maximum)
  */
                       Real                    mSleepLinearVelocity;

  /** \brief Number of solver iterations performed when processing joint/contacts connected to this body.
      \default 4
  */
                       unsigned int            mSolverIterationCount;

  /** \brief The body's initial wake up counter.
      \default 0.02
  */
                       Real                    mWakeUpCounter;

  /** \brief Volume collision type if the RigidBody is a Volume.
      \default Enums::VolumeCollisionFlags_None
  */
                 Enums::VolumeCollisionType    mVolumeCollisionType;

}; // class RigidBodyDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
