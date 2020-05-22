#include <iostream>
#include <Windows.h>
#include <string>
#include "Menu.h"
#include "ListOfStudents.h"
#include "Stuff.h"

ListOfStudents* Group = nullptr;
Menu* mainMenu = nullptr;

std::string mainMenuItems[] = {
	"0. �����",
	"1. �������� ������ �� �����",
	"2. ���������� ������ � ���������",
	"3. ���������� ������ ��������",
	"4. �������������� ������ � ��������",
	"5. �������� ��������",
	"6. ���������������� � ������",
	"7. [������� 87]"
};

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ListOfStudents Group;
	mainMenu = new Menu(mainMenuItems, 8, MENUTYPE_ARROWS); // ���� �� �����-�� �������, 7 ����, ����� ���������
	Student* buf = nullptr;
	std::string filename = "";

	while (87) {
		// std::cout << "� ��������� ��������� ���������: " << Group->Length() << std::endl << std::endl;
		switch (mainMenu->SelectItem(Group.Length())) { // ����� ���������� ������ ������ ���� � ���������� ��� ���������� �����, ������� � 0
		case 0:
			system("cls");
			std::cout << "���������� ������ ���������";
			Group.Reset();
			delete mainMenu;
			FORi(0, 3) { Sleep(500); std::cout << '.'; }
			return 0;
			break;

		case 1: // load list from the file
			std::cout << "��� ����� � ������� � ��������� >";
			filename = GetValidString(STR_PATH);
			std::cout << "��������� ��������� �� �����: " << Group.LoadFromFile(filename) << std::endl;
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 2: // print students table
			if (Group.IsEmpty()) std::cout << "����������� ������ � ���������. �������� �� ��� ��������� �� �����." << std::endl;
			else {
				system("cls");
				std::cout << "��������������: ������� ���������� ��������� ����� ��������� ������ ���������." << std::endl;
				std::cout << "������� ��������� �����������? (0 - ���): ";
				Group.PrintStudents(std::stoi(GetValidString(STR_DIGITS).substr(0, 5))); // fix number length
			}
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 3: // append new student
			if (Group.IsEmpty()) std::cout << "�������� ���������� � ������ ��������.";
			std::cout << std::endl;
			buf = InputStudent();
			if (Group.StudentExists(*buf)) {
				std::cout << "������ ���������� ��������. ������� � �������� ������� �������� ������ (" <<
					buf->GetGradebook() << ") ��� �������� � ���������." << std::endl;
			}
			else {
				Group.Append(*buf);
				std::cout << "[���� �����ب�]" << std::endl << "����������� �������: " << Group[Group.Length() - 1];
			}
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 4: // edit student
			if (Group.IsEmpty()) {
				std::cout << "� ��������� ����������� ��������. ������� ����� �� ��������." << std::endl;
				system("pause");
			}
			else {
				std::cout << "����� �������� ������ ��������, ������ �������� ��������� ��������������� >";
				std::string zach(GetValidString(STR_RUS | STR_ENG | STR_DIGITS).substr(0, 15));
				if (Group.StudentExists(zach)) {
					Group.EditStudent(zach);
				}
				else {
					std::cout << "�� ������ ����� �������� ������. ���������� �����." << std::endl;
				}
			}
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 5: // remove student
			if (Group.IsEmpty()) {
				std::cout << "� ��������� ����������� ��������. ������� ����� �� ��������." << std::endl;
			}
			else {
				std::cout << "����� �������� ������ ��������, ������ � ������� ��������� ������� >";
				std::string zach(GetValidString(STR_RUS | STR_ENG | STR_DIGITS).substr(0, 15));
				if (Group.RemoveStudent(zach)) {
					std::cout << "������� � ������� �������� ������ " << zach << " �����." << std::endl;
				}
				else {
					std::cout << "�� ������ ����� �������� ������. ���������� �����." << std::endl;
				}
			}
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 6: // sync with the file
			if (Group.IsEmpty()) {
				std::cout << "� ��������� ����������� ��������. ������� ����� �� ��������." << std::endl;
			}
			else {
				std::cout << "�������������� ������ � ���� >";
				filename = GetValidString(STR_PATH);
				std::cout << "� ���� �������� ���������: " << Group.ExportToFile(filename) << std::endl;
			}
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 7:
			/* TODO */
			// ����

		default:
			std::cout << "��� �� ������ ���� ������?\n�������� ����� ����. ���������� �����." << std::endl;
			break;
		}
	}
	system("cls");
	std::cout << "���������� ������ ���������";
	Group.Reset();
	delete mainMenu;
	FORi(0, 3) { Sleep(500); std::cout << '.'; }

	return 0;
}