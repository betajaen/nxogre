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
#include "NxOgreArchive.h"
#include "NxOgreFunctions.h"

#ifdef _DEBUG
#include <iostream>
#endif

template<> NxOgre::ResourceSystem* NxOgre::Singleton<NxOgre::ResourceSystem, NxOgre::Classes::_ResourceSystem>::sSingleton = 0;

                                                                                       

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
 mArchives.clear();
 mProtocols.clear();
}

void ResourceSystem::openProtocol(ResourceProtocol* protocol)
{
 StringHash protocol_hash = protocol->getProtocolHash();
 mProtocols.insert(protocol_hash, protocol);
}

Archive* ResourceSystem::openArchive(const Path& path, const String& name)
{

 ResourceProtocol* protocol = mProtocols.at(path.getProtocolHash());

 if (protocol == 0)
 {
  StringStream error_message;
  error_message << "Could not open archive '" << path.getString() << "\n"
                << "Reason: Protocol '" << path.getProtocol() << "' could not be found.";
  NxOgre_ThrowError(error_message.str());
  return 0;
 }
 
 Archive* archive = 0;
 String archive_name = name;

 if (archive_name.length() == 0)
 {
  archive_name = protocol->calculateArchiveName(path);
  archive = protocol->openArchive(archive_name, path);
 }
 else
 {
  archive = protocol->openArchive(archive_name, path);
 }
 
 if (archive == 0)
 {
  StringStream error_message;
  error_message << "Could not open archive '" << path.getString() << "' as '" << archive_name << "'\n"
                << "Reason: Location could not be found.";
  NxOgre_ThrowError(error_message.str());
  return 0;
 }

 StringHash hash = archive->getNameHash();
 mArchives.insert(hash, archive);
 return archive;
 
}

Resource* ResourceSystem::open(const Path& path, Enums::ResourceAccess resource_access)
{

 ResourceProtocol* protocol = mProtocols.at(path.getProtocolHash());

 if (protocol == 0)
 {
  StringStream error_message;
  error_message << "Could not open resource '" << path.getString() << "\n"
                << "Reason: Protocol '" << path.getProtocol() << "' could not be found.";
  NxOgre_ThrowError(error_message.str());
  return 0;
 }
 
 Archive* archive = getArchiveByHash(Functions::StringHash(protocol->calculateArchiveName(path)));
 
 if (archive == 0)
 {
  archive = openArchive(path.getParent());
  if (archive == 0)
  {
   StringStream error_message;
   error_message << "Could not open resource '" << path.getString() << "\n"
                 << "Reason: Archive could not be found or could be opened.";
   NxOgre_ThrowError(error_message.str());
   return 0;
  }
 }
 
 
 
 return archive->open(path, resource_access);
}

Resource* ResourceSystem::open(Archive* archive, const Path& relative_path, Enums::ResourceAccess resource_access)
{
 
 if (archive == 0)
 {
  StringStream error_message;
  error_message << "Could not open resource '" << relative_path.getString() << " (Relative) \n"
                << "Reason: Archive pointer is null.";
  NxOgre_ThrowError(error_message.str());
  return 0;
 }
 
 return archive->open(relative_path, resource_access);
}

void ResourceSystem::close(Resource* resource)
{
 if (resource == 0)
  return;
 
 resource->getArchive()->close(resource);
}

void ResourceSystem::closeArchive(Archive* archive)
{
 if (archive == 0)
  return;


 archive->getProtocol()->closeArchive(archive);
 
 mArchives.erase(archive->getNameHash());
 
}

Archive* ResourceSystem::getArchiveByName(const String& name)
{
 return getArchiveByHash(Functions::StringHash(name));
}

Archive* ResourceSystem::getArchiveByHash(const StringHash& hashed_name)
{
 return mArchives.at(hashed_name);
}

                                                                                       

} // namespace NxOgre

                                                                                       
