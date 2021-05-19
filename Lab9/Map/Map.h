#ifndef MAP_H
#define MAP_H

#include <iostream>

template <typename T1, typename T2>
class Map
{
public:
	struct Element {
		T1 key;
		T2 value;
		int index;
	} *vector;
	int index;
	Map();
	T2& operator[](T1 key);
	Element* begin() { return &vector[0]; }
	Element* end() { return &vector[index]; }
	bool Set(T1 key, T2 value);
	bool Get(const T1& key, T2& value);
	int Count();
	void Clear(Map m);
	bool Delete(const T1& key);
	bool Includes(const Map<T1, T2>& map);
};

template<typename T1, typename T2>
inline Map<T1, T2>::Map()
{
	vector = new Element[100];
	index = 0;
}

template<typename T1, typename T2>
inline T2& Map<T1, T2>::operator[](T1 key)
{
	for (int i = 0; i < index; i++)
		if (vector[i].key == key)
			return vector[i].value;
	vector[index].index = index;
	vector[index].key = key;
	index++;
	return vector[index-1].value;
}

template<typename T1, typename T2>
inline bool Map<T1, T2>::Set(T1 key, T2 value)
{
	for (int i = 0; i < index; i++)
		if (vector[i].key == key) {
			vector[i].value = value;
			return true;
		}
	return false;
}

template<typename T1, typename T2>
inline bool Map<T1, T2>::Get(const T1& key, T2& value)
{
	for (int i = 0; i < index; i++)
		if (vector[i].key == key) {
			value = vector[i].value;
			return true;
		}
	return false;
}

template<typename T1, typename T2>
inline int Map<T1, T2>::Count()
{
	return index;
}

template<typename T1, typename T2>
inline void Map<T1, T2>::Clear(Map m)
{
	index = 0;
	delete[] vector;
}

template<typename T1, typename T2>
inline bool Map<T1, T2>::Delete(const T1& key)
{
	for (int i = 0; i < index; i++)
		if (vector[i].key == key) {
			for (int j = i; j < index - 1; j++)
				vector[j] = vector[j + 1];
			index--;
		}
	return false;
}

template<typename T1, typename T2>
inline bool Map<T1, T2>::Includes(const Map<T1, T2>& map)
{
	int count = 0;
	for (int i = 0; i < map.index; i++)
		for (int j=0;j<index;j++)
			if (map.vector[i].key == vector[j].key) {
				count++;
				break;
			}
	if (count == map.index)
		return true;
	return false;
}

#endif