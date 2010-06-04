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

                                                                                       

#ifndef NXOGRE_COMPARTMENT_H
#define NXOGRE_COMPARTMENT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"



                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Compartment
    desc.
         A compartment represents a sub-instance of one type of physics simulation,
         for example hardware fluid, hardware rigid body, or software rigid body. 
*/ 
class NxOgrePublicClass Compartment : public GenericBasedAllocatable
{
  
  public: // Functions
  
  /*! constructor. Compartment
      note.
           Use Scene::createCompartment
  */
                                              Compartment(const CompartmentDescription&, Scene*);
  
  /*! destructor. Compartment
  */
                                             ~Compartment();
  
  /*! function. getCompartment
      desc.
           Get's the NxCompartment
      return.
            **NxCompartment** * -- The NxCompartment.
      !physx
  */
  NxCompartment*                              getCompartment();

  /*! function. getType
      desc.
           Get the compartment type.
      return.
           **Enums::CompartmentType** -- The type of compartment
  */
  Enums::CompartmentType                      getType() const;
  
  /*! function. getDeviceCode
      desc.
           Get the device code of the compartment.
      return.
           **unsigned int** -- Device code.
  */
  unsigned int                                getDeviceCode() const;
  
  /*! function. getGridHashCellSize
      desc.
           Get the paging grid cell size
      return.
           **Real** -- Paging grid cell size.
  */
  Real                                        getGridHashCellSize() const;
  
  /*! function. getHashTablePower
      desc.
           Get the paging grid power.
      return.
           **unsigned int** -- paging grid power
  */
  unsigned int                                getGridHashTablePower() const;

  /*! function. getTimeScale
      desc.
           Get the time scale of the compartment.
      return.
           **Real** - Time scale of the compartment.
      see.
          Compartment::setTimeScale
  */
  Real                                        getTimeScale() const;
  
  /*! function. setTimeScale
      desc.
           Set the times scale for the compartment
      return.
           **Real** -- Time scale of the compartment
      see.
          Compartment::setTimeScale
  */
  void                                        setTimeScale(Real);
  
  /*! function. setTiming
      desc.
          Sets simulation timing parameters used to simulate the compartment.  
          
          The initial default settings are inherited from the primary scene.
          
          If method is TimeStepMethod_Fixed, elapsedTime(simulate() parameter) is internally subdivided into up to
          maxIter substeps no larger than maxTimestep.
          
          If elapsedTime is not a multiple of maxTimestep then any remaining time is accumulated 
          to be added onto the elapsedTime for the next time step.
          
          If more sub steps than maxIter are needed to advance the simulation by elapsed time, then
          the remaining time is also accumulated for the next call to simulate().
          
          The timestep method of TimeStepMethod_Fixed is strongly preferred for stable, reproducible simulation.
          
          Alternatively TimeStepMethod_Variable can be used, in this case the first two parameters
          are not used.	See also Enums::TimeStepMethod.
      args.
          Real __maxTimestep__ -- Maximum size of a substep; (0, inf)
          unsigned int __maxIter__ -- Maximum number of iterations to divide a timestep into.
          Enums::TimeStepMethod __method__ -- Method to use for timestep (either variable time step or fixed). See Enums::TimeStepMethod.
  */
  void                                        setTiming(Real maxTimeStep = _1_60, unsigned int max_iterator = 8, Enums::TimeStepMethod = Enums::TimeStepMethod_Fixed);
  
  /*! function. getTiming
      desc.
          Gets the simulation timing parameters.
      args.
          Real __maxTimestep__ -- Maximum size of a substep. <b>Range:</b> (0,inf)
          unsigned int __maxIter__ -- Maximum number of iterations to divide a timestep into.
          Enums::TimeStepMethod __method__ -- Method to use for timestep (either variable time step or fixed). See #NxTimeStepMethod.
          unsigned int& __numTimeSteps__
  */
  void                                        getTiming(Real& maxTimeStep, unsigned int &max_iterator, Enums::TimeStepMethod& method, unsigned int& __numTimeSteps__) const;
  
  /*! function. checkResults
      desc.
          This checks to see if the simulation of the objects in this compartment has completed.
          
          This does not cause the data available for reading to be updated with the results of the simulation, it is simply a status check.
          The bool will allow it to either return immediately or block waiting for the condition to be met so that it can return true
          
          bool __block__ -- When set to true will block until the condition is met.
      return.
          **bool** -- True if the results are available.
  */
  bool                                        checkResults(bool block = false);
  
  /*! function. fetchResults
      desc.
          This is the big brother to checkResults() it basically makes the results of the compartment's simulation readable.
          
          The entire scene including the compartments will still be locked for writing until you call fetchResults(NX_RIGID_BODY_FINISHED).
      args.
          bool __block__ -- When set to true will block until the condition is met.
      return.
          **bool** -- True if the results have been fetched.
  */
  bool                                        fetchResults(bool block = false);

  /*! function. setFlags
      desc.
           Set the compartment flags
      args.
           unsigned int __flags__ -- Compartment flags.
  */
  void                                        setFlags(unsigned int flags);
  
  /*! function. getFlags
      desc.
           Get the compartment flags
      return
           **unsigned int** -- Comparment flags.
  */
  unsigned int                                getFlags() const;

  /*! function. to_s
      desc.
          Returns the pointer as string and class type.
  */
  String to_s() const;
  
  protected:
  
                      Scene*                  mScene;

                      NxCompartment*          mCompartment;
  
}; // class Box

/*? class. CompartmentArrayPair
    desc.
         Compartments don't have a userData property. So Scene will store a copy
         of the compartment pointer and the representive pair. This isn't too efficent
         but hopefull you won't be fetching over billions of compartments every frame.
*/
struct CompartmentArrayPair
{
 /*? constructor. CompartmentArrayPair
     desc.
          Internal do not use.
 */
 CompartmentArrayPair()
 : mOriginal(0), mRepresentative(0) {}
 
 /*! constructor. CompartmentArrayPair
     desc.
          Internal do not use.
 */
 CompartmentArrayPair(NxCompartment* original, Compartment* representative)
 : mOriginal(original), mRepresentative(representative) {}
 
 NxCompartment* mOriginal;
 
 Compartment*   mRepresentative;
 
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
