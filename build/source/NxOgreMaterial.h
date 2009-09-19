/** File: NxOgreMaterial.h
    Created on: 13-Nov-08
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NXOGRE_MATERIAL_H
#define NXOGRE_MATERIAL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Material : public PointerClass<Classes::_Material>
{
  friend class Scene;
  friend class Functions::ArrayFunctions<Material*>::Write;

  public: // Functions
  
  /** \brief Text
  */
                          MaterialIdentifier  getIdentifier(void) const;
  /** \brief Text
  */
                          Real                getRestitution(void) const;
  
  /** \brief Text
  */
                          Real                getStaticFriction(void) const;
  
  /** \brief Text
  */
                          Real                getDynamicFriction(void) const;
  
  /** \brief Text
  */
                          void                setRestitution(Real);
  
  /** \brief Text
  */
                          void                setStaticFriction(Real);
  
  /** \brief Text
  */
                          void                setDynamicFriction(Real);
  
  protected: // Functions
  
  /** \internal
  */
                                              Material(NxMaterial*, Scene*);
  
  /** \internal
  */
                                              Material(MaterialPrototype*, Scene*);
  
  /** \internal
  */
                                             ~Material(void);
  
  /** \internal
  */
                           void               create(MaterialPrototype*);
  
  /** \internal
  */
                           void               destroy(void);
  
  protected: // Variables
  
                           Scene*             mScene;
                           NxMaterial*        mMaterial;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
