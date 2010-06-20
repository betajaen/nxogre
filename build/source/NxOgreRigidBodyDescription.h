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

#include "NxOgreRigidbodyFlags.h"
#include "NxOgreDynamicRigidbodyFlags.h"


                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. RigidBodyDescription
    desc.
      Description to describe a RigidBody and it's inherited classes.
    properties.
      String mName -- Name of the RigidBody. This is optional and may be ignored with some inherited RigidBodies (optional). default: mName.clear()
      RigidbodyFlags mRigidbodyFlags -- Rigidbody flags. (See RigidbodyFlags) Enums: mRigidbodyFlags.reset();
      DynamicRigidbodyFlags mDynamicRigidbodyFlags --  Flags for dynamic rigidbodies (Actors/KinematicBodies). default: mDynamicRigidbodyFlags.reset();
      unsigned int mContactReportFlags -- Flags for contact reporting see (Enums::ContactPairFlags). default: 0
      Compartment* mCompartment -- Compartment to use. default: NULL
      Real mDensity -- Density (mass/shape volume). When set to zero, mMass is used. default: 0
      GroupIdentifier mDominanceGroup -- Dominance group index to be assigned to. default: 0
      GroupIdentifier mGroup -- Group index to be assigned to. default: 0
      Real mAngularDamping -- Damping for angular motion. default: 0.05
      Vec3 mAngularVelocity -- Initial angular velocity. default: mAngularVelocity.zero()
      Real mCCDMotionThreshold -- CCD Motion Threshold. default: 0
      Real mContactReportThreshold -- Force threshold for contact reports. default: NxOgreRealMax
      MaterialIdentifier mForceFieldMaterial -- Force Field Material Index. default: 0
      unsigned int mInternalThreadCount -- The number of SDK managed worker threads used when running the simulation is in parallel. default: 0
      Real mLinearDamping -- Damping for linear motion. default: 0.0
      Vec3 mLinearVelocity -- Initial linear velocity. default: mLinearVelocity.zero()
      Real mMass -- Mass of a non-dynamic RigidBody. When set to zero, mDensity is used. default: 1.0
      Matrix44 mMassLocalPose -- Mass Local Pose of the body portion of the Actor. default: mMassLocalPose.identity()
      Vec3 mMassSpaceInertia -- Diagonal mass space inertia tensor in bodies mass frame. default: mMassSpaceInertia.zero()
      Real mMaxAngularVelocity -- Maximum angular velocity of the Actor. When set to -1.0 it has none. default: -1.0
      Real mSleepAngularVelocity -- Maximum angular velocity at which body can go to sleep. When set to -1.0 it has none. default: -1.0
      Real mSleepDamping -- Damping factor for bodies that are about to sleep. default: 0
      Real mSleepEnergyThreshold -- Threshold for the energy-based sleeping algorithm. Only if flags has Enums::BodyFlags_EnergySleepTest. default: -1.0
      Real mSleepLinearVelocity -- Maximum linear velocity at which body can go to sleep. When set to -1.0 it has none. default: -1.0
      unsigned int mSolverIterationCount -- Number of solver iterations performed when processing joint/contacts connected to this body. default: 4
      Real mWakeUpCounter -- The body's initial wake up counter. default: 0.04
      bool mAuxiliaryMirror -- Mirror this RigidBody (Actors and KinematicActors) to AuxiliaryScenes. default: false
    validations.
      mDensity cannot be negative and/or mass cannot non-zero -- (mDensity < 0.0) || (mDensity > 0.0 && mMass > 0.0)
      mMass cannot be negative and/or density cannot non-zero -- (mMass < 0.0) || (mMass > 0.0 && mDensity > 0.0)
      mWakeUpCounter cannot be negative -- (mWakeUpCounter < 0.0)
      mLinearDamping cannot be negative -- (mLinearDamping < 0.0)
      mAngularDamping cannot be negative -- (mAngularDamping < 0.0)
      mCCDMotionThreshold cannot be negative -- (mCCDMotionThreshold < 0.0)
      mSolverIterationCount cannot be less than 1 or more than 255 -- (mSolverIterationCount < 1) || (mSolverIterationCount > 255)
      mContactReportThreshold cannot be negative -- (mContactReportThreshold < 0.0)
    namespace. NxOgre
*/
class NxOgrePublicClass RigidBodyDescription
{
  public: // Functions
  
  /*! constructor. BoxDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  RigidBodyDescription();

  /*! function. to_nxactor
      desc.
          Assigns the values of this RigidBodyDescription to an NxActorDesc, that related to all RigidBodies.
  */
  void to_nxactor(NxActorDesc*) const;

  /*! function. to_nxbody
      desc.
          Assigns the values of this RigidBodyDescription to an NxBodyDesc, that related to dynamic RigidBodies.
  */
  void to_nxactor(NxActorDesc*, NxBodyDesc*) const;

  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:

  /*! variable. mAngularDamping
      desc.
          Damping for angular motion.
      default.
          0.05
      condition.
          mAngularDamping cannot be negative
  */
  Real mAngularDamping;

  /*! variable. mAngularVelocity
      desc.
          Initial angular velocity.
      default.
          mAngularVelocity.zero()
  */
  Vec3 mAngularVelocity;

  /*! variable. mAuxiliaryMirror
      desc.
          Mirror this RigidBody (Actors and KinematicActors) to AuxiliaryScenes.
      default.
          false
  */
  bool mAuxiliaryMirror;

  /*! variable. mCCDMotionThreshold
      desc.
          CCD Motion Threshold.
      default.
          0
      condition.
          mCCDMotionThreshold cannot be negative
  */
  Real mCCDMotionThreshold;

  /*! variable. mCompartment
      desc.
          Compartment to use.
      default.
          NULL
  */
  Compartment* mCompartment;

  /*! variable. mContactReportFlags
      desc.
          Flags for contact reporting see (Enums::ContactPairFlags).
      default.
          0
  */
  unsigned int mContactReportFlags;

  /*! variable. mContactReportThreshold
      desc.
          Force threshold for contact reports.
      default.
          NxOgreRealMax
      condition.
          mContactReportThreshold cannot be negative
  */
  Real mContactReportThreshold;

  /*! variable. mDensity
      desc.
          Density (mass/shape volume). When set to zero, mMass is used.
      default.
          0
      condition.
          mDensity cannot be negative and/or mass cannot non-zero
  */
  Real mDensity;

  /*! variable. mDominanceGroup
      desc.
          Dominance group index to be assigned to.
      default.
          0
  */
  GroupIdentifier mDominanceGroup;

  /*! variable. mDynamicRigidbodyFlags
      desc.
          Flags for dynamic rigidbodies (Actors/KinematicBodies).
      default.
          mDynamicRigidbodyFlags.reset();
  */
  DynamicRigidbodyFlags mDynamicRigidbodyFlags;

  /*! variable. mForceFieldMaterial
      desc.
          Force Field Material Index.
      default.
          0
  */
  MaterialIdentifier mForceFieldMaterial;

  /*! variable. mGroup
      desc.
          Group index to be assigned to.
      default.
          0
  */
  GroupIdentifier mGroup;

  /*! variable. mInternalThreadCount
      desc.
          The number of SDK managed worker threads used when running the simulation is in parallel.
      default.
          0
  */
  unsigned int mInternalThreadCount;

  /*! variable. mLinearDamping
      desc.
          Damping for linear motion.
      default.
          0.0
      condition.
          mLinearDamping cannot be negative
  */
  Real mLinearDamping;

  /*! variable. mLinearVelocity
      desc.
          Initial linear velocity.
      default.
          mLinearVelocity.zero()
  */
  Vec3 mLinearVelocity;

  /*! variable. mMass
      desc.
          Mass of a non-dynamic RigidBody. When set to zero, mDensity is used.
      default.
          1.0
      condition.
          mMass cannot be negative and/or density cannot non-zero
  */
  Real mMass;

  /*! variable. mMassLocalPose
      desc.
          Mass Local Pose of the body portion of the Actor.
      default.
          mMassLocalPose.identity()
  */
  Matrix44 mMassLocalPose;

  /*! variable. mMassSpaceInertia
      desc.
          Diagonal mass space inertia tensor in bodies mass frame.
      default.
          mMassSpaceInertia.zero()
  */
  Vec3 mMassSpaceInertia;

  /*! variable. mMaxAngularVelocity
      desc.
          Maximum angular velocity of the Actor. When set to -1.0 it has none.
      default.
          -1.0
  */
  Real mMaxAngularVelocity;

  /*! variable. mName
      desc.
          Name of the RigidBody. This is optional and may be ignored with some inherited RigidBodies (optional).
      default.
          mName.clear()
  */
  String mName;

  /*! variable. mRigidbodyFlags
      desc.
          Rigidbody flags. (See RigidbodyFlags) Enums: mRigidbodyFlags.reset();
      default.
          
  */
  RigidbodyFlags mRigidbodyFlags;

  /*! variable. mSleepAngularVelocity
      desc.
          Maximum angular velocity at which body can go to sleep. When set to -1.0 it has none.
      default.
          -1.0
  */
  Real mSleepAngularVelocity;

  /*! variable. mSleepDamping
      desc.
          Damping factor for bodies that are about to sleep.
      default.
          0
  */
  Real mSleepDamping;

  /*! variable. mSleepEnergyThreshold
      desc.
          Threshold for the energy-based sleeping algorithm. Only if flags has Enums::BodyFlags_EnergySleepTest.
      default.
          -1.0
  */
  Real mSleepEnergyThreshold;

  /*! variable. mSleepLinearVelocity
      desc.
          Maximum linear velocity at which body can go to sleep. When set to -1.0 it has none.
      default.
          -1.0
  */
  Real mSleepLinearVelocity;

  /*! variable. mSolverIterationCount
      desc.
          Number of solver iterations performed when processing joint/contacts connected to this body.
      default.
          4
      condition.
          mSolverIterationCount cannot be less than 1 or more than 255
  */
  unsigned int mSolverIterationCount;

  /*! variable. mWakeUpCounter
      desc.
          The body's initial wake up counter.
      default.
          0.04
      condition.
          mWakeUpCounter cannot be negative
  */
  Real mWakeUpCounter;

  /*! constructor. RigidBodyDescription
      desc.
          Copy constructor for RigidBodyDescription
  */
  RigidBodyDescription(const RigidBodyDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  RigidBodyDescription& operator=(const RigidBodyDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this RigidBodyDescription as a pointer.
  */
  virtual RigidBodyDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of RigidBodyDescription into another.
  */
  virtual void copy_into(RigidBodyDescription*) const;

  /*! function. reset
      desc.
          Resets RigidBodyDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this RigidBodyDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "RigidBodyDescription-7008a292458be6d5a889be20d7ead6a2"

}; // class RigidBodyDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
