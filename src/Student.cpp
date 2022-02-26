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

