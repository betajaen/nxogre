/** File: NxOgreActiveParticle.h
    Created on: 20-Feb-09
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

#ifndef NXOGRE_ACTIVEPARTICLE_H
#define NXOGRE_ACTIVEPARTICLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief An Active particle, is a particle that is not resting in the scene.
*/
struct NxOgrePublicClass ActiveParticle
{
  
  /** \brief Default and only constructor. Sets the particle to null and to an inactive state.
  */
  ActiveParticle() : mParticle(0), mStatus(NxOgre::Enums::ParticleStatus_Inactive)
  {
  }
  
  /** \brief Current particle/rigid body assigned to this activeparticle, or NULL.
  */
           Particle*                          mParticle;
  
  /** \brief Current status of this particle
  */
           NxOgre::Enums::ParticleStatus      mStatus;
  
  /** \brief Age in seconds.
  */
           Real                               mAge;
  
  /** \brief Entropy
  */
           Real                               mEntropy;
  
}; // class ActiveParticle

                                                                                       

} // namespace NxOgre

                                                                                       

#endif



