/** File: NxOgreVisualDebuggerMeshData.h
    Created on: 5-June-09
    Author: Robin Southern "betajaen"
    SVN: $Id$

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

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass VisualDebuggerMeshData
{
  
  friend class VisualDebugger;
  
  public: // Functions
  
  struct DebugPoint
  {
   Vec3         mPosition;
   unsigned int mColour;
  };
  
  struct DebugLine
  {
   Vec3         mPosition0;
   Vec3         mPosition1;
   unsigned int mColour;
  };
  
  struct DebugTriangle
  {
   Vec3         mPosition0;
   Vec3         mPosition1;
   Vec3         mPosition2;
   unsigned int mColour;
  };
  
  public: // Functions
  
  /** \brief Constructor
  */
                                              VisualDebuggerMeshData(void);
  
  /** \brief Destructor
  */
                                             ~VisualDebuggerMeshData(void);
  
  /** \brief Get Debug Points
  */
  DebugPoint*                                 getPoints(void);
  
  /** \brief Get Debug Lines.
  */
  DebugLine*                                  getLines(void);
  
  /** \brief Get Debug Triangles.
  */
  DebugTriangle*                              getTriangles(void);
  
  /** \brief Get number of debug points
  */
  unsigned int                                getNbPoints(void) const;
  
  /** \brief Get number of debug lines
  */
  unsigned int                                getNbLines(void) const;
  
  /** \brief Get number of debug triangles
  */
  unsigned int                                getNbTriangles(void) const;

  protected: // Variables
  
  NxOgre::Buffer<DebugPoint>                  mPoints;
  
  NxOgre::Buffer<DebugLine>                   mLines;
  
  NxOgre::Buffer<DebugTriangle>               mTriangles;
  
  unsigned int                                mNbPoints;
  
  unsigned int                                mNbLines;
  
  unsigned int                                mNbTriangles;

}; // class ClassName

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
