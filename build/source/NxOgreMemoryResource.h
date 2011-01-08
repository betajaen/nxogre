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

                                                                                       

#ifndef NXOGRE_MEMORYRESOURCE_H
#define NXOGRE_MEMORYRESOURCE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResource.h"


                                                                                       

namespace NxOgre
{

                                                                                       

/** \internal Do not use directly. Use Resource* and ResourceSystem::open
*/
class NxOgrePublicClass MemoryResource : public Resource
{
 
 friend class MemoryResourceProtocol;
 
 public:
  
  /** \brief
  */
                                             MemoryResource(ResourceProtocol*);
  
  /** \brief
  */
                                            ~MemoryResource();
  
  /** \brief What is the resources status?
  */
                       Enums::ResourceStatus getStatus() const;
  
  /** \brief Get the directionality of the resource
  */
                       Enums::ResourceDirectionality getDirectionality() const;
  
  /** \brief Get the type of access of the resource
  */
                        Enums::ResourceAccess         getAccess() const;

  /** \brief Get the size (in bytes) of the resource, or Constants::ResourceSizeUnknown.
      \note  If the Directionality is sucessional or the status is anything but open then
             the file size will be Constants::ResourceSizeUnknown.
  */
                       size_t                getSize() const;
  
  /** \brief Go somewhere into the resource from, this is relative to the ReadWrite pointer and not an absolute.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
                       bool                  seek(size_t);
  
  /** \brief Go to the beginning of the resource.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
                       bool                  seekBeginning();
  
  /** \brief Go to the end of the resource.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
                       bool                  seekEnd();
  
  /** \brief Is the ReadWrite pointer at the end of Resource?
  */
                       bool                  atBeginning() const;
  
  /** \brief Is the ReadWrite pointer at the end of Resource, just like a standard "EOF" function.
  */
                       bool                  atEnd() const;
  
  /** \brief Where the ReadWrite is from the beginning of the resource.
      \note  Constants::ResourceSizeUnknown will be returned if it is an unknown.
  */
                       size_t                at() const;
  
  /** \brief Write something to the buffer, with a size otherwise fail.
  */
                       bool                  write(const void* src, size_t src_size);
  
  /** \brief Write a single null (0x00) to the resource otherwise fail.
  */
                       bool                  writeNull();
  
  /** \brief Write a bool otherwise fail.
  */
                       bool                  writeBool(bool);
  
  /** \brief Write a bool* array otherwise fail.
  */
                       bool                  writeBool(bool*, size_t length);
  
  /** \brief Write a single unsigned char otherwise fail.
  */
                       bool                  writeUChar(unsigned char);
  
  /** \brief Write a unsigned char* array otherwise fail.
  */
                       bool                  writeUChar(unsigned char*, size_t length);
  
  /** \brief Write a single char otherwise fail.
  */
                       bool                  writeChar(char);
  
  /** \brief Write a char* array otherwise fail.
  */
                       bool                  writeChar(char*, size_t length);
  
  /** \brief Write a single unsigned short otherwise fail.
  */
                       bool                  writeUShort(unsigned short);
  
  /** \brief Write a unsigned short* array otherwise fail.
  */
                       bool                  writeUShort(unsigned short*, size_t length);
  
  /** \brief Write a single short otherwise fail.
  */
                       bool                  writeShort(short);
  
  /** \brief Write a short* array otherwise fail.
  */
                       bool                  writeShort(short*, size_t length);
  
  /** \brief Write a single unsigned int otherwise fail.
  */
                       bool                  writeUInt(unsigned int);
  
  /** \brief Write a unsigned int* array otherwise fail.
  */
                       bool                  writeUInt(unsigned int*, size_t length);
  
  /** \brief Write a single int otherwise fail.
  */
                       bool                  writeInt(int);
  
  /** \brief Write a int* array otherwise fail.
  */
                       bool                  writeInt(int*, size_t length);
  
  /** \brief Write a single float otherwise fail.
  */
                       bool                  writeFloat(float);
  
  /** \brief Write a float* array otherwise fail.
  */
                       bool                  writeFloat(float*, size_t length);
  
  /** \brief Write a single double otherwise fail.
  */
                       bool                  writeDouble(double);
  
  /** \brief Write a double* array otherwise fail.
  */
                       bool                  writeDouble(double*, size_t length);
  
  /** \brief Write a float or double otherwise fail
  */
                       bool                  writeReal(NxOgreRealType);
  
  /** \brief Write a float or double array otherwise fail
  */
                       bool                  writeReal(NxOgreRealType*, size_t length);
  
  /** \brief Write a single long otherwise fail.
  */
                       bool                  writeLong(long);
  
  /** \brief Write a long* array otherwise fail.
  */
                       bool                  writeLong(long*, size_t length);
  
  /** \brief Write a single long otherwise fail.
  */
                       bool                  writeString(const String&);
  
  /** \brief Read a bool otherwise fail.
  */
                       bool                  readBool();
  
  /** \brief Read a bool* array otherwise fail.
  */
                       void                  readBoolArray(bool*, size_t length);
  
  /** \brief Read a single unsigned char otherwise fail.
  */
                       unsigned char         readUChar();
  
  /** \brief Read a unsigned char* array otherwise fail.
  */
                       void                  readUCharArray(unsigned char*, size_t length);
  
  /** \brief Read a single char otherwise fail.
  */
                       char                  readChar();
  
  /** \brief Read a char* array otherwise fail.
  */
                       void                  readCharArray(char*, size_t length);
  
  /** \brief Read a single unsigned short otherwise fail.
  */
                       unsigned short        readUShort();
  
  /** \brief Read a unsigned short* array otherwise fail.
  */
                       void                  readUShortArray(unsigned short*, size_t length);
  
  /** \brief Read a single short otherwise fail.
  */
                       short                 readShort();
  
  /** \brief Read a short* array otherwise fail.
  */
                       void                  readShortArray(short*, size_t length);
  
  /** \brief Read a single unsigned int otherwise fail.
  */
                       unsigned int          readUInt();
  
  /** \brief Read a unsigned int* array otherwise fail.
  */
                       void                  readUIntArray(unsigned int*, size_t length);
  
  /** \brief Read a single int otherwise fail.
  */
                       int                   readInt();
  
  /** \brief Read a int* array otherwise fail.
  */
                       void                  readIntArray(int*, size_t length);
  
  /** \brief Read a single float otherwise fail.
  */
                       float                  readFloat();
  
  /** \brief Read a float* array otherwise fail.
  */
                       void                  readFloatArray(float*, size_t length);
  
  /** \brief Read a single double otherwise fail.
  */
                       double                readDouble();
  
  /** \brief Read a double* array otherwise fail.
  */
                       void                  readDouble(double*, size_t length);
  
  /** \brief Read a float or double otherwise fail
  */
                       Real                  readReal();
  
  /** \brief Read a float or double array otherwise fail
  */
                       void                  readRealArray(NxOgreRealType*, size_t length);
  
  /** \brief Read a single long otherwise fail.
  */
                       long                  readLong();
  
  /** \brief Read a long* array otherwise fail.
  */
                       void                  readLongArray(long*, size_t length);
  
  /** \brief Flush function. Not applicable to memory
  */
                       void                  flush();
  
  /** \brief Get the pointer to the first byte of the memory resource
  */
                       char*                 getStart() const;
  
  protected:
  
  /** \brief Open the resource.
  */
                       void                  open();
  
  /** \brief Close the resource.
  */
                       void                  close();
  
  void _willFit(size_t dataSize);
  
  protected: // Variables
  
  safe_memory                                mMemory;
  size_t                                     mIndex;
  
}; // class MemoryResource

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
