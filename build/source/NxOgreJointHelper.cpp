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
#include "NxOgreJointHelper.h"
#include "NxOgreRigidBody.h"
#include "NxOgreJointDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       


void JointHelper::setGlobalAnchor(JointDescription& jdesc, const Vec3& globalAnchorPosition, RigidBody* a, RigidBody* b)
{
 NxFixedJointDesc desc;
 desc.actor[0] = a->getNxActor();
 desc.actor[1] = b->getNxActor();
 desc.setGlobalAnchor(globalAnchorPosition.as<NxVec3>());

 jdesc.mLocalAnchor[0].from<NxVec3>(desc.localAnchor[0]);
 jdesc.mLocalAnchor[1].from<NxVec3>(desc.localAnchor[1]);
}

void JointHelper::setGlobalAxis(JointDescription& jdesc, const Vec3& globalAxis, RigidBody* a, RigidBody* b)
{
 NxFixedJointDesc desc;
 desc.actor[0] = a->getNxActor();
 desc.actor[1] = b->getNxActor();
 desc.setGlobalAxis(globalAxis.as<NxVec3>());

 jdesc.mLocalAxis[0].from<NxVec3>(desc.localAxis[0]);
 jdesc.mLocalAxis[1].from<NxVec3>(desc.localAxis[1]);
}


                                                                                       

} // namespace NxOgre
