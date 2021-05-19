#include "Coleg.h"

Coleg::Coleg(const char* Name, const char* PhoneNumber, const char* Firm, const char* Adress)
{
    name = Name; phoneNumber = PhoneNumber; firm = Firm; adress = Adress;
}

const char* Coleg::GetContactType()
{
    return "coleg";
}
