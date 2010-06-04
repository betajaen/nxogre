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
#include "NxOgreShapeDescription.h"
#include "NxOgreBoxDescription.h"
#include "NxOgreFunctions.h"
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Box::Box(NxBoxShape* box_shape)
: Shape(box_shape), mBoxShape(box_shape)
{
}

Box::~Box()
{
}

unsigned int Box::getShapeType() const
{
 return Classes::_Box;
}

Enums::ShapeFunctionType Box::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Box;
}

void Box::saveToDescription(BoxDescription& description)
{
 NxBoxShapeDesc desc;
 mBoxShape->saveToDesc(desc);
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

 description.mSize = Vec3(desc.dimensions * 2);
}

Vec3 Box::getSize() const
{
 return Vec3(mBoxShape->getDimensions() * 2);
}

void Box::setSize(const Vec3& vec)
{
 mBoxShape->setDimensions((vec * 0.5f).as<NxVec3>());
}

void Box::setSize(Real w, Real h, Real d)
{
 mBoxShape->setDimensions(NxVec3(w * 0.5, h * 0.5, d * 0.5));
}

SimpleBox Box::getWorldOBB()
{
 SimpleBox box;
 
 NxBox obb;
 mBoxShape->getWorldOBB(obb);
 return SimpleBox(obb);
}

String Box::to_s() const
{
 return String("Box");
}

                                                                                       

} // namespace NxOgre

                                                                                       
