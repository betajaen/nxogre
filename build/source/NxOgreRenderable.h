/** File: NxOgreRenderable.h
    Created on: 13-Feb-09
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

#ifndef NXOGRE_RENDERABLE_H
#define NXOGRE_RENDERABLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Renderable is an abstract class with functions to pass onto a RenderSystem to add vertices and indexes to a Scene.
    \warning DO NOT CREATE THIS CLASS MANUALLY. Use a RenderSystem implementation of this class instead.
*/
class NxOgrePublicClass Renderable
{
  
  
  public: // Functions
  
  /**
  */
  Renderable(Enums::RenderableType);
  
  /**
  */
  virtual ~Renderable(void);
  
  /** \brief Draw some PhysXMeshData.
  */
  virtual void                              drawSoftBodySimple(PhysXMeshData*, const Bounds3&) = 0;
  
  /** \brief Draw some PhysXMeshData with texture coordinates.
  */
  virtual void                              drawCloth(PhysXMeshData*, Buffer<float>& textureCoords, const Bounds3&) = 0;
   
  /** \brief Draw some PhysXMeshData with texture coordinates.
  */
  virtual void                              drawClothFast(PhysXMeshData*, const Bounds3&) = 0;
  
  /** \brief Draw some VisualDebuggerData.
  */
  virtual void                              drawVisualDebugger(VisualDebuggerMeshData*) = 0;

  /** \brief Get the RenderableType.
  */
  NxOgre::Enums::RenderableType             getType(void) const;
  
  protected:
  
   NxOgre::Enums::RenderableType            mType;
  
}; // class Renderable

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
