/** File: NxOgreRaycastHit.h
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

#ifndef NXOGRE_RAYCASTHIT_H
#define NXOGRE_RAYCASTHIT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
struct NxOgrePublicClass RaycastHit
{
  /** \brief RigidBody of the Shape that was hit.
  */
  RigidBody*         mRigidBody;
  
  /** \brief Touched shape
  */
  Shape*             mShape;
  
  /** \brief Impact point in world space.
  */
  Vec3               mWorldImpact;
  
  /** \brief Impact normal in world space.
  */
  Vec3               mWorldNormal;
  
  /** \brief Index of touched face of the mesh (if it's a mesh).
  */
  unsigned int       mFaceID;
  
  /** \brief Internal faceID
  */
  unsigned int       mInternalFaceID;
  
  /** \brief Distance from the ray origin to the impact point
  */
  Real               mDistance;

  /** \brief Impact barycentric coordinates
  */
  Real               mU, mV;

  /** \brief Index of touched material.
  */
  MaterialIdentifier mMaterialIndex;

  /** \brief
  */
  unsigned int       mFlags;

}; // class RaycastHit


struct NxOgrePublicClass ClothRaycastHit
{
 /** \brief Did the ray hit the cloth?
 */
 bool mDidHit;
 
 /** \brief Where the ray hit the cloth, in world coordinates. 
 */
 Vec3 mWorldPosition;
 
 /** \brief The vertex nearest to the hit by the raycast
 */
 unsigned int mVertexId;

}; // class ClothRaycastHit

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
