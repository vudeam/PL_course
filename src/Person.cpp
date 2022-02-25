#include "../include/Person.hpp"

#include <iostream>


Person::Person (std::string name,
                std::string surn,
                std::string patr,
                Date dob,
                unsigned char sex)
    : name{name}
    , surn{surn}
    , patr{patr}
    , dob{dob}
    , sex{sex}
{}

void
Person::IntroduceYourself () const
{
    std::cout << name + " " + surn << "\n"
              << "Дата рождения:" << dob.day << "." << dob.month << "." << dob.year << "\n"
              << "Пол: " << sex << "\n";
}

