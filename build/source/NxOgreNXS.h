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

                                                                                       

#ifndef NXOGRE_NXS_H
#define NXOGRE_NXS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Serialisation
{

                                                                                       

/** \brief Collection of functions to serialise PhysX and NxOgre meshs to Resources or MeshDatas.
*/
class NxOgrePublicClass NXS
{
  
 public:



  /** \brief Load a PhysX saved "NXS" Triangle mesh from a Resource, i.e. Loading a mesh from a file.
  */
  static NxTriangleMesh* loadTriangleMesh(Resource*);
  
  /** \brief Save a NxOgre MeshData, i.e. Cooking a mesh from a ManualMesh.
  */
  static bool saveTriangleMesh(Resource*, MeshData*);
  
  /** \brief Save/Convert a TriangleMesh to a MeshData
  */
  static bool saveTriangleMesh(NxTriangleMesh*, MeshData*);



  /** \brief Load a PhysX saved "NXS" Convex mesh from a Resource, i.e Loading a mesh from a file
  */
  static NxConvexMesh* loadConvexMesh(Resource*);
  
  /** \brief Save a NxOgre MeshData, i.e. Cooking a mesh from a ManualMesh.
  */
  static bool saveConvexMesh(Resource*, MeshData*);
  
  /** \brief Save/Convert a ConvexMesh to a MeshData
  */
  static bool saveConvexMesh(NxConvexMesh*, MeshData*);




  /*! function. loadClothMesh
      desc.
          Load a PhysX saved "NXS" Cloth mesh from a Resource, with texture coordinates.
      note.
          If there are no texture coordinates in the file, then textureCoordinates will be blank.
  */
  static NxClothMesh* loadClothMesh(Resource*, buffer<float>& textureCoordinates);
  
  /*! function. saveClothMesh
      desc.
          Save a NxOgre MeshData into a cloth, with texture coordinates.
  */
  static bool saveClothMesh(Resource*, MeshData*);
  
  /*! function. saveClothMesh
      desc.
          Save/Convert a ClothMesh to a MeshData.
      note.
          Texture coordinates cannot be loaded.
  */
  static bool saveClothMesh(NxClothMesh*, MeshData*);





  /** \brief Is a PhysX Triangle, Convex, Cloth or SoftBody file (NXS)? Is an NxOgre Extended Cloth (XCL)?
  */
  static bool isNXSFile(Resource*);
    
  /** \brief Get the type of mesh from the resource.
  */
  static Enums::MeshType getMeshType(Resource*);
  
  /** \brief Turn the MeshType enum to a String.
  */
  static String getMeshTypeAsString(Enums::MeshType);
  
 private:
  
  /** \internal DO NOT USE
  */
  NXS();
  
  /** \internal DO NOT USE
  */
 ~NXS();
  
};

                                                                                       

} // namespace Serialisation

                                                                                       

} // namespace NxOgre

                                                                                       

#endif


#if 0

  /** \brief Load a PhysX saved "NXS" Convex mesh from a Resource, i.e Loading a mesh from a file.
      \note  This uses the file-format "xsk"
  */
  static NxClothMesh* loadClothMesh(Resource*, bool perform_type_check = false);

  /** \brief Save a NxOgre MeshData, i.e. Cooking a mesh from a NxCCDSkeleton
  */
  static bool saveClothMesh(Resource*, MeshData*);

  /** \brief Save/Convert a ConvexMesh to a MeshData.
  */
  static bool saveClothMesh(NxClothMesh*, MeshData*);

  /** \brief Load a PhysX saved "NXS" Convex mesh from a Resource, i.e Loading a mesh from a file.
      \note  This uses the file-format "xcl"
  */
  static NxClothMesh* loadExtendedClothMesh(Resource*, buffer<float>& texture_coords, bool perform_type_check = false);
  
  /** \brief Load cloth texture coordinates from a resource.
      \note
           Texture coords are usually written at the end the file, with the header "ExTXC" at the end.
  */
  static void loadClothTextureCoords(Resource* resource, buffer<float>& texture_coords);

  /** \brief Save cloth texture coordinates from a resource.
      \note
           Texture coords are usually written at the end the file, with the header "ExTXC" at the end.
  */
  static void saveClothTextureCoords(Resource* resource, buffer<float>& texture_coords);

  /** \brief Save a NxOgre MeshData, i.e. Cooking a mesh from a NxCCDSkeleton
      \note  This uses the file-format "xcl"
  */
  static bool saveExtendedClothMesh(Resource*, MeshData*);
  
#endif