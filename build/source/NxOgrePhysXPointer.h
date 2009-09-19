/** File: NxOgrePhysXPointer.h
    Created on: 19-Apr-09
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

#ifndef NXOGRE_PHYSXPOINTER_H
#define NXOGRE_PHYSXPOINTER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerClass.h"

                                                                                       

class NxShape;

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Any NxOgre or user class that is casted into a void* for use in a userData member
           variable in a PhysX class. A parent class may be attached to the Pointer, however
           no class type is specified. It is assumed that the user will know exactly what
           the parent class is, based upon the type of the represented class.
    \note  Shapes are the exception to this rule, and have 0 or very briefly their representive
           Shape as userData. 
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


/** \brief Handy helper macro to get a PhysXPointer instance.
    \usage PhysXPointer* ptr = pointer_cast(physx_class->userData);
*/
#define pointer_cast(userData) static_cast<PhysXPointer*>(userData)

/** \brief Handy helper function to get a PhysX userData's representive class.
    \usage MyClass* my_class = pointer_representive_cast<MyClass>(physx_class->userData);
    \return The representive class or 0 if userData is null.
*/
template<class rep_class> inline rep_class* pointer_representive_cast(void* userData)
{
 if (userData)
  return static_cast<PhysXPointer*>(userData)->get<rep_class>();
 return 0;
}

/** \brief Handy helper function to get a PhysX userData's parent class.
    \usage ParentClass* parent = pointer_parent_cast<ParentClass>(physx_class->userData);
    \return The parent class or 0 if userData is null.
*/
template<class parent_class> inline parent_class* pointer_parent_cast(void* userData)
{
 if (userData)
  return static_cast<PhysXPointer*>(userData)->getParent<parent_class>();
 return 0;
}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
