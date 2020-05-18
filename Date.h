#pragma once
class Date {
public:
	int day;
	int month;
	int year;
	Date(); // 01 Jan 1970
	Date(int, int, int);
	int ValiDate(); // validate the caller
	int ValiDate(int, int, int); // validate any date
};

