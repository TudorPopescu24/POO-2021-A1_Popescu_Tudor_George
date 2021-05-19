#include "Prieten.h"

Prieten::Prieten(const char* Name, const char* Date, const char* PhoneNumber, const char* Adress)
{
	name = Name;  date = Date; phoneNumber = PhoneNumber; adress = Adress;
}

const char* Prieten::GetContactType()
{
	return "prieten";
}
