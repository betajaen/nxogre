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

                                                                                       

#ifndef NXOGRE_FORCEFIELD_H
#define NXOGRE_FORCEFIELD_H


#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreForceFieldDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ForceField
*/
class NxOgrePublicClass ForceField
{

  public:

  /*! function. create
      desc.
          Create a ForceField
      args.
          const ForceFieldDescription& -- Description to use.
          ForceFieldKernel*  -- Kernel.
          Scene* -- Scene.
      note.
          This is to be used by class inheriting ForceField that doesn't use
          the normal constructor.
  */
  void create(const ForceFieldDescription&, ForceFieldKernel*, Scene* scene);

  /*! function. getName
      desc.
           Get the name of the Actor or *BLANK_STRING*
      return.
           String -- The name of the Actor
  */
  String  getName() const;

  /*! function. getName
      desc.
           Get the name of the Actor or *BLANK_STRING*
      return.
           String -- The name of the Actor
  */
  StringHash  getNameHash() const;

  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;

  protected: // Functions

  /*! constructor. ForceField
      desc.
          
  */
  ForceField(const ForceFieldDescription&, ForceFieldKernel*, Scene*);

  /*! constructor. Inheritance Constructor.
      desc.
           Classes that inherit from Actor should use this constructor.
      note.
          When using this constructor, call ForceField::create to create the ForceField.
  */
  ForceField(Scene*);

  /** \internal Use Scene::destroyActor
  */
  virtual ~ForceField();
  
  /*! function. destroy
      desc.
          Destroy the Forcefield manually.
      note.
          This function is to be used by classes that inherit by Forcefield only
  */
  void destroy();

  protected: // Variables
  
  /** \brief Name of the ForceField, otherwise a blank string.
  */
  String  mName;
  
  /** \brief Hash of the name of the ForceField, otherwise a BLANK_HASH.
  */
  StringHash  mNameHash;

  /** \brief ForceField's parent Scene
  */
  Scene*  mScene;
  
  /** \brief Kernel.
  */
  ForceFieldKernel*  mKernel;
  
  /** \brief ForceField
  */
  NxForceField*  mForceField;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
