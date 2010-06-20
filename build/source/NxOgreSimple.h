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

                                                                                       

struct NxOgrePublicClass SimpleShape : public ShapeAllocatable
{
 virtual Enums::SimpleShapeType  getType() const = 0;
 virtual NxForceFieldShapeDesc*  to_ff_shape() const;
#if NxOgreHasCharacterController == 1
 virtual Vec3 to_cc_shape() const;
#endif
};

struct NxOgrePublicClass SimplePlane : public SimpleShape
{
 SimplePlane();
 SimplePlane(const Vec3& normal, float distance);
 
 Enums::SimpleShapeType  getType() const;
 NxForceFieldShapeDesc*  to_ff_shape() const;
 
 Vec3        mNormal;
 float       mDistance;
};

struct NxOgrePublicClass SimpleBox : public SimpleShape
{
 SimpleBox();
 SimpleBox(const Vec3& size, const Vec3& position = Vec3::ZERO, const Quat& orientation = Quat::IDENTITY);
 SimpleBox(const Vec3& size, const Vec3& position, const Matrix33&);
 SimpleBox(const NxBox&);
 SimpleBox(const Bounds3& aabb, const Matrix44& trans);


 Enums::SimpleShapeType  getType() const;
 bool                    contains(const Vec3&) const;
 NxBox                   to_box() const;
 NxForceFieldShapeDesc*  to_ff_shape() const;
#if NxOgreHasCharacterController == 1
 Vec3                    to_cc_shape() const;
#endif

 Vec3     mCenter;
 Matrix33 mRotation;
 Vec3     mSize;
};

struct NxOgrePublicClass SimpleSphere : public SimpleShape
{
 SimpleSphere();
 SimpleSphere(Real radius, const Vec3& center = Vec3::ZERO);
 SimpleSphere(const NxSphere&);
 
 Enums::SimpleShapeType  getType() const;
 NxSphere                to_sphere() const;
 NxForceFieldShapeDesc*  to_ff_shape() const;
 
 Vec3 mCenter;
 Real mRadius;
};

struct NxOgrePublicClass SimpleCapsule : public SimpleShape
{
 SimpleCapsule();
 SimpleCapsule(Real height, Real radius);
 SimpleCapsule(const Vec3& origin, const Vec3& direction, Real radius);
 SimpleCapsule(Real radius, const Vec3& p0, const Vec3& p1);
 SimpleCapsule(const NxCapsule&);
 
 Vec3 getOrigin() const;
 Vec3 getDirection() const;

 Enums::SimpleShapeType  getType() const;
 NxCapsule               to_capsule() const;
 NxForceFieldShapeDesc*  to_ff_shape() const;
#if NxOgreHasCharacterController == 1
 Vec3                    to_cc_shape() const;
#endif

 Vec3 mP0, mP1;
 Real mRadius;
};

struct SimpleConvexPointCloud : public SimpleShape
{
 
 SimpleConvexPointCloud();
~SimpleConvexPointCloud();

 Enums::SimpleShapeType  getType() const;
 NxForceFieldShapeDesc*  to_ff_shape() const;
 
 buffer<Vec3>  mPoints;
};


typedef std::vector<SimpleShape*> SimpleShapes;

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
