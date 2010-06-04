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

                     

#ifndef NXOGRE_FLUIDEMITTERDESCRIPTION_H
#define NXOGRE_FLUIDEMITTERDESCRIPTION_H

                     

#include "NxOgreStable.h"

#if NxOgreHasFluids == 1

#include "NxOgreCommon.h"

                     

namespace NxOgre
{

                     

/*! class. FluidEmitterDescription
    desc.
        FluidEmitterDescription is a set of properties for a FluidEmitter to be like when created.
    
*/
class NxOgrePublicClass FluidEmitterDescription
{
  
  public: // Functions
  
  /*! constructor. FluidEmitterDescription constructor
      desc.
          Calls FluidEmitterDescription::reset.
  */
  FluidEmitterDescription();
  
  /*! function. reset
      desc.
           Resets everything to their default values, and pointers are set to NULL.
  */
  void  reset();
  
  /*! function. valid
      desc.
           Returns if the variables are in a valid range or not
  */
  bool  valid();
  
  /*! variable. mName
      desc.
           Optional name of the FluidEmitter
      default.
           BLANK_STRING
      type.
           String
  */
  String  mName;
  
  /*! variable. mPose
      desc.
          Global or Local pose (if has frame shape) of the FluidEmitter.
      default.
          Matrix44::IDENTITY
      type.
          Matrix44
  */
  Matrix44  mPose;
  
  /*! variable. mFrameShape
      desc.
           A shape for the emitter to be "attached" to.
      note.
           mPose is regarded as a local pose when a FrameShape exists.
      default.
           NULL (No FrameShape)
      type.
           Shape*
  */
  Shape*  mFrameShape;

  /*! variable. mType
      desc.
           The emitter's mode of  operation.
      default.
           Enums::FluidEmitterType
  */
  Enums::FluidEmitterType mType;

  /*! variable. mMaxParticles
      desc.
          Maximum number of particles which are emitted from this emitter.
      note.
          If set to 0, then the number of emitted particles is unrestricted.
      default.
          0
      type.
          unsiged int
  */
  unsigned int mMaxParticles;
  
  /*! variable. mShape
      desc.
           The emitter's shape.
      default.
           Enums::EmitterShape_Rectangular
      type.
           Enums::EmitterShape
  */
  Enums::FluidEmitterShape  mShape;
  
  /*! variable. mDimensionX
      desc.
          Radius of the shape in the X direction.
      default.
          0.25f;
      type.
          Real
  */
  Real  mDimensionX;
  
  /*! variable. mDimensionY
      desc.
          Radius of the shape in the Y direction.
      default.
          0.25f;
      type.
          Real
  */
  Real  mDimensionY;
  
  /*! variable. mRandomPosition
      desc.
           Random vector with values for each axis direction.
           
           * X, Y have to be positive and describe the maximum random particle displacement in each dimension.
           * Z value describes the randomization in emission direction. The emission direction is specified by the third orientation axis of mPose.
           
      default.
          Vec3::ZERO
      type.
          Vec3
  */
  Vec3 mRandomPosition;

  /*! variable. mRandomAngle
      desc.
          Random angle deviation from emission direction.
      default.
          0.0f
      type.
          Radian
  */
  Radian mRandomAngle;
  
  /*! variable. mFluidSpeed
      desc.
          The speed emitted by the fluid particles.
      default.
          1.0f
      type.
          Real
  */
  Real  mFluidSpeed;

  /*! variable. mRate
      desc.
          How many particles are emitted per second.
      note.
          This only applies if the mType is Enums::FluidEmitterType_FlowRate
      default.
          100.0f
      type
          Real
  */
  Real  mRate;

  /*! variable. mParticleLifetime
      desc.
          How long in seconds, a particle will live.
      note.
          If set to 0, it will live forever unless is collides with a drain.
      default.
          0.0f
  */
  Real mParticleLifetime;

  /*! variable. mRepulsionCoefficient
      desc.
          Defines a factor for the impulse transfer from attached emitter to body.
      note.
          This only applies if the mFlags has Enums::FluidEmitterFlags_ForceOnBody
      default.
          1.0f
      range.
          [0, inf)
      type.
          Real
  */
  Real mReplusionCoefficient;

  /** variable. mFlags
      desc.
          Combination of the Enums::FluidFlags using the @|@ (or) operator.
      default.
          FluidFlags_Enabled | FluidFlags_Visualisation | FluidFlags_AddBodyVelocity
      type.
          unsigned int
  */
  unsigned int mFlags;
  
}; // class FluidEmitterDescription

                     

} // namespace NxOgre

                     

#endif

#endif