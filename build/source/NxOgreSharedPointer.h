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

                                                                                       

/*! class. SharedPointer
    desc.
        Shared Pointer
    note.
        Much of this code is based of the SharedPtr class from Ogre3D http://www.ogre3d.org
*/
template<typename T> class NxOgrePublicTemplateClass SharedPointer
{
  public:
  
   SharedPointer()
   : mPtr(0), mReferences(0)
   {
   }
  
   template<typename user_type>
   explicit SharedPointer(user_type* ptr)
   : mPtr(ptr), mReferences(0)
   {
    if (mPtr)
     mReferences = GC::safe_new0<unsigned int>(NXOGRE_GC_THIS);
   }
   
   SharedPointer(const SharedPointer& other)
   : mPtr(0), mReferences(0)
   {
    mPtr = other.mPtr;
    mReferences = other.mReferences;
    if (mReferences)
     ++(*mReferences);
   }
   
   SharedPointer& operator=(const SharedPointer& other)
   {
    if (mPtr == other.mPtr)
     return *this;
    
    SharedPointer<T> temp(other);
    swap(temp);
    return *this;
   }
   
   template<typename user_type>
   SharedPointer(const SharedPointer<user_type>& other)
   : mPtr(0), mReferences(0)
   {
    mPtr = other.getPtr();
    mReferences = other.getReferencesPtr();
    if (mReferences)
     ++(*mReferences);
   }
   
   template<typename user_type>
   SharedPointer& operator=(const SharedPointer<user_type>& other)
   {
    if (mPtr == other.getPtr())
     return *this;
    
    SharedPtr<T> temp(other);
    swap(temp);
    reutrn *this;
   }
   
   virtual ~SharedPointer()
   {
    release();
   }
   
   inline T& operator*() const
   {
    NxOgre_ThrowExceptionIfNull(mPtr, Classes::_void);
    return *mPtr;
   }
   
   inline T* operator->() const
   {
    NxOgre_ThrowExceptionIfNull(mPtr, Classes::_void);
    return mPtr;
   }
   
   inline T* get() const
   {
    NxOgre_ThrowExceptionIfNull(mPtr, Classes::_void);
    return mPtr;
   }
   
   void bind(T* ptr)
   {
    NxOgre_ThrowExceptionIfNotNull(mPtr, "Pointer was expected to be null!", Classes::_void);
    NxOgre_ThrowExceptionIfNotNull(mReferences, "Pointer was expected to be null!", Classes::_unsigned_int);
    
    mReferences = GC::safe_new0<unsigned int>(NXOGRE_GC_THIS);
    mPtr = ptr;
   }
   
   inline bool unique() const
   {
    NxOgre_ThrowExceptionIfNull(mReferences, Classes::_unsigned_int);
    return (*mReferences) == 1;
   }
   
   inline unsigned int references() const
   {
    NxOgre_ThrowExceptionIfNull(mReferences, Classes::_unsigned_int);
    return (*mReferences);
   }
   
   inline unsigned int* referencesPtr() const
   {
    return mReferences;
   }
   
   inline bool isNull() const
   {
    return mPtr == 0;
   }

   inline void setNull()
   {
    if (mPtr == 0)
     return;
    release();
    mPtr = 0;
    mReferences = 0;
   }
   
  protected:
   
   inline void release()
   {
    // Got errors from here? Call setNull before shutting down!
    if (--(*mReferences) == 0)
    {
     GC::safe_delete(mPtr, NXOGRE_GC_THIS);
     GC::safe_delete(mReferences, NXOGRE_GC_THIS);
    }
   }
   
  inline void swap(SharedPointer<T>& other)
  {
   std::swap(mPtr, other.mPtr);
   std::swap(mReferences, other.mReferences);
  }
  
  T* mPtr;
  unsigned int* mReferences;
}; // class SharedPtr

template<typename T1, typename T2> inline bool operator==(SharedPointer<T1> const& a, SharedPointer<T2> const& b)
{
 return a.get() == b.get();
}

template<typename T1, typename T2> inline bool operator!=(SharedPointer<T1> const& a, SharedPointer<T2> const& b)
{
 return a.get() != b.get();
}

template<typename T1, typename T2> inline bool operator<(SharedPointer<T1> const& a, SharedPointer<T2> const& b)
{
 return std::less<const void*>(a.get(), b.get());
}
                                                                                       

} // namespace NxOgre

                                                                                       

#endif
