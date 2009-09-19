/** File: NxOgreMemoryDebugger.h
    Created on: 2-Nov-08
    Author: Robin Southern "betajaen"
    

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
