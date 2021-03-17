#include "Number.h"
#include <iostream>
#include <string.h>

using namespace std;

int main() {
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("92144", 10);
	n1.SwitchBase(12);
	n1.Print();
	n2.SwitchBase(10);
	n2.Print();
	n3.SwitchBase(16);
	n3.Print();
	cout << n3.GetDigitsCount() << endl;
	cout << n3.GetBase() << endl;
	return 0;
}