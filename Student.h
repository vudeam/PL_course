#pragma once
#include "Person.h"
struct Subject {
	char title[30];
	int mark;
};
class Session {
public:
	int n_subjects;
	Subject subjects[10];
};
class Student : private Person {
private:
	int enroll;
	char faculty[10];
	char chair[10];
	char gradebook[10];
	Session* sessions;
	int n_sessions;
public:
	Student();
	Student(const char*, const char*, const char*, Date, char, int, const char*, const char*, const char*, Session*, int);
	void IntroduceYourself() const;
};