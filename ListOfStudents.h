#pragma once
#include <fstream>
#include <string>
#include <cstring>
#include "Student.h"
#include "Menu.h"

struct StudentNode {
	StudentNode* nextNode;
	StudentNode* prevNode;
	Student      data;
};
class ListOfStudents {
private:
	StudentNode* pBeg;
	StudentNode* pEnd;
	int          iStudentsCount;
public:
	ListOfStudents();
	ListOfStudents(Student);
	~ListOfStudents();
	StudentNode* Find(std::string&)  const;
	StudentNode* Find(const char*)   const;
	int Append(Student);
	int Length() const;
	int StudentExists(std::string&)  const;
	int StudentExists(const char*)   const;
	int StudentExists(const Student) const;
	int RemoveStudent(std::string&);
	int IsEmpty() const;
	int LoadFromFile(std::string&);
	int ExportToFile(std::string&);
	void Reset();
	void PrintStudents(int) const;
	void EditStudent(std::string&);
	Student& operator [] (const int) const;
	// Student& operator [] (const char*);
};