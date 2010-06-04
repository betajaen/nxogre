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
#include "NxOgreMeshData.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreNXS.h"
#include "NxOgreX.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MeshData::MeshData() : mType(NxOgre::Enums::MeshType_Unknown), mClothWeldingDistance(0.0f)
{
}

MeshData::~MeshData()
{
}

void MeshData::clear()
{
 mName.clear();
 mType = Enums::MeshType_Unknown;
 mVertices.remove_all();
 mIndexes.remove_all();
 mNormals.remove_all();
 mTextureCoordinates.remove_all();
 mTetrahedra.remove_all();
 mMaterials.remove_all();
 mFlags.remove_all();
 mMasses.remove_all();
 mMeshFlags = 0;
 mClothWeldingDistance = 0.0f;
}

void MeshData::cook(Resource* resource)
{
 
 NxOgre_DebugPrint_Cooking("[MeshData] Attempting to cook to resource");
 
 if (mType == Enums::MeshType_Convex)
  Serialisation::NXS::saveConvexMesh(resource, this);

 else if (mType == Enums::MeshType_Triangle)
  Serialisation::NXS::saveTriangleMesh(resource, this);

 else if (mType == Enums::MeshType_Cloth)
  Serialisation::NXS::saveClothMesh(resource, this);

 else if (mType == Enums::MeshType_Skeleton)
  Serialisation::X::saveSkeletonMesh(resource, this);

// else if (mType == Enums::MeshType_SoftBody)
//  Serialisation::NXS::saveSoftBodyMesh(resource, this);
 
}

void MeshData::cook(const NxOgre::Path& path)
{
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(path, NxOgre::Enums::ResourceAccess_WriteOnly);
 
 cook(cookingResource);
 
 ResourceSystem::getSingleton()->close(cookingResource);
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
