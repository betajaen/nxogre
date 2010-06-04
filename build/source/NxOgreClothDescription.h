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

                     

#ifndef NXOGRE_CLOTHDESCRIPTION_H
#define NXOGRE_CLOTHDESCRIPTION_H

                     

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                     

namespace NxOgre
{

                     

/*! class. ClothDescription
    
    Cloth description is a set of properties for a cloth to be like when created.
    
*/
class NxOgrePublicClass ClothDescription
{
  
  public: // Functions
  
  /*! constructor. ClothDescription constructor
      desc.
          Calls ClothDescription::reset.
  */
                         ClothDescription();
  
  /*! function. reset
      desc.
           Resets everything to their default values, and pointers are set to NULL.
  */
  void                   reset();
  
  /*! function. valid
      desc.
           Returns if the variables are in a valid range or not
  */
  bool                   valid();
  
  /*! variable. mName
      desc.
           Optional name of the Cloth
      default.
           BLANK_STRING
      type.
           String
  */
  String                 mName;
  
  /*! variable. mMesh
      desc.
           Mesh to be used by the cloth.
      type.
           Mesh*
  */
  Mesh*                  mMesh;
  
  /*! variable. mGlobalPose
      desc.
           Global pose of the cloth
      default.
           Matrix44::IDENTITY
      type.
           Matrix44
  */
  Matrix44               mGlobalPose;
  
  /*! variable. mThickness
      desc.
           Thickness of the cloth
      default.
           0.01
      type.
           Real
  */
  Real                   mThickness;
  
  /*! variable. mDensity
      desc.
           Density of the cloth
      default.
           1.0
      type.
           Real
  */
  Real                   mDensity;
  
  /*! variable. mBendingStiffness
      desc.
           Bending stiffness of the cloth
      default.
           1.0
      type.
           Real
      range.
           (0,1)
  */
  Real                   mBendingStiffness;
  
  /*! variable. mBendingStiffness
      desc.
           Stretching stiffness of the cloth
      default.
           1.0
      type.
           Real
      range.
           (0,1)
  */
  Real                   mStretchingStiffness;
  
  /*! variable. mDampingCoefficient
      desc.
           Damping coefficent
      default.
           0.5
      type.
           Real
      range.
           (0,1)
  */
  Real                   mDampingCoefficient;
  
  /*! variable. mFriction
      desc.
           Friction
      default.
           0.5
      type.
           Real
      range.
           (0,1)
  */
  Real                   mFriction;
  
  /** variable. mPressure
      desc.
           Pressure
      default.
           1.0
      type.
           Real
      range.
           (0,1)
  */
  Real                   mPressure;
  
  /*! variable. mTearFactor
      desc.
           Tear Factor
      default.
           1.0
      range.
           [0,inf)
      type.
           Real
  */
  Real                   mTearFactor;
  
  /*! variable. mCollisionResponseCoefficient
      desc.
           Defines a factor for the impulse transfer from cloth to colliding rigid bodies. 
      default.
           0.2
      range.
           [0,inf)
      type.
           Real
  */
  Real                   mCollisionResponseCoefficient;
  
  /*! variable. mAttachmentResponseCoefficient
      desc.
           Defines a factor for the impulse transfer from cloth to attached rigid bodies.
      default.
           0.2
      range.
           [0,1]
      type.
           Real
  */
  Real                   mAttachmentResponseCoefficient;
  
  /*! variable. mAttachmentTearFactor
      desc.
           If the flag Enums::ClothAttachmentTearable is set in the attachment method of NxCloth,
             this variable defines the elongation factor that causes the attachment to tear. 
      default.
           1.5
      range.
           (1,inf)
      type.
           Real
  */
  Real                   mAttachmentTearFactor;
  
  /*! variable. mToFluidResponseCoefficient
      desc.
           Defines a factor for the impulse transfer from this cloth to colliding fluids. 
      default.
           1.0
      range.
           [0,inf)
      type.
           Real
      note.
           Large values can cause instabilities
  */
  Real                   mToFluidResponseCoefficient;
  
  /*! variable. mFromFluidResponseCoefficient
      desc.
           Defines a factor for the impulse transfer from colliding fluids to this cloth.
      default.
           1.0
      range.
           [0,inf)
      type.
           Real
      note.
           Large values can cause instabilities
  */
  Real                   mFromFluidResponseCoefficient;
  
  /*! variable. mMinAdhereVelocity
      desc.
           If the  Enums::ClothAttachmentAdhere flag is set the cloth moves partially in the frame of the attached actor. 
           
           p. This feature is useful when the cloth is attached to a fast moving character.
           In that case the cloth adheres to the shape it is attached to while only 
           velocities below the parameter minAdhereVelocity are used for secondary effects.
           
      default.
           1.0
      range.
           [0,inf)
      type.
           Real
  */
  Real                   mMinAdhereVelocity;
  
  /*! variable. mSolverIterations
      desc.
           Number of solver iterations. 
           
      default.
           5
      range.
           [1,inf)
      type.
           unsigned int
      note.
           Small numbers make the simulation faster while the cloth gets less stiff.
  */
  unsigned int           mSolverIterations;
  
  /*! variable. mExternalAcceleration
      desc.
           External acceleration which affects all non attached particles of the cloth.
           
      default.
           Vec3::ZERO
      type.
           Vec3
  */
  Vec3                   mExternalAcceleration;
  
  /*! variable. mWindAcceleration
      desc.
           Acceleration which acts normal to the cloth surface at each vertex.
           
      default.
           Vec3::ZERO
      type.
           Vec3
  */
  Vec3                   mWindAcceleration;
  
  /*! variable. mWakeUpCounter
      desc.
           The cloth wake up counter.
      range.
           [0, inf)
      default.
           0.4
      type.
           Vec3
  */
  Real                   mWakeUpCounter;
  
  /*! variable. mWakeUpCounter
      desc.
           Maximum linear velocity at which cloth can go to sleep.
      range.
           [0, inf)
      default.
           0.4
      type.
           Vec3
  */
  Real                   mSleepLinearVelocity;
  
  /*! variable. mCollisionGroup
      desc.
           Which collision group this cloth is part of. 
      range.
           [0, 31]
      default.
           0
      type.
           GroupIdentifier
  */
  GroupIdentifier        mCollisionGroup;
  
  /*! variable. mGroupsMask
      desc.
           Which collision group this cloth is part of. 
      range.
           [0, 31]
      default.
           0
      type.
           GroupIdentifier
  */
  int4                   mGroupsMask;
  
  /*! variable. mForceFieldMaterial
      desc.
           Force Field Material Index.
      default.
           0
      type.
           GroupIdentifier
  */
  MaterialIdentifier     mForceFieldMaterial;
  
  /*! variable. mValidBounds
      desc.
           If the flag flag Enums::ClothFlags_HasBounds is set, this variable defines the volume
           outside of which cloth particle are automatically removed from the simulation. 
      default.
           Bounds3()
      type.
           Bounds3
  */
  Bounds3                mValidBounds;
  
  /*! variable. mRelativeGridSpacing
      desc.
           This parameter defines the size of grid cells for collision detection.
           
           The cloth is represented by a set of world aligned cubical cells in broad phase.
           The size of these cells is determined by multiplying the length of the diagonal
           of the AABB of the initial cloth size with this constant.
           
      default.
           0.25
      type.
           [0.01, inf)
  */
  Real                   mRelativeGridSpacing;
  
  /*! variable. mFlags
      desc.
           Flag bits.
      default.
           ClothFlags_Gravity
      type.
           unsigned int
      example.
        ClothDescription desc;
        desc.mFlags |= ClothFlags_Gravity;
        desc.mFlags |= ClothFlags_Tearable;
        // or
        ClothDescription desc;
        desc.mFlags = ClothFlags_Gravity | ClothFlags_Tearable;
  */
  unsigned int           mFlags;
  
  /*! variable. mCompartment
      desc.
          OptionalCompartment to place the cloth into.
      default.
          0 (No compartment)
      type.
          Compartment*
      note.
          Compartment must be a cloth compartment.
  */
  Compartment*  mCompartment;
  
}; // class ClothDescription

                     

} // namespace NxOgre

                     

#endif
