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
 mRemoteDebugger->writeParameter(parameter.as<NxVec3>(), object, true, name, mask);
}

void RemoteDebugger::setParameter(const Vec3& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(parameter.as<NxVec3>(), object, false, name, mask);
}

void RemoteDebugger::createParameter(const SimplePlane& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(NxPlane(parameter.mNormal.as<NxVec3>(), parameter.mDistance), object, true, name, mask);
}

void RemoteDebugger::setParameter(const SimplePlane& parameter, void* object, const char* name, unsigned int mask)
{
 mRemoteDebugger->writeParameter(NxPlane(parameter.mNormal.as<NxVec3>(), parameter.mDistance), object, false, name, mask);
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
 return Vec3(mRemoteDebugger->getPickPoint());
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

                                                                                       
