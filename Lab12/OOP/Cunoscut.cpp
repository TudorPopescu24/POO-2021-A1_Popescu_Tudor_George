#include "Cunoscut.h"

Cunoscut::Cunoscut(const char* Name, const char* PhoneNumber)
{
    name = Name; phoneNumber = PhoneNumber;
}

const char* Cunoscut::GetContactType()
{
    return "cunoscut";
}
