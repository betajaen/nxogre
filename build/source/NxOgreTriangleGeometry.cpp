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
#include "NxOgreMesh.h"
#include "NxOgreShapeBlueprint.h"
#include "NxOgreFunctions.h"
#include "NxOgrePhysXUserEntityReport.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

TriangleGeometry::TriangleGeometry(Mesh* mesh, ShapeBlueprint* blueprint)
: Shape(blueprint)
{
 mBlueprint->mMesh = mesh;
}

TriangleGeometry::~TriangleGeometry(void)
{
}

unsigned int TriangleGeometry::getShapeType() const
{
 return Classes::_TriangleGeometry;
}

NxShapeDesc* TriangleGeometry::create()
{
 NxTriangleMeshShapeDesc* trimesh = new NxTriangleMeshShapeDesc();

 createAbstract(trimesh);

 trimesh->meshData = mBlueprint->mMesh->getAsTriangleMesh();
 trimesh->meshFlags = mBlueprint->mMeshFlags;

 return trimesh;
}

void TriangleGeometry::assign(NxShape* trimesh)
{
 assignAbstract(trimesh);
 mMesh = mBlueprint->mMesh;
 mTriangleMeshShape = trimesh->isTriangleMesh();
}

Enums::ShapeFunctionType TriangleGeometry::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Mesh;
}

Mesh* TriangleGeometry::getTriangleMesh(void)
{
 if (mBlueprint)
  return mBlueprint->mMesh;
 return mMesh;
}

void TriangleGeometry::getTriangle(Triangle& out, unsigned int* flags, Index triangleIndex, bool worldSpaceTranslation, bool worldSpaceRotation)
{
 NxTriangle triangle;
 mTriangleMeshShape->getTriangle(triangle, 0, flags, triangleIndex, worldSpaceTranslation, worldSpaceRotation);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[0], out.mVertices[0]);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[1], out.mVertices[1]);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[2], out.mVertices[2]);
}

void TriangleGeometry::getTriangle(Triangle& out, Triangle& outEdge, unsigned int* flags, Index triangleIndex, bool worldSpaceTranslation, bool worldSpaceRotation)
{
 NxTriangle triangle;
 NxTriangle edge;
 mTriangleMeshShape->getTriangle(triangle, &edge, flags, triangleIndex, worldSpaceTranslation, worldSpaceRotation);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[0], out.mVertices[0]);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[1], out.mVertices[1]);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[2], out.mVertices[2]);
 Functions::XYZ<NxVec3, Vec3>(edge.verts[0], outEdge.mVertices[0]);
 Functions::XYZ<NxVec3, Vec3>(edge.verts[1], outEdge.mVertices[1]);
 Functions::XYZ<NxVec3, Vec3>(edge.verts[2], outEdge.mVertices[2]);
}


bool TriangleGeometry::overlapAAABTriangles(const Bounds3& bounds, unsigned int queryFlags, EntityReport<Index>* callback) const
{
 if (mTriangleMeshShape == 0)
  return false;
 
 PhysXUserEntityReport<Index> report(callback);
 NxBounds3 nBounds;
 Functions::XYZ<Vec3, NxVec3>(bounds.max, nBounds.max);
 Functions::XYZ<Vec3, NxVec3>(bounds.min, nBounds.min);
 
 return mTriangleMeshShape->overlapAABBTriangles(nBounds, queryFlags, &report);
}

bool TriangleGeometry::mapPageInstance(unsigned int pageIndex)
{
 if (mTriangleMeshShape == 0)
  return false;

 return mTriangleMeshShape->mapPageInstance(pageIndex);
}

void TriangleGeometry::unmapPageInstance(unsigned int pageIndex)
{
 if (mTriangleMeshShape == 0)
  return;

 mTriangleMeshShape->unmapPageInstance(pageIndex);
}

bool TriangleGeometry::isPageInstanceMapped(unsigned int pageIndex) const
{
 if (mTriangleMeshShape == 0)
  return false;

 return mTriangleMeshShape->isPageInstanceMapped(pageIndex);
}

                                                                                       

} // namespace NxOgre

                                                                                       
