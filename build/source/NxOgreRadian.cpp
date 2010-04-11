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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreRadian.h"

                                                                                       

namespace NxOgre
{

                                                                                       

const NxOgre::Radian NxOgre::Radian::ZERO(0.0f);

Radian::Radian()
: mRadian(ZERO.mRadian)
{
}


Radian::Radian(Real radians)
: mRadian(radians)
{
}

Radian::Radian(const Radian& other)
: mRadian(other.mRadian)
{
}

Real Radian::rad()
{
 return mRadian;
}

Radian& Radian::operator=(const Real& other)
{
 mRadian = other;
 return *this;
}

const Radian Radian::operator+() const
{
 return *this;
}

Radian Radian::operator+(const Radian& other) const
{
 return Radian(mRadian + other.mRadian);
}

Radian Radian::operator+(const Real& other) const
{
 return Radian(mRadian + other);
}

Radian& Radian::operator+=(const Radian& other)
{
 mRadian += other.mRadian;
 return *this;
}

Radian& Radian::operator+=(const Real& other)
{
 mRadian += other;
 return *this;
}

Radian Radian::operator-() const
{
 return Radian(-mRadian);
}

Radian Radian::operator-(const Radian& other) const
{
 return Radian(mRadian - other.mRadian);
}

Radian Radian::operator-(const Real& other) const
{
 return Radian(mRadian - other);
}

Radian& Radian::operator-=(const Radian& other)
{
 mRadian -= other.mRadian;
 return *this;
}

Radian& Radian::operator-=(const Real& other)
{
 mRadian -= other;
 return *this;
}

Radian Radian::operator*(const Radian& other) const
{
 return Radian(mRadian * other);
}

Radian Radian::operator*(const Real& other) const
{
 return Radian(mRadian * other);
}

Radian& Radian::operator*=(const Radian& other)
{
 mRadian *= other.mRadian;
 return *this;
}

Radian& Radian::operator*=(const Real& other)
{
 mRadian *= other;
 return *this;
}

Radian Radian::operator/(const Radian& other) const
{
 return Radian(mRadian / other.mRadian);
}

Radian Radian::operator/(const Real& other) const
{
 return Radian(mRadian / other);
}

Radian& Radian::operator/=(const Radian& other)
{
 mRadian /= other.mRadian;
 return *this;
}

Radian& Radian::operator/=(const Real& other)
{
 mRadian /= other;
 return *this;
}

bool Radian::operator<(const Radian& other)
{
 return mRadian < other.mRadian;
}

bool Radian::operator<(const Real& other)
{
 return mRadian < other;
}

bool Radian::operator<=(const Radian& other)
{
 return mRadian <= other.mRadian;
}

bool Radian::operator<=(const Real& other)
{
 return mRadian <= other;
}

bool Radian::operator!=(const Radian& other)
{
 return mRadian != other.mRadian;
}

bool Radian::operator!=(const Real& other)
{
 return mRadian != other;
}

bool Radian::operator==(const Radian& other)
{
 return mRadian == other.mRadian;
}

bool Radian::operator==(const Real& other)
{
 return mRadian == other;
}

bool Radian::operator>=(const Radian& other)
{
 return mRadian >= other.mRadian;
}

bool Radian::operator>=(const Real& other)
{
 return mRadian >= other;
}

bool Radian::operator>(const Radian& other)
{
 return mRadian >= other.mRadian;
}

bool Radian::operator>(const Real& other)
{
 return mRadian >= other;
}

String Radian::to_s() const
{
 std::ostringstream ss;
 ss << mRadian;
 return ss.str();
}

Radian::operator Real() const
{
 return mRadian;
}

                                                                                       

} // namespace NxOgre

                                                                                       
