#pragma once
#include <iostream>

template <typename T>
class Vector
{
	int size;
	int count;
	T* vector;
public:
	Vector(int s);
	void Print();
	void Resize();
	void Push(T element);
	T Pop();
	void Delete(int index);
	void Insert(T e, int index);
	void Sort(bool IsGreater(T, T));
	void Set(T element, int index);
	const T& Get(int index);
	int Count();
	int firstIndexOf(T element, bool IsEqual(T, T));
};

template<typename T>
inline Vector<T>::Vector(int s)
{
    count = 0;
	size = s;
	vector = new T[size];
}

template<typename T>
inline void Vector<T>::Print()
{
	for (int i = 0; i < count; i++)
		std::cout << vector[i] << ' ';
	std::cout << '\n';
}

template<typename T>
inline void Vector<T>::Resize()
{
	size = size * 2;
	T* aux = new T[size];
	for (int i = 0; i < count; i++)
		aux[i] = vector[i];
	delete[] vector;
	vector = aux;
}

template<typename T>
inline void Vector<T>::Push(T element)
{
	if (count + 1 > size)
		Resize();
	vector[count] = element;
	count++;
	std::cout << "Am dat push la elementul " << element << '\n';
}

template<typename T>
inline T Vector<T>::Pop()
{
	T element = vector[count - 1];
	count--;
	T* aux = new T[size];
	for (int i = 0; i < count; i++)
		aux[i] = vector[i];
	delete[] vector;
	vector = aux;
	std::cout << "Am dat pop la elementul " << element << '\n';
	return element;
}

template<typename T>
inline void Vector<T>::Delete(int index)
{
	T element = vector[index];
	T* aux = new T[size];
	for (int i = 0; i < index; i++)
		aux[i] = vector[i];
	for (int i = index + 1; i < count; i++)
		aux[i - 1] = vector[i];
	count--;
	delete[] vector;
	vector = aux;
	std::cout << "Am eliminat elementul " << element << " de pe pozitia " << index << '\n';
}

template<typename T>
inline void Vector<T>::Insert(T e, int index)
{
	if (count + 1 > size)
		Resize();
	T element = vector[index];
	T* aux = new T[size];
	for (int i = 0; i < index; i++)
		aux[i] = vector[i];
	aux[index] = e;
	for (int i = index; i < count; i++)
		aux[i + 1] = vector[i];
	count++;
	delete[] vector;
	vector = aux;
	std::cout << "Am adaugat elementul " << e << " pe pozitia " << index << '\n';
}

template<typename T>
inline void Vector<T>::Sort(bool IsGreater(T, T))
{
	if (IsGreater == nullptr)
	{
		T aux;
		bool ok;
		do
		{
			ok = true;
			for (int i = 0; i < count - 1; i++)
				if (vector[i] < vector[i + 1])
				{
					aux = vector[i];
					vector[i] = vector[i + 1];
					vector[i + 1] = aux;
					ok = false;
				}
		} while (!ok);
		return;
	}
	T aux;
	bool ok;
	do
	{
		ok = true;
		for (int i = 0; i < count - 1; i++)
			if (IsGreater(vector[i], vector[i + 1]) == true)
			{
				aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
				ok = false;
			}
	} while (!ok);

}

template<typename T>
inline void Vector<T>::Set(T element, int index)
{
	if (index < 0 || index >= count)
	{
		std::cout << "Eroare! Nu pot seta elementul " << element << " la index-ul " << index << '\n';
		return;
	}
	vector[index] = element;
}

template<typename T>
inline const T& Vector<T>::Get(int index)
{
	if (index < 0 || index >= count)
	{
		std::cout << "Eroare! Nu pot selecta elementul " << vector[index] << " de la index-ul " << index << '\n';
		return;
	}
	return vector[index];
}

template<typename T>
inline int Vector<T>::Count()
{
	return count;
}

template<typename T>
inline int Vector<T>::firstIndexOf(T element, bool IsEqual(T, T))
{
	if (IsEqual == nullptr)
	{
		for (int i = 0; i < count; i++)
			if (element == vector[i])
				return i;
		return -1;
	}
	for (int i = 0; i < count; i++)
		if (IsEqual(vector[i], element) == true)
			return i;
	return -1;
}
