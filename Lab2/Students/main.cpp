#include "students.h"
#include "globalfunctions.h"
#include <iostream>

int main() {
	students x, y;
	x.set_name("Ana");
	x.set_gr_math(7.6);
	x.set_gr_eng(10);
	x.set_gr_hist(6.4);
	y.set_name("Ionel");
	y.set_gr_math(7);
	y.set_gr_eng(9.8);
	y.set_gr_hist(6.5);
	std::cout << cmp_name(x, y) << '\n';
	std::cout << cmp_gr_math(x, y) << '\n';
	std::cout << cmp_gr_eng(x, y) << '\n';
	std::cout << cmp_gr_hist(x, y) << '\n';
	std::cout << cmp_gr_average(x, y) << '\n';
}