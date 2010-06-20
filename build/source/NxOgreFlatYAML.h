/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to Value person obtaining a copy
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

                                                                                       

#ifndef NXOGRE_SIMPLIFIEDYAML_H
#define NXOGRE_SIMPLIFIEDYAML_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Serialisation
{

                                                                                       

/*! class. FlatYAML
    
    desc.
    
     Collection of functions to serialise a property list to a Simplified YAML file format.
    
     This only partially complies with the YAML specification, Flat YAML is only concerned with
     the key-value part of YAML, so other features are missing or incomplete.
     
     More specifically:
      * The YAML document is treated as a flat continuous structure, with no support for child values.
      * All keys are assumed to be strings.
      * Lists are not supported.
      * FlatYAML uses the "Value" class as an intermediate, so accepted types of values are:
         - null
         - string (without newline characters)
         - float
         - integer
         - boolean
         - Vec3 (as a custom nxogre/vec3 type)
         - Quat (as a custom nxogre/quat type)
         - Other types are assumed to be strings.
*/
class NxOgrePublicClass FlatYAML
{
  
 public:
  
  /** \brief Load a NxOgre Skeleton from a Resource
  */
  static void load(const Path&, StringValueList&);

  /** \brief Load a NxOgre Skeleton from a Resource
  */
  static void load(Resource*, StringValueList&);
  
  /** \brief Load a NxOgre Skeleton from a Resource
  */
  static void save(const Path&, const StringValueList&);

  /** \brief Load a NxOgre Skeleton from a Resource
  */
  static void save(Resource*, const StringValueList&);
    
 private:
  
  /** \internal DO NOT USE
  */
  FlatYAML();
  
  /** \internal DO NOT USE
  */
 ~FlatYAML();
  
};

                                                                                       

} // namespace Serialisation

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
