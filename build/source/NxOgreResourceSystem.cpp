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
#include "NxOgreResourceSystem.h"
#include "NxOgreMemoryResourceProtocol.h"
#include NxOgreFileResourceProtocolHeader
#include "NxOgreResource.h"
#include "NxOgreArchive.h"
#include "NxOgreFunctions.h"

template<> NxOgre::ResourceSystem* NxOgre::Singleton<NxOgre::ResourceSystem, NxOgre::Classes::_ResourceSystem>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

ResourceSystem::ResourceSystem()
{
 
 addProtocol(new MemoryResourceProtocol());
 
#ifndef NXOGRE_OPTIONS_NO_DEFAULT_FILEPROTOCOL
 addProtocol(new NxOgreFileResourceProtocol());
#endif
 
}

ResourceSystem::~ResourceSystem()
{
 mArchives.destroyAll(); 
 mProtocols.destroyAll();
}

Resource* ResourceSystem::open(const ArchiveResourceIdentifier& ari, Enums::ResourceAccess access)
{
 Archive* archive = 0;
 for (unsigned int i=0;i < mArchives.size(); i++)
 {
  if (mArchives[i]->getNameHash() == ari.getArchiveHash())
  {
   archive = mArchives[i];
   break;
  }
 }
 
 if (archive == 0)
 {  SharedStringStream ss(200);
  ss << "Could not open resource '" << ari.getArchive() << ":" << ari.getResourceName() << "\n"
     << "Reason: Archive could not be found.";
  NxOgre_ThrowError(ss.get());
  return 0;
 }
 
 return archive->open(ari, access);
}

void ResourceSystem::close(Resource* resource)
{
 if (resource == 0)
  return;
 resource->getArchive()->close(resource);
}

void ResourceSystem::addProtocol(ResourceProtocol* protocol)
{
 mProtocols.insert(protocol);
 protocol->initialise();
}

Archive* ResourceSystem::openArchive(const String& name, const UniformResourceIdentifier& uri)
{
 ResourceProtocol* requestedProtocol = 0;
 ArrayIterator<ResourceProtocol*> iterator = mProtocols.getIterator();
 for (ResourceProtocol* protocol = iterator.begin(); protocol = iterator.next();)
 {
  if (protocol->getProtocolHash() == uri.getProtocolHash())
  {
   requestedProtocol = protocol;
   break;
  }
 }
  
 if (requestedProtocol == 0)
 {
  SharedStringStream ss(200);
  ss << "Could not open archive '" << uri.getLocation() << ":" << uri.getLocation() << "\n"
     << "Reason: Protocol could not be found.";
  NxOgre_ThrowError(ss.get());
  return 0;
 }
  
 Archive* archive = requestedProtocol->openArchive(name, uri);
  
 if (archive == 0)
 {
  SharedStringStream ss(200);
  ss << "Could not open archive '" << uri.getLocation() << ":" << uri.getLocation() << "\n"
     << "Reason: Protocol could not open archive.";
  NxOgre_ThrowError(ss.get());
  return 0;
 }
 
 mArchives.insert(archive);
 return archive;
}

void ResourceSystem::closeArchive(const NxOgre::String &name)
{
  for (unsigned int i=0;i < mArchives.size(); i++)
 {
  if (mArchives[i]->getName() == name)
  {
   mArchives.remove(i);
   Archive* archive = mArchives[i];
   NxOgre_Delete(archive);
   return;
  }
 }
}

Archive* ResourceSystem::getArchiveByName(const String& name)
{
 for (unsigned int i=0;i < mArchives.size(); i++)
  if (mArchives[i]->getName() == name)
   return mArchives[i];
 
 return 0;
}


                                                                                       

} // namespace NxOgre

                                                                                       
