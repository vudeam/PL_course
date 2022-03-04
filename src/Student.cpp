#include "../include/Student.hpp"

#include <algorithm>


Session::Session (std::size_t nSubj, Subject * arrSubjects)
    : nSubjects{nSubj}
{
    for (std::size_t i = 0; i < nSubj; i++) subjects[i] = arrSubjects[i];
}

bool
Session::HasSubject (const std::string & subjName) const
{
    return std::find(std::begin(subjects), std::end(subjects), subjName)
           != std::end(subjects);
}

Student::Student (const std::string & name,
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
                  std::array<Session, 9> ses)
    : Person{name, surn, patr, dob, sex}
    , enrollYear{enroll}
    , faculty{fac}
    , chair{chair}
    , groupname{group}
    , gradebook{grade}
    , nSessions{nSes}
    , sessions{ses}
{}
