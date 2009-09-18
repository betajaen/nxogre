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
