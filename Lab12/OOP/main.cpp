#include "Contact.h"
#include "Agenda.h"
#include <iostream>

using namespace std;

int main() {
	Prieten friend1 = Prieten("Tudor", "24/03/2001", "0769060774", "Iasi");
	Prieten friend2 = Prieten("Misu", "24/08/2005", "0769060770", "Bucurest");
	Agenda Agenda;
	Agenda.AddContact(&friend1);
	Agenda.AddContact(&friend2);
	Coleg coleg1 = Coleg("Andreea", "0755283990", "QuartzMatrix", "Craiova");
	Cunoscut cunoscut1 = Cunoscut("Bogdan", "0755433220");
	Agenda.AddContact(&coleg1);
	Agenda.AddContact(&cunoscut1);
	Agenda.FriendsList();
	Agenda.DeleteContact("Misu");
	Agenda.FriendsList();
	Agenda.SearchByName("Bogdan");
	Agenda.SearchByName("Cristina");
}