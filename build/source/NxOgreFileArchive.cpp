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
#include "NxOgreFileArchive.h"
#include "NxOgreFileResource.h"

#ifdef _DEBUG
#include <iostream>
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

FileArchive::FileArchive(const String& name, const Path& path, ResourceProtocol* protocol)
: Archive(name, path, protocol)
{
#ifdef _DEBUG
 std::cout << "[+] Opening File Archive '" << mName << "' from " << mPath.getString() << std::endl;
#endif
}

FileArchive::~FileArchive(void)
{
#ifdef _DEBUG
 std::cout << "[-] Closing File Archive '" << mName << "' from " << mPath.getString() << std::endl;
#endif
 mResources.clear();
}

Resource* FileArchive::open(const Path& path, NxOgre::Enums::ResourceAccess access)
{
 FileResource* resource = new FileResource(path, this, access);
 _addResource(resource);
 resource->open();
 return resource;
}

void FileArchive::close(Resource* resource)
{
 if (resource == 0)
  return;
 
 FileResource* file_resource = static_cast<FileResource*>(resource);
 file_resource->close();

 _removeResource(resource);
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
