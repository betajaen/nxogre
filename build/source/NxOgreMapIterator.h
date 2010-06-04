#ifndef NXOGRE_MAP_ITERATOR_H
#define NXOGRE_MAP_ITERATOR_H

#include <map>

namespace NxOgre
{

template<typename K, typename T> 
class map_iterator
{

public:

inline map_iterator()
{ // empty constructor.
}


inline map_iterator(const map_iterator& other)
: begin_it(other.begin_it), end_it(other.end_it), current_it(begin_it)
{ // constructor. 
}


inline map_iterator(const typename std::map<K,T>::iterator& begin, const typename std::map<K,T>::iterator& end)
: begin_it(begin), end_it(end), current_it(begin)
{ // constructor.
}

inline ~map_iterator()
{
}

inline typename std::map<K, T>::iterator begin() const
{
 return begin_it;
}

inline typename std::map<K, T>::iterator end() const
{
 return end_it;
}

inline bool operator!=(const typename std::map<K, T>::iterator& comp)
{
 return current_it != comp;
}

inline bool operator==(const typename std::map<K, T>::iterator& comp)
{
 return current_it == comp;
}

inline void operator++()
{
 current_it++;
}

inline void operator++(int)
{
 current_it++;
}

inline void operator--()
{
 current_it--;
}

inline void operator--(int)
{
 current_it--;
}

inline K key() const
{
 return (*current_it).first;
}

inline T& operator->()
{
 return (*current_it).second;
}

inline T& operator*()
{
 return (*current_it).second;
}

protected:
 typename std::map<K, T>::iterator current_it, begin_it, end_it;

};


} // namespace NxOgre

#endif