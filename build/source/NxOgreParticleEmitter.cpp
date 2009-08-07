/** File: NxOgreEmitter.cpp
    Created on: 17-Feb-09
    Author: Robin Southern "betajaen"
    SVN: $Id$

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
#include "NxOgreParticleEmitter.h"
#include "NxOgreActiveParticle.h"
#include "NxOgreParticle.h"
#include "NxOgreParticleGroup.h"

#include "NxPhysicsSDK.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

ParticleEmitter::ParticleEmitter(ParticleGroup* particle_group)
: mParticleGroup(particle_group)
{
}

ParticleEmitter::~ParticleEmitter(void)
{
}

unsigned int ParticleEmitter::emit(unsigned int emit)
{
 unsigned int size = mParticleGroup->mActiveParticles.capacity();
 unsigned int less = emit;
 for (unsigned int i=0;i < size;i++)
 {
  if (less == 0)
   return 0;
  
  ActiveParticle& particle = mParticleGroup->mActiveParticles.fetch();
  if (particle.mParticle != NULL)
   continue;
  
  particle.mParticle = NxOgre_New(Particle)(mParticleGroup->mParticleShape, Matrix44_Zero, mParticleGroup);
  particle.mStatus = NxOgre::Enums::ParticleStatus_Active;
  particle.mAge = 0;
  particle.mEntropy = NxMath::rand(-0.1f, 0.1f);
  less--;
 }
 return less;
}

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       
