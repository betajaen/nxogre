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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreSweepQuery.h"

#include "NxScene.h"
#include "NxShape.h"

                                                                                       

namespace NxOgre
{

SweepCache::SweepCache(NxSweepCache* cache)
: mCache(cache)
{
}

NxSweepCache* SweepCache::getCache()
{
 return mCache;
}

namespace Functions
{

void SweepFunctions::NxSweepQueryHitsToBuffer(NxSweepQueryHit* hits, unsigned int size, SweepQueryHits& buffer)
{
 buffer.remove_all();
 buffer.resize(size);
 for (unsigned int i=0; i < size; i++)
 {
  SweepQueryHit hit;
  hit.mDistancePercentage = hits[i].t;
  hit.mFaceID = hits[i].faceID;
  hit.mHitShape = pointer_representive_cast<Shape>(hits[i].hitShape->userData);
  hit.mInternalFaceID = hits[i].internalFaceID;
  hit.mNormal.from<NxVec3>(hits[i].normal);
  hit.mPoint.from<NxVec3>(hits[i].point);
  hit.mSweepShape = pointer_representive_cast<Shape>(hits[i].sweepShape->userData);
  buffer.push_back(hit);
 }
 
}

} // namespace Functions
} // namespace NxOgre

                                                                                       
