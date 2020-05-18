#pragma once
#include "Student.h"
#include <string>
class ListOfStudents {
private:
	struct studentNode {
		studentNode* nextNode;
		studentNode* prevNode;
		Student data;
	};
	studentNode* pBeg;
	studentNode* pEnd;
	int iStudentsCount;
public:
	ListOfStudents();
	ListOfStudents(Student*);        // implement list with one student at start // TODO
	void Reset();                    // clear list, free memory
	int LoadFromFile(std::string);   // load list from file ant return number of students loaded
	int ExportToFile(std::string);   // exprot to file and return number of students exported
	void append(Student);
	studentNode* find(std::string);
	int StudentExists(std::string);
	int RemoveStudent(std::string);
	int IsEmpty();
	Student& operator [] (const int);
};

