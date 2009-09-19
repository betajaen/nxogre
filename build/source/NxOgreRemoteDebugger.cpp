/** File: NxOgreRemoteDebugger.cpp
    Created on: 3-Apr-09
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
#include "NxOgreRemoteDebugger.h"
#include "NxOgreWorld.h"
#include "NxOgreFunctions.h"
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

RemoteDebugger::RemoteDebugger(World* world)
: mWorld(world), mRemoteDebugger(0)
{
 mRemoteDebugger = mWorld->getPhysXSDK()->getFoundationSDK().getRemoteDebugger();
}

RemoteDebugger::~RemoteDebugger(void)
{
 if (isConnected())
  disconnect();
}

void RemoteDebugger::connect(const char* address, unsigned int port, unsigned int eventMask)
{
 mRemoteDebugger->connect(address, port, eventMask);
}

void RemoteDebugger::disconnect(void)
{
 mRemoteDebugger->disconnect();
}

void RemoteDebugger::flush(void)
{
 mRemoteDebugger->flush();
}

bool RemoteDebugger::isConnected(void) const
{
 return mRemoteDebugger->isConnected();
}

void RemoteDebugger::frameBreak(void)
{
 mRemoteDebugger->frameBreak();
}

void RemoteDebugger::createObject(void* object, Enums::RemoteDebuggerObjectType type, const char *className, unsigned int mask)
{
 mRemoteDebugger->createObject(object, NxRemoteDebuggerObjectType(int(type)), className, mask);
}

void RemoteDebugger::removeObject(void* object, unsigned int mask)
{
 mRemoteDebugger->removeObject(object, mask);
}

void RemoteDebugger::addChild(void* object, void* child, unsigned int mask)
{
 mRemoteDebugger->addChild(object, child, mask);
}

void RemoteDebugger::removeChild(void* object, void* child, unsigned int mask)
{
 mRemoteDebugger->removeChild(object, child, mask);
}

void RemoteDebugger::createParameter(const float& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, true, name, mask);
}

void RemoteDebugger::setParameter(const float& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, false, name, mask);
}

void RemoteDebugger::createParameter(const unsigned int& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, true, name, mask);
}

void RemoteDebugger::setParameter(const unsigned int& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, false, name, mask);
}

void RemoteDebugger::createParameter(const Vec3& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(Functions::XYZ<Vec3, NxVec3>(parameter), object, true, name, mask);
}

void RemoteDebugger::setParameter(const Vec3& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(Functions::XYZ<Vec3, NxVec3>(parameter), object, false, name, mask);
}

void RemoteDebugger::createParameter(const SimplePlane& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(NxPlane(Functions::XYZ<Vec3, NxVec3>(parameter.mNormal), parameter.mDistance), object, true, name, mask);
}

void RemoteDebugger::setParameter(const SimplePlane& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(NxPlane(Functions::XYZ<Vec3, NxVec3>(parameter.mNormal), parameter.mDistance), object, false, name, mask);
}
#if 0
void RemoteDebugger::createParameter(const Matrix44& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, true, name, mask);
}

void RemoteDebugger::setParameter(const Matrix44& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, false, name, mask);
}

void RemoteDebugger::createParameter(const Matrix33& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, true, name, mask);
}

void RemoteDebugger::setParameter(const Matrix33& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, false, name, mask);
}
#endif
void RemoteDebugger::createParameter(const unsigned char* parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, true, name, mask);
}

void RemoteDebugger::setParameter(const unsigned char* parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, false, name, mask);
}

void RemoteDebugger::createParameter(const char* parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, true, name, mask);
}

void RemoteDebugger::setParameter(const char* parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, false, name, mask);
}

void RemoteDebugger::createParameter(const bool& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, true, name, mask);
}

void RemoteDebugger::setParameter(const bool& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, false, name, mask);
}

void RemoteDebugger::createParameter(const void* parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, true, name, mask);
}

void RemoteDebugger::setParameter(const void* parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter, object, false, name, mask);
}

void RemoteDebugger::setMask(unsigned int mask)
{
 mRemoteDebugger->setMask(mask);
}

unsigned int RemoteDebugger::getMask(void)
{
 return mRemoteDebugger->getMask();
}

void* RemoteDebugger::getPickedObject()
{
 return mRemoteDebugger->getPickedObject();
}

Vec3 RemoteDebugger::getPickedPoint(void)
{
 return Functions::XYZ<NxVec3, Vec3>(mRemoteDebugger->getPickPoint());
}

#if 0
void RemoteDebugger::registerListener(RemoteDebuggerListener*)
{
}

void RemoteDebugger::unregisterListener(RemoteDebuggerListener*)
{
}
#endif
                                                                                       

} // namespace NxOgre

                                                                                       
