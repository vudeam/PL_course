#include <iostream>
#include <Windows.h>
#include <string>
#include "Menu.h"
#include "ListOfStudents.h"
#include "Stuff.h"

ListOfStudents* Group = nullptr;
Menu* mainMenu = nullptr;

std::string mainMenuItems[] = {
	"0. Выход",
	"1. Загрузка данных из файла",
	"2. Распечатка данных о студентах",
	"3. Добавление нового студента",
	"4. Редактирование данных о студенте",
	"5. Удаление студента",
	"6. Синхронизировать с файлом",
	"7. [Вариант 87]"
};

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double maxAverage = 0, minAverage = 0;
	int* SessionsToSelect;
	int iSession = -1, lowerYear = 0, upperYear = 0;
	ListOfStudents Group;
	mainMenu = new Menu(mainMenuItems, 8, MENUTYPE_ARROWS); // меню из таких-то пунктов, 7 штук, выбор стрелками
	Student* buf = nullptr;
	std::string filename = "", sessionsSelect = "";

	while (87) {
		// std::cout << "В программу загружено студентов: " << Group->Length() << std::endl << std::endl;
		switch (mainMenu->SelectItem(Group.Length())) { // метод добивается выбора пункта меню и возвращает его порядковый номер, начиная с 0
		case 0:
			system("cls");
			std::cout << "Завершение работы программы";
			Group.Reset();
			delete mainMenu;
			FORi(0, 3) { Sleep(500); std::cout << '.'; }
			return 0;
			break;

		case 1: // load list from the file
			std::cout << "Имя файла с данными о студентах >";
			filename = GetValidString(STR_PATH);
			std::cout << "Загружено студентов из файла: " << Group.LoadFromFile(filename) << std::endl;
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 2: // print students table
			if (Group.IsEmpty()) std::cout << "Отсутствуют данные о студентах. Добавьте их или загрузите из файла." << std::endl;
			else {
				system("cls");
				std::cout << "Предупреждение: большое количество студентов может замедлить работу программы." << std::endl;
				std::cout << "Сколько студентов распечатать? (0 - все): ";
				Group.PrintStudents(std::stoi(GetValidString(STR_DIGITS).substr(0, 5))); // fix number length
			}
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 3: // append new student
			if (Group.IsEmpty()) std::cout << "Добавьте информацию о первом студенте.";
			std::cout << std::endl;
			buf = InputStudent();
			if (Group.StudentExists(*buf)) {
				std::cout << "Ошибка добавления студента. Студент с введённым номером зачётной книжки (" <<
					buf->GetGradebook() << ") уже загружен в программу." << std::endl;
			}
			else {
				Group.Append(*buf);
				std::cout << "[ВВОД ЗАВЕРШЁН]" << std::endl << "ДОБАВЛЕННЫЙ СТУДЕНТ: " << std::endl;
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
				std::cout << "В программе отсутствуют студенты. Сначало нужно их добавить." << std::endl;
				system("pause");
			}
			else {
				std::cout << "Номер зачётной книжки студента, данные которого требуется отредактировать >";
				std::string zach(GetValidString(STR_RUS | STR_ENG | STR_DIGITS).substr(0, 15));
				if (Group.StudentExists(zach)) {
					Group.EditStudent(zach);
				}
				else {
					std::cout << "Не найден номер зачётной книжки. Попробуйте снова." << std::endl;
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
				std::cout << "В программе отсутствуют студенты. Сначало нужно их добавить." << std::endl;
			}
			else {
				std::cout << "Номер зачётной книжки студента, запись о котором требуется удалить >";
				std::string zach(GetValidString(STR_RUS | STR_ENG | STR_DIGITS).substr(0, 15));
				if (Group.RemoveStudent(zach)) {
					std::cout << "Студент с номером зачётной книжки " << zach << " удалён." << std::endl;
				}
				else {
					std::cout << "Не найден номер зачётной книжки. Попробуйте снова." << std::endl;
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
				std::cout << "В программе отсутствуют студенты. Сначало нужно их добавить." << std::endl;
			}
			else {
				std::cout << "Экспортировать данные в файл >";
				filename = GetValidString(STR_PATH);
				std::cout << "В файл записано студентов: " << Group.ExportToFile(filename) << std::endl;
			}
			CLEAN
			std::cout << "[Enter]";
			std::cin.get();
			CLEAN
			system("cls");
			break;

		case 7:
			if (Group.IsEmpty()) {
				std::cout << "В программе отсутствуют студенты. Сначало нужно их добавить." << std::endl;
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
				std::cout << "За какие сессии (1-9) делать выборку (0 - закончить выбор) [" << sessionsSelect << "] : ";
				iSession = stoi(GetValidString(STR_DIGITS).substr(0, 2));
				if (iSession == 0) break;
				if ((iSession < 0) || (iSession > 9)) std::cout << "Неверный номер сессии. Попробуйте снова" << std::endl;
				else {
					sessionsSelect += ' ' + std::to_string(iSession) + ' ';
				}
			}
			while (87) {
				std::cout << "Минимальный год рождения: ";
				lowerYear = stoi(GetValidString(STR_DIGITS).substr(0, 5));
				if (lowerYear >= 1980) break;
				else std::cout << "Неверный год. Проверьте возрастные границы." << std::endl;
			}
			while (87) {
				std::cout << "Максимальный год рождения: ";
				upperYear = stoi(GetValidString(STR_DIGITS).substr(0, 5));
				if ((upperYear < lowerYear) || (upperYear > 2020)) std::cout << "Неверный год. Он не должен быть ниже нижней границы или больше 2020 года" << std::endl;
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
				std::cout << std::endl << "Найденный минимальный средний балл за " << SessionsToSelect[j] << " сессию: " << minAverage << std::endl;
				std::cout << "Найденный максимальный средний балл за " << SessionsToSelect[j] << " сессию: " << maxAverage << std::endl;
				std::cout << std::endl << "НАИБОЛЕЕ УСПЕВАЮЩИЕ ЗА " << SessionsToSelect[j] << " СЕССИЮ:" << std::endl;
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
				std::cout << std::endl << "НАИМЕНЕЕ УСПЕВАЮЩИЕ ЗА " << SessionsToSelect[j] << " СЕССИЮ:" << std::endl;
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
			std::cout << "Как вы вообще сюда попали?\nНеверный пункт меню. Попробуйте снова." << std::endl;
			break;
		}
	}
	system("cls");
	std::cout << "Завершение работы программы";
	Group.Reset();
	delete mainMenu;
	FORi(0, 3) { Sleep(500); std::cout << '.'; }

	return 0;
}