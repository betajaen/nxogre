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
#include "NxOgreSphereDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

SphereDescription::SphereDescription(Real radius, const MaterialIdentifier& material, const Matrix44& local_pose)
: mRadius(radius)
{
 ShapeDescription::reset();
 mMaterial = material;
 mLocalPose = local_pose;
}

SphereDescription::~SphereDescription()
{
}

NxShapeDesc* SphereDescription::createShapeDescription() const
{
 NxSphereShapeDesc* description = GC::safe_allocated_new0<NxSphereShapeDesc, PhysXClassAllocator>(NXOGRE_GC_THIS);
 setShapeDescription(description);
 description->radius = mRadius;
 return description;
}

                                                                                       

} // namespace NxOgre

                                                                                       


// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

SphereDescription::SphereDescription(const SphereDescription& other)
{
 other.copy_into(this);
}

SphereDescription& SphereDescription::operator=(const SphereDescription& other)
{
 other.copy_into(this);
 return *this;
}

SphereDescription* SphereDescription::duplicate() const
{
 SphereDescription* dup = new SphereDescription();
 copy_into(dup);
 return dup;
}

void SphereDescription::copy_into(SphereDescription* other) const
{
 ShapeDescription::copy_into(other);

 other->mRadius = mRadius;
}

void SphereDescription::reset()
{
 mRadius = 0.5;
}

bool SphereDescription::valid() const
{
 if (!ShapeDescription::valid())
  return false;
 return true;
}

void SphereDescription::inspect() const
{
 ShapeDescription::inspect();

 std::cout << "SphereDescription => {\n";
 std::cout << "  mRadius => '" << mRadius << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "SphereDescription-58d367fc3c5c197ecd5290b1e16f08ad"

