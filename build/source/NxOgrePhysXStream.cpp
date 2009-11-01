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
#include "NxOgrePhysXStream.h"
#include "NxOgreResource.h"
#include "NxOgreSharedPointer.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXStream::PhysXStream(Resource* resource) : mResource(resource)
{
}

PhysXStream::~PhysXStream(void)
{
}

NxU8 PhysXStream::readByte() const
{
 return mResource->readUChar();
}

NxU16 PhysXStream::readWord() const
{
 return mResource->readUShort();
}

NxU32 PhysXStream::readDword() const
{
 return mResource->readUInt();
}

NxF32 PhysXStream::readFloat() const
{
 return mResource->readFloat();
}

NxF64 PhysXStream::readDouble() const
{
 return mResource->readDouble();
}

void PhysXStream::readBuffer(void* buffer, NxU32 size) const
{
 return mResource->readCharArray( (char*) buffer, size);
}

NxStream& PhysXStream::storeByte(NxU8 b)
{
 mResource->writeUChar(b);
 return *this;
}

NxStream& PhysXStream::storeWord(NxU16 w)
{
 mResource->writeUShort(w);
 return *this;
}

NxStream& PhysXStream::storeDword(NxU32 d)
{
 mResource->writeUInt(d);
 return *this;
}

NxStream& PhysXStream::storeFloat(NxF32 f)
{
 mResource->writeFloat(f);
 return *this;
}

NxStream& PhysXStream::storeDouble(NxF64 f)
{
 mResource->writeDouble(f);
 return *this;
}

NxStream& PhysXStream::storeBuffer(const void* buffer, NxU32 size)
{
 mResource->write(buffer, size);
 return *this;
}

NxStream& PhysXStream::storeByte(NxI8 b)
{
 return storeByte(NxU8(b));
}

NxStream& PhysXStream::storeWord(NxI16 w)
{
 return storeWord(NxU16(w));
}

NxStream& PhysXStream::storeDword(NxI32 d)
{
 return storeDword(NxU32(d));
}

                                                                                       

} // namespace NxOgre

                                                                                       
