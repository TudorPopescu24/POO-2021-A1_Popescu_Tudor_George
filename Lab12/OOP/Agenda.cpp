#include "Agenda.h"
#include <iostream>

using namespace std;

Agenda::Agenda()
{
	agenda = new Contact*;
	nrContacte = 0;
}

Contact* Agenda::SearchByName(const char* name)
{
	if (nrContacte == 0) {
		throw "Agenda este goala";
	}
	for (int i = 0; i < nrContacte; i++)
		if (agenda[i]->name == name) {
			cout << "Am gasit contactul cu numele " << name << endl;
			return agenda[i];
		}
	cout << "Nu exista niciun contact cu numele acesta" << endl;
	return nullptr;
}

Contact** Agenda::FriendsList()
{
	Contact* friendsList[100];
	int friends = 0;
	for (int i = 0; i < nrContacte; i++)
		if (agenda[i]->GetContactType() == "prieten")
			friendsList[friends++] = agenda[i];
	if (friends) {
		cout << "Lista de prieteni este: ";
		for (int i = 0; i < friends; i++)
			cout << friendsList[i]->name << " ";
		cout << endl;
		return friendsList;
	}
	else {
		cout << "Nu exista niciun prieten in agenda" << endl;
		return nullptr;
	}
}

bool Agenda::DeleteContact(const char* name)
{
	for (int i = 0; i < nrContacte; i++)
		if (agenda[i]->name == name) {
			cout << "Am sters contactul " << name << endl;
			for (int j = i; j < nrContacte - 1; j++)
				agenda[j] = agenda[j + 1];
			nrContacte--;
			return true;
		}
	cout << "Nu exista contact cu numele " << name << endl;
	return false;
}

void Agenda::AddContact(Contact* contact)
{
	cout << "Am adaugat contactul cu numele " << contact->name << endl;
	agenda[nrContacte++] = contact;
}
