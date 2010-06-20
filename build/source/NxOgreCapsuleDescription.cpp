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
#include "NxOgreCapsuleDescription.h"

#include "NxPhysics.h"



namespace NxOgre
{



CapsuleDescription::CapsuleDescription(Real radius, Real height, const MaterialIdentifier& material, const Matrix44& local_pose)
: mRadius(radius), mHeight(height)
{
 ShapeDescription::reset();
 mMaterial = material;
 mLocalPose = local_pose;
}

CapsuleDescription::CapsuleDescription(const Vec2& size, const MaterialIdentifier& material, const Matrix44& local_pose)
: mRadius(size.x), mHeight(size.y)
{
 ShapeDescription::reset();
 mMaterial = material;
 mLocalPose = local_pose;
}

CapsuleDescription::~CapsuleDescription()
{
}

NxShapeDesc* CapsuleDescription::createShapeDescription() const
{
 NxCapsuleShapeDesc* description = GC::safe_allocated_new0<NxCapsuleShapeDesc, PhysXClassAllocator>(NXOGRE_GC_THIS);
 setShapeDescription(description);
 description->radius = mRadius;
 description->height = mHeight;
 return description;
}



} // namespace NxOgre




// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

CapsuleDescription::CapsuleDescription(const CapsuleDescription& other)
{
 other.copy_into(this);
}

CapsuleDescription& CapsuleDescription::operator=(const CapsuleDescription& other)
{
 other.copy_into(this);
 return *this;
}

CapsuleDescription* CapsuleDescription::duplicate() const
{
 CapsuleDescription* dup = new CapsuleDescription();
 copy_into(dup);
 return dup;
}

void CapsuleDescription::copy_into(CapsuleDescription* other) const
{
 ShapeDescription::copy_into(other);

 other->mHeight = mHeight;
 other->mRadius = mRadius;
}

void CapsuleDescription::reset()
{
 mHeight = 1.0;
 mRadius = 1.0;
}

bool CapsuleDescription::valid() const
{
 if (!ShapeDescription::valid())
  return false;
 return true;
}

void CapsuleDescription::inspect() const
{
 ShapeDescription::inspect();

 std::cout << "CapsuleDescription => {\n";
 std::cout << "  mHeight => '" << mHeight << "'\n";
 std::cout << "  mRadius => '" << mRadius << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "CapsuleDescription-900f57fddac29d8ea93d837ad5aae159"

