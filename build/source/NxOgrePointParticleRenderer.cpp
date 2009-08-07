/** File: NxOgreParticleRenderer.cpp
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
#include "NxOgrePointParticleRenderer.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreParticle.h"
#include "NxOgreRenderable.h"
#include "NxOgreActiveParticle.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

PointParticleRenderer::PointParticleRenderer(Renderable* renderable) : ParticleRenderer(renderable)
{
}

PointParticleRenderer::~PointParticleRenderer(void)
{
}

void PointParticleRenderer::draw(CircularBuffer<ActiveParticle>& particles)
{
#if 0
 unsigned int particlesSize = particles.capacity();
 if (particlesSize == 0)
  return;

 mRenderable->begin();
 Vec3 p;

 for (unsigned int i=0;i < particlesSize;i++)
 {
  ActiveParticle& particle = particles.fetch();
  p = ::NxOgre::Functions::RigidBodyFunctions::getGlobalPosition(particle.mParticle->getNxActor());
  mRenderable->addVertex(p.x, p.y, p.z);
 }
 mRenderable->end();
#endif
}

NxOgre::Enums::RenderableType PointParticleRenderer::getRenderableType() const
{
 return NxOgre::Enums::RenderableType_ParticlePoints;
}


                                                                                       

} // namespace NxOgre_Namespace

                                                                                       
