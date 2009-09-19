/** File: NxOgreHeightFieldManager.cpp
    Created on: 27-Mar-09
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
#include "NxOgreHeightFieldManager.h"
#include "NxOgreHeightField.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreResource.h"

template<> NxOgre::HeightFieldManager* NxOgre::Singleton<NxOgre::HeightFieldManager, NxOgre::Classes::_HeightFieldManager>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

HeightFieldManager::HeightFieldManager(void)
{
}

HeightFieldManager::~HeightFieldManager(void)
{
}

HeightField* HeightFieldManager::load(const ArchiveResourceIdentifier& ari)
{
 Resource* resource = ResourceSystem::getSingleton()->open(ari, NxOgre::Enums::ResourceAccess_ReadOnly);
 if (resource == 0)
  return 0;
 HeightField* hf = new HeightField(resource);
 hf->setName(ari.getResourceName());
 mLoadedHeightFields.insert(hf);
 return hf;
}


HeightField* HeightFieldManager::load(const ArchiveResourceIdentifier& ari, const String& name)
{
 Resource* resource = ResourceSystem::getSingleton()->open(ari, NxOgre::Enums::ResourceAccess_ReadOnly);
 if (resource == 0)
  return 0;
 HeightField* hf = new HeightField(resource);
 hf->setName(name);
 mLoadedHeightFields.insert(hf);
 return hf;
}

HeightField* HeightFieldManager::load(Resource* resource)
{
 if (resource == 0)
  return 0;
 HeightField* hf = new HeightField(resource);
 hf->setName(resource->getArchiveResourceIdentifier().getResourceName());
 mLoadedHeightFields.insert(hf);
 return hf;
}

HeightField* HeightFieldManager::load(Resource* resource, const String& name)
{
 if (resource == 0)
  return 0;
 HeightField* hf = new HeightField(resource);
 hf->setName(name);
 mLoadedHeightFields.insert(hf);
 return hf;
}

HeightField* HeightFieldManager::getByName(const String& meshIdentifier)
{
 ArrayIterator<HeightField*> iterator = mLoadedHeightFields.getIterator();
 for (HeightField* hf = iterator.begin(); hf = iterator.next(); )
 {
  if (hf->getName() == meshIdentifier)
   return hf;
 }
 return 0;
}

                                                                                       

} // namespace NxOgre

                                                                                       
