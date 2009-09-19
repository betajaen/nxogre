/** File: NxOgreKinematicActor.cpp
    Created on: 20-Nov-08
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

                                                                                       
