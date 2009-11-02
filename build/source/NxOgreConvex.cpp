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
#include "NxOgreConvex.h"
#include "NxOgreConvexDescription.h"
#include "NxOgreMesh.h"
#include "NxOgreShapeDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Convex::Convex(NxConvexShape* shape, Mesh* mesh)
: Shape(shape), mConvexShape(shape), mMesh(mesh)
{
}

Convex::~Convex(void)
{
}

unsigned int Convex::getShapeType() const
{
 return Classes::_Convex;
}

Enums::ShapeFunctionType Convex::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Convex;
}

Mesh* Convex::getMesh(void)
{
 return mMesh;
}

void Convex::saveToDescription(ConvexDescription& description)
{
 NxConvexShapeDesc desc;
 mConvexShape->saveToDesc(desc);
 description.mDensity = desc.density;
 description.mFlags = desc.shapeFlags;
 description.mGroup = desc.group;
 description.mGroupsMask.mBits0 = desc.groupsMask.bits0;
 description.mGroupsMask.mBits1 = desc.groupsMask.bits1;
 description.mGroupsMask.mBits2 = desc.groupsMask.bits2;
 description.mGroupsMask.mBits3 = desc.groupsMask.bits3;
 desc.localPose.getRowMajor44(description.mLocalPose.ptr());
 description.mMass = desc.mass;
 description.mMaterial = desc.materialIndex;
 description.mNonInteractingCompartmentTypes = desc.nonInteractingCompartmentTypes;
 description.mSkinWidth = desc.skinWidth;

 description.mMesh = mMesh;
 description.mMeshFlags = desc.meshFlags;
}
                                                                                       

} // namespace NxOgre

                                                                                       
