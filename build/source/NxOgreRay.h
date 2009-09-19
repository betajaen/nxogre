/** File: NxOgreRay.h
    Created on: 19-Apr-09
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

#ifndef NXOGRE_RAY_H
#define NXOGRE_RAY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Ray
{
  
  
  public: // Functions
  
  /** \brief Constructor with 0,0,0 as Origin and 1,0,0 as Direction.
  */
                                              Ray(void);
  
  /** \brief Alternate Constructor.
  */
                                              Ray(const Vec3& origin, const Vec3& direction);
  
  /** \brief Destructor.
  */
                                             ~Ray(void);
  
  public: // Variables
  
  /** \brief The origin in global coordinates of the ray.
  */
                                              Vec3 mOrigin;
  
  /** \brief The normalised direction of the ray.
  */
                                              Vec3 mDirection;
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
