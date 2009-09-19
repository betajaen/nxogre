/** File: NxOgreKinematiController.h
    Created on: 22-Nov-08
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

#ifndef NXOGRE_KINEMATICCONTROLLER_H
#define NXOGRE_KINEMATICCONTROLLER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreRigidBody.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass KinematicController : public PointerClass<Classes::_KinematicController>, public RigidBody
{
  
  friend class Scene;
  friend class Functions::ArrayFunctions<KinematicController*>::Write;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_KinematicController>::operator new;

  using ::NxOgre::PointerClass<Classes::_KinematicController>::operator delete;

  using ::NxOgre::PointerClass<Classes::_KinematicController>::getClassType;

  /** \brief Text
  */
  unsigned int                                move(const Vec3&);
  
  /** \brief
  */
  Vec3                                       getPosition(void) const;
  
  protected: // Functions
  
  /** \brief Box based controller.
  */
                                              KinematicController(const Vec3& size, const Vec3& globalPosition, Scene*);
  
  /** \brief Controller destructor.
  */
                                             ~KinematicController(void);
  
  /** \brief
  */
  unsigned int                                sweep(const Vec3& direction, bool walkExperiment, bool &nonWalkable);
  
  /** \brief
  */
  bool                                        sweepTest(const Vec3& direction, unsigned int &nbCollisions, bool isTest, bool normaliseResponse = false);
  
  /** \brief
  */
  void                                        sweepCollisionResponse(Vec3& target, const Vec3& current, const NxVec3& dir, const NxVec3& normal, bool normalise = false);
  
  
  protected: // Variables
  
  /** \brief
  */
                  SimpleBox*                  mVolume;
  
  /** \brief
  */
                    Scene*                    mScene;
  
  /** \brief
  */
                    Shapes                    mShapes;

  /** \brief Max Iterations per move.
      \default 10
  */
                    unsigned int              mMaxIter;
  
  /** \brief Up direction; 0 - X, 1 - Y, 2 -Z
      \default 1
  */
                    unsigned int              mUpDirection;

  /** \brief
  */
                    NxSweepCache*             mCache;

  /** \brief
  */
                    DoubleReal                mSkinWidth;

  /** \brief
  */
                    Vec3               mPosition;
  
  /** \brief
  */
                    Vec3               mFilteredPosition;
  
  /** \brief
  */
                    DoubleReal                mSharpness;
  
  /** \brief
  */
                    DoubleReal                mMinDistance;

  /** \brief
      \default 0
  */
                    DoubleReal                mCollisionResponseBump;

  /** \brief
      \default 1.0
  */
                    DoubleReal                mCollisionResponseFriction;

  /** \brief
  */
                    DoubleReal                mHalfHeight;

  /** \brief
  */
                    DoubleReal                mStepOffset;

  /** \brief
  */
                    bool                      mHandleSlope;

  /** \brief
  */
                    DoubleReal                mSlopeLimit;

  /** \brief
  */
                    bool                      mConstrainClimbing;

  /** \brief Sweep cache bounding box modifier.
      \default 1.5
      \range 1 to inf
  */
                    Real                      mCacheModifier;

  /** \brief
  */
                    DoubleReal                mContactPointHeight;

  /** \brief
  */
                    Shape*                    mShape;

}; // class KinematicController

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
