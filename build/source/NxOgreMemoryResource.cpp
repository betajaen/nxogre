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
:Resource(MEMORY_PATH, protocol, Enums::ResourceAccess_ReadAndWrite), mIndex(0)
{
}

MemoryResource::~MemoryResource()
{
 if (mStatus == Enums::ResourceStatus_Opened)
  close();
}

Enums::ResourceStatus MemoryResource::getStatus() const
{
 return mStatus;
}

Enums::ResourceDirectionality MemoryResource::getDirectionality() const
{
 return mDirectionality;
}

void MemoryResource::open()
{
 if (mStatus == Enums::ResourceStatus_Opened || mStatus == Enums::ResourceStatus_Opening)
  return;
 
 mStatus = Enums::ResourceStatus_Opening;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 mAccess = Enums::ResourceAccess_ReadAndWrite;

#if NXOGRE_DEBUG_RESOURCES == 1
 std::cout << "[+] Opening Memory resource" << std::endl;
#endif
 
 mMemory.resize(4);
 mMemory.clear();
 mIndex = 0;
 
 mStatus = Enums::ResourceStatus_Opened;
 mDirectionality = Enums::ResourceDirectionality_Omidirectional;

}

void MemoryResource::close()
{
 if (mStatus != Enums::ResourceStatus_Opened)
  return;
 
 mStatus = Enums::ResourceStatus_Closing;
 mDirectionality = Enums::ResourceDirectionality_Unknown;

#if NXOGRE_DEBUG_RESOURCES == 1
 std::cout << "[-] Closing Memory resource. -> Final size is " << mMemory.size() << " bytes" << std::endl;
#endif
 
 mMemory.resize(4);
 mMemory.clear();
 mIndex = 0;
 
 mStatus = Enums::ResourceStatus_Closed;
 
}

Enums::ResourceAccess  MemoryResource::getAccess() const
{
 return mAccess;
}

size_t MemoryResource::getSize() const
{
 return mMemory.size();
}

bool MemoryResource::seek(size_t to)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  if (to > mMemory.size())
   return false;
  mIndex = to;
  return true;
 }
 return false;
}

bool MemoryResource::seekBeginning()
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  mIndex = 0;
  return true;
 }
 return false;
}

bool MemoryResource::seekEnd()
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  mIndex = mMemory.size() - 1;
  return true;
 }
 return false;
}

bool MemoryResource::atBeginning() const
{
 return mIndex == 0;
}

bool MemoryResource::atEnd() const
{
 return (mIndex >= mMemory.size() - 1);
}

size_t MemoryResource::at() const
{
 return mIndex;
}

void MemoryResource::_willFit(size_t dataSize)
{
 size_t newSize = mIndex + dataSize;
 if (newSize < mMemory.size())
  return;
 
 while (newSize < mMemory.size())
  newSize <<= 1;
 mMemory.resize(newSize);
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
 
 _willFit(src_size);
 mMemory.put_at(mIndex, src, src_size);
 mIndex += src_size;
 
}

bool MemoryResource::writeNull()
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

bool MemoryResource::readBool()
{
 bool t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(bool);
 return t;
}

void MemoryResource::readBoolArray(bool* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readBool();
}

unsigned char MemoryResource::readUChar()
{
 unsigned char t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(unsigned char);
 return t;
}

void MemoryResource::readUCharArray(unsigned char* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readUChar();
}

char MemoryResource::readChar()
{
 char t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(char);
 return t;
}

void MemoryResource::readCharArray(char* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readChar();
}

unsigned short MemoryResource::readUShort()
{
 unsigned short t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(unsigned short);
 return t;
}

void MemoryResource::readUShortArray(unsigned short* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readUShort();
}

short MemoryResource::readShort()
{
 short t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(short);
 return t;
}

void MemoryResource::readShortArray(short* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readShort();
}

unsigned int MemoryResource::readUInt()
{
 unsigned int t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(unsigned int);
 return t;
}

void MemoryResource::readUIntArray(unsigned int* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readUInt();
}

int MemoryResource::readInt()
{
 int t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(int);
 return t;
}

void MemoryResource::readIntArray(int* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readInt();
}

float MemoryResource::readFloat()
{
 float t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(float);
 return t;
}

void MemoryResource::readFloatArray(float* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readFloat();
}

double MemoryResource::readDouble()
{
 double t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(double);
 return t;
}

void MemoryResource::readDouble(double* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readDouble();
}

Real MemoryResource::readReal()
{
 NxOgreRealType t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(NxOgreRealType);
 return t;
}

void MemoryResource::readRealArray(NxOgreRealType* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readReal();
}

long MemoryResource::readLong()
{
 long t;
 mMemory.get_at(mIndex, t);
 mIndex += sizeof(long);
 return t;
}

void MemoryResource::readLongArray(long* t, size_t length)
{
 for (size_t i=0;i < length;i++)
  t[i] = readLong();
}

void MemoryResource::flush()
{
 // No code required.
}

char* MemoryResource::getStart() const
{
 return (char*) mMemory[0];
}

                                                                                       

} // namespace NxOgre

                                                                                       
