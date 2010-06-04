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
#include "NxOgreNXS.h"
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



NXS::NXS()
{
 // Should never happen.
}

NXS::~NXS()
{
 // Should never happen.
}

NxTriangleMesh* NXS::loadTriangleMesh(Resource* resource)
{

 NxPhysicsSDK* sdk = NxGetPhysicsSDK();

 return sdk->createTriangleMesh(PhysXStream(resource));

}

bool NXS::saveTriangleMesh(Resource* resource, MeshData* mesh_data)
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

// #ifdef NXOGRE_DEBUG
  std::cout << "[#] saveTriangleMesh, isValid = " << description.isValid() << std::endl;
// #endif

 PhysXStream cooking_stream(resource);
 return cookingInterface->NxCookTriangleMesh(description, cooking_stream);

}


bool NXS::saveTriangleMesh(NxTriangleMesh* mesh, MeshData* mesh_data)
{

 NxTriangleMeshDesc desc;
 mesh->saveToDesc(desc);

 mesh_data->mVertices.remove_all();
 mesh_data->mVertices.resize(desc.numVertices * 3);
 const float* vertices = static_cast<const float*>(desc.points);
 for (unsigned int i=0; i < desc.numVertices * 3;i++)
  mesh_data->mVertices.push_back(vertices[i]);


 if (desc.triangles)
 {
  mesh_data->mIndexes.remove_all();
  mesh_data->mIndexes.resize(desc.numTriangles * 3);
  if (desc.flags & NX_MF_16_BIT_INDICES)
  {
   const unsigned short* indexes = static_cast<const unsigned short*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.push_back(indexes[i]);
   }
  }
  else
  {
   const unsigned int* indexes = static_cast<const unsigned int*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.push_back(indexes[i]);
   }
  }
 }

 if (desc.materialIndices)
 {
  mesh_data->mMaterials.remove_all();
  mesh_data->mMaterials.resize(desc.numTriangles * 3);
  const unsigned short* indexes = static_cast<const unsigned short*>(desc.materialIndices);
  for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   mesh_data->mMaterials.push_back(indexes[i]);
 }


 mesh_data->mMeshFlags = desc.flags;
 return true;
}


NxConvexMesh* NXS::loadConvexMesh(Resource* resource)
{


 NxPhysicsSDK* sdk = NxGetPhysicsSDK();

 return sdk->createConvexMesh(PhysXStream(resource));

}

bool NXS::saveConvexMesh(Resource* resource, MeshData* mesh_data)
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

 PhysXStream cooking_stream(resource);

 return cookingInterface->NxCookConvexMesh(description, cooking_stream);

}

bool NXS::saveConvexMesh(NxConvexMesh* mesh, MeshData* mesh_data)
{
 NxConvexMeshDesc desc;
 mesh->saveToDesc(desc);

 const float* vertices = static_cast<const float*>(desc.points);
 for (unsigned int i=0; i < desc.numVertices * 3;i++)
  mesh_data->mVertices.push_back(vertices[i]);

 if (desc.triangles)
 {
  mesh_data->mIndexes.remove_all();
  mesh_data->mIndexes.resize(desc.numTriangles * 3);
  if (desc.flags & NX_MF_16_BIT_INDICES)
  {
   const unsigned short* indexes = static_cast<const unsigned short*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.push_back(indexes[i]);
   }
  }
  else
  {
   const unsigned int* indexes = static_cast<const unsigned int*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.push_back(indexes[i]);
   }
  }
 }

 mesh_data->mMeshFlags = desc.flags;
 return true;
}



NxClothMesh* NXS::loadClothMesh(Resource* resource, buffer<float>& textureCoordinates)
{
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();

 PhysXStream cooking_stream(resource);
 NxClothMesh* mesh = sdk->createClothMesh(cooking_stream);
 
 if (mesh == 0)
  return 0;
 
 size_t fileSize = resource->getSize();

 // False on a resource size less than eight bytes.
 if (fileSize < 5)
  return mesh;


 // False on the resource not having 'ExTXC' at the end of the file.
 {
  char header[5] = {0, 0, 0, 0, 0};
  resource->seekBeginning();
  resource->seek(fileSize - 5);

  resource->readCharArray(header, 5);
  if ( (header[0] == 'E' && header[1] == 'x' && header[2] == 'T' && header[3] == 'X' && header[4] == 'C') == false)
  {
   NxOgre_DebugPrint_Resources("No TextureCoords found for this Cloth Mesh");
   return mesh;
  }
 }


 resource->seek(fileSize - 5 - sizeof(unsigned int));

 size_t nbTextureCoords = resource->readUInt();
 textureCoordinates.resize(nbTextureCoords * 2);

 resource->seek(fileSize - 5 - sizeof(unsigned int) - (nbTextureCoords * 2 * sizeof(float)));

 for (unsigned int i=0;i < nbTextureCoords * 2;i++)
  textureCoordinates[i] = resource->readFloat();

 NxOgre_DebugPrint_Resources("Loaded texture coordinates found for this Cloth Mesh, count = " << nbTextureCoords);
 
 return mesh;
}

bool NXS::saveClothMesh(Resource* resource, MeshData* meshData)
{
 
 NxClothMeshDesc description;
 
 description.points                = meshData->mVertices.first();
 description.pointStrideBytes      = sizeof(float) * 3;
 description.numVertices           = meshData->mVertices.size() / 3;

 if (meshData->mIndexes.size())
 {
  description.triangles             = meshData->mIndexes.first();
  description.triangleStrideBytes   = sizeof(unsigned int) * 3;
  description.numTriangles          = meshData->mIndexes.size() / 3;
 }

 if (meshData->mMasses.size())
 {
  description.vertexMasses          = meshData->mMasses.first();
  description.vertexMassStrideBytes = sizeof(float);
 }

 if (meshData->mFlags.size())
 {
  description.vertexFlags           = meshData->mFlags.first();
  description.vertexFlagStrideBytes = sizeof(unsigned int);
 }

 description.flags                 = meshData->mMeshFlags;
 description.weldingDistance       = meshData->mClothWeldingDistance;


 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();
 
 PhysXStream cooking_stream(resource);
 bool result = cookingInterface->NxCookClothMesh(description, cooking_stream);

 NxOgre_DebugPrint_Cooking("Cooking for Cloth is = " << (result ? "Okay" : "Not Okay"));
 
 if (result == false)
  return false;
 
 if (meshData->mTextureCoordinates.size() == 0)
 {
  NxOgre_DebugPrint_Cooking("No texture coordinates for this cloth mesh");
  return true;
 }

 // Save texture coordinates to the end of the NXS file.
 // -  The header and length is written at the end of the file.
 
 // First write the texture coordinates; two floats each.
 for (unsigned int i=0;i < meshData->mTextureCoordinates.size(); i++)
  resource->writeFloat(meshData->mTextureCoordinates[i]);
  
 // Write the number of texture coordinates.
 resource->writeUInt(meshData->mTextureCoordinates.size() / 2);
 
 // Write header.
 resource->writeUChar('E');
 resource->writeUChar('x');
 resource->writeUChar('T');
 resource->writeUChar('X');
 resource->writeUChar('C');
 
 NxOgre_DebugPrint_Cooking("Wrote Texture Coordinates, tex_coords = " << meshData->mTextureCoordinates.size() / 2 << ", verts = " << meshData->mVertices.size() / 3);

 return true;
}

bool NXS::saveClothMesh(NxClothMesh* mesh, MeshData* meshData)
{

 NxClothMeshDesc desc;
 mesh->saveToDesc(desc);

 meshData->mVertices.remove_all();
 meshData->mVertices.resize(desc.numVertices * 3);

 const float* vertices = static_cast<const float*>(desc.points);
 for (unsigned int i=0; i < desc.numVertices * 3;i++)
 {
  meshData->mVertices.push_back(vertices[i]);
 }

 if (desc.triangles)
 {
  meshData->mIndexes.remove_all();
  meshData->mIndexes.resize(desc.numTriangles * 3);
  if (desc.flags & NX_MF_16_BIT_INDICES)
  {
   const unsigned short* indexes = static_cast<const unsigned short*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    meshData->mIndexes.push_back(indexes[i]);
   }
  }
  else
  {
   const unsigned int* indexes = static_cast<const unsigned int*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    meshData->mIndexes.push_back(indexes[i]);
   }
  }
 }

 if (desc.vertexFlags)
 {
  meshData->mFlags.remove_all();
  meshData->mFlags.resize(desc.numVertices * 3);
  const unsigned int* flags = static_cast<const unsigned int*>(desc.vertexFlags);
  for (unsigned int i=0; i < desc.numVertices * 3;i++)
   meshData->mFlags.push_back(flags[i]);
 }

 if (desc.vertexMasses)
 {
  meshData->mFlags.remove_all();
  meshData->mFlags.resize(desc.numVertices * 3);
  const float* masses = static_cast<const float*>(desc.vertexMasses);
  for (unsigned int i=0; i < desc.numVertices * 3;i++)
   meshData->mFlags.push_back(masses[i]);
 }

 meshData->mMeshFlags = desc.flags;
 meshData->mClothWeldingDistance = desc.weldingDistance;

 return true;
}





bool NXS::isNXSFile(Resource* resource)
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

Enums::MeshType NXS::getMeshType(Resource* resource)
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

String NXS::getMeshTypeAsString(Enums::MeshType type)
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

                                                                                       


#if 0

NxClothMesh* NXS::loadClothMesh(Resource* resource, bool perform_check)
{

 if (perform_check)
 {
  if (isNXSFile(resource) == false)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a PhysX NXS mesh file.";
   NxOgre_ThrowException(IOException, stream.str(), Classes::_MeshSerialiser);
   return 0;
  }

  Enums::MeshType type = getMeshType(resource);

  if (type != Enums::MeshType_Cloth)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a valid PhysX NXS Cloth Mesh file.\n"
          << "Reason: It is a " << getMeshTypeAsString(type);
   NxOgre_ThrowException(IOException, stream.str(), Classes::_MeshSerialiser);
   return 0;
  }
 }

 NxPhysicsSDK* sdk = NxGetPhysicsSDK();

 PhysXStream cooking_stream(resource);
 return sdk->createClothMesh(cooking_stream);
}

bool NXS::saveClothMesh(Resource* resource, MeshData* mesh_data)
{

 NxClothMeshDesc description;
 description.setToDefault();

 description.points                = mesh_data->mVertices.first();
 description.pointStrideBytes      = sizeof(float) * 3;
 description.numVertices           = mesh_data->mVertices.size() / 3;

 if (mesh_data->mIndexes.size())
 {
  description.triangles             = mesh_data->mIndexes.first();
  description.triangleStrideBytes   = sizeof(unsigned int) * 3;
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

 
 NxOgre_DebugPrint_Cooking("Cooking Cloth Mesh. Verts: " << mesh_data->mVertices.size() / 3 << ", Indexes/Tris:" << mesh_data->mIndexes.size() << "/" << mesh_data->mIndexes.size() / 3);

 NxOgre_DebugPrint_Cooking("\nVerts\n" << to_s(mesh_data->mVertices.first(), description.numVertices * 3) << "\nIndexes\n" << to_s(mesh_data->mIndexes.first(), description.numTriangles * 3) << "\n");

 
 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();
 
 PhysXStream cooking_stream(resource);
 bool result = cookingInterface->NxCookClothMesh(description, cooking_stream);
 NxOgre_DebugPrint_Cooking("Cooking result is = " << (result ? "Okay" : "Not Okay"));
 
 return result;
}

bool NXS::saveClothMesh(NxClothMesh* mesh, MeshData* mesh_data)
{
 NxClothMeshDesc desc;
 mesh->saveToDesc(desc);

 mesh_data->mVertices.remove_all();
 mesh_data->mVertices.resize(desc.numVertices * 3);

 const float* vertices = static_cast<const float*>(desc.points);
 for (unsigned int i=0; i < desc.numVertices * 3;i++)
 {
  mesh_data->mVertices.push_back(vertices[i]);
 }

 if (desc.triangles)
 {
  mesh_data->mIndexes.remove_all();
  mesh_data->mIndexes.resize(desc.numTriangles * 3);
  if (desc.flags & NX_MF_16_BIT_INDICES)
  {
   const unsigned short* indexes = static_cast<const unsigned short*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.push_back(indexes[i]);
   }
  }
  else
  {
   const unsigned int* indexes = static_cast<const unsigned int*>(desc.triangles);
   for (unsigned int i=0; i < desc.numTriangles * 3;i++)
   {
    mesh_data->mIndexes.push_back(indexes[i]);
   }
  }
 }

 if (desc.vertexFlags)
 {
  mesh_data->mFlags.remove_all();
  mesh_data->mFlags.resize(desc.numVertices * 3);
  const unsigned int* flags = static_cast<const unsigned int*>(desc.vertexFlags);
  for (unsigned int i=0; i < desc.numVertices * 3;i++)
   mesh_data->mFlags.push_back(flags[i]);
 }

 if (desc.vertexMasses)
 {
  mesh_data->mFlags.remove_all();
  mesh_data->mFlags.resize(desc.numVertices * 3);
  const float* masses = static_cast<const float*>(desc.vertexMasses);
  for (unsigned int i=0; i < desc.numVertices * 3;i++)
   mesh_data->mFlags.push_back(masses[i]);
 }

 mesh_data->mMeshFlags = desc.flags;
 mesh_data->mClothWeldingDistance = desc.weldingDistance;

 return true;
}




NxClothMesh* NXS::loadExtendedClothMesh(Resource* resource, buffer<float>& texture_coords, bool perform_check)
{

 if (perform_check)
 {
  if (isNXSFile(resource) == false)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << "' is not a PhysX NXS mesh file.";
   NxOgre_ThrowException(IOException, stream.str(), Classes::_MeshSerialiser);
   return 0;
  }

  Enums::MeshType type = getMeshType(resource);

  if (type != Enums::MeshType_Cloth)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << "' is not a valid PhysX NXS Cloth Mesh file.\n"
          << "Reason: It is a " << getMeshTypeAsString(type);
   NxOgre_ThrowException(IOException, stream.str(), Classes::_MeshSerialiser);
   return 0;
  }
 }

 NxPhysicsSDK* sdk = NxGetPhysicsSDK();

 PhysXStream cooking_stream(resource);
 NxClothMesh* mesh = sdk->createClothMesh(cooking_stream);

 if (mesh == 0)
  return false;

 loadClothTextureCoords(resource, texture_coords);

 return mesh;
}

bool NXS::saveExtendedClothMesh(Resource* resource, MeshData* mesh_data)
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

 PhysXStream cooking_stream(resource);
 bool b = cookingInterface->NxCookClothMesh(description, cooking_stream);

 if (!b)
  return false;

 // Extended data.
 //  The coordinates are written first, and the header is written at the end of the file (in reverse).
 if (mesh_data->mTextureCoordinates.size())
  saveClothTextureCoords(resource, mesh_data->mTextureCoordinates);

 return true;
}




void NXS::loadClothTextureCoords(Resource* resource, buffer<float>& texture_coords)
{


 // False on a resource size less than eight bytes.
 if (resource->getSize() < 5)
  return;

 //
 size_t fileSize = resource->getSize();

 // False on the resource not having 'ExTXC' at the end of the file.
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
  texture_coords.push_back(resource->readFloat());
}

void NXS::saveClothTextureCoords(Resource* resource, buffer<float>& texture_coords)
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




#endif