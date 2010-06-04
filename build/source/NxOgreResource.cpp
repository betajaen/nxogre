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
#include "NxOgreResource.h"

                                                                                       

const char ::NxOgre::Resource::NULL_BYTE = 0;

                                                                                       

namespace NxOgre
{

                                                                                       
Resource::Resource(const Path& path, ResourceProtocol* protocol, Enums::ResourceAccess access)
: mPath(path),
  mProtocol(protocol), 
  mStatus(Enums::ResourceStatus_Closed),
  mDirectionality(Enums::ResourceDirectionality_Unknown),
  mAccess(access),
  mNbReadBytes(0),
  mNbWroteBytes(0)
{
}

Resource::~Resource()
{
}

ResourceProtocol* Resource::getProtocol()
{
 return mProtocol;
}

Path Resource::getPath() const
{
 return mPath;
}

bool Resource::hasTouched() const
{
 return mNbWroteBytes != 0;
}

unsigned int Resource::getNbBytesRead() const
{
 return mNbReadBytes;
}

unsigned int Resource::getNbBytesWrote() const
{
 return mNbWroteBytes;
}

Enums::ResourceStatus Resource::getStatus() const
{
 return Enums::ResourceStatus_Unknown;
}

Enums::ResourceDirectionality Resource::getDirectionality() const
{
 return Enums::ResourceDirectionality_Unknown;
}

Enums::ResourceAccess Resource::getAccess() const
{
 return Enums::ResourceAccess_NoAccess;
}

size_t Resource::getSize() const
{
 return 0;
}

bool Resource::seek(size_t)
{
 return false;
}

bool Resource::seekBeginning()
{
 return false;
}

bool Resource::seekEnd()
{
 return false;
}

bool Resource::atBeginning() const
{
 return false;
}

bool Resource::atEnd() const
{
 return false;
}

size_t Resource::at() const
{
 return 0;
}

bool Resource::write(const void* src, size_t src_size)
{
 return false;
}

bool Resource::writeNull()
{
 return false;
}

bool Resource::writeBool(bool)
{
 return false;
}

bool Resource::writeBool(bool*, size_t length)
{
 return false;
}

bool Resource::writeUChar(unsigned char)
{
 return false;
}

bool Resource::writeUChar(unsigned char*, size_t length)
{
 return false;
}

bool Resource::writeChar(char)
{
 return false;
}

bool Resource::writeChar(char*, size_t length)
{
 return false;
}

bool Resource::writeUShort(unsigned short)
{
 return false;
}

bool Resource::writeUShort(unsigned short*, size_t length)
{
 return false;
}

bool Resource::writeShort(short)
{
 return false;
}

bool Resource::writeShort(short*, size_t length)
{
 return false;
}

bool Resource::writeUInt(unsigned int)
{
 return false;
}

bool Resource::writeUInt(unsigned int*, size_t length)
{
 return false;
}

bool Resource::writeInt(int)
{
 return false;
}

bool Resource::writeInt(int*, size_t length)
{
 return false;
}

bool Resource::writeFloat(float)
{
 return false;
}

bool Resource::writeFloat(float*, size_t length)
{
 return false;
}

bool Resource::writeDouble(double)
{
 return false;
}

bool Resource::writeDouble(double*, size_t length)
{
 return false;
}

bool Resource::writeReal(NxOgreRealType)
{
 return false;
}

bool Resource::writeReal(NxOgreRealType*, size_t length)
{
 return false;
}

bool Resource::writeLong(long)
{
 return false;
}

bool Resource::writeLong(long*, size_t length)
{
 return false;
}

bool Resource::writeString(const String&)
{
 return false;
}

bool Resource::readBool()
{
 return false;
}

void Resource::readBoolArray(bool*, size_t length)
{
}

unsigned char Resource::readUChar()
{
 return false;
}

void Resource::readUCharArray(unsigned char*, size_t length)
{
}

char Resource::readChar()
{
 return false;
}

void Resource::readCharArray(char*, size_t length)
{
}

unsigned short Resource::readUShort()
{
 return false;
}

void Resource::readUShortArray(unsigned short*, size_t length)
{
}

short Resource::readShort()
{
 return false;
}

void Resource::readShortArray(short*, size_t length)
{
}

unsigned int Resource::readUInt()
{
 return false;
}

void Resource::readUIntArray(unsigned int*, size_t length)
{
}

int Resource::readInt()
{
 return false;
}

void Resource::readIntArray(int*, size_t length)
{
}

float Resource::readFloat()
{
 return false;
}

void Resource::readFloatArray(float*, size_t length)
{
}

double Resource::readDouble()
{
 return false;
}

void Resource::readDouble(double*, size_t length)
{
}

Real Resource::readReal()
{
 return false;
}

void Resource::readRealArray(NxOgreRealType*, size_t length)
{
}

long Resource::readLong()
{
 return false;
}

void Resource::readLongArray(long*, size_t length)
{
}

void Resource::flush()
{
}

String Resource::to_s() const
{
 return NxOgre::to_s((void*)this, String("'" + mPath.getString() + "'") );
}

                                                                                       

} // namespace NxOgre

                                                                                       
