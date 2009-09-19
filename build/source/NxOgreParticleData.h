/** File: NxOgreParticleData.h
    Created on: 11-Aug-09
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

#ifndef NXOGRE_PARTICLEDATA_H
#define NXOGRE_PARTICLEDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ParticleData
{
  
  public: // Functions
  
  /** \brief
  */
  ParticleData(unsigned int initialParticleCount = 1);
  
  /** \brief
  */
 ~ParticleData();
  
  /** \brief Number of particles.
      \note  Each buffer size must equal to this.
  */
  SharedPointer<unsigned int> mNbParticles;
  
  /** \brief
  */
  Buffer<Vec3>       mParticlePositions;
  
  /** \brief
  */
  Buffer<Vec3>       mParticleVelocities;
  
  /** \brief
  */
  Buffer<Vec3>       mParticleLifetimes;
    
  /** \brief
  */
  Buffer<Vec3>       mParticleDensities;
  
  /** \brief
  */
  Buffer<unsigned int>     mParticleIDs;
  
  /** \brief
  */
  Buffer<unsigned int>     mParticleFlags;
  
  /** \brief
  */
  Buffer<Vec3>       mParticleCollisionNormals;
  
}; // class ParticleData

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
