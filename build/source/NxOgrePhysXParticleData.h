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

                                                                                       

#ifndef NXOGRE_PHYSXPARTICLEDATA_H
#define NXOGRE_PHYSXPARTICLEDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass PhysXParticleData : public NxOgre::PointerClass<Classes::_PhysXParticleData>
{
  
  public: // Functions
  
  /** \brief Text
  */
  PhysXParticleData(Fluid*, size_t modifier = 2);
  
  /** \brief Text
  */
 ~PhysXParticleData(void);
  
  /** \internal Do not use in User App.
  */
  NxParticleData           getParticleData();
  
  /** \brief
  */
  float*                   getPositions();
  
  /** \brief
  */
  float*                   getVelocities();
  
  /** \brief
  */
  float*                   getLives();
  
  /** \brief
  */
  float*                   getDensities();
  
  /** \brief
  */
  unsigned int*            getIds();
   
  /** \brief
  */
  unsigned int*            getFlags();
   
  /** \brief
  */
  float*                   getNormals();
  
  protected: // Functions
  
  void                     _configure(size_t maxParticles);
  
  protected: // Variables
  
  unsigned int*            mNbParticles;
  
  Buffer<float>            mPositions;
  
  Buffer<float>            mVelocities;
  
  Buffer<float>            mDensities;
  
  Buffer<float>            mLives;
  
  Buffer<unsigned int>     mIds;
  
  Buffer<unsigned int>     mFlags;
  
  Buffer<float>            mNormals;
  
}; // class PhysXParticleData


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
