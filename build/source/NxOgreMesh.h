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
class NxOgrePublicClass Mesh
{
  
  public: // Functions
  
  /** \brief Mesh constructor
  */
                                              Mesh();
  
  /** \brief Mesh constructor, equilvent of calling load(uri);
  */
                                              Mesh(Resource*);
  
  /** \brief Text
  */
                                             ~Mesh(void);
  
  /** \brief Set the name of this Mesh
  */
  void                                        setName(const char*);
  
  /** \brief Set the name of this Mesh
  */
  void                                        setName(const String&);
  
  /** \brief Get the name of this mesh.
  */
  String                                      getName() const;
  
  /** \brief Text
  */
  Enums::MeshType                             getType(void) const;
  
  /** \brief Is the shape loaded?
  */
  bool                                        isLoaded(void) const;
  
  /** \brief Is a shape(s) using this mesh?
  */
  bool                                        isUsed(void) const;
  
  /** \brief Load a mesh.
  */
  void                                        load(Resource*);
  
  /** \brief Get's the convex mesh, or null
  */
  NxConvexMesh*                               getAsConvex();
  
  /** \brief Get's the convex mesh, or null
  */
  NxTriangleMesh*                             getAsTriangleMesh();
  
  /** \brief Get's the convex mesh, or null
  */
  NxClothMesh*                                getAsCloth();
  
  /** \brief Get's the soft body mesh, or null
  */
  NxSoftBodyMesh*                             getAsSoftBody();

  /** \brief Get's the soft body mesh, or null
  */
  SoftBodyMesh*                               getAsSoftBodyMesh();

  /** \brief Get and/or calculate the statistics of the mesh
  */
  MeshStats                                   getStats();
  
  /** \brief Get the texture coords.
  */
  Buffer<float>&                              getTextureCoords();

  /** \brief Save the mesh information into MeshData
      \note  You should NxOgre_Delete the MeshData pointer after use.
  */
  MeshData*                                   getMeshData();
  
  protected: // Variables
  
 
  Enums::MeshType                             mType;
 
  union
  {
   NxConvexMesh*                              mConvex;
   NxTriangleMesh*                            mTriangle;
   NxClothMesh*                               mCloth;
   NxSoftBodyMesh*                            mSoftBody;
  } mMesh;
  
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
  
  /** \brief Name of the mesh
  */
  String                                      mName;
  
  /** \brief
  */
  MeshStats                                   mMeshStats;

}; // class Mesh

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
