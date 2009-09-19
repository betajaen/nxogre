/** File: NxOgreUniformResourceIdentifier.cpp
    Created on: 16-Nov-08
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
#include "NxOgreUniformResourceIdentifier.h"
#include "NxOgreFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

UniformResourceIdentifier::UniformResourceIdentifier(void)
: mURI(0), mReferences(0)
{
}

UniformResourceIdentifier::UniformResourceIdentifier(const char* resource_identifier)
: mURI(0), mReferences(0)
{
 set(resource_identifier);
}

UniformResourceIdentifier::UniformResourceIdentifier(const UniformResourceIdentifier& other)
{
 mURI = other.mURI;
 mReferences = other.mReferences;
 if (mReferences)
  (*mReferences)++;
}

UniformResourceIdentifier::~UniformResourceIdentifier(void)
{
 if (mReferences)
 {
  if (--(*mReferences) == 0)
  {
   NxOgre_Delete(mURI);
   NxOgre_Unallocate(mReferences);
  }
 }
}

UniformResourceIdentifier& UniformResourceIdentifier::operator=(const UniformResourceIdentifier& other)
{
 if (mReferences)
 {
  if (--(*mReferences) == 0)
  {
   NxOgre_Delete(mURI);
   NxOgre_Unallocate(mReferences);
  }
 }
 mURI = other.mURI;
 mReferences = other.mReferences;
 if (mReferences)
  (*mReferences)++;

 return *this;
}

UniformResourceIdentifier& UniformResourceIdentifier::operator=(const char* c_str)
{
 set(c_str);
 return *this;
}

void UniformResourceIdentifier::set(const char* str)
{

 if (mReferences == 0)
 {
  mURI = NxOgre_New(URIHash)();
  mReferences = (unsigned short*) NxOgre_Allocate(sizeof(unsigned short), Classes::_BufferReferenceCounter);
  (*mReferences) = 1;
 }
 
 // Split up protocol and location here.
 unsigned int str_length    = Functions::getCStringLength(str);
 unsigned int colonPosition = -1;

 for (unsigned int i=0;i < str_length;i++)
 {
  if (str[i] == ':')
  {
   colonPosition = i;
   break;
  }
 }

 if (colonPosition == -1)
  return;

 setProtocol(str, 0, colonPosition);

 if (colonPosition + 1 != str_length)
  setLocation(str, colonPosition + 1, str_length - colonPosition - 1);

}

void UniformResourceIdentifier::set(const UniformResourceIdentifier& other)
{
 if (mReferences)
 {
  if (--(*mReferences) == 0)
  {
   NxOgre_Delete(mURI);
   NxOgre_Unallocate(mReferences);
  }
 }
 mURI = other.mURI;
 mReferences = other.mReferences;
 if (mReferences)
  (*mReferences)++;
}

const char* UniformResourceIdentifier::getProtocol(void) const
{
 if (mURI)
  return mURI->mProtocol;
 return 0;
}

void UniformResourceIdentifier::setProtocol(const char* c_str, unsigned int where, unsigned int length)
{
 if (mURI == 0)
  return;

 if (length == 0)
  length = Functions::getCStringLength(c_str);

 if (mURI->mProtocol == 0)
 {
  mURI->mProtocol = (char*) NxOgre_Allocate(length + 1, Classes::_char);
 }
 else
 {
  unsigned int current_length = Functions::getCStringLength(c_str);
  if (current_length != length)
   mURI->mProtocol = (char*) NxOgre_Reallocate(mURI->mProtocol, length + 1);
 }

 Memory::copy(mURI->mProtocol, c_str + where, length);
 mURI->mProtocol[length] = 0;

 mURI->mProtocolHash = Functions::generateHash(mURI->mProtocol, Enums::HashAlgorithm_DJB2);
}

unsigned long UniformResourceIdentifier::getProtocolHash(void) const
{
 if (mURI)
  return mURI->mProtocolHash;
 return 0;
}

const char* UniformResourceIdentifier::getLocation(void) const
{
 if (mURI)
  return mURI->mLocation;
 return 0;
}

void UniformResourceIdentifier::setLocation(const char* c_str, unsigned int where, unsigned int length)
{
 if (mURI == 0)
  return;

 if (length == 0)
  length = Functions::getCStringLength(c_str);

 if (mURI->mLocation == 0)
 {
  mURI->mLocation = (char*) NxOgre_Allocate(length + 1, Classes::_char);
 }
 else
 {
  unsigned int current_length = Functions::getCStringLength(c_str);
  if (current_length != length)
   mURI->mLocation = (char*) NxOgre_Reallocate(mURI->mLocation, length + 1);
 }

 Memory::copy(mURI->mLocation, c_str + where, length);
 mURI->mLocation[length] = 0;

 mURI->mLocationHash = Functions::generateHash(mURI->mLocation, Enums::HashAlgorithm_DJB2);
}

unsigned long UniformResourceIdentifier::getLocationHash(void) const
{
 if (mURI)
  return mURI->mLocationHash;
 return 0;
}

UniformResourceIdentifier::URIHash::URIHash(void)
: mProtocol(0), mLocation(0), mProtocolHash(0), mLocationHash(0)
{
}

UniformResourceIdentifier::URIHash::~URIHash(void)
{
 if (mProtocol)
  NxOgre_Unallocate(mProtocol);
 if (mLocation)
  NxOgre_Unallocate(mLocation);
}

                                                                                       

} // namespace NxOgre

                                                                                       
