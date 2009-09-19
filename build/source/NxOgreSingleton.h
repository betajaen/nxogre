/** File: NxOgreSingleton.h
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

#ifndef NXOGRE_SINGLETON_H
#define NXOGRE_SINGLETON_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
template<class T, unsigned int Ti> class Singleton
{
  
  public:
  
  static                 T*                   getSingleton(void)
  {
   return sSingleton;
  }
  
  protected: // Functions
  
  /** \brief Text
  */
                                              Singleton(void)
  {
   sSingleton = static_cast<T*>(this);
  }
  
  /** \brief Text
  */
                                             ~Singleton(void)
  {
  }
  
  void* operator new(size_t size)
  {
   return NxOgre_Allocate(size, Ti);
  }

  void operator delete(void* mem)
  {
    NxOgre_Unallocate(mem);
  }

  protected: // Variables
  
   static T*                                      sSingleton;
  
  
}; // class Singleton

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
