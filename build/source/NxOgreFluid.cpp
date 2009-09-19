/** File: NxOgreCloth.cpp
    Created on: 31-May-09
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreFluid.h"
#include "NxOgreFluidDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Fluid::Fluid(const FluidDescription& description, Renderable* renderable, Enums::Priority priority, Scene* scene)
: mName(description.mName),
  mScene(scene),
  mRenderable(renderable),
  mPriority(priority)
{
}

Fluid::~Fluid()
{
}

Renderable* Fluid::getRenderable()
{
 return mRenderable;
}

NxFluid* Fluid::getPhysXFluid()
{
 return mFluid;
}

bool Fluid::advance(float deltaTime, const Enums::Priority&)
{
 
 return true;
}

FluidEmitter* Fluid::createEmitter(const FluidEmitterDescription& desc)
{
 return 0; // temp.
}

void Fluid::destroyEmitter(FluidEmitter*)
{
}

unsigned int Fluid::getNbEmitters() const
{
 return mFluidEmitters.size();
}

ArrayIterator<FluidEmitter*> Fluid::getEmitters()
{
 return ArrayIterator<FluidEmitter*>(mFluidEmitters);
}

unsigned int Fluid::addParticles(ParticleData&, bool appendIds)
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

                                                                                       
