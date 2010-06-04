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
#include <iostream>

template<> NxOgre::HeightFieldManager* NxOgre::Singleton<NxOgre::HeightFieldManager>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

HeightFieldManager::HeightFieldManager() : mNextHeightFieldID(0)
{
}

HeightFieldManager::~HeightFieldManager()
{
 mHeightFields.remove_all();
}

HeightField* HeightFieldManager::load(const Path& path, const String& name)
{
 Resource* resource = ResourceSystem::getSingleton()->open(path, NxOgre::Enums::ResourceAccess_ReadOnly);
 HeightField* hf = load(resource, name);
 ResourceSystem::getSingleton()->close(resource);
 return hf;
}

HeightField* HeightFieldManager::load(Resource* resource, const String& name)
{
 
 if (resource == 0)
 {
  NxOgre_ThrowExceptionIfNull(resource, Classes::_Resource);
  return 0;
 }

 HeightField* hf = GC::safe_new1<HeightField>(resource, NXOGRE_GC_THIS);
 
 if (name == BLANK_STRING)
 {
  String hf_name = resource->getPath().getFilenameOnly();
  
  if (hf_name.length() == 0)
   hf_name = "hf_" + to_s(mNextHeightFieldID++);
  
  hf->setName(hf_name);
 }
 else
 {
  hf->setName(name);
 }
 
 mHeightFields.insert(hf->getNameHash(), hf);
 return hf;
}

HeightField* HeightFieldManager::load(HeightField* hf, const String& name)
{

 if (name == BLANK_STRING)
  hf->setName("hf_" + to_s(mNextHeightFieldID++));
 else
  hf->setName(name);
 
 mHeightFields.insert(hf->getNameHash(), hf);
 
 return hf;
}


bool HeightFieldManager::unload(const String& name)
{
 return unload(Strings::hash(name));
}

bool HeightFieldManager::unload(const StringHash& hashed_name)
{
 HeightField* hf = getByHash(hashed_name);
 if (hf)
 {
  hf->unload();
  mHeightFields.remove(hf->getNameHash());
  return true;
 }
 return false;
}

HeightField* HeightFieldManager::getByName(const String& name)
{
 return getByHash(Strings::hash(name));
}

HeightField* HeightFieldManager::getByHash(const NxOgre::StringHash &hashed_name)
{
 if (mHeightFields.has(hashed_name) == false)
  return 0;
 
 return mHeightFields.at(hashed_name);
}

bool HeightFieldManager::hasHeightField(const StringHash& name) const
{
 return mHeightFields.has(name);
}

bool HeightFieldManager::hasHeightField(const String& name) const
{
 return hasHeightField(Strings::hash(name));
}

HeightFieldManager::HeightFieldIterator HeightFieldManager::getHeightFields() const
{
 return mHeightFields.elements();
}

                                                                                       

} // namespace NxOgre

                                                                                       
