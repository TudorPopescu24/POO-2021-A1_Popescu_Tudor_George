#include "students.h"

void students::set_name(const char* n) {
	this->name = n;
}

void students::set_gr_math(float grade) {
	this->gr_math = grade;
}

void students::set_gr_eng(float grade) {
	this->gr_eng = grade;
}

void students::set_gr_hist(float grade) {
	this->gr_hist = grade;
}

const char* students::get_name() {
	return this->name;
}

float students::get_gr_math() {
	return this->gr_math;
}

float students::get_gr_eng() {
	return this->gr_eng;
}

float students::get_gr_hist() {
	return this->gr_hist;
}

float students::get_gr_average() {
	return (this->gr_math + this->gr_hist + this->gr_eng) / 3;
}