/** File: NxOgreCompartment.h
    Created on: 11-Aug-09
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
