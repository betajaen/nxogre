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



#ifndef NXOGRE_PHYSXPOINTER_H
#define NXOGRE_PHYSXPOINTER_H



#include "NxOgreStable.h"
#include "NxOgreAllocatables.h"
#include "NxOgreClasses.h"



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
class PhysXPointer : public SixteenBytesAllocatable
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

  template<typename T>  T* get()
  {
   return static_cast<T*>(mRepClass);
  }

  template<typename T>  T* getParent()
  {
   return static_cast<T*>(mParentClass);
  }


  const unsigned int type()
  {
   return mType;
  }

 protected:

  int          mType;

  void*        mRepClass;

  void*        mParentClass;

  int          RESERVED;
};

//NxOgreSixteenBytesRestriction(PhysXPointer);


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
