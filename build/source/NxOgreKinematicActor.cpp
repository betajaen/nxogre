/** File: NxOgreKinematicActor.cpp
    Created on: 20-Nov-08
    Author: Robin Southern "betajaen"
    SVN: $Id$

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

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       


KinematicActor::KinematicActor(Shapes shapes, Scene* scene)
: RigidBody(),
  mScene(scene),
  mShapes(shapes)
{
}

KinematicActor::KinematicActor(RigidBodyPrototype* prototype, Scene* scene)
: RigidBody(),
  mScene(scene)
{
 create(prototype, scene);
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
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setGroup(actorGroup, mActor);
}

GroupIdentifier KinematicActor::getGroup(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getGroup(mActor);
}

void KinematicActor::setDominanceGroup(GroupIdentifier dominanceGroup)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setGroup(dominanceGroup, mActor);
}

GroupIdentifier KinematicActor::getDominanceGroup(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getDominanceGroup(mActor);
}

void KinematicActor::resetPairFiltering(void)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::resetPairFiltering(mActor);
}

bool KinematicActor::isDynamic(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::isDynamic(mActor);
}

Real KinematicActor::computeKineticEnergy(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::computeKineticEnergy(mActor);
}

void KinematicActor::setSolverIterationCount(unsigned int iterCount)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setSolverIterationCount(iterCount, mActor);
}

unsigned int KinematicActor::getSolverIterationCount(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getSolverIterationCount(mActor);
}

Real KinematicActor::getContactReportThreshold(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getContactReportThreshold(mActor);
}

void KinematicActor::setContactReportThreshold(Real threshold)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setContactReportThreshold(threshold, mActor);
}

unsigned int KinematicActor::getContactReportFlags(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getContactReportFlags(mActor);
}

void KinematicActor::setContactReportFlags(unsigned int flags)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setContactReportFlags(flags, mActor);
}

unsigned short KinematicActor::getForceFieldMaterial(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getForceFieldMaterial(mActor);
}

void KinematicActor::setForceFieldMaterial(unsigned short ffm)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setForceFieldMaterial(ffm, mActor);
}

void KinematicActor::setGlobalPose(const Matrix44& matrix)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setGlobalPose(matrix, mActor);
}

void KinematicActor::setGlobalPosition (const Vec3& r3)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setGlobalPosition(r3, mActor);
}

void KinematicActor::setGlobalOrientation(const Matrix33& r33)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setGlobalOrientation(r33, mActor);
}

void KinematicActor::setGlobalOrientationQuat(const Quat& quat)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::setGlobalOrientationQuat(quat, mActor);
}

Matrix44 KinematicActor::getGlobalPose(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getGlobalPose(mActor);
}

Vec3 KinematicActor::getGlobalPosition(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getGlobalPosition(mActor);
}

Matrix33 KinematicActor::getGlobalOrientation(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getGlobalOrientation(mActor);
}

Quat KinematicActor::getGlobalOrientationQuat(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getGlobalOrientationQuat(mActor);
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
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::getNbShapes(mActor);
}

void KinematicActor::moveGlobalPose(const Matrix44& m44)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::moveGlobalPose(m44, mActor);
}

void KinematicActor::moveGlobalPosition(const Vec3& r3)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::moveGlobalPosition(r3, mActor);
}

void KinematicActor::moveGlobalOrientation (const Matrix33& r33)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::moveGlobalOrientation(r33, mActor);
}

void KinematicActor::moveGlobalOrientationQuat (const Vec4& r4)
{
 ::NxOgre_Namespace::Functions::RigidBodyFunctions::moveGlobalOrientationQuat(r4, mActor);
}

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       
