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

                                                                                       
