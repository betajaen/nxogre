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
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

NxForceFieldShapeDesc* SimpleShape::to_ff_shape() const
{
 return 0;
}

SimplePlane::SimplePlane()
: mNormal(0,1,0), mDistance(0)
{ // constructor.
}

SimplePlane::SimplePlane(const Vec3& normal, float distance)
: mNormal(normal), mDistance(distance)
{ // constructor.
}

NxForceFieldShapeDesc* SimplePlane::to_ff_shape() const
{
 return 0;
}

Enums::SimpleShapeType SimplePlane::getType() const
{
 return Enums::SimpleShape_Plane;
}




SimpleBox::SimpleBox()
{ // constructor.
 mSize.zero();
 mRotation.identity();
}

SimpleBox::SimpleBox(const Vec3& size, const Vec3& position, const Quat& orientation)
: mSize(size)
{ // constructor.
 mCenter.set(position);
 mRotation.set(orientation);
}

SimpleBox::SimpleBox(const Vec3& size, const Vec3& position, const Matrix33& rotation)
: mSize(size), mCenter(position), mRotation(rotation)
{ // constructor.
}

SimpleBox::SimpleBox(const NxBox& box)
{
 mSize.from<NxVec3>(box.extents);
 mCenter.from<NxVec3>(box.center);
 box.rot.getRowMajor(mRotation.ptr());
}

SimpleBox::SimpleBox(const Bounds3& aabb, const Matrix44& trans)
{
 SimpleBox out;
 NxBounds3 bounds;
 bounds.max.x = aabb.max.x;
 bounds.max.y = aabb.max.y;
 bounds.max.z = aabb.max.z;
 bounds.min.x = aabb.min.x;
 bounds.min.y = aabb.min.y;
 bounds.min.z = aabb.min.z;
 NxMat34 mat;
 mat.setColumnMajor44(trans.ptr());
 NxBox box;
 NxGetUtilLib()->NxCreateBox(box, bounds, mat);
 mSize.from<NxVec3>(box.extents);
 mCenter.from<NxVec3>(box.center);
 box.rot.getRowMajor(mRotation.ptr());
}

bool SimpleBox::contains(const Vec3& point) const
{
 return NxGetUtilLib()->NxBoxContainsPoint(to_box(), point.as<NxVec3>());
}

NxBox SimpleBox::to_box() const
{
 NxBox box;
 box.center.set(mCenter.as<NxVec3>());
 box.rot.setRowMajor(mRotation.ptr());
 box.extents.set(mSize.as<NxVec3>());
 return box;
}

NxForceFieldShapeDesc*  SimpleBox::to_ff_shape() const
{
 NxBoxForceFieldShapeDesc* shape = NXOGRE_NEW_PHYSX(NxBoxForceFieldShapeDesc, PhysXClassAllocator);
 shape->dimensions.set(mSize.as<NxVec3>());
 shape->pose.t.set(mCenter.as<NxVec3>());
 shape->pose.M.setColumnMajor(mRotation.ptr());
 return shape;
}

Enums::SimpleShapeType SimpleBox::getType() const
{
 return Enums::SimpleShape_Box;
}




SimpleSphere::SimpleSphere()
{ // constructor.
}

SimpleSphere::SimpleSphere(Real radius, const Vec3& center)
: mRadius(radius), mCenter(center)
{ // constructor.
}

SimpleSphere::SimpleSphere(const NxSphere& sphere)
: mRadius(sphere.radius)
{
 mCenter.from<NxVec3>(sphere.center);
}

NxSphere SimpleSphere::to_sphere() const
{
 NxSphere sphere;
 sphere.center.set(mCenter.as<NxVec3>());
 sphere.radius = mRadius;
 return sphere;
}

NxForceFieldShapeDesc* SimpleSphere::to_ff_shape() const
{
 NxSphereForceFieldShapeDesc* shape = NXOGRE_NEW_PHYSX(NxSphereForceFieldShapeDesc, PhysXClassAllocator);
 shape->pose.t.set(mCenter.as<NxVec3>());
 shape->radius = mRadius;
 return shape;
}

Enums::SimpleShapeType SimpleSphere::getType() const
{
 return Enums::SimpleShape_Sphere;
}




SimpleCapsule::SimpleCapsule()
: mRadius(0)
{
}

SimpleCapsule::SimpleCapsule(Real radius, const Vec3& p0, const Vec3& p1)
: mRadius(radius), mP0(p0), mP1(p1)
{ // constructor.
}

SimpleCapsule::SimpleCapsule(const Vec3& origin, const Vec3& direction, Real radius)
{ // constructor.
 mP0 = mP1 = origin;
 mP1 += direction;
}

SimpleCapsule::SimpleCapsule(const NxCapsule& capsule)
{
 mP0.from<NxVec3>(capsule.p0);
 mP1.from<NxVec3>(capsule.p1);
 mRadius = capsule.radius;
}

Vec3 SimpleCapsule::getOrigin()
{
 return mP0;
}

Vec3 SimpleCapsule::getDirection()
{
 return mP1 - mP0;
}

NxCapsule SimpleCapsule::to_capsule() const
{
 NxCapsule capsule;
 capsule.p0.set(mP0.as<NxVec3>());
 capsule.p1.set(mP1.as<NxVec3>());
 capsule.radius = mRadius;
 return capsule;
}

NxForceFieldShapeDesc* SimpleCapsule::to_ff_shape() const
{
 return 0;
 /*
 NxCapsule cap;
 
 NxCapsuleForceFieldShapeDesc* shape = NXOGRE_NEW_PHYSX(NxCapsuleForceFieldShapeDesc, PhysXClassAllocator);
 //shape->pose.t.set(.as<NxVec3>());
 //shape->pose.M.fromQuat(NxQuat()));
 shape->radius = mRadius;
 return shape;*/
}

Enums::SimpleShapeType SimpleCapsule::getType() const
{
 return Enums::SimpleShape_Capsule;
}



SimpleConvexPointCloud::SimpleConvexPointCloud()
{ // empty constructor.
}

SimpleConvexPointCloud::~SimpleConvexPointCloud()
{ // empty destructor.
}

Enums::SimpleShapeType  SimpleConvexPointCloud::getType() const
{
 return Enums::SimpleShape_ConvexPointCloud;
}

NxForceFieldShapeDesc*  SimpleConvexPointCloud::to_ff_shape() const
{
 return 0;
}

                                                                                       

} // namespace NxOgre

                                                                                       
