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
#include "NxOgreMesh.h"
#include "NxOgreResourceSystem.h"
#include "NxOgrePhysXStream.h"
#include "NxOgreManualMesh.h"
#include "NxOgreMeshData.h"
#include "NxOgreNXS.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
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

 return MeshStats(desc.numVertices, desc.numTriangles * 3, 0, mesh->getTextureCoords().size(), 0);
}

inline MeshStats _calculateNxSoftBodyStats(::NxOgre::Mesh* mesh)
{
 NxSoftBodyMesh* softbody_mesh = mesh->getAsSoftBody();

 NxSoftBodyMeshDesc desc;
 if (softbody_mesh->saveToDesc(desc) == false)
  return MeshStats();

 return MeshStats(desc.numVertices,desc.numTetrahedra * 4,0,0,desc.numTetrahedra);
}

inline MeshStats calculateStats(::NxOgre::Mesh* mesh)
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

                                                                                       

Mesh::Mesh() : mType(Enums::MeshType_Unknown)
{
 mMesh.mConvex = 0;
}

Mesh::Mesh(Resource* resource) : mType(Enums::MeshType_Unknown)
{
 mMesh.mConvex = 0;
 load(resource);
}

Mesh::~Mesh(void)
{
 unload();
}

Enums::MeshType Mesh::getType(void) const
{
 return mType;
}

String Mesh::getTypeAsString(void) const
{
 switch(mType)
 {
  case Enums::MeshType_Unknown:
   return "unknown";
  break;
  case Enums::MeshType_Convex:
   return "convex";
  break;
  case Enums::MeshType_Triangle:
   return "triangle";
  break;
  case Enums::MeshType_Cloth:
   return "cloth";
  break;
  case Enums::MeshType_SoftBody:
   return "softbody";
  break;
  case Enums::MeshType_Skeleton:
   return "skeleton";
  break;
 }
 return "unknown";
}

bool Mesh::isLoaded(void) const
{
 return (mType != Enums::MeshType_Unknown);
}

bool Mesh::isUsed(void) const
{
 
 switch(mType)
 {
  case Enums::MeshType_Unknown:
   return false;
  break;
  case Enums::MeshType_Convex:
   return (mMesh.mConvex->getReferenceCount() != 0);
  break;
  case Enums::MeshType_Triangle:
   return (mMesh.mTriangle->getReferenceCount() != 0);
  break;
  case Enums::MeshType_Cloth:
   return (mMesh.mCloth->getReferenceCount() != 0);
  break;
  case Enums::MeshType_SoftBody:
   return (mMesh.mSoftBody->getReferenceCount() != 0);
  break;
  case Enums::MeshType_Skeleton:
   return (mMesh.mSkeleton->getReferenceCount() != 0);
  break;
 }
 
 return false;
}

void Mesh::load(Resource* resource)
{
 
 unload();
 
 if (Serialisation::NXS::isNXSFile(resource) == false) 
 {
  StringStream stream;
  stream << "Resource '" << resource->getPath().getString() << " is not a PhysX NXS mesh file.";
  NxOgre_ThrowException(IOException, stream.str(), Classes::_MeshSerialiser);
  return;
 }
 
 mType = Serialisation::NXS::getMeshType(resource);

 if (mType == Enums::MeshType_Unknown)
 {
  StringStream stream;
  stream << "Resource '" << resource->getPath().getString() << " is not a valid PhysX NXS Mesh file.\n"
         << "Reason: Un-recongised mesh header";
  NxOgre_ThrowException(IOException, stream.str(), Classes::_MeshSerialiser);
  return;
 }
 
 resource->seekBeginning();
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 if (mType == Enums::MeshType_Convex)
  mMesh.mConvex = Serialisation::NXS::loadConvexMesh(resource);
 else if (mType == Enums::MeshType_Triangle)
  mMesh.mTriangle = Serialisation::NXS::loadTriangleMesh(resource);
 else if (mType == Enums::MeshType_Cloth)
  mMesh.mCloth = Serialisation::NXS::loadExtendedClothMesh(resource, mTextureCoords);
// else if (mType == Enums::MeshType_SoftBody)
//  mMesh.mSoftBody = Serialisation::NXS::loadSoftBodyMesh(resource);
 else if (mType == Enums::MeshType_Skeleton)
  mMesh.mSkeleton = Serialisation::NXS::loadSkeletonMesh(resource);
 
}

void Mesh::unload()
{
 
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 // If there is a sdk, then release the mesh, if there is no sdk, then mesh would of been automatically released.
 if (sdk)
 {
  if (mType == Enums::MeshType_Convex)
   sdk->releaseConvexMesh( *mMesh.mConvex );
  else if (mType == Enums::MeshType_Triangle)
   sdk->releaseTriangleMesh( *mMesh.mTriangle );
  else if (mType == Enums::MeshType_Cloth)
   sdk->releaseClothMesh( *mMesh.mCloth );
  else if (mType == Enums::MeshType_SoftBody)
   sdk->releaseSoftBodyMesh( *mMesh.mSoftBody );
  else if (mType == Enums::MeshType_Skeleton)
   sdk->releaseCCDSkeleton( *mMesh.mSkeleton );
 }
 
 mMesh.mCloth = 0;
 mTextureCoords.clear();
 mVertices.clear();
 mIndices.clear();
 mNormals.clear();
 mType = Enums::MeshType_Unknown;
 mName = BLANK_STRING;
 mNameHash = BLANK_HASH;
 mMeshStats.clear();
}

NxConvexMesh* Mesh::getAsConvex()
{
 return mType == Enums::MeshType_Convex ? mMesh.mConvex : 0;
}

NxTriangleMesh* Mesh::getAsTriangleMesh()
{
 return mType == Enums::MeshType_Triangle ? mMesh.mTriangle : 0;
}

NxClothMesh* Mesh::getAsCloth()
{
 return mType == Enums::MeshType_Cloth ? mMesh.mCloth : 0;
}

NxSoftBodyMesh* Mesh::getAsSoftBody()
{
 return mType == Enums::MeshType_SoftBody ? mMesh.mSoftBody : 0;
}

NxCCDSkeleton* Mesh::getAsSkeleton()
{
 return mType == Enums::MeshType_Skeleton ? mMesh.mSkeleton : 0;
}

void Mesh::setName(const char* name)
{
 setName(String(name));
}

void Mesh::setName(const String& name)
{
 mName = name;
 mNameHash = Strings::hash(name);
}

String Mesh::getName() const
{
 return mName;
}

StringHash Mesh::getNameHash() const
{
 return mNameHash;
}

MeshStats Mesh::getStats()
{
 if (mMeshStats.getNbVertices() != 0)
  return mMeshStats;
 
 mMeshStats = calculateStats(this);

 return mMeshStats;
}

Buffer<float>& Mesh::getTextureCoords()
{
 return mTextureCoords;
}

MeshData* Mesh::getMeshData()
{
 MeshData* data = NXOGRE_NEW_NXOGRE(MeshData)();
 data->mType = getType();
 if (mType == NxOgre::Enums::MeshType_Triangle)
  Serialisation::NXS::saveTriangleMesh(mMesh.mTriangle, data);
 else if (mType == NxOgre::Enums::MeshType_Convex)
  Serialisation::NXS::saveConvexMesh(mMesh.mConvex, data);
 else if (mType == NxOgre::Enums::MeshType_Cloth)
  Serialisation::NXS::saveClothMesh(mMesh.mCloth, data);
// else if (mType == NxOgre::Enums::MeshType_SoftBody)
//  NxOgre::Functions::Mesh::saveSoftBodyMesh(mMesh.mSoftBody, data);
 else if (mType == NxOgre::Enums::MeshType_Skeleton)
  Serialisation::NXS::saveSkeletonMesh(mMesh.mSkeleton, data);

 return data;
}



                                                                                       

} // namespace NxOgre

                                                                                       
