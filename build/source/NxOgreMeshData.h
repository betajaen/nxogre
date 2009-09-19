/** File: NxOgreMeshData.h
    Created on: 14-Sept-09
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

#ifndef NXOGRE_OPTIONS_MINIMAL
#ifndef NXOGRE_MESHDATA_H
#define NXOGRE_MESHDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class NxOgrePublicClass MeshData : public PointerClass<Classes::_MeshData>
{
  
 public:
  
  /** \brief MeshData constructor.
  */
                                   MeshData();
  
  /** \brief MeshData destructor.
  */
                                  ~MeshData();
  
  /** \brief Sett the name to null-string, type to unknown and clean all Buffers.
  */
  void                             clear();
  
  /** \brief
  */
  void                             cook(Resource*);
  
  /** \brief
  */
  void                             cook(const NxOgre::ArchiveResourceIdentifier&);
  
  String                           mName;
  
  NxOgre::Enums::MeshType          mType;
  
  /** \brief Vertices
      \for   Triangle, Convex, Cloth, SoftBodies.
  */
  Buffer<float>                    mVertices;
  
  /** \brief Indexes.
      \for   Triangle, Convex (Optional), Cloth, SoftBodies.
  */
  Buffer<unsigned int>             mIndexes;
  
  /** \brief Normals.
      \for   Cloth, SoftBodies.
  */
  Buffer<float>                    mNormals;

  /** \brief Texture Coordinates.
      \for   Cloth (optional), SoftBodies (optional).
      \note  Texture Coordinates are not compatible/ignored by vanilla PhysX installations.
  */
  Buffer<float>                    mTextureCoordinates;

  /** \brief Tetrahedra indexes.
      \for   SoftBodies. 
  */
  Buffer<unsigned int>             mTetrahedra;

  /** \brief Materials per index.
      \for   Triangles (optional)
  */
  Buffer<MaterialIdentifier>       mMaterials;

  /** \brief Vertex Flags
      \for   Cloth (optional) and SoftBodies (optional).
  */
  Buffer<unsigned int>             mFlags;

  /** \brief Vertex Masses
      \for   Cloth (optional) and SoftBodies (optional).
  */
  Buffer<float>                    mMasses;
  
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
#endif
