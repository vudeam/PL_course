#ifndef STUDENT_HPP
#define STUDENT_HPP


#include "Person.hpp"

#include <array>
#include <cstddef>
#include <iosfwd>
#include <string>


class Subject
{
public:

    std::string title;
    int mark;
};

class Session
{
public:

    Session () = default;
    Session (std::size_t nSubjects, Subject * arr);

    bool
    HasSubject (const std::string & subjName) const;

    std::size_t nSubjects;
    std::array<Subject, 10> subjects;
};

class Student : public Person
{
public:

    Student () = default;
    Student (const std::string & name,
             const std::string & surn,
             const std::string & patr,
             Date dob,
             unsigned char sex,
             std::size_t enroll,
             const std::string & fac,
             const std::string & chair,
             const std::string & group,
             const std::string & grade,
             const std::size_t nSes,
             std::array<Session, 9> ses);

    friend std::ostream &
    operator<< (std::ostream & os, const Student & stud);

    virtual void
    IntroduceYourself () const;

    std::string
    GetGradebook () const;

    int
    GetDOBYear () const;

    double
    CalcAvgGrade () const;

    double
    CalcAvgGrade (std::size_t sessionNum) const;

private:

    std::size_t            enrollYear;
    std::string            faculty;
    std::string            chair;
    std::string            groupname;
    std::string            gradebook;
    std::array<Session, 9> sessions;
    std::size_t            nSessions;
};


#endif        /* STUDENT_HPP */

