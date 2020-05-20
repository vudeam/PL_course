#include <iostream>
#include <cstring>
#include "Person.h"

Person::Person() {};
Person::Person(
	const char* _name,
	const char* _surn,
	const char* _patr,
	Date        _dob,
	char        _sex
) : dob(_dob), sex(_sex) {
	strcpy_s(this->name, _name);
	strcpy_s(this->surn, _surn);
	strcpy_s(this->patr, _patr);
}
void Person::IntroduceYourself() const {
	std::cout << this->name << ' ' << this->surn << ' ' << this->patr << std::endl;
	std::cout << "Дата рождения: " << this->dob.day << '.' << this->dob.month << '.' << this->dob.year << std::endl;
	std::cout << "Пол: " << this->sex << std::endl;
	return;
}