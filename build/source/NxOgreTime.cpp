/** File: NxOgreTime.cpp
    Created on: 30-Sep-09
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
#include "NxOgreTime.h"

#if NxOgrePlatform == NxOgrePlatformWindows
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

float time()
{
 static __int64 s = 0;
 static __int64 f = 0;
 
 if (s == 0)
 {
  QueryPerformanceCounter( (LARGE_INTEGER*) &s);
  QueryPerformanceFrequency( (LARGE_INTEGER*) &f);
  return 0.0f;
 }
 
 __int64 c = 0;
 QueryPerformanceCounter( (LARGE_INTEGER*) &c);
 return (float) ( (c - s) / double(f) );
}

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       
