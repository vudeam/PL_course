#pragma once
#include <iostream>
#include "Person.h"

struct Subject {
	char title[30];
	int mark;
};
class Session {
public:
	int n_subjects;
	Subject subjects[10];
	Session();
	Session(int, Subject*);
};
class Student : private Person {
private:
	int      enroll;
	char     faculty[10];
	char     chair[10];
	char     groupname[15];
	char     gradebook[10];
	Session  sessions[9];
	int      n_sessions;
public:
	Student();
	Student(const char*, const char*, const char*, Date, char, int, const char*, const char*, const char*, const char*, Session*, int);
	void IntroduceYourself() const;
	friend std::ostream& operator << (std::ostream&, const Student&);
	friend class ListOfStudents;
};