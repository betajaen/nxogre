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
#include "NxOgreFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

unsigned int getCStringLength(const char* str)
{
 if (str == 0)
  return 0;
 const char* c = str;
 while((*c) != 0)
  c++;
 return unsigned int(c - str);
}

unsigned long generateHash(const char* str, Enums::HashAlgorithm ha)
{
 switch (ha)
 {
  
  case  Enums::HashAlgorithm_DJB2:
  {
   if (str == 0)
    return 0;
  
   unsigned long hash = 5381;
   int c;
  
   while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  
   return hash;
  }
  
 };
  
 return 0;
}

                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       
