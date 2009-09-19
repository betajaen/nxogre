/** File: NxOgreMesh.h
    Created on: 15-Jan-09
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

#ifndef NXOGRE_MESH_H
#define NXOGRE_MESH_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreMeshStats.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SoftBodyMesh
{
  
  public: // Functions
  
  struct TetraLink
  {
   int   tetraNb;
   float barycentricX;
   float barycentricY;
   float barycentricZ;
  };
  
  /** \brief Mesh constructor
  */
                                              Mesh();
  
  /** \brief Mesh constructor, equilvent of calling load(uri);
  */
                                              Mesh(Resource*);
  
  /** \brief Text
  */
                                             ~Mesh(void);
  
  protected: // functions

  /** \brief
  */
  void                                        updateTetraLinks(PhysXMeshData*);

  /** \brief
  */
  void                                        updateNormals();

  /** \brief
  */
  Vec3                                        computeBarycentricCoords(Vec3 vertex, Vec3 p0, Vec3 p1, Vec3 p2, Vec3 p3);

  protected: // variables

  /** \brief Render vertices
  */
  Buffer<float>                               mVertices;

  /** \brief Render indices
  */
  Buffer<unsigned int>                        mIndices;

  /** \brief Render normals
  */
  Buffer<float>                               mNormals;
  
  /** \brief Render texture coords
  */
  Buffer<float>                               mTextureCoords;
  
  /** \brief
  */
  Buffer<TetraLink>                           mTetraLink;
  
  /** \brief
  */
  Buffer<bool>                                mDrainedTriangleVertices;
  
}; // class Mesh

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
