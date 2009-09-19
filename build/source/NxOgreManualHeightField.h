/** File: NxOgreManualHeightField.h
    Created on: 22-Mar-09
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

#ifndef NXOGRE_MANUALHEIGHTFIELD_H
#define NXOGRE_MANUALHEIGHTFIELD_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class NxOgrePublicClass HeightFieldData : public PointerClass<Classes::_HeightFieldData>
{
 
 public:
 
  HeightFieldData();
 ~HeightFieldData();
 
  String                                     mName;
  Enums::Axis                                mAxis;
  unsigned int                               mNbRows;
  unsigned int                               mNbColumns;
  Array<HeightFieldSample>                   mSamples;
  Real                                       mThickness;
  Real                                       mVerticalExtent;
  Real                                       mConvexEdgeThreshold;
  bool                                       mNoEdgeBoundaries;
  
};

/** \brief
*/
class NxOgrePublicClass ManualHeightField
{
  
  friend class HeightField;
 
  public: // Functions
  
  /** \brief Text
  */
                                              ManualHeightField(void);
  
  /** \brief Text
  */
                                              ManualHeightField(const ManualHeightField& other);
  
  /** \brief Text
  */
                                             ~ManualHeightField(void);

  /** \brief Assignment operator
  */
  ManualHeightField&                          operator=(ManualHeightField& other);

  /** \brief Set the name of the heightfield, otherwise sequentially generate one.
  */
  void                                        name(const char* = 0);
    
  /** \brief Get the name of the heightfield.
  */
  String                                      name(void) const;

  /** \brief Text
  */
  void                                        clear(void);
  
  /** \brief Text
  */
  void                                        begin(unsigned int nbColumns, unsigned int nbRows, Enums::Axis upAxis = Enums::Y);
  
  /** \brief Where the current sample position is.
  */
  int2                                        location();
  
  /** \brief How large the heightfield is.
  */
  int2                                        size();
  
  /** \brief Add a heightfield sample, from the HeightField sample class.
  */
  void                                        sample(HeightFieldSample);
  
  /** \brief Add a heightfield sample, manually.
  */
  void                                        sample(short height, MaterialIdentifier mat0 = 0, MaterialIdentifier mat1 = 0, Enums::HeightFieldTesselation = Enums::HeightFieldTesselation_NE_SW);
  
  /** \brief Stop and create the heightfield, and load the HeightField into the HeightFieldManager
  */
  HeightField*                                end(const String& name);
  
  /** \brief Stop and create the heightfield to a Resource.
  */
  void                                        end(Resource*);
  
  /** \brief
  */
  bool                                        isValid(void);
  
  /** \brief Set the vertical extent of the heightfield
  */
  void                                        setVerticalExtent(Real);
  
  /** \brief Get the vertical extent of the heightfield
  */
  Real                                        getVerticalExtent(void);
  
  /** \brief Set the vertical extent of the convex edge threshold.
  */
  void                                        setConvexEdgeThreshold(Real);
  
  /** \brief Get the vertical extent of the convex edge threshold.
  */
  Real                                        getConvexEdgeThreshold(void) const;
  
  /** \brief Set it to disable collisions with height field with boundary edges.
  */
  void                                        setHasNoBoundaryEdges(bool);
  
  /** \brief Get if it to disable collisions with height field with boundary edges.
  */
  bool                                        getHasNoBoundaryEdges(void) const;

  protected: // Functions
  
  /** \internal Do not use.
  */
  NxHeightField*                              cook(void);
  
  protected: // Variables
  
  HeightFieldData*                      mHeightField;
  RefT*                                       mRef;
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
