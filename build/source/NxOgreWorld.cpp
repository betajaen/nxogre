/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2011 Robin Southern, http://github.com/betajaen/nxogre/
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

#include "NxOgreWorld.h"
#include "NxOgreScene.h"
#include "NxPhysics.h"

namespace NxOgre
{
 
 // --------------------------------------------------

 World* World::SINGLETON = NXOGRE_NULL_POINTER;

 // --------------------------------------------------

 class PhysXAllocator : public NxUserAllocator, public AllocatedClass::PhysX
 {
   
  public:
   
   // --------------------------------------------------
   
   void* mallocDEBUG(size_t size, const char* file, int line)
   {
#if NXOGRE_DEBUG_MEMORY >= 2
    return GC::safe_malloc(size, file, __FUNCTION__, line);
#else
    NXOGRE_UNUSED(file);
    NXOGRE_UNUSED(line);
    return GC::safe_malloc(size);
#endif
   }
   
   // --------------------------------------------------
   
   void* mallocDEBUG(size_t size, const char* file, int line, const char* className, NxMemoryType type)
   {
    NXOGRE_UNUSED(type);
#if NXOGRE_DEBUG_MEMORY >= 2
    return GC::safe_malloc(size, file, __FUNCTION__, line);
#else
    NXOGRE_UNUSED(file);
    NXOGRE_UNUSED(className);
    NXOGRE_UNUSED(line);
    return GC::safe_malloc(size);
#endif
   }

   void* malloc(size_t size)
   {
    return NXOGRE_MALLOC(size);
   }
  
   // --------------------------------------------------
  
   void* malloc(size_t size, NxMemoryType type)
   {
    NXOGRE_UNUSED(type);
    return NXOGRE_MALLOC(size);
   }
  
  // --------------------------------------------------

   void* realloc(void* memory, size_t size)
   {
    return NXOGRE_REALLOC(memory, size);
   }
  
  // --------------------------------------------------

   void free(void* memory)
   {
    NXOGRE_FREE(memory);
   }
  
  // --------------------------------------------------

 };

 class PhysXOutputStream : public NxUserOutputStream, public AllocatedClass::PhysX
 {
  public:
   
   PhysXOutputStream(NxAssertResponse assertion_policy)
   : mAssertionPolicy(assertion_policy)
   {
   }

   void reportError(NxErrorCode code, const char * message, const char *file, int line)
   {
    // TODO: Flesh out
   }

   NxAssertResponse reportAssertViolation(const char * message, const char *file, int line)
   {
    // TODO: Flesh out
    return mAssertionPolicy;
   }

   void print(const char * message)
   {
    // TODO: Flesh out
   }
   
   NXOGRE_FORCE_INLINE static NxAssertResponse PhysXAssertionPolicyToNxAssertResponse( Enums::PhysXAssertionPolicy policy)
   {
    if (policy == Enums::PhysXAssertionPolicy_Breakpoint)
     return NX_AR_BREAKPOINT;
    else if (policy == Enums::PhysXAssertionPolicy_Continue)
     return NX_AR_CONTINUE;
    else if (policy == Enums::PhysXAssertionPolicy_Ignore)
     return NX_AR_IGNORE;
    return NX_AR_BREAKPOINT;
   }
   
   NXOGRE_FORCE_INLINE static Enums::PhysXAssertionPolicy NxAssertResponseToPhysXAssertionPolicy( NxAssertResponse policy)
   {
    if (policy == NX_AR_BREAKPOINT)
     return Enums::PhysXAssertionPolicy_Breakpoint;
    else if (policy == NX_AR_CONTINUE)
     return Enums::PhysXAssertionPolicy_Continue;
    else if (policy == NX_AR_IGNORE)
     return Enums::PhysXAssertionPolicy_Ignore;
    return Enums::PhysXAssertionPolicy_Breakpoint;
   }

   NxAssertResponse  mAssertionPolicy;
   
 };


 // --------------------------------------------------

 NxPhysicsSDKDesc WorldDescription::to_physx_desc() const
 {
  NxPhysicsSDKDesc desc;
  desc.cookerThreadMask = mCookerThreadMask;
  desc.flags = 0;
  
  if (mNoHardware)
   desc.flags |= NX_SDKF_NO_HARDWARE;
  
  if (mPerSceneBatching)
   desc.flags |= NX_SDKF_PER_SCENE_BATCHING;
  
  desc.gpuHeapSize = mGPUHeapSize;
  desc.hwConvexMax = mHardwareMaximumConvex;
  desc.hwPageMax = mHardwareMaximumPage;
  desc.hwPageSize = mHardwarePageSize;
  desc.meshCacheSize = mMeshCacheSize;
  return desc;
 }

 // --------------------------------------------------

 String to_s(const WorldDescription::Reason& r)
 {
  OStringStream s;
  if (r.assertion_policy)
   s << "Assertion response\n";
  if (r.cooker_thread_mask)
   s << "Cooker thread mask\n";
  if (r.gpu_heap_size)
   s << "GPU heap size\n";
  if (r.hardware_maximum_convex)
   s << "Hardware maximum convex\n";
  if (r.hardware_maximum_page)
   s << "Hardware maximum page\n";
  if (r.hardware_page_size)
   s << "Hardware page size\n";
  if (r.mesh_cache_size)
   s << "Mesh cache size\n";
  if (r.no_hardware)
   s << "No hardware\n";
  if (r.per_scene_batching)
   s << "Per Scene batching\n";
  return s.str();
 }

 String WorldDescription::to_s() const
 {
  OStringStream s;
  s << "\n[\nassertion_policy = " << mAssertionPolicy << " ,\n"
    << "cooker_thread_mask = " << mCookerThreadMask << ",\n"
    << "hardware_maximum_convex = " << mHardwareMaximumConvex << ",\n"
    << "hardware_maximum_page = " << mHardwareMaximumPage  << ",\n"
    << "no_hardware = " << mNoHardware  << ",\n"
    << "per_scene_batching = " << mPerSceneBatching  << ",\n"
    << "gpu_heap_size = " << mGPUHeapSize  << ",\n"
    << "mesh_cache_size = " << mMeshCacheSize  << ",\n"
    << "hardware_page_size = " << mHardwarePageSize  << "\n]\n";
  return s.str();
 }

 // --------------------------------------------------

 World::World(const WorldDescription& desc)
 : mSDK(NXOGRE_NULL_POINTER)
 {
  std::cout << desc.to_s() << "\n";
  loadFromDescription(desc);
 }

 // --------------------------------------------------

 World::~World()
 {
  
  NXOGRE_LOG_MESSAGE("Stopping PhysX SDK");
  if (mSDK)
  {
   NxReleasePhysicsSDK(mSDK);
   mSDK = NXOGRE_NULL_POINTER;
  }
  NXOGRE_DELETE(mPhysXAllocator);
  NXOGRE_DELETE(mPhysXOutputStream);
 }

 // --------------------------------------------------

 void World::loadFromDescription(const WorldDescription& desc)
 {
  mDescription = desc;
  NxSDKCreateError errorCode = NXCE_NO_ERROR;
  mPhysXAllocator = NXOGRE_NEW PhysXAllocator();
  mPhysXOutputStream = NXOGRE_NEW PhysXOutputStream(NX_AR_BREAKPOINT);
  
NXOGRE_LOG_LONG_MESSAGE_BEGIN
  StringStream s;
  s << "Creating PhysX SDK using PhysX " << NX_SDK_VERSION_MAJOR << "." << NX_SDK_VERSION_MINOR << "." << NX_SDK_VERSION_BUGFIX;
NXOGRE_LOG_LONG_MESSAGE_END(s);
  
  mSDK = NxCreatePhysicsSDK(NX_PHYSICS_SDK_VERSION, mPhysXAllocator, mPhysXOutputStream, mDescription.to_physx_desc(), &errorCode);
  
  if (mSDK == 0)
  {
   StringStream s;
   s << "Could not create PhysxSDK, reasons being could be: \n";
   
   if (errorCode == NXCE_DESCRIPTOR_INVALID)
   {
    s << "WorldDescription is invalid, specifically;\n" << to_s(desc.wrong()) << "\n";
    NXOGRE_THROW_EXCEPTION(BadDescriptionException, s.str().c_str());
   }
   else
   {
    
    if (errorCode == NXCE_PHYSX_NOT_FOUND)
     s << "Unable to find the PhysX libraries. The PhysX drivers are not installed correctly.";
    
    else if (errorCode == NXCE_WRONG_VERSION)
     s << "NxOgre has given a version number that does not match with the libraries.";
    
    else if (errorCode == NXCE_CONNECTION_ERROR)
     s << "A PhysX card was found, but there are problems when communicating with the card.";
    
    else if (errorCode == NXCE_RESET_ERROR)
     s << "A PhysX card was found, but it did not reset (or initialize) properly.";
    
    else if (errorCode == NXCE_IN_USE_ERROR)
     s << "A PhysX card was found, but it is already in use by another application.";
    
    else if (errorCode == NXCE_BUNDLE_ERROR)
     s << "A PhysX card was found, but there are issues with loading the firmware.";
    else
     s << "Unknown error\n";
    NXOGRE_THROW_EXCEPTION(PhysXException, s.str().c_str());
   }
  }
  
 }

 // --------------------------------------------------

 WorldDescription World::saveToDescription() const
 {
  return mDescription;
 }

 // --------------------------------------------------
 World* World::createWorld(const WorldDescription& description)
 {
  if (SINGLETON)
  {
   NXOGRE_THROW_EXCEPTION(BadStateException, "World already exists.");
   return NXOGRE_NULL_POINTER;
  }
  
  SINGLETON = NXOGRE_NEW World(description);
  
  return SINGLETON;
 }

 // --------------------------------------------------
 
 void World::destroyWorld()
 {
  
  if (SINGLETON == 0)
  {
   NXOGRE_THROW_EXCEPTION(BadStateException, "World has already been destroyed.");
   return;
  }
  
  NXOGRE_DELETE(SINGLETON);
  SINGLETON = NXOGRE_NULL_POINTER;
  
  NXOGRE_LOG_MESSAGE("NxOgre and PhysX Objects destroyed");
  
 }
 
 // --------------------------------------------------
 
 void World::advance(Real deltaTime)
 {
   std::cout << "Advancing time by " << deltaTime << "\n";
 }
 
 // --------------------------------------------------
 
 void World::setPhysXAssertionPolicy(Enums::PhysXAssertionPolicy policy)
 {
  mPhysXOutputStream->mAssertionPolicy = PhysXOutputStream::PhysXAssertionPolicyToNxAssertResponse(policy);
 }
 
 Enums::PhysXAssertionPolicy World::getPhysXAssertionPolicy() const
 {
  return PhysXOutputStream::NxAssertResponseToPhysXAssertionPolicy(mPhysXOutputStream->mAssertionPolicy);
 }

} // namespace World
