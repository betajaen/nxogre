/** File: NxOgreTriangleGeometry.cpp
    Created on: 15-Mar-09
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

                                                                                       
