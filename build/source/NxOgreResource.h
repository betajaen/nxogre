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

                                                                                       

#ifndef NXOGRE_RESOURCE_H
#define NXOGRE_RESOURCE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       


/** \brief A Resource represents a file or a block of data. It can be streamed from or accessed randomly. Resources should
     be created via the ResourceSystem and handled safely in a Resource*.
 \example
  <code>
    Resource* res = ResourceSystem::getSingleton()->open("file://test.bin", Enums::ResourceAccess_ReadAndWrite);
    res->writeChar('d');
    res->seekBack(5);
    char* c = (char*) NxOgre_Allocate(Classes::_char, sizeof(char) * 5);
    res->readCharArray(c, sizeof(char) * 5);
  </code>
*/
class NxOgrePublicClass Resource : public ResourceAllocatable
{
  
  public: // Functions
  
  /** \brief Required abstract constructor
  */
  Resource(const Path& relative_path, ResourceProtocol*, Enums::ResourceAccess);
  
  /** \brief Required virtual destructor
  */
  virtual ~Resource();
  
  /** \brief Get the protocol.
  */
  ResourceProtocol* getProtocol();
  
  /** \brief Get the resource location; e.x. filename, memory address, etc.
  */
  Path getPath() const;
  
  /** \brief Has the resource been "touched" by a write operation?
  */
  bool hasTouched() const;
  
  /** \brief Get the number of read wrote on that resource.
  */
  unsigned int getNbBytesRead() const;
  
  /** \brief Get the number of bytes wrote on that resource.
  */
  unsigned int getNbBytesWrote() const;
  
  /** \brief What is the resources status?
  */
  virtual Enums::ResourceStatus getStatus() const;
  
  /** \brief Get the directionality of the resource
  */
  virtual Enums::ResourceDirectionality getDirectionality() const;
  
  /** \brief Get the type of access of the resource
  */
  virtual Enums::ResourceAccess   getAccess() const;
  
  /** \brief Get the size (in bytes) of the resource, or Constants::ResourceSizeUnknown.
   \note  If the Directionality is sucessional or the status is anything but open then
    the file size will be Constants::ResourceSizeUnknown.
  */
  virtual size_t  getSize() const;
  
  /** \brief Go somewhere into the resource from, this is relative to the ReadWrite pointer and not an absolute.
   \note Depending on status, or directionality this will not be possible.
   \return True if the seek did happen, or false if it did not.
  */
  virtual bool seek(size_t);

  /** \brief Go to the beginning of the resource.
   \note Depending on status, or directionality this will not be possible.
   \return True if the seek did happen, or false if it did not.
  */
  virtual bool seekBeginning();

  /** \brief Go to the end of the resource.
   \note Depending on status, or directionality this will not be possible.
   \return True if the seek did happen, or false if it did not.
  */
  virtual bool seekEnd();

  /** \brief Is the ReadWrite pointer at the end of Resource?
  */
  virtual bool atBeginning() const;

  /** \brief Is the ReadWrite pointer at the end of Resource, just like a standard "EOF" function.
  */
  virtual bool atEnd() const;

  /** \brief Where the ReadWrite is from the beginning of the resource.
   \note  Constants::ResourceSizeUnknown will be returned if it is an unknown.
  */
  virtual size_t  at() const;

  /** \brief Write something otherwise fail.
  */
  virtual bool write(const void* src, size_t src_size);

  /** \brief Write a single null (0x00) to the resource otherwise fail.
  */
  virtual bool writeNull();

  /** \brief Write a bool otherwise fail.
  */
  virtual bool writeBool(bool);

  /** \brief Write a bool* array otherwise fail.
   \note  Length should be given as "array_size * sizeof(T)" or the same value you give
    to NxOgre_Allocate as a size.
  */
  virtual bool writeBool(bool*, size_t length);

  /** \brief Write a single unsigned char otherwise fail.
  */
  virtual bool writeUChar(unsigned char);

  /** \brief Write a unsigned char* array otherwise fail.
   \note  Length should be given as "array_size * sizeof(T)" or the same value you give
    to NxOgre_Allocate as a size.
  */
  virtual bool writeUChar(unsigned char*, size_t length);

  /** \brief Write a single char otherwise fail.
  */
  virtual bool writeChar(char);

  /** \brief Write a char* array otherwise fail.
  */
  virtual bool writeChar(char*, size_t length);

  /** \brief Write a single unsigned short otherwise fail.
  */
  virtual bool writeUShort(unsigned short);

  /** \brief Write a unsigned short* array otherwise fail.
  */
  virtual bool writeUShort(unsigned short*, size_t length);

  /** \brief Write a single short otherwise fail.
  */
  virtual bool writeShort(short);

  /** \brief Write a short* array otherwise fail.
  */
  virtual bool writeShort(short*, size_t length);

  /** \brief Write a single unsigned int otherwise fail.
  */
  virtual bool writeUInt(unsigned int);

  /** \brief Write a unsigned int* array otherwise fail.
  */
  virtual bool writeUInt(unsigned int*, size_t length);

  /** \brief Write a single int otherwise fail.
  */
  virtual bool writeInt(int);

  /** \brief Write a int* array otherwise fail.
  */
  virtual bool writeInt(int*, size_t length);

  /** \brief Write a single float otherwise fail.
  */
  virtual bool writeFloat(float);

  /** \brief Write a float* array otherwise fail.
  */
  virtual bool writeFloat(float*, size_t length);

  /** \brief Write a single double otherwise fail.
  */
  virtual bool writeDouble(double);

  /** \brief Write a double* array otherwise fail.
  */
  virtual bool writeDouble(double*, size_t length);

  /** \brief Write a float or double otherwise fail
  */
  virtual bool writeReal(NxOgreRealType);

  /** \brief Write a float or double array otherwise fail
  */
  virtual bool writeReal(NxOgreRealType*, size_t length);

  /** \brief Write a single long otherwise fail.
  */
  virtual bool writeLong(long);

  /** \brief Write a long* array otherwise fail.
  */
  virtual bool writeLong(long*, size_t length);

  /** \brief Write a null terminated string
  */
  virtual bool writeString(const String&);

  /** \brief Read a bool otherwise fail.
  */
  virtual bool readBool();

  /** \brief Read a bool* array otherwise fail.
   \note  Length should be given as "array_size * sizeof(T)" or the same value you give
    to NxOgre_Allocate as a size.
  */
  virtual void readBoolArray(bool*, size_t length);

  /** \brief Read a single unsigned char otherwise fail.
  */
  virtual unsigned char   readUChar();

  /** \brief Read a unsigned char* array otherwise fail.
   \note  Length should be given as "array_size * sizeof(T)" or the same value you give
    to NxOgre_Allocate as a size.
  */
  virtual void readUCharArray(unsigned char*, size_t length);

  /** \brief Read a single char otherwise fail.
  */
  virtual char readChar();

  /** \brief Read a char* array otherwise fail.
   \note  Length should be given as "array_size * sizeof(T)" or the same value you give
    to NxOgre_Allocate as a size.
  */
  virtual void readCharArray(char*, size_t length);

  /** \brief Read a single unsigned short otherwise fail.
  */
  virtual unsigned short  readUShort();

  /** \brief Read a unsigned short* array otherwise fail.
   \note  Length should be given as "array_size * sizeof(T)" or the same value you give
    to NxOgre_Allocate as a size.
  */
  virtual void readUShortArray(unsigned short*, size_t length);

  /** \brief Read a single short otherwise fail.
  */
  virtual short   readShort();

  /** \brief Read a short* array otherwise fail.
  */
  virtual void readShortArray(short*, size_t length);

  /** \brief Read a single unsigned int otherwise fail.
  */
  virtual unsigned int    readUInt();

  /** \brief Read a unsigned int* array otherwise fail.
  */
  virtual void readUIntArray(unsigned int*, size_t length);

  /** \brief Read a single int otherwise fail.
  */
  virtual int  readInt();

  /** \brief Read a int* array otherwise fail.
  */
  virtual void readIntArray(int*, size_t length);

  /** \brief Read a single float otherwise fail.
  */
  virtual float   readFloat();

  /** \brief Read a float* array otherwise fail.
  */
  virtual void readFloatArray(float*, size_t length);

  /** \brief Read a single double otherwise fail.
  */
  virtual double  readDouble();

  /** \brief Read a double* array otherwise fail.
  */
  virtual void readDouble(double*, size_t length);

  /** \brief Read a float or double otherwise fail
  */
  virtual Real readReal();

  /** \brief Read a float or double array otherwise fail
  */
  virtual void readRealArray(NxOgreRealType*, size_t length);

  /** \brief Read a single long otherwise fail.
  */
  virtual long readLong();

  /** \brief Read a long* array otherwise fail.
  */
  virtual void readLongArray(long*, size_t length);
  
  /** \brief Force any changes to the resource
  */
  virtual void flush();
    
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  protected: // Variables
  
  /** \brief Open the resource.
  */
  void  open();
  
  /** \brief Close the resource.
  */
  void  close();

  /** \internal Local copy of the resource location
  */
  Path    mPath;
  
  /** \internal Local copy of the resource status. Updated often throughout the resources lifetime.
  */
  Enums::ResourceStatus   mStatus;
  
  /** \internal Local copy of the resource directionality.
  */
  Enums::ResourceDirectionality mDirectionality;
  
  /** \internal Local copy of the resource resource access.
  */
  Enums::ResourceAccess   mAccess;
  
  /** \brief Parent archive
  */
  ResourceProtocol*  mProtocol;
  
  /** \internal A single null byte
  */
  static const char    NULL_BYTE;
  
  /* Number of bytes read.
  */
  unsigned int mNbReadBytes;
  
  /* Number of bytes wrote.
  */
  unsigned int mNbWroteBytes;

}; // class Resource

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
