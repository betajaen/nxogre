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
#include "NxOgreCommon.h"
#include "NxOgrePlaneGeometryDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PlaneGeometryDescription::PlaneGeometryDescription(const Vec3& normal, Real distance, const MaterialIdentifier& material)
: mNormal(normal), mDistance(distance)
{
 ShapeDescription::reset();
 mMaterial = material;
}

PlaneGeometryDescription::~PlaneGeometryDescription()
{
}

NxShapeDesc* PlaneGeometryDescription::createShapeDescription() const
{
 NxPlaneShapeDesc* description = NXOGRE_NEW_PHYSX(NxPlaneShapeDesc, PhysXClassAllocator);
 setShapeDescription(description);
 description->normal = mNormal.as<NxVec3>();
 description->d = mDistance;
 return description;
}

                                                                                       

} // namespace NxOgre

                                                                                       


// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

PlaneGeometryDescription::PlaneGeometryDescription(const PlaneGeometryDescription& other)
{
 other.copy_into(this);
}

PlaneGeometryDescription& PlaneGeometryDescription::operator=(const PlaneGeometryDescription& other)
{
 other.copy_into(this);
 return *this;
}

PlaneGeometryDescription* PlaneGeometryDescription::duplicate() const
{
 PlaneGeometryDescription* dup = new PlaneGeometryDescription();
 copy_into(dup);
 return dup;
}

void PlaneGeometryDescription::copy_into(PlaneGeometryDescription* other) const
{
 ShapeDescription::copy_into(other);

 other->mDistance = mDistance;
 other->mNormal = mNormal;
}

void PlaneGeometryDescription::reset()
{
 mDistance = 0;
 mNormal.set(0,1,0);
}

bool PlaneGeometryDescription::valid() const
{
 if (!ShapeDescription::valid())
  return false;
 return true;
}

void PlaneGeometryDescription::inspect() const
{
 ShapeDescription::inspect();

 std::cout << "PlaneGeometryDescription => {\n";
 std::cout << "  mDistance => '" << mDistance << "'\n";
 std::cout << "  mNormal => '" << mNormal << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "PlaneGeometryDescription-e9d569ded62d6428f4adef457efaed17"

