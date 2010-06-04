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

                                                                                       

#ifndef NXOGRE_HEIGHTFIELD_H
#define NXOGRE_HEIGHTFIELD_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass HeightField : public ResourceAllocatable
{
  
  NXOGRE_GC_FRIEND_NEW1
  NXOGRE_GC_FRIEND_DELETE
  
  friend class HeightFieldData;
  friend class HeightFieldManager;
  
  public: // Functions
  
  /** \brief Set the name of this HeightField
  */
  void                                        setName(const char*);
  
  /** \brief Set the name of this HeightField
  */
  void                                        setName(const String&);
  
  /** \brief Get the name of this heightfield.
  */
  String                                      getName() const;
  
  /** \brief Get the name of this heightfield.
  */
  StringHash                                  getNameHash() const;
  
  /** \brief Is the shape loaded?
  */
  bool                                        isLoaded() const;
  
  /** \brief Is a shape(s) using this heightfield?
  */
  bool                                        isUsed() const;

  /*! function. getNbRows
      desc.
          Get number of rows.
  */
  unsigned int                                getNbRows() const;

  /*! function. getNbColumns
      desc.
          Get number of columns.
  */
  unsigned int                                getNbColumns() const;

  /** \brief Get's the convex heightfield, or null
  */
  NxHeightField*                              getHeightField();
  
  /** \brief Save the heightfield information into HeightFieldData
      \note  You should NXOGRE_DELETE_NXOGRE the HeightFieldData pointer after use.
  */
  HeightFieldData*                            getHeightFieldData();
  
  /*! function. inspect
      desc.
          Give a description of what this heightfield is.
  */
  String                                      inspect() const;
  
  protected: // Variables
  
  NxHeightField*                              mHeightField;
  
  /** \brief Name of the heightfield
  */
  String                                      mName;
  
  /** \brief Hash of the name of the heightfield.
  */
  StringHash                                  mNameHash;

  protected:
  
  /** \brief HeightField constructor
  */
                                              HeightField();
  
  /** \brief HeightField constructor, equilvent of calling load(uri);
  */
                                              HeightField(Resource*);
  
  /** \brief HeightField constructor, equilvent of calling load(uri);
  */
                                              HeightField(NxHeightField*);
  
  /** \brief HeightField destructor.
  */
                                             ~HeightField();
    
  /** \brief Load a heightfield from a resource, and take on that heightfield.
  */
  void                                        load(Resource*);
  
  /** \brief Unload the heightfield.
  */
  void                                        unload();

}; // class HeightField

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
