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

                                                                                       


#ifndef NXOGRE_STRING_H
#define NXOGRE_STRING_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

typedef std::string String;

typedef std::stringstream StringStream;

typedef unsigned long StringHash;

namespace Functions
{
 
 unsigned long inline StringHash(const char* str)
 {
  
  if (strlen(str) == 0 || str == 0)
   return 0;
  
  unsigned long hash = 5381;
  int c = 0;
  while (c = *str++)
   hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash; 
 }
 
 unsigned long inline StringHash(const String& str)
 {
  return StringHash(str.c_str());
 }
 
 inline size_t find_first_character_of(const ::NxOgre::String& string_val, char search)
 {
  for (size_t i=0; i < string_val.length(); i++)
  {
   if (string_val[i] == search)
    return i;
  }
  return ::NxOgre::String::npos;
 }
 
}


static const String BLANK_STRING = String();

static const StringHash BLANK_HASH = Functions::StringHash(BLANK_STRING);


                                                                                       

} // namespace NXOGRE_NAMESPACE

                                                                                       

#endif
