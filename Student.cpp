#include "Stuff.h"
#include "Student.h"
#include <cstring>
#include <iostream>
#include <iomanip>
Student::Student(
	const char* _name,
	const char* _surn,
	const char* _patr,
	Date _dob,
	char _sex,
	int _enroll,
	const char* _faculty,
	const char* _chair,
	const char* _gradebook,
	Session* _sessions,
	int _n_sessions
) : Person(_name, _surn, _patr, _dob, _sex), enroll(_enroll), n_sessions(_n_sessions) {
	strcpy_s(this->faculty, _faculty);
	strcpy_s(this->chair, _chair);
	strcpy_s(this->gradebook, _gradebook);
	this->sessions = new Session[_n_sessions];
	FORi(0, _n_sessions) this->sessions[i] = _sessions[i];
}
void Student::IntroduceYourself() const {
	std::cout << '|' << std::left << std::setw(30) << this->name << '|' <<
		std::left << std::setw(30) << this->surn << '|' <<
		std::left << std::setw(30) << this->patr << '|' <<
		std::left << std::setw(10) << this->dob.day << '.' << this->dob.month << '.' << this->dob.year << '|' <<
		this->sex << '|' << std::left << std::setw(5) << this->enroll << '|' <<
		std::left << std::setw(10) << this->faculty << '|' <<
		std::left << std::setw(10) << this->chair << '|' <<
		std::left << std::setw(10) << this->gradebook << '|' << std::endl;
}