/** File: NxOgreXXX.h
    Created on: X-XXX-XX
    Author: Robin Southern "betajaen"
    SVN: $Id$

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

#ifndef NXOGRE_MATH_H
#define NXOGRE_MATH_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

namespace Functions
{

                                                                                       

/** \brief
*/
namespace Math
{
/*
    const Real PI;
    const Real HALF_PI;
    const Real TWO_PI;
    const Real INVERSE_PI;


#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
    const DoubleReal PI_DOUBLE;
    const DoubleReal HALF_PI_DOUBLE;
    const DoubleReal TWO_PI_DOUBLE;
    const DoubleReal INVERSE_PI_DOUBLE;
#endif
*/
   /** \brief Find the sine of an angle, in radians.
   */
   NxOgrePublicFunction  Real          sin(Real);

   /** \brief Fine the cosine of an angle, in radians.
   */
   NxOgrePublicFunction  Real          cos(Real);

   /** \brief Find both the sin and cos of an angle, in radians.
   */
   NxOgrePublicFunction  void          sinCos(Real a, Real& sine, Real& cosine);

   /** \brief Find the tangent of an angle, in randians.
   */
   NxOgrePublicFunction  Real          tan(Real);

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
   /** \brief Find the sine of an angle, in radians.
   */
   NxOgrePublicFunction  DoubleReal    sin(DoubleReal);
#endif

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
   /** \brief Find the sine of an angle, in radians.
   */
   NxOgrePublicFunction  DoubleReal    cos(DoubleReal);
#endif

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
   /** \brief Find the sine of an angle, in radians.
   */
   NxOgrePublicFunction  void          sinCos(DoubleReal a, DoubleReal& sin, DoubleReal& cosine);
#endif

  /** \brief Find the arcsine of an angle, in radians.
   */
   NxOgrePublicFunction  Real          asin(Real);

   /** \brief Fine the arccosine of an angle, in radians.
   */
   NxOgrePublicFunction  Real          acos(Real);

   /** \brief Find the arctangent of an angle, in randians.
   */
   NxOgrePublicFunction  Real          atan(Real);

   /** \brief Find the tangent of an angle, in randians.
   */
   NxOgrePublicFunction  Real          atan2(Real);


#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
   /** \brief Find the sine of an angle, in radians.
   */
   NxOgrePublicFunction  DoubleReal    tan(DoubleReal);
#endif

   /** \brief Perform a square root 
   */
   NxOgrePublicFunction  Real          sqrt(Real);

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
   /** \brief Perform a square root 
   */
   NxOgrePublicFunction  DoubleReal    sqrtDouble(DoubleReal);
#endif

   /** \brief Generate a random Real number between a and b.
   */
   NxOgrePublicFunction  Real          random(Real a, Real b);
   
   /** \brief Generate a random integer between a and b.
   */
   NxOgrePublicFunction  int           random(int a, int b);
   
   NxOgrePublicFunction  Real          abs(Real);

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
   /** \brief Perform a square root 
   */
   NxOgrePublicFunction  DoubleReal    abs(DoubleReal);
#endif

} // namespace Math

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
