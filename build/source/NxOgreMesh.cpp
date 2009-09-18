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
#include "NxOgreNXSFunctions.h"
#include "NxOgreMeshFunctions.h"
#include "NxOgreManualMesh.h"
#include "NxOgreMeshData.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

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
}

Enums::MeshType Mesh::getType(void) const
{
 return mType;
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
 }
 
 return false;
}

void Mesh::load(Resource* resource)
{
 
 if (Functions::NXSFunctions::isNXS(resource) == false) 
 {
  SharedStringStream stream;
  stream << "Resource '" << resource->getArchiveResourceIdentifier().getArchive() << ":" << resource->getArchiveResourceIdentifier().getResourceName() << " is not a PhysX NXS mesh file.";
  NxOgre_ThrowError(stream.get());
  return;
 }
 
 mType = Functions::NXSFunctions::getMeshType(resource);

 if (mType == Enums::MeshType_Unknown)
 {
  SharedStringStream stream;
  stream << "Resource '" << resource->getArchiveResourceIdentifier().getArchive() << ":" << resource->getArchiveResourceIdentifier().getResourceName() << " is not a valid PhysX NXS Mesh file.\n"
         << "Reason: Un-recongised mesh header";
  NxOgre_ThrowError(stream.get());
  return;
 }
 
 resource->seekBeginning();
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 
 if (mType == Enums::MeshType_Convex)
  mMesh.mConvex = sdk->createConvexMesh(PhysXStream(resource));
 else if (mType == Enums::MeshType_Triangle)
  mMesh.mTriangle = sdk->createTriangleMesh(PhysXStream(resource));
 else if (mType == Enums::MeshType_Cloth)
  mMesh.mCloth = sdk->createClothMesh(PhysXStream(resource));
 else if (mType == Enums::MeshType_SoftBody)
  mMesh.mSoftBody = sdk->createSoftBodyMesh(PhysXStream(resource));
 
 // Check for extended NxOgre data.
 if (mType == Enums::MeshType_Cloth)
  NxOgre::Functions::Mesh::loadExtendedCloth(resource, mTextureCoords);

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

void Mesh::setName(const char* name)
{
 mName = name;
}

void Mesh::setName(const String& name)
{
 mName = name;
}

String Mesh::getName() const
{
 return mName;
}

MeshStats Mesh::getStats()
{
 if (mMeshStats.getNbVertices() != 0)
  return mMeshStats;
 
 mMeshStats = ::NxOgre::Functions::Mesh::calculateStats(this);

 return mMeshStats;
}

Buffer<float>& Mesh::getTextureCoords()
{
 return mTextureCoords;
}

MeshData* Mesh::getMeshData()
{
 MeshData* data = NxOgre_New(MeshData)();
 data->mType = getType();
 if (mType == NxOgre::Enums::MeshType_Triangle)
  NxOgre::Functions::Mesh::saveTriangleMesh(mMesh.mTriangle, data);
 else if (mType == NxOgre::Enums::MeshType_Convex)
  NxOgre::Functions::Mesh::saveConvexMesh(mMesh.mConvex, data);
 else if (mType == NxOgre::Enums::MeshType_Cloth)
  NxOgre::Functions::Mesh::saveClothMesh(mMesh.mCloth, data);
// else if (mType == NxOgre::Enums::MeshType_SoftBody)
//  NxOgre::Functions::Mesh::saveSoftBodyMesh(mMesh.mSoftBody, data);
 
 return data;
}



                                                                                       

} // namespace NxOgre

                                                                                       
