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
	n3 = n1 + n2;
	n3.Print();
	n1 = n3 - n2;
	n1.Print();
	n2 = -n1;
	n2.Print();
	n2 = -n2;
	n2.Print();
	cout << n2[1] << endl;
	Number n4("734", 8);
	Number n5("734", 8);
	cout << (n4 == n5) << endl;
	cout << (n4 == n2) << endl;
	Number n6 = 12345;
	n6.Print();
	n2 = 1234;
	n2.Print();
	n3 = "123456";
	n3.Print();
	n4.Print();
	--n4;
	n4.Print();
	n3.Print();
	n3--;
	n3.Print();
}