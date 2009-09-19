/** File: NxOgreFunctions.cpp
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

                                                                                       
