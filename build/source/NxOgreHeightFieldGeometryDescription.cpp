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
#include "NxOgreHeightFieldGeometryDescription.h"
#include "NxOgreHeightField.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

HeightFieldGeometryDescription::HeightFieldGeometryDescription(HeightField* heightfield, const Vec3& dimensions, Enums::TerrainCentering tc)
: mDimensions(dimensions),
  mScaleDimensions(false),
  mTerrainCentering(tc),
  mSmoothSphereCollisions(false),
  mHoleMaterial(65535),
  mHighBits(0),
  mHeightField(heightfield),
  mMeshFlags(0)
{
 ShapeDescription::reset();
}

HeightFieldGeometryDescription::HeightFieldGeometryDescription(HeightField* heightfield, Real dx, Real dy, Real dz, Enums::TerrainCentering tc)
: mDimensions(dx, dy, dz),
  mScaleDimensions(false),
  mTerrainCentering(tc),
  mSmoothSphereCollisions(false),
  mHoleMaterial(65535),
  mHighBits(0),
  mHeightField(heightfield),
  mMeshFlags(0)
{
 ShapeDescription::reset();
}
  
HeightFieldGeometryDescription::HeightFieldGeometryDescription(HeightField* heightfield, const Vec3& dimensions, const Matrix44& local_pose)
: mDimensions(dimensions),
  mScaleDimensions(false),
  mTerrainCentering(Enums::TerrainCentering_LocalPose),
  mSmoothSphereCollisions(false),
  mHoleMaterial(65535),
  mHighBits(0),
  mHeightField(heightfield),
  mMeshFlags(0)
{
 ShapeDescription::reset();
 mMaterial = 0;
 mLocalPose = local_pose;
}

HeightFieldGeometryDescription::HeightFieldGeometryDescription(HeightField* heightfield, Real dx, Real dy, Real dz, const Matrix44& local_pose)
: mDimensions(dx, dy, dz),
  mScaleDimensions(false),
  mTerrainCentering(Enums::TerrainCentering_LocalPose),
  mSmoothSphereCollisions(false),
  mHoleMaterial(65535),
  mHighBits(0),
  mHeightField(heightfield),
  mMeshFlags(0)
{
 ShapeDescription::reset();
 mMaterial = 0;
 mLocalPose = local_pose;
}

HeightFieldGeometryDescription::~HeightFieldGeometryDescription()
{
}

NxShapeDesc* HeightFieldGeometryDescription::createShapeDescription() const
{
 NxHeightFieldShapeDesc* description = NXOGRE_NEW_PHYSX(NxHeightFieldShapeDesc, PhysXClassAllocator);
 setShapeDescription(description);
 description->heightField = (mHeightField == 0) ? 0 : mHeightField->getHeightField();

 if (mScaleDimensions)
 {
  description->rowScale = mDimensions.x;
  description->heightScale = mDimensions.y;
  description->columnScale = mDimensions.z;
 }
 else
 {
  description->rowScale = mDimensions.x / Real(mHeightField->getNbRows());
  description->heightScale = mDimensions.y / 32768.0f;
  description->columnScale = mDimensions.z / Real(mHeightField->getNbColumns()); 
 }
 
 description->materialIndexHighBits = mHighBits;
 description->holeMaterial = mHoleMaterial;
 description->meshFlags = mMeshFlags;

 return description;
}



                                                                                       

} // namespace NxOgre

                                                                                       



// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

HeightFieldGeometryDescription::HeightFieldGeometryDescription(const HeightFieldGeometryDescription& other)
{
 other.copy_into(this);
}

HeightFieldGeometryDescription& HeightFieldGeometryDescription::operator=(const HeightFieldGeometryDescription& other)
{
 other.copy_into(this);
 return *this;
}

HeightFieldGeometryDescription* HeightFieldGeometryDescription::duplicate() const
{
 HeightFieldGeometryDescription* dup = new HeightFieldGeometryDescription();
 copy_into(dup);
 return dup;
}

void HeightFieldGeometryDescription::copy_into(HeightFieldGeometryDescription* other) const
{
 ShapeDescription::copy_into(other);

 other->mDimensions = mDimensions;
 other->mHeightField = mHeightField;
 other->mHighBits = mHighBits;
 other->mHoleMaterial = mHoleMaterial;
 other->mMeshFlags = mMeshFlags;
 other->mScaleDimensions = mScaleDimensions;
 other->mSmoothSphereCollisions = mSmoothSphereCollisions;
 other->mTerrainCentering = mTerrainCentering;
}

void HeightFieldGeometryDescription::reset()
{
 mDimensions.set(1,1,1);
 mHeightField = NULL;
 mHighBits = 0;
 mHoleMaterial = 65535;
 mMeshFlags = 0;
 mScaleDimensions = false;
 mSmoothSphereCollisions = false;
 mTerrainCentering = Enums::TerrainCentering_LocalPose;
}

bool HeightFieldGeometryDescription::valid() const
{
 if (!ShapeDescription::valid())
  return false; // mHeightField pointer cannot be null
 if (mHeightField == NULL)
  return false;

 return true;
}

void HeightFieldGeometryDescription::inspect() const
{
 ShapeDescription::inspect();

 std::cout << "HeightFieldGeometryDescription => {\n";
 std::cout << "  mDimensions => '" << mDimensions << "'\n";
 std::cout << "  mHeightField => '" << mHeightField << "'\n";
 std::cout << "  mHighBits => '" << mHighBits << "'\n";
 std::cout << "  mHoleMaterial => '" << mHoleMaterial << "'\n";
 std::cout << "  mMeshFlags => '" << mMeshFlags << "'\n";
 std::cout << "  mScaleDimensions => '" << mScaleDimensions << "'\n";
 std::cout << "  mSmoothSphereCollisions => '" << mSmoothSphereCollisions << "'\n";
 std::cout << "  mTerrainCentering => '" << mTerrainCentering << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "HeightFieldGeometryDescription-9b665079e3ebd114391a4feefb62b4e2"

