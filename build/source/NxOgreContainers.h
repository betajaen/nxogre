/** File: NxOgreContainers.h
    Created on: 17-Sept-09
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

#ifndef NXOGRE_CONTAINERS_H
#define NXOGRE_CONTAINERS_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       


template<typename value_type>
class vector_iterator;

template<typename key_type, typename value_type>
class map_iterator;

template<typename key_type, typename value_type>
class multimap_iterator;

template<typename value> struct vector
{
 typedef value                                                      value_type;
 typedef boost::ptr_vector<value_type>                              type;
 typedef typename type::const_iterator                              const_iterator;
 typedef typename type::iterator                                    iterator;
 typedef vector_iterator<value>                                   user_iterator;
};

template<typename key, typename value> struct map
{
 typedef key                                                        key_type;
 typedef value                                                      value_type;
 typedef boost::ptr_map<key_type, value_type>                       type;
 typedef typename type::const_iterator                              const_iterator;
 typedef typename type::iterator                                    iterator;
 typedef map_iterator<key_type, value_type>         user_iterator;
};

template<typename key, typename value> struct multimap
{
 typedef key                                                        key_type;
 typedef value                                                      value_type;
 typedef boost::ptr_multimap<key_type, value_type>                  type;
 typedef typename type::const_iterator                              const_iterator;
 typedef typename type::iterator                                    iterator;
 typedef multimap_iterator<key_type, value_type>    user_iterator;
};


                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
