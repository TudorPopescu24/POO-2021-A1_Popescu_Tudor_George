#pragma once
#include "Contact.h"
class Coleg :
    public Contact
{
    const char* phoneNumber;
    const char* firm;
    const char* adress;
public:
    Coleg(const char* Name, const char* PhoneNumber, const char* Firm, const char* Adress);
    virtual const char* GetContactType();
};

