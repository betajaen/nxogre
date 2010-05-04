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
#include "NxOgreTriangleGeometryDescription.h"
#include "NxOgreMesh.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

TriangleGeometryDescription::TriangleGeometryDescription(Mesh* mesh, const Matrix44& local_pose)
: mMesh(mesh), mMeshFlags(0), mMeshPagingMode(Enums::MeshPagingMode_Manual)
{
 ShapeDescription::reset();
 mLocalPose = local_pose;
}

TriangleGeometryDescription::~TriangleGeometryDescription()
{
}

NxShapeDesc* TriangleGeometryDescription::createShapeDescription() const
{
 NxTriangleMeshShapeDesc* description = NXOGRE_NEW_PHYSX(NxTriangleMeshShapeDesc, PhysXClassAllocator);
 setShapeDescription(description);
 
 description->meshData = (mMesh == 0) ? 0 : mMesh->getAsTriangleMesh();
 description->meshFlags = mMeshFlags;
 description->meshPagingMode = (NxMeshPagingMode) (int) mMeshPagingMode;
 
 return description;
}


                                                                                       

} // namespace NxOgre

                                                                                       


// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

TriangleGeometryDescription::TriangleGeometryDescription(const TriangleGeometryDescription& other)
{
 other.copy_into(this);
}

TriangleGeometryDescription& TriangleGeometryDescription::operator=(const TriangleGeometryDescription& other)
{
 other.copy_into(this);
 return *this;
}

TriangleGeometryDescription* TriangleGeometryDescription::duplicate() const
{
 TriangleGeometryDescription* dup = new TriangleGeometryDescription();
 copy_into(dup);
 return dup;
}

void TriangleGeometryDescription::copy_into(TriangleGeometryDescription* other) const
{
 ShapeDescription::copy_into(other);

 other->mMesh = mMesh;
 other->mMeshFlags = mMeshFlags;
 other->mMeshPagingMode = mMeshPagingMode;
}

void TriangleGeometryDescription::reset()
{
 mMesh = NULL;
 mMeshFlags = 0;
 mMeshPagingMode = Enums::MeshPagingMode_Manual;
}

bool TriangleGeometryDescription::valid() const
{
 if (!ShapeDescription::valid())
  return false;
 return true;
}

void TriangleGeometryDescription::inspect() const
{
 ShapeDescription::inspect();

 std::cout << "TriangleGeometryDescription => {\n";
 std::cout << "  mMesh => '" << mMesh << "'\n";
 std::cout << "  mMeshFlags => '" << mMeshFlags << "'\n";
 std::cout << "  mMeshPagingMode => '" << mMeshPagingMode << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "TriangleGeometryDescription-23818dae2a7d516e43ac7064c70a63dd"

