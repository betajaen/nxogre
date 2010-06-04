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
#include "NxOgreHeightFieldData.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief HeightFieldManager holds all meshes that are currently in the World.
*/
class NxOgrePublicClass HeightFieldManager: public ::NxOgre::Singleton<HeightFieldManager>, public BigClassAllocatable
{
  
  friend class World;
  
  NXOGRE_GC_FRIEND_NEW0
  NXOGRE_GC_FRIEND_DELETE
  
  friend class HeightFieldData;
  
  public: // Functions
  
  typedef map<size_t, HeightField*, GC::HasGarbageCollection> HeightFields;
  
  typedef map_iterator<size_t, HeightField*>                  HeightFieldIterator;
  
  /*! function. load
      desc.
          Load a mesh into the World, that can be used in any Scene.
      note.
          If the name is blank, then the mesh name is taken from the path filename, if it can't do that
          then a name is created for it.
  */
  HeightField* load(const Path&, const String& name = BLANK_STRING);
  
  /*! function. load
      desc.
          Load a mesh into the World, that can be used in any Scene.
      note.
          If the name is blank then a name is created for it.
  */
  HeightField* load(Resource*, const String& name = BLANK_STRING);
  
  /*! function. unload
      desc.
          Try and unload a mesh otherwise return false.
      note.
          The mesh cannot be used by anything to be unloaded.
  */
  bool unload(const String& name);
  
  /*! function. unload
      desc.
          Try and unload a mesh otherwise return false.
      note.
          The mesh cannot be used by anything to be unloaded.
  */
  bool unload(const StringHash& name);
  
  /*! function. hasHeightField
      desc.
          Is a mesh loaded?
  */
  bool hasHeightField(const String& name) const;
  
  /*! function. hasHeightField
      desc.
          Is a mesh loaded?
  */
  bool hasHeightField(const StringHash& hash_name) const;
  
  /*! function. getByName
      desc.
          Get a mesh by it's name or null if it doesn't exist.
  */
  HeightField* getByName(const String& name);
  
  /*! function. getByHash
      desc.
          Get a mesh by it's hashed name or null if it doesn't exist.
  */
  HeightField* getByHash(const StringHash& hashed_name);
  
  /*! function. getHeightFields
      desc.
          Get an iterator to all the loaded meshes.
  */
  HeightFieldIterator getHeightFields() const;
  
  protected: // Variables
  
  /* \internal For use with HeightFieldData::cookQuickly
  */
  HeightField* load(HeightField*, const String& name = BLANK_STRING);

  /* \internal See World::precreateSingletons
  */
  HeightFieldManager();
  
  /* \internal See World::destroySingletons
  */
 ~HeightFieldManager();
  
  /* Known loaded meshes in the World.
  */
  HeightFields mHeightFields;
  
  unsigned int mNextHeightFieldID;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
