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
#include "NxOgreFileResourceProtocol.h"
#include "NxOgreFileResource.h"

#include "NxOgreFunctions.h"
#include "NxOgreResource.h"

#ifdef _DEBUG
#include <iostream>
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

FileResourceProtocol::FileResourceProtocol()
{
 mProtocolName = "file";
 mProtocolHash = Strings::hash(mProtocolName);
}

FileResourceProtocol::~FileResourceProtocol()
{
}

Resource* FileResourceProtocol::open(const Path& path, Enums::ResourceAccess access)
{
 FileResource* resource = GC::safe_new3<FileResource>(path, this, access, NXOGRE_GC_THIS);
 addResource(resource);
 resource->open();
 return resource;
}

void FileResourceProtocol::close(Resource* resource)
{
 FileResource* file_resource = static_cast<FileResource*>(resource);
 file_resource->close();
 removeResource(file_resource); // Removing it will automatically delete it as well.
}

String FileResourceProtocol::getProtocol() const
{
 return mProtocolName;
}

StringHash FileResourceProtocol::getProtocolHash() const
{
 return mProtocolHash;
}

bool FileResourceProtocol::usesNamelessResources() const
{
 return false;
}

void FileResourceProtocol::initialise()
{
 // No default archives, so nothing to do.
}

                                                                                       

} // namespace NxOgre

                                                                                       
