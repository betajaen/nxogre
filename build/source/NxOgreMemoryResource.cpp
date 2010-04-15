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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMemoryResource.h"

#ifdef _DEBUG
#include <iostream>
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

MemoryResource::MemoryResource(ResourceProtocol* protocol)
:Resource(MEMORY_PATH, protocol, Enums::ResourceAccess_ReadAndWrite), mStart(0), mEnd(0), mPointer(0)
{
}

MemoryResource::~MemoryResource(void)
{
 if (mStatus == Enums::ResourceStatus_Opened)
  close();
}

Enums::ResourceStatus MemoryResource::getStatus(void) const
{
 return mStatus;
}

Enums::ResourceDirectionality MemoryResource::getDirectionality(void) const
{
 return mDirectionality;
}

void MemoryResource::open(void)
{
 if (mStatus == Enums::ResourceStatus_Opened || mStatus == Enums::ResourceStatus_Opening)
  return;
 
 mStatus = Enums::ResourceStatus_Opening;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 mAccess = Enums::ResourceAccess_ReadAndWrite;

#ifdef NXOGRE_DEBUG_RESOURCES
 std::cout << "[+] Opening Memory resource" << std::endl;
#endif
 
 mStart = (char*) NXOGRE_ALLOCATE(ResourceAllocator, 16);
 mEnd = mStart + 16;
 mPointer = mStart;
 mStatus = Enums::ResourceStatus_Opened;
 mDirectionality = Enums::ResourceDirectionality_Omidirectional;

}

void MemoryResource::close(void)
{
 if (mStatus != Enums::ResourceStatus_Opened)
  return;
 
 mStatus = Enums::ResourceStatus_Closing;
 mDirectionality = Enums::ResourceDirectionality_Unknown;

#ifdef NXOGRE_DEBUG_RESOURCES
 std::cout << "[-] Closing Memory resource. -> End Size is " << int(mEnd - mStart) << " bytes" << std::endl;
#endif
 
 if (mStart)
  NXOGRE_DEALLOCATE(ResourceAllocator, mStart);
 mStart = mEnd = mPointer = 0;
 mStatus = Enums::ResourceStatus_Closed;
 
}

Enums::ResourceAccess  MemoryResource::getAccess(void) const
{
 return mAccess;
}

size_t MemoryResource::getSize(void) const
{
 return (mEnd - mStart);
}

bool MemoryResource::seek(size_t to)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  if (to > size_t(mEnd - mStart))
   return false;

  mPointer = mStart + to;

  return true;
 }
 return false;
}

bool MemoryResource::seekBeginning(void)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  mPointer = mStart;
  return true;
 }
 return false;
}

bool MemoryResource::seekEnd(void)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  mPointer = mEnd - 1;
  return true;
 }
 return false;
}

bool MemoryResource::atBeginning(void) const
{
 return (mPointer == mStart);
}

bool MemoryResource::atEnd(void) const
{
 return (mPointer >= mEnd - 1);
}

size_t MemoryResource::at(void) const
{
 return (mPointer - mStart);
}

bool MemoryResource::write(const void* src, size_t src_size)
{
 
 if (mStatus != Enums::ResourceStatus_Opened)
 {
  return false;
 }

 if (mAccess != Enums::ResourceAccess_ReadAndWrite)
 {
  return false;
 }
 size_t current_size = (mEnd - mStart);
 char* pointer_willbe = mPointer + src_size;
 
 if (pointer_willbe > mStart + current_size)
 {
  mStatus = Enums::ResourceStatus_Maintenance;
  
  size_t new_buffer_size = (current_size * 2) + 1;

  char* new_buffer = (char*) NXOGRE_ALLOCATE(ResourceAllocator, new_buffer_size);
  if (mStart)
   NxOgreCopy(new_buffer, mStart, current_size);

  size_t pointer_pos = mPointer - mStart;
  NXOGRE_DEALLOCATE(ResourceAllocator, mStart);
  
  mStart = new_buffer;
  mEnd = mStart + new_buffer_size;
  mPointer = mStart + pointer_pos;
  
  mStatus = Enums::ResourceStatus_Opened;
 }
  
 NxOgreCopy(mPointer, src, src_size);
 mPointer += src_size;
  
 return true;
}

bool MemoryResource::writeNull(void)
{
 return write(&NULL_BYTE, sizeof(char));
}

bool MemoryResource::writeBool(bool bool_value)
{
 return write(&bool_value, sizeof(bool));
}

bool MemoryResource::writeBool(bool* bool_array, size_t length)
{
 return write(&bool_array, sizeof(bool) * length);
}

bool MemoryResource::writeUChar(unsigned char char_value)
{
 return write(&char_value, sizeof(unsigned char));
}

bool MemoryResource::writeUChar(unsigned char* char_array, size_t length)
{
 return write(&char_array, sizeof(unsigned char) * length);
}

bool MemoryResource::writeChar(char char_value)
{
 return write(&char_value, sizeof(char));
}

bool MemoryResource::writeChar(char* char_array, size_t length)
{
 return write(char_array, sizeof(char) * length);
}

bool MemoryResource::writeUShort(unsigned short u_short_value)
{
 return write(&u_short_value, sizeof(unsigned short));
}

bool MemoryResource::writeUShort(unsigned short* u_short_array, size_t length)
{
 return write(u_short_array, sizeof(unsigned short) * length);
}

bool MemoryResource::writeShort(short short_value)
{
 return write(&short_value, sizeof(short));
}

bool MemoryResource::writeShort(short* short_array, size_t length)
{
 return write(short_array, sizeof(short_array) * length);
}

bool MemoryResource::writeUInt(unsigned int u_int_value)
{
 return write(&u_int_value, sizeof(unsigned int));
}

bool MemoryResource::writeUInt(unsigned int* u_int_array, size_t length)
{
 return write(u_int_array, sizeof(unsigned int) * length);
}

bool MemoryResource::writeInt(int int_value)
{
 return write(&int_value, sizeof(int));
}

bool MemoryResource::writeInt(int* int_array, size_t length)
{
 return write(int_array, sizeof(int) * length);
}

bool MemoryResource::writeFloat(float float_value)
{
 return write(&float_value, sizeof(float));
}

bool MemoryResource::writeFloat(float* float_array, size_t length)
{
 return write(float_array, sizeof(float) * length);
}

bool MemoryResource::writeDouble(double double_value)
{
 return write(&double_value, sizeof(double));
}

bool MemoryResource::writeDouble(double* double_array, size_t length)
{
 return write(double_array, sizeof(double) * length);
}

bool MemoryResource::writeReal(NxOgreRealType real_value)
{
 return write(&real_value, sizeof(NxOgreRealType));
}

bool MemoryResource::writeReal(NxOgreRealType* real_array, size_t length)
{
 return write(real_array, sizeof(NxOgreRealType) * length);
}

bool MemoryResource::writeLong(long long_value)
{
 return write(&long_value, sizeof(long));
}

bool MemoryResource::writeLong(long* long_array, size_t length)
{
 return write(long_array, sizeof(long) * length);
}

bool MemoryResource::writeString(const String& str)
{
 write(str.data(), str.length());
 return write(&NULL_BYTE, sizeof(char));
}

bool MemoryResource::readBool(void)
{
 bool t;
 NxOgreCopy(&t, mPointer, sizeof(bool));
 mPointer += sizeof(bool);
 return t;
}

void MemoryResource::readBoolArray(bool* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

unsigned char MemoryResource::readUChar(void)
{
 unsigned char t;
 NxOgreCopy(&t, mPointer, sizeof(unsigned char));
 mPointer += sizeof(unsigned char);
 return t;
}

void MemoryResource::readUCharArray(unsigned char* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

char MemoryResource::readChar(void)
{
 char t;
 NxOgreCopy(&t, mPointer, sizeof(char));
 mPointer += sizeof(char);
 return t;
}

void MemoryResource::readCharArray(char* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

unsigned short MemoryResource::readUShort(void)
{
 unsigned short t;
 NxOgreCopy(&t, mPointer, sizeof(unsigned short));
 mPointer += sizeof(unsigned short);
 return t;
}

void MemoryResource::readUShortArray(unsigned short* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

short MemoryResource::readShort(void)
{
 short t;
 NxOgreCopy(&t, mPointer, sizeof(short));
 mPointer += sizeof(short);
 return t;
}

void MemoryResource::readShortArray(short* t, size_t length)
{
NxOgreCopy(t, mPointer, length);
mPointer += length;
}

unsigned int MemoryResource::readUInt(void)
{
 unsigned int t;
 NxOgreCopy(&t, mPointer, sizeof(unsigned int));
 mPointer += sizeof(unsigned int);
 return t;
}

void MemoryResource::readUIntArray(unsigned int* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

int MemoryResource::readInt(void)
{
 int t;
 NxOgreCopy(&t, mPointer, sizeof(int));
 mPointer += sizeof(int);
 return t;
}

void MemoryResource::readIntArray(int* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

float MemoryResource::readFloat(void)
{
 float t;
 NxOgreCopy(&t, mPointer, sizeof(float));
 mPointer += sizeof(float);
 return t;
}

void MemoryResource::readFloatArray(float* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

double MemoryResource::readDouble(void)
{
 double t;
 NxOgreCopy(&t, mPointer, sizeof(double));
 mPointer += sizeof(double);
 return t;
}

void MemoryResource::readDouble(double* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

Real MemoryResource::readReal(void)
{
 NxOgreRealType t;
 NxOgreCopy(&t, mPointer, sizeof(NxOgreRealType));
 mPointer += sizeof(NxOgreRealType);
 return t;
}

void MemoryResource::readRealArray(NxOgreRealType* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

long MemoryResource::readLong(void)
{
 long t;
 NxOgreCopy(&t, mPointer, sizeof(long));
 mPointer += sizeof(long);
 return t;
}

void MemoryResource::readLongArray(long* t, size_t length)
{
 NxOgreCopy(t, mPointer, length);
 mPointer += length;
}

void MemoryResource::flush()
{
 // No code required.
}

char* MemoryResource::getStart() const
{
 return mStart;
}

                                                                                       

} // namespace NxOgre

                                                                                       
