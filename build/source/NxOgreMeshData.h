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

                                                                                       

#ifndef NXOGRE_MESHDATA_H
#define NXOGRE_MESHDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class NxOgrePublicClass MeshData : public ResourceAllocatable
{
  
 public:
  
  /** \brief MeshData constructor.
  */
                                   MeshData();
  
  /** \brief MeshData destructor.
  */
                                  ~MeshData();
  
  /** \brief Set the name to null-string, type to unknown and clean all Buffers.
  */
  void                             clear();
  
  /** \brief
  */
  void                             cook(Resource*);
  
  /** \brief
  */
  void                             cook(const Path&);
  
  String                           mName;
  
  NxOgre::Enums::MeshType          mType;
  
  /** \brief Vertices
      \for   Triangle, Convex, Cloth, SoftBodies.
  */
  buffer<float>                    mVertices;
  
  /** \brief Indexes.
      \for   Triangle, Convex (Optional), Cloth, SoftBodies.
  */
  buffer<unsigned int>             mIndexes;
  
  /** \brief Normals.
      \for   Cloth, SoftBodies.
  */
  buffer<float>                    mNormals;

  /** \brief Texture Coordinates.
      \for   Cloth (optional), SoftBodies (optional).
      \note  Texture Coordinates are not compatible/ignored by vanilla PhysX installations.
  */
  buffer<float>                    mTextureCoordinates;

  /** \brief Tetrahedra indexes.
      \for   SoftBodies. 
  */
  buffer<unsigned int>             mTetrahedra;

  /** \brief Materials per index.
      \for   Triangles (optional)
  */
  buffer<MaterialIdentifier>       mMaterials;

  /** \brief Vertex Flags
      \for   Cloth (optional) and SoftBodies (optional).
  */
  buffer<unsigned int>             mFlags;

  /** \brief Vertex Masses
      \for   Cloth (optional) and SoftBodies (optional).
  */
  buffer<float>                    mMasses;
  
  /** \brief Mesh Flags
      \see NxOgre::Enums::MeshConstructionFlags
  */
  unsigned int                     mMeshFlags;
  
  /** \brief Welding distances for vertices in cloth.
      \default 0.0f
  */
  float                            mClothWeldingDistance;
  
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
