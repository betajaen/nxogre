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
#include "NxOgreWorldDescription.h"

namespace NxOgre
{

WorldDescription::WorldDescription()
{
 reset();
}

} // namespace NxOgre


// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

WorldDescription::WorldDescription(const WorldDescription& other)
{
 other.copy_into(this);
}

WorldDescription& WorldDescription::operator=(const WorldDescription& other)
{
 other.copy_into(this);
 return *this;
}

WorldDescription* WorldDescription::duplicate() const
{
 WorldDescription* dup = new WorldDescription();
 copy_into(dup);
 return dup;
}

void WorldDescription::copy_into(WorldDescription* other) const
{
 other->mAssertionResponse = mAssertionResponse;
 other->mCookerThreadMask = mCookerThreadMask;
 other->mHardwareMaximumConvex = mHardwareMaximumConvex;
 other->mHardwareMaximumPage = mHardwareMaximumPage;
 other->mNoHardware = mNoHardware;
}

void WorldDescription::reset()
{
 mAssertionResponse = Enums::PhysXAssertion_Continue;
 mCookerThreadMask = 0;
 mHardwareMaximumConvex = 2048;
 mHardwareMaximumPage = 256;
 mNoHardware = false;
}

bool WorldDescription::valid() const
{
 // mHardwareMaximumConvex must be a power of 2
 if ((mHardwareMaximumConvex & (mHardwareMaximumConvex - 1)))
  return false;
 // mHardwareMaximumPage must be a power of 2
 if ((mHardwareMaximumPage & (mHardwareMaximumPage - 1)))
  return false;

 return true;
}

void WorldDescription::inspect() const
{
 std::cout << "WorldDescription => {\n";
 std::cout << "  mAssertionResponse => '" << mAssertionResponse << "'\n";
 std::cout << "  mCookerThreadMask => '" << mCookerThreadMask << "'\n";
 std::cout << "  mHardwareMaximumConvex => '" << mHardwareMaximumConvex << "'\n";
 std::cout << "  mHardwareMaximumPage => '" << mHardwareMaximumPage << "'\n";
 std::cout << "  mNoHardware => '" << mNoHardware << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "WorldDescription-c13960d86c98f541e399d9182795dca9"

