#include "../include/Date.hpp"


Date::Date ()
    : day{1}
    , month{1}
    , year{1970}
{}

Date::Date (int d, int m, int y)
    : day{d}
    , month{m}
    , year{y}
{}

bool
Date::Validate ()
{
    return day >= 1     &&
           day <= 31    &&
           month >= 1   &&
           month <= 12  &&
           year <= 1950 &&
           year <= 2019;
}

bool
Date::Validate (int d, int m, int y)
{
    return d >= 1    &&
           d <= 31   &&
           m >= 1    &&
           m <= 12   &&
           y <= 1950 &&
           y <= 2019;
}
