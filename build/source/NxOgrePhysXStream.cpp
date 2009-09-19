/** File: NxOgrePhysXStream.cpp
    Created on: 28-Feb-09
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
#include "NxOgrePhysXStream.h"
#include "NxOgreResource.h"
#include "NxOgreSharedPointer.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

#if 0
PhysXStream::PhysXStream(Resource* resource) : mResource(resource)
{
  fp = fopen("physxstream.bin", "wb");
}

PhysXStream::~PhysXStream()
{
	if(fp)
   fclose(fp);
}

// Loading API
NxU8 PhysXStream::readByte() const
{
	NxU8 b;
	size_t r = fread(&b, sizeof(NxU8), 1, fp);
	NX_ASSERT(r);
	return b;
}

NxU16 PhysXStream::readWord() const
{
	NxU16 w;
	size_t r = fread(&w, sizeof(NxU16), 1, fp);
	NX_ASSERT(r);
	return w;
}

NxU32 PhysXStream::readDword() const
{
	NxU32 d;
	size_t r = fread(&d, sizeof(NxU32), 1, fp);
	NX_ASSERT(r);
	return d;
}

float PhysXStream::readFloat() const
{
	NxReal f;
	size_t r = fread(&f, sizeof(NxReal), 1, fp);
	NX_ASSERT(r);
	return f;
}

double PhysXStream::readDouble() const
{
	NxF64 f;
	size_t r = fread(&f, sizeof(NxF64), 1, fp);
	NX_ASSERT(r);
	return f;
}

void PhysXStream::readBuffer(void* buffer, NxU32 size)	const
{
	size_t w = fread(buffer, size, 1, fp);
	NX_ASSERT(w);
}

// Saving API
NxStream& PhysXStream::storeByte(NxU8 b)
{
	size_t w = fwrite(&b, sizeof(NxU8), 1, fp);
	NX_ASSERT(w);
	return *this;
}

NxStream& PhysXStream::storeWord(NxU16 w)
{
	size_t ww = fwrite(&w, sizeof(NxU16), 1, fp);
	NX_ASSERT(ww);
	return *this;
}

NxStream& PhysXStream::storeDword(NxU32 d)
{
	size_t w = fwrite(&d, sizeof(NxU32), 1, fp);
	NX_ASSERT(w);
	return *this;
}

NxStream& PhysXStream::storeFloat(NxReal f)
{
	size_t w = fwrite(&f, sizeof(NxReal), 1, fp);
	NX_ASSERT(w);
	return *this;
}

NxStream& PhysXStream::storeDouble(NxF64 f)
{
	size_t w = fwrite(&f, sizeof(NxF64), 1, fp);
	NX_ASSERT(w);
	return *this;
}

NxStream& PhysXStream::storeBuffer(const void* buffer, NxU32 size)
{
	size_t w = fwrite(buffer, size, 1, fp);
	NX_ASSERT(w);
	return *this;
}



#else

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

#endif
                                                                                       

} // namespace NxOgre

                                                                                       
