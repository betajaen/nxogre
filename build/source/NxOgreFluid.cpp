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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreFluid.h"
#include "NxOgreFluidDescription.h"
#include "NxOgreCompartment.h"
#include "NxOgreScene.h"
#include "NxOgreRenderable.h"
#include "NxOgreTimeController.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Fluid::Fluid(const FluidDescription& description, Renderable* renderable, Enums::Priority priority, Scene* scene)
: mName(description.mName),
  mScene(scene),
  mRenderable(renderable),
  mPriority(priority)
{
 mNameHash = Strings::hash(mName);
 
 mParticleData = NXOGRE_NEW_NXOGRE(PhysXParticleData)();
 mParticleData->configure(description.mMaxParticles, 2);
 
 NxFluidDesc fd;
 fd.attractionForDynamicShapes = description.mAttractionForDynamicShapes;
 fd.attractionForStaticShapes  = description.mAttractionForStaticShapes;
 fd.collisionDistanceMultiplier = description.mCollisionDistanceMultiplier;
 fd.collisionGroup = description.mCollisionGroup;
 fd.collisionMethod = description.mCollisionMethod;
 fd.collisionResponseCoefficient = description.mCollisionResponseCoefficient;
 if (description.mCompartment)
  fd.compartment = description.mCompartment->getCompartment();
 fd.damping = description.mDamping;
 fd.dynamicFrictionForDynamicShapes = description.mDynamicFrictionForDynamicShapes;
 fd.dynamicFrictionForStaticShapes = description.mDynamicFrictionForStaticShapes;
 fd.externalAcceleration = description.mExternalAcceleration.as<NxVec3>();
 fd.fadeInTime = description.mFadeInTime;
 fd.flags = description.mFlags; 
 // fd.fluidPacketData = ...
 fd.forceFieldMaterial = description.mForceFieldMaterial;
 fd.groupsMask.bits0 = description.mGroupsMask.w;
 fd.groupsMask.bits1 = description.mGroupsMask.x;
 fd.groupsMask.bits2 = description.mGroupsMask.y;
 fd.groupsMask.bits3 = description.mGroupsMask.z;
 // fd.initialParticleData = ...
 fd.kernelRadiusMultiplier = description.mKernelRadiusMultiplier;
 fd.maxParticles = description.mMaxParticles;
 fd.motionLimitMultiplier = description.mMotionLimitMultiplier;
 fd.name = mName.c_str();
 fd.numReserveParticles = description.mNbReserveParticles;
 fd.packetSizeMultiplier = description.mPacketSizeMultiplier;
 //fd.particleCreationIdWriteData = ...
 //fd.particleDeletionIdWriteData = ...
 fd.particlesWriteData = mParticleData->getParticleData();
 //fd.projectionPlane = ...
 fd.restDensity = description.mRestDensity;
 fd.restitutionForDynamicShapes = description.mRestitutionForDynamicShapes;
 fd.restitutionForStaticShapes = description.mRestitutionForStaticShapes;
 fd.restParticlesPerMeter = description.mRestParticlesPerMetre;
 fd.simulationMethod = description.mSimulationMethod;
 fd.staticFrictionForDynamicShapes = description.mStaticFrictionForDynamicShapes;
 fd.staticFrictionForStaticShapes = description.mStaticFrictionForStaticShapes;
 fd.stiffness = description.mStiffness;
 fd.surfaceTension = description.mSurfaceTension;
 fd.viscosity = description.mViscosity;
 
 mFluid = mScene->getScene()->createFluid(fd);
 if (mFluid == 0)
 { 
  StringStream ss;
  ss << "Fluid was not created! \n";
//     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowException(IOException, ss.str(), Classes::_Fluid);
  return;
 }
 
 TimeController::getSingleton()->addTimeListener(this, mPriority);
}

Fluid::~Fluid()
{
 
 TimeController::getSingleton()->removeTimeListener(this, mPriority);
 
 if (mFluid)
 {
  mFluidEmitters.clear();
  mScene->getScene()->releaseFluid(*mFluid);
  mFluid = 0;
 }
 
 NXOGRE_DELETE_NXOGRE(mParticleData);
 
}

Renderable* Fluid::getRenderable()
{
 return mRenderable;
}

NxFluid* Fluid::getFluid()
{
 return mFluid;
}

bool Fluid::advance(float, const Enums::Priority&)
{
 if (mRenderable && mParticleData)
 {
  NxBounds3 bounds;
  mFluid->getWorldBounds(bounds);
  mRenderable->drawFluid(mParticleData, Bounds3::from(bounds));
 }
 return true;
}

FluidEmitter* Fluid::createEmitter(const FluidEmitterDescription& description)
{
 FluidEmitter* emitter = new FluidEmitter(description, this);
 mFluidEmitters.insert(emitter->getNameHash(), emitter);
 return emitter;
}

void Fluid::destroyEmitter(FluidEmitter*)
{
}

unsigned int Fluid::getNbEmitters() const
{
 return mFluidEmitters.size();
}

Fluid::FluidEmitterIterator Fluid::getEmitters()
{
 return FluidEmitterIterator(mFluidEmitters);
}

unsigned int Fluid::addParticles(ParticleData&, bool)
{
 return 0; // Temp.
}

void Fluid::removeAllParticles()
{
 mFluid->removeAllParticles();
}

ParticleData* Fluid::getParticleData()
{
 return 0; // Temp.
}

unsigned int Fluid::getNbReserveParticles() const
{
 return mFluid->getNumReserveParticles();
}

void Fluid::setNbReserveParticles(unsigned int particles)
{
 mFluid->setNumReserveParticles(particles);
}

unsigned int Fluid::getCurrentParticleLimit() const
{
 return mFluid->getCurrentParticleLimit();
}

void Fluid::setCurrentParticleLimit(unsigned int limit)
{
 mFluid->setCurrentParticleLimit(limit);
}

Buffer<FluidPacket*> Fluid::getFluidPacketData() const
{
 return Buffer<FluidPacket*>(); // Temp.
}

unsigned int Fluid::getSimulationMethod() const
{
 return mFluid->getSimulationMethod();
}

void Fluid::setSimulationMethod(unsigned int simulationMethod)
{
 mFluid->setSimulationMethod(simulationMethod);
}

Real Fluid::getStiffness() const
{
 return mFluid->getStiffness();
}

void Fluid::setStiffness(Real stiffness)
{
 mFluid->setStiffness(stiffness);
}

Real Fluid::getViscosity() const
{
 return mFluid->getViscosity();
}

void Fluid::setViscosity(Real viscosity)
{
 mFluid->setViscosity(viscosity);
}

void Fluid::setSurfaceTension(Real surfaceTension)
{
 mFluid->setSurfaceTension(surfaceTension);
}

Real Fluid::getDamping() const
{
 return mFluid->getDamping();
}

void Fluid::setDamping(Real damping)
{
 mFluid->setDamping(damping);
}

Real Fluid::getFadeInTime() const
{
 return mFluid->getFadeInTime();
}

void Fluid::setFadeInTime(Real fadeIn)
{
 mFluid->setFadeInTime(fadeIn);
}

Vec3 Fluid::getExternalAcceleration() const
{
 return Vec3(mFluid->getExternalAcceleration());
}

void Fluid::setExternalAcceleration(const Vec3& acceleration)
{
 mFluid->setExternalAcceleration(acceleration.as<NxVec3>());
}

SimplePlane Fluid::getProjectionPlane() const
{
 SimplePlane plane;
 NxPlane  nx_plane;
 mFluid->setProjectionPlane(nx_plane);
 plane.mNormal = nx_plane.normal;
 plane.mDistance = nx_plane.d;
 return plane;
}

void Fluid::setProjectionPlane(const SimplePlane& plane)
{
 NxPlane nx_plane;
 nx_plane.d = plane.mDistance;
 nx_plane.normal = plane.mNormal.as<NxVec3>();
 mFluid->setProjectionPlane(nx_plane);
}

unsigned int Fluid::getCollisionMethod() const
{
 return mFluid->getCollisionMethod();
}

void Fluid::setCollisionMethod(unsigned int collisionMethod)
{
 mFluid->setCollisionMethod(collisionMethod);
}

Real Fluid::getRestitutionForStaticShapes() const
{
 return mFluid->getRestitutionForStaticShapes();
}

void Fluid::setRestitutionForStaticShapes(Real restitution)
{
 mFluid->setRestitutionForStaticShapes(restitution);
}

Real Fluid::getDynamicFrictionForStaticShapes() const
{
 return mFluid->getDynamicFrictionForStaticShapes();
}

void Fluid::setDynamicFrictionForStaticShapes(Real friction)
{
 mFluid->setDynamicFrictionForStaticShapes(friction);
}

Real Fluid::getStaticFrictionForStaticShapes() const
{
 return mFluid->getStaticFrictionForStaticShapes();
}

void Fluid::setStaticFrictionForStaticShapes(Real friction)
{
 mFluid->setStaticFrictionForStaticShapes(friction);
}

Real Fluid::getAttractionForStaticShapes() const
{
 return mFluid->getAttractionForStaticShapes();
}

void Fluid::setAttractionForStaticShapes(Real attraction)
{
 mFluid->setAttractionForStaticShapes(attraction);
}

Real Fluid::getRestitutionForDynamicShapes() const
{
 return mFluid->getRestitutionForDynamicShapes();
}

void Fluid::setRestitutionForDynamicShapes(Real restitution)
{
 mFluid->setRestitutionForDynamicShapes(restitution);
}

Real Fluid::getDynamicFrictionForDynamicShapes() const
{
 return mFluid->getDynamicFrictionForDynamicShapes();
}

void Fluid::setDynamicFrictionForDynamicShapes(Real friction)
{
 mFluid->setDynamicFrictionForDynamicShapes(friction);
}

Real Fluid::getStaticFrictionForDynamicShapes() const
{
 return mFluid->getStaticFrictionForDynamicShapes();
}

void Fluid::setStaticFrictionForDynamicShapes(Real friction)
{
 mFluid->setStaticFrictionForDynamicShapes(friction);
}

Real Fluid::getAttractionForDynamicShapes() const
{
 return mFluid->getAttractionForDynamicShapes();
}

void Fluid::setAttractionForDynamicShapes(Real attraction)
{
 mFluid->setAttractionForDynamicShapes(attraction);
}

void Fluid::setCollisionResponseCoefficient(Real coefficient)
{
 mFluid->setCollisionResponseCoefficient(coefficient);
}

Real Fluid::getCollisionResponseCoefficient() const
{
 return mFluid->getCollisionResponseCoefficient();
}

void Fluid::setFlag(Enums::FluidFlags flags, bool value)
{
 mFluid->setFlag(NxFluidFlag(unsigned int(flags)), value);
}

bool Fluid::getFlag(Enums::FluidFlags flags) const
{
 return mFluid->getFlag(NxFluidFlag(unsigned int(flags)));
}

Scene* Fluid::getScene()
{
 return mScene;
}

unsigned int Fluid::getMaxParticles() const
{
 return mFluid->getMaxParticles();
}

Real Fluid::getKernelRadiusMultiplier() const
{
 return mFluid->getKernelRadiusMultiplier();
}

Real Fluid::getMotionLimitMultiplier() const
{
 return mFluid->getMotionLimitMultiplier();
}

Real Fluid::getCollisionDistanceMultiplier() const
{
 return mFluid->getCollisionDistanceMultiplier();
}

unsigned int Fluid::getPacketSizeMultiplier() const
{
 return mFluid->getPacketSizeMultiplier();
}

Real Fluid::getRestParticlesPerMetre() const
{
 return mFluid->getRestParticlesPerMeter();
}

Real Fluid::getRestDensity() const
{
 return mFluid->getRestDensity();
}

Real Fluid::getRestParticleDistance() const
{
 return mFluid->getRestParticleDistance();
}

Real Fluid::getParticleMass() const
{
 return mFluid->getParticleMass();
}

void Fluid::setGroup(GroupIdentifier collisionGroup)
{
 mFluid->setGroup(collisionGroup);
}

GroupIdentifier Fluid::getGroup() const
{
 return mFluid->getGroup();
}

void Fluid::setGroupsMask(const int4& mask)
{
 NxGroupsMask groups_mask;
 groups_mask.bits0 = mask.w;
 groups_mask.bits1 = mask.x;
 groups_mask.bits2 = mask.y;
 groups_mask.bits3 = mask.z;
 mFluid->setGroupsMask(groups_mask);
}

int4 Fluid::getGroupsMask() const
{
 NxGroupsMask groups_mask = mFluid->getGroupsMask();
 int4 mask;
 mask.w = groups_mask.bits0;
 mask.x = groups_mask.bits1;
 mask.y = groups_mask.bits2;
 mask.z = groups_mask.bits3;
 return mask;
}

Bounds3 Fluid::getWorldBounds() const
{
 NxBounds3 nx_bounds;
 mFluid->getWorldBounds(nx_bounds);
 return Bounds3().from(nx_bounds);
}

unsigned int Fluid::getPPUTime() const
{
 return mFluid->getPPUTime();
}

void Fluid::setName(const String& name)
{
 mName = name;
 mFluid->setName(mName.c_str());
}

String Fluid::getName() const
{
 return mName;
}

StringHash Fluid::getNameHash() const
{
 return mNameHash;
}

Compartment* Fluid::getCompartment()
{
 return mCompartment;
}

MaterialIdentifier Fluid::getForceFieldMaterial() const
{
 return mFluid->getForceFieldMaterial();
}

void Fluid::setForceFieldMaterial(MaterialIdentifier identifier)
{
 mFluid->setForceFieldMaterial(identifier);
}

                                                                                       

} // namespace NxOgre

                                                                                       
