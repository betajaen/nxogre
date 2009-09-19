/** File: NxOgreTuple.h
    Created on: 16-Apr-09
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

#ifndef NXOGRE_TUPLE_H
#define NXOGRE_TUPLE_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief An ordered 2-tuple.
*/
template <typename T>
class NxOgrePublicClass Pair
{
 public:
  
  Pair()
  {
  }
  
  Pair(T _1st, T _2nd)
  : first(_1st), second(_2nd)
  {
  }
  
  T  first;
  T  second;
  
}; // class Pair

/** \brief An ordered 3-tuple.
*/
template <typename T>
class NxOgrePublicClass Triple
{
 public:
  
  Triple()
  {
  }
  
  Triple(T _1st, T _2nd, T _3rd)
  : first(_1st), second(_3rd), third(_3rd)
  {
  }
  
  T  first;
  T  second;
  T  third;
  
}; // class Triple

/** \brief An ordered 4-tuple.
*/
template <typename T>
class NxOgrePublicClass Quadruple
{
 public:
  
  Quadruple()
  {
  }
  
  Quadruple(T _1st, T _2nd, T _3rd, T _4th)
  : first(_1st), second(_3rd), third(_3rd), fourth(_4th)
  {
  }
  
  T  first;
  T  second;
  T  third;
  T  fourth;
  
}; // class Quadruple

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
