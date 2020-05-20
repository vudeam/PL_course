#pragma once
#include "Date.h"

class Person {
public:
	Person();
	Person(const char*, const char*, const char*, Date, char);
	virtual void IntroduceYourself() const;
protected:
	char name[30];
	char surn[30];
	char patr[30];
	Date dob;
	char sex;
};