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

                                                                                       

#ifndef NXOGRE_MANUALHEIGHTFIELD_H
#define NXOGRE_MANUALHEIGHTFIELD_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class NxOgrePublicClass HeightFieldData : public ResourceAllocatable
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
