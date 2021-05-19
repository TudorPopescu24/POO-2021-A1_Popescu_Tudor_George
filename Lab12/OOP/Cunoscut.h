#pragma once
#include "Contact.h"
class Cunoscut :
    public Contact
{
    const char* phoneNumber;
public:
    Cunoscut(const char* Name, const char* PhoneNumber);
    virtual const char* GetContactType();
};

