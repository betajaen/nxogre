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
    return GC::safe_malloc(size, file, line);
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
    return GC::safe_malloc(size, file, line);
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

 // --------------------------------------------------

 World::World(const WorldDescription& desc)
 : mSDK(NXOGRE_NULL_POINTER)
 {
  assert(SINGLETON);
  loadFromDescription(desc);
 }

 // --------------------------------------------------

 World::~World()
 {
  
  if (mSDK)
  {
   NxReleasePhysicsSDK(mSDK);
   mSDK = NXOGRE_NULL_POINTER;
  }
  
  NXOGRE_DELETE(mPhysXAllocator);
  
 }

 // --------------------------------------------------

 void World::loadFromDescription(const WorldDescription& desc)
 {
  mDescription = desc;
  NxSDKCreateError errorCode = NXCE_NO_ERROR;
  mPhysXAllocator = NXOGRE_NEW PhysXAllocator();
  mPhysXOutputStream = NXOGRE_NEW PhysXOutputStream(NX_AR_BREAKPOINT);

  mSDK = NxCreatePhysicsSDK(NX_PHYSICS_SDK_VERSION, mPhysXAllocator, mPhysXOutputStream, mDescription.to_physx_desc(), &errorCode);
  
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
  
  if (SINGLETON)
  {
   NXOGRE_THROW_EXCEPTION(BadStateException, "World has already been destroyed.");
   return;
  }

  NXOGRE_DELETE(SINGLETON);
  SINGLETON = NXOGRE_NULL_POINTER;
  
 }
 
 // --------------------------------------------------


} // namespace World
