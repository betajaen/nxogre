/** File: NxOgrePhysXPointer.h
    Created on: 19-Apr-09
    Author: Robin Southern "betajaen"
    SVN: $Id$

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

#ifndef NXOGRE_PHYSXPOINTER_H
#define NXOGRE_PHYSXPOINTER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerClass.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

/** \brief Any NxOgre or user class that is casted into a void* for use in a userData member
           variable in a PhysX class. A parent class may be attached to the Pointer, however
           no class type is specified. It is assumed that the user will know exactly what
           the parent class is, based upon the type of the represented class.
*/
class PhysXPointer : public PointerClass<Classes::_PhysXPointer>
{
 public:
  
  PhysXPointer(void* pClass, void* pParent = 0)
  : mType(Classes::_void), mRepClass(pClass), mParentClass(pParent)
  {
  }
  
  PhysXPointer(void* pClass, unsigned int t, void* pParent = 0)
  : mType(t), mRepClass(pClass), mParentClass(pParent)
  {
  }
  
  
  template<int T>
  PhysXPointer(PointerClass<T>* pClass, void* pParent = 0)
  : mType(T), mRepClass(pClass), mParentClass(pParent)
  {
  }
  
  template<typename T>  T* get(void)
  {
   return static_cast<T*>(mRepClass);
  }
  
  template<typename T>  T* getParent(void)
  {
   return static_cast<T*>(mParentClass);
  }
  

  const unsigned int type(void)
  {
   return mType;
  }
  
 protected:
  
  const int    mType;
  
  void*  mRepClass;

  void*  mParentClass;
  
};

#define pointer_cast(userData) static_cast<PhysXPointer*>(userData)

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
