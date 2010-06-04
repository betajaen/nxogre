#ifndef NXOGRE_REGISTER_TYPE_H
#define NXOGRE_REGISTER_TYPE_H

#include "NxOgreClassPrototypes.h"

namespace NxOgre
{

namespace GC
{

template< typename T > struct type2id
{
 typedef void type;
 static inline const char* type_name() { return typeid(T).name(); }
 enum { type_id = 0 };
};

#define NxOgre_PreprocessorToStringBase(x) #x
#define NxOgre_Stringify(x) NxOgre_PreprocessorToStringBase(x)

#define REGISTER_TYPE(TYPE) \
 template<> struct type2id< TYPE > \
 { \
  typedef TYPE type; \
  static inline const char* type_name() { return NxOgre_Stringify(TYPE); } \
  enum {type_id = 100 + __LINE__, }; \
 }; \
 template<> struct type2id< TYPE* > \
 { \
  typedef TYPE* type; \
  static inline const char* type_name() { return NxOgre_Stringify(TYPE*); } \
  enum {type_id = 200 + __LINE__, }; \
 };

REGISTER_TYPE(void);
REGISTER_TYPE(unsigned char);
REGISTER_TYPE(char);
REGISTER_TYPE(unsigned short);
REGISTER_TYPE(short);
REGISTER_TYPE(unsigned int);
REGISTER_TYPE(int);
REGISTER_TYPE(float);
REGISTER_TYPE(double);
REGISTER_TYPE(unsigned long);
REGISTER_TYPE(long);

enum
{
 USER_TYPE_BEGIN = 1500
};

} // Namespace GC
} // Namespace NxOgre

#endif