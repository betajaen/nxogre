/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2011 Robin Southern, http://github.com/betajaen/nxogre/
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

#include "NxOgreSceneIntegrator.h"
#include "NxPhysics.h"

namespace NxOgre
{
 
 // --------------------------------------------------

 FixedASyncSceneIntegrator::FixedASyncSceneIntegrator(NxScene* scene, Real maxTimeStep, int maxSubSteps)
 : mScene(scene), mMaxTimeStep(maxTimeStep), mMaxSubSteps(maxSubSteps)
 {
 }

 FixedASyncSceneIntegrator::~FixedASyncSceneIntegrator()
 {
 }
 
 void FixedASyncSceneIntegrator::advance()
 {
  
  advance(mTimer.nowSeconds());
  
 }
 
 void FixedASyncSceneIntegrator::advance(Real customDeltaTime)
 {
  
  mFrameTime = customDeltaTime;
  
  mScene->simulate(mFrameTime);
  mScene->flushStream();
  
  /*
     Calculate timestep and alpha here.
  */
  
  while(!mScene->checkResults(NX_RIGID_BODY_FINISHED, false))
  {
   // Callback for user waiting function?
  }
  mScene->fetchResults(NX_RIGID_BODY_FINISHED, true);
 }

 // --------------------------------------------------


} // namespace World
