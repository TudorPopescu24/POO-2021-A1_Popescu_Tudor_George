#pragma once
#include "Contact.h"
#include "Prieten.h"
#include "Coleg.h"
#include "Cunoscut.h"

class Agenda
{
	Contact** agenda;
	int nrContacte;
public:
	Agenda();
	Contact* SearchByName(const char* name);
	Contact** FriendsList();
	bool DeleteContact(const char* name);
	void AddContact(Contact* contact);
};

