#include "Date.h"

Date::Date() : day(1), month(1), year(1970) {};
Date::Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {};
int Date::ValiDate() { return (this->day >= 1) && (this->day <= 31) && (this->month >= 1) && (this->month <= 12) && (this->year >= 1950) && (this->year <= 2019); }
int Date::ValiDate(int _day, int _month, int _year) { return (_day >= 1) && (_day <= 31) && (_month >= 1) && (_month <= 12) && (_year >= 1950) && (_year <= 2019); }