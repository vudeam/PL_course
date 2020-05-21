#include <iostream>
#include <Windows.h>
#include <string>
#include "Menu.h"
#include "ListOfStudents.h"
#include "Stuff.h"

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

	group = new ListOfStudents();
	mainMenu = new Menu(mainMenuItems, 7, MENUTYPE_ARROWS); // ���� �� �����-�� �������, 7 ����, ����� ���������
	std::string filename;

	while (87) {
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
			if (group->IsEmpty()) std::cout << "����������� ������ � ���������. �������� �� ��� ��������� �� �����." << std::endl;
			else {
				std::cout << "������� ��������� �����������? (0 - ���). ��������������: ������� ���������� ��������� ����� ��������� ������ ���������";
				group->PrintStudents(std::stoi(GetValidString(STR_DIGITS))); // fix number length
			}
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
					//group->EditStudent(zach);
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
	}
	delete mainMenu;
	delete group;

	return 0;
}