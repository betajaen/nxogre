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
#include "NxOgreFileResource.h"
#include "NxOgreErrorStream.h"
#include "NxOgreReason.h"

                                                                                       

#include <iostream>
#include <string>

                                                                                       

#include "stdio.h"

                                                                                       

namespace NxOgre
{

                                                                                       

FileResource::FileResource(const Path& path, ResourceProtocol* protocol, Enums::ResourceAccess ra)
: Resource(path, protocol, ra)
{
}

FileResource::~FileResource()
{
 if (mStatus == Enums::ResourceStatus_Opened)
  close();
}

Enums::ResourceAccess FileResource::getAccess() const
{
 return mAccess;
}

Enums::ResourceStatus FileResource::getStatus() const
{
 return mStatus;
}

Enums::ResourceDirectionality FileResource::getDirectionality() const
{
 return mDirectionality;
}

void FileResource::open()
{

 if (mStatus == Enums::ResourceStatus_Opened)
  close();

 mStatus = Enums::ResourceStatus_Opening;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 mFile = 0;
 mNbReadBytes = 0;
 mNbWroteBytes = 0;

 std::string os_path = mPath.getOSString();

 if (mAccess == Enums::ResourceAccess_ReadOnly)
 {
  NxOgre_DebugPrint_Resources("Opening '" << mPath.getString() << "' as read.");
  mFile = fopen(os_path.c_str(), "rb");
 }
 else if (mAccess == Enums::ResourceAccess_WriteOnly)
 {
  NxOgre_DebugPrint_Resources("Opening '" << mPath.getString() << "' as write.");
  mFile = fopen(os_path.c_str(), "wb");
 }
 else if (mAccess == Enums::ResourceAccess_AppendOnly)
 {
  NxOgre_DebugPrint_Resources("Opening '" << mPath.getString() << "' as append.");
  mFile = fopen(os_path.c_str(), "ab");
 }
 else if (mAccess == Enums::ResourceAccess_ReadAndWrite)
 {
  NxOgre_DebugPrint_Resources("Opening '" << mPath.getString() << "' as read/write.");
  mFile = fopen(os_path.c_str(), "wb+");
 }

 if (mFile == 0)
 {
  NxOgre_ThrowException(PathInvalidException, Reason::Exceptionise(os_path, mStatus), Classes::_FileResource);
  return;
 }

 mStatus = Enums::ResourceStatus_Opened;
 mDirectionality = Enums::ResourceDirectionality_Omidirectional;

}

void FileResource::close()
{
 mStatus = Enums::ResourceStatus_Closing;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 
 NxOgre_DebugPrint_Resources("Closing '" << mPath.getString() << "', Read " << mNbReadBytes << "b and Wrote " << mNbWroteBytes << "b. ");
 
 if (mFile)
  fclose(mFile);
 mStatus = Enums::ResourceStatus_Closed;
 
}

size_t FileResource::getSize() const
{
 if (mStatus != Enums::ResourceStatus_Opened)
  return 0;

 long pos = ftell(mFile), size = 0;

 fseek(mFile, 0, SEEK_END);
 size = ftell(mFile);
 fseek(mFile, pos, SEEK_SET);
 return size;
}

bool FileResource::seek(size_t to)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  fseek(mFile, to, SEEK_SET);
  return true;
 }
 return false;
}

bool FileResource::seekBeginning()
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  rewind(mFile);
  return true;
 }
 return false;
}

bool FileResource::seekEnd()
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  fseek(mFile, 0, SEEK_END);
  return true;
 }
 return false;
}

bool FileResource::atBeginning() const
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  return ftell(mFile) == 0;
 }
 return false;
}

bool FileResource::atEnd() const
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  return feof(mFile);
 }
 return false;
}

size_t FileResource::at() const
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  return ftell(mFile);
 }
 return Constants::ResourceSizeUnknown;
}

bool FileResource::write(const void* src, size_t src_size)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWroteBytes += src_size;
 fwrite(src, src_size, 1, mFile);
 return true;
}

bool FileResource::writeNull()
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(char);
 return fwrite(&NULL_BYTE, sizeof(char), 1, mFile) == 1;
}

bool FileResource::writeBool(bool v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(bool);
 return fwrite(&v, sizeof(bool), 1, mFile) == 1;
}

bool FileResource::writeBool(bool* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(bool) * length;
 return fwrite(&v, sizeof(bool) * length, 1, mFile) == 1;
}

bool FileResource::writeUChar(unsigned char v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(unsigned char);
 return fwrite(&v, sizeof(unsigned char), 1, mFile) == 1;
}

bool FileResource::writeUChar(unsigned char* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(unsigned char) * length;
 return fwrite(&v, sizeof(unsigned char) * length, 1, mFile) == 1;
}

bool FileResource::writeChar(char v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(char);
 return fwrite(&v, sizeof(char), 1, mFile) == 1;
}

bool FileResource::writeChar(char* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(unsigned char) * length;
 return fwrite(&v, sizeof(unsigned char) * length, 1, mFile) == 1;
}

bool FileResource::writeUShort(unsigned short v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(unsigned short);
 return fwrite(&v, sizeof(unsigned short), 1, mFile) == 1;
}

bool FileResource::writeUShort(unsigned short* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(unsigned short) * length;
 return fwrite(&v, sizeof(unsigned short) * length, 1, mFile) == 1;
}

bool FileResource::writeShort(short v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(short);
 return fwrite(&v, sizeof(short), 1, mFile) == 1;
}

bool FileResource::writeShort(short* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(short) * length;
 return fwrite(&v, sizeof(short) * length, 1, mFile) == 1;
}

bool FileResource::writeUInt(unsigned int v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(unsigned int);
 return fwrite(&v, sizeof(unsigned int), 1, mFile) == 1;
}

bool FileResource::writeUInt(unsigned int* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(unsigned int) * length;
 return fwrite(&v, sizeof(unsigned int) * length, 1, mFile) == 1;
}

bool FileResource::writeInt(int v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(int);
 return fwrite(&v, sizeof(int), 1, mFile) == 1;
}

bool FileResource::writeInt(int* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(int) * length;
 return fwrite(&v, sizeof(int) * length, 1, mFile) == 1;
}

bool FileResource::writeFloat(float v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(float);
 return fwrite(&v, sizeof(float), 1, mFile) == 1;
}

bool FileResource::writeFloat(float* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(float) * length;
 return fwrite(&v, sizeof(float) * length, 1, mFile) == 1;
}

bool FileResource::writeDouble(double v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(double);
 return fwrite(&v, sizeof(double), 1, mFile) == 1;
}

bool FileResource::writeDouble(double* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(double) * length;
 return fwrite(&v, sizeof(double) * length, 1, mFile) == 1;
}

bool FileResource::writeReal(NxOgreRealType v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(NxOgreRealType);
 return fwrite(&v, sizeof(NxOgreRealType), 1, mFile) == 1;
}

bool FileResource::writeReal(NxOgreRealType* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(NxOgreRealType) * length;
 return fwrite(&v, sizeof(NxOgreRealType) * length, 1, mFile) == 1;
}

bool FileResource::writeLong(long v)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(long);
 return fwrite(&v, sizeof(long), 1, mFile) == 1;
}

bool FileResource::writeLong(long* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());

 mNbWroteBytes += sizeof(long) * length;
 return fwrite(&v, sizeof(long) * length, 1, mFile) == 1;
}

bool FileResource::writeString(const String& str)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWroteBytes += str.length();
 return fwrite(str.data(), str.length(), 1, mFile);
}

bool FileResource::readBool()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(bool);
 bool t=0;fread(&t, sizeof(bool), 1, mFile);
 return t;
}

void FileResource::readBoolArray(bool* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(bool) * length;
 fread(t, sizeof(bool) * length, 1, mFile);
}

unsigned char FileResource::readUChar()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(unsigned char);
 unsigned char t=0;fread(&t, sizeof(unsigned char), 1, mFile);
 return t;
}

void FileResource::readUCharArray(unsigned char* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(unsigned char) * length;
 fread(t, sizeof(unsigned char) * length, 1, mFile);
}

char FileResource::readChar()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(char);
 char t=0;fread(&t, sizeof(char), 1, mFile);
 return t;
}

void FileResource::readCharArray(char* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(char) * length;
 fread(t, sizeof(char) * length, 1, mFile);
}

unsigned short FileResource::readUShort()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(unsigned short);
 unsigned short t=0;fread(&t, sizeof(unsigned short), 1, mFile);
 return t;
}

void FileResource::readUShortArray(unsigned short* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(unsigned short) * length;
 fread(t, sizeof(unsigned short) * length, 1, mFile);
}

short FileResource::readShort()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(short);
 short t=0;fread(&t, sizeof(short), 1, mFile);
 return t;
}

void FileResource::readShortArray(short* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(short) * length;
 fread(t, sizeof(short) * length, 1, mFile);
}

unsigned int FileResource::readUInt()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(unsigned int);
 unsigned int t=0;fread(&t, sizeof(unsigned int), 1, mFile);
 return t;
}

void FileResource::readUIntArray(unsigned int* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(unsigned int) * length;
 fread(t, sizeof(unsigned int) * length, 1, mFile);
}

int FileResource::readInt()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(int);
 int t=0;fread(&t, sizeof(int), 1, mFile);
 return t;
}

void FileResource::readIntArray(int* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(int) * length;
 fread(t, sizeof(int) * length, 1, mFile);
}

float FileResource::readFloat()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(float);
 float t=0;fread(&t, sizeof(float), 1, mFile);
 return t;
}

void FileResource::readFloatArray(float* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(float) * length;
 fread(t, sizeof(float) * length, 1, mFile);
}

double FileResource::readDouble()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(double);
 double t=0;fread(&t, sizeof(double), 1, mFile);
 return t;
}

void FileResource::readDoubleArray(double* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(double) *length;
 fread(t, sizeof(double) * length, 1, mFile);
}

Real FileResource::readReal()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(NxOgreRealType);
 NxOgreRealType t=0;fread(&t, sizeof(NxOgreRealType), 1, mFile);
 return t;
}

void FileResource::readRealArray(NxOgreRealType* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(NxOgreRealType) * length;
 fread(t, sizeof(NxOgreRealType) * length, 1, mFile);
}

long FileResource::readLong()
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(long);
 long t=0;fread(&t, sizeof(long), 1, mFile);
 return t;
}

void FileResource::readLongArray(long* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadBytes+=sizeof(long) * length;
 fread(t, sizeof(long) * length, 1, mFile);
}

void FileResource::flush()
{
 fflush(mFile);
}

                                                                                       

} // namespace NxOgre

                                                                                       
