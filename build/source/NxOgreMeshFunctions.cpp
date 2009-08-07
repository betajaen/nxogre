/** File: NxOgreMeshFunction.cpp
    Created on: 28-Feb-09
    Author: Robin Southern "betajaen"
    SVN: $Id$

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
#include "NxOgreMeshFunctions.h"
#include "NxOgreWorld.h"
#include "NxOgrePhysXStream.h"
#include "NxOgreManualMesh.h"
#include "NxOgreMesh.h"
#include "NxOgreMeshStats.h"

#ifndef NXOGRE_OPTIONS_MINIMAL

#include "NxPhysics.h"
#include "NxCooking.h"

                                                                                       

namespace NxOgre_Namespace
{
namespace Functions
{
namespace Mesh
{

                                                                                       

inline MeshStats _calculateNxTriangleMeshStats(::NxOgre::Mesh* mesh)
{
 NxTriangleMesh* tri_mesh = mesh->getAsTriangleMesh();
 return MeshStats(tri_mesh->getCount(0, NX_ARRAY_VERTICES), tri_mesh->getCount(0, NX_ARRAY_TRIANGLES) * 3);
}

inline MeshStats _calculateNxConvexMeshStats(::NxOgre::Mesh* mesh)
{
 NxConvexMesh* convex_mesh = mesh->getAsConvex();
 return MeshStats(convex_mesh->getCount(0, NX_ARRAY_VERTICES), convex_mesh->getCount(0, NX_ARRAY_TRIANGLES) * 3);
}

inline MeshStats _calculateNxClothStats(::NxOgre::Mesh* mesh)
{
 NxClothMesh* cloth_mesh = mesh->getAsCloth();

 NxClothMeshDesc desc;
 if (cloth_mesh->saveToDesc(desc) == false)
  return MeshStats();

 // TODO: nb of texture coordinates.
 return MeshStats(desc.numVertices /* /3 */, desc.numTriangles * 3);
}

inline MeshStats _calculateNxSoftBodyStats(::NxOgre::Mesh* mesh)
{
 NxSoftBodyMesh* softbody_mesh = mesh->getAsSoftBody();

 NxSoftBodyMeshDesc desc;
 if (softbody_mesh->saveToDesc(desc) == false)
  return MeshStats();

 return MeshStats(desc.numVertices,desc.numTetrahedra * 4,0,0,desc.numTetrahedra);
}

/** \brief Calculate the number of vertices, indices, texture coordinates, tetrahedra of a mesh.
*/
NxOgrePublicFunction MeshStats calculateStats(::NxOgre::Mesh* mesh)
{
 MeshStats stats;
 if (mesh == 0)
  return stats;

 if (mesh->getType() == NxOgre::Enums::MeshType_Triangle)
  stats = _calculateNxTriangleMeshStats(mesh);

 else if (mesh->getType() == NxOgre::Enums::MeshType_Convex)
  stats = _calculateNxConvexMeshStats(mesh);
 
 else if (mesh->getType() == NxOgre::Enums::MeshType_Cloth)
  stats = _calculateNxClothStats(mesh);

 else if (mesh->getType() == NxOgre::Enums::MeshType_SoftBody)
  stats = _calculateNxSoftBodyStats(mesh);

 return stats;
}


NxOgrePublicFunction bool  createTriangleMesh
                 (
                  Resource* cookTo,
                  Buffer<float>& vertices,
                  Buffer<unsigned int>& indexes,
                  Buffer<MaterialIdentifier>& materials
                 )
{
 NxTriangleMeshDesc description;
 
 description.points               = vertices.first();
 description.pointStrideBytes     = sizeof(float) * 3;
 description.numVertices          = vertices.size() / 3;
 
 description.triangles            = indexes.first();
 description.triangleStrideBytes  = 3 * sizeof(unsigned int);
 description.numTriangles         = indexes.size() / 3;
 
 description.materialIndices      = materials.first();
 description.materialIndexStride  = sizeof(MaterialIdentifier);
 
 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();
 
 return cookingInterface->NxCookTriangleMesh(description, PhysXStream(cookTo));
}

/** \brief Create a  Convex Mesh/Point Cloud
*/
NxOgrePublicFunction bool    createConvexMesh(Resource* cookTo, Buffer<float>& vertices, Buffer<unsigned int>& indexes)
{
 NxConvexMeshDesc description;
 description.points               = vertices.first();
 description.pointStrideBytes     = sizeof(float) * 3;
 description.numVertices          = vertices.size() / 3;
 
 if (indexes.size())
 {
  description.triangles           = indexes.first();
  description.triangleStrideBytes = 3 * sizeof(unsigned int);
  description.numTriangles        = indexes.size() / 3;
 }
 else
  description.flags              |= NX_CF_COMPUTE_CONVEX;
 
 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();
 
 return cookingInterface->NxCookConvexMesh(description, PhysXStream(cookTo));
}



bool createSoftBodyMesh(Resource* resource, Buffer<float>& vertices, Buffer<unsigned int>& tetrahedra)
{
 printf("sb.1\n");
 NxSoftBodyMeshDesc description;
 description.setToDefault();
 description.vertices             = vertices.first();
 description.vertexStrideBytes    = sizeof(float) * 3;
 description.numVertices          = vertices.size() / 3;

 printf("sb.2\n");
 description.tetrahedra              = tetrahedra.first();
 description.tetrahedronStrideBytes  = sizeof(unsigned int) * 4;
 description.numTetrahedra           = tetrahedra.size() / 4 / 2;

 printf("vertices = %i\ntetrahedra = %i\n", description.numVertices, description.numTetrahedra);

 printf("description valid = %i\n", description.isValid()); 
 printf("sb.3\n");
 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();

 printf("Cooking interface: %p\n", cookingInterface);

 printf("sb.4\n");
 bool b = cookingInterface->NxCookSoftBodyMesh(description, PhysXStream(resource));

 printf("sb.5\n");
 return b;
}


/** \brief Create a  Convex Mesh/Point Cloud
*/
NxOgrePublicFunction bool createClothMesh(Resource* resource, Buffer<float>& vertices, Buffer<unsigned int>& indexes, Buffer<float>& texture_coords, Buffer<unsigned int>& flags, Buffer<float>& masses, unsigned int cookingFlags, float weldingDistance)
{
 NxClothMeshDesc description;
 description.setToDefault();
 description.points               = vertices.first();
 description.pointStrideBytes     = sizeof(float) * 3;
 description.numVertices          = vertices.size();
 
 description.triangles           = indexes.first();
 description.triangleStrideBytes = 3 * sizeof(unsigned int);
 description.numTriangles        = indexes.size() / 3;
 /*
 if (masses.size())
 {
  description.vertexMasses = masses.first();
  description.vertexFlagStrideBytes = sizeof(float);
 }

 if (flags.size())
 {
  description.vertexFlags = flags.first();
  description.vertexFlagStrideBytes = sizeof(unsigned int);
 }
*/
// description.weldingDistance = weldingDistance;
// description.flags = cookingFlags;
 
 printf("Description valid? %i\n", description.isValid());
 printf(" numVertices: %i, buffer size: %i\n", description.numVertices, vertices.size());
 printf(" numTriangles: %i, buffer size: %i\n", description.numTriangles, indexes.size());


 NxCookingInterface* cookingInterface = World::getWorld()->getPhysXCookingInterface();
 printf("Cooking interface: %p\n", cookingInterface);
 
 bool b = cookingInterface->NxCookClothMesh(description, PhysXStream(resource));
 
 // Extended data.
 //  The coordinates are written first, and the header is written at the end of the file (in reverse).
 if (texture_coords.size())
 {
  printf("Saving texture coordinates\n");
  saveExtendedCloth(resource, texture_coords);
 }
 return b;
}

NxOgrePublicFunction ::NxOgre::Mesh* generateFlatCloth(const ArchiveResourceIdentifier& target, const Vec2& size, Real d)
{
 
 int numX = (int) (size.x / d) + 1;
 int numY = (int) (size.y / d) + 1;
 
 int nbVertices = (numX + 1) * (numY + 1);
 int nbTriangles = numX * numY * 2;
 
 ManualMesh mesh;
 
 mesh.begin(Enums::MeshType_Cloth, nbVertices, nbTriangles);
 
 int i, j, i0, i1, i2, i3;

 int b =0;
 // Vertices
 for (i = 0; i <= numY; i++)
  for (j = 0; j <= numX; j++)
   {
    mesh.vertex(d * j, 0, d * i);
    b++;
   }
 printf("bv = %i\n", b);
 
 // Triangles
 b = 0;
 for (i = 0; i <= numY; i++)
  for (j = 0; j <= numX; j++)
  {
   i0 = i * (numX + 1) + j;
   i1 = i0 + 1;
   i2 = i0 + (numX + 1);
   i3 = i2 + 1;
   
   if ( (j+1) % 2)
   {
    mesh.triangle(i0, i2, i1);
    mesh.triangle(i1, i2, i3);
   }
   else
   {
    mesh.triangle(i0, i2, i3);
    mesh.triangle(i0, i3, i1);
   }
   b++;
   b++;
  }
  
  printf("bt = %i\n", b);
 
  return mesh.end(true, target);
}


void loadExtendedCloth(Resource* resource, Buffer<float>& texture_coords)
{
 
 // False on a resource that isn't opened.
 if (resource->getStatus() != ::NxOgre::Enums::ResourceStatus_Opened)
  return;

 // False on a resource that cannot be read.
 if (resource->getAccess() > ::NxOgre::Enums::ResourceAccess_ReadAndWrite)
  return;

 // False on a resource that cannot be used at omidirectionally.
 if (resource->getDirectionality() != ::NxOgre::Enums::ResourceDirectionality_Omidirectional)
  return;

 
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
  printf("AT = %i\n", resource->at());
  resource->readCharArray(header, 5);
  printf("Header = '%c%c%c%c%c'\n", header[0], header[1], header[2], header[3], header[4]);
  if ( (header[0] == 'E' && header[1] == 'x' && header[2] == 'T' && header[3] == 'X' && header[4] == 'C') == false)
   return;
 }
 
 
 resource->seek(fileSize - 5 - sizeof(unsigned int));
 
 size_t textureLength = resource->readUInt();
 
 resource->seek(fileSize - 5 - sizeof(unsigned int) - (textureLength * sizeof(float)));
 
 printf("texture length = %i", textureLength);

 for (size_t i = 0; i < textureLength;i++)
  texture_coords.append(resource->readFloat());
}

void saveExtendedCloth(Resource* resource, Buffer<float>& texture_coords)
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

                                                                                       

}
}
} // namespace NxOgre_Namespace

                                                                                       

#endif

                                                                                       
