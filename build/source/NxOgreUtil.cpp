/** File: NxOgreUtil.cpp
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreUtil.h"
#include "NxOgreSimple.h"
#include "NxOgreFunctions.h"
#include "NxOgreRay.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Util
{

                                                                                       

bool SimpleBoxContainsPoint(const SimpleBox& oBox, const Vec3& oP)
{
 NxBox box;
 Functions::SimpleBoxToNxBox(oBox, box);
 NxVec3 p;
 Functions::XYZ<Vec3, NxVec3>(oP, p);
 return NxGetUtilLib()->NxBoxContainsPoint(box, p);
}

SimpleBox NxOgrePublicFunction createSimpleBox(const Bounds3& aabb, const Matrix44& trans)
{
 SimpleBox out;
 NxBounds3 bounds;
 bounds.max.x = aabb.max.x;
 bounds.max.y = aabb.max.y;
 bounds.max.z = aabb.max.z;
 bounds.min.x = aabb.min.x;
 bounds.min.y = aabb.min.y;
 bounds.min.z = aabb.min.z;
 NxMat34 mat;
 mat.setColumnMajor44(trans.ptr());
 NxBox box;
 NxGetUtilLib()->NxCreateBox(box, bounds, mat);
 Functions::NxBoxToSimpleBox(box, out);
 return out;
}

SimplePlane NxOgrePublicFunction createSimplePlane(const Vec3& normal, const Real& distance)
{
 SimplePlane plane;
 plane.mDistance = distance;
 plane.mNormal = normal;
 return plane;
}

bool NxOgrePublicFunction RayPlaneIntersect(const Ray& ray, const SimplePlane& simplePlane, Real& distance, Vec3& pointOnPlane)
{
 NxPlane plane;
 plane.d = simplePlane.mDistance;
 Functions::XYZ<Vec3, NxVec3>(simplePlane.mNormal, plane.normal);

 NxRay inRay;
 Functions::XYZ<Vec3, NxVec3>(ray.mDirection, inRay.dir);
 Functions::XYZ<Vec3, NxVec3>(ray.mOrigin, inRay.orig);
 
 NxVec3 physxPointOnPlane;
 bool result = NxGetUtilLib()->NxRayPlaneIntersect(inRay, plane, distance, physxPointOnPlane);
 Functions::XYZ<NxVec3, Vec3>(physxPointOnPlane, pointOnPlane);
 return result;
}


                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       
