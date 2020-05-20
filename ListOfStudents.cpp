#include "ListOfStudents.h"
#include "Stuff.h"

ListOfStudents::ListOfStudents() : pBeg(nullptr), pEnd(nullptr), iStudentsCount(0) {};
ListOfStudents::ListOfStudents(Student stud) : pBeg(nullptr), pEnd(nullptr), iStudentsCount(0) { this->Append(stud); }
ListOfStudents::~ListOfStudents() {
	if (this->pBeg) {
		StudentNode* toRemove = this->pBeg;
		while (toRemove) {
			toRemove = toRemove->nextNode;
			delete this->pBeg;
			this->pBeg = toRemove;
		}
	}
}
Student& ListOfStudents::operator [] (const int _i) {
	if ((_i >= this->iStudentsCount) || (_i < 0)) throw "Out of list range!";
	else {
		StudentNode* pCurrent = this->pBeg;
		FORi(0, _i) pCurrent = pCurrent->nextNode;
		return pCurrent->data;
	}
}
int ListOfStudents::Length() { return this->iStudentsCount; }
void ListOfStudents::Append(Student stud) {
	StudentNode* node = (StudentNode*) new StudentNode;
	node->data = stud;
	node->nextNode = nullptr;
	node->prevNode = nullptr;
	if (this->pBeg) { // if not first of the list
		node->prevNode = this->pEnd;
		this->pEnd->nextNode = node;
		this->pEnd = node;
	}
	else {
		this->pBeg = this->pEnd = node;
	}
	this->iStudentsCount += 1;
}
void ListOfStudents::Reset() {
	if (this->pBeg) {
		StudentNode* toRemove = this->pBeg;
		while (toRemove) {
			toRemove = toRemove->nextNode;
			delete this->pBeg;
			this->pBeg = toRemove;
		}
	}
	this->pBeg = this->pEnd = nullptr;
	this->iStudentsCount = 0;
}
int ListOfStudents::IsEmpty() { return this->iStudentsCount == 0; }
StudentNode* ListOfStudents::Find(std::string _gradebook) {
	StudentNode* node = this->pBeg;
	while (node) {
		if (!strcmp(node->data.gradebook, _gradebook.c_str())) return node;
		node = node->nextNode;
	}
	return nullptr;
}
int ListOfStudents::StudentExists(std::string _gradebook) { return this->Find(_gradebook) ? 1 : 0; }
int ListOfStudents::RemoveStudent(std::string _gradebook) {
	if (StudentNode* toRemove = this->Find(_gradebook)) {
		if ((toRemove == this->pBeg) && (toRemove == this->pEnd)) { // last and only element
			this->pBeg = this->pEnd = nullptr;
		}
		else if (toRemove == this->pBeg) {          // head
			this->pBeg = this->pBeg->nextNode;
			this->pBeg->prevNode = nullptr;
		}
		else if (toRemove == this->pEnd) {     // tail
			this->pEnd = this->pEnd->prevNode;
			this->pEnd->nextNode = nullptr;
		}
		else {
			(toRemove->prevNode)->nextNode = toRemove->nextNode;
			(toRemove->nextNode)->prevNode = toRemove->prevNode;
		}
		delete toRemove;
		this->iStudentsCount -= 1;
		return 1;
	}
	return 0;
}