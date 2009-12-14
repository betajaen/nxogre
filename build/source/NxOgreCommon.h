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

                                                                                       

#ifndef NXOGRE_COMMON_H
#define NXOGRE_COMMON_H

                                                                                       

#include "NxOgreClassPrototypes.h"
#include "NxOgreAllocator.h"
#include "NxOgreAllocatables.h"
#include "NxOgrePhysXPrototypes.h"
#include "NxOgreEnums.h"
#include "NxOgreException.h"
#include "NxOgreWarning.h"
#include "NxOgreNotice.h"
#include "NxOgrePointerFunctions.h"
#include "NxOgreClasses.h"
#include "NxOgreErrorStream.h"
#include "NxOgrePhysXPointer.h"
#include "NxOgreSharedPointer.h"
#include "NxOgreSingleton.h"
#include "NxOgreArray.h"
#include "NxOgreMap.h"
#include "NxOgrePtrVector.h"
#include "NxOgrePtrHashmap.h"
#include "NxOgrePtrMultiHashmap.h"
#include "NxOgreBuffer.h"
#include "NxOgreCircularBuffer.h"
#include "NxOgreMath.h"
#include "NxOgreTuple.h"
#include "NxOgreVec2.h"
#include "NxOgreVec3.h"
#include "NxOgreVec4.h"
#include "NxOgreQuat.h"
#include "NxOgreGroupsMask.h"
#include "NxOgreBounds.h"
#include "NxOgreMatrix.h"
#include "NxOgreString.h"
#include "NxOgreIntVectors.h"
#include "NxOgrePath.h"
#include "NxOgreTriangle.h"
#include "NxOgreEntityReport.h"
#include "NxOgreTimeStep.h"
#include "NxOgreTimer.h"

                                                                                       

namespace NxOgre
{

                                                                                       

typedef BoundsT<Vec2> Bounds2;
typedef BoundsT<Vec3> Bounds3;
typedef BoundsT<Vec4> Bounds4;
typedef Real          Radian;

                                                                                       

/** \brief 1/30th of a second, to 8 sig. figs.
*/
static const Real _1_30 = 0.0333333f;

/** \brief 1/60th of a second, to 8 sig. figs.
*/
static const Real _1_60 = 0.0166666f;

/** \brief 1/100th of a second.
*/
static const Real _1_100 = 0.01f;

/** \brief 1/5th of a second
*/
static const Real _1_5 = 0.2f;

/** \brief Numerical identifier for ActorGroups and ShapeGroups.
*/
typedef unsigned short GroupIdentifier;

/** \brief Numerical identifier for Materials.
*/
typedef unsigned short MaterialIdentifier;

/** \brief An index in a triangle
*/
typedef unsigned int Index;

/** \brief A pair of JointLimitDescriptions.
*/
typedef Pair<JointLimitDescription> JointLimitPairDescription;

/** \brief A pair of JointLimitDescriptions.
*/
typedef Pair<JointLimitSoftDescription> JointLimitPairSoftDescription;

/** \brief
*/
typedef JointDescription FixedJointDescription;

/** \brief Used by the SDK for caching raycasts.
*/
typedef NxShape** RaycastCache;

/** \brief Buffer of SweepQueryHits
*/
typedef Buffer<SweepQueryHit> SweepQueryHits;

/*! desc.
*/
typedef std::pair<Real, Real> ConstraintDominance;

//
static const Path MEMORY_PATH = Path("memory://");

                                                                                       

#define Matrix33_Zero     NxOgre::Matrix33::ZERO

#define Matrix33_Identity NxOgre::Matrix33::IDENTITY

#define Matrix44_Zero     NxOgre::Matrix44::ZERO

#define Matrix44_Identity NxOgre::Matrix44::IDENTITY

                                                                                       

namespace Constants
{

/** \brief Unknown resource size constant.
*/
static const size_t ResourceSizeUnknown = -1;

enum
{
 DefaultRemoteDebuggerPort = 5425
};

}; // namespace Constants

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
