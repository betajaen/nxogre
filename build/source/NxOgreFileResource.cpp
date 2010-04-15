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

#ifdef _DEBUG
#include <iostream>
#endif
                                                                                       

namespace NxOgre
{

                                                                                       


FileResource::FileResource(const Path& path, ResourceProtocol* protocol, Enums::ResourceAccess ra)
: Resource(path, protocol, ra), mWroteNbBytes(0)
{
}

FileResource::~FileResource(void)
{
 if (mStatus == Enums::ResourceStatus_Opened)
  close();

}

Enums::ResourceAccess FileResource::getAccess(void) const
{
 return mAccess;
}

Enums::ResourceStatus FileResource::getStatus(void) const
{
 return mStatus;
}

Enums::ResourceDirectionality FileResource::getDirectionality(void) const
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
 
 std::string os_path = mPath.getOSString();

 if (mAccess == Enums::ResourceAccess_ReadOnly)
 {
  #ifdef NXOGRE_DEBUG_RESOURCES
   std::cout << "[+] Opening File Resource -> " << mPath.getString() << " as read" << std::endl;
  #endif
  mFile = fopen(os_path.c_str(), "rb");
 }
 else if (mAccess == Enums::ResourceAccess_WriteOnly)
 {
  #ifdef NXOGRE_DEBUG_RESOURCES
   std::cout << "[+] Opening File Resource -> " << mPath.getString() << " as write" << std::endl;
  #endif
  mFile = fopen(os_path.c_str(), "wb");
 }
 else if (mAccess == Enums::ResourceAccess_AppendOnly)
 {
  #ifdef NXOGRE_DEBUG_RESOURCES
   std::cout << "[+] Opening File Resource -> " << mPath.getString() << " as append" << std::endl;
  #endif
  mFile = fopen(os_path.c_str(), "ab");
 }
 else if (mAccess == Enums::ResourceAccess_ReadAndWrite)
 {
  #ifdef NXOGRE_DEBUG_RESOURCES
   std::cout << "[+] Opening File Resource -> " << mPath.getString() << " as read/write" <<  std::endl;
  #endif
  mFile = fopen(os_path.c_str(), "rb+");
 }
 
 if (mFile == 0)
 {
  NxOgre_ThrowException(PathInvalidException, Reason::Exceptionise(os_path, mStatus), Classes::_FileResource);
  return;
 }
 
 mStatus = Enums::ResourceStatus_Opened;
 mDirectionality = Enums::ResourceDirectionality_Omidirectional;
 mNbWriteOperations = 0;
 mNbReadOperations = 0;
 
}

void FileResource::close(void)
{
 mStatus = Enums::ResourceStatus_Closing;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 if (mFile)
  fclose(mFile);
 mStatus = Enums::ResourceStatus_Closed;

#ifdef NXOGRE_DEBUG_RESOURCES
 std::cout << "[-] Closing File Resource -> " << mPath.getString() << " did R: " << mNbReadOperations << " W: " << mNbWriteOperations << std::endl;
#endif
 
}

size_t FileResource::getSize(void) const
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

bool FileResource::seekBeginning(void)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  rewind(mFile);
  return true;
 }
 return false;
}

bool FileResource::seekEnd(void)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  fseek(mFile, 0, SEEK_END);
  return true;
 }
 return false;
}

bool FileResource::atBeginning(void) const
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  return ftell(mFile) == 0;
 }
 return false;
}

bool FileResource::atEnd(void) const
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  return feof(mFile);
 }
 return false;
}

size_t FileResource::at(void) const
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
 mNbWriteOperations++;
 mWroteNbBytes += src_size;
 size_t w =  (fwrite(src, src_size, 1, mFile));
 return true;
}

bool FileResource::writeNull(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(char);
 return fwrite(&NULL_BYTE, sizeof(char), 1, mFile) == 1;
}

bool FileResource::writeBool(bool v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(bool);
 return fwrite(&v, sizeof(bool), 1, mFile) == 1;
}

bool FileResource::writeBool(bool* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(char) * length;
 return fwrite(&v, sizeof(char) * length, 1, mFile) == 1;
}

bool FileResource::writeUChar(unsigned char v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned char);
 return fwrite(&v, sizeof(unsigned char), 1, mFile) == 1;
}

bool FileResource::writeUChar(unsigned char* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned char) * length;
 return fwrite(&v, sizeof(unsigned char) * length, 1, mFile) == 1;
}

bool FileResource::writeChar(char v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(char);
 return fwrite(&v, sizeof(char), 1, mFile) == 1;
}

bool FileResource::writeChar(char* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned char) * length;
 return fwrite(&v, sizeof(unsigned char) * length, 1, mFile) == 1;
}

bool FileResource::writeUShort(unsigned short v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned short);
 return fwrite(&v, sizeof(unsigned short), 1, mFile) == 1;
}

bool FileResource::writeUShort(unsigned short* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned short) * length;
 return fwrite(&v, sizeof(unsigned short) * length, 1, mFile) == 1;
}

bool FileResource::writeShort(short v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(short);
 return fwrite(&v, sizeof(short), 1, mFile) == 1;
}

bool FileResource::writeShort(short* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(short) * length;
 return fwrite(&v, sizeof(short) * length, 1, mFile) == 1;
}

bool FileResource::writeUInt(unsigned int v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned int);
 return fwrite(&v, sizeof(unsigned int), 1, mFile) == 1;
}

bool FileResource::writeUInt(unsigned int* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned int) * length;
 return fwrite(&v, sizeof(unsigned int) * length, 1, mFile) == 1;
}

bool FileResource::writeInt(int v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(int);
 return fwrite(&v, sizeof(int), 1, mFile) == 1;
}

bool FileResource::writeInt(int* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(int) * length;
 return fwrite(&v, sizeof(int) * length, 1, mFile) == 1;
}

bool FileResource::writeFloat(float v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(float);
 return fwrite(&v, sizeof(float), 1, mFile) == 1;
}

bool FileResource::writeFloat(float* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(float) * length;
 return fwrite(&v, sizeof(float) * length, 1, mFile) == 1;
}

bool FileResource::writeDouble(double v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(double);
 return fwrite(&v, sizeof(double), 1, mFile) == 1;
}

bool FileResource::writeDouble(double* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(double) * length;
 return fwrite(&v, sizeof(double) * length, 1, mFile) == 1;
}

bool FileResource::writeReal(NxOgreRealType v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(NxOgreRealType);
 return fwrite(&v, sizeof(NxOgreRealType), 1, mFile) == 1;
}

bool FileResource::writeReal(NxOgreRealType* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(NxOgreRealType) * length;
 return fwrite(&v, sizeof(NxOgreRealType) * length, 1, mFile) == 1;
}

bool FileResource::writeLong(long v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(long);
 return fwrite(&v, sizeof(long), 1, mFile) == 1;
}

bool FileResource::writeLong(long* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(long) * length;
 return fwrite(&v, sizeof(long) * length, 1, mFile) == 1;
}

bool FileResource::writeString(const String& str)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes +=  str.length() + 1;
 return fwrite(str.data(), str.length(), 1, mFile);
}

bool FileResource::readBool(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 bool t=0;fread(&t, sizeof(bool), 1, mFile);
 return t;
}

void FileResource::readBoolArray(bool* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(bool) * length, 1, mFile);
}

unsigned char FileResource::readUChar(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 unsigned char t=0;fread(&t, sizeof(unsigned char), 1, mFile);
 return t;
}

void FileResource::readUCharArray(unsigned char* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(unsigned char) * length, 1, mFile);
}

char FileResource::readChar(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 char t=0;fread(&t, sizeof(char), 1, mFile);
 return t;
}

void FileResource::readCharArray(char* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(char) * length, 1, mFile);
}

unsigned short FileResource::readUShort(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 unsigned short t=0;fread(&t, sizeof(unsigned short), 1, mFile);
 return t;
}

void FileResource::readUShortArray(unsigned short* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(unsigned short) * length, 1, mFile);
}

short FileResource::readShort(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 short t=0;fread(&t, sizeof(short), 1, mFile);
 return t;
}

void FileResource::readShortArray(short* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(short) * length, 1, mFile);
}

unsigned int FileResource::readUInt(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 unsigned int t=0;fread(&t, sizeof(unsigned int), 1, mFile);
 return t;
}

void FileResource::readUIntArray(unsigned int* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(unsigned int) * length, 1, mFile);
}

int FileResource::readInt(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 int t=0;fread(&t, sizeof(int), 1, mFile);
 return t;
}

void FileResource::readIntArray(int* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(int) * length, 1, mFile);
}

float FileResource::readFloat(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 float t=0;fread(&t, sizeof(float), 1, mFile);
 return t;
}

void FileResource::readFloatArray(float* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(float) * length, 1, mFile);
}

double FileResource::readDouble(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 double t=0;fread(&t, sizeof(double), 1, mFile);
 return t;
}

void FileResource::readDoubleArray(double* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(double) * length, 1, mFile);
}

Real FileResource::readReal(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 NxOgreRealType t=0;fread(&t, sizeof(NxOgreRealType), 1, mFile);
 return t;
}

void FileResource::readRealArray(NxOgreRealType* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(NxOgreRealType) * length, 1, mFile);
}

long FileResource::readLong(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 long t=0;fread(&t, sizeof(long), 1, mFile);
 return t;
}

void FileResource::readLongArray(long* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(long) * length, 1, mFile);
}

void FileResource::flush()
{
 fflush(mFile);
}

                                                                                       

} // namespace NxOgre

                                                                                       
