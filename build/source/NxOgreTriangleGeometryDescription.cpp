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
 ShapeDescription::reset(0, local_pose);
}

TriangleGeometryDescription::~TriangleGeometryDescription()
{
}

void TriangleGeometryDescription::reset()
{
 ShapeDescription::reset();
 mMesh = 0;
 mMeshFlags = 0;
 mMeshPagingMode = Enums::MeshPagingMode_Manual;
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

bool TriangleGeometryDescription::isValid() const
{
 if (mMesh == 0)
  return false;
 if (mMesh->getType() != Enums::MeshType_Triangle)
  return false;
 
 return ShapeDescription::isValid();
}

                                                                                       

} // namespace NxOgre

                                                                                       
