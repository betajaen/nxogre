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

                                                                                       

#ifndef NXOGRE_CONTAINERS_H
#define NXOGRE_CONTAINERS_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
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


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
