/** File: NxOgreArchiveResourceIdentifier.cpp
    Created on: 4-Mar-09
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
#include "NxOgreArchiveResourceIdentifier.h"
#include "NxOgreFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ArchiveResourceIdentifier::ArchiveResourceIdentifier(void)
: mARI(0), mReferences(0)
{
}

ArchiveResourceIdentifier::ArchiveResourceIdentifier(const char* resource_identifier)
: mARI(0), mReferences(0)
{
 set(resource_identifier);
}

ArchiveResourceIdentifier::ArchiveResourceIdentifier(const ArchiveResourceIdentifier& other)
{
 mARI = other.mARI;
 mReferences = other.mReferences;
 if (mReferences)
  (*mReferences)++;
}

ArchiveResourceIdentifier::~ArchiveResourceIdentifier(void)
{
 if (mReferences)
 {
  if (--(*mReferences) == 0)
  {
   NxOgre_Delete(mARI);
   NxOgre_Unallocate(mReferences);
  }
 }
}

ArchiveResourceIdentifier& ArchiveResourceIdentifier::operator=(const ArchiveResourceIdentifier& other)
{
 if (mReferences)
 {
  if (--(*mReferences) == 0)
  {
   NxOgre_Delete(mARI);
   NxOgre_Unallocate(mReferences);
  }
 }
 mARI = other.mARI;
 mReferences = other.mReferences;
 if (mReferences)
  (*mReferences)++;

 return *this;
}

ArchiveResourceIdentifier& ArchiveResourceIdentifier::operator=(const char* c_str)
{
 set(c_str);
 return *this;
}

void ArchiveResourceIdentifier::set(const char* str)
{

 if (mReferences == 0)
 {
  mARI = NxOgre_New(ARIHash)();
  mReferences = (unsigned short*) NxOgre_Allocate(sizeof(unsigned short), Classes::_ArchiveResourceIdentifierReferenceCounter);
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

 setArchive(str, 0, colonPosition);

 if (colonPosition + 1 != str_length)
  setResourceName(str, colonPosition + 1, str_length - colonPosition - 1);

}

void ArchiveResourceIdentifier::set(const ArchiveResourceIdentifier& other)
{
 if (mReferences)
 {
  if (--(*mReferences) == 0)
  {
   NxOgre_Delete(mARI);
   NxOgre_Unallocate(mReferences);
  }
 }
 mARI = other.mARI;
 mReferences = other.mReferences;
 if (mReferences)
  (*mReferences)++;
}

const char* ArchiveResourceIdentifier::getArchive(void) const
{
 if (mARI)
  return mARI->mArchive;
 return 0;
}

void ArchiveResourceIdentifier::setArchive(const char* c_str, unsigned int where, unsigned int length)
{
 if (mARI == 0)
  return;

 if (length == 0)
  length = Functions::getCStringLength(c_str);

 if (mARI->mArchive == 0)
 {
  mARI->mArchive = (char*) NxOgre_Allocate(length + 1, Classes::_char);
 }
 else
 {
  unsigned int current_length = Functions::getCStringLength(c_str);
  if (current_length != length)
   mARI->mArchive = (char*) NxOgre_Reallocate(mARI->mArchive, length + 1);
 }

 Memory::copy(mARI->mArchive, c_str + where, length);
 mARI->mArchive[length] = 0;

 mARI->mArchiveHash = Functions::generateHash(mARI->mArchive, Enums::HashAlgorithm_DJB2);
}

unsigned long ArchiveResourceIdentifier::getArchiveHash(void) const
{
 if (mARI)
  return mARI->mArchiveHash;
 return 0;
}

const char* ArchiveResourceIdentifier::getResourceName(void) const
{
 if (mARI)
  return mARI->mResourceName;
 return 0;
}

void ArchiveResourceIdentifier::setResourceName(const char* c_str, unsigned int where, unsigned int length)
{
 if (mARI == 0)
  return;

 if (length == 0)
  length = Functions::getCStringLength(c_str);

 if (mARI->mResourceName == 0)
 {
  mARI->mResourceName = (char*) NxOgre_Allocate(length + 1, Classes::_char);
 }
 else
 {
  unsigned int current_length = Functions::getCStringLength(c_str);
  if (current_length != length)
   mARI->mResourceName = (char*) NxOgre_Reallocate(mARI->mResourceName, length + 1);
 }

 Memory::copy(mARI->mResourceName, c_str + where, length);
 mARI->mResourceName[length] = 0;

 mARI->mResourceNameHash = Functions::generateHash(mARI->mResourceName, Enums::HashAlgorithm_DJB2);
}

unsigned long ArchiveResourceIdentifier::getResourceNameHash(void) const
{
 if (mARI)
  return mARI->mResourceNameHash;
 return 0;
}

ArchiveResourceIdentifier::ARIHash::ARIHash(void)
: mArchive(0), mResourceName(0), mArchiveHash(0), mResourceNameHash(0)
{
}

ArchiveResourceIdentifier::ARIHash::~ARIHash(void)
{
 if (mArchive)
  NxOgre_Unallocate(mArchive);
 if (mResourceName)
  NxOgre_Unallocate(mResourceName);
}

                                                                                       

} // namespace NxOgre

                                                                                       
