/** File: NxOgreSoftBodyDescription.h
    Created on: 24-June-09
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

#ifndef NXOGRE_SOFTBODYDESCRIPTION_H
#define NXOGRE_SOFTBODYDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SoftBodyDescription
{
  
  public: // Functions
  
  /** \brief SoftBodyDescription constructor, all it does is call RigidBodyDescription::reset.
  */
                                               SoftBodyDescription(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                         reset(void);
  
  /** \brief Returns if the variables are in a valid range or not
  */
                        bool                   valid(void);
  
  /** \brief Optional name of the SoftBody
      \note  Apart from Actors (and probably derivations of), names are ignored.
  */
                        String                 mName;
  
  /** \brief Mesh to be used by the cloth.
  */
                        Mesh*                  mMesh;
  
  /** \brief Global pose of the cloth
  */
                        Matrix44               mGlobalPose;
  
  /** \brief Size of the particles used for collision detection. 
  */
                        Real                   mParticleRadius;
  
  /** \brief Density
  */
                        Real                   mDensity;
  
  /** \brief Bending stiffness of the cloth
      \range (0,1)
  */
                        Real                   mVolumeStiffness;
  
  /** \brief Bending stiffness of the cloth
      \range (0,1)
  */
                        Real                   mStretchingStiffness;
    
  /** \brief Damping coefficent
      \range (0,1)
  */
                        Real                   mDampingCoefficient;
    
  /** \brief Friction
      \range (0,1)
  */
                        Real                   mFriction;
      
  /** \brief Tear Factor
  */
                        Real                   mTearFactor;
  
  /** \brief Defines a factor for the impulse transfer from cloth to colliding rigid bodies. 
  */
                        Real                   mCollisionResponseCoefficient;
  
  /** \brief Defines a factor for the impulse transfer from cloth to attached rigid bodies. 
  */
                        Real                   mAttachmentResponseCoefficient;
  
  /** \brief If the flag Enums::ClothAttachmentTearable is set in the attachment method of NxCloth,
             this variable defines the elongation factor that causes the attachment to tear. 
  */
                        Real                   mAttachmentTearFactor;
  
  /** \brief Defines a factor for the impulse transfer from this cloth to colliding fluids. 
  */
                        Real                   mToFluidResponseCoefficient;
  
  /** \brief Defines a factor for the impulse transfer from colliding fluids to this cloth.
  */
                        Real                   mFromFluidResponseCoefficient;
  
  /** \brief If the  Enums::ClothAttachmentAdhere flag is set the cloth moves partially in the frame of the attached actor. 
  */
                        Real                   mMinAdhereVelocity;
  
  
  /** \brief Number of solver iterations.  
  */
                        unsigned int           mSolverIterations;
  
  /** \brief External acceleration which affects all non attached particles of the cloth. 
  */
                        Vec3                   mExternalAcceleration;
    
  /** \brief The cloth wake up counter.
  */
                        Real                   mWakeUpCounter;
    
  /** \brief Maximum linear velocity at which cloth can go to sleep.
  */
                        Real                   mSleepLinearVelocity;
  
  /** \brief Sets which collision group this cloth is part of. 
      \range (0,32)
  */
                        GroupIdentifier        mCollisionGroup;

  /** \brief Sets which collision group this cloth is part of. 
      \range (0,32)
  */
                        int4                   mGroupsMask;

  /** \brief Force Field Material Index, index != 0 has to be created.
  */
                        MaterialIdentifier     mForceFieldMaterial;

  /** \brief If the flag Enums::ClothFlags_HasBounds is set, this variable defines the volume outside of which cloth particle are automatically removed from the simulation. 
      \range (0,32)
  */
                        Bounds3                mValidBounds;
  
  /** \brief Cloth flags.
      \see NxOgre::Enums::ClothFlags
  */
                        unsigned int           mFlags;
  
}; // class SoftBodyDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
