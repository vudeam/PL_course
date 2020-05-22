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
int ListOfStudents::StudentExists(const Student _candidate) const {
	StudentNode* node = this->pBeg;
	while (node) {
		if (!strcmp(node->data.gradebook, _candidate.gradebook)) return 1;
		node = node->nextNode;
	}
	return 0;
}
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
	if (!fin) { std::cout << "�������� �������������� ������ ��� �������� �����. ���������� ��������."; return -1; }
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
	std::ofstream fout(_filename.c_str(), std::ios::out | std::ios::binary);
	if (!fout) { std::cout << "�������� �������������� ������ ��� �������� �����. ������ ��������."; return -1; }
	int iStudentsExported = 0;
	StudentNode* node = this->pBeg;
	while (node) {
		fout.write((char*)&node->data, sizeof(Student));
		iStudentsExported += 1;
		node = node->nextNode;
	}
	fout.close();
	return iStudentsExported;
}
void ListOfStudents::PrintStudents(int _toPrint = 0) const {
	int count = 0;
	if (_toPrint < 0) {
		std::cout << "������ ����������� ������������� ���������� ���������." << std::endl;
		return;
	}
	if ((_toPrint == 0) || (_toPrint > this->iStudentsCount)) count = this->iStudentsCount;
	else count = _toPrint;
	std::cout << std::endl << std::endl;
	std::cout << "|#  |" << "���. ����.|" << std::left << std::setw(30) << "�������" << '|' <<
		std::left << std::setw(30) << "���" << '|' <<
		std::left << std::setw(30) << "��������" << '|' <<
		"���|" << "���� ����.|" << "���.|" << "��������� |" << "�������   |" << "������� ��.    |" << "������� ���� �� ������              |" << std::endl;
	std::cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
	FORi(0, count) {
		std::cout << '|' << std::right << std::setfill('0') << std::setw(3) << i + 1 << '|' << std::setfill(' ');
		std::cout << std::left << std::setw(10) << (*this)[i].gradebook;
		std::cout << '|' << std::left << std::setw(30) << (*this)[i].surn <<
			'|' << std::left << std::setw(30) << (*this)[i].name <<
			'|' << std::left << std::setw(30) << (*this)[i].patr << '|';
		std::cout << ' ' << (*this)[i].sex << ' ' << '|' <<
			std::right << std::setfill('0') << std::setw(2) << (*this)[i].dob.day << '.' <<
			std::setfill('0') << std::setw(2) << (*this)[i].dob.month << '.' <<
			(*this)[i].dob.year << '|' << std::setfill(' ');
		std::cout << (*this)[i].enroll << '|';
		std::cout << std::left << std::setw(10) << (*this)[i].faculty << '|';
		std::cout << std::left << std::setw(10) << (*this)[i].chair << '|';
		std::cout << std::left << std::setw(15) << (*this)[i].groupname << '|';
		//std::cout << std::left << std::setw(10) << (*this)[i].gradebook << '|';
		FORj(0, 9) {
			if ((*this)[i].AverageScore(j+1) > 0) std::cout << std::fixed << std::setprecision(1) << (double)(*this)[i].AverageScore(j+1);
			else std::cout << " * ";
			std::cout << ' ';
		}
		std::cout << '|' << std::endl;
		std::cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;

	}
	return;
}
void ListOfStudents::EditStudent(std::string& _zach) {
	Menu* editMenu = nullptr;
	std::string items[] = {
		"0. ��������� ��������������",
		"1. �������",
		"2. ���",
		"3. ��������",
		"4. ���� ��������",
		"5. ��� �����������",
		"6. ���������",
		"7. �������",
		"8. ������� ������",
		"9. ����� �������� ������",
		"10. ���",
		"11. �������� � �������"
	};
	editMenu = new Menu(items, 12, MENUTYPE_KEYS);
	std::string name = "", surn = "", patr = "", faculty = "", chair = "", groupname = "", gradebook = _zach, gradebook_new = "", subjName = "";
	int day = 0, month = 0, year = 0, enroll = 0, n_sessions = 0, n_subjects = 0, subjMark = 0;
	char sex = '�';
	Student* NewStudent = nullptr;
	Date* dob = nullptr;
	Session* Sessions = nullptr;
	Subject* subjects = nullptr;
	dob = new Date();
	system("cls");
	while (87) {
		system("cls");
		std::cout << "�������:" << std::endl;
		this->Find(gradebook)->data.IntroduceYourself();
		std::cout << std::endl << "����� �������� ��������� ���������������?" << std::endl;
		switch (editMenu->SelectItem(-1)) { // display items and don't show number of students
		case 0:
			delete editMenu;
			system("cls");
			return;
			break;

		case 1:
			std::cout << "�������: ";
			surn = GetValidString(STR_RUS | STR_ENG);
			strcpy_s(this->Find(gradebook)->data.surn, surn.substr(0, 29).c_str());
			break;

		case 2:
			std::cout << "���: ";
			name = GetValidString(STR_RUS | STR_ENG);
			strcpy_s(this->Find(gradebook)->data.name, name.substr(0, 29).c_str());
			break;

		case 3:
			std::cout << "��������: ";
			patr = GetValidString(STR_ENG | STR_RUS);
			strcpy_s(this->Find(gradebook)->data.patr, patr.substr(0, 29).c_str());
			break;

		case 4:
			while (87) {
				std::cout << "���� �������� (��): ";
				day = stoi(GetValidString(STR_DIGITS).substr(0, 2));
				std::cout << "���� �������� (��): ";
				month = stoi(GetValidString(STR_DIGITS).substr(0, 2));
				std::cout << "���� �������� (����): ";
				year = stoi(GetValidString(STR_DIGITS).substr(0, 4));
				if (dob->ValiDate(day, month, year)) break;
				else std::cout << "�������� ���� ��������. ���������� �����." << std::endl;
			}
			this->Find(gradebook)->data.dob = *(new Date(day, month, year));
			break;

		case 5:
			while (87) {
				std::cout << "��� �����������: ";
				enroll = stoi(GetValidString(STR_DIGITS).substr(0, 4));
				if ((enroll - 16) > this->Find(gradebook)->data.dob.year) break;
				else std::cout << "�������� ��� �����������. ��������� ���������� �������." << std::endl;
			}
			this->Find(gradebook)->data.enroll = enroll;
			break;

		case 6:
			std::cout << "���������: ";
			faculty = GetValidString(STR_RUS);
			strcpy_s(this->Find(gradebook)->data.faculty, faculty.substr(0, 9).c_str());
			break;

		case 7:
			std::cout << "�������: ";
			chair = GetValidString(STR_RUS | STR_ENG | STR_DIGITS);
			strcpy_s(this->Find(gradebook)->data.chair, chair.substr(0, 9).c_str());
			break;

		case 8:
			std::cout << "������� ������: ";
			groupname = GetValidString(STR_RUS | STR_ENG | STR_DIGITS);
			strcpy_s(this->Find(gradebook)->data.groupname, groupname.substr(0, 14).c_str());
			break;

		case 9:
			std::cout << "����� �������� ������: ";
			gradebook_new = GetValidString(STR_ENG | STR_RUS | STR_DIGITS);
			if (this->StudentExists(gradebook_new)) {
				std::cout << "������� � ����� �� ������� �������� ������ ��� ����������.";
				CLEAN
				std::cout << "[Enter]";
				std::cin.get();
				CLEAN
			}
			else {
				strcpy_s(this->Find(gradebook)->data.gradebook, gradebook_new.substr(0, 9).c_str());
				gradebook = gradebook_new;
			}
			break;

		case 10:
			while (87) {
				std::cout << "��� (�/�): ";
				sex = GetValidString(STR_RUS)[0];
				if ((sex == '�') || (sex == '�')) break;
				else std::cout << "�������� ���. ���������� �����." << std::endl;
			}
			this->Find(gradebook)->data.sex = sex;
			break;

		case 11:
			std::cout << "---------- ���� ������ � ������� ��� �������� " <<
				this->Find(gradebook)->data.name << ' ' << this->Find(gradebook)->data.surn <<
				" ----------" << std::endl;
			while (87) {
				std::cout << "���������� ������ (1-9): ";
				n_sessions = stoi(GetValidString(STR_DIGITS).substr(0, 2));
				if ((n_sessions >= 1) && (n_sessions <= 9)) break;
				else std::cout << "�������� ���������� ������. ���������� �����." << std::endl;
			}
			Sessions = new Session[n_sessions];
			FORi(0, n_sessions) {
				std::cout << "[������ " << i + 1 << "] ";
				while (87) {
					std::cout << "���������� ��������� � ������ (1-10): ";
					n_subjects = stoi(GetValidString(STR_DIGITS).substr(0, 3));
					if ((n_subjects >= 1) && (n_subjects <= 10)) break;
					else std::cout << "�������� ���������� ���������. ���������� �����." << std::endl;
				}
				subjects = new Subject[n_subjects];
				FORj(0, n_subjects) {
					std::cout << "[������ " << i + 1 << "][������� " << j + 1 << "] �������� (�� 29 ��������): ";
					subjName = GetValidString(STR_SUBJ);
					strcpy_s(subjects[j].title, subjName.substr(0, 29).c_str());
					std::cout << "[������ " << i + 1 << "][������� " << j + 1 << "] ������ (2-5): ";
					while (87) {
						subjMark = stoi(GetValidString(STR_DIGITS).substr(0, 2));
						if ((subjMark >= 2) && (subjMark <= 5)) break;
						else std::cout << "�������� ������. ���������� �����.";
					}
					subjects[j].mark = subjMark;
					//Sessions[i].subjects[j] = subjects[j];
					Session s(n_subjects, subjects);
					Sessions[i] = s;
				}
			}
			this->Find(gradebook)->data.n_sessions = n_sessions;
			FORi(0, n_sessions) this->Find(gradebook)->data.sessions[i] = Sessions[i];
			delete[] Sessions;
			delete[] subjects;
			break;

		default:
			std::cout << "������ �������� �����. ���������� �����." << std::endl;
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			break;
		}
	}

	delete editMenu;
	return;
}