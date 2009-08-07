/** File: NxOgreParticleGroup.cpp
    Created on: 15-Feb-09
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
#include "NxOgreParticleGroup.h"
#include "NxOgreTimeController.h"
#include "NxOgreParticleRenderer.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

ParticleGroup::ParticleGroup(Scene* scene, ParticleRenderer* renderer, SimpleShape* particleShape, Real particleMass, NxOgre::Enums::Priority tl_priority)
: mScene(scene), mParticleRenderer(renderer), mParticleShape(particleShape), mParticleMass(particleMass)
{
 TimeController::getSingleton()->addTimeListener(this, tl_priority);
}

ParticleGroup::~ParticleGroup(void)
{
}

void ParticleGroup::addForces(Vec3 min, Vec3 max)
{
}

Scene* ParticleGroup::getScene()
{
 return mScene;
}

Real ParticleGroup::getParticleMass() const
{
 return mParticleMass;
}

ParticleRenderer* ParticleGroup::getParticleRenderer()
{
 return mParticleRenderer;
}

bool ParticleGroup::advance(float user_deltaTime, const Enums::Priority&)
{
 mParticleRenderer->draw(mActiveParticles);
 return true;
}

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       
