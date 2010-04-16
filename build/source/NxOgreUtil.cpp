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

                                                                                       

bool NxOgrePublicFunction RayPlaneIntersect(const Ray& ray, const SimplePlane& simplePlane, Real& distance, Vec3& pointOnPlane)
{
 NxPlane plane;
 plane.d = simplePlane.mDistance;
 plane.normal = simplePlane.mNormal.as<NxVec3>();

 NxRay inRay;
 inRay.dir = ray.mDirection.as<NxVec3>();
 inRay.orig = ray.mOrigin.as<NxVec3>();

 NxVec3 physxPointOnPlane;
 bool result = NxGetUtilLib()->NxRayPlaneIntersect(inRay, plane, distance, physxPointOnPlane);
 pointOnPlane.from<NxVec3>(physxPointOnPlane);
 return result;
}


                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       
