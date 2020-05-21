#include <iostream>
#include <Windows.h>
#include <string>
#include "Menu.h"
#include "ListOfStudents.h"
#include "Stuff.h"

ListOfStudents* group = nullptr;
Menu* mainMenu = nullptr;

std::string mainMenuItems[] = {
	"0. Выход",
	"1. Загрузка данных из файла",
	"2. Распечатка данных о студентах",
	"3. Редактирование данных о студенте",
	"4. Удаление студента",
	"5. Выгрузка данных в файл",
	"6. [Вариант 87]"
};

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	group = new ListOfStudents();
	mainMenu = new Menu(mainMenuItems, 7, MENUTYPE_ARROWS); // меню из таких-то пунктов, 7 штук, выбор стрелками
	std::string filename;

	while (87) {
		switch (mainMenu->SelectItem()) { // метод добивается выбора пункта меню и возвращает его порядковый номер, начиная с 0
		case 0:
			system("cls");
			std::cout << "Завершение работы программы";
			FORi(0, 3) { Sleep(500); std::cout << '.'; }
			group->Reset();
			delete mainMenu;
			delete group;
			return 0;
			break;

		case 1:
			std::cout << "Имя файла с данными о студентах >";
			filename = GetValidString(STR_PATH);
			group->Reset();
			group->LoadFromFile(filename);
			break;

		case 2:
			if (group->IsEmpty()) std::cout << "Отсутствуют данные о студентах. Добавьте их или загрузите из файла." << std::endl;
			else {
				std::cout << "Сколько студентов распечатать? (0 - все). Предупреждение: большое количество студентов может замедлить работу программы";
				group->PrintStudents(std::stoi(GetValidString(STR_DIGITS))); // fix number length
			}
			break;

		case 3:
			if (group->IsEmpty()) {
				std::cout << "В группе отсутствуют студенты. Сначало нужно их добавить." << std::endl;
				system("pause");
			}
			else {
				std::cout << "Номер зачётной книжки студента, данные которого требуется отредактировать >";
				std::string zach(GetValidString(STR_RUS | STR_DIGITS));
				if (group->StudentExists(zach)) {
					//group->EditStudent(zach);
				}
				else {
					std::cout << "Не найден номер зачётной книжки. Попробуйте снова." << std::endl;
				}
			}
			break;

		case 4:
			if (group->IsEmpty()) {
				std::cout << "В группе отсутствуют студенты. Сначало нужно их добавить." << std::endl;
			}
			else {
				std::cout << "Номер зачётной книжки студента, данные которого требуется отредактировать >";
				std::string zach(GetValidString(STR_RUS | STR_DIGITS));
				if (group->StudentExists(zach)) {
					group->RemoveStudent(zach);
				}
				else {
					std::cout << "Не найден номер зачётной книжки. Попробуйте снова." << std::endl;
				}
			}
			break;

		case 5:
			std::cout << "Экспортировать данные в файл >";
			filename = GetValidString(STR_PATH);
			group->ExportToFile(filename);
			// group.Reset() ??
			break;

		case 6:
			/* TODO */
			// ЖОПА

		default:
			std::cout << "Как вы вообще сюда попали?\nНеверный пункт меню. Попробуйте снова." << std::endl;
			break;
		}
	}
	delete mainMenu;
	delete group;

	return 0;
}