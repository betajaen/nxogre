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
   s.dimensions.x = box->mExtents.x;
   s.dimensions.y = box->mExtents.y;
   s.dimensions.z = box->mExtents.z;
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
 t.center.x = s.mCenter.x;
 t.center.y = s.mCenter.y;
 t.center.z = s.mCenter.z;
 t.extents.x = s.mExtents.x;
 t.extents.y = s.mExtents.y;
 t.extents.z = s.mExtents.z;
 t.rot.setColumnMajor(s.mRotation.ptr());
}

extern inline void NxBoxToSimpleBox(const NxBox& t, SimpleBox& s)
{
 s.mCenter.x = t.center.x;
 s.mCenter.y = t.center.y;
 s.mCenter.z = t.center.z;
 s.mExtents.x = t.extents.x;
 s.mExtents.y = t.extents.y;
 s.mExtents.z = t.extents.z;
 t.rot.getColumnMajor(s.mRotation.ptr());
}

extern void SimpleCapsuleToNxCapsule(const SimpleCapsule& s, NxCapsule& t)
{
 t.p0.x = s.mP0.x;
 t.p0.y = s.mP0.y;
 t.p0.z = s.mP0.z;

 t.p1.x = s.mP1.x;
 t.p1.y = s.mP1.y;
 t.p1.z = s.mP1.z;

 t.radius = s.Radius;
}

extern void NxCapsuleToSimpleCapsule(const NxCapsule& t, SimpleCapsule& s)
{
 s.mP0.x = t.p0.x;
 s.mP0.y = t.p0.y;
 s.mP0.z = t.p0.z;

 s.mP1.x = t.p1.x;
 s.mP1.y = t.p1.y;
 s.mP1.z = t.p1.z;

 s.Radius = t.radius;

}


                                                                                       

};

                                                                                       

} // namespace NxOgre

                                                                                       
