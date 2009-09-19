/** File: NxOgreMSWindowsFileResource.cpp
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
#include "NxOgreMSWindowsFileResource.h"
#include "NxOgreErrorStream.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MSWindowsFileResource::MSWindowsFileResource(const ArchiveResourceIdentifier& ari, Archive* archive, Enums::ResourceAccess ra)
:Resource(ari, archive), mWroteNbBytes(0)
{
 mAccess = ra;
 mStatus = Enums::ResourceStatus_Waiting;
}

MSWindowsFileResource::~MSWindowsFileResource(void)
{
}

Enums::ResourceAccess MSWindowsFileResource::getAccess(void) const
{
 return mAccess;
}

Enums::ResourceStatus MSWindowsFileResource::getStatus(void) const
{
 return mStatus;
}

Enums::ResourceDirectionality MSWindowsFileResource::getDirectionality(void) const
{
 return mDirectionality;
}

void MSWindowsFileResource::open()
{
 if (mStatus == Enums::ResourceStatus_Opened)
  close();
  
 mStatus = Enums::ResourceStatus_Opening;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 mFile = 0;
  
 SharedStringStream fullPath;
 fullPath << mArchive->getURI().getLocation();


 if (!fullPath.endsWith('/'))
  fullPath << "/" << mArchiveResourceIdentifier.getResourceName();
 else
  fullPath << mArchiveResourceIdentifier.getResourceName();
 
 switch(mAccess)
 {
  case Enums::ResourceAccess_ReadOnly:
   mFile = fopen(fullPath.get(), "rb");
  break;
  case Enums::ResourceAccess_WriteOnly:
   mFile = fopen(fullPath.get(), "wb");
  break;
  case Enums::ResourceAccess_AppendOnly:
   mFile = fopen(fullPath.get(),  "ab");
  break;
  case Enums::ResourceAccess_ReadAndWrite:
   mFile = fopen(fullPath.get(),  "rb+");
  break;
 }
  
 if (mFile == 0)
 {
  mStatus = Enums::ResourceStatus_HasError;
  SharedStringStream ss;
  ss << "File '" << fullPath.get() << "' could not be opened. -> ";
  NxOgre_ThrowError(ss.get());
  return;
 }

 mStatus = Enums::ResourceStatus_Opened;
 mDirectionality = Enums::ResourceDirectionality_Omidirectional;
 mNbWriteOperations = 0;
 mNbReadOperations = 0;
 
}

void MSWindowsFileResource::close(void)
{
 mStatus = Enums::ResourceStatus_Closing;
 mDirectionality = Enums::ResourceDirectionality_Unknown;
 if (mFile)
  fclose(mFile);
 mStatus = Enums::ResourceStatus_Closed;

 printf("MSWindowsFileResource Debug---------------------------\n"
        "ARI       : %s:%s\n"
        "Read Ops  : %i\n"
        "Write Ops : %i\n"
        "------------------------------------------------------\n",
        mArchiveResourceIdentifier.getArchive(),
        mArchiveResourceIdentifier.getResourceName(),
        mNbReadOperations,
        mNbWriteOperations);
}

size_t MSWindowsFileResource::getSize(void) const
{
 if (mStatus != Enums::ResourceStatus_Opened)
  return 0;

 long pos = ftell(mFile), size = 0;

 fseek(mFile, 0, SEEK_END);
 size = ftell(mFile);
 fseek(mFile, pos, SEEK_SET);
 return size;
}

bool MSWindowsFileResource::seek(size_t to)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  fseek(mFile, to, SEEK_SET);
  return true;
 }
 return false;
}

bool MSWindowsFileResource::seekBeginning(void)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  rewind(mFile);
  return true;
 }
 return false;
}

bool MSWindowsFileResource::seekEnd(void)
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  fseek(mFile, 0, SEEK_END);
  return true;
 }
 return false;
}

bool MSWindowsFileResource::atBeginning(void) const
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  return ftell(mFile) == 0;
 }
 return false;
}

bool MSWindowsFileResource::atEnd(void) const
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  return feof(mFile);
 }
 return false;
}

size_t MSWindowsFileResource::at(void) const
{
 if (mStatus == Enums::ResourceStatus_Opened && mDirectionality == Enums::ResourceDirectionality_Omidirectional)
 {
  return ftell(mFile);
 }
 return Constants::ResourceSizeUnknown;
}

bool MSWindowsFileResource::write(const void* src, size_t src_size)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += src_size;
 size_t w =  (fwrite(src, src_size, 1, mFile));
 return true;
}

bool MSWindowsFileResource::writeNull(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(char);
 return fwrite(&NULL_BYTE, sizeof(char), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeBool(bool v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(bool);
 return fwrite(&v, sizeof(bool), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeBool(bool* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(char) * length;
 return fwrite(&v, sizeof(char) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeUChar(unsigned char v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned char);
 return fwrite(&v, sizeof(unsigned char), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeUChar(unsigned char* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned char) * length;
 return fwrite(&v, sizeof(unsigned char) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeChar(char v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(char);
 return fwrite(&v, sizeof(char), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeChar(char* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned char) * length;
 return fwrite(&v, sizeof(unsigned char) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeUShort(unsigned short v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned short);
 return fwrite(&v, sizeof(unsigned short), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeUShort(unsigned short* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned short) * length;
 return fwrite(&v, sizeof(unsigned short) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeShort(short v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(short);
 return fwrite(&v, sizeof(short), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeShort(short* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(short) * length;
 return fwrite(&v, sizeof(short) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeUInt(unsigned int v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned int);
 return fwrite(&v, sizeof(unsigned int), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeUInt(unsigned int* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(unsigned int) * length;
 return fwrite(&v, sizeof(unsigned int) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeInt(int v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(int);
 return fwrite(&v, sizeof(int), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeInt(int* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(int) * length;
 return fwrite(&v, sizeof(int) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeFloat(float v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(float);
 return fwrite(&v, sizeof(float), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeFloat(float* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(float) * length;
 return fwrite(&v, sizeof(float) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeDouble(double v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(double);
 return fwrite(&v, sizeof(double), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeDouble(double* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(double) * length;
 return fwrite(&v, sizeof(double) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeReal(NxOgreRealType v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(NxOgreRealType);
 return fwrite(&v, sizeof(NxOgreRealType), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeReal(NxOgreRealType* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(NxOgreRealType) * length;
 return fwrite(&v, sizeof(NxOgreRealType) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::writeLong(long v)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(long);
 return fwrite(&v, sizeof(long), 1, mFile) == 1;
}

bool MSWindowsFileResource::writeLong(long* v, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbWriteOperations++;
 mWroteNbBytes += sizeof(long) * length;
 return fwrite(&v, sizeof(long) * length, 1, mFile) == 1;
}

bool MSWindowsFileResource::readBool(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 bool t=0;fread(&t, sizeof(bool), 1, mFile);
 return t;
}

void MSWindowsFileResource::readBoolArray(bool* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(bool) * length, 1, mFile);
}

unsigned char MSWindowsFileResource::readUChar(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 unsigned char t=0;fread(&t, sizeof(unsigned char), 1, mFile);
 return t;
}

void MSWindowsFileResource::readUCharArray(unsigned char* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(unsigned char) * length, 1, mFile);
}

char MSWindowsFileResource::readChar(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 char t=0;fread(&t, sizeof(char), 1, mFile);
 return t;
}

void MSWindowsFileResource::readCharArray(char* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(char) * length, 1, mFile);
}

unsigned short MSWindowsFileResource::readUShort(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 unsigned short t=0;fread(&t, sizeof(unsigned short), 1, mFile);
 return t;
}

void MSWindowsFileResource::readUShortArray(unsigned short* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(unsigned short) * length, 1, mFile);
}

short MSWindowsFileResource::readShort(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 short t=0;fread(&t, sizeof(short), 1, mFile);
 return t;
}

void MSWindowsFileResource::readShortArray(short* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(short) * length, 1, mFile);
}

unsigned int MSWindowsFileResource::readUInt(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 unsigned int t=0;fread(&t, sizeof(unsigned int), 1, mFile);
 return t;
}

void MSWindowsFileResource::readUIntArray(unsigned int* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(unsigned int) * length, 1, mFile);
}

int MSWindowsFileResource::readInt(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 int t=0;fread(&t, sizeof(int), 1, mFile);
 return t;
}

void MSWindowsFileResource::readIntArray(int* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(int) * length, 1, mFile);
}

float MSWindowsFileResource::readFloat(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 float t=0;fread(&t, sizeof(float), 1, mFile);
 return t;
}

void MSWindowsFileResource::readFloatArray(float* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(float) * length, 1, mFile);
}

double MSWindowsFileResource::readDouble(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 double t=0;fread(&t, sizeof(double), 1, mFile);
 return t;
}

void MSWindowsFileResource::readDouble(double* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(double) * length, 1, mFile);
}

Real MSWindowsFileResource::readReal(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 NxOgreRealType t=0;fread(&t, sizeof(NxOgreRealType), 1, mFile);
 return t;
}

void MSWindowsFileResource::readRealArray(NxOgreRealType* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(NxOgreRealType) * length, 1, mFile);
}

long MSWindowsFileResource::readLong(void)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 long t=0;fread(&t, sizeof(long), 1, mFile);
 return t;
}

void MSWindowsFileResource::readLongArray(long* t, size_t length)
{
 // printf(__FUNCTION__ "at %i\n", at());
 mNbReadOperations++;
 fread(t, sizeof(long) * length, 1, mFile);
}

void MSWindowsFileResource::flush()
{
 fflush(mFile);
}
                                                                                       

} // namespace NxOgre

                                                                                       
