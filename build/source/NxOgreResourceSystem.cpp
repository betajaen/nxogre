/** File: NxOgreResourceSystem.cpp
    Created on: 23-Jan-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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

                                                                                       
