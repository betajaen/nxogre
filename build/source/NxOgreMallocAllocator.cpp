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
#include "NxOgreMallocAllocator.h"

#include <string>
#include <map>
#include <fstream>

                                                                                       

namespace NxOgre
{

                                                                                       

#ifdef NXOGRE_MEMORY_DEBUGGER_USEFILE

std::ofstream s;

struct TrackingAllocator
{
 struct Allocation
 {
  Allocation(void* ptr, size_t size, const char* file, unsigned int line)
  : mPtr(ptr), mSize(size), mLine(line)
  {
   if (file)
   {
    std::string fs(file);
    size_t n = fs.find_last_of('\\');
    
    if (n == std::string::npos)
     n = fs.find_last_of('/');
    
    if (n != std::string::npos)
     mFile = fs.substr(n+1);
    else
     mFile = fs;
   } 
   
  }
  
  void*        mPtr;
  size_t       mSize;
  std::string  mFile;
  unsigned int mLine;
 };

 TrackingAllocator()
 { s.open(NxOgre_Stringify(NXOGRE_MEMORY_DEBUGGER_FILE)); }
 
 ~TrackingAllocator()
 {
  s << "---------------------------------------------\n";
  if (mAllocations.size())
  {
   for (std::map<void*, Allocation>::iterator i = mAllocations.begin(); i != mAllocations.end(); i++)
     s << "LEAK:" << (*i).second.mPtr << " => " << (*i).second.mSize << " b,  from " << (*i).second.mFile << ":" << (*i).second.mLine << "\n";
  }
  else
  {
   s << "No leaks reported.";
  }
  s.flush();
  s.close();
 }
 
 void pushMem(void* ptr, size_t length, const char* file, unsigned int line)
 {
  Allocation allocation(ptr, length, file, line);
  s << "ALLOCATED:" << ptr << " => " << length << " b,  from " << (file != 0 ? allocation.mFile : "?") << ":" << line << "\n";
  s.flush();
  mAllocations.insert(std::pair<void*, Allocation>(ptr, allocation));
 }
 
 void popMem(void* ptr)
 {
  s << "UNALLOCATED: " << ptr << " => ";
  std::map<void*, Allocation>::iterator i = mAllocations.find(ptr);
  if (i != mAllocations.end())
  {
   s << (*i).second.mSize << " b,  from " << (*i).second.mFile << ":" << (*i).second.mLine << "\n";
   mAllocations.erase(i);
  }
  else
   s << "\n";
  s.flush();
 }
 
 std::map<void*, Allocation> mAllocations;
 
} gTrackingAllocator;

#endif

#ifdef NXOGRE_DEBUG
void* MallocAllocator::allocateBytes(size_t length, const char* file, unsigned int line)
#else
void* MallocAllocator::allocateBytes(size_t length)
#endif
{
 
 void* ptr = malloc(length);
 
 #ifdef NXOGRE_MEMORY_DEBUGGER_USEFILE
 #ifdef NXOGRE_DEBUG
  gTrackingAllocator.pushMem(ptr, length, file, line);
 #endif
 #endif
 return ptr;
 
}


void* MallocAllocator::reallocateBytes(void* memory, size_t newLength)
{
 
 void* newPtr = realloc(memory, newLength);
 
 #ifdef NXOGRE_MEMORY_DEBUGGER_USEFILE
  gTrackingAllocator.popMem(memory);
  gTrackingAllocator.pushMem(newPtr, newLength, 0, 0);
 #endif
 
 return newPtr;
}

void MallocAllocator::deallocateBytes(void* memory)
{
 
 if (memory == 0)
  return;
 
 free(memory);
 
 #ifdef NXOGRE_MEMORY_DEBUGGER_USEFILE
  gTrackingAllocator.popMem(memory);
 #endif
 
}

                                                                                       

} // namespace NxOgre

                                                                                       
