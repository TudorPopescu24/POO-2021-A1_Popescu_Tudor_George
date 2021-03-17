#pragma once
class Number
{
	char* value;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& n); // copy constructor
	friend Number& operator+ (const Number& i, const Number& j);
	friend Number& operator- (const Number& i, const Number& j);
	Number& operator- ();
	char& operator[] (int index);
	bool operator== (const Number& i);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};