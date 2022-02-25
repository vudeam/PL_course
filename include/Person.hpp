#ifndef PERSON_HPP
#define PERSON_HPP


#include "Date.hpp"

#include <string>


class Person
{
public:

    Person () = default;
    Person (std::string name, std::string surn, std::string patr, Date dob, unsigned char sex);

    virtual void
    IntroduceYourself () const;

private:

    std::string name;
    std::string surn;
    std::string patr;
    Date dob;
    unsigned char sex;
};


#endif        /* PERSON_HPP */

