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
Student& ListOfStudents::operator [] (const int _i) const {
	if ((_i >= this->iStudentsCount) || (_i < 0)) throw "Out of list range!";
	else {
		StudentNode* pCurrent = this->pBeg;
		FORi(0, _i) pCurrent = pCurrent->nextNode;
		return pCurrent->data;
	}
}
int ListOfStudents::Length() const { return this->iStudentsCount; }
int ListOfStudents::Append(Student stud) {
	if (this->StudentExists(stud.gradebook)) return 0; // if student exists - skip addition
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
	return 1;
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
int ListOfStudents::IsEmpty() const { return this->iStudentsCount == 0; }
StudentNode* ListOfStudents::Find(std::string& _gradebook) const {
	StudentNode* node = this->pBeg;
	while (node) {
		if (!strcmp(node->data.gradebook, _gradebook.c_str())) return node;
		node = node->nextNode;
	}
	return nullptr;
}
StudentNode* ListOfStudents::Find(const char* _gradebook) const {
	StudentNode* node = this->pBeg;
	while (node) {
		if (!strcmp(node->data.gradebook, _gradebook)) return node;
		node = node->nextNode;
	}
	return nullptr;
}
int ListOfStudents::StudentExists(std::string& _gradebook) const { return this->Find(_gradebook) ? 1 : 0; }
int ListOfStudents::StudentExists(const char* _gradebook) const { return this->Find(_gradebook) ? 1 : 0; }
int ListOfStudents::RemoveStudent(std::string& _gradebook) {
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
//Student& ListOfStudents::operator[] (const char* _gradebook) { // doesn't seem to work!
//	StudentNode* found = this->pBeg;
//	while (found) {
//		if (!strcmp(found->data.gradebook, _gradebook)) return found->data;
//		found = found->nextNode;
//	}
//	throw "Student not found"; // !!!
//}
int ListOfStudents::LoadFromFile(std::string& _filename) {
	if (!FileExists(_filename)) return 0;
	this->Reset();
	std::ifstream fin(_filename.c_str(), std::ios::in | std::ios::binary);
	Student fromFile;
	int iStudentsImported = 0;
	while (fin.read((char*)&fromFile, sizeof(Student))) {
		if (!this->StudentExists(fromFile.gradebook)) {
			this->Append(fromFile);
			iStudentsImported += 1;
		}
	}
	fin.close();
	return iStudentsImported;
}
int ListOfStudents::ExportToFile(std::string& _filename) {
	if (this->iStudentsCount <= 0) return 0;
	std::ofstream fout(_filename.c_str());
	int iStudentsExported = 0;
	StudentNode* node = this->pBeg;
	while (node) {
		fout.write((char*)node, sizeof(Student));
		iStudentsExported += 1;
		node = node->nextNode;
	}
	fout.close();
	return iStudentsExported;
}
void ListOfStudents::PrintStudents(int _toPrint = 0) const {
	std::cout << "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
	//std::cout << '|' << std::left << std::setw(30) << "ÔÀÌÈËÈß" << '|' << std::left << std::setw(300) << "ÈÌß" << '|' << std::left << std::setw(30) << "ÎÒ×ÅÑÒÂÎ" << 
	FORi(0, this->iStudentsCount) {
		std::cout << '|' << std::left << std::setw(30) << (*this)[i].surn <<
			'|' << std::left << std::setw(30) << (*this)[i].name <<
			'|' << std::left << std::setw(30) << (*this)[i].patr << '|' << std::endl;
	}
	return;
}