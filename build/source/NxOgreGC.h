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

                                                                                       

#ifndef NXOGRE_GC_H
#define NXOGRE_GC_H

#include "NxOgreConfiguration.h"
#include "NxOgreType2Id.h"

                                                                                       

namespace NxOgre
{

                                                                                       

typedef unsigned char Byte;

                                                                                       

namespace GC
{

                                                                                       

#define NXOGRE_GC_THIS  __FILE__, __LINE__

#define NXOGRE_GC_FRIEND_DELETE template<class T> friend inline void ::NxOgre::GC::safe_delete(T*,const char*,int);
#define NXOGRE_GC_FRIEND_NEW0 template<class T> friend inline T* ::NxOgre::GC::safe_new0(const char*,int);
#define NXOGRE_GC_FRIEND_NEW1 template<class T, typename A1> friend inline T* ::NxOgre::GC::safe_new1(const A1&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW2 template<class T, typename A1, typename A2> friend inline T* ::NxOgre::GC::safe_new2(const A1&,const A2&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW3 template<class T, typename A1, typename A2, typename A3> friend inline T* ::NxOgre::GC::safe_new3(const A1&,const A2&,const A3&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW4 template<class T, typename A1, typename A2, typename A3, typename A4> friend inline T* ::NxOgre::GC::safe_new4(const A1&,const A2&,const A3&,const A4&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW5 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5> friend inline T* ::NxOgre::GC::safe_new5(const A1&,const A2&,const A3&,const A4&,const A5&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW6 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> friend inline T* ::NxOgre::GC::safe_new6(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW7 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> friend inline T* ::NxOgre::GC::safe_new7(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const A7&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW8 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8> friend inline T* ::NxOgre::GC::safe_new8(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const A7&,const A8&,const char*,int);

#if NXOGRE_DEBUG_MEMORY == 1
void NxOgrePublicFunction gc_debugger_push_ptr(void* ptr, unsigned int size, const char* type, const char* file, unsigned int line);
void NxOgrePublicFunction gc_debugger_change_ptr(void* old_ptr, void*  new_ptr, unsigned int new_size, const char* file, unsigned int line);
void NxOgrePublicFunction gc_debugger_pop_ptr(void* ptr, const char* file, unsigned int line);
void NxOgrePublicFunction gc_debugger_first_frame();
void NxOgrePublicFunction gc_debugger_frame(unsigned int id, float time);
void NxOgrePublicFunction gc_debugger_last_frame();
#endif

template<typename T, typename AX> inline T* safe_malloc(size_t bytes, const char* file, unsigned line)
{
 T* mem = (T*) AX::allocateBytes(bytes);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(mem, bytes, type2id<T>::type_name(), file, line);
#endif
 return mem;
}

template<typename T, typename AX> inline T* safe_malloc(size_t bytes, const char* type, const char* file, unsigned line)
{
 T* mem = (T*) AX::allocateBytes(bytes);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(mem, bytes, type, file, line);
#endif
 return mem;
}

template<typename T, typename AX> inline T* safe_realloc(T* mem, size_t new_size, const char* file, unsigned line)
{
 T* new_mem = (T*) AX::reallocateBytes(mem, new_size);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_change_ptr(mem, new_mem, new_size, file, line);
#endif
 return new_mem;
}

template<typename T, typename AX> inline void safe_free(T* mem, const char* file, unsigned line)
{
 if (mem == 0)
  return;
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_pop_ptr(mem, file, line);
#endif
 AX::deallocateBytes(mem);
}

template<typename T> inline T* safe_new0(const char* file, int line)
{
 T* ptr = new T();
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX> inline T* safe_allocated_new0(const char* file, int line)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T();
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1> inline T* safe_new1(const A1& v1, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1> inline T* safe_allocated_new1(const A1& v1, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2> inline T* safe_new2(const A1& v1, const A2& v2, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2> inline T* safe_allocated_new2(const A1& v1, const A2& v2, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3> inline T* safe_new3(const A1& v1, const A2& v2, const A3& v3, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3> inline T* safe_allocated_new3(const A1& v1, const A2& v2, const A3& v3, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4> inline T* safe_new4(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4> inline T* safe_allocated_new4(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5> inline T* safe_new5(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4, v5);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5> inline T* safe_allocated_new5(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4, v5);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> inline T* safe_new6(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4, v5, v6);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> inline T* safe_allocated_new6(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> inline T* safe_new7(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4, v5, v6, v7);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> inline T* safe_allocated_new7(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6, v7);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>  inline T* safe_new8(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const A8& v8, const char* file = 0, int line = 0)
{
 T* ptr = new T(v1, v2, v3, v4, v5, v6, v7, v8);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>  inline T* safe_allocated_new8(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const A8& v8, const char* file = 0, int line = 0)
{
 void* mem = AX::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6, v7, v8);
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
 return ptr;
};

template<typename T> void inline safe_delete(T* ptr, const char* file, int line)
{
 if (ptr == 0)
  return;
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_pop_ptr(ptr, file, line);
#endif
 delete ptr;
}

template<typename T, typename AX> void inline safe_allocated_delete(T* ptr, const char* file, int line)
{
 if (ptr == 0)
  return;
 ptr->~T();
#if NXOGRE_DEBUG_MEMORY == 1
 gc_debugger_pop_ptr(ptr, file, line);
#endif
 AX::deallocateBytes(ptr);
}

class NoGarbageCollection
{
 public:

 // map<K,T>, multimap<K,T>, hashmap<K,T>
 template<typename K, typename T> class impl_map
 {
  public:
    inline void gc_free(T&) {}
    template<typename it> inline void gc_free_range(it first, it last) {}
 };

 // map<K,T*>, multimap<K,T*>, hashmap<K,T*>
 template<typename K, typename T> class impl_map<K,T*>
 {
  public:
    inline void gc_free(T*) {}
    template<typename it> inline void gc_free_range(it first, it last) {}
 };

 // vector<T>
 template<typename T> class impl_vector
 {
  protected:

    inline void gc_free(T&) {}
    template<typename it> inline void gc_free_range(it first, it last) {}
 };

 // vector<T*>
 template<typename T> class impl_vector<T*>
 {
  protected:

    inline void gc_free(T*) {}
    template<typename it>  inline void gc_free_range(it first, it last) {}
 };

};

class HasGarbageCollection
{
 public:

 // map<K,T>, multimap<K,T>, hashmap<K,T>
 template<typename K, typename T> class impl_map
 {
  public:
    inline void gc_free(T& ref) {ref.~T();}
    template<typename it> inline void gc_free_range(it first, it last)
    {
     while(first != last)
     {
       (*first).second.~T();
       first++;
     }
    }
 };

 // map<K,T*>, multimap<K,T*>, hashmap<K,T*>
 template<typename K, typename T> class impl_map<K,T*>
 {
  public:
    inline void gc_free(T* ptr) {safe_delete(ptr, NXOGRE_GC_THIS);}
    template<typename it> inline void gc_free_range(it first, it last)
    {
     while(first != last)
     {
       //delete (*first).second;
       safe_delete((*first).second, NXOGRE_GC_THIS);
       first++;
     }
    }
 };

 // vector<T>
 template<typename T> class impl_vector
 {
  protected:

    inline void gc_free(T& ref) {ref.~T();}
    template<typename it> inline void gc_free_range(it first, it last)
    {
     while(first != last)
     {
       (*first).~T();
       first++;
     }
    }
 };

 // vector<T*>
 template<typename T> class impl_vector<T*>
 {
  protected:

    inline void gc_free(T* ptr) {safe_delete<T>(ptr, NXOGRE_GC_THIS);}
    template<typename it> inline void gc_free_range(it first, it last)
    {
     while(first != last)
     {
       safe_delete<T>((*first), NXOGRE_GC_THIS);
       first++;
     }
    }
 };

};

template<typename T> bool safe_copy(T* first, T* last, T* dest)
{
 if (first == 0 || last == 0 || dest == 0)
  return false;
 for (; first != last; ++dest, ++first)
  *dest = *first;
 return true;
}

                                                                                       

} // namespace GC

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
