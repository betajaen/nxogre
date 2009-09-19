/** File: NxOgreVisualDebuggerMeshData.h
    Created on: 5-June-09
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

#ifndef NXOGRE_VISUALDEBUGGERMESHDATA_H
#define NXOGRE_VISUALDEBUGGERMESHDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass VisualDebuggerMeshData
{
  
  friend class VisualDebugger;
  
  public: // Functions
  
  
  public: // Functions
  
  /** \brief Constructor
  */
                                              VisualDebuggerMeshData(void);
  
  /** \brief Destructor
  */
                                             ~VisualDebuggerMeshData(void);
  
  /** \brief Get Debug Lines.
  */
  float*                                      getLines(void);

  /** \brief Get Debug colours
  */
  unsigned int*                               getColours(void);

    /** \brief Get number of debug lines
  */
  unsigned int                                getNbLines(void) const;
  
  protected: // Variables
  
  unsigned int                                mNbLines;
  
  NxOgre::Buffer<float>                       mLines;
  
  NxOgre::Buffer<unsigned int>                mColours;
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
