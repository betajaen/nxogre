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

extern inline void SimpleBoxToNxBox(const SimpleBox& s, NxBox& t)
{
}

extern inline void NxBoxToSimpleBox(const NxBox& t, SimpleBox& s)
{
}

extern inline void SimpleSphereToNxSphere(const SimpleSphere& s , NxSphere& t)
{
}

extern inline void NxSphereToSimpleSphere(const NxSphere& s, SimpleSphere& t)
{
}

extern void SimpleCapsuleToNxCapsule(const SimpleCapsule& s, NxCapsule& t)
{
}

extern void NxCapsuleToSimpleCapsule(const NxCapsule& t, SimpleCapsule& s)
{
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

SimpleBox::SimpleBox(const NxBox& box)
{
 mSize.from<NxVec3>(box.extents);
 mCenter.from<NxVec3>(box.center);
 box.rot.getRowMajor(mRotation.ptr());
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

NxBox SimpleBox::to_box() const
{
 NxBox box;
 box.center.set(mCenter.as<NxVec3>());
 box.rot.setRowMajor(mRotation.ptr());
 box.extents.set(mSize.as<NxVec3>());
 return box;
}

SimpleSphere::SimpleSphere()
{
}

SimpleSphere::SimpleSphere(Real radius, const Vec3& position)
: mRadius(radius)
{
 mPose.set(position);
}

SimpleCapsule::SimpleCapsule()
: mRadius(0), mHeight(0)
{
}

SimpleCapsule::SimpleCapsule(Real height, Real radius, const Vec3& position, const Quat& orientation)
: mRadius(0), mHeight(0)
{ // constructor.
 mPose.set(position);
 mPose.set(orientation);
}

SimpleCapsule::SimpleCapsule(Real height, Real radius, const Matrix44& pose)
: mRadius(0), mHeight(0)
{ // constructor.
 mPose.set(pose);
}


                                                                                       

} // namespace NxOgre

                                                                                       
