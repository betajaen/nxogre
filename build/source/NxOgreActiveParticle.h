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



