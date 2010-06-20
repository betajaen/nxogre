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

                                                                                       

#ifndef NXOGRE_FLUID_H
#define NXOGRE_FLUID_H

                                                                                       

#include "NxOgreStable.h"

#if NxOgreHasFluids == 1

#include "NxOgreCommon.h"
#include "NxOgreTimeListener.h"
#include "NxOgreFluidEmitter.h"
#include "NxOgreFluidEmitterDescription.h"
#include "NxOgrePhysXParticleData.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Fluid
    desc.
    The fluid class represents the main module for the particle based fluid simulation.
    SPH (Smoothed Particle Hydrodynamics) is used to animate the particles.
    
    There are two kinds of particle interaction forces which govern the behaviour of the fluid:
    
    *Pressure* 
      These forces result from particle densities higher than the "rest density" of the fluid. 
      The rest density is given by specifying the inter-particle distance at which the fluid is in its relaxed state.
      Particles which are closer than the rest spacing are pushed away from each other. =:
    *Viscosity*
      These forces act on neighboring particles depending on the difference of their velocities.
      Particles drag other particles with them which is used to simulate the viscous behaviour of the fluid. =:
    
    The fluid class manages a set of particles. Particles can be created in two ways:
    
    * Particles can be added by the user directly.
    * The user can add emitters to the fluid and configure the parameters of the emission. (See FluidEmitter)
    
    Particles can be removed in two ways as well:
    * The user can specify a lifetime for the particles.  When its lifetime expires, a particle is deleted.
    * Shapes can be configured to act as drains.  When a particle intersects with a drain, the particle is deleted. (See Enums::ShapeFlags)
    
    Particles collide with static and dynamic shapes. Particles are also affected by the scene gravity and a user force, 
    as well as global velocity damping.  In order to render a fluid, the user can supply the fluid instance with a 
    user buffer into which the particle state is written after each simuation step.

    For a good introduction to SPH fluid simulation,
    see http://graphics.ethz.ch/~mattmuel/publications/sca03.pdf

    see. FluidDescription
*/
class NxOgrePublicClass Fluid : public NonRigidBodyBasedAllocatable, public TimeListener
{
  
 public:
  
  NXOGRE_GC_FRIEND_NEW4
  NXOGRE_GC_FRIEND_DELETE
  
  typedef hashmap<FluidEmitter*>           FluidEmitters;
  typedef hashmap_iterator<FluidEmitter*>  FluidEmitterIterator;
  
  /*! function. getRenderable
      desc.
          Get the renderable of the Fluid.
      return.
          **Renderable** * -- The renderable pointer.
  */
  Renderable*  getRenderable();

  /*! function. getPhysXFluid
      desc.
          Get the pointer to the NxFluid instance.
      note.
          This NxFluid is owned by the Fluid class, do not delete or destroy the pointer.
      return.
          **NxFluid** * -- the NxFluid instance
      !physx
  */
  NxFluid*  getFluid();
  
  /*! function. advance
      desc.
          Causes the Fluid to call the renderable to redraw.
      note.
          This method is called by the TimeController and never should be called by the user - without a good reason.
      args.
          float __deltaTime__ -- Time passed.
          const Enums::Priority __priority__ -- Time priority of the fluid.
  */
  bool  advance(float deltaTime, const Enums::Priority& priority, const Enums::SceneFunction&);
  
  /*! function. createEmitter
      desc.
          Create a fluid emitter.
      args.
          const FluidEmitterDescription& __description__ -- Initial fluid emitter properties
      note.
          The Fluid emitter pointer is owned by the Fluid.
      return.
          **FluidEmitter** * -- The new emitter.
  */
  FluidEmitter*  createEmitter(const FluidEmitterDescription& description = FluidEmitterDescription());
  
  /*! function. destroyEmitter
      desc.
          Destroy a fluid emitter.
      args.
          FluidEmitter* __emitter__ -- The emitter to destroy
  */
  void  destroyEmitter(FluidEmitter* emitter);
  
  /*! function. getNbEmitters
      desc.
          Get the number of fluid emitters of this fluid.
      return.
          **unsigned int** -- The number of fluid emitters.
  */
  unsigned int  getNbEmitters() const;
  
  /** \brief
  */
  FluidEmitterIterator  getEmitters();
  
  /** \brief
  */
  unsigned int  addParticles(ParticleData&, bool appendIds = false);
  
  /** \brief
  */
  void  removeAllParticles();
  
  /** \brief
  */
  unsigned int getNbParticles() const;
  
//  /** \brief
//  */
//  ParticleData*  getParticleData();
  
  /** \brief
  */
  unsigned int  getNbReserveParticles() const;
  
  /** \brief
  */
  void  setNbReserveParticles(unsigned int);
  
  /** \brief
  */
  unsigned int  getCurrentParticleLimit() const;
  
  /** \brief
  */
  void  setCurrentParticleLimit(unsigned int);
  
  /** \brief
  */
  buffer<FluidPacket*>  getFluidPacketData() const;
  
  /** \brief
  */
  unsigned int  getSimulationMethod() const;
  
  /** \brief
  */ 
  void  setSimulationMethod(unsigned int simulationMethod);
  
  /** \brief
  */
  Real  getStiffness() const;
  
  /** \brief
  */
  void  setStiffness(Real stiffness);
  
  /** \brief
  */
  Real  getViscosity() const;
  
  /** \brief
  */
  void  setViscosity(Real viscosity);
  
  /** \brief
  */
  void  setSurfaceTension(Real surfaceTension);
  
  /** \brief
  */
  Real  getDamping() const;
  
  /** \brief
  */
  void  setDamping(Real damping);
  
  /** \brief
  */
  Real  getFadeInTime() const;
  
  /** \brief
  */
  void  setFadeInTime(Real fadeIn);
  
  /** \brief
  */
  Vec3  getExternalAcceleration() const;
  
  /** \brief
  */
  void  setExternalAcceleration(const Vec3& acceleration);
  
  /** \brief
  */
  SimplePlane  getProjectionPlane() const;
  
  /** \brief
  */
  void  setProjectionPlane(const SimplePlane&);
  
  /** \brief
  */
  unsigned int  getCollisionMethod() const;
  
  /** \brief
  */
  void  setCollisionMethod(unsigned int collisionMethod);
  
  /** \brief
  */
  Real  getRestitutionForStaticShapes() const;
  
  /** \brief
  */
  void  setRestitutionForStaticShapes(Real restitution);
  
  /** \brief
  */
  Real  getDynamicFrictionForStaticShapes() const;
  
  /** \brief
  */
  void  setDynamicFrictionForStaticShapes(Real friction);
  
  /** \brief
  */
  Real  getStaticFrictionForStaticShapes() const;
  
  /** \brief
  */
  void  setStaticFrictionForStaticShapes(Real friction);
  
  /** \brief
  */
  Real  getAttractionForStaticShapes() const;
  
  /** \brief
  */
  void  setAttractionForStaticShapes(Real attraction);
  
  /** \brief 
  */
  Real  getRestitutionForDynamicShapes() const;
  
  /** \brief
  */
  void  setRestitutionForDynamicShapes(Real restitution);
  
  /** \brief
  */
  Real  getDynamicFrictionForDynamicShapes() const;
  
  /** \brief
  */
  void  setDynamicFrictionForDynamicShapes(Real friction);
  
  /** \brief
  */
  Real  getStaticFrictionForDynamicShapes() const;
  
  /** \brief
  */
  void  setStaticFrictionForDynamicShapes(Real friction);
  
  /** \brief
  */
  Real  getAttractionForDynamicShapes() const;
  
  /** \brief
  */
  void  setAttractionForDynamicShapes(Real attraction);
  
  /** \brief
  */
  void  setCollisionResponseCoefficient(Real coefficient);
  
  /** \brief
  */
  Real  getCollisionResponseCoefficient() const;
  
  /** \brief
  */
  void  setFlag(Enums::FluidFlags, bool value);
  
  /** \brief
  */
  bool  getFlag(Enums::FluidFlags) const;
  
  /** \brief
  */
  Scene*  getScene();
  
  /** \brief
  */
  unsigned int  getMaxParticles() const;
  
  /** \brief
  */
  Real  getKernelRadiusMultiplier() const;
  
  /** \brief
  */
  Real  getMotionLimitMultiplier() const;
  
  /** \brief
  */
  Real  getCollisionDistanceMultiplier() const;
  
  /** \brief
  */
  unsigned int  getPacketSizeMultiplier() const;
  
  /** \brief
  */
  Real  getRestParticlesPerMetre() const;
  
  /** \brief
  */
  Real  getRestDensity() const;
  
  /** \brief
  */
  Real  getRestParticleDistance() const;
  
  /** \brief
  */
  Real  getParticleMass() const;
  
  /** \brief
  */
  void  setGroup(GroupIdentifier collisionGroup);
  
  /** \brief
  */
  GroupIdentifier  getGroup() const;
  
  /** \brief
  */
  void  setGroupsMask(const int4& mask);
  
  /** \brief
  */
  int4  getGroupsMask() const;
  
  /** \brief
  */
  Bounds3  getWorldBounds() const;
  
  /** \brief
  */
  unsigned int  getPPUTime() const;
  
  /** \brief
  */
  void  setName(const String&);
  
  /** \brief
  */
  String  getName() const;
  
  /** \brief
  */
  StringHash getNameHash() const;
  
  /** \brief
  */
  Compartment*  getCompartment();
  
  /** \brief
  */
  MaterialIdentifier  getForceFieldMaterial() const;
  
  /** \brief
  */
  void  setForceFieldMaterial(MaterialIdentifier);
  
 protected: // functions
  
  /** \brief
  */
  Fluid(const FluidDescription&, Renderable*, Enums::Priority, Scene*);
  
  /** \brief
  */
 ~Fluid();
  
 protected: // variables
  
  /** \brief Scene that the fluid belongs to.
  */
  Scene*  mScene;
  
  /** \brief Actual fluid.
  */
  NxFluid*  mFluid;
  
  /** \brief
  */
  Renderable*  mRenderable;
  
  /** \brief Possible name of the mesh.
  */
  String  mName;
  
  /** \brief
  */
  StringHash mNameHash;

  /** \brief Current render priority.
  */
  Enums::Priority  mPriority;
  
  /** \brief Current emitters of this fluid. 
  */
  FluidEmitters  mFluidEmitters;
  
  /** \brief
  */
  Compartment*  mCompartment;
  
  /** \brief
  */
  PhysXParticleData* mParticleData;
  
}; // class Fluid

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
#endif