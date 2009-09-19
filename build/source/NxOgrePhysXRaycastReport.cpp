/** File: NxOgrePhysXCallback.cpp
    Created on: 19-Apr-09
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
#include "NxOgrePhysXRaycastReport.h"
#include "NxOgreCallback.h"
#include "NxOgreRaycastHit.h"
#include "NxOgreFunctions.h"

#include "NxPhysicsSDK.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXRaycastReport::PhysXRaycastReport(Callback* callback)
: mCallback(callback)
{
}

PhysXRaycastReport::~PhysXRaycastReport()
{
}

bool PhysXRaycastReport::onHit(const NxRaycastHit& hit)
{
 RaycastHit out;
 out.mDistance = hit.distance;
 out.mFaceID = hit.faceID;
 out.mFlags = hit.flags;
 out.mInternalFaceID = hit.internalFaceID;
 out.mMaterialIndex = hit.materialIndex;
 out.mShape = static_cast<Shape*>(hit.shape->userData);
 out.mU = hit.u;
 out.mV = hit.v;
 Functions::XYZ<NxVec3, Vec3>(hit.worldImpact, out.mWorldImpact);
 Functions::XYZ<NxVec3, Vec3>(hit.worldNormal, out.mWorldNormal);

 return mCallback->onHitEvent(out);
}

                                                                                       

} // namespace NxOgre

                                                                                       
