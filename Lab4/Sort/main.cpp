#include "Sort.h"
#include <string.h>
#include <iostream>

using namespace std;

int main() {
	int vector[] = { 1,2,3,4,5 };
	char* string = _strdup("100,200,50,30,1,0");
	Sort s1(5, 10, 100);
	Sort s2 = { 5, 70, 100, 500, 20 };
	Sort s3(5, vector);
	Sort s4(10, 12, 63, 1900, 5, 67, 23, 87, 15, 5, 500);
	Sort s5(string);
	s1.Print();
	s2.Print();
	s3.Print();
	s4.Print();
	s5.Print();
	cout << s1.GetElementsCount() << ' ' << s2.GetElementsCount() << ' ' << s3.GetElementsCount() << ' ' << s4.GetElementsCount() << ' ' << s5.GetElementsCount() << endl;
	cout << s1.GetElementFromIndex(1) << ' ' << s3.GetElementFromIndex(3) << ' ' << s5.GetElementFromIndex(5) << endl;
	s1.BubbleSort();
	s2.BubbleSort();
	s3.BubbleSort();
	s4.BubbleSort();
	s5.BubbleSort();
	s1.Print();
	s2.Print();
	s3.Print();
	s4.Print();
	s5.Print();
}