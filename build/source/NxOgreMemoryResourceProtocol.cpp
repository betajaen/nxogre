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
#include "NxOgreMemoryResourceProtocol.h"
#include "NxOgreFunctions.h"
#include "NxOgreResource.h"
#include "NxOgreMemoryResource.h"
#include "NxOgreResourceSystem.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MemoryResourceProtocol::MemoryResourceProtocol() : mHasInit(false)
{
 mProtocolName = "memory";
 mProtocolHash = Strings::hash(mProtocolName);
}

MemoryResourceProtocol::~MemoryResourceProtocol()
{
}

Resource* MemoryResourceProtocol::open(const Path& path, Enums::ResourceAccess access)
{
 MemoryResource* resource = GC::safe_new1<MemoryResource>(this, NXOGRE_GC_THIS);
 resource->open();
 addResource(resource);
 return resource;
}

void MemoryResourceProtocol::close(Resource* resource)
{
 MemoryResource* mem_resource = static_cast<MemoryResource*>(resource);
 mem_resource->close();
 removeResource(mem_resource); // Removing it will automatically delete it as well.
}

String MemoryResourceProtocol::getProtocol()
{
 return mProtocolName;
}

StringHash MemoryResourceProtocol::getProtocolHash() const
{
 return mProtocolHash;
}

bool MemoryResourceProtocol::usesNamelessResources() const
{
 return true;
}

void MemoryResourceProtocol::initialise()
{
}

                                                                                       

} // namespace NxOgre

                                                                                       
