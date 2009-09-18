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
#include "NxOgreMSWindowsFileArchive.h"
#include "NxOgreMSWindowsFileResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MSWindowsFileArchive::MSWindowsFileArchive(const String& name, const UniformResourceIdentifier& uri, ResourceProtocol* protocol)
: Archive(name, uri, protocol)
{
}

MSWindowsFileArchive::~MSWindowsFileArchive(void)
{
 mResources.destroyAll();
}

Resource* MSWindowsFileArchive::open(const ArchiveResourceIdentifier& ari, NxOgre::Enums::ResourceAccess access)
{
 MSWindowsFileResource* resource = new MSWindowsFileResource(ari, this, access);
 resource->open();
 mResources.insert(resource);
 return resource;
}

void MSWindowsFileArchive::close(Resource* resource)
{
 MSWindowsFileResource* msfile_resource = static_cast<MSWindowsFileResource*>(resource);
 mResources.remove(msfile_resource);
 msfile_resource->close();
 NxOgre_Delete(msfile_resource);

}

                                                                                       

} // namespace NxOgre

                                                                                       
