/** File: NxOgreSharedStringStream.cpp
    Created on: 5-Nov-08
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
#include "NxOgreSharedStringStream.h"
#include "NxOgreFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

#define NXOGRE_STREAM_MAX_INT_DIGITS 32
#define NXOGRE_STREAM_MAX_FLOAT_DIGITS 64
#define NXOGRE_STREAM_MAX_DOUBLE_DIGITS 64

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, const char* c_str)
{
 stream.add(c_str);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, const String& string)
{
 stream.add(string.c_str());
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, const void* ptr)
{
 char buffer[NXOGRE_STREAM_MAX_INT_DIGITS];
 ::sprintf_s(buffer, NXOGRE_STREAM_MAX_INT_DIGITS, "%p", ptr);
 stream.add(buffer);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, unsigned int i)
{
 char buffer[NXOGRE_STREAM_MAX_INT_DIGITS];
 ::sprintf_s(buffer, NXOGRE_STREAM_MAX_INT_DIGITS, "%i", i);
 stream.add(buffer);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, char i)
{
 char buffer[2];
 ::sprintf_s(buffer, 2, "%c", i);
 stream.add(buffer);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, int i)
{
 char buffer[NXOGRE_STREAM_MAX_INT_DIGITS];
 ::sprintf_s(buffer, NXOGRE_STREAM_MAX_INT_DIGITS, "%i", i);
 stream.add(buffer);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, float i)
{
 char buffer[NXOGRE_STREAM_MAX_FLOAT_DIGITS];
 ::sprintf_s(buffer, NXOGRE_STREAM_MAX_FLOAT_DIGITS, "%f", i);
 stream.add(buffer);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, double i)
{
 char buffer[NXOGRE_STREAM_MAX_DOUBLE_DIGITS];
 ::sprintf_s(buffer, NXOGRE_STREAM_MAX_DOUBLE_DIGITS, "%Lf", i);
 stream.add(buffer);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, const Vec3& r)
{
 char buffer[(NXOGRE_STREAM_MAX_FLOAT_DIGITS * 3) + 2];
 ::sprintf_s(buffer, NXOGRE_STREAM_MAX_DOUBLE_DIGITS, "%f %f %f", r.x, r.y, r.z);
 stream.add(buffer);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, const Quat& r)
{
 char buffer[(NXOGRE_STREAM_MAX_FLOAT_DIGITS * 4) + 3];
 ::sprintf_s(buffer, NXOGRE_STREAM_MAX_DOUBLE_DIGITS, "%f %f %f %f", r.w, r.x, r.y, r.z);
 stream.add(buffer);
 return stream;
}

extern inline SharedStringStream&      operator<<(SharedStringStream& stream, const SharedStringStream& string)
{
 stream.add(string.get());
 return stream;
}

#undef NXOGRE_STREAM_MAX_INT_DIGITS
#undef NXOGRE_STREAM_MAX_FLOAT_DIGITS
#undef NXOGRE_STREAM_MAX_DOUBLE_DIGITS

                                                                                       

SharedStringStream::SharedStringStream(unsigned int _buffer_size)
: _Buffer(0), _References(0)
{
 // printf("SharedStringStream\n");
 _createBuffer( (_buffer_size == 0 ? 32 : _buffer_size) );
 _References = (unsigned short*) NxOgre_Allocate(sizeof(unsigned short), Classes::_SharedStringStreamReferenceCounter);
 (*_References) = 1;
}

SharedStringStream::SharedStringStream(const char* c_str)
: _Buffer(0), _References(0)
{
 add(c_str);
 _References = (unsigned short*) NxOgre_Allocate(sizeof(unsigned short), Classes::_SharedStringStreamReferenceCounter);
 (*_References) = 1;

}

SharedStringStream::SharedStringStream(const SharedStringStream& other)
: _Buffer(0)
{
 _Buffer = other._Buffer;
 _References = other._References;

 if (_References)
  ++(*_References);

}

SharedStringStream::~SharedStringStream(void)
{
 if (_References)
 {
  --(*_References);
  if ((*_References) == 0)
  {
   NxOgre_Unallocate(_References);
   NxOgre_Unallocate(_Buffer->_String);
   NxOgre_Unallocate(_Buffer);
  }
 }
}

SharedStringStream& SharedStringStream::operator=(const SharedStringStream& other)
{
 if (_References)
 {
  --(*_References);
  if (_References == 0)
  {
   NxOgre_Unallocate(_References);
   NxOgre_Unallocate(_Buffer);
  }
 }

 _Buffer = other._Buffer;
 _References = other._References;

 if (_References)
  ++(*_References);

 return *this;
}

const char* SharedStringStream::get(void) const
{
 if (_References == 0)
  return 0;

 return _Buffer->_String;
}

void SharedStringStream::add(const char* str)
{
 unsigned int str_length = Functions::getCStringLength(str);


 if (_Buffer == 0)
 {
  _createBuffer(32);
 }

 if (str == 0)
  return;

 if ( (_Buffer->_Write + str_length) > _Buffer->_End)
 {
  size_t current_size = _Buffer->_Write - _Buffer->_String;
  size_t new_size = current_size + str_length + 8;
  char* new_string = (char*) NxOgre_Reallocate(_Buffer->_String, new_size);
  _Buffer->_String = new_string;
  _Buffer->_Write = _Buffer->_String + current_size;
  _Buffer->_End   = _Buffer->_String + new_size;
 }

 Memory::copy(_Buffer->_Write, str, str_length);
 _Buffer->_Write = _Buffer->_Write + str_length;
 (*_Buffer->_Write) = 0;

// printf("String is: %s\n", _Buffer->_String);
}

SharedStringStream::operator const char*(void) const
{
 if (_References == 0)
  return 0;

 return _Buffer->_String;
}

bool SharedStringStream::isSet(void) const
{
 return (_Buffer->_String != 0 && _References != 0);
}

void SharedStringStream::_createBuffer(size_t buffer_size)
{
  _Buffer = (Buffer*) NxOgre_Allocate(sizeof(Buffer), Classes::_SharedStringStream_Buffer);
  _Buffer->_String = _Buffer->_Write = (char*) NxOgre_Allocate(buffer_size, Classes::_char);
  _Buffer->_End = _Buffer->_String + buffer_size;
  (*_Buffer->_Write) = 0;
}

bool SharedStringStream::endsWith(char c) const
{
 return (*_Buffer->_Write - 1) == c;
}

void SharedStringStream::clear()
{
 if (_Buffer)
 {
  _Buffer->_Write = _Buffer->_String;
  (*_Buffer->_Write) = 0;
 }
}

size_t SharedStringStream::length() const
{
 if (_Buffer)
  return _Buffer->_Write - _Buffer->_String;
 return 0;
}

                                                                                       

} // namespace NxOgre

                                                                                       
