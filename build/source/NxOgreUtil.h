/** File: NxOgreUtil.h
    Created on: 11-Apr-09
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
