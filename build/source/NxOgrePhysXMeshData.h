/** File: NxOgreXXX.h
    Created on: X-XXX-XX
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

#ifndef NXOGRE_PHYSXMESHDATA_H
#define NXOGRE_PHYSXMESHDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass PhysXMeshData : public NxOgre::PointerClass<Classes::_PhysXMeshData>
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              PhysXMeshData(Mesh*, size_t modifier = 2);
  
  /** \brief Text
  */
                                             ~PhysXMeshData(void);
  
  /** \internal Do not use in User App.
  */
                     NxMeshData               getMeshData();
  
  /** \brief Get the vertices as three floats. Use getNbVertices() as a count. Vertices size will be 3 * getNbVertices().
  */
                     float*                   getVertices();
  
  /** \brief Get the vertices as three floats. Use getNbVertices() as a count. Normals size will be 3 * getNbVertices().
  */                 
                     float*                   getNormals();
  
  /** \brief Get the indexes as 32 bit integers. Use getNbIndices() as a count.
  */                 
                     unsigned int*            getIndices();
  
  /** \brief Get the current number of vertices, normals and texture coordinates.
  */
                     unsigned int             getNbVertices();
   
  /** \brief Get the current indices
  */
                     unsigned int             getNbIndices();
   
  /** \brief Get the current parent indices
  */
                     unsigned int             getNbParentIndices();
  
  protected:

                     void                     _configure(size_t verts, size_t indices, size_t parent_indices);
  
                     Buffer<float>            mVertices;
  
                     Buffer<float>            mNormals;
  
                     Buffer<unsigned int>     mIndices;
  
                     Buffer<unsigned int>     mParentIndices;
  
                     unsigned int*            mNbVertices;
  
                     unsigned int*            mNbIndices;
  
                     unsigned int*            mNbParentIndices;
  
}; // class PhysXMeshData


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
