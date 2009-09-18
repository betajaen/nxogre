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
#include "NxOgreCommon.h"
#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Fluid : public PointerClass<Classes::_Fluid>, public TimeListener
{
  
 public:
  
  
  /** \brief Get the renderable.
  */
  Renderable*                                 getRenderable();

  /** \internal
  */
  NxFluid*                                    getPhysXFluid();
  
 protected:
  
  /** \brief
  */
  Fluid(const FluidDescription&, Renderable*, Enums::Priority, Scene*);
  
  /** \brief
  */
 ~Fluid();
  
  /** \brief
  */
  bool                                          advance(float deltaTime, const Enums::Priority&);
  
  /** \brief
  */
  FluidEmitter*                                 createEmitter(const FluidEmitterDescription& desc);
  
  /** \brief
  */
  void                                          destroyEmitter(FluidEmitter*);
  
  /** \brief
  */
  unsigned int                                  getNbEmitters() const;
  
  /** \brief
  */
  ArrayIterator<FluidEmitter*>                  getEmitters();
  
  /** \brief
  */
  unsigned int                                  addParticles(ParticleData&, bool appendIds = false);
  
  /** \brief
  */
  void                                          removeAllParticles();
  
  /** \brief
  */
  ParticleData*                                 getParticleData();
  
  /** \brief
  */
  unsigned int                                  getNbReserveParticles() const;
  
  /** \brief
  */
  void                                          setNbReserveParticles(unsigned int);
  
  /** \brief
  */
  unsigned int                                  getCurrentParticleLimit() const;
  
  /** \brief
  */
  void                                          setCurrentParticleLimit(unsigned int);
  
  /** \brief
  */
  Buffer<FluidPacket*>                          getFluidPacketData() const;
  
  /** \brief
  */
  unsigned int                                  getSimulationMethod() const;
  
  /** \brief
  */ 
  void                                          setSimulationMethod(unsigned int simulationMethod);
  
  /** \brief
  */
  Real                                          getStiffness() const;
  
  /** \brief
  */
  void                                          setStiffness(Real stiffness);
  
  /** \brief
  */
  Real                                          getViscosity() const;
  
  /** \brief
  */
  void                                          setViscosity(Real viscosity);
  
  /** \brief
  */
  void                                          setSurfaceTension(Real surfaceTension);
  
  /** \brief
  */
  Real                                          getDamping() const;
  
  /** \brief
  */
  void                                          setDamping(Real damping);
  
  /** \brief
  */
  Real                                          getFadeInTime() const;
  
  /** \brief
  */
  void                                          setFadeInTime(Real fadeIn);
  
  /** \brief
  */
  Vec3                                          getExternalAcceleration() const;
  
  /** \brief
  */
  void                                          setExternalAcceleration(const Vec3& acceleration);
  
  /** \brief
  */
  SimplePlane                                   getProjectionPlane() const;
  
  /** \brief
  */
  void                                          setProjectionPlane(const SimplePlane&);
  
  /** \brief
  */
  unsigned int                                  getCollisionMethod() const;
  
  /** \brief
  */
  void                                          setCollisionMethod(unsigned int collisionMethod);
  
  /** \brief
  */
  Real                                          getRestitutionForStaticShapes() const;
  
  /** \brief
  */
  void                                          setRestitutionForStaticShapes(Real restitution);
  
  /** \brief
  */
  Real                                          getDynamicFrictionForStaticShapes() const;
  
  /** \brief
  */
  void                                          setDynamicFrictionForStaticShapes(Real friction);
  
  /** \brief
  */
  Real                                          getStaticFrictionForStaticShapes() const;
  
  /** \brief
  */
  void                                          setStaticFrictionForStaticShapes(Real friction);
  
  /** \brief
  */
  Real                                          getAttractionForStaticShapes() const;
  
  /** \brief
  */
  void                                          setAttractionForStaticShapes(Real attraction);
  
  /** \brief 
  */
  Real                                          getRestitutionForDynamicShapes() const;
  
  /** \brief
  */
  void                                          setRestitutionForDynamicShapes(Real restitution);
  
  /** \brief
  */
  Real                                          getDynamicFrictionForDynamicShapes() const;
  
  /** \brief
  */
  void                                          setDynamicFrictionForDynamicShapes(Real friction);
  
  /** \brief
  */
  Real                                          getStaticFrictionForDynamicShapes() const;
  
  /** \brief
  */
  void                                          setStaticFrictionForDynamicShapes(Real friction);
  
  /** \brief
  */
  Real                                          getAttractionForDynamicShapes() const;
  
  /** \brief
  */
  void                                          setAttractionForDynamicShapes(Real attraction);
  
  /** \brief
  */
  void                                          setCollisionResponseCoefficient(Real coefficient);
  
  /** \brief
  */
  Real                                          getCollisionResponseCoefficient() const;
  
  /** \brief
  */
  void                                          setFlag(Enums::FluidFlags, bool value);
  
  /** \brief
  */
  bool                                          getFlag(Enums::FluidFlags) const;
  
  /** \brief
  */
  Scene*                                        getScene();
  
  /** \brief
  */
  unsigned int                                  getMaxParticles() const;
  
  /** \brief
  */
  Real                                          getKernelRadiusMultiplier() const;
  
  /** \brief
  */
  Real                                          getMotionLimitMultiplier() const;
  
  /** \brief
  */
  Real                                          getCollisionDistanceMultiplier() const;
  
  /** \brief
  */
  unsigned int                                  getPacketSizeMultiplier() const;
  
  /** \brief
  */
  Real                                          getRestParticlesPerMetre() const;
  
  /** \brief
  */
  Real                                          getRestDensity() const;
  
  /** \brief
  */
  Real                                          getRestParticleDistance() const;
  
  /** \brief
  */
  Real                                          getParticleMass() const;
  
  /** \brief
  */
  void                                          setGroup(GroupIdentifier collisionGroup);
  
  /** \brief
  */
  GroupIdentifier                               getGroup() const;
  
  /** \brief
  */
  void                                          setGroupsMask(const int4& mask);
  
  /** \brief
  */
  int4                                          getGroupsMask() const;
  
  /** \brief
  */
  Bounds3                                       getWorldBounds() const;
  
  /** \brief
  */
  unsigned int                                  getPPUTime() const;
  
  /** \brief
  */
  void                                          setName(const String&);
  
  /** \brief
  */
  String                                        getName() const;
  
  /** \brief
  */
  Compartment*                                  getCompartment();
  
  /** \brief
  */
  MaterialIdentifier                            getForceFieldMaterial() const;
  
  /** \brief
  */
  void                                          setForceFieldMaterial(MaterialIdentifier);
  
  
 protected:
  
  /** \brief Scene that the fluid belongs to.
  */
  Scene*                                        mScene;
  
  /** \brief Actual fluid.
  */
  NxFluid*                                      mFluid;
  
  /** \brief
  */
  Renderable*                                   mRenderable;
  
  /** \brief Possible name of the mesh.
  */
  String                                        mName;
  
  /** \brief Current render priority.
  */
  Enums::Priority                               mPriority;
  
  /** \brief Current emitters of this fluid. 
  */
  Array<FluidEmitter*>                          mFluidEmitters;
  
  /** \brief
  */
  Compartment*                                  mCompartment;
  
}; // class Fluid

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
