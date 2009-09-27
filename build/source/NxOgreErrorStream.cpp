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
#include "NxOgreSharedStringStream.h"

                                                                                       

template<> ::NxOgre::ErrorStream* ::NxOgre::Singleton<NxOgre::ErrorStream, ::NxOgre::Classes::_ErrorStream>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

ErrorStream* ErrorStream::getSingleton(void)
{
 return sSingleton;
}

Error::Error(const String& message, const String& file, unsigned int line, unsigned char error_type)
{
  mMessage = message;
  mFile = file;
  mLine = line;
  mType = error_type;
}

Error::~Error()
{
}

ErrorStream::ErrorStream(void) : Singleton(), mLogResource(0)
{
}

ErrorStream::~ErrorStream(void)
{
 //mErrors.
}

void ErrorStream::throwAssertion(const char* message, const char* file, unsigned int line)
{
 Error* error = NxOgre_New(Error)(String(message), String(file), line, 3);
 print(error);
 mErrors.insert(error);
}

void ErrorStream::throwError(const char* message, const char* file, unsigned int line)
{
 Error* error = NxOgre_New(Error)(String(message), String(file), line, 2);
 print(error);
 delete error; // temp
}

void ErrorStream::throwError(const String& message, const char* file, unsigned int line)
{
 Error* error = NxOgre_New(Error)(message, String(file), line, 2);
 print(error);
 delete error; // temp
}

void ErrorStream::throwWarning(const char* message, const char* file, unsigned int line)
{
 Error* error = NxOgre_New(Error)(String(message), String(file), line, 1);
 print(error);
 delete error; // temp
}

void ErrorStream::throwNotice(const char* message, const char* file, unsigned int line)
{
 Error* error = NxOgre_New(Error)(String(message), String(file), line, 0);
 print(error);
 delete error; // temp
}

void ErrorStream::print(Error* error)
{
 
 mStringStream.clear();
 
 
 if (error->mType == 0)
  mStringStream << "-Notice ----------------------------------------------------------\n";
 else if (error->mType == 1)
  mStringStream << "-Warning ---------------------------------------------------------\n";
 else if (error->mType == 2)
  mStringStream << "-Error -----------------------------------------------------------\n";
 else if (error->mType == 3)
  mStringStream << "-Assertion -------------------------------------------------------\n";
 else
  mStringStream << "-Banana not found! -----------------------------------------------\n";
 
 if (error->mFile.length())
  mStringStream << "From: " << error->mFile.c_str() << "(" << error->mLine << ")\n";
 
 mStringStream << error->mMessage << "\n------------------------------------------------------------------\n";
 
 printf(mStringStream.get());
 
 if (mLogResource)
 {
  mLogResource->write(mStringStream.get(), mStringStream.length());
  mLogResource->flush();
 }
 
}


void ErrorStream::setLogResource(Resource* resource)
{
 if (mLogResource)
  ::NxOgre::ResourceSystem::getSingleton()->close(mLogResource);
 
 mLogResource = resource;
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
