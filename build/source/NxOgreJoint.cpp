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
#include "NxOgreJoint.h"
#include "NxOgreFunctions.h"
#include "NxOgreRigidBody.h"
#include "NxOgreScene.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       


Joint::Joint(RigidBody* first, RigidBody* second)
: mJoint(0)
{
 mRigidBodies[0] = first;
 mRigidBodies[1] = second;
}

Joint::~Joint(void)
{
 if (mJoint)
  mRigidBodies[0]->getScene()->getScene()->releaseJoint(*mJoint);
}

Enums::JointFunctionType Joint::getJointType()
{
 return Enums::JointFunctionType_Count;
}

RigidBody* Joint::getFirstRigidBody(void)
{
 return mRigidBodies[0];
}

RigidBody* Joint::getSecondRigidBody(void)
{
 return mRigidBodies[1];
}

void Joint::setGlobalAnchor(const Vec3& vec)
{
 mJoint->setGlobalAnchor(vec.as<NxVec3>());
}

void Joint::setGlobalAxis(const Vec3& vec)
{
 mJoint->setGlobalAxis(vec.as<NxVec3>());
}

Vec3 Joint::getGlobalAnchor(void) const
{
 return Vec3(mJoint->getGlobalAnchor());
}

Vec3 Joint::getGlobalAxis(void) const
{
 return Vec3(mJoint->getGlobalAxis());
}

Enums::JointState Joint::getState(void)
{
 if (mJoint == 0)
  return Enums::JointState_Dead;
 return Enums::JointState(int(mJoint->getState()));
}

void Joint::setBreakable(Real maxForce, Real maxTorque)
{
 mJoint->setBreakable(maxForce, maxTorque);
}

void Joint::getBreakable(Real& force, Real& torque)
{
 mJoint->getBreakable(force, torque);
}

Real Joint::getBreakableForce(void)
{
 Real force, torque;
 mJoint->getBreakable(force, torque);
 return force;
}

Real Joint::getBreakableTorque(void)
{
 Real force, torque;
 mJoint->getBreakable(force, torque);
 return torque;
}

void Joint::setSolverExtrapolationFactor(Real solverExtrapolationFactor)
{
 mJoint->setSolverExtrapolationFactor(solverExtrapolationFactor);
}

Real Joint::getSolverExtrapolationFactor(void) const
{
 return mJoint->getSolverExtrapolationFactor();
}

void Joint::setUseAccelerationSpring(Enums::JointSpringType type)
{
 mJoint->setUseAccelerationSpring(bool(type));
}

Enums::JointSpringType Joint::getUseAccelerationSpring(void) const
{
 return Enums::JointSpringType(int(mJoint->getUseAccelerationSpring()));
}

void Joint::setLimitPoint(const Vec3& point, bool pointIsOnRigidBody2)
{
 mJoint->setLimitPoint(point.as<NxVec3>(), pointIsOnRigidBody2);
}

bool Joint::getLimitPoint(const Vec3& worldLimitPoint) const
{
 return mJoint->getLimitPoint(worldLimitPoint.as<NxVec3>());
}

void Joint::addLimitPoint(const Vec3& normal, const Vec3& pointInPlane, Real restitution)
{
 mJoint->addLimitPlane(normal.as<NxVec3>(), pointInPlane.as<NxVec3>(), restitution);
}

void Joint::purgeLimitPlanes(void)
{
 mJoint->purgeLimitPlanes();
}

String Joint::to_s() const
{
 return NxOgre::to_s((void*)this, String("Joint") );
}

                                                                                       

} // namespace NxOgre

                                                                                       
