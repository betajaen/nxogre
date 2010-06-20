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
#include "NxOgreShapeDescription.h"
#include "NxOgreMesh.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ShapeDescription::ShapeDescription()
{ // virtual
}

ShapeDescription::~ShapeDescription()
{ // virtual
}

NxShapeDesc* ShapeDescription::createShapeDescription() const
{
 std::cout << "?? ShapeDescription::createShapeDescription\n";
 return 0;
}

void ShapeDescription::setShapeDescription(NxShapeDesc* description) const
{
 description->ccdSkeleton = (mSkeleton != 0) ? mSkeleton->getAsSkeleton() : 0;
 description->density = mDensity;
 description->group = mGroup;
 description->groupsMask.bits0 = mGroupsMask.bits0;
 description->groupsMask.bits1 = mGroupsMask.bits1;
 description->groupsMask.bits2 = mGroupsMask.bits2;
 description->groupsMask.bits3 = mGroupsMask.bits3;
 description->localPose.setRowMajor44(mLocalPose.ptr());
 description->mass = mMass;
 description->materialIndex = mMaterial;
 description->nonInteractingCompartmentTypes = mNonInteractingCompartmentTypes;
 description->shapeFlags = mFlags.to_i();
 description->skinWidth = mSkinWidth;
 description->userData = (void*) mId;
}

                                                                                       

} // namespace NxOgre

                                                                                       



// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

ShapeDescription::ShapeDescription(const ShapeDescription& other)
{
 other.copy_into(this);
}

ShapeDescription& ShapeDescription::operator=(const ShapeDescription& other)
{
 other.copy_into(this);
 return *this;
}

ShapeDescription* ShapeDescription::duplicate() const
{
 ShapeDescription* dup = new ShapeDescription();
 copy_into(dup);
 return dup;
}

void ShapeDescription::copy_into(ShapeDescription* other) const
{
 other->mDensity = mDensity;
 other->mFlags = mFlags;
 other->mGroup = mGroup;
 other->mGroupsMask = mGroupsMask;
 other->mId = mId;
 other->mLocalPose = mLocalPose;
 other->mMass = mMass;
 other->mMaterial = mMaterial;
 other->mNonInteractingCompartmentTypes = mNonInteractingCompartmentTypes;
 other->mSkeleton = mSkeleton;
 other->mSkinWidth = mSkinWidth;
}

void ShapeDescription::reset()
{
 mDensity = 1.0;
 mFlags.reset();
 mGroup = 0;
 mGroupsMask.zero();
 mId = 0;
 mLocalPose.identity();
 mMass = -1.0;
 mMaterial = 0;
 mNonInteractingCompartmentTypes = 0;
 mSkeleton = 0;
 mSkinWidth = -1.0;
}

bool ShapeDescription::valid() const
{
 // mGroup index should be in the first 32 groups
 if ((mGroup >= 32))
  return false;

 return true;
}

void ShapeDescription::inspect() const
{
 std::cout << "ShapeDescription => {\n";
 std::cout << "  mDensity => '" << mDensity << "'\n";
 std::cout << "  mFlags => '" << mFlags << "'\n";
 std::cout << "  mGroup => '" << mGroup << "'\n";
 std::cout << "  mGroupsMask => '" << mGroupsMask << "'\n";
 std::cout << "  mId => '" << mId << "'\n";
 std::cout << "  mLocalPose => '" << mLocalPose << "'\n";
 std::cout << "  mMass => '" << mMass << "'\n";
 std::cout << "  mMaterial => '" << mMaterial << "'\n";
 std::cout << "  mNonInteractingCompartmentTypes => '" << mNonInteractingCompartmentTypes << "'\n";
 std::cout << "  mSkeleton => '" << mSkeleton << "'\n";
 std::cout << "  mSkinWidth => '" << mSkinWidth << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "ShapeDescription-11f697d54f71eb074e1517ee08161adc"

