#pragma once
class Date {
public:
	int day;
	int month;
	int year;
	Date();
	Date(int, int, int);
	int ValiDate();
	int ValiDate(int, int, int);
};