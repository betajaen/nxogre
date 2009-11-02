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
: mSize(size)
{
 ShapeDescription::reset(material, local_pose);
}

BoxDescription::BoxDescription(Real width, Real height, Real depth, const MaterialIdentifier& material, const Matrix44& local_pose)
: mSize(width, height, depth)
{
 ShapeDescription::reset(material, local_pose);
}

BoxDescription::BoxDescription(Real combined_width_height_and_depth, const MaterialIdentifier& material, const Matrix44& local_pose)
: mSize(combined_width_height_and_depth, combined_width_height_and_depth, combined_width_height_and_depth)
{
 ShapeDescription::reset(material, local_pose);
}

BoxDescription::~BoxDescription()
{
}

void BoxDescription::reset()
{
 ShapeDescription::reset();
 mSize.set(1.0, 1.0, 1.0);
}

NxShapeDesc* BoxDescription::createShapeDescription() const
{
 NxBoxShapeDesc* description = NxOgreAllocatedNew<NxBoxShapeDesc, PhysXClassAllocator>();
 setShapeDescription(description);
 description->dimensions = (mSize * 0.5).as<NxVec3>();
 return description;
}

bool BoxDescription::isValid() const
{
 if (mSize.x < 0.0f)
  return false;
 if (mSize.y < 0.0f)
  return false;
 if (mSize.z < 0.0f)
  return false;
 
 return ShapeDescription::isValid();
}

                                                                                       

} // namespace NxOgre

                                                                                       
