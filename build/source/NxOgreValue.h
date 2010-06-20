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

                                                                                       

#ifndef NXOGRE_VALUE_H
#define NXOGRE_VALUE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreString.h"
#include "NxOgreVec3.h"
#include "NxOgreQuat.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Value
    desc. 
        Simple holder class for bool, int, float, string, Vec3 or Quat types for serialisation to
        text or binary files.
*/
class Value
{
 
 public:
  
  enum ValueType
  {
   ValueType_Null = 0 ,
   ValueType_Int  = 1,
   ValueType_Float = 2,
   ValueType_Bool = 3,
   ValueType_String = 4,
   ValueType_Vec3 = 5,
   ValueType_Quat = 6
  };
  
  inline ~Value()
  {
   _freeString();
  }
   
  inline Value() : mType(ValueType_Null)
  {
   setNull();
  }

  inline Value(const Value& other)
  : mType(ValueType_Null), mValue(other.mValue)
  {
   if (other.mType == ValueType_String)
    set(other.mValue.stringVal);
   mType = other.mType;
  }

  Value& operator=(const Value& other)
  {
   Value temp(other);
   swap(temp);
   return *this;
  }

  void swap(Value& other)
  {
   // swap types.
   ValueType this_type = mType;
   mType = other.mType;
   other.mType = this_type;
   // swap values;
   std::swap(mValue, other.mValue);
  }
/*
_freeString();
   mValue = other.mValue;
   if (other.mType == ValueType_String)
    set(other.mValue.stringVal);
   mType = other.mType;
*/
  inline Value(int val) : mType(ValueType_Null)
  {
   set(val);
  }
  
  inline Value(float val) : mType(ValueType_Null)
  {
   set(val);
  }
  
  inline Value(bool val) : mType(ValueType_Null)
  {
   set(val);
  }
  
  inline Value(const char* val) : mType(ValueType_Null)
  {
   set(val);
  }

  inline Value(const std::string& val) : mType(ValueType_Null)
  {
   set(val);
  }
  
  inline Value(const Vec3& val) : mType(ValueType_Null)
  {
   set(val);
  }
  
  inline Value(const Quat& val) : mType(ValueType_Null)
  {
   set(val);
  }
  
  inline void setNull()
  {
   _freeString();
   mType = ValueType_Null;
  }
  
  inline void set(int val)
  {
   _freeString();
   mValue.intVal = val;
   mType = ValueType_Int;
  }
  
  inline void set(float val)
  {
   _freeString();
   mValue.floatVal = val;
   mType = ValueType_Float;
  }
  
  inline void set(bool val)
  {
   _freeString();
   mValue.boolVal = val;
   mType = ValueType_Bool;
  }
  
  inline void set(const char* val)
  {
   _freeString();
   mValue.stringVal = _duplicateString(val);
   mType = ValueType_String;
  }
  
  inline void set(const std::string& val)
  {
   _freeString();
   mValue.stringVal = _duplicateString(val.c_str());
   mType = ValueType_String;
  }
  
  inline void set(const Vec3& val)
  {
   _freeString();
   mValue.float4Val[0] = val.x;
   mValue.float4Val[1] = val.y;
   mValue.float4Val[2] = val.z;
   mType = ValueType_Vec3;
  }
  
  inline void set(const Quat& val)
  {
   _freeString();
   mValue.float4Val[0] = val.w;
   mValue.float4Val[1] = val.x;
   mValue.float4Val[2] = val.y;
   mValue.float4Val[3] = val.z;
   mType = ValueType_Quat;
  }
  
  inline ValueType type() const
  {
   return mType;
  }

  inline std::string type_str() const
  {
   if (mType == ValueType_Null)
    return "null";
   else if (mType == ValueType_Int)
    return "int";
   else if (mType == ValueType_Float)
    return "float";
   else if (mType == ValueType_Bool)
    return "bool";
   else if (mType == ValueType_String)
    return "string";
   else if (mType == ValueType_Vec3)
    return "vec3";
   else if (mType == ValueType_Quat)
    return "quat";
   else
    return "unknown";
  }
  
  inline bool isNull() const
  {
   return mType == ValueType_Null;
  }
  
  inline bool isInt() const
  {
   return mType == ValueType_Int;
  }
  
  inline bool isFloat() const
  {
   return mType == ValueType_Float;
  }
  
  inline bool isBool() const
  {
   return mType == ValueType_Bool;
  }
  
  inline bool isString() const
  {
   return mType == ValueType_String;
  }
  
  inline bool isVec3() const
  {
   return mType == ValueType_Vec3;
  }
  
  inline bool isQuat() const
  {
   return mType == ValueType_Quat;
  }

  inline bool getBool() const
  {
   return mValue.boolVal;
  }
  
  inline bool getBool(bool other_value) const
  {
   if (mType == ValueType_Bool)
    return mValue.boolVal;
   return other_value;
  }

  inline int getInt() const
  {
   return mValue.intVal;
  }
  
  inline int getInt(int other_value) const
  {
   if (mType == ValueType_Int)
    return mValue.intVal;
   return other_value;
  }
  
  inline float getFloat() const
  {
   return mValue.floatVal;
  }
  
  inline float getFloat(float other_value) const
  {
   if (mType == ValueType_Float)
    return mValue.floatVal;
   return other_value;
  }
  
  inline std::string getString() const
  {
   return std::string(mValue.stringVal);
  }
  
  inline std::string getString(const std::string& other_value) const
  {
   if (mType == ValueType_String)
    return std::string(mValue.stringVal);
   return other_value;
  }
  
  inline Vec3 getVec3() const
  {
   return Vec3(mValue.float4Val[0], mValue.float4Val[1], mValue.float4Val[2]);
  }

  inline Vec3 getVec3(const Vec3& other_value) const
  {
   if (mType == ValueType_Vec3)
    return Vec3(mValue.float4Val[0], mValue.float4Val[1], mValue.float4Val[2]);
   return other_value;
  }
  
  inline Quat getQuat() const
  {
   return Quat(mValue.float4Val[0], mValue.float4Val[1], mValue.float4Val[2], mValue.float4Val[3]);
  }
  
  inline Quat getQuat3(const Quat& other_value) const
  {
   if (mType == ValueType_Quat)
    return Quat(mValue.float4Val[0], mValue.float4Val[1], mValue.float4Val[2], mValue.float4Val[3]);
   return other_value;
  }
  
  inline static Value from_s(const std::string& value)
  {
   if (Strings::isNull(value))
    return Value();
   else if (Strings::isInteger(value))
    return Value(to_i(value));
   else if (Strings::isBoolean(value))
    return Value(to_b(value));
   else if (Strings::isReal(value))
    return Value(to_f(value));
   
   int wordCount = Strings::numWords(value);
   
   if (wordCount == 3 || wordCount == 4)
   {

    std::vector<std::string> strings = Strings::split(value);
    for (std::vector<std::string>::const_iterator it = strings.begin(); it != strings.end(); it++)
    {
     if (Strings::isReal((*it)) == false)
      return Value(value); // String with 3 or 4 words
    }
    
    if (wordCount == 3 && strings.size() == 3)
     return Value(Vec3(to_f(strings[0]), to_f(strings[1]), to_f(strings[2])));
    
    if (wordCount == 4 && strings.size() == 4)
     return Value(Quat(to_f(strings[0]), to_f(strings[1]), to_f(strings[2]), to_f(strings[3])));
    
    return Value(value); // String with 3 or 4 words.
   }

   return Value(value); // A string.
  }
  
  inline std::string to_s() const
  {
   std::ostringstream s;
   if (mType == ValueType_Null)
    s << "null";
   else if (mType == ValueType_Bool)
    s << (mValue.boolVal ? "true" : "false");
   else if (mType == ValueType_Int)
    s << mValue.intVal;
   else if (mType == ValueType_Float)
    s << mValue.floatVal;
   else if (mType == ValueType_String)
    s << mValue.stringVal;
   else if (mType == ValueType_Vec3)
    s << mValue.float4Val[0] << " " << mValue.float4Val[1] << " " << mValue.float4Val[2];
   else if (mType == ValueType_Quat)
    s << mValue.float4Val[0] << " " << mValue.float4Val[1] << " " << mValue.float4Val[2] << " " << mValue.float4Val[3];
   
   return s.str();
  }

 private:
  
  inline void _freeString()
  {
   if (mType == ValueType_String && mValue.stringVal != 0)
   {
    free(mValue.stringVal);
    mValue.stringVal = 0;
   }
  }
  
  inline char* _duplicateString(const char* original)
  {
   int length = strlen(original);
   char* copy = (char*) malloc(length + 1);
   memcpy(copy, original, length);
   copy[length] = 0;
   return copy;
  }
  
  union ValueHolder
  {
   bool         boolVal;
   int          intVal;
   float        floatVal;
   char*        stringVal;
   float        float4Val[4];
  };
  
  ValueType   mType;
  ValueHolder mValue;
};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
