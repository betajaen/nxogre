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
#include "NxOgreShapeDescription.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Shape::Shape(NxShape* shape)
: mShape(shape), mNameHash(BLANK_HASH)
{
}

Shape::~Shape(void)
{
}

void Shape::destroy()
{
 mShape->getActor().releaseShape(*mShape);
}

Enums::ShapeFunctionType Shape::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Unknown;
}

NxShape* Shape::getAbstractShape() const
{
 return mShape;
}

StringHash Shape::getNameHash() const
{
 return mNameHash;
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
 Matrix44 matrix;
 mShape->getLocalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

void Shape::setLocalPose(const Matrix44& matrix)
{
 NxMat34 mat;
 mat.setRowMajor44(matrix.ptr());
 mShape->setLocalPose(mat);
}

Matrix44 Shape::getGlobalPose() const
{
 Matrix44 matrix;
 mShape->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

void Shape::setGlobalPose(const Matrix44& matrix)
{
 NxMat34 mat;
 mat.setRowMajor44(matrix.ptr());
 mShape->setGlobalPose(mat);
}

bool Shape::getFlag(Enums::ShapeFlags flag) const
{
 return bool(mShape->getFlag(NxShapeFlag(int(flag))));
}

void Shape::setFlag(Enums::ShapeFlags flag, bool b)
{
 mShape->setFlag(NxShapeFlag(int(flag)), b);
}

GroupIdentifier Shape::getGroup() const
{
 return mShape->getGroup();
}

void Shape::setGroup(const GroupIdentifier& identifier)
{
  mShape->setGroup(identifier);
}

MaterialIdentifier Shape::getMaterial() const
{
 return mShape->getMaterial();
}

void Shape::setMaterial(const MaterialIdentifier& identifier)
{
 mShape->setMaterial(identifier);
}


float Shape::getSkinWidth() const
{
 return mShape->getSkinWidth();
}

void Shape::setSkinWidth(const float& skin_width)
{
 mShape->setSkinWidth(skin_width);
}

GroupsMask Shape::getGroupMask() const
{
 NxGroupsMask mask = mShape->getGroupsMask();
 GroupsMask gm;
 gm.mBits0 = mask.bits0;
 gm.mBits1 = mask.bits1;
 gm.mBits2 = mask.bits2;
 gm.mBits3 = mask.bits3;
 return gm;
}

void Shape::setGroupMask(const int4& gm)
{
 if (mShape)
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
 return mShape->getNonInteractingCompartmentTypes();
}

void Shape::setInteractingCompartmentTypes(const int& types)
{
 mShape->setNonInteractingCompartmentTypes(types);
}

                                                                                       

} // namespace NxOgre

                                                                                       
