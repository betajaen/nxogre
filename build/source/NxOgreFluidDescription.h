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
                                                                                       

#ifndef NXOGRE_FLUIDDESCRIPTION_H
#define NXOGRE_FLUIDDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"

#if NxOgreHasFluids == 1

#include "NxOgreCommon.h"
#include "NxOgreParticleData.h"
#include "NxOgreSimple.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass FluidDescription
{
  
  public: // Functions
  
  /** \brief FluidDescription constructor, all it does is call RigidBodyDescription::reset.
  */
                                               FluidDescription();
  
  virtual                                     ~FluidDescription();

  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                         reset();
  
  /** \brief Returns if the variables are in a valid range or not
  */
  bool                                         valid();
  
  /** \brief
  */
  SharedPointer<ParticleData>                  mParticleData;
  
  /** \brief
  */  
  unsigned int                                 mMaxParticles;
  
  /** \brief
  */
  unsigned int                                 mNbReserveParticles;
  
  /** \brief
  */
  Real                                         mRestParticlesPerMetre;
  
  /** \brief
  */
  Real                                         mRestDensity;
  
  /** \brief
  */
  Real                                         mKernelRadiusMultiplier;
  
  /** \brief
  */
  Real                                         mMotionLimitMultiplier;
  
  /** \brief
  */
  Real                                         mCollisionDistanceMultiplier;
  
  /** \brief
  */
  unsigned int                                 mPacketSizeMultiplier;
  
  /** \brief
  */
  Real                                         mStiffness;
  
  /** \brief
  */
  Real                                         mViscosity;
  
  /** \brief
  */
  Real                                         mSurfaceTension;
  
  /** \brief
  */
  Real                                         mDamping;
  
  /** \brief
  */
  Real                                         mFadeInTime;
  
  /** \brief
  */
  Vec3                                         mExternalAcceleration;
  
  /** \brief
  */
  SimplePlane                                  mProjectionPlane;
  
  /** \brief
  */
  Real                                         mRestitutionForStaticShapes;
  
  /** \brief
  */
  Real                                         mDynamicFrictionForStaticShapes;
  
  /** \brief
  */
  Real                                         mStaticFrictionForStaticShapes;
  
  /** \brief
  */
  Real                                         mAttractionForStaticShapes;
  
  /** \brief
  */
  Real                                         mRestitutionForDynamicShapes;
  
  /** \brief
  */
  Real                                         mDynamicFrictionForDynamicShapes;
  
  /** \brief
  */
  Real                                         mStaticFrictionForDynamicShapes;
  
  /** \brief
  */
  Real                                         mAttractionForDynamicShapes;
  
  /** \brief
  */
  Real                                         mCollisionResponseCoefficient;
  
  /** \brief
  */
  unsigned int                                 mSimulationMethod;
  
  /** \brief
  */
  unsigned int                                 mCollisionMethod;
  
  /** \brief
  */
  GroupIdentifier                              mCollisionGroup;
  
  /** \brief
  */
  int4                                         mGroupsMask;
  
  /** \brief
  */
  MaterialIdentifier                           mForceFieldMaterial;
  
  /** \brief
  */
  unsigned int                                 mFlags;
  
  /** \brief Optional name.
  */
  String                                       mName;
  
  /** \brief
  */
  Compartment*                                 mCompartment;
  
}; // class FluidDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

#endif