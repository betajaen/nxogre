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
                                               SoftBodyDescription();
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                         reset();
  
  /** \brief Returns if the variables are in a valid range or not
  */
                        bool                   valid();
  
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
