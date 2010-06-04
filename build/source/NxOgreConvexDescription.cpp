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
#include "NxOgreConvexDescription.h"
#include "NxOgreMesh.h"
#include "NxOgreReason.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ConvexDescription::ConvexDescription(Mesh* mesh, const MaterialIdentifier& material, const Matrix44& local_pose)
: mMesh(mesh), mMeshFlags(0)
{
 ShapeDescription::reset();
 mMaterial = material;
 mLocalPose = local_pose;
}

ConvexDescription::~ConvexDescription()
{
}

NxShapeDesc* ConvexDescription::createShapeDescription() const
{
 
 NxOgre_ThrowExceptionIfNull(mMesh, Classes::_Mesh);
 
 if (mMesh->getType() != Enums::MeshType_Convex)
 {
  NxOgre_ThrowException(WrongTypeException, Reason::Exceptionise(mMesh, Enums::MeshType_Convex), Classes::_Mesh);
  return 0;
 }
 
 NxConvexShapeDesc* description = GC::safe_allocated_new0<NxConvexShapeDesc, PhysXClassAllocator>(NXOGRE_GC_THIS);
 setShapeDescription(description);
 
 description->meshData = (mMesh == 0) ? 0 : mMesh->getAsConvex();
 description->meshFlags = mMeshFlags;
 return description;
}


                                                                                       

} // namespace NxOgre

                                                                                       


// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

ConvexDescription::ConvexDescription(const ConvexDescription& other)
{
 other.copy_into(this);
}

ConvexDescription& ConvexDescription::operator=(const ConvexDescription& other)
{
 other.copy_into(this);
 return *this;
}

ConvexDescription* ConvexDescription::duplicate() const
{
 ConvexDescription* dup = new ConvexDescription();
 copy_into(dup);
 return dup;
}

void ConvexDescription::copy_into(ConvexDescription* other) const
{
 ShapeDescription::copy_into(other);

 other->mMesh = mMesh;
 other->mMeshFlags = mMeshFlags;
}

void ConvexDescription::reset()
{
 mMesh = NULL;
 mMeshFlags = 0;
}

bool ConvexDescription::valid() const
{
 if (!ShapeDescription::valid())
  return false; // mMesh must be a convex mesh
 if ((mMesh->getType() != Enums::MeshType_Convex))
  return false;

 return true;
}

void ConvexDescription::inspect() const
{
 ShapeDescription::inspect();

 std::cout << "ConvexDescription => {\n";
 std::cout << "  mMesh => '" << mMesh << "'\n";
 std::cout << "  mMeshFlags => '" << mMeshFlags << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "ConvexDescription-1ead03930ffbdc2d8f5fbcfe475ea5e5"

