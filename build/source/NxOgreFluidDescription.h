/** File: NxOgreFluidDescription.h
    Created on: 11-Aug-09
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

#ifndef NXOGRE_FLUIDDESCRIPTION_H
#define NXOGRE_FLUIDDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
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
                                               FluidDescription(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                         reset(void);
  
  /** \brief Returns if the variables are in a valid range or not
  */
  bool                                         valid(void);
  
  /** \brief
  */
  ParticleData                                 mParticleData;
  
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
