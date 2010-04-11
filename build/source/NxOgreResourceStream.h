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

                                                                                       

#ifndef NXOGRE_RESOURCESTREAM_H
#define NXOGRE_RESOURCESTREAM_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       


/*! class. TextResourceStream
    desc.
        Helper class to write to Resources as text files, in the style of the STL stream classes.
        All datatypes will be converted into their text equilvant via the to_s function.
    note.
        You must open and close the Resource as you would with any other Resource.
*/
class NxOgrePublicClass TextResourceStream
{
  
  public: // Functions
  
  /** \brief Required abstract constructor
  */
  TextResourceStream(Resource* resource);

  inline TextResourceStream& operator <<(int value)
  {
   mResource->writeString(to_s(value));
   return *this;
  }
  
  inline TextResourceStream& operator <<(unsigned int value)
  {
   mResource->writeString(to_s(value));
   return *this;
  }

  inline TextResourceStream& operator <<(float value)
  {
   mResource->writeString(to_s(value));
   return *this;
  }

  inline TextResourceStream& operator <<(double value)
  {
   mResource->writeString(to_s(value));
   return *this;
  }

  inline TextResourceStream& operator <<(char value)
  {
   mResource->writeChar(value);
   return *this;
  }

  inline TextResourceStream& operator <<(unsigned char value)
  {
   mResource->writeUChar(value);
   return *this;
  }

  inline TextResourceStream& operator <<(short value)
  {
   mResource->writeString(to_s(value));
   return *this;
  }

  inline TextResourceStream& operator <<(unsigned short value)
  {
   mResource->writeString(to_s(value));
   return *this;
  }


  inline TextResourceStream& operator <<(const char* string)
  {
   mResource->write(string, strlen(string));
   return *this;
  }
  
  inline TextResourceStream& operator <<(const String& string)
  {
   mResource->writeString(string);
   return *this;
  }
  

  Resource* mResource;
  
}; // class Resource

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
