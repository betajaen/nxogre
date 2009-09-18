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
