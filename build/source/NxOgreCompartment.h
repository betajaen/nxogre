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

#include "NxOgrePointerClass.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A compartment represents a sub-instance of one type of physics simulation,
           for example hardware fluid, hardware rigid body, or software rigid body. 
*/ 
class NxOgrePublicClass Compartment : public PointerClass<Classes::_Compartment>
{
  
  public: // Functions
  
  /** \brief Compartment constructor.
      \note  Use Scene::createCompartment
  */
                                              Compartment(const CompartmentDescription&, Scene*);
  
  /** \brief Compartment destructor.
  */
                                             ~Compartment(void);
  
  /** \brief
  */
  NxCompartment*                              getCompartment();

  /** \brief Get the compartment type.
  */
  Enums::CompartmentType                      getType() const;
  
  /** \brief
  */
  unsigned int                                getDeviceCode() const;
  
  /** \brief
  */
  Real                                        getGridHashCellSize() const;
  
  /** \brief
  */
  unsigned int                                getGridHashTablePower() const;

  /** \brief
  */
  Real                                        getTimeScale() const;
  
  /** \brief
  */
  void                                        setTimeScale(Real);
  
  /** \brief
  */
  void                                        setTiming(Real maxTimeStep = _1_60, unsigned int max_iterator = 8, Enums::TimeStepMethod = Enums::TimeStepMethod_Fixed);
  
  /** \brief
  */
  void                                        getTiming(Real& maxTimeStep, unsigned int &max_iterator, Enums::TimeStepMethod& method, unsigned int& num_time_steps) const;
  
  /** \brief
  */
  bool                                        checkResults(bool block = false);
  
  /** \brief
  */
  bool                                        fetchResults(bool block = false);

  /** \brief
  */
  void                                        setFlags(unsigned int flags);
  
  /** \brief
  */
  unsigned int                                getFlags() const;

  protected:
  
                      Scene*                  mScene;

                      NxCompartment*          mCompartment;
  
}; // class Box

/** \brief Compartments don't have a userData property. So Scene will store a copy
           of the compartment pointer and the representive pair. This isn't too efficent
           but hopefull you won't be fetching over billions of compartments every frame.
*/
struct CompartmentArrayPair
{
 CompartmentArrayPair()
 : mOriginal(0), mRepresentative(0) {}
 CompartmentArrayPair(NxCompartment* original, Compartment* representative)
 : mOriginal(original), mRepresentative(representative) {}
 NxCompartment* mOriginal;
 Compartment*   mRepresentative;
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
