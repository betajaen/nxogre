/** File: NxOgreNodeRenderable.h
    Created on: 4-Apr-09
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

#ifndef NXOGRE_NODERENDERABLE_H
#define NXOGRE_NODERENDERABLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A Node Renderable is a position/orientation that is meant to be be used in a SceneGraph. NodeRenderables
           are RenderSystem specific.
*/
class NxOgrePublicClass NodeRenderable
{
  
  public: // Functions
  
  /** \brief Destructor
  */
  virtual                                    ~NodeRenderable(void);
  
  /** \brief Text
  */
  virtual void                                update(const Matrix44&);
  
}; // class NodeRenderable

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
