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
#include "NxOgreWorld.h"
#include "NxOgreWorldDescription.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreErrorStream.h"
#include "NxOgreTimeController.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreMeshManager.h"
#include "NxOgreHeightFieldManager.h"
#include "NxOgreReason.h"
#include "NxOgrePhysXOutputStream.h"
#include "NxOgrePhysXUserAllocator.h"
#include "NxOgreScene.h"
#include "NxOgreSceneDescription.h"
#include "NxOgreCallback.h"
#include "NxOgreVisualDebugger.h"
#include "NxOgreRemoteDebugger.h"
#include "NxOgreUtil.h"

#include "NxPhysics.h"
#include "NxCooking.h"

                                                                                       

namespace NxOgre
{

                                                                                       

World* World::sWorldInstance = 0;
NxCookingInterface* World::mCookingInterface = 0;

                                                                                       

void World::precreateSingletons(void)
{
 
 mCookingInterface = NxGetCookingLib(NX_PHYSICS_SDK_VERSION);

 if (mCookingInterface == 0)
 {
  throw PhysXSystemSoftwareException(__FILE__, __LINE__, Classes::_World); 
  return;
 }
 
 mCookingInterface->NxInitCooking();
 
 if (ErrorStream::getSingleton() == 0)
  NXOGRE_NEW_NXOGRE ErrorStream();
 if (ResourceSystem::getSingleton() == 0)
  NXOGRE_NEW_NXOGRE ResourceSystem();
 if (MeshManager::getSingleton() == 0)
  NXOGRE_NEW_NXOGRE MeshManager();
 if (HeightFieldManager::getSingleton() == 0)
  NXOGRE_NEW_NXOGRE HeightFieldManager();
 if (TimeController::getSingleton() == 0)
  NXOGRE_NEW_NXOGRE TimeController();
 
#ifdef NXOGRE_OPTIONS_USE_LOG
 {
  Resource* resource = ResourceSystem::getSingleton()->open(Path("file://NxOgre.log"), Enums::ResourceAccess_WriteOnly);
  if (resource)
   ErrorStream::getSingleton()->setLogResource(resource);
 }
#endif
 
}

void World::destroySingletons(void)
{
 
 if (ErrorStream::getSingleton() != 0)
 {
  ErrorStream* error_stream = ErrorStream::getSingleton();
  NXOGRE_DELETE_NXOGRE(error_stream);
 }

 if (TimeController::getSingleton() != 0)
 {
  TimeController* time_controller = TimeController::getSingleton();
  NXOGRE_DELETE_NXOGRE(time_controller);
 }

 if (ResourceSystem::getSingleton() != 0)
 {
  ResourceSystem* resource_system = ResourceSystem::getSingleton();
  NXOGRE_DELETE_NXOGRE(resource_system);
 }
 
 if (MeshManager::getSingleton() != 0)
 {
  MeshManager* mesh_manager = MeshManager::getSingleton();
  NXOGRE_DELETE_NXOGRE(mesh_manager);
 }
 
 if (HeightFieldManager::getSingleton() != 0)
 {
  HeightFieldManager* hf_manager = HeightFieldManager::getSingleton();
  NXOGRE_DELETE_NXOGRE(hf_manager);
 }
 
 mCookingInterface->NxCloseCooking();
 
}

World* World::createWorld(const WorldDescription& description)
{
 
 if (World::sWorldInstance != 0)
  return 0;
 
 precreateSingletons();
 World::sWorldInstance = NXOGRE_NEW_NXOGRE World(description);
 return World::sWorldInstance;
 
}

void World::destroyWorld(bool also_destroy_singletons)
{
 
 if (World::sWorldInstance == 0)
  return;
 
 // Clear all scenes
 World::sWorldInstance->mScenes.clear();
 
 // Clear all singletons
 if (also_destroy_singletons)
  destroySingletons();
 
 // Shutdown PhysX.
 NXOGRE_DELETE_NXOGRE(World::sWorldInstance);
 
}

World::World(const WorldDescription& description)
: mSDK(0), mDeadSDK(false), mPhysXOutputStream(0), mPhysXUserAllocator(0), mNullCallback(0)
{
 
 mPhysXOutputStream = NXOGRE_NEW_NXOGRE PhysXOutputStream();
 mPhysXUserAllocator = NXOGRE_NEW_NXOGRE PhysXUserAllocator();
  
 NxPhysicsSDKDesc sdk_description;
 sdk_description.cookerThreadMask = description.mCookerThreadMask;
 if (description.mNoHardware)
  sdk_description.flags |= NX_SDKF_NO_HARDWARE;
 sdk_description.hwConvexMax = description.mHardwareMaximumConvex;
 sdk_description.hwPageMax= description.mHardwareMaximumPage;
 sdk_description.hwPageSize = description.mHardwarePageSize;
 
  
 NxSDKCreateError errorCode = NXCE_NO_ERROR;
 mSDK = NxCreatePhysicsSDK(NX_PHYSICS_SDK_VERSION, mPhysXUserAllocator, mPhysXOutputStream, sdk_description, &errorCode); 
 
 
 if (errorCode != NXCE_NO_ERROR || mSDK == 0)
 {
  
  if (errorCode == NXCE_PHYSX_NOT_FOUND)
  {
    throw PhysXSystemSoftwareException(__FILE__, __LINE__, Classes::_World);
  }
  else
  {
    NxOgre_ThrowException(PhysXSDKCreationFailedException, Reason::Exceptionise(sdk_description, mSDK == 0, errorCode), Classes::_World);
  }
  
  mDeadSDK = true;
  return;
 }

 mNullCallback = NXOGRE_NEW Callback();

 mVisualDebugger = new VisualDebugger(this);
 mRemoteDebugger = new RemoteDebugger(this);

}

World::~World(void)
{
 
 NXOGRE_DELETE_NXOGRE(mRemoteDebugger);
 NXOGRE_DELETE_NXOGRE(mVisualDebugger);
 
 mScenes.clear();
 
 if (!mDeadSDK && mSDK)
  mSDK->release();
 
 NXOGRE_DELETE_NXOGRE(mNullCallback);
 NXOGRE_DELETE_NXOGRE(mPhysXOutputStream);
 NXOGRE_DELETE_NXOGRE(mPhysXUserAllocator);
 
}

bool World::isDead(void) const
{
 return mDeadSDK;
}

Scene* World::createScene(const NxOgre::SceneDescription& description)
{
 Scene* scene = NXOGRE_NEW_NXOGRE Scene(description, mSDK);
 StringHash hash = scene->getNameHash();
 mScenes.insert(hash, scene);
 return scene;
}

void World::destroyScene(Scene* scene)
{
 if (scene == 0)
  return;
 
 mScenes.erase(scene->getNameHash());
 
}

bool World::hasHardware(void) const
{
 if (mDeadSDK)
  return false;
 return mSDK->getHWVersion() != NX_HW_VERSION_NONE;
}

World* World::getWorld()
{
 return sWorldInstance;
}

Callback* World::getNullCallback()
{
 return mNullCallback;
}

VisualDebugger* World::getVisualDebugger()
{
 return mVisualDebugger;
}

RemoteDebugger* World::getRemoteDebugger()
{
 return mRemoteDebugger;
}

World::SceneIterator World::getScenes()
{
 return SceneIterator(mScenes);
}

NxPhysicsSDK* World::getPhysXSDK(void)
{
 return mSDK;
}

NxCookingInterface* World::getPhysXCookingInterface(void)
{
 return mCookingInterface;
}

                                                                                       

} // namespace NxOgre

                                                                                       
