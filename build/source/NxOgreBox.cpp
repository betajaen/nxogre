/** File: NxOgreBox.cpp
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

NxShapeDesc* Box::create()
{
 NxBoxShapeDesc* box = new NxBoxShapeDesc();
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
  return Functions::XYZ<NxVec3, Vec3>(mBoxShape->getDimensions() * 2);
 }
 else
 {
  return Vec3(mBlueprint->mSize.x, mBlueprint->mSize.y, mBlueprint->mSize.z);
 }
}

void Box::setSize(const Vec3& vec)
{
 if (mBoxShape)
  mBoxShape->setDimensions(Functions::XYZ<Vec3, NxVec3>(vec * 0.5f));
 else
 {
  mBlueprint->mSize.x = vec.x;
  mBlueprint->mSize.y = vec.y;
  mBlueprint->mSize.z = vec.z;
 }
}

void Box::setSize(float w, float h, float d)
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

                                                                                       
