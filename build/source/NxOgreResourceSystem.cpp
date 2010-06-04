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
#include "NxOgreCommon.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreMemoryResourceProtocol.h"
#include "NxOgreFileResourceProtocol.h"
#include "NxOgreResource.h"
#include "NxOgreFunctions.h"

#ifdef _DEBUG
#include <iostream>
#endif

template<> NxOgre::ResourceSystem* NxOgre::Singleton<NxOgre::ResourceSystem>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

ResourceSystem::ResourceSystem()
{
 
 openProtocol(new MemoryResourceProtocol());
 
#ifndef NXOGRE_OPTIONS_NO_DEFAULT_FILEPROTOCOL
 openProtocol(new FileResourceProtocol());
#endif
 
}

ResourceSystem::~ResourceSystem()
{
 mProtocols.remove_all();
}

void ResourceSystem::openProtocol(ResourceProtocol* protocol)
{
 StringHash protocol_hash = protocol->getProtocolHash();
 mProtocols.insert(protocol_hash, protocol);
}

Resource* ResourceSystem::open(const Path& path, Enums::ResourceAccess resource_access)
{

 ResourceProtocol* protocol = mProtocols[path.getProtocolHash()];

 if (protocol == 0)
 {
  StringStream error_message;
  error_message << "Could not open resource '" << path.getString() << "\n"
                << "Reason: Protocol '" << path.getProtocol() << "' could not be found.";
  NxOgre_ThrowException(IOException, error_message.str(), Classes::_MeshSerialiser);
  return 0;
 }
 
 return protocol->open(path, resource_access);
}

void ResourceSystem::close(Resource* resource)
{
 if (resource == 0)
  return;
 
 resource->getProtocol()->close(resource);
}

ResourceSystem::ProtocolIterator ResourceSystem::getProtocols()
{
 return mProtocols.elements();
}

                                                                                       

} // namespace NxOgre

                                                                                       
