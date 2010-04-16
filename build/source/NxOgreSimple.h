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

                                                                                       

#ifndef NXOGRE_SIMPLE_H
#define NXOGRE_SIMPLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

inline void NxOgrePublicFunction SimpleShapeToActorDescription(NxActorDesc&, SimpleShape*);

};

struct SimpleShape : public ShapeAllocatable
{
 Enums::SimpleShapeType  mType;
};

struct SimplePlane : public SimpleShape
{
 SimplePlane();
 SimplePlane(const Vec3& normal, float distance);
 Vec3        mNormal;
 float       mDistance;
};

struct SimpleBox : public SimpleShape
{
 SimpleBox();
 SimpleBox(const Vec3& size, const Vec3& position = Vec3::ZERO, const Quat& orientation = Quat::IDENTITY);
 SimpleBox(const Vec3& size, const Vec3& position, const Matrix33&);
 SimpleBox(const NxBox&);
 SimpleBox(const Bounds3& aabb, const Matrix44& trans);

 
 bool  contains(const Vec3&) const;
 NxBox to_box() const;
 
 Vec3     mCenter;
 Matrix33 mRotation;
 Vec3     mSize;
};

struct SimpleSphere : public SimpleShape
{
 SimpleSphere();
 SimpleSphere(Real radius, const Vec3& center = Vec3::ZERO);
 SimpleSphere(const NxSphere&);
 
 NxSphere to_sphere() const;
 
 Vec3 mCenter;
 Real mRadius;
};

struct SimpleCapsule : public SimpleShape
{
 SimpleCapsule();
 SimpleCapsule(Real radius, const Vec3& p0, const Vec3& p1);
 SimpleCapsule(const NxCapsule&);
 
 NxCapsule to_capsule() const;
 
 Vec3 mP0, mP1;
 Real mRadius;
};

struct SimplePointCloud : public SimpleShape
{
 
 SimplePointCloud();
~SimplePointCloud();
 
 Buffer<Vec3>  mPoints;
};

struct SimpleTriangleMesh : public SimpleShape
{
 
 SimpleTriangleMesh();
~SimpleTriangleMesh();
 
 Buffer<Vec3>          mPoints;
 Buffer<Vec3>          mNormals;
 Buffer<unsigned int>  mIndices;
};

typedef std::vector<SimpleShape*> SimpleShapes;

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
