/** File: NxOgreXXX.h
    Created on: X-XXX-XX
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

#ifndef NXOGRE_PARTICLEGROUP_H
#define NXOGRE_PARTICLEGROUP_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreActiveParticle.h"
#include "NxOgreRestingParticle.h"
#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ParticleGroup : public PointerClass<Classes::_ParticleGroup>, public TimeListener
{
  
  friend class Scene;
  friend class ParticleEmitter;
  friend class ParticleDrain;
  friend class Functions::ArrayFunctions<ParticleGroup*>::Write;
  
  public: // Functions
  
  /** \brief Text
  */
  void                                        addForces(Vec3 min, Vec3 max);
  
  /** \brief Text
  */
  Scene*                                      getScene();
  
  /** \brief Text
  */
  Real                                        getParticleMass() const;
  
  /** \brief
  */
  ParticleRenderer*                           getParticleRenderer();
  
  /** \brief
  */
  bool                                        advance(float user_deltaTime, const Enums::Priority&);
  
  /** \brief
  */
  void                                        createParticle(const Matrix44&);
  
  /** \brief
  */
  ParticleEmitter*                            createEmitter(const Matrix44&, SimpleShape*);
  
  /** \brief
  */
  ParticleDrain*                              createDrain(const Matrix44&, SimpleShape*);
  
  /** \brief
  */
  void                                        destroyEmitter(ParticleEmitter*);
  
  /** \brief
  */
  void                                        destroyDrain(ParticleDrain*);
  
  /** \brief Set the number of cached resting particles.
  */
  void                                        setMaximumResting(unsigned int = 100);
  
  /** \brief Set the number of active particles.
  */
  void                                        setMaximumActive(unsigned int = 1000);
  
  /** \brief
  */
  void                                        pushForce(const Vec3&);
  
  /** \brief
  */
  void                                        popForce();
  
  /** \brief
  */
  void                                        clearForces();
  
  /** \brief
  */
  Array<Vec3>                                getForces();
  
  
  protected: // functions
  
  /** \internal Use Scene::createParticleGroup()
  */
                                              ParticleGroup(Scene*, ParticleRenderer*, SimpleShape* particleShape, Real particleMass = 0.0001f, NxOgre::Enums::Priority timeListenerPriority = NxOgre::Enums::Priority_Medium);
  
  /** \internal Use Scene::destroyParticleGroup()
  */
                                             ~ParticleGroup(void);
  
  protected: // Variables
  
  /** \brief Scene the Particlegroup is in.
  */
  Scene*                                      mScene;
  
  /** \brief Mass of all new particles.
  */
  Real                                        mParticleMass;
  
  /** \brief
  */
  ParticleRenderer*                           mParticleRenderer;
  
  /** \brief
  */
  SimpleShape*                                mParticleShape;
  
  /** \brief Sum of seperate forces multiplied by mass that applied to each particle per deltaTime
             <code>= (E_{1}^{n} Fn) * m</code>
  */
  Array<Vec3>                                mStackedForces;
  
  /** \brief Expired particles that still need to be rendered for a certain amount of time.
  */
  CircularBuffer<ActiveParticle>              mActiveParticles;
  
  /** \brief Expired particles that still need to be rendered for a certain amount of time.
  */
  CircularBuffer<RestingParticle>             mRestingParticles;
  
  /** \brief Size lock for particles array, any emitters will respect this, and re-use old particles.
  */
  unsigned int                                mMaximumActive;
  
  /** \brief Size lock for particles buffer, any emitters will respect this, and re-use old particles.
  */
  unsigned int                                mMaximumResting;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
