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

                                                                                       

#ifndef NXOGRE_SHAREDPOINTER_H
#define NXOGRE_SHAREDPOINTER_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
template<typename T>
class NxOgrePublicClass SharedPointer
{
  public: // Functions
  
  /** \brief SharedPointer<T> constructor with no pointer to T.
  */
                                              SharedPointer(void)
  : mPtr(0), mReferences(0)
  {
  }

  /** \brief SharedPointer<T> copy constructor
  */
                                              SharedPointer(const SharedPointer<T>& other)
  : mPtr(other.mPtr), mReferences(other.mReferences)
  {
   if (mReferences)
    (*mReferences)++;
  }
  
  /** \brief SharedPointer<T> constructor with a pointer to T
  */
  explicit                                    SharedPointer(T* ptr)
  : mPtr(ptr)
  {
   mReferences = (unsigned int*) NXOGRE_ALLOCATE(FourByteAllocator, sizeof(unsigned int));
   (*mReferences) = 1;
  }

  /** \brief SharedPointer<T> destructor
  */
                                             ~SharedPointer(void)
  {
   if (mReferences)
   {
    if (--(*mReferences) == 0)
    {
     NXOGRE_DELETE_NXOGRE(mPtr);
     NXOGRE_DEALLOCATE(FourByteAllocator, mReferences);
     mReferences = 0;
     mPtr        = 0;
    }
   }
  }
  
  /** \brief SharedPointer<T> assignment operator
  */
                        SharedPointer<T>&      operator=(const SharedPointer<T>& other)
  {
   if (mReferences)
   {
    if (--(*mReferences) == 0)
    {
     NXOGRE_DELETE_NXOGRE(mPtr);
     NXOGRE_DEALLOCATE(FourByteAllocator, mReferences);
    }
   }
   mPtr = other.mPtr;
   mReferences = other.mReferences;
   if (mReferences)
    (*mReferences)++;
   return *this;
  }

  /** \brief SharedPointer<T> -> operator
  */
  T*                       operator->(void) const
  {
   return mPtr;
  }

  /** \brief SharedPointer<T> * operator
  */
  T&                       operator*(void) const
  {
   return mPtr;
  }

  /** \brief SharedPointer<T> get operator
  */
  inline                T*                       get(void) const
  {
   return mPtr;
  }

  /** \brief Is the pointer that the SharedPointer represent actually NULL?
  */
  bool                     isNullPtr(void)
  {
   return (mPtr == 0);
  }

  /** \brief Does the SharedPointer actually contain a pointer?
  */
  bool                    isNull(void)
  {
   return (mReferences == 0);
  }

  protected: // Variables
  
  T*             mPtr;
  unsigned int*  mReferences;
  
}; // class ClassName


template <typename T1, typename T2> inline bool operator==(SharedPointer<T1> const& first, SharedPointer<T2> const& second)
{
 return first.get() == second.get();
}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
