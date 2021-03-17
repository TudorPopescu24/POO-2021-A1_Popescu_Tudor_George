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