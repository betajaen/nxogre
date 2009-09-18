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

                                                                                       

#ifndef NXOGRE_WORLDPROTOTYPE_H
#define NXOGRE_WORLDPROTOTYPE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreWorldDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A WorldPrototype is pretty much an entired serialised world.
*/
class NxOgrePublicClass WorldPrototype : public WorldDescription, public PointerClass<::NxOgre::Classes::_WorldPrototype>
{
  
  public: // Functions
  
  /** \brief WorldPrototype constructor
  */
                                              WorldPrototype(void);
  
  /** \brief WorldPrototype destructor
  */
                                             ~WorldPrototype(void);
  
  /** \brief Reset the World to the most default values, with no Scenes.
  */
                        void                  reset(void);

  /** \brief Does the prototype's variables are in the range of acceptable values?
  */
                        bool                  valid(void);

  /** \brief Scenes
  */
                        Array<Scene*>         mScenes;
  
  /** \brief Meshes
  */
///             Array<Mesh*>                  mMeshes;
  
  /** \brief HeightFields
  */
///             Array<HeightField*>           mHeightField;
  
  
}; // class WorldPrototype

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
