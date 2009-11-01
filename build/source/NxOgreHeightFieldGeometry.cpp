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
#include "NxOgreHeightFieldGeometry.h"
#include "NxOgreHeightField.h"
#include "NxOgreHeightFieldGeometryDescription.h"
#include "NxOgrePhysXUserEntityReport.h"
#include "NxOgreFunctions.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

HeightFieldGeometry::HeightFieldGeometry(NxHeightFieldShape* shape, HeightField* heightfield)
: Shape(shape), mHeightFieldShape(shape), mHeightField(heightfield)
{
}

HeightFieldGeometry::~HeightFieldGeometry(void)
{
}

unsigned int HeightFieldGeometry::getShapeType() const
{
 return Classes::_HeightFieldGeometry;
}

Enums::ShapeFunctionType HeightFieldGeometry::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_HeightField;
}

HeightField* HeightFieldGeometry::getHeightField() const
{
 return mHeightField;
}

void  HeightFieldGeometry::setSize(const Vec3& size)
{
 mHeightFieldShape->setRowScale(size.x / Real(mHeightFieldShape->getHeightField().getNbRows()));
 mHeightFieldShape->setHeightScale(size.y / 32768.0f);
 mHeightFieldShape->setColumnScale(size.z / Real(mHeightFieldShape->getHeightField().getNbColumns()));
}

void  HeightFieldGeometry::setScale(const Vec3& scale)
{
 mHeightFieldShape->setRowScale(scale.x);
 mHeightFieldShape->setHeightScale(scale.y);
 mHeightFieldShape->setColumnScale(scale.z);
}

Real  HeightFieldGeometry::getHeightScale(void) const
{
 return mHeightFieldShape->getHeightScale();
}

Real  HeightFieldGeometry::getRowScale(void) const
{
 return mHeightFieldShape->getRowScale();
}

Real  HeightFieldGeometry::getColumnScale(void) const
{
 return mHeightFieldShape->getColumnScale();
}

void  HeightFieldGeometry::setHeightScale(Real scale)
{
 mHeightFieldShape->setHeightScale(scale);
}

void  HeightFieldGeometry::setRowScale(Real scale)
{
 mHeightFieldShape->setRowScale(scale);
}

void  HeightFieldGeometry::setColumnScale(Real scale)
{
 mHeightFieldShape->setColumnScale(scale);
}

bool  HeightFieldGeometry::overlapAAABTriangles(const Bounds3& bounds, unsigned int queryFlags, EntityReport<Index>* callback ) const
{
 PhysXUserEntityReport<Index> report(callback);
 NxBounds3 nBounds;
 nBounds.max = bounds.max.as<NxVec3>();
 nBounds.min = bounds.min.as<NxVec3>();
 
 return mHeightFieldShape->overlapAABBTriangles(nBounds, queryFlags, &report);
}

void  HeightFieldGeometry::getTriangle(Triangle& out, unsigned int* flags, Index index, bool worldTrans, bool worldRot )
{
 NxTriangle triangle;
 mHeightFieldShape->getTriangle(triangle, 0, flags, index, worldTrans, worldRot);
 out.mVertices[0].from<NxVec3>(triangle.verts[0]);
 out.mVertices[1].from<NxVec3>(triangle.verts[1]);
 out.mVertices[2].from<NxVec3>(triangle.verts[2]);
}

void  HeightFieldGeometry::getTriangle(Triangle& out, Triangle& outEdge, unsigned int* flags, Index index, bool worldTrans, bool worldRot )
{
 NxTriangle triangle;
 NxTriangle edge;
 mHeightFieldShape->getTriangle(triangle, &edge, flags, index, worldTrans, worldRot);
 out.mVertices[0].from<NxVec3>(triangle.verts[0]);
 out.mVertices[1].from<NxVec3>(triangle.verts[1]);
 out.mVertices[2].from<NxVec3>(triangle.verts[2]);
 outEdge.mVertices[0].from<NxVec3>(edge.verts[0]);
 outEdge.mVertices[1].from<NxVec3>(edge.verts[1]);
 outEdge.mVertices[2].from<NxVec3>(edge.verts[2]);
}

bool HeightFieldGeometry::isPointOnHeightField(const Vec2& vec)
{
 return mHeightFieldShape->isShapePointOnHeightField(vec.x, vec.y);
}

bool HeightFieldGeometry::isPointOnHeightField(Real x, Real z)
{
 return mHeightFieldShape->isShapePointOnHeightField(x, z);
}

MaterialIdentifier HeightFieldGeometry::getMaterialAt(const Vec2& vec)
{
 return mHeightFieldShape->getMaterialAtShapePoint(vec.x, vec.y);
}

MaterialIdentifier HeightFieldGeometry::getMaterialAt(Real x, Real z)
{
 return mHeightFieldShape->getMaterialAtShapePoint(x, z);
}

Vec3 HeightFieldGeometry::getNormalAt(Real x, Real z)
{
 return Vec3(mHeightFieldShape->getNormalAtShapePoint(x, z));
}

Vec3 HeightFieldGeometry::getNormalAt(const Vec2& vec)
{
 return Vec3(mHeightFieldShape->getNormalAtShapePoint(vec.x, vec.y));
}

Vec3 HeightFieldGeometry::getSmoothNormalAt(Real x, Real z)
{
 return Vec3(mHeightFieldShape->getSmoothNormalAtShapePoint(x, z));
}

Vec3 HeightFieldGeometry::getSmoothNormalAt(const Vec2& vec)
{
 return Vec3(mHeightFieldShape->getSmoothNormalAtShapePoint(vec.x, vec.y));
}


                                                                                       

} // namespace NxOgre

                                                                                       
