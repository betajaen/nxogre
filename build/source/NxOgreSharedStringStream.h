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
