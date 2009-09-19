/** File: NxOgreMemoryResource.cpp
    Created on: 17-Nov-08
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMemoryResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MemoryResource::MemoryResource(const ArchiveResourceIdentifier& ari, Archive* archive)
:Resource(ari, archive), mStart(0), mEnd(0), mPointer(0)
{
}

MemoryResource::~MemoryResource(void)
{
 if (mStart)
  NxOgre_Unallocate(mStart);
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
 if (mStatus == Enums::ResourceStatus_Opened)
  close();
 
 mStatus = Enums::ResourceStatus_Opening;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 mAccess = Enums::ResourceAccess_ReadAndWrite;

 mStart = (char*) NxOgre_Allocate(16, Classes::_char);
 mEnd = mStart + 16;
 mPointer = mStart;
 mStatus = Enums::ResourceStatus_Opened;
}

void MemoryResource::close(void)
{
 mStatus = Enums::ResourceStatus_Closing;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 if (mStart)
  NxOgre_Unallocate(mStart);
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
  return false;
 if (mStatus != mAccess != Enums::ResourceAccess_ReadOnly)
  return false;
 
 size_t current_size = (mEnd - mStart);
 char* pointer_willbe = mPointer + src_size;
 
 if (pointer_willbe > mStart + current_size)
 {
  mStatus = Enums::ResourceStatus_Maintenance;
  
  size_t new_buffer_size = (current_size * 2) + 1;
  char* new_buffer = (char*) NxOgre_Allocate(new_buffer_size, Classes::_char);
  if (mStart)
   Memory::copy(new_buffer, mStart, current_size);
  NxOgre_Unallocate(mStart);
  
  size_t pointer_pos = mPointer - mStart;
  mStart = new_buffer;
  mEnd = mStart + new_buffer_size;
  mPointer = mStart + pointer_pos;
  
  mStatus = Enums::ResourceStatus_Maintenance;
 }
  
 Memory::copy(mPointer, src, src_size);
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

bool MemoryResource::readBool(void)
{
 bool t;
 Memory::copy(&t, mPointer, sizeof(bool));
 mPointer += sizeof(bool);
 return t;
}

void MemoryResource::readBoolArray(bool* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

unsigned char MemoryResource::readUChar(void)
{
 unsigned char t;
 Memory::copy(&t, mPointer, sizeof(unsigned char));
 mPointer += sizeof(unsigned char);
 return t;
}

void MemoryResource::readUCharArray(unsigned char* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

char MemoryResource::readChar(void)
{
 char t;
 Memory::copy(&t, mPointer, sizeof(char));
 mPointer += sizeof(char);
 return t;
}

void MemoryResource::readCharArray(char* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

unsigned short MemoryResource::readUShort(void)
{
 unsigned short t;
 Memory::copy(&t, mPointer, sizeof(unsigned short));
 mPointer += sizeof(unsigned short);
 return t;
}

void MemoryResource::readUShortArray(unsigned short* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

short MemoryResource::readShort(void)
{
 short t;
 Memory::copy(&t, mPointer, sizeof(short));
 mPointer += sizeof(short);
 return t;
}

void MemoryResource::readShortArray(short* t, size_t length)
{
Memory::copy(t, mPointer, length);
mPointer += length;
}

unsigned int MemoryResource::readUInt(void)
{
 unsigned int t;
 Memory::copy(&t, mPointer, sizeof(unsigned int));
 mPointer += sizeof(unsigned int);
 return t;
}

void MemoryResource::readUIntArray(unsigned int* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

int MemoryResource::readInt(void)
{
 int t;
 Memory::copy(&t, mPointer, sizeof(int));
 mPointer += sizeof(int);
 return t;
}

void MemoryResource::readIntArray(int* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

float MemoryResource::readFloat(void)
{
 float t;
 Memory::copy(&t, mPointer, sizeof(float));
 mPointer += sizeof(float);
 return t;
}

void MemoryResource::readFloatArray(float* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

double MemoryResource::readDouble(void)
{
 double t;
 Memory::copy(&t, mPointer, sizeof(double));
 mPointer += sizeof(double);
 return t;
}

void MemoryResource::readDouble(double* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

Real MemoryResource::readReal(void)
{
 NxOgreRealType t;
 Memory::copy(&t, mPointer, sizeof(NxOgreRealType));
 mPointer += sizeof(NxOgreRealType);
 return t;
}

void MemoryResource::readRealArray(NxOgreRealType* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

long MemoryResource::readLong(void)
{
 long t;
 Memory::copy(&t, mPointer, sizeof(long));
 mPointer += sizeof(long);
 return t;
}

void MemoryResource::readLongArray(long* t, size_t length)
{
 Memory::copy(t, mPointer, length);
 mPointer += length;
}

void MemoryResource::flush()
{
 // No code required.
}


                                                                                       

} // namespace NxOgre

                                                                                       
