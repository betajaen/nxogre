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
#if NxOgreHasFluids == 1

                                                                                       

#ifndef NXOGRE_FLUIDEMITTER_H
#define NXOGRE_FLUIDEMITTER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


#include "NxOgreFluidEmitterDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. FluidEmitter
    desc.
        The fluid emitter class. It represents an emitter (fluid source) which is associated with one fluid.
        
        The emitter is an alternative to adding particles to the fluid via the NxFluid::addParticles() method.
        
        Emission always takes place in a plane given by the orientation and position of the emitter. The 
        shape of the area of emission is either a rectangle or an ellipse. The direction of emission is usually 
        perpendicular to the emission plane. However, this can be randomly modulated using the setRandomAngle() 
        method. An emitter can have two types of operation:
        
        *Constant pressure*
        In this case the state of the surrounding fluid is taken into account. The emitter tries 
        to match the rest spacing of the particles. Nice rays of water can be generated this way.
        *Constant flow rate*
        In this case the emitter keeps emitting the same number of particles each frame. The rate can 
        be adjusted dynamically.
        
        The emitter's pose can be animated directly or attached to a shape which belongs to a 
        dynamic actor. This shape is called the frame shape. When attaching an emitter to a shape, one 
        has the option of enabling impulse transfer from the emitter to the body of the shape. 
        The impulse generated is dependent on the rate, density, 
        and velocity of the emitted particles.
*/
class NxOgrePublicClass FluidEmitter : public NonRigidBodyBasedAllocatable
{
  
  NXOGRE_GC_FRIEND_NEW2
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  /*! function. getName
      desc.
          Get the name of the FluidEmitter
      return.
          **String** -- The name of the FluidEmitter.
  */
  String  getName() const;

  /*! function. getNameHash
      desc.
          Get the hash of the name of the FluidEmitter
      return.
          **StringHash** -- The hash of the name of the FluidEmitter.
  */
  StringHash  getNameHash() const;

  /*! function. getFluid
      desc.
          Get the fluid that this emitter is associciated with.
      return.
          **Fluid** * -- The fluid
  */
  Fluid*  getFluid();
  
  /*! function. setGlobalPose
      desc.
          Set the global pose of the emitter in world space.
      args.
          const Matrix44& __pose__ -- New emitter pose.
  */
  void  setGlobalPose(const Matrix44& pose);
  
  /*! function. setGlobalPosition
      desc.
          Set the global position of the emitter in world space.
      args.
          const Vec3& __position__ -- New position.
  */
  void  setGlobalPosition(const Vec3& position);
  
  /*! function. setGlobalOrientation
      desc.
          Set the global orientation of the emitter in world space.
      args.
          const Quat& __orientation__ -- New orientation.
  */
  void  setGlobalOrientation(const Quat& orientation);
  
  /*! function. getGlobalPose
      desc.
          Get the global pose of the emitter in world space.
      return.
          **Matrix44** -- Emitter pose.
  */
  Matrix44  getGlobalPose() const;
  
  /*! function. getGlobalPosition
      desc.
          Get the global position of the emitter in world space.
      args.
          **Vec3** -- Emitter position.
  */
  Vec3  getGlobalPosition() const;
  
  /*! function. getGlobalOrientation
      desc.
          Get the global orientation of the emitter in world space.
      args.
          **Quat** -- Emitter orientation.
  */
  Quat  getGlobalOrientation() const;
  
  /*! function. setLocalPose
      desc.
          Set the global pose of the emitter in local space of the shape frame.
      args.
          const Matrix44& __pose__ -- New emitter pose.
  */
  void  setLocalPose(const Matrix44& pose);
  
  /*! function. setLocalPosition
      desc.
          Set the global position of the emitter in local space of the shape frame.
      args.
          const Vec3& __position__ -- New position.
  */
  void  setLocalPosition(const Vec3& position);
  
  /*! function. setLocalOrientation
      desc.
          Set the global orientation of the emitter in local space of the shape frame.
      args.
          const Quat& __orientation__ -- New orientation.
  */
  void  setLocalOrientation(const Quat& orientation);
  
  /*! function. getLocalPose
      desc.
          Get the global pose of the emitter in local space of the shape frame.
      return.
          **Matrix44** -- Emitter pose.
  */
  Matrix44  getLocalPose() const;
  
  /*! function. getLocalPosition
      desc.
          Get the global position of the emitter in local space of the shape frame.
      args.
          **Vec3** -- Emitter position.
  */
  Vec3  getLocalPosition() const;
  
  /*! function. getLocalOrientation
      desc.
          Get the global orientation of the emitter in local space of the shape frame.
      args.
          **Quat** -- Emitter orientation.
  */
  Quat  getLocalOrientation() const;

  /*! function. setFrameShape
      desc.
          Set the frame shape, or to none.
      args.
          Shape* __shape__ -- Shape pointer or NULL for none.
  */
  void  setFrameShape(Shape* shape);

  /*! function. getFrameShape
      desc.
          Get the frame shape pointer, or a NULL pointer when it's none.
      return.
          **Shape** * -- Shape pointer or NULL for none.
  */
  Shape* getFrameShape();

  /*! function. getDimensionX
      desc.
           Returns the radius of the emitter along the x axis.
      return.
           **Real** -- Radius of the emitter along the x axis.
  */
  Real  getDimensionX();

  /*! function. getDimensionY
      desc.
           Returns the radius of the emitter along the y axis.
      return.
           **Real** -- Radius of the emitter along the y axis.
  */
  Real  getDimensionY();

  /*! function. setRandomPosition
      desc.
          Set the maximal random displacment of particles in every dimension of the emtiter
      args.
          Vec3 __maxDisplacement__ -- Maximal random particle displacement.
  */
  void  setRandomPosition(Vec3 maxDisplacement);
  
  /*! function. getRandomPosition
      desc.
          Get the maximal random displacment
      return.
          **Vec3** -- Maximal random displacment
  */
  Vec3  getRandomPosition() const;
  
  /*! function. setRandomAngle
      desc.
          Set the maximal random angle offset
      args.
          Radian __maxAngle__ -- Maximum random angle for emitted particles
  */
  void setRandomAngle(Radian maxAngle);
  
  /*! function. getRandomAngle
      desc.
          Get the maximal random angle displacment
      return.
          **Radian** -- Maximal angle random displacment
  */
  Radian  getRandomAngle() const;
  
  /*! function. setFluidSpeed
      desc.
          Set the velocity magnitude (speed) of the emitted particles.
      args.
          Real __speed__ -- Speed of the emitted particles.
  */
  void  setFluidSpeed(Real speed);
  
  /*! function. getFluidSpeed
      desc.
          Get the velocity magnitude (speed) of the emitted particles.
      return.
          **Real** -- Speed of the emitted particles.
  */
  Real  getFluidSpeed() const;
  
  /*! function. setRate
      desc.
          Set the emission rate of the particles measured in particles/second
      note.
          Only used if the Enums::EmitterType is EmitterType_ConstantFlowRate
      args.
          Real __rate__ -- New emission rate.
  */
  void  setRate(Real rate);
  
  /*! function. getRate
      desc.
          Get the emission rate of the particles measured in particles/second
      return.
          **Real** -- Current emission rate.
  */
  Real  getRate() const;
  
  /*! function. setParticleLifetime
      desc.
          Set the lifetime of the emitted particles
      args.
          Real __rate__ -- New lifetime.
  */
  void  setParticleLifetime(Real life);
  
  /*! function. getParticleLifetime
      desc.
          Get the lifetime of the emitted particles
      return.
          **Real** -- Current emitted particles
  */
  Real  getParticleLifetime() const;
  
  /*! function. setRepulsionCoefficient
      desc.
          Sets the repulsion coefficient.
      args.
          Real __coefficient__ -- New replusion coefficient; Range (0, inf).
  */
  void  setRepulsionCoefficient(Real coefficient);
  
  /*! function. getRepulsionCoefficient
      desc.
          Get the repulsion coefficient.
      return.
          **Real** -- Current repulsion coefficient.
  */
  Real  getRepulsionCoefficient() const;
  
  /*! function. resetEmission
      desc.
          Resets the particle reservoir.
      args.
          unsigned int __maxParticles__ -- New maximum particle
  */
  void  resetEmission(unsigned int maxParticles);
  
  /*! function. getMaxParticles
      desc.
          Returns the maximum number of particles to be emitted.
      return.
          **unsigned int** -- The maximum number of particles.
  */
  unsigned int  getMaxParticles() const;
  
  /*! function. getNbParticlesEmitted
      desc.
          Returns the number of particles emitted.
      return.
          **unsigned int** -- The number of particles emitted.
  */
  unsigned int  getNbParticlesEmitted() const;
  
  /*! function. setFlag
      desc.
           Set a fluid flag
      args.
           Enums::FluidEmitterFlag __flag__ -- Flag to set
           bool __value__ -- Flag value.
  */
  void  setFlag(Enums::FluidEmitterFlags flag, bool value);
  
  /*! function. getFlag
      desc.
          Get a flag value.
      args.
          Enums::FluidEmitterFlag __flag__ -- Flag to fetch.
      return.
          **bool** -- Flag value
  */
  bool  getFlag(Enums::FluidEmitterFlags) const;
  
  /*! function. getShape
      desc.
          Get the emitter shape.
      args.
          Enums::FluidEmitterShape __shape__ -- Shape emitter type
      return.
          **bool** -- True if it is that type of shape.
  */
  bool  isShape(Enums::FluidEmitterShape shape) const;
  
 protected:
  
  /*! constructor. FluidEmitter
      desc.
           Fluid Constructor, see Fluid::createEmitter
      args.
           const FluidEmitterDescription& __description__ -- Initial emitter properties
           Fluid* __fluid__ -- Parent fluid
  */
  FluidEmitter(const FluidEmitterDescription& description, Fluid* fluid);
  
  /*! destructor. FluidEmitter
      desc.
           Fluid Emitters are owned by the Fluid and will be destroyed by it.
  */
 ~FluidEmitter();
  
  protected:
  
  String mName;
  
  StringHash mNameHash;
  
  Fluid*                 mFluid;
  
  NxFluidEmitter*        mFluidEmitter;
  
}; // class Box

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
#endif
