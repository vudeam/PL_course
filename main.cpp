#include <iostream>
#include <Windows.h>
#include <string>
#include "Stuff.h"
//#include "Group.h"
#include "ListOfStudents.h"
#include "Menu.h"

ListOfStudents* group = nullptr;
Menu* mainMenu = nullptr;

std::string mainMenuItems[] = {
	"0. �����",
	"1. �������� ������ �� �����",
	"2. ���������� ������ � ���������",
	"3. �������������� ������ � ��������",
	"4. �������� ��������",
	"5. �������� ������ � ����",
	"6. [������� 87]"
};

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*
	FILE* f = nullptr;
	fopen_s(&f, "group.mersov", "w");
	std::fstream finout;
	finout.open("group_fstream.mersov", std::ios::out | std::ios::binary);
	Student* group = (Student*) new Student[N_PEOPLE];
	for (int i = 0; i < N_PEOPLE; i++) {
		std::cout << "Student #" << i + 1 << std::endl << "FIO >";
		strcpy_s(group[i].FIO, "����");
		std::cout << "subject1 >";
		std::cin >> group[i].marks[0].title;
		std::cout << "mark1 >";
		std::cin >> group[i].marks[0].mark;
		std::cout << "subject2 >";
		std::cin >> group[i].marks[1].title;
		std::cout << "mark1 >";
		std::cin >> group[i].marks[0].mark;
		std::cout << std::endl;
		fwrite(group, sizeof(Student), 1, f);
	}
	std::cout << "\nWriting to a file...";
	fwrite(group, sizeof(Student), N_PEOPLE, f);
	finout.write((char*)group, N_PEOPLE * sizeof(Student));
	fclose(f);
	finout.close();
	fopen_s(&f, "group.mersov", "r");
	fseek(f, 2 * sizeof(Student), SEEK_SET);
	Student from_file;
	fread(&from_file, sizeof(Student), 1, f);
	std::cout << from_file.FIO << ';' << from_file.marks[0].title << ':' << from_file.marks[0].mark << ';' << from_file.marks[1].title << ':' << from_file.marks[1].mark << std::endl;
	finout.open("group_fstream.mersov", std::ios::in | std::ios::binary);
	Student fromFile;
	while (!finout.read((char*)&fromFile, sizeof(Student)).eof()) std::cout << fromFile.FIO << ';' << fromFile.marks[0].title << ':' << fromFile.marks[0].mark << ';' << fromFile.marks[1].title << ':' << fromFile.marks[0].mark << std::endl;
	finout.close();
	*/

	group = new ListOfStudents();
	mainMenu = new Menu(mainMenuItems, 7, MENUTYPE_ARROWS); // ���� �� �����-�� �������, 7 ����, ����� ���������
	std::string filename;

	switch (mainMenu->SelectItem()) { // ����� ���������� ������ ������ ���� � ���������� ��� ���������� �����, ������� � 0
	case 0:
		system("cls");
		std::cout << "���������� ������ ���������";
		FORi(0, 3) { Sleep(500); std::cout << '.'; }
		group->Reset();
		delete mainMenu;
		delete group;
		return 0;
		break;

	case 1:
		std::cout << "��� ����� � ������� � ��������� >";
		filename = GetValidString(STR_PATH);
		group->Reset();
		group->LoadFromFile(filename);
		break;
	
	case 2:
		std::cout << "������� ��������� �����������? (0 - ���) ";
		group->PrintStudents(std::stoi(GetValidString(STR_DIGITS)));
		break;

	case 3:
		if (group->IsEmpty()) {
			std::cout << "� ������ ����������� ��������. ������� ����� �� ��������." << std::endl;
			system("pause");
		}
		else {
			std::cout << "����� �������� ������ ��������, ������ �������� ��������� ��������������� >";
			std::string zach(GetValidString(STR_RUS | STR_DIGITS));
			if (group->StudentExists(zach)) {
				group->EditStudent(zach);
			}
			else {
				std::cout << "�� ������ ����� �������� ������. ���������� �����." << std::endl;
			}
		}
		break;

	case 4:
		if (group->IsEmpty()) {
			std::cout << "� ������ ����������� ��������. ������� ����� �� ��������." << std::endl;
		}
		else {
			std::cout << "����� �������� ������ ��������, ������ �������� ��������� ��������������� >";
			std::string zach(GetValidString(STR_RUS | STR_DIGITS));
			if (group->StudentExists(zach)) {
				group->RemoveStudent(zach);
			}
			else {
				std::cout << "�� ������ ����� �������� ������. ���������� �����." << std::endl;
			}
		}
		break;
	
	case 5:
		std::cout << "�������������� ������ � ���� >";
		filename = GetValidString(STR_PATH);
		group->ExportToFile(filename);
		// group.Reset() ??
		break;

	case 6:
		/* TODO */
		// ����

	default:
		std::cout << "��� �� ������ ���� ������?\n�������� ����� ����. ���������� �����." << std::endl;
		break;
	}

	delete mainMenu;
	delete group;

	return 0;
}