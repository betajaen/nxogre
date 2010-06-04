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

                                                                                       

#ifndef NXOGRE_FORCEFIELDLINEARKERNEL_H
#define NXOGRE_FORCEFIELDLINEARKERNEL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreForceFieldKernel.h"
#include "NxOgreForceFieldLinearKernelDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ForceFieldLinearKernelDescription
    desc.
        A Box is a cubiod shape that can be used in Actors, KinematicActors, StaticGeometries and Volumes for
        collisions and testing against them.
        
    see. Shape
*/ 
class NxOgrePublicClass ForceFieldLinearKernel : public ForceFieldKernel
{
  
  NXOGRE_GC_FRIEND_NEW2
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  unsigned int getShapeType() const;
  
  /*! function. getConstant
      desc.
           Gets the constant part of force field function. 
      return.
           **Vec3** -- The constant
  */
  Vec3  getConstant() const;
  
  /*! function. setConstant
      desc.
           Sets the constant part of force field function. 
      args.
           const Vec3& __constant__ -- New constant.
  */
  void  setConstant(const Vec3& constant);
  
  /*! function. getPositionMultiplier
      desc.
           Gets the coefficient of force field function position term. 
      return.
           **Vec3** -- The constant
  */
  Matrix33  getPositionMultiplier() const;
  
  /*! function. setSize
      desc.
           Sets the coefficient of force field function position term. 
      args.
           const Vec3& __constant__ -- New constant.
  */
  void  setPositionMultiplier(const Matrix33& constant);
  
  /*! function. getPositionTarget
      desc.
           Gets the force field position target. 
      return.
           **Vec3** -- The position target.
  */
  Vec3  getPositionTarget() const;
  
  /*! function. setPositionTarget
      desc.
           Sets the coefficient of force field function velocity term. 
      args.
           const Vec3& __positionTarget__ -- New constant.
  */
  void  setPositionTarget(const Vec3& positionTarget);
  
  /*! function. getPositionTarget
      desc.
           Gets the force field position target. 
      return.
           **Vec3** -- The position target.
  */
  Vec3  getVelocityTarget() const;
  
  /*! function. setPositionTarget
      desc.
           Sets the coefficient of force field function velocity term. 
      args.
           const Vec3& __velocityTarget__ -- New velocity target.
  */
  void  setVelocityTarget(const Vec3& velocityTarget);
  
  /*! function. getFalloffLinear
      desc.
           Gets the linear falloff term.
      return.
           **Vec3** -- The linear falloff.
  */
  Vec3  getFalloffLinear() const;
  
  /*! function. setFalloffLinear
      desc.
           Sets the linear falloff term. 
      args.
           const Vec3& __linearFalloff__ -- New linear falloff.
  */
  void  setFalloffLinear(const Vec3& linearFalloff);
  
  /*! function. getFalloffQuadratic
      desc.
           Gets the quadratic falloff term.
      return.
           **Vec3** -- The quadratic falloff.
  */
  Vec3  getFalloffQuadratic() const;
  
  /*! function. setFalloffQuadratic
      desc.
           Sets the quadratic falloff term. 
      args.
           const Vec3& __quadraticFalloff__ -- New quadratic falloff.
  */
  void  setFalloffQuadratic(const Vec3& quadraticFalloff);
  
  
  /*! function. saveToDescription
      desc.
          Save to a ForceFieldLinearKernelDescription
  */
  void saveToDescription(ForceFieldLinearKernelDescription&);
  
  /*! function. getNoise
      desc.
           Gets the force field noise. 
      return.
           **Vec3** -- The position target.
  */
  Vec3  getNoise() const;
  
  /*! function. setNoise
      desc.
           Sets the force field noise
      args.
           const Vec3& __noise__ -- New constant.
  */
  void  setNoise(const Vec3& noise);
  
  /*! function. getNoise
      desc.
           Gets the force field noise. 
      return.
           **Real** -- The position target.
  */
  Real  getTorusRadius() const;
  
  /*! function. setNoise
      desc.
           Sets the force field noise
      args.
           Real __torusRadius__ -- New constant.
  */
  void  setTorusRadius(Real torusRadius);
  
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  protected:
  
  /* constructor. Box
  */
  ForceFieldLinearKernel(const ForceFieldLinearKernelDescription&, Scene*);
  
  /* destructor. Box
  */
 ~ForceFieldLinearKernel();
  
  protected:
  
  NxForceFieldLinearKernel*  mKernel;
  
}; // class Box

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
