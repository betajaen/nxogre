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

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief HeightFieldManager holds all HeightFieldes that are currently in the World.
*/
class NxOgrePublicClass HeightFieldManager: public ::NxOgre::Singleton<HeightFieldManager, ::NxOgre::Classes::_HeightFieldManager>
{
  
  friend class World;
  friend class ManualHeightField;
  
  public: // Functions
  
  /** \brief Load a HeightField into the World, that can be used in any Scene.
      \note  It will take the resource name as it's name.
  */
  HeightField*                                       load(const ArchiveResourceIdentifier&);
  
  /** \brief Load a HeightField into the World, that can be used in any Scene.
  */
  HeightField*                                       load(const ArchiveResourceIdentifier&, const String& name);
    
  /** \brief Load a HeightField into the World, that can be used in any Scene.
      \note  It will try to take the resource name as it's name, otherwise a random one will be generated.
  */
  HeightField*                                       load(Resource*);
  
  /** \brief Load a HeightField into the World, that can be used in any Scene.
  */
  HeightField*                                       load(Resource*, const String& name);
  
  /** \brief Text
  */
  HeightField*                                       getByName(const String& HeightFieldIdentifier);
  
  protected: // Variables
  
  /** \internal See World::precreateSingletons
  */
                                                     HeightFieldManager(void);
  
  /** \internal See World::destroySingletons
  */
                                                    ~HeightFieldManager(void);
  
  /** \brief Known loaded HeightFields in the World.
  */
  Array<HeightField*>                                mLoadedHeightFields;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
