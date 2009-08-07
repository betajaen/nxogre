/** File: NxOgreParticle.h
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

#ifndef NXOGRE_PARTICLE_H
#define NXOGRE_PARTICLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreRigidBody.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Particle : public PointerClass<Classes::_Particle>, public RigidBody
{
  
  friend class Scene;
  friend class ParticleEmitter;
  friend class ParticleGroup;
  friend class Functions::ArrayFunctions<Particle*>::Write;
  
  public: // Functions
  
   using ::NxOgre::PointerClass<Classes::_Particle>::operator new;

   using ::NxOgre::PointerClass<Classes::_Particle>::operator delete;
  
   using ::NxOgre::PointerClass<Classes::_Particle>::getClassType;

  /** \brief Text
  */
  NxOgre::Enums::ParticleStatus               getStatus(void) const;
  
  /** \brief Text
  */
  void                                        setStatus(NxOgre::Enums::ParticleStatus);
  
  protected: // Functions
  
  /** \internal
  */
                                              Particle(SimpleShape* sharedShape, const Matrix44&, ParticleGroup*);
  
  /** \internal
  */
                                             ~Particle(void);
  
  protected: // Variables
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
