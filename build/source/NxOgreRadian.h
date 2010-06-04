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

                                                                                       

#ifndef NXOGRE_RADIAN_H
#define NXOGRE_RADIAN_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class NxOgrePublicClass Radian
{
 public:
  
  inline Radian();
  
  inline Radian(Real radians);
  
  inline Radian(const Radian& other);
  
  inline Real    rad() const;

  inline Radian& operator=(const Real& other);
  
  inline const Radian operator+() const;
  
  inline Radian operator+(const Radian& other) const;
  
  inline Radian operator+(const Real& other) const;
  
  inline Radian& operator+=(const Radian& other);
  
  inline Radian& operator+=(const Real& other);
  
  inline Radian operator-() const;
  
  inline Radian operator-(const Radian& other) const;
  
  inline Radian operator-(const Real& other) const;
  
  inline Radian& operator-=(const Radian& other);
  
  inline Radian& operator-=(const Real& other);

  inline Radian operator*(const Radian& other) const;
  
  inline Radian operator*(const Real& other) const;

  inline Radian& operator*=(const Radian& other);
  
  inline Radian& operator*=(const Real& other);

  inline Radian operator/(const Radian& other) const;
  
  inline Radian operator/(const Real& other) const;

  inline Radian& operator/=(const Radian& other);
  
  inline Radian& operator/=(const Real& other);

  inline bool operator<(const Radian& other);

  inline bool operator<(const Real& other);

  inline bool operator<=(const Radian& other);

  inline bool operator<=(const Real& other);

  inline bool operator!=(const Radian& other);

  inline bool operator!=(const Real& other);

  inline bool operator==(const Radian& other);

  inline bool operator==(const Real& other);

  inline bool operator>=(const Radian& other);

  inline bool operator>=(const Real& other);

  inline bool operator>(const Radian& other);

  inline bool operator>(const Real& other);

  inline String to_s() const;
  
  inline operator Real() const;
  
  static const Radian ZERO;
  
 private:
  
  Real mRadian;
  
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
