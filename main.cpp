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

	double maxAverage = 0, minAverage = 0;
	int* SessionsToSelect;
	int iSession = -1, lowerYear = 0, upperYear = 0;
	ListOfStudents Group;
	mainMenu = new Menu(mainMenuItems, 8, MENUTYPE_ARROWS); // ���� �� �����-�� �������, 7 ����, ����� ���������
	Student* buf = nullptr;
	std::string filename = "", sessionsSelect = "";

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
				std::cout << "[���� �����ب�]" << std::endl << "����������� �������: " << std::endl;
				Group[Group.Length() - 1].IntroduceYourself();
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
			if (Group.IsEmpty()) {
				std::cout << "� ��������� ����������� ��������. ������� ����� �� ��������." << std::endl;
				CLEAN
				std::cout << "[Enter]";
				std::cin.get();
				CLEAN
				system("cls");
				break;
			}
			sessionsSelect = "";
			maxAverage = minAverage = 0;
			lowerYear = upperYear = 0;
			while (87) {
				std::cout << "�� ����� ������ (1-9) ������ ������� (0 - ��������� �����) [" << sessionsSelect << "] : ";
				iSession = stoi(GetValidString(STR_DIGITS).substr(0, 2));
				if (iSession == 0) break;
				if ((iSession < 0) || (iSession > 9)) std::cout << "�������� ����� ������. ���������� �����" << std::endl;
				else {
					sessionsSelect += ' ' + std::to_string(iSession) + ' ';
				}
			}
			while (87) {
				std::cout << "����������� ��� ��������: ";
				lowerYear = stoi(GetValidString(STR_DIGITS).substr(0, 5));
				if (lowerYear >= 1980) break;
				else std::cout << "�������� ���. ��������� ���������� �������." << std::endl;
			}
			while (87) {
				std::cout << "������������ ��� ��������: ";
				upperYear = stoi(GetValidString(STR_DIGITS).substr(0, 5));
				if ((upperYear < lowerYear) || (upperYear > 2020)) std::cout << "�������� ���. �� �� ������ ���� ���� ������ ������� ��� ������ 2020 ����" << std::endl;
				else break;
			}
			if (sessionsSelect.empty()) {
				CLEAN
				std::cout << "[Enter]";
				std::cin.get();
				CLEAN
				system("cls");
				break;
			}
			iSession = 0;
			FORi(0, sessionsSelect.length()) {
				if (((sessionsSelect[i] - '0') > 0) && ((sessionsSelect[i] - '0') < 10)) iSession += 1;
			}
			SessionsToSelect = new int[iSession];
			iSession = 0;
			FORi(0, sessionsSelect.length()) {
				if (((sessionsSelect[i] - '0') > 0) && ((sessionsSelect[i] - '0') < 10)) {
					SessionsToSelect[iSession] = sessionsSelect[i] - '0';
					iSession += 1;
				}
			}
			FORj(0, iSession) { // iterate through each session number in 
				//maxAverage = minAverage = Group[0].AverageScore(SessionsToSelect[j]); // set max & min to first average
				FORi(0, Group.Length()) { // find first non-zero average score
					if ((Group[i].GetDOBYear() <= upperYear) && (Group[i].GetDOBYear() >= lowerYear)) // find student within bounds
					if ((Group[i].AverageScore(SessionsToSelect[j]) > 0)) {
						maxAverage = minAverage = Group[i].AverageScore(SessionsToSelect[j]);
						break;
					}
				}
				FORi(0, Group.Length()) {
					if ((Group[i].GetDOBYear() <= upperYear) && (Group[i].GetDOBYear() >= lowerYear)) {
						if ((maxAverage < Group[i].AverageScore(SessionsToSelect[j])) && (Group[i].AverageScore(SessionsToSelect[j]) > 0))
							maxAverage = Group[i].AverageScore(SessionsToSelect[j]);
						if ((minAverage > Group[i].AverageScore(SessionsToSelect[j]) && (Group[i].AverageScore(SessionsToSelect[j]) > 0)))
							minAverage = Group[i].AverageScore(SessionsToSelect[j]);
					}
				}
				std::cout << std::endl << "��������� ����������� ������� ���� �� " << SessionsToSelect[j] << " ������: " << minAverage << std::endl;
				std::cout << "��������� ������������ ������� ���� �� " << SessionsToSelect[j] << " ������: " << maxAverage << std::endl;
				std::cout << std::endl << "�������� ���������� �� " << SessionsToSelect[j] << " ������:" << std::endl;
				std::cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
				FORi(0, Group.Length()) {
					if ((Group[i].GetDOBYear() <= upperYear) && (Group[i].GetDOBYear() >= lowerYear))
					if (maxAverage == Group[i].AverageScore(SessionsToSelect[j])) {
						std::cout << '|' << std::right << std::setfill('0') << std::setw(3) <<
							i + 1 << '|' << std::setfill(' ') <<
							Group[i] << std::endl;
						std::cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
					}
				}
				std::cout << std::endl;
				std::cout << std::endl << "�������� ���������� �� " << SessionsToSelect[j] << " ������:" << std::endl;
				std::cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
				FORi(0, Group.Length()) {
					if ((Group[i].GetDOBYear() <= upperYear) && (Group[i].GetDOBYear() >= lowerYear))
					if (minAverage == Group[i].AverageScore(SessionsToSelect[j])) {
						std::cout << '|' << std::right << std::setfill('0') << std::setw(3) <<
							i + 1 << '|' << std::setfill(' ') <<
							Group[i] << std::endl;
						std::cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
					}
				}
				CLEAN
				std::cout << "[Enter]";
				std::cin.get();
				CLEAN
			}
			delete[] SessionsToSelect;
			system("cls");
			break;

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