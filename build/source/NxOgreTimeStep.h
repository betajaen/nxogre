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

                                                                                       

#ifndef NXOGRE_TIMESTEP_H
#define NXOGRE_TIMESTEP_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class Scene;
class FixedSceneTimer;

/*! class TimeStep.
    desc.
        Abstract/User class for handling Time Stepping.
*/
class NxOgrePublicClass TimeStep
{
  
  public: // Variables
  
  /*! constructor. TimeStep
  */
  TimeStep(Scene*);
  
  /*! destructor. TimeStep
  */
  virtual ~TimeStep();

  /*! function. calculate
      desc.
          Calculate the true timestep based of the actual seconds passed.
  */
  void         calculate(float deltaTime);
  
  /*! function. getMaxTimeStep
      desc.
          Get the maximum amount of time possible that can be simulated in a single timestep.
  */
  float        getMaxTimeStep() const;

  /*! function. getSubSteps
      desc.
          Get the number of sub-steps
  */
  unsigned int getSubSteps() const;
  
  /*! function. getMaxIterator
      desc.
          Get the maximum iterator per timestep.
  */
  unsigned int getMaxIterator() const;
  
  /*! function. getAlpha
      desc.
          Get alpha interpolation value
  */
  float        getAlpha() const;
  
  /*! function. getModified
      desc.
          Get the actual deltaTime used by PhysX
  */
  float        getModified() const;
  
  /*! function. getAccumulator
      desc.
          Get the time carried over from the previous timestep.
  */
  float        getAccumulator() const;
  
  /*! function. getActual
      desc.
          Get the time given by the user from TimeStep::calculate.
  */
  float        getActual() const;
  
  /*! function. isFixed
      desc.
          Is the time controller fixed?
  */
  bool         isFixed() const;

  protected:
  
  float        mActual;
  float        mMaxTimeStep;
  unsigned int mSubSteps;
  unsigned int mMaxIterator;
  float        mAlpha;
  float        mModified;
  float        mAccumulator;
  int          mMethod;

}; // class TimeStep

/*! class. FixedTimeStep
    desc.
        TimeStep for the FixedTimeController
*/
class NxOgrePublicClass FixedTimeStep : public TimeStep
{
 
 public:
  
  FixedTimeStep(Scene*);
  
  void         calculate(float deltaTime);
  
 protected:
  
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
