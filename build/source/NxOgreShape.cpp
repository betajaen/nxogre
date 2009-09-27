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
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Shape::Shape(ShapeBlueprint* blueprint)
: mBlueprint(blueprint), mShape(0)
{
}

Shape::~Shape(void)
{
 if (mBlueprint)
  delete mBlueprint;
}

Enums::ShapeFunctionType Shape::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Unknown;
}

void Shape::reset()
{
  mBlueprint->reset();
}

ShapeBlueprint* Shape::getBlueprint()
{
 return mBlueprint;
}

bool Shape::isAttached() const
{
 return mShape != 0;
}

String Shape::getName() const
{
 return mName;
}

void Shape::setName(const String& name)
{
 mName = name;
}

Matrix44 Shape::getLocalPose() const
{
 if (mBlueprint)
 {
  return mBlueprint->mLocalPose;
 }
 
 Matrix44 matrix;
 mShape->getLocalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

void Shape::setLocalPose(const Matrix44& matrix)
{
 if (mBlueprint)
 {
  mBlueprint->mLocalPose = matrix;
 }
 else
 {
  NxMat34 mat;
  mat.setRowMajor44(matrix.ptr());
  mShape->setLocalPose(mat);
 }
}

Matrix44 Shape::getGlobalPose() const
{
 if (mBlueprint)
 {
  return Matrix44::ZERO;
 }
 
 Matrix44 matrix;
 mShape->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

void Shape::setGlobalPose(const Matrix44& matrix)
{
 if (mBlueprint)
 {}
 else
 {
  NxMat34 mat;
  mat.setRowMajor44(matrix.ptr());
  mShape->setGlobalPose(mat);
 }
}

bool Shape::getFlag(Enums::ShapeFlags flag) const
{
 if (mBlueprint)
 {
  return bool(mBlueprint->mFlags & flag); // I think.
 }
 return bool(mShape->getFlag(NxShapeFlag(int(flag))));
}

void Shape::setFlag(Enums::ShapeFlags flag, bool b)
{
 if (mBlueprint)
  if (b)
   mBlueprint->mFlags |= flag;
  else
   mBlueprint->mFlags ^= flag; // I think.
 else
  mShape->setFlag(NxShapeFlag(int(flag)), b);
}

GroupIdentifier Shape::getGroup() const
{
 if (mBlueprint)
  return mBlueprint->mGroup;
 else
  return mShape->getGroup();
}

void Shape::setGroup(const GroupIdentifier& identifier)
{
 if (mBlueprint)
  mBlueprint->mGroup = identifier;
 else
  mShape->setGroup(identifier);
}

MaterialIdentifier Shape::getMaterial() const
{
 if (mBlueprint)
  return mBlueprint->mMaterial;
 else
  return mShape->getMaterial();
}

void Shape::setMaterial(const MaterialIdentifier& identifier)
{
 if (mBlueprint)
  mBlueprint->mMaterial = identifier;
 else
  mShape->setMaterial(identifier);
}

Real Shape::getDensity() const
{
 if (mBlueprint)
  return mBlueprint->mDensity;
 return 0;
}

void Shape::setDensity(const float& density)
{
 if (mBlueprint)
  mBlueprint->mDensity = density;
}

Real Shape::getMass() const
{
 if (mBlueprint)
  return mBlueprint->mMass;
 return 0;
}

void Shape::setMass(const float& mass)
{
 if (mBlueprint)
  mBlueprint->mMass = mass;
}

float Shape::getSkinWidth() const
{
 if (mBlueprint)
  return mBlueprint->mSkinWidth;
 else
  return mShape->getSkinWidth();
}

void Shape::setSkinWidth(const float& skin_width)
{
 if (mBlueprint)
  mShape->setSkinWidth(skin_width);
}

int4 Shape::getGroupMask() const
{
 if (mBlueprint)
  return mBlueprint->mGroupsMask;
 else
 {
  NxGroupsMask mask = mShape->getGroupsMask();
  int4 gm;
  gm.w = mask.bits0;
  gm.x = mask.bits1;
  gm.y = mask.bits2;
  gm.z = mask.bits3;
  return gm;
 }
}

void Shape::setGroupMask(const int4& gm)
{
 if (mBlueprint)
  mBlueprint->mGroupsMask = gm;
 else
 {
  NxGroupsMask mask;
  mask.bits0 = gm.w;
  mask.bits1 = gm.x;
  mask.bits2 = gm.y;
  mask.bits3 = gm.z;
  mShape->setGroupsMask(mask);
 }
}

int Shape::getInteractingCompartmentTypes() const
{
 if (mBlueprint)
  return mBlueprint->mShapesCompartmentTypes;
 else
  return mShape->getNonInteractingCompartmentTypes();
}

void Shape::setInteractingCompartmentTypes(const int& types)
{
 if (mBlueprint)
  mBlueprint->mShapesCompartmentTypes = types;
 else
  mShape->setNonInteractingCompartmentTypes(types);
}

void Shape::createAbstract(NxShapeDesc* x)
{
 x->ccdSkeleton = 0; //< \will_be mSkeleton->getAsSkeleton();
 x->density = mBlueprint->mDensity;
 x->group = mBlueprint->mGroup;
 x->groupsMask.bits0 = mBlueprint->mGroupsMask.w;
 x->groupsMask.bits1 = mBlueprint->mGroupsMask.x;
 x->groupsMask.bits2 = mBlueprint->mGroupsMask.y;
 x->groupsMask.bits3 = mBlueprint->mGroupsMask.z;
 x->localPose.setRowMajor44(mBlueprint->mLocalPose.ptr());
 x->mass = mBlueprint->mMass;
 x->materialIndex = mBlueprint->mMaterial;
 x->name = mName.c_str();
 x->nonInteractingCompartmentTypes = mBlueprint->mShapesCompartmentTypes;
 x->shapeFlags = mBlueprint->mFlags;
 x->skinWidth = mBlueprint->mSkinWidth;
}


void Shape::assignAbstract(NxShape* shape)
{
 mShape = shape;
}

NxShape* Shape::getAbstractShape()
{
 return mShape;
}

                                                                                       

} // namespace NxOgre

                                                                                       
