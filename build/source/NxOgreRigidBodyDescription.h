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
  
  /** \brief Clone the properties of this into another RigidBodyDescription or a class derived from it.
  */
                        void                   clone(RigidBodyDescription& target) const;
  
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
  Vec3                    mMassSpaceInertia;

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

}; // class RigidBodyDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
