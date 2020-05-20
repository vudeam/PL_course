#include <iostream>
#include <iomanip>
#include <cstring>
#include "Stuff.h"
#include "Student.h"

Session::Session() : n_subjects(0) {};
Session::Session(int _n_subjects, Subject* _subjects) : n_subjects(_n_subjects) {
	FORi(0, _n_subjects) this->subjects[i] = _subjects[i];
}
Student::Student() {};
Student::Student(
	const char* _name,
	const char* _surn,
	const char* _patr,
	Date        _dob,
	char        _sex,
	int         _enroll,
	const char* _faculty,
	const char* _chair,
	const char* _groupname,
	const char* _gradebook,
	Session*    _sessions,
	int         _n_sessions
) : Person(_name, _surn, _patr, _dob, _sex), enroll(_enroll), n_sessions(_n_sessions) {
	strcpy_s(this->faculty,   _faculty);
	strcpy_s(this->chair,     _chair);
	strcpy_s(this->groupname, _groupname);
	strcpy_s(this->gradebook, _gradebook);
	// this->sessions = new Session[_n_sessions];
	FORi(0, _n_sessions) this->sessions[i] = _sessions[i];
}
void Student::IntroduceYourself() const {
	/*std::cout << '|' << std::left << std::setw(30) << this->name << '|' <<
		std::left << std::setw(30) << this->surn << '|' <<
		std::left << std::setw(30) << this->patr << '|' <<
		std::left << this->dob.day << '.' << this->dob.month << '.' << this->dob.year << '|' <<
		std::left << ' ' << this->sex << ' ' << '|' << std::left << std::setw(5) << this->enroll << '|' <<
		std::left << std::setw(10) << this->faculty << '|' <<
		std::left << std::setw(10) << this->chair << '|' <<
		std::left << std::setw(10) << this->gradebook << '|' << std::endl;*/
	std::cout << this->surn << ' ' << this->name << ' ' << this->patr << std::endl;
	std::cout << "Дата рождения: " << this->dob.day << '.' << this->dob.month << '.' << this->dob.year << std::endl;
	std::cout << "Пол: " << this->sex << std::endl;
	std::cout << "Год поступления: " << this->enroll << std::endl;
	std::cout << "Факультет: " << this->faculty << ", кафедра " << this->chair << std::endl;
	std::cout << "Учебная группа: " << this->groupname << std::endl;
	std::cout << "Зачётная книжка №" << this->gradebook << std::endl;
	std::cout << "Успеваемость:" << std::endl;
	FORi(0, this->n_sessions) {
		std::cout << "-------------Сессия " << i + 1 << "------------" << std::endl;
		FORj(0, this->sessions[i].n_subjects) {
			std::cout << j+1 << ')' << std::left << std::setw(30) << std::setfill('.') <<
				this->sessions[i].subjects[j].title << 
				this->sessions[i].subjects[j].mark << std::endl;
		}
	}
}
std::ostream& operator << (std::ostream& _ostr, const Student& _stud) {
	_ostr << _stud.surn << ' ' << _stud.name << ' ' << _stud.patr << std::endl;
	_ostr << "Дата рождения: " << _stud.dob.day << '.' << _stud.dob.month << '.' << _stud.dob.year << std::endl;
	_ostr << "Пол: " << _stud.sex << std::endl;
	_ostr << "Год поступления: " << _stud.enroll << std::endl;
	_ostr << "Факультет: " << _stud.faculty << ", кафедра" << _stud.chair << std::endl;
	_ostr << "Учебная группа: " << _stud.groupname << std::endl;
	_ostr << "Зачётная книжка №" << _stud.gradebook << std::endl;
	_ostr << "Успеваемость: " << std::endl;
	FORi(0, _stud.n_sessions) {
		_ostr << "-------------Сессия " << i + 1 << "------------" << std::endl;
		FORj(0, _stud.sessions[i].n_subjects) {
			_ostr << j + 1 << ')' << std::left << std::setw(30) << std::setfill('.') <<
				_stud.sessions[i].subjects[j].title <<
				_stud.sessions[i].subjects[j].mark << std::endl;
		}
	}
	return _ostr;
}