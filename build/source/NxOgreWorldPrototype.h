/** File: NxOgreWorldPrototype.h
    Created on: 02-Nov-08
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
