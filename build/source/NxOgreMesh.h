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

                                                                                       

#ifndef NXOGRE_MESH_H
#define NXOGRE_MESH_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreMeshStats.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Mesh : public ResourceAllocatable
{
  
  NXOGRE_GC_FRIEND_NEW1
  NXOGRE_GC_FRIEND_DELETE
  friend class MeshManager;
  
  public: // Functions
  
  /** \brief Set the name of this Mesh
  */
  void                                        setName(const char*);
  
  /** \brief Set the name of this Mesh
  */
  void                                        setName(const String&);
  
  /** \brief Get the name of this mesh.
  */
  String                                      getName() const;
  
  /** \brief Get the name of this mesh.
  */
  StringHash                                  getNameHash() const;
  
  /** \brief Text
  */
  Enums::MeshType                             getType() const;
  
  /** \brief Get type (as a string).
      \note Use Mesh::getType for comparisions.
  */
  String                                      getTypeAsString() const;
  
  /** \brief Is the shape loaded?
  */
  bool                                        isLoaded() const;
  
  /** \brief Is a shape(s) using this mesh?
  */
  bool                                        isUsed() const;

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

  /** \brief Get's the convex mesh, or null
  */
  NxCCDSkeleton*                              getAsSkeleton();

  /** \brief Get and/or calculate the statistics of the mesh
  */
  MeshStats                                   getStats();
  
  /*! function. getTextureCoords
      desc.
          Fill a float array with texture coordinates assigned to this mesh.
      note.
          Float array length should be at least: 2 * mMesh->getNbTextureCoords()
  */
  void                                        getTextureCoords(float*);

  /** \brief Get number of texture coords.
  */
  unsigned int                                getNbTextureCoords() const;

  /** \brief Save the mesh information into MeshData
      \note  You should NXOGRE_DELETE_NXOGRE the MeshData pointer after use.
  */
  MeshData*                                   getMeshData();
  
  /*! function. inspect
      desc.
          Give a description of what this mesh is.
  */
  String inspect() const;
  
  protected: // Variables
  
  Enums::MeshType                             mType;
 
  union
  {
   NxConvexMesh*                              mConvex;
   NxTriangleMesh*                            mTriangle;
   NxClothMesh*                               mCloth;
   NxSoftBodyMesh*                            mSoftBody;
   NxCCDSkeleton*                             mSkeleton;
  } mMesh;
  
  /** \brief Render vertices
  */
  buffer<float>                               mVertices;

  /** \brief Render indices
  */
  buffer<unsigned int>                        mIndices;

  /** \brief Render normals
  */
  buffer<float>                               mNormals;
  
  /** \brief Render texture coords
  */
  buffer<float>                               mTextureCoords;
  
  /** \brief Name of the mesh
  */
  String                                      mName;
  
  /** \brief Hash of the name of the mesh.
  */
  StringHash                                  mNameHash;

  /** \brief
  */
  MeshStats                                   mMeshStats;
  
  protected:
  
  /** \brief Mesh constructor
  */
                                              Mesh();
  
  /** \brief Mesh constructor, equilvent of calling load(uri);
  */
                                              Mesh(Resource*);
  
  /** \brief Text
  */
                                             ~Mesh();
    
  /** \brief Load a mesh from a resource, and take on that mesh.
  */
  void                                        load(Resource*);
  
  /** \brief Unload the mesh.
  */
  void                                        unload();

}; // class Mesh

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
