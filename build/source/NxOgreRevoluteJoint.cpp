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
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(description), Classes::_RevoluteJoint);
  return;
 }

 mJoint =  first->getScene()->getScene()->createJoint(description);
 mRevoluteJoint = mJoint->isRevoluteJoint();
}

RevoluteJoint::~RevoluteJoint()
{
 mRigidBodies[0]->getScene()->getScene()->releaseJoint(*mJoint);
}

void RevoluteJoint::setProjectionMode(Enums::JointProjectionMode mode)
{
 mRevoluteJoint->setProjectionMode(NxJointProjectionMode(int(mode)));
}

Enums::JointProjectionMode RevoluteJoint::getProjectionMode() const
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

JointLimitPairDescription RevoluteJoint::getLimits()
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

MotorDescription RevoluteJoint::getMotor()
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

SpringDescription RevoluteJoint::getSpring()
{
 SpringDescription out;
 NxSpringDesc spring;
 mRevoluteJoint->getSpring(spring);
 out.mDamper = spring.damper;
 out.mSpring = spring.spring;
 out.mTargetValue = spring.targetValue;
 return out;
}

Real RevoluteJoint::getAngle()
{
 return mRevoluteJoint->getAngle();
}

Real RevoluteJoint::getVelocity()
{
 return mRevoluteJoint->getVelocity();
}

void RevoluteJoint::setRevoluteJointFlags(unsigned int flags)
{
 mRevoluteJoint->setFlags(flags);
}

unsigned int RevoluteJoint::getRevoluteJointFlags()
{
 return mRevoluteJoint->getFlags();
}

                                                                                       

} // namespace NxOgre

                                                                                       
