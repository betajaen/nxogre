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
#include "NxOgreShapeDescription.h"
#include "NxOgreCapsuleDescription.h"
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Capsule::Capsule(NxCapsuleShape* shape, bool isDirty)
: Shape(shape, isDirty), mCapsuleShape(shape)
{
}

Capsule::~Capsule()
{
}

unsigned int Capsule::getShapeType() const
{
 return Classes::_Capsule;
}

Enums::ShapeFunctionType Capsule::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Capsule;
}

void Capsule::setDimensions(Real radius, Real height)
{
 mCapsuleShape->setDimensions(radius, height);
}

void Capsule::setRadius(Real radius)
{
 mCapsuleShape->setRadius(radius);
}

void Capsule::setHeight(Real height)
{
 mCapsuleShape->setHeight(height);
}

Real Capsule::getRadius() const
{
 return mCapsuleShape->getRadius();
}

Real Capsule::getHeight() const
{
 return mCapsuleShape->getHeight();
}

SimpleCapsule Capsule::getWorldCapsule()
{
 SimpleCapsule out;
 if (mCapsuleShape)
 {
  NxCapsule capsule;
  mCapsuleShape->getWorldCapsule(capsule);
  return SimpleCapsule(capsule);
 }
 return out;
}

void Capsule::saveToDescription(CapsuleDescription& description)
{
 NxCapsuleShapeDesc desc;
 mCapsuleShape->saveToDesc(desc);
 description.mDensity = desc.density;
 description.mFlags.from_i(desc.shapeFlags);
 description.mGroup = desc.group;
 description.mGroupsMask.bits0 = desc.groupsMask.bits0;
 description.mGroupsMask.bits1 = desc.groupsMask.bits1;
 description.mGroupsMask.bits2 = desc.groupsMask.bits2;
 description.mGroupsMask.bits3 = desc.groupsMask.bits3;
 desc.localPose.getRowMajor44(description.mLocalPose.ptr());
 description.mMass = desc.mass;
 description.mMaterial = desc.materialIndex;
 description.mNonInteractingCompartmentTypes = desc.nonInteractingCompartmentTypes;
 description.mSkinWidth = desc.skinWidth;

 description.mRadius = mCapsuleShape->getRadius();
 description.mHeight = mCapsuleShape->getHeight();
}

String Capsule::to_s() const
{
 return String("Capsule");
}

                                                                                       

} // namespace NxOgre

                                                                                       
