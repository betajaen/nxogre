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
#include "NxOgreErrorStream.h"
#include "NxOgreSingleton.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreResource.h"

#include <iostream>

                                                                                       

template<> ::NxOgre::ErrorStream* ::NxOgre::Singleton<NxOgre::ErrorStream>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

void ErrorListener::onException(const Exception&)
{
}

void ErrorListener::onWarning(const Warning&)
{
}

void ErrorListener::onNotice(const Notice&)
{
}

ErrorStream::ErrorStream() : Singleton<ErrorStream>(), mLogResource(0)
{
}

ErrorStream::~ErrorStream()
{
 //mErrors.
}

void ErrorStream::addException(const Exception& exception)
{
 if (mLogResource)
 {
  mLogResource->writeString(exception.to_s());
 }
 
 for (std::vector<ErrorListener*>::iterator it = mListeners.begin(); it != mListeners.end(); it++)
  (*it)->onException(exception);
 
}

void ErrorStream::addWarning(const Warning& warning)
{
 if (mLogResource)
 {
  mLogResource->writeString(warning.to_s());
 }
 
 for (std::vector<ErrorListener*>::iterator it = mListeners.begin(); it != mListeners.end(); it++)
  (*it)->onWarning(warning);
 
}

void ErrorStream::addNotice(const Notice& notice)
{
 if (mLogResource)
 {
  mLogResource->writeString(notice.to_s());
 }
 
 for (std::vector<ErrorListener*>::iterator it = mListeners.begin(); it != mListeners.end(); it++)
  (*it)->onNotice(notice);
 
}

void ErrorStream::setLogResource(Resource* resource)
{
 if (mLogResource || (resource == 0 && mLogResource))
  ::NxOgre::ResourceSystem::getSingleton()->close(mLogResource);
 
 mLogResource = resource;
 
}

Resource* ErrorStream::getLogResource()
{
 return mLogResource;
}

void ErrorStream::addListener(ErrorListener* listener)
{
 
 NxOgre_ThrowExceptionIfNull(listener, Classes::_ErrorListener);
 
 for (std::vector<ErrorListener*>::iterator it = mListeners.begin(); it != mListeners.end(); it++)
  if ((*it) == listener)
   return;
 
 mListeners.push_back(listener);
}

void ErrorStream::removeListener(ErrorListener* listener)
{
 
 NxOgre_ThrowExceptionIfNull(listener, Classes::_ErrorListener);
 
 for (std::vector<ErrorListener*>::iterator it = mListeners.begin(); it != mListeners.end(); it++)
 {
  if ((*it) == listener)
  {
   mListeners.erase(it);
   return;
  }
 }
}

                                                                                       

} // namespace NxOgre

                                                                                       
