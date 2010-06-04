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

                                                                                       

#ifndef NXOGRE_VERTEXBUFFER_H
#define NXOGRE_VERTEXBUFFER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreBuffer.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. VertexBuffer
    desc.
        Chunk of managed memory that holds floats in succession representing vertices.
*/
class NxOgrePublicTemplateClass VertexBuffer : public FrequentOperationsAllocatable
{

  public:

   friend class MeshRenderable;

   inline VertexBuffer()
   {
    mNbElements = GC::safe_allocated_new0<unsigned int, FourByteAllocator>(NXOGRE_GC_THIS);
    *mNbElements = 0;
   }

   inline ~VertexBuffer()
   {
    GC::safe_allocated_delete<unsigned int, FourByteAllocator>(mNbElements, NXOGRE_GC_THIS);
   }

   /*! function. vertices
       desc.
           pointer to the first vertex's X element, each elements are ordered as so; XYZXYZXYZXYZXYZ etc.
   */
   inline float* vertices()
   {
    return mBuffer.first();
   }

   /*! function. capacity
       desc.
           how many vertices the buffer can take.
   */
   inline unsigned int capacity() const
   {
    return mBuffer.capacity() / 3;
   }

   /*! function. capacity
       desc.
           how much physical bytes the buffer takes.
   */
   inline unsigned int capacity_bytes() const
   {
    return mBuffer.capacity() * sizeof(float);
   }

   /*! function. bytes
       desc.
           how much physical bytes in use in the buffer.
   */
   inline unsigned int bytes() const
   {
    return count() * 3 * sizeof(float);
   }

   /*! function. count
       desc.
           number of vertices (buffer.size / 3)
   */
   inline unsigned int count() const
   {
    return *mNbElements;
   }

   /*! function. count_ptr
       desc.
           pointer to the number of vertices.
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

   buffer<float>                  mBuffer;
   unsigned int*                  mNbElements;

};

/*! class. NormalBuffer
    desc.
        Chunk of managed memory that holds floats in succession representing vertices.
*/
class NxOgrePublicTemplateClass NormalBuffer : public FrequentOperationsAllocatable
{

  public:

   friend class MeshRenderable;

   inline NormalBuffer()
   {
    mNbElements = GC::safe_allocated_new0<unsigned int, FourByteAllocator>(NXOGRE_GC_THIS);
    *mNbElements = 0;
   }

   inline ~NormalBuffer()
   {
    GC::safe_allocated_delete<unsigned int, FourByteAllocator>(mNbElements, NXOGRE_GC_THIS);
   }

   /*! function. normals
       desc.
           pointer to the first normal's X element, each elements are ordered as so; XYZXYZXYZXYZXYZ etc.
   */
   inline float* normals()
   {
    return mBuffer.first();
   }

   /*! function. capacity
       desc.
           how many normals the buffer can take.
   */
   inline unsigned int capacity() const
   {
    return mBuffer.capacity() / 3;
   }

   /*! function. capacity
       desc.
           how much physical bytes the buffer takes.
   */
   inline unsigned int  capacity_bytes() const
   {
    return mBuffer.capacity() * sizeof(float);
   }

   /*! function. bytes
       desc.
           how much physical bytes in use in the buffer.
   */
   inline unsigned int  bytes() const
   {
    return count() * 3 * sizeof(float);
   }

   /*! function. count
       desc.
           number of vertices (buffer.size / 3)
   */
   inline unsigned int  count() const
   {
    return *mNbElements;
   }

   /*! function. count_ptr
       desc.
           pointer to the number of vertices.
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

   buffer<float>                  mBuffer;
   unsigned int*                  mNbElements;

};


/*! class. TextureCoordinateBuffer
    desc.
        Chunk of managed memory that holds floats in succession representing vertices.
*/
class NxOgrePublicTemplateClass TextureCoordinateBuffer : public FrequentOperationsAllocatable
{

  public:

   friend class MeshRenderable;

   inline TextureCoordinateBuffer()
   {
    mNbElements = GC::safe_allocated_new0<unsigned int, FourByteAllocator>(NXOGRE_GC_THIS);
    *mNbElements = 0;
   }

   inline ~TextureCoordinateBuffer()
   {
    GC::safe_allocated_delete<unsigned int, FourByteAllocator>(mNbElements, NXOGRE_GC_THIS);
   }

   /*! function. normals
       desc.
           pointer to the first texture coordinate's U element, each elements are ordered as so; UVUVUVUVUVUV etc.
   */
   inline float* texture_coords()
   {
    return mBuffer.first();
   }

   /*! function. capacity
       desc.
           how many normals the buffer can take.
   */
   inline unsigned int capacity() const
   {
    return mBuffer.capacity() / 2;
   }

   /*! function. capacity
       desc.
           how much physical bytes the buffer takes.
   */
   inline unsigned int  capacity_bytes() const
   {
    return mBuffer.capacity() * sizeof(float);
   }

   /*! function. bytes
       desc.
           how much physical bytes in use in the buffer.
   */
   inline unsigned int  bytes() const
   {
    return count() * 2 * sizeof(float);
   }

   /*! function. count
       desc.
           number of vertices (buffer.size / 3)
   */
   inline unsigned int  count() const
   {
    return *mNbElements;
   }

   /*! function. count_ptr
       desc.
           pointer to the number of vertices.
   */
   inline unsigned int* count_ptr()
   {
    return mNbElements;
   }

  protected:

   /*! function. set_capacity
       desc.
           set how many texture coords the buffer should take.
   */
   inline void set_capacity(unsigned int new_size)
   {
    mBuffer.resize(new_size * 2);
   }

  protected:

   buffer<float>                  mBuffer;
   unsigned int*                  mNbElements;

};


/*! class. RGBABuffer
    desc.
        Chunk of managed memory that holds unsigned ints in succession representing representing a RGBA colour.
*/
class NxOgrePublicTemplateClass RGBABuffer : public FrequentOperationsAllocatable
{

  public:

   friend class MeshRenderable;

   inline RGBABuffer()
   {
    mNbElements = GC::safe_allocated_new0<unsigned int, FourByteAllocator>(NXOGRE_GC_THIS);
    *mNbElements = 0;
   }

   inline ~RGBABuffer()
   {
    GC::safe_allocated_delete<unsigned int, FourByteAllocator>(mNbElements, NXOGRE_GC_THIS);
   }

   /*! function. normals
       desc.
           pointer to the first normal's X element, each elements are ordered as so; XYZXYZXYZXYZXYZ etc.
   */
   inline unsigned int* rgba()
   {
    return mBuffer.first();
   }

   /*! function. setCapacity
       desc.
           set how many colours the buffer should take.
   */
   inline void setCapacity(unsigned int new_size)
   {
    mBuffer.resize(new_size);
   }

   /*! function. capacity
       desc.
           how colours the buffer can take.
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

   /*! function. count
       desc.
           number of colours
   */
   inline unsigned int count() const
   {
    return *mNbElements;
   }

   /*! function. count_ptr
       desc.
           pointer to the number of vertices.
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
    mBuffer.resize(new_size);
   }

  protected:

   buffer<unsigned int>           mBuffer;
   unsigned int*                  mNbElements;

};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
