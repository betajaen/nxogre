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
#include "NxOgreArchive.h"
#include "NxOgreFunctions.h"

#ifdef _DEBUG
# include <iostream>
#endif
                                                                                       

namespace NxOgre
{

                                                                                       

Archive::Archive(const String& archive_name, const Path& path, ResourceProtocol* protocol)
: mName(archive_name), mPath(path), mProtocol(protocol)
{
 mNameHash = Strings::hash(archive_name);
}

Archive::~Archive(void)
{
}

String Archive::getName()
{
 return mName;
}

StringHash Archive::getNameHash()
{
 return mNameHash;
}

ResourceProtocol* Archive::getProtocol() const
{
 return mProtocol;
}

Path Archive::getPath() const
{
 return mPath;
}

Archive::ResourcesIterator Archive::getOpenResources()
{
 return ResourcesIterator(mResources);
}

Resource* Archive::open(const Path&, NxOgre::Enums::ResourceAccess)
{
 return 0;  // virtual function.
}

void Archive::close(Resource*)
{
 // virtual function.
}

void Archive::_addResource(Resource* resource)
{
 mResources.push_back(resource);
}

void Archive::_removeResource(Resource* resource)
{
 mResources.erase(resource);
}

String Archive::to_s() const
{
 return NxOgre::to_s((void*)this, (mName.length() ? String("'" + mName + "'") : String("Archive") ));
}

                                                                                       

} // namespace NxOgre

                                                                                       
