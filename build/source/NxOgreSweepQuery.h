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

                                                                                       

#ifndef NXOGRE_SWEEPQUERYHIT_H
#define NXOGRE_SWEEPQUERYHIT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
struct NxOgrePublicClass SweepQueryHit
{
  
  /** \brief Distance to hit expressed as a percentage of the source motion vector ([0,1] coeff)
  */
  float         mDistancePercentage;
  
  /** \brief Shape that was hit.
  */
  Shape*        mHitShape;
  
  /** \brief Shape that hits the hitShape
  */
  Shape*        mSweepShape;
  
  /** \brief ID of touched triangle (internal)
  */
  unsigned int  mInternalFaceID;
  
  /** \brief ID of touched triangle (external)
  */
  unsigned int  mFaceID;
  
  /** \brief World-space impact point
  */
  Vec3  mPoint;
  
  /** \brief World-space impact normal
  */
  Vec3  mNormal;
  
}; // class RaycastHit

class NxOgrePublicClass SweepCache : public GenericBasedAllocatable
{
 
 NXOGRE_GC_FRIEND_NEW1
 NXOGRE_GC_FRIEND_DELETE
 
 public:
  
  NxSweepCache* getCache();
  
 protected:
  
  SweepCache(NxSweepCache*);
  
  NxSweepCache* mCache;
  
};

namespace Functions
{

class SweepFunctions
{
 public:
  
  static void NxSweepQueryHitsToBuffer(NxSweepQueryHit*, unsigned int size, SweepQueryHits&);
  
};

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
