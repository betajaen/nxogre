/** File: NxOgreErrorStream.cpp
    Created on: 4-Nov-08
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

                                                                                       
