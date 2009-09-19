/** File: NxOgreSharedPointer.h
    Created on: 15-Nov-08
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

#ifndef NXOGRE_SHAREDPOINTER_H
#define NXOGRE_SHAREDPOINTER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMemory.h"

                                                                                       

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
   mReferences = (unsigned short*) NxOgre_Allocate(sizeof(unsigned short), Classes::_BufferReferenceCounter)
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
     NxOgre_Delete(mPtr);
     NxOgre_Unallocate(mReferences);
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
     NxOgre_Delete(mPtr);
     NxOgre_Unallocate(mReferences);
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
  
                         T*                    mPtr;
                         unsigned short*       mReferences;
  
}; // class ClassName


template <typename T1, typename T2> inline bool operator==(SharedPointer<T1> const& first, SharedPointer<T2> const& second)
{
 return first.get() == second.get();
}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
