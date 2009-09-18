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

                                                                                       
