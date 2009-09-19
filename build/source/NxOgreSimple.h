/** File: NxOgreSimple.h
    Created on: 24-Nov-08
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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
 unsigned int    mNbVertices;
 Vec3*    mVertices;
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
