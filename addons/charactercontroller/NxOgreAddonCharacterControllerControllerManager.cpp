/** File: NxOgreCharacterController.h
    Created on: 02-Dec-09
    Author: Robin Southern "betajaen"
    

    Copyright (c) 2008-2009 Robin Southern

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

#include "NxOgreAddonCharacterControllerCommon.h"
#include "NxOgreAddonCharacterControllerControllerManager.h"
#include "NxOgreAddonCharacterController.h"

#include "NxControllerManager.h"

                                                                                       

namespace NxOgre
{

class ControllerAllocator : public NxUserAllocator
{
  
 public:
  
  ControllerAllocator(void) {}
  
  void*  mallocDEBUG(size_t size, const char*, int)
  {
   return ::malloc(size);
  }
  
  void*  mallocDEBUG(size_t size, const char*, int, const char*, NxMemoryType)
  {
   return ::malloc(size);
  }
  
  void*  malloc(size_t size)
  {
   return ::malloc(size);
  }
  
  void*  malloc(size_t size, NxMemoryType)
  {
   return ::malloc(size);
  }
  
  void*  realloc(void* mem, size_t new_size)
  {
   return ::realloc(mem, new_size);
  }
  
  void  free(void* mem)
  {
   ::free(mem);
  }
  
};


ControllerManager::ControllerManager()
{
 mAllocator = new ControllerAllocator();
 mManager = NxCreateControllerManager(mAllocator);
}

ControllerManager::~ControllerManager()
{
 mControllers.destroyAll();
 NxReleaseControllerManager(mManager);
 delete mAllocator;
}

Controller*  ControllerManager::createBoxController(const ControllerDescription& description, const Vec3& size, Scene* scene, PointRenderable* renderable)
{
 Controller* controller = new Controller(description, size, renderable, scene, this);
 mControllers.insert(controller);
 return controller;
}

Controller*  ControllerManager::createCapsuleController(const ControllerDescription& description, const Vec2& size, Scene* scene, PointRenderable* renderable)
{
 Controller* controller = new Controller(description, size, renderable, scene, this);
 mControllers.insert(controller);
 return controller;
}

void  ControllerManager::destroyController(Controller* controller)
{
 mControllers.remove(controller);
 delete controller;
}

NxControllerManager*  ControllerManager::getControllerManager()
{
 return mManager;
}

}

                                                                                       
