/** File: NxOgreMemoryResource.h
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

#ifndef NXOGRE_MEMORYRESOURCE_H
#define NXOGRE_MEMORYRESOURCE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResource.h"
#include "NxOgrePointerClass.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \internal Do not use directly. Use Resource* and ResourceSystem::open
*/
class NxOgrePublicClass MemoryResource : public PointerClass<Classes::_MemoryResource>, public Resource
{
 
 friend class MemoryArchive;
 
 public:
  
  /** \brief
  */
                                             MemoryResource(const ArchiveResourceIdentifier&, Archive*);
  
  /** \brief
  */
                                            ~MemoryResource(void);
  
  /** \brief What is the resources status?
  */
                       Enums::ResourceStatus getStatus(void) const;
  
  /** \brief Get the directionality of the resource
  */
                       Enums::ResourceDirectionality getDirectionality(void) const;
  
  /** \brief Get the type of access of the resource
  */
                        Enums::ResourceAccess         getAccess(void) const;

  /** \brief Get the size (in bytes) of the resource, or Constants::ResourceSizeUnknown.
      \note  If the Directionality is sucessional or the status is anything but open then
             the file size will be Constants::ResourceSizeUnknown.
  */
                       size_t                getSize(void) const;
  
  /** \brief Go somewhere into the resource from, this is relative to the ReadWrite pointer and not an absolute.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
                       bool                  seek(size_t);
  
  /** \brief Go to the beginning of the resource.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
                       bool                  seekBeginning(void);
  
  /** \brief Go to the end of the resource.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
                       bool                  seekEnd(void);
  
  /** \brief Is the ReadWrite pointer at the end of Resource?
  */
                       bool                  atBeginning(void) const;
  
  /** \brief Is the ReadWrite pointer at the end of Resource, just like a standard "EOF" function.
  */
                       bool                  atEnd(void) const;
  
  /** \brief Where the ReadWrite is from the beginning of the resource.
      \note  Constants::ResourceSizeUnknown will be returned if it is an unknown.
  */
                       size_t                at(void) const;
  
  /** \brief Write something to the buffer, with a size otherwise fail.
  */
                       bool                  write(const void* src, size_t src_size);
  
  /** \brief Write a single null (0x00) to the resource otherwise fail.
  */
                       bool                  writeNull(void);
  
  /** \brief Write a bool otherwise fail.
  */
                       bool                  writeBool(bool);
  
  /** \brief Write a bool* array otherwise fail.
  */
                       bool                  writeBool(bool*, size_t length);
  
  /** \brief Write a single unsigned char otherwise fail.
  */
                       bool                  writeUChar(unsigned char);
  
  /** \brief Write a unsigned char* array otherwise fail.
  */
                       bool                  writeUChar(unsigned char*, size_t length);
  
  /** \brief Write a single char otherwise fail.
  */
                       bool                  writeChar(char);
  
  /** \brief Write a char* array otherwise fail.
  */
                       bool                  writeChar(char*, size_t length);
  
  /** \brief Write a single unsigned short otherwise fail.
  */
                       bool                  writeUShort(unsigned short);
  
  /** \brief Write a unsigned short* array otherwise fail.
  */
                       bool                  writeUShort(unsigned short*, size_t length);
  
  /** \brief Write a single short otherwise fail.
  */
                       bool                  writeShort(short);
  
  /** \brief Write a short* array otherwise fail.
  */
                       bool                  writeShort(short*, size_t length);
  
  /** \brief Write a single unsigned int otherwise fail.
  */
                       bool                  writeUInt(unsigned int);
  
  /** \brief Write a unsigned int* array otherwise fail.
  */
                       bool                  writeUInt(unsigned int*, size_t length);
  
  /** \brief Write a single int otherwise fail.
  */
                       bool                  writeInt(int);
  
  /** \brief Write a int* array otherwise fail.
  */
                       bool                  writeInt(int*, size_t length);
  
  /** \brief Write a single float otherwise fail.
  */
                       bool                  writeFloat(float);
  
  /** \brief Write a float* array otherwise fail.
  */
                       bool                  writeFloat(float*, size_t length);
  
  /** \brief Write a single double otherwise fail.
  */
                       bool                  writeDouble(double);
  
  /** \brief Write a double* array otherwise fail.
  */
                       bool                  writeDouble(double*, size_t length);
  
  /** \brief Write a float or double otherwise fail
  */
                       bool                  writeReal(NxOgreRealType);
  
  /** \brief Write a float or double array otherwise fail
  */
                       bool                  writeReal(NxOgreRealType*, size_t length);
  
  /** \brief Write a single long otherwise fail.
  */
                       bool                  writeLong(long);
  
  /** \brief Write a long* array otherwise fail.
  */
                       bool                  writeLong(long*, size_t length);
  
  /** \brief Read a bool otherwise fail.
  */
                       bool                  readBool(void);
  
  /** \brief Read a bool* array otherwise fail.
  */
                       void                  readBoolArray(bool*, size_t length);
  
  /** \brief Read a single unsigned char otherwise fail.
  */
                       unsigned char         readUChar(void);
  
  /** \brief Read a unsigned char* array otherwise fail.
  */
                       void                  readUCharArray(unsigned char*, size_t length);
  
  /** \brief Read a single char otherwise fail.
  */
                       char                  readChar(void);
  
  /** \brief Read a char* array otherwise fail.
  */
                       void                  readCharArray(char*, size_t length);
  
  /** \brief Read a single unsigned short otherwise fail.
  */
                       unsigned short        readUShort(void);
  
  /** \brief Read a unsigned short* array otherwise fail.
  */
                       void                  readUShortArray(unsigned short*, size_t length);
  
  /** \brief Read a single short otherwise fail.
  */
                       short                 readShort(void);
  
  /** \brief Read a short* array otherwise fail.
  */
                       void                  readShortArray(short*, size_t length);
  
  /** \brief Read a single unsigned int otherwise fail.
  */
                       unsigned int          readUInt(void);
  
  /** \brief Read a unsigned int* array otherwise fail.
  */
                       void                  readUIntArray(unsigned int*, size_t length);
  
  /** \brief Read a single int otherwise fail.
  */
                       int                   readInt(void);
  
  /** \brief Read a int* array otherwise fail.
  */
                       void                  readIntArray(int*, size_t length);
  
  /** \brief Read a single float otherwise fail.
  */
                       float                 readFloat(void);
  
  /** \brief Read a float* array otherwise fail.
  */
                       void                  readFloatArray(float*, size_t length);
  
  /** \brief Read a single double otherwise fail.
  */
                       double                readDouble(void);
  
  /** \brief Read a double* array otherwise fail.
  */
                       void                  readDouble(double*, size_t length);
  
  /** \brief Read a float or double otherwise fail
  */
                       Real                  readReal(void);
  
  /** \brief Read a float or double array otherwise fail
  */
                       void                  readRealArray(NxOgreRealType*, size_t length);
  
  /** \brief Read a single long otherwise fail.
  */
                       long                  readLong(void);
  
  /** \brief Read a long* array otherwise fail.
  */
                       void                  readLongArray(long*, size_t length);
  
  /** \brief Flush function. Not applicable to memory
  */
                       void                   flush();
  
  protected:
  
  /** \brief Open the resource.
  */
                       void                  open();
  
  /** \brief Close the resource.
  */
                       void                  close(void);
  
  protected: // Variables
  
                       char*                 mStart;
                       char*                 mEnd;
                       char*                 mPointer;

}; // class MemoryResource

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
