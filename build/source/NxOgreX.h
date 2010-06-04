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

                                                                                       

#ifndef NXOGRE_X_H
#define NXOGRE_X_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Serialisation
{

                                                                                       

/** \brief Collection of functions to serialise NxOgre meshes and heightfields to Resources or MeshDatas.
*/
class NxOgrePublicClass X
{
  
 public:
  
  /** \brief Load a NxOgre Skeleton from a Resource
  */
  static NxCCDSkeleton* loadSkeletonMesh(Resource*);
  
  /** \brief Save a NxOgre MeshData, i.e. Cooking a mesh from a ManualMesh.
  */
  static bool saveSkeletonMesh(Resource*, MeshData*);
  
  /** \brief Save/Convert a NxCCDSkeleton to a MeshData
  */
  static bool saveSkeletonMesh(NxCCDSkeleton*, MeshData*);
  
  /** \brief Load a NxOgre HeightField from a Resource
  */
  static NxHeightField* loadHeightField(Resource*);
  
  /** \brief Save a NxOgre HeightFieldData, i.e. Cooking a heightfield from a HeightFieldData.
  */
  static bool saveHeightField(Resource*, HeightFieldData*);
  
  /** \brief Save/Convert a NxHeightField to a HeightFieldData
  */
  static bool saveHeightField(NxHeightField*, HeightFieldData*);
  
  
  /** \brief Is a PhysX Skeleton or Heightfield?
  */
  static bool isXFile(Resource*);
    
  /** \brief Get the type of mesh from the resource.
  */
  static Enums::XType getXType(Resource*);
  
  /** \brief Turn the MeshType enum to a String.
  */
  static String getXTypeAsString(Enums::XType);
  
 private:
  
  /** \internal DO NOT USE
  */
  X();
  
  /** \internal DO NOT USE
  */
 ~X();
  
};

                                                                                       

} // namespace Serialisation

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
