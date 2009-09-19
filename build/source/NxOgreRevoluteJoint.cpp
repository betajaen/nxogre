/** File: NxOgreRevoluteJoint.cpp
    Created on: 15-Apr-09
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
#include "NxOgreRevoluteJoint.h"
#include "NxOgreJoint.h"
#include "NxOgreRigidBody.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreScene.h"
#include "NxOgreReason.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

RevoluteJoint::RevoluteJoint(RigidBody* first, RigidBody* second, const RevoluteJointDescription& desc)
: Joint(first, second), mRevoluteJoint(0)
{
 NxRevoluteJointDesc description;
 mRigidBodies[0] = first;
 mRigidBodies[1] = second;
 description.actor[0] = mRigidBodies[0]->getNxActor();
 if (mRigidBodies[1])
  description.actor[1] = mRigidBodies[1]->getNxActor();
 else
  description.actor[1] = 0;

 Functions::PrototypeFunctions::RevoluteJointDescriptionToNxRevoluteJointDescription(desc, description);
 
 if (description.isValid() == false)
 {
  SharedStringStream message(SharedStringStream::_LARGE); 
  
  message << "An error occured whilst creating a RevoluteJoint.\nThe reason(s) and cause(s) could be:\n\n";
  message << Reason::whyAsStream(description).get();
  NxOgre_ThrowError(message.get());
  return;
 }

 mJoint =  first->getScene()->getScene()->createJoint(description);
 mRevoluteJoint = mJoint->isRevoluteJoint();
}

RevoluteJoint::~RevoluteJoint(void)
{
 mRigidBodies[0]->getScene()->getScene()->releaseJoint(*mJoint);
}

void RevoluteJoint::setProjectionMode(Enums::JointProjectionMode mode)
{
 mRevoluteJoint->setProjectionMode(NxJointProjectionMode(int(mode)));
}

Enums::JointProjectionMode RevoluteJoint::getProjectionMode(void) const
{
 return Enums::JointProjectionMode(int(mRevoluteJoint->getProjectionMode()));
}

Enums::JointFunctionType RevoluteJoint::getJointType()
{
 return Enums::JointFunctionType_Revolute;
}

void RevoluteJoint::setLimits(const JointLimitPairDescription& desc)
{
 NxJointLimitPairDesc pair;
 Functions::PrototypeFunctions::JointLimitDescriptionToNxJointLimitDesc(desc.first, pair.low);
 Functions::PrototypeFunctions::JointLimitDescriptionToNxJointLimitDesc(desc.second, pair.high);
 mRevoluteJoint->setLimits(pair);
}

JointLimitPairDescription RevoluteJoint::getLimits(void)
{
 NxJointLimitPairDesc pair;
 JointLimitPairDescription out;
 mRevoluteJoint->getLimits(pair);
 out.first.mRestitution = pair.low.restitution;
 out.first.mValue = pair.low.value;
 out.second.mRestitution = pair.high.restitution;
 out.second.mValue = pair.high.value;
 return out;
}

void RevoluteJoint::setMotor(const MotorDescription& in)
{
 NxMotorDesc motor;
 Functions::PrototypeFunctions::MotorDescriptionToNxMotorDesc(in, motor);
 mRevoluteJoint->setMotor(motor);
}

MotorDescription RevoluteJoint::getMotor(void)
{
 MotorDescription out;
 NxMotorDesc motorDesc;
 mRevoluteJoint->getMotor(motorDesc);
 out.mFreeSpin = motorDesc.freeSpin;
 out.mMaxForce = motorDesc.maxForce;
 out.mVelocityTarget = motorDesc.velTarget;
 return out;
}

void RevoluteJoint::setSpring(const SpringDescription& in)
{
 NxSpringDesc desc;
 Functions::PrototypeFunctions::SpringDescriptionToNxSpringDesc(in, desc);
 mRevoluteJoint->setSpring(desc);
}

SpringDescription RevoluteJoint::getSpring(void)
{
 SpringDescription out;
 NxSpringDesc spring;
 mRevoluteJoint->getSpring(spring);
 out.mDamper = spring.damper;
 out.mSpring = spring.spring;
 out.mTargetValue = spring.targetValue;
 return out;
}

Real RevoluteJoint::getAngle(void)
{
 return mRevoluteJoint->getAngle();
}

Real RevoluteJoint::getVelocity(void)
{
 return mRevoluteJoint->getVelocity();
}

void RevoluteJoint::setRevoluteJointFlags(unsigned int flags)
{
 mRevoluteJoint->setFlags(flags);
}

unsigned int RevoluteJoint::getRevoluteJointFlags(void)
{
 return mRevoluteJoint->getFlags();
}

                                                                                       

} // namespace NxOgre

                                                                                       
