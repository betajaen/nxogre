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
#include "NxOgreMeshSerialiser.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MeshData::MeshData() : mType(NxOgre::Enums::MeshType_Unknown), mClothWeldingDistance(0.0f), mFlags(0)
{
}

MeshData::~MeshData()
{
}

void MeshData::clear()
{
 mName.clear();
 mType = Enums::MeshType_Unknown;
 mVertices.clear();
 mIndexes.clear();
 mNormals.clear();
 mTextureCoordinates.clear();
 mTetrahedra.clear();
 mMaterials.clear();
 mFlags.clear();
 mMasses.clear();
 mFlags = 0;
 mClothWeldingDistance = 0.0f;
}

void MeshData::cook(Resource* resource)
{
 
 if (mType == Enums::MeshType_Convex)
  Serialisation::MeshSerialiser::saveConvexMesh(resource, this);

 else if (mType == Enums::MeshType_Triangle)
  Serialisation::MeshSerialiser::saveTriangleMesh(resource, this);

 else if (mType == Enums::MeshType_Cloth)
  Serialisation::MeshSerialiser::saveClothMesh(resource, this);

// else if (mType == Enums::MeshType_SoftBody)
//  Serialisation::MeshSerialiser::saveSoftBodyMesh(resource, this);
 
}

void MeshData::cook(const NxOgre::Path& path)
{
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(path, NxOgre::Enums::ResourceAccess_WriteOnly);
 
 cook(cookingResource);
 
 ResourceSystem::getSingleton()->close(cookingResource);
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
