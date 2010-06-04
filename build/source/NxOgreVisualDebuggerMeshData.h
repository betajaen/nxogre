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

                                                                                       

#ifndef NXOGRE_VISUALDEBUGGERMESHDATA_H
#define NXOGRE_VISUALDEBUGGERMESHDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass VisualDebuggerMeshData : public GenericBasedAllocatable
{
  
  friend class VisualDebugger;
  
  public: // Functions
  
  
  public: // Functions
  
  /** \brief Constructor
  */
                                              VisualDebuggerMeshData();
  
  /** \brief Destructor
  */
                                             ~VisualDebuggerMeshData();
  
  /** \brief Get Debug Lines.
  */
  float*                                      getLines();

  /** \brief Get Debug colours
  */
  unsigned int*                               getColours();

    /** \brief Get number of debug lines
  */
  unsigned int                                getNbLines() const;
  
  protected: // Variables
  
  unsigned int                                mNbLines;
  
  NxOgre::buffer<float>                       mLines;
  
  NxOgre::buffer<unsigned int>                mColours;
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
