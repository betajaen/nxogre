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
#if NxOgreHasFluids == 1
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
 mNameHash = Strings::hash(mName);
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
 ed.rate = description.mRate;
 
 mFluidEmitter = mFluid->getFluid()->createEmitter(ed);
 if (mFluidEmitter == 0)
 { 
  StringStream ss;
  ss << "FluidEmitter was not created! \n";
//     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowException(DescriptionInvalidException, ss.str(), Classes::_FluidEmitter);
  return;
 }

}

FluidEmitter::~FluidEmitter()
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
 Matrix33 mat(orientation);
 NxMat33 matrix;
 matrix.setRowMajor(mat.ptr());
 mFluidEmitter->setGlobalOrientation(matrix);
}

Matrix44 FluidEmitter::getGlobalPose() const
{
 Matrix44 matrix;
 mFluidEmitter->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

Vec3 FluidEmitter::getGlobalPosition() const
{
 return Vec3(mFluidEmitter->getGlobalPosition());
}

Quat FluidEmitter::getGlobalOrientation() const
{
 NxMat33 matrix = mFluidEmitter->getGlobalOrientation();
 Matrix33 m(matrix(0,0),matrix(0,1),matrix(0,2), matrix(1,0),matrix(1,1),matrix(1,2),matrix(2,0),matrix(2,1),matrix(2,2));
 return Quat(m);
}

void FluidEmitter::setLocalPose(const Matrix44& pose)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(pose.ptr());
 mFluidEmitter->setLocalPose(global_pose);
}

void FluidEmitter::setLocalPosition(const Vec3& position)
{
 mFluidEmitter->setLocalPosition(position.as<NxVec3>());
}

void FluidEmitter::setLocalOrientation(const Quat& orientation)
{
 Matrix33 mat(orientation);
 NxMat33 matrix;
 matrix.setRowMajor(mat.ptr());
 mFluidEmitter->setLocalOrientation(matrix);
}

Matrix44 FluidEmitter::getLocalPose() const
{
 Matrix44 matrix;
 mFluidEmitter->getLocalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

Vec3 FluidEmitter::getLocalPosition() const
{
 return Vec3(mFluidEmitter->getLocalPosition());
}

Quat FluidEmitter::getLocalOrientation() const
{
 NxMat33 matrix = mFluidEmitter->getLocalOrientation();
 Matrix33 m(matrix(0,0),matrix(0,1),matrix(0,2), matrix(1,0),matrix(1,1),matrix(1,2),matrix(2,0),matrix(2,1),matrix(2,2));
 return Quat(m);
}

void FluidEmitter::setFrameShape(Shape* shape)
{
 if (shape == 0)
  mFluidEmitter->setFrameShape(0);
 else
  mFluidEmitter->setFrameShape(shape->getAbstractShape());
}

Shape* FluidEmitter::getFrameShape()
{
 NxShape* physx_shape = mFluidEmitter->getFrameShape();
 if (physx_shape == 0)
  return 0;
 return pointer_representive_cast<Shape>(physx_shape->userData);
}

Real FluidEmitter::getDimensionX()
{
 return mFluidEmitter->getDimensionX();
}

Real FluidEmitter::getDimensionY()
{
 return mFluidEmitter->getDimensionY();
}

void FluidEmitter::setRandomPosition(Vec3 maxDisplacement)
{
 mFluidEmitter->setRandomPos(maxDisplacement.as<NxVec3>());
}

Vec3 FluidEmitter::getRandomPosition() const
{
 return Vec3(mFluidEmitter->getRandomPos());
}

void FluidEmitter::setRandomAngle(Radian maxAngle)
{
 mFluidEmitter->setRandomAngle(maxAngle);
}

Radian FluidEmitter::getRandomAngle() const
{
 return mFluidEmitter->getRandomAngle();
}

void FluidEmitter::setFluidSpeed(Real speed)
{
 mFluidEmitter->setFluidVelocityMagnitude(speed);
}

Real FluidEmitter::getFluidSpeed() const
{
 return mFluidEmitter->getFluidVelocityMagnitude();
}

void FluidEmitter::setRate(Real rate)
{
 mFluidEmitter->setRate(rate);
}

Real FluidEmitter::getRate() const
{
 return mFluidEmitter->getRate();
}

void FluidEmitter::setParticleLifetime(Real life)
{
 mFluidEmitter->setParticleLifetime(life);
}

Real FluidEmitter::getParticleLifetime() const
{
 return mFluidEmitter->getParticleLifetime();
}

void FluidEmitter::setRepulsionCoefficient(Real coefficient)
{
 mFluidEmitter->setRepulsionCoefficient(coefficient);
}

Real FluidEmitter::getRepulsionCoefficient() const
{
 return mFluidEmitter->getRepulsionCoefficient();
}

void FluidEmitter::resetEmission(unsigned int maxParticles)
{
 mFluidEmitter->resetEmission(maxParticles);
}

unsigned int FluidEmitter::getMaxParticles() const
{
 return mFluidEmitter->getMaxParticles();
}

unsigned int FluidEmitter::getNbParticlesEmitted() const
{
 return mFluidEmitter->getNbParticlesEmitted();
}

void FluidEmitter::setFlag(Enums::FluidEmitterFlags flag, bool value)
{
 mFluidEmitter->setFlag(NxFluidEmitterFlag(int(flag)), value);
}

bool FluidEmitter::getFlag(Enums::FluidEmitterFlags flag) const
{
 return mFluidEmitter->getFlag(NxFluidEmitterFlag(int(flag)));
}

bool FluidEmitter::isShape(Enums::FluidEmitterShape shape) const
{
 return mFluidEmitter->getShape(NxEmitterShape((int) shape));
}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
