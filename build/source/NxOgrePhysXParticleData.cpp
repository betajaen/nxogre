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
#include "NxOgrePhysXParticleData.h"
#include "NxOgreFluid.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXParticleData::PhysXParticleData()
: mNbParticles(0)
{
}

PhysXParticleData::~PhysXParticleData(void)
{
 //NxOgre_Delete(mNbParticles);
 NxOgre_Unallocate(mNbParticles);
}

NxParticleData PhysXParticleData::getParticleData()
{
 
 NxParticleData data;
 
 data.bufferPos = mPositions.first();
 data.bufferPosByteStride = sizeof(float) * 3;
 
 data.bufferVel = mVelocities.first();
 data.bufferVelByteStride = sizeof(float) * 3;
 
 data.bufferLife = mLives.first();
 data.bufferLifeByteStride = sizeof(float);
 
 data.bufferDensity = mDensities.first();
 data.bufferDensityByteStride = sizeof(float);
 
 data.bufferId = mIds.first();
 data.bufferIdByteStride = sizeof(unsigned int);
 
 data.bufferFlag = mFlags.first();
 data.bufferFlagByteStride = sizeof(unsigned int);
 
 data.bufferCollisionNormal = mNormals.first();
 data.bufferCollisionNormalByteStride = sizeof(float) * 3;
 
 data.numParticlesPtr = mNbParticles;
 
 if (data.isValid() == false)
 { 
  StringStream ss;
  ss << "PhysX ParticleData ( Max " << mPositions.capacity() / 3 << " Particles ) will be not created! \n";
  
  ss << "Reason is:\n";
  
  if (data.numParticlesPtr && !(data.bufferPos || data.bufferVel || data.bufferLife || data.bufferDensity || data.bufferId || data.bufferCollisionNormal))
   ss << " - Has number of particles ptr but no buffers\n";
  
  if ((data.bufferPos || data.bufferVel || data.bufferLife || data.bufferDensity || data.bufferId || data.bufferCollisionNormal) && !data.numParticlesPtr)
   ss << " - Has buffers but no particles ptr\n";
  
  if (data.bufferPos && !data.bufferPosByteStride)
   ss << " - Has position buffer but no stride\n";

  if (data.bufferVel && !data.bufferVelByteStride)
   ss << " - Has velocities buffer but no stride\n";

  if (data.bufferLife && !data.bufferLifeByteStride)
   ss << " - Has lives buffer but no stride\n";

  if (data.bufferDensity && !data.bufferDensityByteStride)
   ss << " - Has density buffer but no stride\n";

  if (data.bufferId && !data.bufferIdByteStride)
   ss << " - Has ids buffer but no stride\n";

  if (data.bufferFlag && !data.bufferFlagByteStride)
   ss << " - Has flags buffer but no stride\n";

  if (data.bufferCollisionNormal && !data.bufferCollisionNormalByteStride)
   ss << " - Has normals buffer but no stride\n";

  NxOgre_ThrowError(ss.str());
  return data;
 }

 return data;
}

void PhysXParticleData::configure(size_t maxParticles, size_t modifier)
{
 
 size_t size = maxParticles * modifier;
 
 mDensities.reserve(size);
 mFlags.reserve(size);
 mLives.reserve(size);
 mPositions.reserve(size * 3);
 mVelocities.reserve(size * 3);
 mIds.reserve(size);
 
 if (mNbParticles == 0)
 {
  mNbParticles = (unsigned int*) NxOgre_Allocate(sizeof(unsigned int), ::NxOgre::Classes::_unsigned_int);
  (*mNbParticles) = 0;
 }
 
}

float* PhysXParticleData::getPositions()
{
 printf("Positions Cap: %i\n", mPositions.capacity() / 3);
 return mPositions.first();
}

float* PhysXParticleData::getVelocities()
{
 return mVelocities.first();
}

float* PhysXParticleData::getLives()
{
 return mLives.first();
}

float* PhysXParticleData::getDensities()
{
 return mDensities.first();
}

unsigned int* PhysXParticleData::getIds()
{
 return mIds.first();
}

unsigned int* PhysXParticleData::getFlags()
{
 return mFlags.first();
}

float* PhysXParticleData::getNormals()
{
 return mNormals.first();
}

unsigned int PhysXParticleData::getNbParticles() const
{
 return (*mNbParticles);
}

                                                                                       

} // namespace NxOgre

                                                                                       
