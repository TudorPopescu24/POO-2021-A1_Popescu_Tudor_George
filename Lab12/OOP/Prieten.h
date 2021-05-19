#pragma once
#include "Contact.h"
class Prieten :
    public Contact
{
    const char* date;
    const char* phoneNumber;
    const char* adress;
public:
    Prieten(const char* Name, const char* Date, const char* PhoneNumber, const char* Adress);
    virtual const char* GetContactType();
};

