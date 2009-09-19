/** File: NxOgreScenePrototype.h
    Created on: 6-Nov-08
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

#ifndef NXOGRE_SCENEPROTOTYPE_H
#define NXOGRE_SCENEPROTOTYPE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreSceneDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ScenePrototype : public SceneDescription, public PointerClass<::NxOgre::Classes::_ScenePrototype>
{
  
  public: // Functions

  /** \brief ScenePrototype constructor
  */
                                              ScenePrototype(void);
  
  /** \brief ScenePrototype destructor
  */
                                             ~ScenePrototype(void);
  
  /** \brief Reset the Scene to the most default values, with no Scenes.
  */
                        void                  reset(void);

  /** \brief Does the prototype's variables are in the range of acceptable values?
  */
                        bool                  valid(void);
  
      
  
}; // class ScenePrototype

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
