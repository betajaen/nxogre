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

                                                                                       

#ifndef NXOGRE_HEIGHTFIELDMANAGER_H
#define NXOGRE_HEIGHTFIELDMANAGER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreHeightField.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief HeightFieldManager holds all HeightFieldes that are currently in the World.
*/
class NxOgrePublicClass HeightFieldManager: public ::NxOgre::Singleton<HeightFieldManager>, public BigClassAllocatable
{
  
  friend class World;
  friend class ManualHeightField;
  
  public: // Functions
  
  typedef ptr_multihashmap<HeightField>             HeightFields;
  
  typedef ptr_multihashmap<HeightField>::iterator_t HeightFieldIterator;
  
  protected: // Variables
  
  /** \brief Load a heightfield into the World, that can be used in any Scene.
      \note  If name is BLANK_STRING then name may be given as <code>Path::getFilenameOnly()</code> of the path
  */
  HeightField*                                       load(const Path&, const String& name = BLANK_STRING);
  
  /** \brief Load a heightfield into the World, that can be used in any Scene.
      \note  If name is BLANK_STRING then name may be given as <code>Path::getFilenameOnly()</code> of the path
  */
  HeightField*                                       load(Resource*, const String& name = BLANK_STRING);
  
  /** \brief Get a heightfield by it's name. (Slower)
  */
  HeightField*                                       getByName(const String& name);
  
  /** \brief Get a heightfield by it's the hash of its name. (Faster)
  */
  HeightField*                                       getByHash(const StringHash& hashed_name);
  
  /** \brief
  */
  HeightFieldIterator                                getMeshes();
  
  /** \internal See World::precreateSingletons
  */
                                                     HeightFieldManager(void);
  
  /** \internal See World::destroySingletons
  */
                                                    ~HeightFieldManager(void);
  /** \brief Known loaded HeightFields in the World.
  */
  HeightFields                                       mHeightFields;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
