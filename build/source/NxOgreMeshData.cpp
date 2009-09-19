/** File: NxOgreMeshData.cpp
    Created on: 14-Sept-09
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
#include "NxOgreMeshData.h"
#include "NxOgreMeshFunctions.h"
#include "NxOgreResourceSystem.h"

                                                                                       

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
  Functions::Mesh::createConvexMesh(resource, this);

 else if (mType == Enums::MeshType_Triangle)
  Functions::Mesh::createTriangleMesh(resource, this);

 else if (mType == Enums::MeshType_Cloth)
  Functions::Mesh::createClothMesh(resource, this);

 else if (mType == Enums::MeshType_SoftBody)
  Functions::Mesh::createSoftBodyMesh(resource, this);
 
}

void MeshData::cook(const NxOgre::ArchiveResourceIdentifier& ari)
{
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(ari, NxOgre::Enums::ResourceAccess_WriteOnly);
 
 cook(cookingResource);
 
 ResourceSystem::getSingleton()->close(cookingResource);
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
