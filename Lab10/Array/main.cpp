#include "Array.h"

using namespace std;

int main() {
	Array<int> p(3);
	p += 10;
	p += 20;
	p += 30;
	Array<int> d(6);
	Array<int> l(6);
	Array<int> l2(6);

	d += 400;
	d += 300;
	d += 200;
	d += 100;
	return 0;
}