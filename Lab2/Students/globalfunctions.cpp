#include "students.h"
#include "globalfunctions.h"
#include <cstring>

int cmp_name(students a, students b) {
	return strcmp(a.get_name(), b.get_name());
}

int cmp_gr_math(students a, students b) {
	if (a.get_gr_math() > b.get_gr_math())
		return 1;
	else if (a.get_gr_math() == b.get_gr_math())
		return 0;
	else return -1;
}

int cmp_gr_eng(students a, students b) {
	if (a.get_gr_eng() > b.get_gr_eng())
		return 1;
	else if (a.get_gr_eng() == b.get_gr_eng())
		return 0;
	else return -1;
}

int cmp_gr_hist(students a, students b) {
	if (a.get_gr_hist() > b.get_gr_hist())
		return 1;
	else if (a.get_gr_hist() == b.get_gr_hist())
		return 0;
	else return -1;
}

int cmp_gr_average(students a, students b) {
	if (a.get_gr_average() > b.get_gr_average())
		return 1;
	else if (a.get_gr_average() == b.get_gr_average())
		return 0;
	else return -1;
}