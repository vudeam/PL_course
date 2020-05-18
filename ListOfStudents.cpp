#include "ListOfStudents.h"
ListOfStudents::ListOfStudents() : pBeg(nullptr), pEnd(nullptr), iStudentsCount(0) {};
void ListOfStudents::append(Student stud) {
	studentNode* node = (studentNode*) new studentNode;
	if (this->pBeg) {
		this->pBeg = this->pEnd = node;
		node->data = stud;
		this->iStudentsCount = 1;
	}
	else {
		node->prevNode = this->pEnd;
		this->pEnd->nextNode = node;
		this->pEnd = node;
	}
}