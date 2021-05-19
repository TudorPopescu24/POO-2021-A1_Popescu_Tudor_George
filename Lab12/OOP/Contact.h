#pragma once
class Contact
{
public:
	const char* name;
	virtual const char* GetContactType() = 0;
};

