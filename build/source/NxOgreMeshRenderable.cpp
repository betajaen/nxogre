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
#include "NxOgreMeshRenderable.h"
#include "NxOgreMesh.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MeshRenderable::MeshRenderable(Mesh* mesh, float tearingfactor)
: mMesh(mesh)
{
 mStats = mMesh->getStats();
 configure(tearingfactor);
}

MeshRenderable::~MeshRenderable()
{
}

void MeshRenderable::configure(float tearingFactor)
{
 
 unsigned int growth = NxOgre::Math::ceil(tearingFactor);
 
 // Allocate memory for the vertex, normal, index and parent index buffers.
 vertices.set_capacity(int( float(mStats.getNbVertices()) * growth ));
 normals.set_capacity(int( float(mStats.getNbVertices()) * growth ));
 indexes.set_capacity(mStats.getNbIndices());
 parent_indexes.set_capacity(mStats.getNbIndices());
 
 // Allocate and Copy texture coordinates from mesh.
 texture_coordinates.set_capacity(mMesh->getNbTextureCoords() * growth);
 mMesh->getTextureCoords(texture_coordinates.texture_coords());
 
}

void MeshRenderable::getPhysXMeshData(NxMeshData& data)
{

 data.dirtyBufferFlagsPtr = 0;
 data.flags = 0;

 // vertices
 data.verticesPosBegin = vertices.vertices();
 data.verticesPosByteStride = sizeof(float) * 3;
 data.maxVertices = vertices.capacity();
 data.numVerticesPtr = vertices.count_ptr();

 // normals
 data.verticesNormalBegin = normals.normals();
 data.verticesNormalByteStride = sizeof(float) * 3;

 // indices
 data.indicesBegin = indexes.indexes();
 data.indicesByteStride = sizeof(unsigned int);
 data.maxIndices = indexes.capacity();
 data.numIndicesPtr = indexes.count_ptr();

 // parent indices
 data.parentIndicesBegin = parent_indexes.indexes();
 data.parentIndicesByteStride = sizeof(unsigned int);
 data.maxParentIndices = 0; // temp.
 data.numParentIndicesPtr = parent_indexes.count_ptr();

}

                                                                                       

} // namespace NxOgre

                                                                                       

