/** File: NxOgreManualMesh.cpp
    Created on: 28-Feb-09
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
#include "NxOgreManualMesh.h"
#include "NxOgreMesh.h"
#include "NxOgreMeshData.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreMeshFunctions.h"
#include "NxOgreMeshManager.h"
#include "NxOgreFunctions.h"
#include "NxOgreResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ManualMesh::ManualMesh(void)
{
 mMesh = new MeshData();

 mRef = (RefT*) NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_ManualMeshReferenceCounter);
 (*mRef) = 1;
}

ManualMesh::~ManualMesh(void)
{
 if(--(*mRef) == 0)
 {
  ::NxOgre::Memory::unallocate(mRef);
  delete mMesh;
 }
}

ManualMesh& ManualMesh::operator=(ManualMesh& other)
{
 if(--(*mRef) == 0)
 {
  ::NxOgre::Memory::unallocate(mRef);
  delete mMesh;
 }
 mMesh      = other.mMesh;
 mRef       = other.mRef;
 (*mRef)++;
 return *this;
}

void ManualMesh::begin(NxOgre::Enums::MeshType type, unsigned int estimatedVerticesSize, unsigned int estimatedTriSize)
{
 
 mMesh->mType = type;
 mMesh->mVertices.reserve(estimatedVerticesSize * 3);
 Functions::fill<float>(mMesh->mVertices.first(), mMesh->mVertices.end(), 0.0f);
 
 if (mMesh->mType == NxOgre::Enums::MeshType_Triangle)
 {
  mMesh->mIndexes.reserve(estimatedTriSize == AUTO_CALCULATE_TRIANGLES ? mMesh->mVertices.size() * 3 : estimatedTriSize * 3);
  mMesh->mMaterials.reserve(mMesh->mIndexes.size());
  
  Functions::fill<unsigned int>(mMesh->mIndexes.first(), mMesh->mIndexes.end(), 0);
  Functions::fill<MaterialIdentifier>(mMesh->mMaterials.first(), mMesh->mMaterials.end(), 0);
  
  return;
 }
 
 if (mMesh->mType == NxOgre::Enums::MeshType_Convex)
 {
  // Normally, convexes don't need triangles. So instead of wasting memory each time, it will be allocated as needed.
  mMesh->mIndexes.reserve(estimatedTriSize == AUTO_CALCULATE_TRIANGLES ? 0 : estimatedTriSize * 3);
  Functions::fill<unsigned int>(mMesh->mIndexes.first(), mMesh->mIndexes.end(), 0);
 }
 
 if (mMesh->mType == NxOgre::Enums::MeshType_SoftBody)
 {
  mMesh->mTetrahedra.reserve(estimatedVerticesSize * 4);
  Functions::fill<unsigned int>(mMesh->mTetrahedra.first(), mMesh->mTetrahedra.end(), 0);
 }
 
}

void ManualMesh::clean()
{
 mMesh->clear();
}

void ManualMesh::name(const String& name)
{
 mMesh->mName = name;
}

void ManualMesh::name(const char* name)
{
 mMesh->mName = name;
}

String ManualMesh::name(void) const
{
 return mMesh->mName;
}

void ManualMesh::acquire(MeshData* data)
{
 
 if(--(*mRef) == 0)
 {
  ::NxOgre::Memory::unallocate(mRef);
  delete mMesh;
 }
 
 mRef = (RefT*) NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_ManualMeshReferenceCounter);
 (*mRef) = 1;
 
 mMesh = data;
 
}

void ManualMesh::vertex(float x, float y, float z)
{
 mMesh->mVertices.append(x);
 mMesh->mVertices.append(y);
 mMesh->mVertices.append(z);
}

void ManualMesh::vertex(const Vec3& r)
{
 mMesh->mVertices.append(r.x);
 mMesh->mVertices.append(r.y);
 mMesh->mVertices.append(r.z);
}

void ManualMesh::index(unsigned int i)
{
 mMesh->mIndexes.append(i);
}

void ManualMesh::triangle(unsigned int a, unsigned int b, unsigned int c)
{
 mMesh->mIndexes.append(a);
 mMesh->mIndexes.append(b);
 mMesh->mIndexes.append(c);
}

void ManualMesh::normal(float a, float b, float c)
{
 mMesh->mNormals.append(a);
 mMesh->mNormals.append(b);
 mMesh->mNormals.append(c);
}

void ManualMesh::normal(const Vec3& n)
{
 mMesh->mNormals.append(n.x);
 mMesh->mNormals.append(n.y);
 mMesh->mNormals.append(n.z);
}

void ManualMesh::textureCoordinate(float a, float b)
{
 mMesh->mTextureCoordinates.append(a);
 mMesh->mTextureCoordinates.append(b);
}

void ManualMesh::textureCoordinate(const Vec2& r)
{
 mMesh->mTextureCoordinates.append(r.x);
 mMesh->mTextureCoordinates.append(r.y);
}

void ManualMesh::material(MaterialIdentifier i)
{
 mMesh->mMaterials.append(i);
}

void ManualMesh::tetrahedra(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
 mMesh->mTetrahedra.append(a);
 mMesh->mTetrahedra.append(b);
 mMesh->mTetrahedra.append(c);
 mMesh->mTetrahedra.append(d);
}

void ManualMesh::vertexMass(float mass)
{
 mMesh->mMasses.append(mass);
}

void ManualMesh::vertexFlag(unsigned int flag)
{
 mMesh->mFlags.append(flag);
}

bool ManualMesh::isValid(void) const
{
 return true;
}

Mesh* ManualMesh::end(bool cleanUp, const ArchiveResourceIdentifier& cookingTarget)
{
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(cookingTarget, NxOgre::Enums::ResourceAccess_ReadAndWrite);
 
 mMesh->cook(cookingResource);
 
 cookingResource->seekBeginning();

 Mesh* mesh = 0;
 
 if (mMesh->mName.length() == 0)
  mesh = MeshManager::getSingleton()->load(cookingResource);
 else
  mesh = MeshManager::getSingleton()->load(cookingResource, mMesh->mName);
  
 if (cookingResource->getStatus() == Enums::ResourceStatus_Opened)
  ResourceSystem::getSingleton()->close(cookingResource);
 
 if (cleanUp)
  clean();
 
 return mesh;
}

void ManualMesh::endCookOnly(bool cleanUp, ArchiveResourceIdentifier& cookingTarget)
{
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(cookingTarget, NxOgre::Enums::ResourceAccess_WriteOnly);
 
 mMesh->cook(cookingResource);
 
 ResourceSystem::getSingleton()->close(cookingResource);
 
 if (cleanUp)
  clean();
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
