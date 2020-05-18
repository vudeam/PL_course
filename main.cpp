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

	/*
	FILE* f = nullptr;
	fopen_s(&f, "group.mersov", "w");
	std::fstream finout;
	finout.open("group_fstream.mersov", std::ios::out | std::ios::binary);
	Student* group = (Student*) new Student[N_PEOPLE];
	for (int i = 0; i < N_PEOPLE; i++) {
		std::cout << "Student #" << i + 1 << std::endl << "FIO >";
		strcpy_s(group[i].FIO, "Иван");
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
	mainMenu = new Menu(mainMenuItems, 7, MENUTYPE_ARROWS); // меню из таких-то пунктов, 7 штук, выбор стрелками
	std::string filename;

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
		std::cout << "Сколько студентов распечатать? (0 - все) ";
		group->PrintStudents(std::stoi(GetValidString(STR_DIGITS)));
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
				group->EditStudent(zach);
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

	delete mainMenu;
	delete group;

	return 0;
}