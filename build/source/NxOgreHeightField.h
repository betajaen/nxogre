/** File: NxOgreHeightField.h
    Created on: 17-Mar-09
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

#ifndef NXOGRE_HEIGHTFIELD_H
#define NXOGRE_HEIGHTFIELD_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreHeightFieldSample.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass HeightField
{
  
  friend class ManualHeightField;
  
  public: // Functions
  
  /** \brief HeightField constructor
  */
                                              HeightField();
  
  /** \brief HeightField constructor, equilvent of calling load(uri);
  */
                                              HeightField(Resource*);
  
  /** \brief Text
  */
                                             ~HeightField(void);
  
  /** \brief Set the name of this HeightField
  */
  void                                        setName(const char*);
  
  /** \brief Set the name of this HeightField
  */
  void                                        setName(const String&);
  
  /** \brief Get the name of this heightfield.
  */
  String                                getName() const;
  
  /** \brief Is the shape loaded?
  */
  bool                                        isLoaded(void) const;
  
  /** \brief Is a shape(s) using this heightfield?
  */
  bool                                        isUsed(void) const;
  
  /** \brief Load a heightfield.
  */
  void                                        load(Resource*);
  
  /** \brief Get the NxHeightfield pointer.
  */
  NxHeightField*                              getHeightField(void);

 protected:
  
  /** \brief Protected Constructor, for use with ManualHeightField
  */
                                              HeightField(const String& name, NxHeightField*);

  NxHeightField*                              mHeightField;
  
  String                                mName;
  
}; // class HeightField

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
