/** File: NxOgreXXX.cpp
    Created on: X-XXX-XX
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
#include "NxOgrePhysXMeshData.h"
#include "NxOgreMesh.h"
#include "NxOgreMeshStats.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXMeshData::PhysXMeshData(Mesh* mesh, size_t modifier)
{
 MeshStats stats = mesh->getStats();
 _configure(stats.getNbVertices() * modifier, stats.getNbIndices() * modifier, stats.getNbIndices() * modifier);
}

PhysXMeshData::~PhysXMeshData(void)
{
 NxOgre_Delete(mNbVertices);
 NxOgre_Delete(mNbIndices);
 NxOgre_Delete(mNbParentIndices);
}

NxMeshData PhysXMeshData::getMeshData()
{
 NxMeshData data;
 
 data.dirtyBufferFlagsPtr = 0;
 data.flags = 0;
 data.indicesBegin = mIndices.first();
 data.indicesByteStride = sizeof(unsigned int);
 data.maxIndices = mIndices.capacity();
 data.maxParentIndices = 0;
 data.maxVertices = mVertices.capacity();
 data.numIndicesPtr = mNbIndices;
 data.numParentIndicesPtr = mNbParentIndices;
 data.numVerticesPtr = mNbVertices;
 data.parentIndicesBegin = mParentIndices.first();
 data.parentIndicesByteStride = sizeof(unsigned int);
 data.verticesNormalBegin = mNormals.first();
 data.verticesNormalByteStride = sizeof(float) * 3;
 data.verticesPosBegin = mVertices.first();
 data.verticesPosByteStride = sizeof(float) * 3;
 
 return data;
}

float* PhysXMeshData::getVertices()
{
 return mVertices.first();
}

float* PhysXMeshData::getNormals()
{
 return mNormals.first();
}

unsigned int* PhysXMeshData::getIndices()
{
 return mIndices.first();
}

unsigned int PhysXMeshData::getNbVertices()
{
 return (*mNbVertices);
}

unsigned int PhysXMeshData::getNbIndices()
{
 return (*mNbIndices);
}

unsigned int PhysXMeshData::getNbParentIndices()
{
 return (*mNbParentIndices);
}

void PhysXMeshData::_configure(size_t verts, size_t indices, size_t parent_indices)
{
 mVertices.reserve(verts * 3);
 mNormals.reserve(verts * 3);
 mIndices.reserve(indices);
 mParentIndices.reserve(parent_indices);

 mNbVertices = (unsigned int*) NxOgre_Allocate(sizeof(unsigned int), ::NxOgre::Classes::_unsigned_int);
 (*mNbVertices) = 0;

 mNbIndices = (unsigned int*) NxOgre_Allocate(sizeof(unsigned int), ::NxOgre::Classes::_unsigned_int);
 (*mNbIndices) = 0;

 mNbParentIndices = (unsigned int*) NxOgre_Allocate(sizeof(unsigned int), ::NxOgre::Classes::_unsigned_int);
 (*mNbParentIndices) = 0;

}

                                                                                       

} // namespace NxOgre

                                                                                       
