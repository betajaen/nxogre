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
#include "NxOgreString.h"
#include "NxOgreHash.h"
#include "NxOgreVec2.h"
#include "NxOgreVec3.h"
#include "NxOgreVec4.h"
#include "NxOgreRadian.h"
#include "NxOgreResource.h"

#include <sstream>
#include <algorithm>

                                                                                       

namespace NxOgre
{

                                                                                       

static const String bool_true = "true";
static const String bool_false = "false";
static const String whitespace = " \t\r\n";
static const String newlines = "\r\n";

std::string to_s(bool b)
{
 if (b)
  return bool_true;
 else
  return bool_false;
}

std::string to_s(unsigned char v)
{
 std::ostringstream s;
 s << v;
 return s.str();
}

std::string to_s(char v)
{
 std::ostringstream s;
 s << v;
 return s.str();
}

std::string to_s(short v)
{
 std::ostringstream s;
 s << v;
 return s.str();
}

std::string to_s(unsigned short v)
{
 std::ostringstream s;
 s << v;
 return s.str();
}

std::string to_s(int v)
{
 std::ostringstream s;
 s << v;
 return s.str();
}

std::string to_s(unsigned int v)
{
 std::ostringstream s;
 s << v;
 return s.str();
}

std::string to_s(float v)
{
 std::ostringstream s;
 s << v;
 return s.str();
}

std::string to_s(double v)
{
 std::ostringstream s;
 s << v;
 return s.str();
}

std::string to_s(const Vec2& v)
{
 return v.to_s();
}

std::string to_s(const Vec3& v)
{
 return v.to_s();
}

std::string to_s(const Vec4& v)
{
 return v.to_s();
}

std::string to_s(const Radian& v)
{
 return v.to_s();
}

String NxOgrePublicFunction to_s(float* arr, size_t length)
{
 std::ostringstream s;
 for (size_t i=0;i < length;i++)
  s << arr[i] << " ";
 return s.str();
}

String NxOgrePublicFunction to_s(unsigned int* arr, size_t length)
{
 std::ostringstream s;
 for (size_t i=0;i < length;i++)
  s << arr[i] << " ";
 return s.str();
}


std::string to_s(void* ptr, const String& description)
{
 std::ostringstream s;
 s << "<" << (description.length() != 0 ? std::string(description + ":") : std::string()) << ptr << ">";
 return s.str();
}

int to_i(const String& str)
{
 std::stringstream s(str);
 int out = 0;
 s >> out;
 return out;
}

float to_f(const String& str)
{
 std::stringstream s(str);
 float out = 0.f;
 s >> out;
 return out;
}

bool to_b(const String& str)
{
 if (str.length() != 4)
  return false;
 
 if (!(str[0] == 'T' || str[0] == 't'))
  return false;

 if (!(str[1] == 'R' || str[1] == 'r'))
  return false;

 if (!(str[2] == 'U' || str[2] == 'u'))
  return false;

 if (!(str[3] == 'E' || str[3] == 'e'))
  return false;
 
 return true;
}

void inspect(const float& value)
{
 std::cout << value << "f" << std::endl;
}

void inspect(const double& value)
{
 std::cout << value << "f" << std::endl;
}

void inspect(const int& value)
{
 std::cout << value << "i" << std::endl;
}

void inspect(const char& value)
{
 std::cout << value << "c" << std::endl;
}

void inspect(const short& value)
{
 std::cout << value << "s" << std::endl;
}

void inspect(const unsigned int& value)
{
 std::cout << value << "ui" << std::endl;
}

void inspect(const unsigned char& value)
{
 std::cout << value << "uc" << std::endl;
}

void inspect(const unsigned short& value)
{
 std::cout << value << "us" << std::endl;
}

void inspect(const String& value)
{
 std::cout << "'" << value << "'" << std::endl;
}


namespace Strings
{
#if 1

StringHash hash(const char* str)
{
 return hash(NxOgre::String(str));
}

StringHash hash(const NxOgre::String& str)
{
 static HashFunction<NxOgre::String> function;
 return function(str);
}

#else
StringHash hash(const char* str)
{
 if (strlen(str) == 0 || str == 0)
  return 0;
 
 unsigned long hash = 5381;
 int c = 0;
 while (c = *str++)
  hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
 return hash; 
}

StringHash hash(const String& str)
{
 return hash(str.c_str());
}

#endif
void NxOgrePublicFunction replace(String& string, char search, char replacement)
{
 for (String::iterator it = string.begin(); it != string.end(); ++it)
  if ((*it) == search)
   (*it) = replacement;
}

String NxOgrePublicFunction replace_copy(const String& original, char search, char replacement)
{
 String string(original);
 for (String::iterator it = string.begin(); it != string.end(); ++it)
  if ((*it) == search)
   (*it) = replacement;
 return string;
}

size_t index(const String& string, char search)
{
 return string.find_first_of(search);
}

bool has(const String& string, char search)
{
 return string.find_first_of(search) != String::npos;
}

void trim(String& string)
{
 string.erase(string.find_last_not_of(whitespace)+1);
 string.erase(0, string.find_first_not_of(whitespace));
}

String trim_copy(const String& string)
{
 String dest(string);
 trim(dest);
 return dest;
}

void captialise(String& string)
{
 lower(string);
 if (string.length())
  toupper(string[0]);
}

String captialise_copy(const String& string)
{
 String dest(string);
 captialise(dest);
 return dest;
}

void lower(String& string)
{
 std::transform(string.begin(), string.end(), string.begin(), tolower);
}

String lower_copy(const String& original)
{
 String dest;
 dest.append(original);
 lower(dest);
 return dest;
}

void upper(String& string)
{
 std::transform(string.begin(), string.end(), string.begin(), toupper);
}

String upper_copy(const String& original)
{
 String dest;
 dest.append(original);
 upper(dest);
 return dest;
}

void slice_to_first_of(String& string, char pattern)
{
 size_t pos = string.find_first_of(pattern);
 if (pos != String::npos)
  string.assign(string.substr(0, pos));
}

void slice_to_last_of(String& string, char pattern)
{
 size_t pos = string.find_last_of(pattern);
 if (pos != String::npos)
  string.assign(string.substr(0, pos));
}

void slice_after_first_of(String& string, char pattern)
{
 size_t pos = string.find_first_of(pattern);
 if (pos != String::npos)
  string.assign(string.substr(pos+1));
}

void slice_after_last_of(String& string, char pattern)
{
 size_t pos = string.find_last_of(pattern);
 if (pos != String::npos)
  string.assign(string.substr(pos+1));
}


void slice(String& string, size_t begin)
{
 string.assign(string.substr(begin));
}

void slice(String& string, size_t begin, size_t end)
{
 string.assign(string.substr(begin, end));
}

String slice_copy(const String& string, size_t begin)
{
 return string.substr(begin);
}

String slice_copy(const String& string, size_t begin, size_t end)
{
 return string.substr(begin, end);
}

bool starts(const String& original, const String& comparision)
{
 return original.compare(0, comparision.length(), comparision) == 0;
}

bool starts_insensitive(const String& original, const String& comparision)
{
 if (original.length() < comparision.length())
  return false;
 
 for (size_t it = 0; it < comparision.length();++it)
  if (tolower(original[it]) != tolower(comparision[it]))
   return false;
 
 return true;
}

bool matches(const String& original, const String& comparision)
{
 return original == comparision;
}

bool matches_insensitive(const String& original, const String& comparision)
{
 return lower_copy(original) == lower_copy(comparision);
}

StringPair cut(const String& str, bool& didCut, char delimiter, char endDelimiter)
{
 
 didCut = false;
 
 String working(str);
 
 if (endDelimiter != 0)
  slice_to_first_of(working, endDelimiter);
 
 trim(working);
 
 if (working.length() == 0)
  return StringPair(String(), String());
 
 if (Strings::index(working, ':') == std::string::npos)
  return StringPair(String(), String());

 std::string first(working);
 slice_to_first_of(first, ':');
 std::string second(working);
 slice_after_first_of(second, ':');
 
 trim(first);
 trim(second);
 
 didCut = true;
 
 return StringPair(first, second);
}

std::map<std::string, std::string> cut_many(const String& str, char delimiter, char endDelimiter)
{
 std::map<std::string, std::string> ret;
 
 if (str.length() <= 1)
  return ret;

 std::vector<std::string> lines = split(str, "\n");
 
 for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); it++)
 {
  String working(str);
  
  if (endDelimiter != 0)
   slice_to_first_of(working, endDelimiter);
  
  trim(working);
  
  if (working.length() == 0)
   continue;
  
  if (Strings::index(working, ':') == std::string::npos)
   continue;
  
  std::string first(working);
  slice_to_first_of(first, ':');
  std::string second(working);
  slice_after_first_of(second, ':');
  
  trim(first);
  trim(second);
  
  ret.insert(std::pair<std::string, std::string>(first, second));
 }
 
 return ret;
}


std::vector<std::string> split(const String& str, const String& delimiters)
{
 std::vector<std::string> out;
 size_t b = str.find_first_not_of(delimiters, 0);
 size_t a = str.find_first_of(delimiters, b);
 std::string t;
 while (a != String::npos || b != String::npos)
 {
  std::stringstream s(str.substr(b, a - b));
  s >> t;
  out.push_back(t);
  b = str.find_first_not_of(delimiters, a);
  a = str.find_first_of(delimiters, b);
 }

 return out;
}

bool split(const String& str, std::map<String, String>& value, char delimiter, bool lowerKey, bool trim)
{
 size_t pos = str.find_first_of(delimiter);
 if (pos == String::npos)
  return false;
 
 std::string k = str.substr(0,pos);
 std::string v = str.substr(pos+1);

 if (lowerKey)
  lower(k);

 if (trim)
 {
  Strings::trim(k);
  Strings::trim(v);
 }
 
 value[k] = v;

 return true;
}


bool split(const String& str, NxOgre::map<String, String>& value, char delimiter, bool lowerKey, bool trim)
{
 size_t pos = str.find_first_of(delimiter);
 if (pos == String::npos)
  return false;
 
 std::string k = str.substr(0,pos);
 std::string v = str.substr(pos+1);

 if (lowerKey)
  lower(k);

 if (trim)
 {
  Strings::trim(k);
  Strings::trim(v);
 }
 
 value.insert(k, v);

 return true;
}

int numWords(const std::string& str)
{
 
 if (str.length() == 0)
  return 0;
 
 int ret = 0;
 bool lastWasSpace = true;
 for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
 {
  if (isspace((*it)))
   lastWasSpace = true;
  else
  {
   if (lastWasSpace)
    ret++;
   lastWasSpace = false;
  }
 }
 
 return ret;
}

bool isNull(const std::string& str)
{
 if (str.length() != 4)
  return false;
 
 if (!(str[0] == 'N' || str[0] == 'n'))
  return false;

 if (!(str[1] == 'U' || str[1] == 'u'))
  return false;

 if (!(str[2] == 'L' || str[2] == 'l'))
  return false;

 if (!(str[3] == 'L' || str[3] == 'l'))
  return false;
 
 return true;
}

bool isInteger(const std::string& str)
{
 bool hasExponent = false;
 for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
 {
  
  // Sign -- Must be the first character of the string.
  if ((*it) == '-' || (*it) == '+')
  {
   if (it == str.begin())
    continue;
   
   return false;
  }
  
  // Exponent -- Can't be at the first or last part of the string, and there can only be one of them.
  if ((*it) == 'E' || (*it) == 'e')
  {
   if (hasExponent || it == str.begin() || it == str.end())
    return false;
   hasExponent = true;
   continue;
  }
  
  if (isdigit((*it)) == false)
   return false;
  
 }
 return true;
}

bool isReal(const std::string& str)
{
 bool hasDecimal = false, hasExponent = false, hasSign = false;
 for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
 {
  
  // Sign -- Must be the first character of the string, or if the previous character was an exponent.
  if ((*it) == '-' || (*it) == '+')
  {
   
   hasSign = true;
   
   if (it == str.begin())
    continue;

   std::string::const_iterator last = it - 1;
   if ( (*last) == 'E' || (*last) == 'e')
    continue;
   
   return false;
  }
  
  // Exponent -- Can't be at the first or last part of the string, and there can only be one of them.
  if ((*it) == 'E' || (*it) == 'e')
  {
   if (hasExponent || hasDecimal || hasSign || it == str.begin() || it == str.end())
    return false;
   hasExponent = true;
   continue;
  }
  
  // Decimal -- There can only be one of them. There can't be one if there is an exponent.
  if ((*it) == '.')
  {
   if (hasExponent || hasDecimal)
    return false;
   hasDecimal = true;
   continue;
  }

  if (isdigit((*it)) == false)
   return false;
 }
 
 return true;
}

bool isBoolean(const std::string& str)
{
 std::string working(str);
 std::transform(working.begin(), working.end(), working.begin(), tolower);
 return working == "true" || working == "false";
}



void getLine(NxOgre::Resource* resource, NxOgre::buffer<char>& buffer)
{
 buffer.remove_all();
 while(1)
 {
  char c = resource->readChar();
  if (resource->atEnd() || c == '\n')
   break;
  buffer.push_back(c);
 }
 
 if (buffer[buffer.size() - 1] == '\r')
  buffer[buffer.size() - 1] = 0;
 else
  buffer.push_back(0);
}


}

                                                                                       

} // namespace NXOGRE_NAMESPACE

                                                                                       
