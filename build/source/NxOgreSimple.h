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
inline void NxOgrePublicFunction SimpleBoxToNxBox(const SimpleBox&, NxBox&);
inline void NxOgrePublicFunction NxBoxToSimpleBox(const NxBox&, SimpleBox&);
inline void NxOgrePublicFunction SimpleCapsuleToNxCapsule(const SimpleCapsule&, NxCapsule&);
inline void NxOgrePublicFunction NxCapsuleToSimpleCapsule(const NxCapsule&, SimpleCapsule&);
};

struct SimpleShape
{
 Enums::SimpleShapeType  mType;
 Vec3                    mCenter;
 void*                   mUser;
};

struct SimplePlane : public SimpleShape
{
 Vec3        mNormal;
 double      mDistance;
};

struct SimpleBox : public SimpleShape
{
 Matrix33    mRotation;
 Vec3        mExtents;
};

struct SimpleSphere : public SimpleShape
{
 Real mRadius;
};

struct SimpleSegment : public SimpleShape
{
 Vec3 mP0;
 Vec3 mP1;
};

struct SimpleCapsule : public SimpleSegment
{
 Real Radius;
};

struct SimplePointCloud : public SimpleShape
{
 unsigned int   mNbVertices;
 Vec3*          mVertices;
};

struct SimpleTriangleMesh : public SimpleShape
{
 unsigned int    mNbVertices;
 Vec3*           mVertices;
 Vec3*           mNormals;
 unsigned int    mNbIndicies;
 unsigned int*   mIndicies;
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
