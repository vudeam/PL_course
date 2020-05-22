#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
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
	int HasSubject(std::string&) const;
	int HasSubject(const char*) const;
};
class Student : private Person {
private:
	int      enroll;
	char     faculty  [10];
	char     chair    [10];
	char     groupname[15];
	char     gradebook[10];
	Session  sessions [9];
	int      n_sessions;
public:
	Student();
	Student(const char*, const char*, const char*, Date, char, int, const char*, const char*, const char*, const char*, Session*, int);
	void IntroduceYourself() const;
	double AverageScore() const;     // calculate student's average score for all sessions
	double AverageScore(int) const;  // calculate student's average score for a given session (1-9)
	const char* GetGradebook() const;
	friend std::ostream& operator << (std::ostream&, const Student&);
	friend class ListOfStudents;
};