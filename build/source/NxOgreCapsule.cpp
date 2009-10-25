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

unsigned int Capsule::getShapeType() const
{
 return Classes::_Capsule;
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

                                                                                       
