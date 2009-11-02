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
#include "NxOgreTriangleGeometry.h"
#include "NxOgreTriangleGeometryDescription.h"
#include "NxOgreMesh.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreFunctions.h"
#include "NxOgrePhysXUserEntityReport.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

TriangleGeometry::TriangleGeometry(NxTriangleMeshShape* shape, Mesh* mesh)
: Shape(shape), mTriangleMeshShape(shape), mMesh(mesh)
{
}

TriangleGeometry::~TriangleGeometry(void)
{
}

unsigned int TriangleGeometry::getShapeType() const
{
 return Classes::_TriangleGeometry;
}

Enums::ShapeFunctionType TriangleGeometry::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Mesh;
}

Mesh* TriangleGeometry::getTriangleMesh(void)
{
 return mMesh;
}

void TriangleGeometry::getTriangle(Triangle& out, unsigned int* flags, Index triangleIndex, bool worldSpaceTranslation, bool worldSpaceRotation)
{
 NxTriangle triangle;
 mTriangleMeshShape->getTriangle(triangle, 0, flags, triangleIndex, worldSpaceTranslation, worldSpaceRotation);
 out.mVertices[0] = triangle.verts[0];
 out.mVertices[1] = triangle.verts[1];
 out.mVertices[2] = triangle.verts[2];
}

void TriangleGeometry::getTriangle(Triangle& out, Triangle& outEdge, unsigned int* flags, Index triangleIndex, bool worldSpaceTranslation, bool worldSpaceRotation)
{
 NxTriangle triangle;
 NxTriangle edge;
 mTriangleMeshShape->getTriangle(triangle, &edge, flags, triangleIndex, worldSpaceTranslation, worldSpaceRotation);
 out.mVertices[0] = triangle.verts[0];
 out.mVertices[1] = triangle.verts[1];
 out.mVertices[2] = triangle.verts[2];
 outEdge.mVertices[0] = triangle.verts[0];
 outEdge.mVertices[1] = triangle.verts[1];
 outEdge.mVertices[2] = triangle.verts[2];
}

bool TriangleGeometry::overlapAAABTriangles(const Bounds3& bounds, unsigned int queryFlags, EntityReport<Index>* callback) const
{
 PhysXUserEntityReport<Index> report(callback);
 NxBounds3 nBounds;
 bounds.from<NxBounds3>(nBounds);
 
 return mTriangleMeshShape->overlapAABBTriangles(nBounds, queryFlags, &report);
}

bool TriangleGeometry::mapPageInstance(unsigned int pageIndex)
{
 return mTriangleMeshShape->mapPageInstance(pageIndex);
}

void TriangleGeometry::unmapPageInstance(unsigned int pageIndex)
{
 mTriangleMeshShape->unmapPageInstance(pageIndex);
}

bool TriangleGeometry::isPageInstanceMapped(unsigned int pageIndex) const
{
 return mTriangleMeshShape->isPageInstanceMapped(pageIndex);
}

void TriangleGeometry::saveToDescription(TriangleGeometryDescription& description)
{
 NxTriangleMeshShapeDesc desc;
 mTriangleMeshShape->saveToDesc(desc);
 description.mDensity = desc.density;
 description.mFlags = desc.shapeFlags;
 description.mGroup = desc.group;
 description.mGroupsMask.mBits0 = desc.groupsMask.bits0;
 description.mGroupsMask.mBits1 = desc.groupsMask.bits1;
 description.mGroupsMask.mBits2 = desc.groupsMask.bits2;
 description.mGroupsMask.mBits3 = desc.groupsMask.bits3;
 desc.localPose.getRowMajor44(description.mLocalPose.ptr());
 description.mMass = desc.mass;
 description.mMaterial = desc.materialIndex;
 description.mNonInteractingCompartmentTypes = desc.nonInteractingCompartmentTypes;
 description.mSkinWidth = desc.skinWidth;
 
 description.mMesh = mMesh;
 description.mMeshFlags = desc.meshFlags;
 description.mMeshPagingMode = Enums::MeshPagingMode(int(desc.meshPagingMode));
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
