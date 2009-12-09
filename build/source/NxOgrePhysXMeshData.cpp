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
#include "NxOgrePhysXMeshData.h"
#include "NxOgreMesh.h"
#include "NxOgreMeshStats.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXMeshData::PhysXMeshData(Mesh* mesh, size_t modifier)
: mNbVertices(0), mNbParentIndices(0), mNbIndices(0)
{
 MeshStats stats = mesh->getStats();
 _configure(stats.getNbVertices() * modifier, stats.getNbIndices() * modifier, stats.getNbIndices() * modifier);
}

PhysXMeshData::~PhysXMeshData(void)
{
 
 if (mNbVertices)
  NXOGRE_DEALLOCATE(FourByteAllocator, mNbVertices);
 
 if (mNbIndices)
  NXOGRE_DEALLOCATE(FourByteAllocator, mNbIndices);
 
 if (mNbParentIndices)
  NXOGRE_DEALLOCATE(FourByteAllocator, mNbParentIndices);
 
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

 mNbVertices = (unsigned int*) NXOGRE_ALLOCATE(FourByteAllocator, (sizeof(unsigned int)));
 (*mNbVertices) = 0;

 mNbIndices = (unsigned int*) NXOGRE_ALLOCATE(FourByteAllocator, (sizeof(unsigned int)));
 (*mNbIndices) = 0;

 mNbParentIndices = (unsigned int*) NXOGRE_ALLOCATE(FourByteAllocator, (sizeof(unsigned int)));
 (*mNbParentIndices) = 0;

}

                                                                                       

} // namespace NxOgre

                                                                                       
