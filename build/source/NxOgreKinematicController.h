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
