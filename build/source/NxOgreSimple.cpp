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

                                                                                       

namespace Functions
{

                                                                                       

extern inline void SimpleShapeToActorDescription(NxActorDesc& description, SimpleShape* shape)
{
 switch(shape->mType)
 {
  case NxOgre::Enums::SimpleShape_Box:
  {
   SimpleBox* box = (SimpleBox*) shape;
   NxBoxShapeDesc s;
   s.dimensions = box->mSize.as<NxVec3>();
   s.localPose.t = box->mCenter.as<NxVec3>();
   s.localPose.M.getRowMajor(box->mRotation.ptr());
   description.shapes.push_back(&s);
  }
  break;
  case NxOgre::Enums::SimpleShape_Sphere:
  {
   SimpleSphere* sphere = (SimpleSphere*) shape;
   NxSphereShapeDesc s;
   s.radius = sphere->mRadius;
   description.shapes.push_back(&s);
  }
  break;

 }
}

                                                                                       

} // namespace Functions

                                                                                       

SimplePlane::SimplePlane()
: mNormal(0,1,0), mDistance(0)
{ // constructor.
}

SimplePlane::SimplePlane(const Vec3& normal, float distance)
: mNormal(normal), mDistance(distance)
{ // constructor.
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

SimpleCapsule::SimpleCapsule()
: mRadius(0)
{
}

SimpleCapsule::SimpleCapsule(Real radius, const Vec3& p0, const Vec3& p1)
: mRadius(radius), mP0(p0), mP1(p1)
{ // constructor.
}


SimpleCapsule::SimpleCapsule(const NxCapsule& capsule)
{
 mP0.from<NxVec3>(capsule.p0);
 mP1.from<NxVec3>(capsule.p1);
 mRadius = capsule.radius;
}

NxCapsule SimpleCapsule::to_capsule() const
{
 NxCapsule capsule;
 capsule.p0.set(mP0.as<NxVec3>());
 capsule.p1.set(mP1.as<NxVec3>());
 capsule.radius = mRadius;
 return capsule;
}

                                                                                       

} // namespace NxOgre

                                                                                       
