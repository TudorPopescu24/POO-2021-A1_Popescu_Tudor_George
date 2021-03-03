#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstdarg>
#include <cstring>

int Math::Add(int x, int y) {
	return x + y;
}

int Math::Add(int x, int y, int z) {
	return x + y + z;
}

int Math::Add(double x, double y) {
	return x + y;
}

int Math::Add(double x, double y, double z) {
	return x + y + z;
}

int Math::Mul(int x, int y) {
	return x * y;
}

int Math::Mul(int x, int y, int z) {
	return x * y * z;
}

int Math::Mul(double x, double y) {
	return x * y;
}

int Math::Mul(double x, double y, double z) {
	return x * y * z;
}

int Math::Add(int count, ...) {
	int suma = 0;
	va_list lista;
	va_start(lista, count);
	for (int i = 0; i < count; i++)
		suma += va_arg(lista, int);
	return suma;
}

char* Math::Add(const char* x, const char* y) {
	int suma = (int)x + (int)y;
	char* result = (char*)suma;
	return result;
}

