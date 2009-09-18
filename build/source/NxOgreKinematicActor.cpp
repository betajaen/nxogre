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
#include "NxOgreKinematicActor.h"

#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreRigidBodyPrototype.h"

                                                                                       

namespace NxOgre
{

                                                                                       


KinematicActor::KinematicActor(Scene* scene)
: RigidBody(),
  mScene(scene)
{
}

KinematicActor::KinematicActor(RigidBodyPrototype* prototype, Scene* scene)
: RigidBody(),
  mScene(scene)
{
 create(prototype, scene, &mShapes);
}

KinematicActor::~KinematicActor(void)
{
 destroy();
}


unsigned int KinematicActor::getClassType() const
{
 return Classes::_KinematicActor;
}


void KinematicActor::setGroup(GroupIdentifier actorGroup)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGroup(actorGroup, mActor);
}

GroupIdentifier KinematicActor::getGroup(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGroup(mActor);
}

void KinematicActor::setDominanceGroup(GroupIdentifier dominanceGroup)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGroup(dominanceGroup, mActor);
}

GroupIdentifier KinematicActor::getDominanceGroup(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getDominanceGroup(mActor);
}

void KinematicActor::resetPairFiltering(void)
{
 ::NxOgre::Functions::RigidBodyFunctions::resetPairFiltering(mActor);
}

bool KinematicActor::isDynamic(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::isDynamic(mActor);
}

Real KinematicActor::computeKineticEnergy(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::computeKineticEnergy(mActor);
}

void KinematicActor::setSolverIterationCount(unsigned int iterCount)
{
 ::NxOgre::Functions::RigidBodyFunctions::setSolverIterationCount(iterCount, mActor);
}

unsigned int KinematicActor::getSolverIterationCount(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getSolverIterationCount(mActor);
}

Real KinematicActor::getContactReportThreshold(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getContactReportThreshold(mActor);
}

void KinematicActor::setContactReportThreshold(Real threshold)
{
 ::NxOgre::Functions::RigidBodyFunctions::setContactReportThreshold(threshold, mActor);
}

unsigned int KinematicActor::getContactReportFlags(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getContactReportFlags(mActor);
}

void KinematicActor::setContactReportFlags(unsigned int flags)
{
 ::NxOgre::Functions::RigidBodyFunctions::setContactReportFlags(flags, mActor);
}

unsigned short KinematicActor::getForceFieldMaterial(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getForceFieldMaterial(mActor);
}

void KinematicActor::setForceFieldMaterial(unsigned short ffm)
{
 ::NxOgre::Functions::RigidBodyFunctions::setForceFieldMaterial(ffm, mActor);
}

void KinematicActor::setGlobalPose(const Matrix44& matrix)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalPose(matrix, mActor);
}

void KinematicActor::setGlobalPosition (const Vec3& r3)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalPosition(r3, mActor);
}

void KinematicActor::setGlobalOrientation(const Matrix33& r33)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalOrientation(r33, mActor);
}

void KinematicActor::setGlobalOrientationQuat(const Quat& quat)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalOrientationQuat(quat, mActor);
}

Matrix44 KinematicActor::getGlobalPose(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPose(mActor);
}

Vec3 KinematicActor::getGlobalPosition(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPosition(mActor);
}

Matrix33 KinematicActor::getGlobalOrientation(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientation(mActor);
}

Quat KinematicActor::getGlobalOrientationQuat(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientationQuat(mActor);
}


void KinematicActor::createShape(Shape*)
{
 //< \argh
}

void KinematicActor::releaseShape(Shape*)
{
 //< \argh
}

unsigned int KinematicActor::getNbShapes(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getNbShapes(mActor);
}

void KinematicActor::moveGlobalPose(const Matrix44& m44)
{
 ::NxOgre::Functions::RigidBodyFunctions::moveGlobalPose(m44, mActor);
}

void KinematicActor::moveGlobalPosition(const Vec3& r3)
{
 ::NxOgre::Functions::RigidBodyFunctions::moveGlobalPosition(r3, mActor);
}

void KinematicActor::moveGlobalOrientation (const Matrix33& r33)
{
 ::NxOgre::Functions::RigidBodyFunctions::moveGlobalOrientation(r33, mActor);
}

void KinematicActor::moveGlobalOrientationQuat (const Quat& q)
{
 ::NxOgre::Functions::RigidBodyFunctions::moveGlobalOrientationQuat(q, mActor);
}

                                                                                       

} // namespace NxOgre

                                                                                       
