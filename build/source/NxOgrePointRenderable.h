/** File: NxOgrePointRenderable.h
    Created on: 19-May-09
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

#ifndef NXOGRE_POINTRENDERABLE_H
#define NXOGRE_POINTRENDERABLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A point renderable is intended to represent a pre-load visual mesh in a SceneGraph or similar rendering API. Instead
           of giving full vertex and triangle information. A PointRenderable only gives the global position and orientation
           of a single point (e.x. the center of the physics object) for the RenderSystem to transform the visual mesh to.
    \warning DO NOT CREATE THIS CLASS MANUALLY. Use a RenderSystem implementation of this class instead.
*/
class NxOgrePublicClass PointRenderable
{
  
  public: // Functions
  
  /** \brief Required virtual destructor.
  */
  virtual                                    ~PointRenderable(void);
  
  /** \brief Transform the visual mesh according the global position and orientation (as a quaternion).
  */
  virtual void                                render(const Vec3&, const Quat&) = 0;
  
  
}; // class PointRenderable

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
