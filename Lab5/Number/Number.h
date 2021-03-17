#pragma once
class Number
{
	char* value;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};