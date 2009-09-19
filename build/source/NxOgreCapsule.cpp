/** File: NxOgreCapsule.cpp
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
#include "NxOgreCapsule.h"
#include "NxOgreShapeBlueprint.h"
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Capsule::Capsule(Real radius, Real height, ShapeBlueprint* blueprint)
: Shape(blueprint)
{
 mBlueprint->mSize.x = radius;
 mBlueprint->mSize.y = height;
}

Capsule::~Capsule(void)
{
}

NxShapeDesc* Capsule::create()
{
 NxCapsuleShapeDesc* capsule = new NxCapsuleShapeDesc();
 Shape::createAbstract(capsule);
 
 capsule->radius = mBlueprint->mSize.x;
 capsule->height = mBlueprint->mSize.y;
 
 return capsule;
}

void Capsule::assign(NxShape* capsule)
{
 assignAbstract(capsule);
 mCapsuleShape = capsule->isCapsule();
}

Enums::ShapeFunctionType Capsule::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Capsule;
}

void Capsule::setDimensions(Real radius, Real height)
{
 if (mCapsuleShape)
 {
  mCapsuleShape->setDimensions(radius, height);
 }
 else
 {
  mBlueprint->mSize.x = radius;
  mBlueprint->mSize.y = height;
 }
}

void Capsule::setRadius(Real radius)
{
 if (mCapsuleShape)
 {
  mCapsuleShape->setRadius(radius);
 }
 else
 {
  mBlueprint->mSize.x = radius;
 }
}

void Capsule::setHeight(Real height)
{
 if (mCapsuleShape)
 {
  mCapsuleShape->setHeight(height);
 }
 else
 {
  mBlueprint->mSize.y = height;
 }
}

Real Capsule::getRadius(void) const
{
 if (mCapsuleShape)
 {
  return mCapsuleShape->getRadius();
 }
 else
 {
  return mBlueprint->mSize.x;
 }
}

Real Capsule::getHeight(void) const
{
 if (mCapsuleShape)
 {
  return mCapsuleShape->getHeight();
 }
 else
 {
  return mBlueprint->mSize.y;
 }
}

SimpleCapsule Capsule::getWorldCapsule(void)
{
 SimpleCapsule out;
 if (mCapsuleShape)
 {
  NxCapsule capsule;
  mCapsuleShape->getWorldCapsule(capsule);
  Functions::NxCapsuleToSimpleCapsule(capsule, out);
 }
 return out;
}


                                                                                       

} // namespace NxOgre

                                                                                       
