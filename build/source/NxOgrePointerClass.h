/** File: PointerClass.h
    Created on: 2-Nov-08
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

#ifndef NXOGRE_POINTERCLASS_H
#define NXOGRE_POINTERCLASS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreClasses.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief PointerClass is inherited by all classes of NxOgre that intend to be used as a pointer,
           it overrides the new/delete operators allowing them to be allocated using the Memory
           class.
    \example
      "Ti" is an unique identifier. In NxOgre; those are defined in NxOgreClasses.h. If you want to use
      your own; then an integer over 75000 is considered "User space".
      <code>
       class myClass : public PointerClass<_myClass>
      </code>
*/
template<unsigned int Ti> class PointerClass
{
   
  public: // Functions
   
   virtual unsigned int getClassType() const
   {
    return Ti;
   }
   
   void* operator new(size_t size)
   {
    return NxOgre_Allocate(size, Ti);
   }
   
   void* operator new(size_t size, void* ptr)
   {
    return ptr;
   }
   
   void* operator new[](size_t size)
   {
    return NxOgre_Allocate(size, Ti);
   }
   
   void operator delete(void* mem)
   {
    NxOgre_Unallocate(mem);
   }
   
   void operator delete[](void* mem)
   {
    NxOgre_Unallocate(mem);
   }
   
}; // class PointerClass

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
