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
#include "NxOgreX.h"
#include "NxOgreWorld.h"
#include "NxOgreResource.h"
#include "NxOgrePhysXStream.h"
#include "NxOgreMeshData.h"
#include "NxOgreHeightFieldData.h"
#include "NxOgreReason.h"

#include "NxPhysics.h"
#include "NxCooking.h"

                                                                                       

namespace NxOgre
{

                                                                                       


namespace Serialisation
{

static const unsigned int X_SKELETON_VERSION = 1;
static const unsigned int X_HEIGHTFIELD_VERSION = 3;


X::X()
{
 // Should never happen.
}

X::~X()
{
 // Should never happen.
}

NxCCDSkeleton* X::loadSkeletonMesh(Resource* resource)
{
 resource->seekBeginning();
 resource->seek(14);
 size_t nbVertices = resource->readUShort();
 size_t nbTriangles = resource->readUShort();

 NxOgre_DebugPrint_Cooking("Reading Skeleton Mesh. nbVertices = '" << nbVertices << "', nbTriangles = '" << nbTriangles << "'");
 
 buffer<float> vertices;
 vertices.resize(nbVertices * 3);
 for (unsigned int i=0;i < nbVertices * 3;i++)
 {
  vertices.push_back(resource->readFloat());
 }

#if 0
 for (unsigned int i=0;i < nbVertices * 3;i+=3)
 {
  std::cout << "V: " << vertices[i+0] << ", "<< vertices[i+01] << ", " << vertices[i+2] << "\n";
 }
#endif

 buffer<unsigned short> indexes;
 indexes.resize(nbTriangles * 3);
 for (unsigned short i=0;i < nbTriangles * 3;i++)
 {
  indexes.push_back(resource->readUShort());
 }

#if 0
 for (unsigned int i=0;i < nbTriangles * 3;i+=3)
 {
  std::cout << "I: " << indexes[i+00] << ", "<< indexes[i+01] << ", " << indexes[i+2] << "\n";
 }
#endif
 
 NxSimpleTriangleMesh desc;
 desc.flags |= NX_MF_16_BIT_INDICES;
 desc.numTriangles = nbTriangles;
 desc.numVertices = nbVertices;
 desc.points = vertices.first();
 desc.pointStrideBytes = sizeof(float) * 3;
 desc.triangles = indexes.first();
 desc.triangleStrideBytes = sizeof(unsigned short) * 3;
 
 
 NxOgre_DebugPrint_Cooking("Reading Skeleton Description Valid = '" << desc.isValid() << "'");
 
 
 NxPhysicsSDK* sdk = World::getSingleton()->getPhysXSDK();

 NxOgre_DebugPrint_Cooking("SDK Ptr = '" << sdk << "'");

 NxCCDSkeleton* skeleton = sdk->createCCDSkeleton(desc);
 
 NxOgre_DebugPrint_Cooking("Skeleton Ptr = '" << skeleton << "'");
 
 return skeleton;
}

bool X::saveSkeletonMesh(Resource* resource, MeshData* mesh_data)
{
 // Calculate filelength.
 size_t estFileLength =  6                          // "NXOGRE"
                         + sizeof(unsigned int)     // File size
                         + 2                        // File Type
                         + sizeof(short)            // Version
                         + sizeof(short)            // Number of vertices
                         + sizeof(short)            // Number of indexes
                         + (mesh_data->mVertices.size() * sizeof(float))
                         + (mesh_data->mIndexes.size() * sizeof(unsigned short));

 NxOgre_DebugPrint_Cooking("Writing Skeleton Mesh. est_file_size = '" << estFileLength << "'");
 
 resource->writeChar('N'); // 1
 resource->writeChar('X'); // 2
 resource->writeChar('O'); // 3
 resource->writeChar('G'); // 4
 resource->writeChar('R'); // 5
 resource->writeChar('E'); // 6
 
 resource->writeUInt(estFileLength);  // 10
 
 resource->writeChar('S'); // 11
 resource->writeChar('K'); // 12
 
 resource->writeUShort(X_SKELETON_VERSION); // 14

 resource->writeUShort(mesh_data->mVertices.size() / 3); // 16
 resource->writeUShort(mesh_data->mIndexes.size() / 3); // 18
 
 // Vertices 
 resource->write(mesh_data->mVertices.first(), sizeof(float) * mesh_data->mVertices.size());
 
 // Indexes. Converted to unsigned short.
 for (unsigned int i=0; i < mesh_data->mIndexes.size(); i++)
  resource->writeUShort(mesh_data->mIndexes[i]);
 
 return true;
}


bool X::saveSkeletonMesh(NxCCDSkeleton* mesh, MeshData* mesh_data)
{
 return false;
}









NxHeightField* X::loadHeightField(Resource* resource)
{
 
 NxHeightFieldDesc desc;
 
 NxOgre_DebugPrint_Cooking("Reading HeightField Mesh.");
 
 resource->seekBeginning();
 resource->seek(14);

 desc.sampleStride = sizeof(HeightFieldSample);
 desc.nbRows = resource->readUInt();
 desc.nbColumns = resource->readUInt();
 
 NxOgre_DebugPrint_Cooking("nbRows = '" << desc.nbRows << "', nbColumns = '" << desc.nbColumns << "'");
 
 desc.thickness = resource->readFloat();
 desc.verticalExtent = resource->readFloat();
 desc.convexEdgeThreshold = resource->readFloat();
 
 if (resource->readBool() == false)
  desc.flags |= NX_HF_NO_BOUNDARY_EDGES;
 
 buffer<unsigned int> samples;
 samples.resize(desc.nbRows * desc.nbColumns);
 for (unsigned int i=0;i < desc.nbRows * desc.nbColumns;i++)
 {
  samples.push_back(resource->readUInt());
 }
 
 desc.samples = samples.first();
 
 if (desc.isValid() == false)
 {
   NxOgre_ThrowException(DescriptionInvalidException, "Cannot cook HeightField. Reason(s) are: " + Reason::Exceptionise(desc) , Classes::_RigidBody);
 }
 
 NxOgre_DebugPrint_Cooking("Reading HeightField Description Valid = '" << desc.isValid() << "'");
 
 NxPhysicsSDK* sdk = World::getSingleton()->getPhysXSDK();
 
 NxHeightField* hf = sdk->createHeightField(desc);
 
 NxOgre_DebugPrint_Cooking("HeightField Ptr = '" << hf << "'");
 
 return hf;
}


bool X::saveHeightField(Resource* resource, HeightFieldData* hf_data)
{
 // Calculate filelength.
 size_t estFileLength =  6                          // "NXOGRE"
                         + sizeof(unsigned int)     // File size
                         + 2                        // File Type
                         + sizeof(short)            // Version
                         + 0;

 NxOgre_DebugPrint_Cooking("Writing HeightField. est_file_size = '" << estFileLength << "'");
 
 resource->writeChar('N'); // 1
 resource->writeChar('X'); // 2
 resource->writeChar('O'); // 3
 resource->writeChar('G'); // 4
 resource->writeChar('R'); // 5
 resource->writeChar('E'); // 6
 
 resource->writeUInt(estFileLength);  // 10
 
 resource->writeChar('H'); // 11
 resource->writeChar('F'); // 12
 
 resource->writeUShort(X_HEIGHTFIELD_VERSION); // 14

 resource->writeUInt(hf_data->mNbRows);
 resource->writeUInt(hf_data->mNbColumns);
 resource->writeFloat(hf_data->mThickness);
 resource->writeFloat(hf_data->mVerticalExtent);
 resource->writeFloat(hf_data->mConvexEdgeThreshold);
 resource->writeChar(hf_data->mNoEdgeBoundaries);
 
 resource->write(hf_data->mSamples.first(), sizeof(HeightFieldSample) * hf_data->mSamples.size());
 
 return true;
}

bool X::saveHeightField(NxHeightField*, HeightFieldData*)
{
 return false;
}



bool X::isXFile(Resource* resource)
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
 if (resource->getSize() < 12)
 {
  NxOgre_DebugPrint_Meshes("File header size less than 12 bytes");
  return false;
 }
 
 // False on the resource not having 'N', 'X', 'O', 'G', 'R', 'E' as the first six bytes of the file.
 {
  char header[6] = {0, 0, 0, 0, 0, 0};
  resource->seekBeginning();
  resource->readCharArray(header, 6);
  if ( (header[0] == 'N' && header[1] == 'X' && header[2] == 'O' && header[3] == 'G' && header[4] == 'R' && header[5] == 'E') == false)
  {
   NxOgre_DebugPrint_Meshes("isXFile -- Not a NXOGRE header");
   return false;
  }
 }

 // False on size being less than 12 bytes.
 unsigned int size = resource->readUInt();
 if (size < 12)
 {
  NxOgre_DebugPrint_Meshes("File header size less than 12 bytes");
  return false;
 }

 {
  char fileType[2] = {0, 0};
  resource->readCharArray(fileType, 2);


  // Skeleton
  if ( (fileType[0] == 'S' && fileType[1] == 'K')  )
  {
   NxOgre_DebugPrint_Meshes("X-file file type is Skeleton");
   return true;
  }

  // Heightfield
  if ( (fileType[0] == 'H' && fileType[1] == 'F')  )
  {
   NxOgre_DebugPrint_Meshes("X-file file type is Heightfield");
   return true;
  }

  
  NxOgre_DebugPrint_Meshes("Not a recongised header '" << fileType[0] << fileType[1] << "'");
 }

 // No need to check for a version, that is mesh/heightfield type specific.

 return false;
}



Enums::XType X::getXType(Resource* resource)
{
 char meshType[2] = {0, 0};
 resource->seekBeginning();
 resource->seek(10);
 resource->readCharArray(meshType, 2);

 NxOgre_DebugPrint_Meshes("Header '" << meshType[0] << meshType[1] << "'");

 // NxConvexMesh
 if ( (meshType[0] == 'S' && meshType[1] == 'K')  )
  return Enums::XType_Skeleton;

 // NxTriangleMesh
 if ( (meshType[0] == 'H' && meshType[1] == 'F' )  )
  return Enums::XType_HeightField;

 return Enums::XType_Unknown;
}

String X::getXTypeAsString(Enums::XType type)
{
 
 if (type == Enums::XType_Skeleton)
  return "skeleton";
 else if (type == Enums::XType_HeightField)
  return "heightfield";
 
 return "unknown";
}

                                                                                       

} // namespace Serialisation

                                                                                       

} // namespace NxOgre

                                                                                       
