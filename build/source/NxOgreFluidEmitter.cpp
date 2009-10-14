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
#include "NxOgreFluidEmitter.h"
#include "NxOgreFluidEmitterDescription.h"
#include "NxOgreFluid.h"
#include "NxOgreShape.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

FluidEmitter::FluidEmitter(const FluidEmitterDescription& description, Fluid* fluid)
: mFluid(fluid),
  mName(description.mName)
{
 mNameHash = Functions::StringHash(mName);
 NxFluidEmitterDesc ed;
 ed.dimensionX = description.mDimensionX;
 ed.dimensionY = description.mDimensionY;
 ed.flags = description.mFlags;
 ed.fluidVelocityMagnitude = description.mFluidSpeed;
 if (description.mFrameShape)
  ed.frameShape = description.mFrameShape->getAbstractShape();
 ed.maxParticles = description.mMaxParticles;
 ed.name = mName.c_str();
 ed.particleLifetime = description.mParticleLifetime;
 NxMat34 pose;
 pose.setRowMajor44(description.mPose.ptr());
 ed.relPose = pose;
 ed.repulsionCoefficient = description.mReplusionCoefficient;
 ed.shape = description.mShape;
 ed.type = description.mType;
 
 mFluidEmitter = mFluid->getFluid()->createEmitter(ed);
 if (mFluidEmitter == 0)
 { 
  StringStream ss;
  ss << "FluidEmitter was not created! \n";
//     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowError(ss.str());
  return;
 }

}

FluidEmitter::~FluidEmitter(void)
{
 if (mFluidEmitter && mFluid)
 {
  mFluid->getFluid()->releaseEmitter(*mFluidEmitter);
  mFluidEmitter = 0;
 }
}

String FluidEmitter::getName() const
{
 return mName;
}

StringHash FluidEmitter::getNameHash() const
{
 return mNameHash;
}

Fluid* FluidEmitter::getFluid()
{
 return mFluid;
}

void FluidEmitter::setGlobalPose(const Matrix44& pose)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(pose.ptr());
 mFluidEmitter->setGlobalPose(global_pose);
}

void FluidEmitter::setGlobalPosition(const Vec3& position)
{
 mFluidEmitter->setGlobalPosition(position.as<NxVec3>());
}

void FluidEmitter::setGlobalOrientation(const Quat& orientation)
{
}
#if 0
Matrix44 FluidEmitter::getGlobalPose() const;

Vec3 FluidEmitter::getGlobalPosition() const;

Quat FluidEmitter::getGlobalOrientation() const;

void FluidEmitter::setLocalPose(const Matrix44& pose);

void FluidEmitter::setLocalPosition(const Vec3& position);

void FluidEmitter::setLocalOrientation(const Quat& orientation);

Matrix44 FluidEmitter::getLocalPose() const;

Vec3 FluidEmitter::getLocalPosition() const;

Quat FluidEmitter::getLocalOrientation() const;

void FluidEmitter::setFrameShape(Shape* shape);

Shape* FluidEmitter::getFrameShape();

Real FluidEmitter::getDimensionX();

Real FluidEmitter::getDimensionY();

void FluidEmitter::setRandomPosition(Vec3 maxDisplacement);

Vec3 FluidEmitter::getRandomPosition() const;

void FluidEmitter::setRandomAngle(Radian maxAngle);

Radian FluidEmitter::getRandomAngle() const;

void FluidEmitter::setFluidSpeed(Real speed);

Real FluidEmitter::getFluidSpeed() const;

void FluidEmitter::setRate(Real rate);

Real FluidEmitter::getRate() const;

void FluidEmitter::setParticleLifetime(Real life);

Real FluidEmitter::getParticleLifetime() const;

void FluidEmitter::setRepulsionCoefficient(Real coefficient);

Real FluidEmitter::getRepulsionCoefficient() const;

void FluidEmitter::resetEmission(unsigned int maxParticles);

unsigned int FluidEmitter::getMaxParticles() const;

unsigned int FluidEmitter::getNbParticlesEmitted() const;

void FluidEmitter::setFlag(Enums::FluidEmitterFlags flag, bool value);

bool FluidEmitter::getFlag(Enums::FluidEmitterFlags) const;

bool FluidEmitter::isShape(Enums::FluidEmitterShape shape) const;

bool FluidEmitter::isType(Enums::FluidEmitterShape type) const;
#endif
                                                                                       

} // namespace NxOgre

                                                                                       
