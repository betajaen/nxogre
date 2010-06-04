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

                                                                                       

#ifndef NXOGRE_MESHMANAGER_H
#define NXOGRE_MESHMANAGER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreMesh.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief MeshManager holds all meshes that are currently in the World.
*/
class NxOgrePublicClass MeshManager: public ::NxOgre::Singleton<MeshManager>, public BigClassAllocatable
{
  
  friend class World;
  
  NXOGRE_GC_FRIEND_NEW0
  NXOGRE_GC_FRIEND_DELETE

  public: // Functions
  
  typedef map<size_t, Mesh*, GC::HasGarbageCollection> Meshes;
  
  typedef map_iterator<size_t, Mesh*>                  MeshIterator;
  
  /*! function. load
      desc.
          Load a mesh into the World, that can be used in any Scene.
      note.
          If the name is blank, then the mesh name is taken from the path filename, if it can't do that
          then a name is created for it.
  */
  Mesh* load(const Path&, const String& name = BLANK_STRING);
  
  /*! function. load
      desc.
          Load a mesh into the World, that can be used in any Scene.
      note.
          If the name is blank then a name is created for it.
  */
  Mesh* load(Resource*, const String& name = BLANK_STRING);
  
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
  
  /*! function. hasMesh
      desc.
          Is a mesh loaded?
  */
  bool hasMesh(const String& name) const;
  
  /*! function. hasMesh
      desc.
          Is a mesh loaded?
  */
  bool hasMesh(const StringHash& hash_name) const;
  
  /*! function. getByName
      desc.
          Get a mesh by it's name or null if it doesn't exist.
  */
  Mesh* getByName(const String& name);
  
  /*! function. getByHash
      desc.
          Get a mesh by it's hashed name or null if it doesn't exist.
  */
  Mesh* getByHash(const StringHash& hashed_name);
  
  /*! function. getMeshes
      desc.
          Get an iterator to all the loaded meshes.
  */
  MeshIterator getMeshes() const;
  
  protected: // Variables
  
  /* \internal See World::precreateSingletons
  */
  MeshManager();
  
  /* \internal See World::destroySingletons
  */
 ~MeshManager();
  
  /* Known loaded meshes in the World.
  */
  Meshes mMeshes;
  
  unsigned int mNextMeshID;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
