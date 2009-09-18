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

                                                                                       
