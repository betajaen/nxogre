/** File: NxOgreHeightFieldGeometry.cpp
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
#include "NxOgreHeightFieldGeometry.h"
#include "NxOgreHeightField.h"
#include "NxOgreHeightFieldGeometryBlueprint.h"
#include "NxOgrePhysXUserEntityReport.h"
#include "NxOgreFunctions.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

HeightFieldGeometry::HeightFieldGeometry(HeightField* heightfield, const Vec3& size, HeightFieldGeometryBlueprint* blueprint)
: Shape(blueprint), mHeightField(0), mHeightFieldShape(0)
{

 blueprint->mHeightField = heightfield;

 blueprint->mSize.x = size.x  / Real(blueprint->mHeightField->getHeightField()->getNbRows());
 blueprint->mSize.y = size.y  / 32768.0f;
 blueprint->mSize.z = size.z  / Real(blueprint->mHeightField->getHeightField()->getNbColumns());

 blueprint->mTerrainCentering = Enums::TerrainCentering_LocalPose;
 blueprint->mSmoothSphereCollisions;
 blueprint->mHoleMaterial = 65535;
 blueprint->mHighBits = 0;
}

HeightFieldGeometry::HeightFieldGeometry(HeightField* heightfield,  HeightFieldGeometryBlueprint* blueprint)
: Shape(blueprint), mHeightField(0), mHeightFieldShape(0)
{

 blueprint->mHeightField = heightfield;

 blueprint->mTerrainCentering = Enums::TerrainCentering_LocalPose;
 blueprint->mSmoothSphereCollisions;
 blueprint->mHoleMaterial = 65535;
 blueprint->mHighBits = 0;
}

HeightFieldGeometry::~HeightFieldGeometry(void)
{
}

NxShapeDesc* HeightFieldGeometry::create(void)
{
 NxHeightFieldShapeDesc* heightfield = new NxHeightFieldShapeDesc();
 createAbstract(heightfield);

 HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);

 heightfield->heightField = blueprint->mHeightField->getHeightField();

 heightfield->rowScale    = blueprint->mSize.x;
 heightfield->heightScale = blueprint->mSize.y;
 heightfield->columnScale = blueprint->mSize.z;

 heightfield->holeMaterial = blueprint->mHoleMaterial;
 heightfield->materialIndexHighBits = blueprint->mHighBits;
 heightfield->meshFlags = blueprint->mMeshFlags;

 if (blueprint->mSmoothSphereCollisions)
  heightfield->meshFlags |= NX_MESH_SMOOTH_SPHERE_COLLISIONS;

 if (blueprint->mTerrainCentering == Enums::TerrainCentering_CenterXZ)
 {
  heightfield->localPose.t.x = -(blueprint->mSize.x * 0.5f);
  heightfield->localPose.t.z = -(blueprint->mSize.z * 0.5f);
 }
 else if (blueprint->mTerrainCentering == Enums::TerrainCentering_CenterAbove)
 {
  heightfield->localPose.t.x = -(blueprint->mSize.x * 0.5f);
  heightfield->localPose.t.y = blueprint->mSize.y;
  heightfield->localPose.t.z = -(blueprint->mSize.z * 0.5f);
 }

 return heightfield;
}

void HeightFieldGeometry::assign(NxShape* heightfield)
{
 assignAbstract(heightfield);
 mHeightFieldShape = heightfield->isHeightField();
}

Enums::ShapeFunctionType HeightFieldGeometry::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_HeightField;
}


HeightField* HeightFieldGeometry::getHeightField() const
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  return blueprint->mHeightField;
 }
 else
 {
  return mHeightField;
 }
}

Enums::TerrainCentering HeightFieldGeometry::getTerrainCentering() const
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  return blueprint->mTerrainCentering;
 }
 else
 {
  return Enums::TerrainCentering_LocalPose;
 }
}

bool HeightFieldGeometry::getSmoothSphereCollisions() const
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  return blueprint->mSmoothSphereCollisions;
 }
 else
 {
  return false;
 }
}

MaterialIdentifier HeightFieldGeometry::getHoleMaterial() const
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  return blueprint->mHoleMaterial;
 }
 return 0;
}

MaterialIdentifier HeightFieldGeometry::getHighBits() const
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  return blueprint->mHighBits;
 }
 return 0;
}

void HeightFieldGeometry::setHeightField(HeightField* hf)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mHeightField = hf;
 }
}

void HeightFieldGeometry::setTerrainCentering(Enums::TerrainCentering tc)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mTerrainCentering = tc;
 }
}

void HeightFieldGeometry::setSmoothSphereCollisions(bool ssc)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mSmoothSphereCollisions = ssc;
 }
}

void HeightFieldGeometry::setHoleMaterial(MaterialIdentifier identifier)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mHoleMaterial = identifier;
 }
}

void HeightFieldGeometry::setHighBits(MaterialIdentifier identifier)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mHighBits = identifier;
 }
}

void  HeightFieldGeometry::setSize(const Vec3& size)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mSize.x = size.x  / Real(blueprint->mHeightField->getHeightField()->getNbRows());
  blueprint->mSize.y = size.y  / Real(blueprint->mHeightField->getHeightField()->getNbColumns());
  blueprint->mSize.z = size.z  / 32768.0f;
 }
 else
 {
  mHeightFieldShape->setRowScale(size.x  / Real(mHeightFieldShape->getHeightField().getNbRows()));
  mHeightFieldShape->setHeightScale(size.y  / Real(mHeightFieldShape->getHeightField().getNbColumns()));
  mHeightFieldShape->setColumnScale(size.z  / 32768.0f);
 }
}

void  HeightFieldGeometry::setScale(const Vec3& scale)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mSize.x = scale.x;
  blueprint->mSize.y = scale.y;
  blueprint->mSize.z = scale.z;
 }
 else
 {
  mHeightFieldShape->setRowScale(scale.x);
  mHeightFieldShape->setHeightScale(scale.y);
  mHeightFieldShape->setColumnScale(scale.z);
 }
}

Real  HeightFieldGeometry::getHeightScale(void) const
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  return blueprint->mSize.y;
 }
 else
  return mHeightFieldShape->getHeightScale();
}

Real  HeightFieldGeometry::getRowScale(void) const
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  return blueprint->mSize.x;
 }
 else
  return mHeightFieldShape->getRowScale();
}

Real  HeightFieldGeometry::getColumnScale(void) const
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  return blueprint->mSize.z;
 }
 else
  return mHeightFieldShape->getColumnScale();
}

void  HeightFieldGeometry::setHeightScale(Real scale)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mSize.y = scale;
 }
 else
  mHeightFieldShape->setHeightScale(scale);
}

void  HeightFieldGeometry::setRowScale(Real scale)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mSize.x = scale;
 }
 else
  mHeightFieldShape->setRowScale(scale);
}

void  HeightFieldGeometry::setColumnScale(Real scale)
{
 if (mBlueprint)
 {
  HeightFieldGeometryBlueprint* blueprint = static_cast<HeightFieldGeometryBlueprint*>(mBlueprint);
  blueprint->mSize.z = scale;
 }
 else
  mHeightFieldShape->setColumnScale(scale);
}

bool  HeightFieldGeometry::overlapAAABTriangles(const Bounds3& bounds, unsigned int queryFlags, EntityReport<Index>* callback ) const
{
 if (mHeightFieldShape == 0)
  return false;
 
 PhysXUserEntityReport<Index> report(callback);
 NxBounds3 nBounds;
 Functions::XYZ<Vec3, NxVec3>(bounds.max, nBounds.max);
 Functions::XYZ<Vec3, NxVec3>(bounds.min, nBounds.min);
 
 return mHeightFieldShape->overlapAABBTriangles(nBounds, queryFlags, &report);
}

void  HeightFieldGeometry::getTriangle(Triangle& out, unsigned int* flags, Index index, bool worldTrans, bool worldRot )
{
 NxTriangle triangle;
 mHeightFieldShape->getTriangle(triangle, 0, flags, index, worldTrans, worldRot);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[0], out.mVertices[0]);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[1], out.mVertices[1]);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[2], out.mVertices[2]);
}

void  HeightFieldGeometry::getTriangle(Triangle& out, Triangle& outEdge, unsigned int* flags, Index index, bool worldTrans, bool worldRot )
{
 NxTriangle triangle;
 NxTriangle edge;
 mHeightFieldShape->getTriangle(triangle, &edge, flags, index, worldTrans, worldRot);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[0], out.mVertices[0]);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[1], out.mVertices[1]);
 Functions::XYZ<NxVec3, Vec3>(triangle.verts[2], out.mVertices[2]);
 Functions::XYZ<NxVec3, Vec3>(edge.verts[0], outEdge.mVertices[0]);
 Functions::XYZ<NxVec3, Vec3>(edge.verts[1], outEdge.mVertices[1]);
 Functions::XYZ<NxVec3, Vec3>(edge.verts[2], outEdge.mVertices[2]);
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
 if (mHeightFieldShape == 0)
  return 0xFFFF;
 
 return mHeightFieldShape->getMaterialAtShapePoint(vec.x, vec.y);
}

MaterialIdentifier HeightFieldGeometry::getMaterialAt(Real x, Real z)
{
 if (mHeightFieldShape == 0)
  return 0xFFFF;
 
 return mHeightFieldShape->getMaterialAtShapePoint(x, z);
}

Vec3 HeightFieldGeometry::getNormalAt(Real x, Real z)
{
 if (mHeightFieldShape == 0)
  return Vec3::ZERO;
 
 return Functions::XYZ<NxVec3, Vec3>(mHeightFieldShape->getNormalAtShapePoint(x, z));
}

Vec3 HeightFieldGeometry::getNormalAt(const Vec2& vec)
{
 if (mHeightFieldShape == 0)
  return Vec3::ZERO;
 
 return Functions::XYZ<NxVec3, Vec3>(mHeightFieldShape->getNormalAtShapePoint(vec.x, vec.y));
}

Vec3 HeightFieldGeometry::getSmoothNormalAt(Real x, Real z)
{
 if (mHeightFieldShape == 0)
  return Vec3::ZERO;
 
 return Functions::XYZ<NxVec3, Vec3>(mHeightFieldShape->getSmoothNormalAtShapePoint(x, z));
}

Vec3 HeightFieldGeometry::getSmoothNormalAt(const Vec2& vec)
{
 if (mHeightFieldShape == 0)
  return Vec3::ZERO;
 
 return Functions::XYZ<NxVec3, Vec3>(mHeightFieldShape->getSmoothNormalAtShapePoint(vec.x, vec.y));
}


                                                                                       

} // namespace NxOgre

                                                                                       
