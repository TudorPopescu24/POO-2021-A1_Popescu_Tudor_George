#include "NumberList.h"
#include <iostream>

int main() {
	NumberList p;
	p.Init();
	p.Add(10);
	p.Add(2);
	p.Add(100);
	p.Add(3);
	p.Add(15);
	p.Print();
	p.Add(23);
	p.Add(144);
	p.Add(5);
	p.Print();
	p.Sort();
	p.Print();
	return 0;
}