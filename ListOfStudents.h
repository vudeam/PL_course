#pragma once
#include <string>
#include <cstring>
#include "Student.h"

struct StudentNode {
	StudentNode* nextNode;
	StudentNode* prevNode;
	Student data;
};
class ListOfStudents {
private:
	StudentNode* pBeg;
	StudentNode* pEnd;
	int iStudentsCount;
public:
	ListOfStudents();
	ListOfStudents(Student);         // create list with one student at start
	~ListOfStudents();
	int Length();
	void Reset();                    // clear list, free memory
	void Append(Student);
	StudentNode* Find(std::string);
	int StudentExists(std::string);
	int RemoveStudent(std::string);
	int IsEmpty();
	int LoadFromFile(std::string);   // load list from file ant return number of students loaded
	int ExportToFile(std::string);   // exprot to file and return number of students exported
	Student& operator [] (const int);
};

