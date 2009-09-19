/** File: NxOgreHeightFieldManager.h
    Created on: 27-Mar-09
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
