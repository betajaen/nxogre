/** File: NxOgreSharedString.h
    Created on: 4-Nov-08
    Author: Robin Southern "betajaen"
    

    (c) Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

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

#ifndef NXOGRE_STRING_H
#define NXOGRE_STRING_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerClass.h"
#include "NxOgreMemory.h"
#include <stdio.h>

                                                                                       

namespace NxOgre
{

                                                                                       

class String;

class NxOgrePublicClass StringBase : public PointerClass<Classes::_StringBase>
{
 
 friend class String;
 
 public:
  
  inline void reallocate(unsigned int size)
  {
#if 0
   mString = (char*) realloc(mString, size);
#else
   mString = (char*) ::NxOgre::Memory::reallocate(mString, size);
#endif
   mBufferSize = size;
  }
  
  // Non-Realloc size. Data is not preserved.
  inline void allocate(unsigned int size)
  {
#if 0
   mString = (char*) malloc(size);
#elif NxOgreMemoryDebugger == 1
   mString = (char*) ::NxOgre::Memory::allocate(size, Classes::_char, __FILE__, __LINE__);
#else
   mString = (char*) ::NxOgre::Memory::allocate(size);
#endif
   mBufferSize = size;
  }

  inline void deallocate()
  {
#if 0
   ::free(mString);
#else
   ::NxOgre::Memory::unallocate(mString);
#endif
   mString = 0;
  }
  
  inline const char* c_str() const
  {
   return mString;
  };
  
  inline unsigned int length()
  {
   return mStringSize;
  }
  
  inline unsigned char at(const unsigned int pos) const
  {
   if (pos > mStringSize)
    return 0;
   return mString[pos];
  }
  
  // Safer
  inline void assign(const char* str)
  {
   unsigned int len = Length(str) + 1;
   if (len == 1)
   {
    reallocate(1);
    mString[0] = 0;
    mStringSize = 0;
    return;
   }
   
   if (len > mBufferSize)
    reallocate(len);
   Assign(str, len);
   
  }
  
  inline bool compare(const char* other)
  {
   unsigned int otherLen = Length(other);
   
   if (mString == 0 && other == 0)
    return true;
   
   if (mStringSize != otherLen || mStringSize == 0 || otherLen == 0)
    return false;
   
   for (unsigned int i=0; i < mStringSize;i++)
    if (mString[i] != other[i])
     return false;
   return true;
  }
  
 protected:
  
  StringBase() : mReferences(1), mString(0), mStringSize(0), mBufferSize(0)
  {
   allocate(1);
   mString[0] = 0;
  }
  
  StringBase(const char* string) : mReferences(1), mString(0), mStringSize(0), mBufferSize(0)
  {
   unsigned int len = Length(string) + 1;
   if (len > 1)
   {
    allocate(len);
    Assign(string, len);
   }
   else
   {
    allocate(1);
    mString[0] = 0;
   }
  }

  inline ~StringBase()
  {
   deallocate();
  }

  // Non-safer.
  inline void Assign(const char* str, unsigned int len)
  {
#if 0
   memcpy(mString, str, len);
#else
   NxOgre::Memory::copy(mString, str, len);
#endif
   mStringSize = len - 1;
  }

  inline unsigned int Length(const char* string)
  {
   if (string == 0)
    return 0;
   unsigned int length = 0;
    
   while(string[length++] != 0)
    ;
   return length;
  }
  
  unsigned int mReferences;
  char*        mString;
  unsigned int mStringSize;
  unsigned int mBufferSize;
  
};


class NxOgrePublicClass String
{
 public:
  
  inline String()
  {
   mString = _new(0);
  }
  
  inline String(const char* string)
  {
   mString = _new(string);
  }

  inline String(const String& other)
  {
   mString = _acquire(other.mString);
  }

  inline ~String()
  {
   mString = _free(mString);
  }

  inline void clear()
  {
   _free(mString);
   mString = _new(0);
  }

  inline String& operator=(const String& other)
  {
   _free(mString);
   mString = _acquire(other.mString);
   return *this;
  }

  inline String& operator=(const char* string)
  {
   mString->assign(string);
   return *this;
  }

  inline const char* c_str() const
  {
   return mString->c_str();
  }
  
  inline unsigned char operator[](const unsigned int pos) const
  {
   return mString->at(pos);
  }

  inline unsigned int length() const
  {
   return mString->length();
  }

  inline bool operator==(const String& other)
  {
   return mString->compare(other.c_str());
  }

  inline bool operator==(const char* other)
  {
   return mString->compare(other);
  }


 protected:
  
   inline StringBase* _free(StringBase* str)
   {
    
    if (str == 0)
     return 0;
    
    str->mReferences--;
    if (str->mReferences == 0)
    {
     delete str;
     str = 0;
    }
    return str;
   }

   inline StringBase* _new(const char* string)
   {
    return new StringBase(string);
   }

   inline StringBase* _acquire(StringBase* str = 0)
   {
    if (str == 0)
    {
     return new StringBase();
    }
   
    str->mReferences++;
    return str;
   }

   StringBase* mString;

};

                                                                                       

} // namespace NXOGRE_NAMESPACE

                                                                                       

#endif
