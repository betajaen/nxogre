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

                                                                                       

#ifndef NXOGRE_INDEXBUFFER_H
#define NXOGRE_INDEXBUFFER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreBuffer.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. IndexBuffer
    desc.
        Chunk of managed memory that holds unsigned ints in succession representing representing triangles.
*/
class NxOgrePublicTemplateClass IndexBuffer : public FrequentOperationsAllocatable
{

  public:

   friend class MeshRenderable;

   inline IndexBuffer()
   {
    mNbElements = GC::safe_allocated_new0<unsigned int, FourByteAllocator>(NXOGRE_GC_THIS);
    *mNbElements = 0;
   }

   inline ~IndexBuffer()
   {
    GC::safe_allocated_delete<unsigned int, FourByteAllocator>(mNbElements, NXOGRE_GC_THIS);
   }

   /*! function. normals
       desc.
           pointer to the first index of the first triangle; order is ABCABCABCABC etc
   */
   inline unsigned int* indexes()
   {
    return mBuffer.first();
   }
  
   /*! function. capacity
       desc.
           how much physical bytes the buffer takes.
   */
   inline unsigned int capacity() const
   {
    return mBuffer.capacity();
   }

   /*! function. capacity
       desc.
           how much physical bytes the buffer takes.
   */
   inline unsigned int capacity_bytes() const
   {
    return mBuffer.capacity() * sizeof(unsigned int);
   }

   /*! function. bytes
       desc.
           how much physical bytes in use in the buffer.
   */
   inline unsigned int bytes() const
   {
    return count() * sizeof(unsigned int);
   }

   /*! function. triangles
       desc.
           number of triangles
   */
   inline unsigned int triangles() const
   {
    return count() / 3;
   }

   /*! function. count
       desc.
           number of indexes
   */
   inline unsigned int count() const
   {
    return *mNbElements;
   }

   /*! function. count_ptr
       desc.
           pointer to the number of indexes.
   */
   inline unsigned int* count_ptr()
   {
    return mNbElements;
   }

  protected:

   /*! function. set_capacity
       desc.
           set how many vertices the buffer should take.
   */
   inline void set_capacity(unsigned int new_size)
   {
    mBuffer.resize(new_size * 3);
   }

  protected:

   buffer<unsigned int>           mBuffer;
   unsigned int*                  mNbElements;

};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
