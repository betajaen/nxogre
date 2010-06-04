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

                                                                                       

#ifndef NXOGRE_MSWINDOWSFILERESOURCE_H
#define NXOGRE_MSWINDOWSFILERESOURCE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResource.h"


                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. FileResource
    desc.
        File version of a Resource, created via FileArchive.
*/
class NxOgrePublicClass FileResource : public Resource
{
  
 public:
  
  /*! constructor. FileResource
      desc.
          Resource to access a single file on a disk, created via a FileArchive of the FileProtocol.
      args.
          const Path& __path__ -- Relative path of the file from the Archive's path.
          Archive* __archive__ -- Archive that the Resource must belong to. Archive must be a FileArchive.
          Enums::ResourceAccess __access__ -- Access restrictions.
  */
  FileResource(const Path& path, ResourceProtocol* protocol, Enums::ResourceAccess access);
  
  /*! destructor. FileResource
  */
  ~FileResource();
  
  /*! function. getAccess
      desc.
          Get the type of access of the resource
      return.
          **Enums::ResourceAccess** -- Type of access.
  */
  Enums::ResourceAccess  getAccess() const;
  
  /*! function. getStatus
      desc.
          What is the resources status?
      return.
          **Enums::ResourceStatus** -- Current status.
  */
  Enums::ResourceStatus  getStatus() const;
  
  /*! function. getDirectionality
      desc.
          Get the directionality of the resource
  */
  Enums::ResourceDirectionality  getDirectionality() const;
  
  /*! function. open
      desc.
          Open the resource.
  */
  void  open();
  
  /*! function. close
      desc.
          Close the resource.
  */
  void  close();
  
  /*! function. getSize
      desc.
           Get the size (in bytes) of the resource, or Constants::ResourceSizeUnknown.
      note.
           If the Directionality is sucessional or the status is anything but open then
           the file size will be Constants::ResourceSizeUnknown.
      return.
           **size_t** -- Size of the resource in bytes, or Constants::ResourceSizeUnknown.
  */
  size_t  getSize() const;
  
  /*! function. seek
      desc.
           Go somewhere into the resource from, this is relative to the ReadWrite pointer and not an absolute.
      note.
           Depending on status, or directionality this will not be possible.
      return.
           **bool** -- True if the seek did happen, or false if it did not.
  */
  bool  seek(size_t);
  
  /*! function. seekBeginning
      desc.
           Go to the beginning of the resource.
      note.
           Depending on status, or directionality this will not be possible.
      return.
           **bool* -- True if the seek did happen, or false if it did not.
  */
  bool  seekBeginning();
  
  /*! function. seekEnd
      desc.
           Go to the end of the resource.
      note.
           Depending on status, or directionality this will not be possible.
      return.
           **bool** -- True if the seek did happen, or false if it did not.
  */
  bool  seekEnd();
  
  /*! function. atBeginning
      desc.
           Is the ReadWrite pointer at the beginning of Resource?
      return.
           **bool** -- If the ReadWrite pointer is at the beginning of the resource.
  */
  bool  atBeginning() const;
  
  /*! function. atEnd
      desc.
           Is the ReadWrite pointer at the end of Resource, just like a standard "EOF" function.
      return.
           **bool** -- If the ReadWrite pointer is at the end of the resource.
  */
  bool  atEnd() const;
  
  /*! function. at
      desc.
           Where the ReadWrite pointer is.
      note.
           Constants::ResourceSizeUnknown will be returned if it is an unknown. This is a likely value with Streams.
      return.
           **size_t** -- Where the ReadWrite pointer is, in bytes, in relation to the beginning of the resource.
  */
  size_t  at() const;
  
  /*! function. write
      desc.
          Write a chunk of memory to the Resource with a size.
      args.
          const void* __src__ -- The data to write.
          size_t src_size __srcSize__ -- The size of data in _bytes_.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  write(const void* src, size_t src_size);
  
  /*! function. writeNull
      desc.
           Write a single null (0x00) byteto the resource.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeNull();
  
  /*! function. writeBool.0
      desc.
          Write a bool.
      args.
          bool __value__ -- Boolean value to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeBool(bool value);
  
  /*! function. writeBool.1
      desc.
          Write a boolean array.
      args.
          bool __values__ -- Boolean values to write.
          size_t __length__ -- Number of boolean values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeBool(bool* values, size_t length);
  
  /*! function. writeUChar.0
      desc.
          Write a single unsigned char otherwise fail.
      args.
          unsigned char __value__ -- Unsigned char to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeUChar(unsigned char value);
  
  /*! function. writeUChar.1
      desc.
          Write a unsigned char array.
      args.
          unsigned char* __value__ -- Unsigned char to write.
          size_t __length__ -- Number of unsigned char values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeUChar(unsigned char* value, size_t length);
  
  /*! function. writeChar.0
      desc.
          Write a single char.
      args.
          char __value__ -- char to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeChar(char value);
  
  /*! function. writeChar.1
      desc.
          Write a char array.
      args.
          char* __value__ -- Char to write.
          size_t __length__ -- Number of char values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeChar(char*, size_t length);
  
  /*! function. writeUShort.0
      desc.
          Write a single unsigned short otherwise fail.
      args.
          char __value__ -- Unsigned short to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeUShort(unsigned short value);
  
  /*! function. writeUShort.1
      desc.
          Write a single unsigned short..
      args.
          unsigned short* __values__ -- unsigned shorts to write.
          size_t __length__ -- Number of unsigned short values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeUShort(unsigned short* values, size_t length);
  
  /*! function. writeShort.0
      desc.
           Write a single short.
      args.
          short __value__ -- Short to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeShort(short);
  
  /*! function. writeShort.1
      desc.
          Write a short* array.
      args.
          short* __values__ -- Shorts to write.
          size_t __length__ -- Number of short values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeShort(short*, size_t length);
  
  /*! function. writeUInt.0
      desc.
          Write a single unsigned int.
      args.
          unsigned int __value__ -- Unsigned int to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeUInt(unsigned int value);
  
  /*! function. writeShort.1
      desc.
          Write a unsigned int* array.
      args.
          short* __values__ -- Shorts to write.
          size_t __length__ -- Number of short values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeUInt(unsigned int*, size_t length);
  
  /*! function. writeInt.0
      desc.
          Write a single int.
      args.
          unsigned int __value__ -- Int to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeInt(int value);
  
  /*! function. writeInt.1
      desc.
          Write a int* array otherwise fail.
      args.
          short* __values__ -- Ints to write.
          size_t __length__ -- Number of int values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool writeInt(int*, size_t length);
  
  /*! function. writeFloat.0
      desc.
          Write a single float otherwise fail.
      args.
          float __value__ -- float to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeFloat(float);
  
  /*! function. writeFloat.1
      desc.
          Write a float* array otherwise fail.
      args.
          float* __values__ -- Floats to write.
          size_t __length__ -- Number of float values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeFloat(float*, size_t length);
  
  /*! function. writeDouble.0
      desc.
          Write a single double otherwise fail.
      args.
          double __value__ -- Double to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeDouble(double);
  
  /*! function. writeDouble.1
      desc.
          Write a double* array otherwise fail.
      args.
          double* __values__ -- Double to write.
          size_t __length__ -- Number of double values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeDouble(double*, size_t length);
  
  /*! function. writeReal.0
      desc.
          Write a single Real otherwise fail.
      args.
          double __value__ -- Double to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeReal(NxOgreRealType value);
  
  /*! function. writeReal.1
      desc.
          Write a Real* array otherwise fail.
      args.
          Real* __values__ -- Real to write.
          size_t __length__ -- Number of Real values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeReal(NxOgreRealType* values, size_t length);
  
  /*! function. writeLong.0
      desc.
          Write a single long otherwise fail.
      args.
          long __value__ -- Long to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeLong(long value);
  
  /*! function. writeLong.1
      desc.
          Write a long* array otherwise fail.
      args.
          long* __values__ -- long to write.
          size_t __length__ -- Number of long values.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool  writeLong(long* values, size_t length);
  
  /*! function. writeString
      desc.
          Write a string (without a null ending byte) otherwise fail.
      args.
          const String& __string__ -- String to write.
      return.
          **bool** -- If the write was sucessful or not.
  */
  bool writeString(const String&);

  /*! function. readBool
      desc.
          Read a single bool otherwise fail.
      return.
          **bool** -- The read boolean value.
  */
  bool  readBool();
  
  /*! function. readBoolArray
      desc.
          Write a bool* array otherwise fail.
      args.
          bool* __values__ -- bools to write.
          size_t __length__ -- Number of bool values.
  */
  void  readBoolArray(bool*, size_t length);
  
  /*! function. readUChar
      desc.
          Read a single unsigned char.
      return.
          **bool** -- The read unsigned char value.
  */
  unsigned char  readUChar();
  
  /*! function. readUCharArray
      desc.
          Write a unsigned char* array otherwise fail.
      args.
          unsigned char* __values__ -- unsigned chars to write.
          size_t __length__ -- Number of unsigned char values.
  */
  void  readUCharArray(unsigned char* values, size_t length);
  
  /*! function. readChar
      desc.
          Read a single char.
      return.
          **char** -- The read char value.
  */
  char  readChar();
  
  /*! function. readCharArray
      desc.
          Read a char* array otherwise fail.
      args.
          char* __values__ -- Char to write.
          size_t __length__ -- Number of long values.
  */
  void  readCharArray(char* values, size_t length);
  
  /*! function. readUShort
      desc.
          Read a single unsigned short.
      return.
          **unsigned short** -- The read unsigned short value.
  */
  unsigned short  readUShort();
  
  /*! function. readUShortArray
      desc.
          Read a unsigned short* array otherwise fail.
      args.
          unsigned short* __values__ --  Read unsigned shorts.
          size_t __length__ -- Number of unsigned short values.
  */
  void  readUShortArray(unsigned short* values, size_t length);
  
  /*! function. readShort
      desc.
          Read a single short otherwise fail.
      return.
          **Short** -- The read short value.
  */
  short  readShort();
  
  /*! function. readShortArray
      desc.
          Read a short* array otherwise fail.
      args.
          short* __values__ -- Read shorts.
          size_t __length__ -- Number of short values.
  */
  void  readShortArray(short* values, size_t length);
  
  /*! function. readUInt
      desc.
          Read a single unsigned int.
      return.
          **unsigned int** -- The read unsigned int value.
  */
  unsigned int  readUInt();
  
  /*! function. readUIntArray
      desc.
          Read a unsigned int* array otherwise fail.
      args.
          unsigned int* __values__ -- unsigned ints to write.
          size_t __length__ -- Number of unsigned ints values.
  */
  void  readUIntArray(unsigned int* value, size_t length);
  
  /*! function. readInt
      desc.
          Read a single int.
      return.
          **int** -- The read int value.
  */
  int  readInt();
  
  /*! function. readIntArray
      desc.
          Read a int* array otherwise fail.
      args.
          unsigned int* __values__ -- Read ints.
          size_t __length__ -- Number of int values.
  */
  void  readIntArray(int* values, size_t length);
  
  /*! function. readFloat
      desc.
          Read a single float.
      return.
          **int** -- The read float value.
  */
  float  readFloat();
  
  /*! function. readFloatArray
      desc.
          Read a float* array otherwise fail.
      args.
          unsigned float* __values__ -- Read float values.
          size_t __length__ -- Number of float values.
  */
  void  readFloatArray(float*, size_t length);
  
  /*! function. readDouble
      desc.
          Read a single double.
      return.
          **double** -- The read double value.
  */
  double  readDouble();
  
  /*! function. readDoubleArray
      desc.
          Read a double* array otherwise fail.
      args.
          double* __values__ -- Read double values.
          size_t __length__ -- Number of double values.
  */
  void  readDoubleArray(double* values, size_t length);
  
  /*! function. readReal
      desc.
          Read a single Real.
      return.
          **Real** -- The read Real value.
  */
  Real  readReal();
  
  /*! function. readDoubleArray
      desc.
          Read a Real* array otherwise fail.
      args.
          Real* __values__ -- Read Real values.
          size_t __length__ -- Number of double values.
  */
  void  readRealArray(NxOgreRealType* values, size_t length);
    
  /*! function. readLong
      desc.
          Read a single long.
      return.
          **long** -- The read long value.
  */
  long  readLong();

  
  /*! function. readDoubleArray
      desc.
          Read a long* array otherwise fail.
      args.
          long* __values__ -- Read long values.
          size_t __length__ -- Number of long values.
  */
  void  readLongArray(long*, size_t length);
  
  /*! function. flush
      desc.
          Flush any write operations now.
  */
  void  flush();
  
  protected: // Variables
  
  /* File pointer
  */
  FILE*         mFile;
  
}; // class FileResource

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
