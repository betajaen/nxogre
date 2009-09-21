/** File: NxOgreSharedStringStream.h
    Created on: 4-Nov-08
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

#ifndef NXOGRE_SHAREDSTRINGSTREAM_H
#define NXOGRE_SHAREDSTRINGSTREAM_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreVec3.h"
#include "NxOgreString.h"


                                                                                       

namespace NxOgre
{

                                                                                       

class SharedStringStream;

inline SharedStringStream& operator<<(SharedStringStream&, const char*);
inline SharedStringStream& operator<<(SharedStringStream&, const void*);
inline SharedStringStream& operator<<(SharedStringStream&, unsigned int);
inline SharedStringStream& operator<<(SharedStringStream&, char);
inline SharedStringStream& operator<<(SharedStringStream&, int);
inline SharedStringStream& operator<<(SharedStringStream&, float);
inline SharedStringStream& operator<<(SharedStringStream&, double);
inline SharedStringStream& operator<<(SharedStringStream&, const Vec3&);
inline SharedStringStream& operator<<(SharedStringStream&, const Quat&);
inline SharedStringStream& operator<<(SharedStringStream&, const SharedStringStream&);
inline SharedStringStream& operator<<(SharedStringStream&, const String&);

class NxOgrePublicClass SharedStringStream
{
  
  friend SharedStringStream& operator<<(SharedStringStream&, const char*);
  friend SharedStringStream& operator<<(SharedStringStream&, const void*);
  friend SharedStringStream& operator<<(SharedStringStream&, unsigned int);
  friend SharedStringStream& operator<<(SharedStringStream&, int);
  friend SharedStringStream& operator<<(SharedStringStream&, float);
  friend SharedStringStream& operator<<(SharedStringStream&, double);
  friend SharedStringStream& operator<<(SharedStringStream&, const Vec3&);
  friend SharedStringStream& operator<<(SharedStringStream&, const Quat&);
  friend SharedStringStream& operator<<(SharedStringStream&, const SharedStringStream&);
  friend SharedStringStream& operator<<(SharedStringStream&, const String&);

  public: // Functions
  
  enum
  {
   _LARGE = 512
  };


  /** \brief A blank string
  */
                                              SharedStringStream(size_t buffer_size = 32);
  
  /** \brief A string
  */
                                              SharedStringStream(const char*);
  
  /** \brief Copy constructor
  */
                                              SharedStringStream(const SharedStringStream&);
  
  /** \brief No more string
  */
                                             ~SharedStringStream(void);
  
  /** \brief Assignment operator
  */
                     SharedStringStream&      operator=(const SharedStringStream&);
  
  
  /** \brief Set from a const char via an assignment operator
  */

  
  /** \brief Get as a const char
  */
                           const char*        get(void) const;
  
  
  /** \brief Set from a const char
  */
                           void               add(const char*);
  
  /** \brief To a const char via an operator.
  */
                           operator const char*(void) const;
  
  /** \brief  Is there a string present?
  */
                           bool                isSet(void) const;
  
  /** \brief  Does the stream currently end with a character?
  */
                           bool                endsWith(char) const;

  /** \brief Clear the stream
      \note It does not resize the buffer.
  */
                           void                clear();

  /** \brief Length of the stream so far, not the total size of the buffer.
  */
                           size_t              length() const;

  protected: // Functions

  /** \internal
  */
                           void                _createBuffer(size_t);

  protected: // Structs
  
  /** \internal
  */
  struct Buffer
  {
   char *_String, *_Write, *_End;
  };

  protected: // Variables
  
                           Buffer*             _Buffer;
                           unsigned short*     _References;
  
}; // class SharedStringStream;

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
