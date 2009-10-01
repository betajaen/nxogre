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
#include "NxOgreMeshSerialiser.h"
#include "NxOgreWorld.h"
#include "NxOgreResource.h"
#include "NxOgrePhysXStream.h"
#include "NxOgreMeshData.h"

#include "NxPhysics.h"
#include "NxCooking.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Serialisation
{

                                                                                       

MeshSerialiser::MeshSerialiser()
{
 assert(0); // NEVER TO BE CREATED.
}

MeshSerialiser::~MeshSerialiser()
{
 assert(0); // NEVER TO BE DELETED.
}

NxTriangleMesh* MeshSerialiser::loadTriangleMesh(Resource* resource, bool perform_check)
{
 
 if (perform_check)
 {
  if (isNXSFile(resource) == false) 
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a PhysX NXS mesh file.";
   NxOgre_ThrowError(stream.str());
   return 0;
  }
  
  Enums::MeshType type = getMeshType(resource);
  
  if (type != Enums::MeshType_Triangle)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a valid PhysX NXS Triangle Mesh file.\n"
          << "Reason: It is a " << getMeshTypeAsString(type);
   NxOgre_ThrowError(stream.str());
   return 0;
  }
 }
 
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 return sdk->createTriangleMesh(PhysXStream(resource));
 
}

bool MeshSerialiser::saveTriangleMesh(Resource* resource, MeshData* mesh_data)
{

 NxTriangleMeshDesc description;
 
 description.points               = mesh_data->mVertices.first();
 description.pointStrideBytes     = sizeof(float) * 3;
 description.numVertices          = mesh_data->mVertices.size() / 3;
 
 if (mesh_data->mIndexes.size())
 {
  description.triangles            = mesh_data->mIndexes.first();
  description.triangleStrideBytes  = 3 * sizeof(unsigned int);
  description.numTriangles         = mesh_data->mIndexes.size() / 3;
 }

 description.materialIndices      = mesh_data->mMaterials.first();
 description.materialIndexStride  = sizeof(MaterialIdentifier);
 
 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();
 
 return cookingInterface->NxCookTriangleMesh(description, PhysXStream(resource));
 
}


bool MeshSerialiser::saveTriangleMesh(NxTriangleMesh* mesh, MeshData* mesh_data)
{
 
 NxTriangleMeshDesc desc;
 mesh->saveToDesc(desc);
 
 
 mesh_data->mVertices.reserve(desc.numVertices * 3);
 const float* vertices = static_cast<const float*>(desc.points);
 for (unsigned int i=0; i < desc.numVertices * 3;i++)
  mesh_data->mVertices.append(vertices[i]);
 
  
 if (desc.triangles)
 {
  mesh_data->mIndexes.reserve(desc.numTriangles * 3);
  if (desc.flags & NX_MF_16_BIT_INDICES)
  {
   const unsigned short* indexes = static_cast<const unsigned short*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.append(indexes[i]);
   }
  }
  else
  {
   const unsigned int* indexes = static_cast<const unsigned int*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.append(indexes[i]);
   }
  }
 }
 
 if (desc.materialIndices)
 {
  mesh_data->mMaterials.reserve(desc.numTriangles * 3);
  const unsigned short* indexes = static_cast<const unsigned short*>(desc.materialIndices);
  for (unsigned int i=0; i < desc.numTriangles * 3;i++)
  {
    mesh_data->mMaterials.append(indexes[i]);
  }
 }
 

 mesh_data->mMeshFlags = desc.flags;
 return true;
}


NxConvexMesh* MeshSerialiser::loadConvexMesh(Resource* resource, bool perform_check)
{

 if (perform_check)
 {
  if (isNXSFile(resource) == false) 
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a PhysX NXS mesh file.";
   NxOgre_ThrowError(stream.str());
   return 0;
  }
  
  Enums::MeshType type = getMeshType(resource);
  
  if (type != Enums::MeshType_Convex)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a valid PhysX NXS Convex Mesh file.\n"
          << "Reason: It is a " << getMeshTypeAsString(type);
   NxOgre_ThrowError(stream.str());
   return 0;
  }
 }
 
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 return sdk->createConvexMesh(PhysXStream(resource));

}

bool MeshSerialiser::saveConvexMesh(Resource* resource, MeshData* mesh_data)
{
 
 NxConvexMeshDesc description;
 description.points               = mesh_data->mVertices.first();
 description.pointStrideBytes     = sizeof(float) * 3;
 description.numVertices          = mesh_data->mVertices.size() / 3;

 if (mesh_data->mIndexes.size())
 {
  description.triangles           = mesh_data->mIndexes.first();
  description.triangleStrideBytes = 3 * sizeof(unsigned int);
  description.numTriangles        = mesh_data->mIndexes.size() / 3;
 }
 else
  description.flags              |= NX_CF_COMPUTE_CONVEX;
 
 if (mesh_data->mMeshFlags & NX_MF_16_BIT_INDICES)
  description.flags              |= NX_CF_16_BIT_INDICES;


 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();
 
 return cookingInterface->NxCookConvexMesh(description, PhysXStream(resource));
 
}

bool MeshSerialiser::saveConvexMesh(NxConvexMesh* mesh, MeshData* mesh_data)
{
 NxConvexMeshDesc desc;
 mesh->saveToDesc(desc); 
 
 const float* vertices = static_cast<const float*>(desc.points);
 for (unsigned int i=0; i < desc.numVertices * 3;i++)
  mesh_data->mVertices.append(vertices[i]);
 
 if (desc.triangles)
 {
  mesh_data->mIndexes.reserve(desc.numTriangles * 3);
  if (desc.flags & NX_MF_16_BIT_INDICES)
  {
   const unsigned short* indexes = static_cast<const unsigned short*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.append(indexes[i]);
   }
  }
  else
  {
   const unsigned int* indexes = static_cast<const unsigned int*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.append(indexes[i]);
   }
  }
 }

 mesh_data->mMeshFlags = desc.flags;
 return true;
}



NxCCDSkeleton* MeshSerialiser::loadSkeletonMesh(Resource* resource, bool perform_check)
{
 // VIRTUAL
 return 0;
}




bool MeshSerialiser::saveSkeletonMesh(Resource*, NxCCDSkeleton*)
{
 return false;
}


bool MeshSerialiser::saveSkeletonMesh(NxCCDSkeleton*, MeshData*)
{
 return false;
}





NxClothMesh* MeshSerialiser::loadClothMesh(Resource* resource, bool perform_check)
{
 
 if (perform_check)
 {
  if (isNXSFile(resource) == false) 
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a PhysX NXS mesh file.";
   NxOgre_ThrowError(stream.str());
   return 0;
  }
  
  Enums::MeshType type = getMeshType(resource);
  
  if (type != Enums::MeshType_Cloth)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a valid PhysX NXS Cloth Mesh file.\n"
          << "Reason: It is a " << getMeshTypeAsString(type);
   NxOgre_ThrowError(stream.str());
   return 0;
  }
 }
 
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 return sdk->createClothMesh(PhysXStream(resource));
}

bool MeshSerialiser::saveClothMesh(Resource* resource, MeshData* mesh_data)
{
 
 NxClothMeshDesc description;
 description.setToDefault();
 
 description.points                = mesh_data->mVertices.first();
 description.pointStrideBytes      = sizeof(float) * 3;
 description.numVertices           = mesh_data->mVertices.size();
 
 if (mesh_data->mIndexes.size())
 {
  description.triangles             = mesh_data->mIndexes.first();
  description.triangleStrideBytes   = 3 * sizeof(unsigned int);
  description.numTriangles          = mesh_data->mIndexes.size() / 3;
 }
 
 if (mesh_data->mMasses.size())
 {
  description.vertexMasses          = mesh_data->mMasses.first();
  description.vertexMassStrideBytes = sizeof(float);
 }
 
 if (mesh_data->mFlags.size())
 {
  description.vertexFlags           = mesh_data->mFlags.first();
  description.vertexFlagStrideBytes = sizeof(unsigned int);
 }
 
 description.flags                 = mesh_data->mMeshFlags;
 description.weldingDistance       = mesh_data->mClothWeldingDistance;

 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();

 return cookingInterface->NxCookClothMesh(description, PhysXStream(resource));
 
}

bool MeshSerialiser::saveClothMesh(NxClothMesh* mesh, MeshData* mesh_data)
{
 NxClothMeshDesc desc;
 mesh->saveToDesc(desc);
 
 mesh_data->mVertices.reserve(desc.numVertices * 3);
 
 const float* vertices = static_cast<const float*>(desc.points);
 for (unsigned int i=0; i < desc.numVertices * 3;i++)
 {
  mesh_data->mVertices.append(vertices[i]);
 }
 
 if (desc.triangles)
 {
  mesh_data->mIndexes.reserve(desc.numTriangles * 3);
  if (desc.flags & NX_MF_16_BIT_INDICES)
  {
   const unsigned short* indexes = static_cast<const unsigned short*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.append(indexes[i]);
   }
  }
  else
  {
   const unsigned int* indexes = static_cast<const unsigned int*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.append(indexes[i]);
   }
  }
 }
 
 if (desc.vertexFlags)
 {
  mesh_data->mFlags.reserve(desc.numVertices * 3);
  const unsigned int* flags = static_cast<const unsigned int*>(desc.vertexFlags);
  for (unsigned int i=0; i < desc.numVertices * 3;i++)
   mesh_data->mFlags.append(flags[i]);
 }
 
 if (desc.vertexMasses)
 {
  mesh_data->mFlags.reserve(desc.numVertices * 3);
  const float* masses = static_cast<const float*>(desc.vertexMasses);
  for (unsigned int i=0; i < desc.numVertices * 3;i++)
   mesh_data->mFlags.append(masses[i]);
 } 
 
 mesh_data->mMeshFlags = desc.flags;
 
 mesh_data->mClothWeldingDistance = desc.weldingDistance;
 
 return true;
}




NxClothMesh* MeshSerialiser::loadExtendedClothMesh(Resource* resource, Buffer<float>& texture_coords, bool perform_check)
{
 
 if (perform_check)
 {
  if (isNXSFile(resource) == false) 
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a PhysX NXS mesh file.";
   NxOgre_ThrowError(stream.str());
   return 0;
  }
  
  Enums::MeshType type = getMeshType(resource);
  
  if (type != Enums::MeshType_Cloth)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a valid PhysX NXS Cloth Mesh file.\n"
          << "Reason: It is a " << getMeshTypeAsString(type);
   NxOgre_ThrowError(stream.str());
   return 0;
  }
 }
 
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 NxClothMesh* mesh = sdk->createClothMesh(PhysXStream(resource));

 if (mesh == 0)
  return false;
 
 loadClothTextureCoords(resource, texture_coords);
 
 return mesh;
}

bool MeshSerialiser::saveExtendedClothMesh(Resource* resource, MeshData* mesh_data)
{
 
 NxClothMeshDesc description;
 description.setToDefault();
 
 description.points                = mesh_data->mVertices.first();
 description.pointStrideBytes      = sizeof(float) * 3;
 description.numVertices           = mesh_data->mVertices.size();
 
 if (mesh_data->mIndexes.size())
 {
  description.triangles             = mesh_data->mIndexes.first();
  description.triangleStrideBytes   = 3 * sizeof(unsigned int);
  description.numTriangles          = mesh_data->mIndexes.size() / 3;
 }
 
 if (mesh_data->mMasses.size())
 {
  description.vertexMasses          = mesh_data->mMasses.first();
  description.vertexMassStrideBytes = sizeof(float);
 }
 
 if (mesh_data->mFlags.size())
 {
  description.vertexFlags           = mesh_data->mFlags.first();
  description.vertexFlagStrideBytes = sizeof(unsigned int);
 }
 
 description.flags                 = mesh_data->mMeshFlags;
 description.weldingDistance       = mesh_data->mClothWeldingDistance;

 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();


 bool b = cookingInterface->NxCookClothMesh(description, PhysXStream(resource));
 
 if (!b)
  return false;

 // Extended data.
 //  The coordinates are written first, and the header is written at the end of the file (in reverse).
 if (mesh_data->mTextureCoordinates.size())
  saveClothTextureCoords(resource, mesh_data->mTextureCoordinates);

 return true;
}




void MeshSerialiser::loadClothTextureCoords(Resource* resource, Buffer<float>& texture_coords)
{

 
 // False on a resource size less than eight bytes.
 if (resource->getSize() < 5)
  return;
 
 //
 size_t fileSize = resource->getSize();
 
 // False on the resource not having 'NxOgre<42>' at the end of the file.
 {
  char header[5] = {0, 0, 0, 0, 0};
  resource->seekBeginning();
  resource->seek(fileSize - 5);
 
  resource->readCharArray(header, 5);
  if ( (header[0] == 'E' && header[1] == 'x' && header[2] == 'T' && header[3] == 'X' && header[4] == 'C') == false)
   return;
 }
 
 
 resource->seek(fileSize - 5 - sizeof(unsigned int));
 
 size_t textureLength = resource->readUInt();
 
 resource->seek(fileSize - 5 - sizeof(unsigned int) - (textureLength * sizeof(float)));
 
 for (size_t i = 0; i < textureLength;i++)
  texture_coords.append(resource->readFloat());
}

void MeshSerialiser::saveClothTextureCoords(Resource* resource, Buffer<float>& texture_coords)
{
 
 size_t texture_length = texture_coords.size();
 for (size_t i = 0; i < texture_length;i++)
  resource->writeFloat(texture_coords[i]);
 
 resource->writeUInt(texture_length);
 
 resource->writeUChar('E');
 resource->writeUChar('x');
 resource->writeUChar('T');
 resource->writeUChar('X');
 resource->writeUChar('C');
 
}




bool MeshSerialiser::isNXSFile(Resource* resource)
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



bool MeshSerialiser::isXSKFile(Resource* resource)
{
 return false;
}




Enums::MeshType MeshSerialiser::getMeshType(Resource* resource)
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

String MeshSerialiser::getMeshTypeAsString(Enums::MeshType type)
{
 if (type == Enums::MeshType_Cloth)
  return "cloth";
 else if (type == Enums::MeshType_Convex)
  return "convex";
 else if (type == Enums::MeshType_Skeleton)
  return "skeleton";
 else if (type == Enums::MeshType_SoftBody)
  return "softbody";
 else if (type == Enums::MeshType_Triangle)
  return "triangle";
 
 return "unknown";
}



                                                                                       

} // namespace Serialisation

                                                                                       

} // namespace NxOgre

                                                                                       
