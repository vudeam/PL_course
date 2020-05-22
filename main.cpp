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

	ListOfStudents Group;
	mainMenu = new Menu(mainMenuItems, 8, MENUTYPE_ARROWS); // меню из таких-то пунктов, 7 штук, выбор стрелками
	Student* buf = nullptr;
	std::string filename = "";

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
				std::cout << "[ВВОД ЗАВЕРШЁН]" << std::endl << "ДОБАВЛЕННЫЙ СТУДЕНТ: " << Group[Group.Length() - 1];
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
			/* TODO */
			// ЖОПА

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