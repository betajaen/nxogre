/** File: NxOgreJoint.cpp
    Created on: 14-Apr-09
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
 mRigidBodies[0] = 0;
 mRigidBodies[1] = 0;
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
 mJoint->setGlobalAnchor(Functions::XYZ<Vec3, NxVec3>(vec));
}

void Joint::setGlobalAxis(const Vec3& vec)
{
 mJoint->setGlobalAxis(Functions::XYZ<Vec3, NxVec3>(vec));
}

Vec3 Joint::getGlobalAnchor(void) const
{
 return Functions::XYZ<NxVec3, Vec3>(mJoint->getGlobalAnchor());
}

Vec3 Joint::getGlobalAxis(void) const
{
 return Functions::XYZ<NxVec3, Vec3>(mJoint->getGlobalAxis());
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
 mJoint->setLimitPoint(Functions::XYZ<Vec3, NxVec3>(point), pointIsOnRigidBody2);
}

bool Joint::getLimitPoint(const Vec3& worldLimitPoint) const
{
 return mJoint->getLimitPoint(Functions::XYZ<Vec3, NxVec3>(worldLimitPoint));
}

void Joint::addLimitPoint(const Vec3& normal, const Vec3& pointInPlane, Real restitution)
{
 mJoint->addLimitPlane(Functions::XYZ<Vec3, NxVec3>(normal), Functions::XYZ<Vec3, NxVec3>(pointInPlane), restitution);
}

void Joint::purgeLimitPlanes(void)
{
 mJoint->purgeLimitPlanes();
}

                                                                                       

} // namespace NxOgre

                                                                                       
