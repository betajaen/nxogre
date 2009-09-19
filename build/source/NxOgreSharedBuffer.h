/** File: NxOgreSharedBuffer.h
    Created on: 22-Nov-08
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

#ifndef NXOGRE_SHAREDBUFFER_H
#define NXOGRE_SHAREDBUFFER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerClass.h"
#include "NxOgreClasses.h"
#include "NxOgreMemory.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A block of memory that is shared. Usually two or more classes, working from the same
           buffer. To help with threading it has a "locked" function, which the user can poll
           the isLocked function until it is no longer being used.
*/
template<typename T>
class NxOgrePublicClass SharedBuffer
{
  
  public: // Functions
  
  typedef typename T* TIterator;
  
  struct TBuffer : public PointerClass<Classes::_TBuffer>
  {
   TIterator  mStart;
   TIterator  mEnd;
   bool       mLocked;
  };
  
  
  /** \brief Text
  */
  NxOgreForceInline                           SharedBuffer(void)
  : mBuffer(0), mReferences(0)
  {
  }
  
  NxOgreForceInline                           SharedBuffer(const SharedBuffer<T>& other)
  : mBuffer(other.mBuffer), mReferences(other.mReferences)
  {
   if (mReferences)
    (*mReferences)++;
  }
  
  /** \brief Text
  */
  NxOgreForceInline                           SharedBuffer(size_t length)
  : mBuffer(0), mReferences(0)
  {
  }
  
  /** \brief Text
  */
  NxOgreForceInline                          ~SharedBuffer(void)
  {
   if (mReferences)
   {
    if (--(*mReferences) == 0)
    {
     if (mBuffer->mStart)
      NxOgre_Unallocate(mStart);
     NxOgre_Delete(mBuffer);
     NxOgre_Unallocate(mReferences);
    }
   }
  }
  
  TBuffer* operator->(void)
  {
   return mBuffer;
  }
  
  NxOgreForceInline   size_t                  size(void)
  {
   if (mBuffer)
    return mEnd - mStart;
   return 0;
  }
  /** \brief Reserve a block of memory
  */
  NxOgreForceInline    void                   reserve(size_t new_size, bool copy_data)
  {
   if (mBuffer == 0)
    mBuffer = NxOgre_New(TBuffer)();
   mBuffer->mLocked = true;
   TIterator new_first = (TIterator) ::NxOgre::Memory::allocate(new_size * sizeof(T), Classes::USER_CLASS, __FILE__, __LINE__);
   if (copy_data)
    if (new_size < size())
     Memory::copy(new_first, mBuffer->mStart, new_size);
    else
     Memory::copy(new_first, mBuffer->mStart, size());
   NxOgre_Unallocate(mBuffer->mStart);
   mBuffer->mStart = new_first;
   mBuffer->mEnd = mBuffer->mStart + new_size;
   mBuffer->mLocked = false;
  }
  
  protected: // Variables

  
  /** \internal Buffer
  */
                        TBuffer*              mBuffer;
  
  
  /** \internal Number of references
  */
                     unsigned short*          mReferences;
  
}; // class SharedBuffer

                                                                                       
/** \brief A block of memory that is shared. Usually two or more classes, working from the same
           buffer. To help with threading it has a "locked" function, which the user can poll
           the isLocked function until it is no longer being used.
*/
template<typename T>
class NxOgrePublicClass SharedBuffer<T*>
{
  
  public: // Functions
  
  typedef typename T** TIterator;
  
  struct TBuffer : public PointerClass<Classes::_TBuffer>
  {
   TIterator  mStart;
   TIterator  mEnd;
   bool       mLocked;
  };
  
  /** \brief Text
  */
  NxOgreForceInline                           SharedBuffer(void)
  : mBuffer(0), mReferences(0)
  {
  }
  
  NxOgreForceInline                           SharedBuffer(const SharedBuffer<T>& other)
  : mBuffer(other.mBuffer), mReferences(other.mReferences)
  {
   if (mReferences)
    (*mReferences)++;
  }
  
  /** \brief Text
  */
  NxOgreForceInline                           SharedBuffer(size_t length)
  : mBuffer(0), mReferences(0)
  {
  }
  
  /** \brief Text
  */
  NxOgreForceInline                          ~SharedBuffer(void)
  {
   if (mReferences)
   {
    if (--(*mReferences) == 0)
    {
     if (mBuffer->mStart)
      NxOgre_Unallocate(mBuffer->mStart);
     NxOgre_Delete(mBuffer);
     NxOgre_Unallocate(mReferences);
    }
   }
  }
  
  TBuffer* operator->(void)
  {
   return mBuffer;
  }
  
  NxOgreForceInline   size_t                  size(void)
  {
   if (mBuffer)
    return mBuffer->mEnd - mBuffer->mStart;
   return 0;
  }
  
  /** \brief Reserve a block of memory
  */
  NxOgreForceInline    void                   reserve(size_t new_size, bool copy_data)
  {
   if (mBuffer == 0)
    mBuffer = NxOgre_New(TBuffer)();
   mBuffer->mLocked = true;
   TIterator new_first = (TIterator) ::NxOgre::Memory::allocate(new_size * sizeof(T*), Classes::USER_CLASS, __FILE__, __LINE__);
   if (copy_data)
    if (new_size < size())
     Memory::copy(new_first, mBuffer->mStart, new_size);
    else
     Memory::copy(new_first, mBuffer->mStart, size());
   NxOgre_Unallocate(mBuffer->mStart);
   mBuffer->mStart = new_first;
   mBuffer->mEnd = mBuffer->mStart + new_size;
   mBuffer->mLocked = false;
  }
  
  protected: // Variables
  
  /** \internal Buffer
  */
                        TBuffer*              mBuffer;
  
  /** \internal Number of references
  */
                     unsigned short*          mReferences;
  
}; // class SharedBuffer

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
