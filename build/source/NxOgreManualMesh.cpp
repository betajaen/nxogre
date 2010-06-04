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
#include "NxOgreManualMesh.h"
#include "NxOgreMesh.h"
#include "NxOgreMeshData.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreMeshManager.h"
#include "NxOgreFunctions.h"
#include "NxOgreResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ManualMesh::ManualMesh()
: mMesh(GC::safe_new0<MeshData>(NXOGRE_GC_THIS))
{
}

ManualMesh::ManualMesh(const ManualMesh& other)
: mMesh(other.mMesh)
{
}

ManualMesh::ManualMesh(MeshData* data)
: mMesh(data)
{
}

ManualMesh::~ManualMesh()
{
}

ManualMesh& ManualMesh::operator=(ManualMesh& other)
{
 mMesh = other.mMesh;
 return *this;
}

void ManualMesh::begin(NxOgre::Enums::MeshType type, unsigned int estimatedVerticesSize, unsigned int estimatedTriSize)
{
 
 mMesh->mType = type;
 mMesh->mVertices.remove_all();
 mMesh->mIndexes.remove_all();
 mMesh->mNormals.remove_all();
 mMesh->mTextureCoordinates.remove_all();
 mMesh->mTetrahedra.remove_all();
 mMesh->mMaterials.remove_all();
 mMesh->mFlags.remove_all();
 mMesh->mMasses.remove_all();
 mMesh->mMeshFlags = 0;
 mMesh->mClothWeldingDistance = 0.0f;

 mMesh->mVertices.resize(estimatedVerticesSize * 3);
 Functions::fill<float>(mMesh->mVertices.first(), mMesh->mVertices.last(), 0.0f);
 
 if (mMesh->mType == NxOgre::Enums::MeshType_Triangle)
 {
  mMesh->mIndexes.resize(estimatedTriSize == AUTO_CALCULATE_TRIANGLES ? mMesh->mVertices.size() * 3 : estimatedTriSize * 3);
  mMesh->mMaterials.resize(mMesh->mIndexes.size());
  
  Functions::fill<unsigned int>(mMesh->mIndexes.first(), mMesh->mIndexes.last(), 0);
  Functions::fill<MaterialIdentifier>(mMesh->mMaterials.first(), mMesh->mMaterials.last(), 0);
  
  return;
 }
 
 if (mMesh->mType == NxOgre::Enums::MeshType_Convex)
 {
  // Normally, convexes don't need triangles. So instead of wasting memory each time, it will be allocated as needed.
  mMesh->mIndexes.resize(estimatedTriSize == AUTO_CALCULATE_TRIANGLES ? 0 : estimatedTriSize * 3);
  Functions::fill<unsigned int>(mMesh->mIndexes.first(), mMesh->mIndexes.last(), 0);
 }
 
 if (mMesh->mType == NxOgre::Enums::MeshType_SoftBody)
 {
  mMesh->mTetrahedra.resize(estimatedVerticesSize * 4);
  Functions::fill<unsigned int>(mMesh->mTetrahedra.first(), mMesh->mTetrahedra.last(), 0);
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

String ManualMesh::name() const
{
 return mMesh->mName;
}

void ManualMesh::acquire(MeshData* data)
{
 mMesh = SharedPointer<MeshData>(data);
}

void ManualMesh::vertex(float x, float y, float z)
{
 mMesh->mVertices.push_back(x);
 mMesh->mVertices.push_back(y);
 mMesh->mVertices.push_back(z);
}

void ManualMesh::vertex(const Vec3& r)
{
 mMesh->mVertices.push_back(r.x);
 mMesh->mVertices.push_back(r.y);
 mMesh->mVertices.push_back(r.z);
}

unsigned int ManualMesh::nbVertices() const
{
 return mMesh->mVertices.size() / 3;
}

unsigned int ManualMesh::nbTriangles() const
{
 return mMesh->mIndexes.size() / 3;
}

unsigned int ManualMesh::nbTextureCoords() const
{
 return mMesh->mTextureCoordinates.size() / 2;
}

void ManualMesh::modifyVertex(unsigned index, const Vec3& newValue)
{
 mMesh->mVertices[(index*3)] = newValue.x;
 mMesh->mVertices[(index*3)+1] = newValue.y;
 mMesh->mVertices[(index*3)+2] = newValue.z;
}

void ManualMesh::scaleVertex(unsigned index, const Vec3& factor)
{
 mMesh->mVertices[(index*3)] *= factor.x;
 mMesh->mVertices[(index*3)+1] *= factor.y;
 mMesh->mVertices[(index*3)+2] *= factor.z;
}

void ManualMesh::index(unsigned int i)
{
 mMesh->mIndexes.push_back(i);
}

void ManualMesh::triangle(unsigned int a, unsigned int b, unsigned int c)
{
 mMesh->mIndexes.push_back(a);
 mMesh->mIndexes.push_back(b);
 mMesh->mIndexes.push_back(c);
}

void ManualMesh::normal(float a, float b, float c)
{
 mMesh->mNormals.push_back(a);
 mMesh->mNormals.push_back(b);
 mMesh->mNormals.push_back(c);
}

void ManualMesh::normal(const Vec3& n)
{
 mMesh->mNormals.push_back(n.x);
 mMesh->mNormals.push_back(n.y);
 mMesh->mNormals.push_back(n.z);
}

void ManualMesh::textureCoordinate(float a, float b)
{
 mMesh->mTextureCoordinates.push_back(a);
 mMesh->mTextureCoordinates.push_back(b);
}

void ManualMesh::textureCoordinate(const Vec2& r)
{
 mMesh->mTextureCoordinates.push_back(r.x);
 mMesh->mTextureCoordinates.push_back(r.y);
}

void ManualMesh::material(MaterialIdentifier i)
{
 mMesh->mMaterials.push_back(i);
}

void ManualMesh::tetrahedra(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
 mMesh->mTetrahedra.push_back(a);
 mMesh->mTetrahedra.push_back(b);
 mMesh->mTetrahedra.push_back(c);
 mMesh->mTetrahedra.push_back(d);
}

void ManualMesh::vertexMass(float mass)
{
 mMesh->mMasses.push_back(mass);
}

void ManualMesh::vertexFlag(unsigned int flag)
{
 mMesh->mFlags.push_back(flag);
}

bool ManualMesh::isValid() const
{ // NOTE: Incomplete function
 return true;
}

Mesh* ManualMesh::end(bool cleanUp, const Path& cookingTarget)
{
 
 NxOgre_DebugPrint_Cooking("ManualMesh -- end");
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(cookingTarget, NxOgre::Enums::ResourceAccess_ReadAndWrite);
 
 NxOgre_DebugPrint_Cooking("Attempting to cook to resource");
 mMesh->cook(cookingResource);
 
 NxOgre_DebugPrint_Cooking("Attempting to read mesh.");
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

void ManualMesh::endCookOnly(bool cleanUp, const Path& cookingTarget)
{
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(cookingTarget, NxOgre::Enums::ResourceAccess_WriteOnly);
 
 mMesh->cook(cookingResource);
 
 ResourceSystem::getSingleton()->close(cookingResource);
 
 if (cleanUp)
  clean();
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
