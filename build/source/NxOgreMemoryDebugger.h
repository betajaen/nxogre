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

                                                                                       

#ifndef NXOGRE_MEMORYDEBUGGER_H
#define NXOGRE_MEMORYDEBUGGER_H

                                                                                       

#include "NxOgreStable.h"

#if (NxOgreMemoryDebugger == 1)

#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A MemoryAllocation is a note of one "piece" of memory that is currently allocated.
*/
struct NxOgrePublicClass MemoryAllocation
{
  void*         _Ptr;
  size_t        _Size;
  int           _Type;
  const char*   _File;
  unsigned int  _Line;
};

/** \brief The MemoryDebugger, it should not be used by mere mortals.
*/
class NxOgrePublicClass MemoryDebugger
{
  public:
    
    public:
    
    typedef MemoryAllocation Vt;
    typedef Vt* VtIterator;
    
    MemoryDebugger(void);
   ~MemoryDebugger(void);
    
    void*         addAllocation(void*, size_t, unsigned int, const char*, unsigned int);
    void          removeAllocation(void*);
    void          changeAllocation(void*, void*, size_t);
    void          allowCleanups(bool);
    unsigned int  getOverhead(void);
    void          clean(void);
    // Prints leaks to a file.
    void          writeAllocationsToFile(const char* filename = NxOgre_Stringify(NXOGRE_MEMORY_DEBUGGER_FILE));


   private:
    
    unsigned int _size() const;
    unsigned int _capacity() const;
    void _clear();
    void _copy(VtIterator begin, VtIterator end, VtIterator dest);
    void _clip(unsigned int size);
    void _reserve(unsigned int new_size);
    void _resize(unsigned int new_size);
    void _range_destruct(VtIterator begin, VtIterator end);
    
  protected:
    
    VtIterator   _First, _Last, _End;
    bool         _CleanAllowed;
    bool         _EverythingIsOkayAlarm;
    
}; // class MemoryDebugger

                                                                                       

} // namespace NxOgre


                                                                                       

#endif
#endif
