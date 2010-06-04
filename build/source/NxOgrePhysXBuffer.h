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

                                                                                       
#if 0
#ifndef NXOGRE_PHYSXMESHPARTDATA_H
#define NXOGRE_PHYSXMESHPARTDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreBuffer.h"
#include "NxOgreSharedPointer.h"


                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. PhysXBuffer
    desc.
        Chunk of managed memory that holds N types in succession representing vertices, triangles,
        texture coordinates, etc. of a Mesh.
*/
template<typename T, unsigned int N>
class NxOgrePublicTemplateClass PhysXBuffer : public FrequentOperationsAllocatable
{
public:

   PhysXBuffer(unsigned int initialCapacity = 16)
   : mBuffer()
   { // constructor.
    mBuffer.resize(initialCapacity * N);
    mNbElements = GC::safe_allocated_new0<unsigned int, FourByteAllocator>(NXOGRE_GC_THIS);
    (*mNbElements) = 0;
   }

   inline ~PhysXBuffer()
   {
    GC::safe_allocated_delete<unsigned int, FourByteAllocator>(mNbElements, NXOGRE_GC_THIS);
   }

   // Get a pointer to the beginning of the buffer.
   inline T* first()
   {
    return mBuffer.first();
   }

   // How many bytes does one element take up?
   inline unsigned int stride() const
   {
    return sizeof(T) * N;
   }

   // Return the number of __bytes__ used by this buffer.
   inline unsigned int  byte_size() const
   {
    return (*mNbElements) * sizeof(T) * N;
   }
   
   // Return the number of vertices used by this buffer.
   inline unsigned int size() const
   {
    return (*mNbElements);
   }

   // Return the pointer
   inline unsigned int* sizePtr() const
   {
    return mNbElements;
   }

   // Return the number of maximum number of vertices that this buffer can hold.
   inline unsigned int capacity() const
   {
    return mBuffer.capacity() / N;
   }

   // Set the number of maximum number of vertices that this buffer can hold. 
   inline void setCapacity(size_t size)
   {
    mBuffer.resize(size * N);
   }

  protected:

   buffer<T>                      mBuffer;

   unsigned int*                  mNbElements;

};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
#endif
