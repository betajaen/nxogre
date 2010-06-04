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

                                                                                       

#ifndef NXOGRE_MATERIAL_H
#define NXOGRE_MATERIAL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Material
*/
class NxOgrePublicClass Material : public GenericBasedAllocatable
{
  
  NXOGRE_GC_FRIEND_NEW2
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  /*! function. getNameHash
      desc.
          Get the material's name.
      note.
          Don't be confused with the getIdentifier function. MaterialIdentifier's are used internally in PhysX to reference
          materials. Where as Names are used externally to reference a material; also materials can go without names but
          not MaterialIdentifiers.
      return.
          **String** -- The material's name
  */
  String  getName() const;

  /*! function. getNameHash
      desc.
          Get the hash of the material's name.
      note.
          Don't be confused with the getIdentifier function. MaterialIdentifier's are used internally in PhysX to reference
          materials. Where as Names are used externally to reference a material; also materials can go without names but
          not MaterialIdentifiers.
      return.
          **StringHash** -- The material's hashed name
  */
  StringHash getNameHash() const;

  /*! function. getIdentifier
      desc.
          Get the internal material identifier (unsigned short) used internally within PhysX to reference a material used
          in shapes and meshes.
      return.
          **MaterialIdentifier** -- The material's identifier.
  */
  MaterialIdentifier  getIdentifier() const;
  
  /*! function. getRestitution
      desc.
          Text
  */
  Real  getRestitution() const;
  
  /** \brief Text
  */
  Real  getStaticFriction() const;
  
  /** \brief Text
  */
  Real  getDynamicFriction() const;
  
  /** \brief Text
  */
  void  setRestitution(Real);
  
  /** \brief Text
  */
  void  setStaticFriction(Real);
  
  /** \brief Text
  */
  void  setDynamicFriction(Real);
  
  /** \brief Text
  */
  void  setAll(Real restitution, Real staticFriction, Real dynamicFriction);

  protected: // Functions
  
  /** \internal
  */
  Material(NxMaterial*, Scene*);
  
  /** \internal
  */
  Material(const MaterialDescription&, Scene*);
  
  /** \internal
  */
  ~Material();
  
  /** \internal
  */
  void  create(const MaterialDescription&);
  
  /** \internal
  */
  void  destroy();
  
  protected: // Variables
  
  Scene*  mScene;
  
  NxMaterial*  mMaterial;
  
  String  mName;
  
  StringHash mNameHash;
  
}; // class Material

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
