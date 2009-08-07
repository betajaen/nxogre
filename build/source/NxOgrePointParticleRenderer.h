/** File: NxOgrePointParticleRenderer.h
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

#ifndef NXOGRE_POINTPARTICLERENDERABLE_H
#define NXOGRE_POINTPARTICLERENDERABLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreParticleRenderer.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass PointParticleRenderer : public PointerClass<Classes::_PointParticleRenderer>, public ParticleRenderer
{
  
  public: // Functions
  
   /** \brief Text
   */
                                               PointParticleRenderer(Renderable*);
   
   /** \brief Text
   */
   virtual                                    ~PointParticleRenderer(void);
   
   /** \brief Text
   */
   void                                        draw(CircularBuffer<ActiveParticle>& particles);
   
   /** \brief Text
   */
   NxOgre::Enums::RenderableType       getRenderableType() const;
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
