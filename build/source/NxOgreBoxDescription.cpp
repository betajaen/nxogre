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
#include "NxOgreBoxDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

BoxDescription::BoxDescription(const Vec3& size, const MaterialIdentifier& material, const Matrix44& local_pose)
{
 ShapeDescription::reset();
 mSize = size;
 mMaterial = material;
 mLocalPose = local_pose;
}

BoxDescription::BoxDescription(Real width, Real height, Real depth, const MaterialIdentifier& material, const Matrix44& local_pose)
{
 ShapeDescription::reset();
 mSize = Vec3(width, height, depth);
 mMaterial = material;
 mLocalPose = local_pose;
}

BoxDescription::BoxDescription(Real r, const MaterialIdentifier& material, const Matrix44& local_pose)
{
 ShapeDescription::reset();
 mSize = Vec3(r, r, r);
 mMaterial = material;
 mLocalPose = local_pose;
}

BoxDescription::~BoxDescription()
{
}

NxShapeDesc* BoxDescription::createShapeDescription() const
{
 NxBoxShapeDesc* description = NXOGRE_NEW_PHYSX(NxBoxShapeDesc, PhysXClassAllocator);
 setShapeDescription(description);
 description->dimensions = (mSize * 0.5).as<NxVec3>();
 return description;
}

                                                                                       

} // namespace NxOgre

                                                                                       


// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

BoxDescription::BoxDescription(const BoxDescription& other)
{
 other.copy_into(this);
}

BoxDescription& BoxDescription::operator=(const BoxDescription& other)
{
 other.copy_into(this);
 return *this;
}

BoxDescription* BoxDescription::duplicate() const
{
 BoxDescription* dup = new BoxDescription();
 copy_into(dup);
 return dup;
}

void BoxDescription::copy_into(BoxDescription* other) const
{
 ShapeDescription::copy_into(other);

 other->mSize = mSize;
}

void BoxDescription::reset()
{
 mSize.set(1,1,1);
}

bool BoxDescription::valid() const
{
 if (!ShapeDescription::valid())
  return false; // mSize cannot have negative or zero values
 if (mSize.isNegative() || mSize.isZero())
  return false;

 return true;
}

void BoxDescription::inspect() const
{
 ShapeDescription::inspect();

 std::cout << "BoxDescription => {\n";
 std::cout << "  mSize => '" << mSize << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "BoxDescription-b0de51e9b492dd515101858546e9314f"

