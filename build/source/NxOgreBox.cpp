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
#include "NxOgreBox.h"
#include "NxOgreShapeBlueprint.h"
#include "NxOgreFunctions.h"
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Box::Box(Real whd_dimensions, ShapeBlueprint* blueprint)
: Shape(blueprint)
{
 mBlueprint->mSize.set(0, whd_dimensions, whd_dimensions, whd_dimensions);
}

Box::Box(Real w, Real h, Real d, ShapeBlueprint* blueprint)
: Shape(blueprint)
{
 mBlueprint->mSize.set(0,w,h,d);
}

Box::Box(const Vec3& r, ShapeBlueprint* blueprint)
: Shape(blueprint)
{
 mBlueprint->mSize.set(0, r.x, r.y, r.z);
}

Box::~Box(void)
{
}

unsigned int Box::getShapeType() const
{
 return Classes::_Box;
}

NxShapeDesc* Box::create()
{
 NxBoxShapeDesc* box = NxOgre_New(NxBoxShapeDesc)();
 Shape::createAbstract(box);
 
 box->dimensions.set(mBlueprint->mSize.x * 0.5, mBlueprint->mSize.y * 0.5, mBlueprint->mSize.z * 0.5);

 return box;
}

void Box::assign(NxShape* box)
{
 assignAbstract(box);
 mBoxShape = box->isBox();
}

Enums::ShapeFunctionType Box::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Box;
}

Vec3 Box::getSize() const
{
 if (mBoxShape)
 {
  return Vec3(mBoxShape->getDimensions() * 2);
 }
 else
 {
  return Vec3(mBlueprint->mSize.x, mBlueprint->mSize.y, mBlueprint->mSize.z);
 }
}

void Box::setSize(const Vec3& vec)
{
 if (mBoxShape)
  mBoxShape->setDimensions((vec * 0.5f).as<NxVec3>());
 else
 {
  mBlueprint->mSize.x = vec.x;
  mBlueprint->mSize.y = vec.y;
  mBlueprint->mSize.z = vec.z;
 }
}

void Box::setSize(Real w, Real h, Real d)
{
 if (mBoxShape)
  mBoxShape->setDimensions(NxVec3(w * 0.5, h * 0.5, d * 0.5));
 else
 {
  mBlueprint->mSize.x = w;
  mBlueprint->mSize.y = h;
  mBlueprint->mSize.z = d;
 }
}

SimpleBox Box::getWorldOBB(void)
{
 SimpleBox box;
 
 if (mBoxShape)
 {
  NxBox obb;
  mBoxShape->getWorldOBB(obb);
  Functions::NxBoxToSimpleBox(obb, box);
 }
 
 return box;
}

                                                                                       

} // namespace NxOgre

                                                                                       
