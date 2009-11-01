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
#include "NxOgreMemoryArchive.h"
#include "NxOgreMemoryResource.h"

#ifdef _DEBUG
#include <iostream>
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

MemoryArchive::MemoryArchive(const String& name, const Path& path, ResourceProtocol* protocol)
: Archive(name, path, protocol)
{
#ifdef _DEBUG
 std::cout << "[+] Opening Memory Archive" << std::endl;
#endif
}

MemoryArchive::~MemoryArchive(void)
{
#ifdef _DEBUG
 std::cout << "[-] Closing Memory Archive" << std::endl;
#endif
 mResources.clear();
}

Resource* MemoryArchive::open(const Path&, NxOgre::Enums::ResourceAccess)
{
 MemoryResource* resource = new MemoryResource(this);
 _addResource(resource);
 resource->open();
 return resource;
}

void MemoryArchive::close(Resource* resource)
{
 if (resource == 0)
  return;
 
 MemoryResource* memory_resource = static_cast<MemoryResource*>(resource);
 memory_resource->close();
 
 _removeResource(resource);
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
