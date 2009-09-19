/** File: NxOgreResource.h
    Created on: 15-Nov-08
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

#ifndef NXOGRE_RESOURCE_H
#define NXOGRE_RESOURCE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreArchive.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A Resource represents a file or a block of data. It can be streamed from or accessed randomly. Resources should
           be created via the ResourceSystem and handled safely in a Resource*.
    \example
     <code>
       Resource* res = ResourceSystem::getSingleton()->open("file://test.bin", Enums::ResourceAccess_ReadAndWrite);
       res->writeChar('d');
       res->seekBack(5);
       char* c = (char*) NxOgre_Allocate(Classes::_char, sizeof(char) * 5);
       res->readCharArray(c, sizeof(char) * 5);
     </code>
*/
class NxOgrePublicClass Resource
{
  
  public: // Functions
  
  /** \brief Required abstract constructor
  */
                                               Resource(const ArchiveResourceIdentifier&, Archive*);
  
  /** \brief Required virtual destructor
  */
  virtual                                     ~Resource(void);
  
  /** \brief Get the parent Archive.
  */
  Archive*                                   getArchive();
  
  /** \brief Get the ArchiveResourceIdentifier that identifies the Resource and Archive's name.
  */
  ArchiveResourceIdentifier                    getArchiveResourceIdentifier();
  
  /** \brief Has the resource been "touched" by a write operation?
  */
  bool                                         hasTouched() const;
  
  /** \brief Get the number of read operations on that resource.
  */
  unsigned int                                 getNbReadOperations() const;
  
  /** \brief Get the number of write operations on that resource.
  */
  unsigned int                                 getNbWriteOperations() const;
  
  /** \brief What is the resources status?
  */
  virtual               Enums::ResourceStatus getStatus(void) const = 0;
  
  /** \brief Get the directionality of the resource
  */
  virtual               Enums::ResourceDirectionality getDirectionality(void) const = 0;
  
  /** \brief Get the type of access of the resource
  */
  virtual               Enums::ResourceAccess         getAccess(void) const = 0;
  
  /** \brief Get the size (in bytes) of the resource, or Constants::ResourceSizeUnknown.
      \note  If the Directionality is sucessional or the status is anything but open then
             the file size will be Constants::ResourceSizeUnknown.
  */
  virtual               size_t                getSize(void) const = 0;
  
  /** \brief Go somewhere into the resource from, this is relative to the ReadWrite pointer and not an absolute.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
  virtual               bool                  seek(size_t) = 0;

  /** \brief Go to the beginning of the resource.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
  virtual               bool                  seekBeginning(void) = 0;

  /** \brief Go to the end of the resource.
      \note Depending on status, or directionality this will not be possible.
      \return True if the seek did happen, or false if it did not.
  */
  virtual               bool                  seekEnd(void) = 0;

  /** \brief Is the ReadWrite pointer at the end of Resource?
  */
  virtual               bool                  atBeginning(void) const = 0;

  /** \brief Is the ReadWrite pointer at the end of Resource, just like a standard "EOF" function.
  */
  virtual               bool                  atEnd(void) const = 0;

  /** \brief Where the ReadWrite is from the beginning of the resource.
      \note  Constants::ResourceSizeUnknown will be returned if it is an unknown.
  */
  virtual               size_t                at(void) const = 0;

  /** \brief Write something otherwise fail.
  */
  virtual               bool                  write(const void* src, size_t src_size) = 0;

  /** \brief Write a single null (0x00) to the resource otherwise fail.
  */
  virtual               bool                  writeNull(void) = 0;

  /** \brief Write a bool otherwise fail.
  */
  virtual               bool                  writeBool(bool) = 0;

  /** \brief Write a bool* array otherwise fail.
      \note  Length should be given as "array_size * sizeof(T)" or the same value you give
             to NxOgre_Allocate as a size.
  */
  virtual               bool                  writeBool(bool*, size_t length) = 0;

  /** \brief Write a single unsigned char otherwise fail.
  */
  virtual               bool                  writeUChar(unsigned char) = 0;

  /** \brief Write a unsigned char* array otherwise fail.
      \note  Length should be given as "array_size * sizeof(T)" or the same value you give
             to NxOgre_Allocate as a size.
  */
  virtual               bool                  writeUChar(unsigned char*, size_t length) = 0;

  /** \brief Write a single char otherwise fail.
  */
  virtual               bool                  writeChar(char) = 0;

  /** \brief Write a char* array otherwise fail.
  */
  virtual               bool                  writeChar(char*, size_t length) = 0;

  /** \brief Write a single unsigned short otherwise fail.
  */
  virtual               bool                  writeUShort(unsigned short) = 0;

  /** \brief Write a unsigned short* array otherwise fail.
  */
  virtual               bool                  writeUShort(unsigned short*, size_t length) = 0;

  /** \brief Write a single short otherwise fail.
  */
  virtual               bool                  writeShort(short) = 0;

  /** \brief Write a short* array otherwise fail.
  */
  virtual               bool                  writeShort(short*, size_t length) = 0;

  /** \brief Write a single unsigned int otherwise fail.
  */
  virtual               bool                  writeUInt(unsigned int) = 0;

  /** \brief Write a unsigned int* array otherwise fail.
  */
  virtual               bool                  writeUInt(unsigned int*, size_t length) = 0;

  /** \brief Write a single int otherwise fail.
  */
  virtual               bool                  writeInt(int) = 0;

  /** \brief Write a int* array otherwise fail.
  */
  virtual               bool                  writeInt(int*, size_t length) = 0;

  /** \brief Write a single float otherwise fail.
  */
  virtual               bool                  writeFloat(float) = 0;

  /** \brief Write a float* array otherwise fail.
  */
  virtual               bool                  writeFloat(float*, size_t length) = 0;

  /** \brief Write a single double otherwise fail.
  */
  virtual               bool                  writeDouble(double) = 0;

  /** \brief Write a double* array otherwise fail.
  */
  virtual               bool                  writeDouble(double*, size_t length) = 0;

  /** \brief Write a float or double otherwise fail
  */
  virtual               bool                  writeReal(NxOgreRealType) = 0;

  /** \brief Write a float or double array otherwise fail
  */
  virtual               bool                  writeReal(NxOgreRealType*, size_t length) = 0;

  /** \brief Write a single long otherwise fail.
  */
  virtual               bool                  writeLong(long) = 0;

  /** \brief Write a long* array otherwise fail.
  */
  virtual               bool                  writeLong(long*, size_t length) = 0;


  /** \brief Read a bool otherwise fail.
  */
  virtual               bool                  readBool(void) = 0;

  /** \brief Read a bool* array otherwise fail.
      \note  Length should be given as "array_size * sizeof(T)" or the same value you give
             to NxOgre_Allocate as a size.
  */
  virtual               void                  readBoolArray(bool*, size_t length) = 0;

  /** \brief Read a single unsigned char otherwise fail.
  */
  virtual               unsigned char         readUChar(void) = 0;

  /** \brief Read a unsigned char* array otherwise fail.
      \note  Length should be given as "array_size * sizeof(T)" or the same value you give
             to NxOgre_Allocate as a size.
  */
  virtual               void                  readUCharArray(unsigned char*, size_t length) = 0;

  /** \brief Read a single char otherwise fail.
  */
  virtual               char                  readChar(void) = 0;

  /** \brief Read a char* array otherwise fail.
      \note  Length should be given as "array_size * sizeof(T)" or the same value you give
             to NxOgre_Allocate as a size.
  */
  virtual               void                  readCharArray(char*, size_t length) = 0;

  /** \brief Read a single unsigned short otherwise fail.
  */
  virtual               unsigned short        readUShort(void) = 0;

  /** \brief Read a unsigned short* array otherwise fail.
      \note  Length should be given as "array_size * sizeof(T)" or the same value you give
             to NxOgre_Allocate as a size.
  */
  virtual               void                  readUShortArray(unsigned short*, size_t length) = 0;

  /** \brief Read a single short otherwise fail.
  */
  virtual               short                 readShort(void) = 0;

  /** \brief Read a short* array otherwise fail.
  */
  virtual               void                  readShortArray(short*, size_t length) = 0;

  /** \brief Read a single unsigned int otherwise fail.
  */
  virtual               unsigned int          readUInt(void) = 0;

  /** \brief Read a unsigned int* array otherwise fail.
  */
  virtual               void                  readUIntArray(unsigned int*, size_t length) = 0;

  /** \brief Read a single int otherwise fail.
  */
  virtual               int                   readInt(void) = 0;

  /** \brief Read a int* array otherwise fail.
  */
  virtual               void                  readIntArray(int*, size_t length) = 0;

  /** \brief Read a single float otherwise fail.
  */
  virtual               float                 readFloat(void) = 0;

  /** \brief Read a float* array otherwise fail.
  */
  virtual               void                  readFloatArray(float*, size_t length) = 0;

  /** \brief Read a single double otherwise fail.
  */
  virtual               double                readDouble(void) = 0;

  /** \brief Read a double* array otherwise fail.
  */
  virtual               void                  readDouble(double*, size_t length) = 0;

  /** \brief Read a float or double otherwise fail
  */
  virtual               Real                  readReal(void) = 0;

  /** \brief Read a float or double array otherwise fail
  */
  virtual               void                  readRealArray(NxOgreRealType*, size_t length) = 0;

  /** \brief Read a single long otherwise fail.
  */
  virtual               long                  readLong(void) = 0;

  /** \brief Read a long* array otherwise fail.
  */
  virtual               void                  readLongArray(long*, size_t length) = 0;
  
  /** \brief Force any changes to the resource
  */
  virtual               void                  flush() = 0;

  protected: // Functions

  /** \brief Open the resource.
  */
                       void                  open(void);
  
  /** \brief Close the resource.
  */
                       void                  close(void);

  protected: // Variables
  
  /** \internal Local copy of the resource identifier
  */
                ArchiveResourceIdentifier     mArchiveResourceIdentifier;
  
  /** \internal Local copy of the resource status. Updated often throughout the resources lifetime.
  */
                Enums::ResourceStatus         mStatus;
  
  /** \internal Local copy of the resource directionality.
  */
                Enums::ResourceDirectionality mDirectionality;
  
  /** \internal Local copy of the resource resource access.
  */
                Enums::ResourceAccess         mAccess;
  
  /** \brief Parent archive
  */
                Archive*                    mArchive;
  
  /** \brief Number of Read Operations.
  */
                unsigned int                  mNbReadOperations;
  
  /** \brief Number of Write operations.
  */
                unsigned int                  mNbWriteOperations;

  /** \internal A single null byte
  */
  static const           char                 NULL_BYTE;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
