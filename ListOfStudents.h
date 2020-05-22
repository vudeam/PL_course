#pragma once
#include <fstream>
#include <string>
#include <cstring>
#include "Student.h"
#include "Menu.h"

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
	ListOfStudents(Student);                 // create list with one student at start
	~ListOfStudents();
	int Length() const;
	void Reset();                            // clear list, free memory
	int Append(Student);
	StudentNode* Find(std::string&) const;   // find student by gradebook (returns pointer or nullptr)
	StudentNode* Find(const char*) const;    // find student by gradebook (returns pointer or nullptr)
	int StudentExists(std::string&) const;   // 1 if student with given gradebook exists else 0
	int StudentExists(const char*) const;    // 1 if student with given gradebook exists else 0
	int StudentExists(const Student) const;  // 1 if student with given student's gradebook exists
	int RemoveStudent(std::string&);         // 1 if student removed; 0 if student was not found
	int IsEmpty() const;
	int LoadFromFile(std::string&);          // load list from file ant return number of students loaded
	int ExportToFile(std::string&);          // exprot to file and return number of students exported
	// Student& operator [] (const char*);
	void PrintStudents(int) const;
	void EditStudent(std::string&);
	Student& operator [] (const int) const;
};