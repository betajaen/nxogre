/** File: NxOgreNXSFunctions.cpp
    Created on: 16-Jan-09
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreNXSFunctions.h"
#include "NxOgreResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace NXSFunctions
{

                                                                                       

extern inline bool isNXS(Resource* resource)
{
 
 // False on a resource that isn't opened.
 if (resource->getStatus() != ::NxOgre::Enums::ResourceStatus_Opened)
  return false;

 // False on a resource that cannot be read.
 if (resource->getAccess() > ::NxOgre::Enums::ResourceAccess_ReadAndWrite)
  return false;

 // False on a resource that cannot be used at omidirectionally.
 if (resource->getDirectionality() != ::NxOgre::Enums::ResourceDirectionality_Omidirectional)
  return false;

 
 // False on a resource size less than eight bytes.
 if (resource->getSize() < 8)
  return false;
 
 // False on the resource not having 'N', 'X', 'S' as the first three bytes of the file.
 {
  char header[3] = {0, 0, 0};
  resource->seekBeginning();
  resource->readCharArray(header, 3);
  if ( (header[0] == 'N' && header[1] == 'X' && header[2] == 'S') == false)
   return false;
 
 }
 
 // False on the resource not having an unknown mesh type; according to PhysX 2.8.1, 17-Jan-2009
 {
  char meshType[4] = {0, 0, 0, 0};
  resource->seekBeginning();
  resource->seek(4);
  resource->readCharArray(meshType, 4);
  
  
  //printf("MESH HEADER = %c%c%c%c\n", meshType[0], meshType[1], meshType[2], meshType[3]);
  
  // NxConvexMesh
  if ( (meshType[0] == 'C' && meshType[1] == 'V' && meshType[2] == 'X' && meshType[3] == 'M')  )
   return true;
  
  // NxTriangleMesh
  if ( (meshType[0] == 'M' && meshType[1] == 'E' && meshType[2] == 'S' && meshType[3] == 'H')  )
   return true;

  // NxClothMesh or NxSSoftBody
  if ( (meshType[0] == 'C' && meshType[1] == 'L' && meshType[2] == 'T' && meshType[3] == 'H')  )
   return true;
 }
 
 return false;
}

extern inline Enums::MeshType getMeshType(Resource* resource)
{
 char meshType[4] = {0, 0, 0, 0};
 resource->seekBeginning();
 resource->seek(4);
 resource->readCharArray(meshType, 4);

 // NxConvexMesh
 if ( (meshType[0] == 'C' && meshType[1] == 'V' && meshType[2] == 'X' && meshType[3] == 'M')  )
  return Enums::MeshType_Convex;
 
 // NxTriangleMesh
 if ( (meshType[0] == 'M' && meshType[1] == 'E' && meshType[2] == 'S' && meshType[3] == 'H')  )
  return Enums::MeshType_Triangle;
 
 // NxClothMesh or NxSoftBody
 if ( (meshType[0] == 'C' && meshType[1] == 'L' && meshType[2] == 'T' && meshType[3] == 'H')  )
 {
  // SoftBodies and Cloth have the same header, however it seems that there is a subtle difference between the two;
  // Byte 12 value is 01 for Cloth and 02 for SoftBodies.
  
  resource->seekBeginning();
  resource->seek(12);
  
  unsigned char d = resource->readChar();
  if (d == 1)
   return Enums::MeshType_Cloth;
  else if (d == 2)
   return Enums::MeshType_SoftBody;
  else
   return Enums::MeshType_Unknown;

 }
 return Enums::MeshType_Unknown;
}

/// extern inline bool hasExtendedMeshData(Resource*)
/// {
///  
/// }

/// extern inline void* getExtendedMeshData(Resource*, size_t& dataLength)
/// {
///  
/// }

                                                                                       

}

                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       
