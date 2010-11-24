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
#include "NxOgrePrincipalScene.h"
#include "NxOgreAuxiliaryScene.h"
#include "NxPhysics.h"
#include "NxCooking.h"

#if NxOgreHasCharacterController == 1
#include "ControllerManager.h"
#include "NxOgrePhysXControllerHitReport.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

World* World::sWorldInstance = 0;
NxCookingInterface* World::mCookingInterface = 0;

                                                                                       

void World::precreateSingletons()
{
 
 mCookingInterface = NxGetCookingLib(NX_PHYSICS_SDK_VERSION);

 if (mCookingInterface == 0)
 {
  throw PhysXSystemSoftwareException(__FILE__, __LINE__, Classes::_World); 
  return;
 }
 
 mCookingInterface->NxInitCooking();
 
 if (ErrorStream::getSingleton() == 0)
 {
  NxOgre_DebugPrint_Core("World::precreateSingletons -- Creating ErrorStream");
  GC::safe_new0<ErrorStream>(NXOGRE_GC_THIS);
 }

 if (ResourceSystem::getSingleton() == 0)
 {
  NxOgre_DebugPrint_Core("World::precreateSingletons -- Creating ResourceSystem");
  GC::safe_new0<ResourceSystem>(NXOGRE_GC_THIS);
 }

 if (MeshManager::getSingleton() == 0)
 {
  NxOgre_DebugPrint_Core("World::precreateSingletons -- Creating MeshManager");
  GC::safe_new0<MeshManager>(NXOGRE_GC_THIS);
 }

 if (HeightFieldManager::getSingleton() == 0)
 {
  NxOgre_DebugPrint_Core("World::precreateSingletons -- Creating HeightFieldManager");
  GC::safe_new0<HeightFieldManager>(NXOGRE_GC_THIS);
 }
 
#ifdef NXOGRE_OPTIONS_USE_LOG
 {
  Resource* resource = ResourceSystem::getSingleton()->open(Path("file://NxOgre.log"), Enums::ResourceAccess_WriteOnly);
  if (resource)
   ErrorStream::getSingleton()->setLogResource(resource);
 }
#endif
 
 NxOgre_DebugPrint_Core("World::precreateSingletons -- Function Exit -- Okay");

}

void World::destroySingletons()
{
 

 if (ErrorStream::getSingleton() != 0)
 {
  NxOgre_DebugPrint_Core("World::precreateSingletons -- Destroying ErrorStream");
  GC::safe_delete(ErrorStream::getSingleton(), NXOGRE_GC_THIS);
  ResourceSystem::sSingleton = 0;
 }

 if (ResourceSystem::getSingleton() != 0)
 {
  NxOgre_DebugPrint_Core("World::precreateSingletons -- Destroying ResourceSystem");
  GC::safe_delete(ResourceSystem::getSingleton(), NXOGRE_GC_THIS);
  ResourceSystem::sSingleton = 0;
 }
 
 if (MeshManager::getSingleton() != 0)
 {
  NxOgre_DebugPrint_Core("World::precreateSingletons -- Destroying MeshManager");
  GC::safe_delete(MeshManager::getSingleton(), NXOGRE_GC_THIS);
  MeshManager::sSingleton = 0;
 }
 
 if (HeightFieldManager::getSingleton() != 0)
 {
  NxOgre_DebugPrint_Core("World::precreateSingletons -- Destroying HeightFieldManager");
  GC::safe_delete(HeightFieldManager::getSingleton(), NXOGRE_GC_THIS);
  HeightFieldManager::sSingleton = 0;
 }
 
 mCookingInterface->NxCloseCooking();
 
}

World* World::createWorld(const WorldDescription& description)
{
 
 
 if (World::sWorldInstance != 0)
 {
  NxOgre_DebugPrint_Core("World::createWorld -- World could not be created. Reason: sWorldInstance is not null. sWorldInstance = '" << sWorldInstance << "'");
  return 0;
 }
 
 precreateSingletons();
 World::sWorldInstance = GC::safe_new1<World>(description, NXOGRE_GC_THIS);
 NxOgre_DebugPrint_Core("World::createWorld -- World was created, pointer is = '" << sWorldInstance << "'");
 return World::sWorldInstance;
 
}

void World::destroyWorld(bool also_destroy_singletons)
{
 
 if (World::sWorldInstance == 0)
 {
  NxOgre_DebugPrint_Core("World::destroyWorld -- World could not be destroyed. Reason: sWorldInstance pointer is null.");
  return;
 }
 
#if NXOGRE_DEBUG_MEMORY == 1
 GC::gc_debugger_last_frame();
#endif
 
#if NxOgreHasCharacterController == 1
 if (World::sWorldInstance->mControllerManager != 0)
 {
  NxReleaseControllerManager(World::sWorldInstance->mControllerManager);
  World::sWorldInstance->mControllerManager = 0;
 }
#endif
 
 // Clear all scenes
 World::sWorldInstance->mScenes.remove_all();
 
 // Clear all singletons
 if (also_destroy_singletons)
  destroySingletons();
 
 // Shutdown PhysX.
 GC::safe_delete(World::sWorldInstance, NXOGRE_GC_THIS);
 World::sWorldInstance = 0;
 
 NxOgre_DebugPrint_Core("World::destroyWorld -- World is destroyed.");
 
}

World::World(const WorldDescription& description)
: mSDK(0), mDeadSDK(false), mPhysXOutputStream(0), mPhysXUserAllocator(0), mNullCallback(0)
#if NxOgreHasCharacterController == 1
 , mControllerManager(0)
 , mPhysXCharacterHitReport(0)
#endif
{
 
 mPhysXOutputStream = GC::safe_new0<PhysXOutputStream>(NXOGRE_GC_THIS);
 mPhysXUserAllocator = GC::safe_new0<PhysXUserAllocator>(NXOGRE_GC_THIS);
 mNullCallback = GC::safe_new0<Callback>(NXOGRE_GC_THIS);

 NxPhysicsSDKDesc sdk_description;
 sdk_description.cookerThreadMask = description.mCookerThreadMask;
 if (description.mNoHardware)
  sdk_description.flags |= NX_SDKF_NO_HARDWARE;
 sdk_description.hwConvexMax = description.mHardwareMaximumConvex;
 sdk_description.hwPageMax = description.mHardwareMaximumPage;
 sdk_description.hwPageSize = 65536; // Restriction imposed by NxPhysXSDKDesc
 
  
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


 mVisualDebugger = GC::safe_new1<VisualDebugger>(this);
 mRemoteDebugger = GC::safe_new1<RemoteDebugger>(this);
 
 
}

World::~World()
{
 
 
 GC::safe_delete(mRemoteDebugger, NXOGRE_GC_THIS);
 GC::safe_delete(mVisualDebugger, NXOGRE_GC_THIS);
 
 mScenes.remove_all();
 
 if (!mDeadSDK && mSDK)
  mSDK->release();
 
 GC::safe_delete(mNullCallback, NXOGRE_GC_THIS);
 GC::safe_delete(mPhysXOutputStream, NXOGRE_GC_THIS);
 GC::safe_delete(mPhysXUserAllocator, NXOGRE_GC_THIS);
 
}

bool World::isDead() const
{
 return mDeadSDK;
}

Scene* World::createScene(const NxOgre::SceneDescription& description, Enums::SceneType scene_type)
{
 
 Scene* scene = 0;
 
 if (scene_type == Enums::SceneType_Prinicipal)
  scene = GC::safe_new2<PrincipalScene>(description, mSDK, NXOGRE_GC_THIS);
 else
  scene = GC::safe_new2<AuxiliaryScene>(description, mSDK, NXOGRE_GC_THIS);
 
 mScenes.insert(scene->getNameHash(), scene);
 
 return scene;
 
}

void World::destroyScene(Scene* scene)
{
 
 if (scene == 0)
  return;
 
 mScenes.remove(scene->getNameHash(), scene);
 
}

bool World::hasHardware() const
{
 if (mDeadSDK)
  return false;
 return mSDK->getHWVersion() != NX_HW_VERSION_NONE;
}

World* World::getWorld()
{
 return sWorldInstance;
}

World* World::getSingleton()
{
 return sWorldInstance;
}

Callback* World::getNullCallback() const
{
 return mNullCallback;
}

VisualDebugger* World::getVisualDebugger() const
{
 return mVisualDebugger;
}

RemoteDebugger* World::getRemoteDebugger() const
{
 return mRemoteDebugger;
}

World::SceneIterator World::getScenes() const
{
 return mScenes.elements();
}

NxPhysicsSDK* World::getPhysXSDK() const
{
 return mSDK;
}

NxCookingInterface* World::getPhysXCookingInterface() const
{
 return mCookingInterface;
}


#if NxOgreHasCharacterController == 1

NxControllerManager* World::getPhysXControllerManager()
{
 if (mControllerManager == 0)
  mControllerManager = NxCreateControllerManager(mPhysXUserAllocator);

 return mControllerManager;
}

PhysXCharacterHitReport* World::getPhysXCharacterHitReport()
{
 if (mPhysXCharacterHitReport == 0)
  mPhysXCharacterHitReport = new PhysXCharacterHitReport();

 return mPhysXCharacterHitReport;
}

#endif

void World::advance(Real deltaTime)
{
 // Primary Simulation and Rendering.
 for (SceneIterator it = mScenes.elements(); it != it.end(); it++)
 {
  it->simulate(deltaTime);
  if (it->canRender() == false)
   mSceneSecondaryBuffer.push_back((*it));
  else
   it->render(deltaTime);
 } // for

 // Secondary Rendering
 if (mSceneSecondaryBuffer.size())
 {
  for (SceneBufferIterator it = mSceneSecondaryBuffer.elements(); it != it.end(); it++)
  {
   if (it->canRender() == false)
    mSceneTertiaryBuffer.push_back((*it));
   else
    it->render(deltaTime);
  } // for
  mSceneSecondaryBuffer.remove_all();
 } // if

 // Tertiary Rendering
 if (mSceneTertiaryBuffer.size())
 {
  for (SceneBufferIterator it = mSceneTertiaryBuffer.elements(); it != it.end(); it++)
  {
   while(true)
   {
    if (it->canRender() == false)
     continue;
    it->render(deltaTime);
    break;
   } // while
  } // for
  mSceneTertiaryBuffer.remove_all();
 } // if

}

void World::setSkinWidth(float value)
{
 mSDK->setParameter(NX_SKIN_WIDTH, value);
}

float World::getSkinWidth() const
{
 return mSDK->getParameter(NX_SKIN_WIDTH);
}

void World::setDefaultSleepLinearVelocitySquared(float value)
{
 mSDK->setParameter(NX_DEFAULT_SLEEP_LIN_VEL_SQUARED, value);
}

float World::getDefaultSleepLinearVelocitySquared() const
{
 return mSDK->getParameter(NX_DEFAULT_SLEEP_LIN_VEL_SQUARED);
}

void World::setDefaultSleepAngularVelocitySquared(float value)
{
 mSDK->setParameter(NX_DEFAULT_SLEEP_ANG_VEL_SQUARED, value);
}

float World::getDefaultSleepAngularVelocitySquared() const
{
 return mSDK->getParameter(NX_DEFAULT_SLEEP_ANG_VEL_SQUARED);
}

void World::setBounceThreshold(float value)
{
 mSDK->setParameter(NX_BOUNCE_THRESHOLD, value);
}

float World::getBounceThreshold() const
{
 return mSDK->getParameter(NX_BOUNCE_THRESHOLD);
}

void World::setDynamicFrictionScaling(float value)
{
 mSDK->setParameter(NX_DYN_FRICT_SCALING, value);
}

float World::getDynamicFrictionScaling() const
{
 return mSDK->getParameter(NX_DYN_FRICT_SCALING);
}

void World::setStaticFrictionScaling(float value)
{
 mSDK->setParameter(NX_STA_FRICT_SCALING, value);
}

float World::getStaticFrictionScaling() const
{
 return mSDK->getParameter(NX_STA_FRICT_SCALING);
}

void World::setMaxAngularVelocity(float value)
{
 mSDK->setParameter(NX_MAX_ANGULAR_VELOCITY, value);
}

float World::getMaxAngularVelocity() const
{
 return mSDK->getParameter(NX_MAX_ANGULAR_VELOCITY);
}

void World::setCCDEnabled(bool value)
{
 mSDK->setParameter(NX_CONTINUOUS_CD, float(value));
}

bool World::getCCDEnabled() const
{
 return mSDK->getParameter(NX_CONTINUOUS_CD) == 1.0f;
}

void World::setCCDEpsilon(float value)
{
 mSDK->setParameter(NX_CCD_EPSILON, value);
}

float World::getCCDEpilson() const
{
 return mSDK->getParameter(NX_CCD_EPSILON);
}

void World::setAdaptiveForce(float value)
{
 mSDK->setParameter(NX_ADAPTIVE_FORCE, value);
}

float World::getAdaptiveForce() const
{
 return mSDK->getParameter(NX_ADAPTIVE_FORCE);
}

void World::setJointCollisionsEnabled(bool value)
{
 mSDK->setParameter(NX_COLL_VETO_JOINTED, float(value));
}

bool World::getJointCollisionsEnabled() const
{
 return mSDK->getParameter(NX_COLL_VETO_JOINTED) == 1.0f;
}

void World::setTriggerTriggerCallbackEnabled(bool value)
{
 mSDK->setParameter(NX_TRIGGER_TRIGGER_CALLBACK, float(value));
}

bool World::getTriggerTriggerCallbackEnabled() const
{
 return mSDK->getParameter(NX_TRIGGER_TRIGGER_CALLBACK) == 1.0f;
}

void World::setSolverConvergenceThreshold(float value)
{
 mSDK->setParameter(NX_SOLVER_CONVERGENCE_THRESHOLD, value);
}

float World::getSolverConvergenceThreshold() const
{
 return mSDK->getParameter(NX_SOLVER_CONVERGENCE_THRESHOLD);
}

void World::setBoundingBoxNoiseLevel(float value)
{
 mSDK->setParameter(NX_BBOX_NOISE_LEVEL, value);
}

float World::getBoundingBoxNoiseLevel() const
{
 return mSDK->getParameter(NX_BBOX_NOISE_LEVEL);
}

void World::setImplicitSweepCacheSize(float value)
{
 mSDK->setParameter(NX_IMPLICIT_SWEEP_CACHE_SIZE, value);
}

float World::getImplicitSweepCacheSize() const
{
 return mSDK->getParameter(NX_IMPLICIT_SWEEP_CACHE_SIZE);
}

void  World::setDefaultSleepEnergy(float value)
{
 mSDK->setParameter(NX_DEFAULT_SLEEP_ENERGY, value);
}

float World::getDefaultSleepEnergy() const
{
 return mSDK->getParameter(NX_DEFAULT_SLEEP_ENERGY);
}

void  World::setAsynchronousMeshCreation(bool value)
{
 mSDK->setParameter(NX_ASYNCHRONOUS_MESH_CREATION, bool(value));
}

bool World::getAsynchronousMeshCreation() const
{
 return mSDK->getParameter(NX_ASYNCHRONOUS_MESH_CREATION) == 1.0f;
}

void World::setForceFieldCustomKernelEpsilon(float value)
{
 mSDK->setParameter(NX_FORCE_FIELD_CUSTOM_KERNEL_EPSILON, value);
}

float World::getForceFieldCustomKernelEpsilon() const
{
 return mSDK->getParameter(NX_FORCE_FIELD_CUSTOM_KERNEL_EPSILON);
}

void World::setImprovedSpringSolver(bool value)
{
 mSDK->setParameter(NX_IMPROVED_SPRING_SOLVER, bool(value));
}

bool World::getImprovedSpringSolver() const
{
 return mSDK->getParameter(NX_IMPROVED_SPRING_SOLVER) == 1.0f;
}

std::string World::to_s() const
{
 return NxOgre::to_s((void*)this, String("World"));
}
                                                                                       

} // namespace NxOgre

                                                                                       
