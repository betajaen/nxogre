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

                                                                                       

#ifndef NXOGRE_UTIL_H
#define NXOGRE_UTIL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Util
{

                                                                                       

/** \brief Test if an oriented box contains a point.
    \param box Box to test.
    \param p  Point to test.
    \return If box contains p.
    \see NxBoxContainsPoint
    \warning This function can only be used once World or the PhysX SDK has been created.
*/
bool NxOgrePublicFunction SimpleBoxContainsPoint(const SimpleBox& box, const Vec3& p);


/** \brief Create an oriented box from an axis aligned box and a transformation.
    \brief aabb Axis-Aligned Box.
    \brief trans Transformation matrix.
    \return The transformed box.
    \see NxComputeBoxPlanes
    \warning This function can only be used once World or the PhysX SDK has been created.
*/
SimpleBox NxOgrePublicFunction createSimpleBox(const Bounds3& aabb, const Matrix44& trans);

#if 0
/** \brief Computes plane equation for each face of an oriented box.
    \brief box Box to compute.
    \brief planes Array to recieve the six computed planes.
    \return True on success.
    \see NxComputeBoxPlanes
    \warning This function can only be used once World or the PhysX SDK has been created.
*/
bool NxOgrePublicFunction computeSimpleBoxPlanes(const SimpleBox& box, SimplePlane* planes_array_of_six);
#endif

/** \brief Create an oriented box from an axis aligned box and a transformation.
    \brief normal Plane direction.
    \brief distance Distance from the center of the world.
    \return The plane
*/
SimplePlane NxOgrePublicFunction createSimplePlane(const Vec3& normal, const Real& distance);


/** \brief Using a Ray-plane intersection test. 
           Returns distance between ray origin and impact point, as well as impact point on plane.
    \note  This function is faster than a ray-cast if you want 3D coordinates on a flat plane.
    \brief Ray          Ray to use
    \brief SimplePlane  Plane to test
    \brief Distance     Distance if hit.
    \brief pointOnPlane Point on plane, if the intersection test is true.
    \return True If the intersection was true.
*/
bool NxOgrePublicFunction RayPlaneIntersect(const Ray&, const SimplePlane&, Real& distance, Vec3& pointOnPlane);

                                                                                       

} // namespace Util


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
