#include "Number.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int truevalue(char c) {
	if (c >= '0' && c <= '9')
		return (int)(c - '0');
	else
		return (int)(c - 'A' + 10);
}

char truevalue(int c) {
	if (c >= 0 && c <= 9)
		return (char)(c + '0');
	else
		return (char)(c - 10 + 'A');
}

int Base10(char* number, int base) {
	int i, nr = 0, p = 1;
	for (i = strlen(number) - 1; i >= 0; i--) {
		nr = nr + p * truevalue(number[i]);
		p = p * base;
	}
	return nr;
}

char* NewBase(int number, int base) {
	int i = 0;
	char* newnumber = (char*)malloc(100);
	while (number > 0) {
		newnumber[i++] = truevalue(number % base);
		number = number / base;
	}
	newnumber[i] = NULL;
	_strrev(newnumber);
	return newnumber;
}

Number::Number(const char* value, int base)
{
	this->value = (char*)value;
	this->base = base;
}

Number::Number(const Number& n)
{
	this->value = n.value;
	this->base = n.base;
}

Number::Number(const int&& n)
{
	value = (char*)malloc(100);
	int x = n, i = 0;
	while (x > 0) {
		value[i++] = truevalue(x % 10);
		x = x / 10;
	}
	value[i] = NULL;
	_strrev(value);
	this->base = 10;
}

Number::Number(const char*&& c)
{
	value = (char*)c;
	this->base = 10;
}

void Number::SwitchBase(int newBase)
{
	this->value = NewBase(Base10(this->value, this->base), newBase);
	this->base = newBase;
}

void Number::Print()
{
	cout << this->value << ' ' << this->base << endl;
}

int Number::GetDigitsCount()
{
	return strlen(this->value);
}

int Number::GetBase()
{
	return this->base;
}

Number& operator+(const Number& i, const Number& j)
{
	int maxbase, suma;
	if (i.base > j.base) maxbase = i.base;
	else maxbase = j.base;
	suma = Base10(i.value, i.base) + Base10(j.value, j.base);
	Number result(NewBase(suma, maxbase), maxbase);
	return result;
}

Number& operator-(const Number& i, const Number& j)
{
	int maxbase, diferenta;
	if (i.base > j.base) maxbase = i.base;
	else maxbase = j.base;
	diferenta = Base10(i.value, i.base) + Base10(j.value, j.base);
	Number result(NewBase(diferenta, maxbase), maxbase);
	return result;
}

Number& Number::operator-()
{
	if (value[0] == '-')
		strcpy(value, value + 1);
	else {
		strcpy(value + 1, value);
		value[0] = '-';
	}
	return (*this);
}

char& Number::operator[](int index)
{
	return value[index];
}

bool Number::operator==(const Number& i)
{
	if ((value == i.value) && (base == i.base)) return true;
	return false;
}

Number& Number::operator--()
{
	strcpy(value, value + 1);
	return (*this);
}

Number& Number::operator--(int)
{
	Number temp = *this;
	value[strlen(value) - 1] = NULL;
	return temp;

}

Number& Number::operator=(const int n)
{
	value = (char*)malloc(100);
	int x = n, i = 0;
	while (x > 0) {
		value[i++] = truevalue(x % 10);
		x = x / 10;
	}
	value[i] = NULL;
	_strrev(value);
	this->base = 10;
	return (*this);
}

Number& Number::operator=(const char* c)
{
	base = 10;
	value = (char*)c;
	return (*this);
}

