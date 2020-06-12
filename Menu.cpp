#include "Menu.h"

Menu::Menu() {
	this->iItemsCount = -1;
	this->TYPE = 0;
	this->strItemsArr = new std::string[2];
	this->strItemsArr[0] = "[Меню не инициализировано]";
	this->strItemsArr[1] = "[Menu is not initialized]";
}
Menu::Menu(std::string* _menuItems, int nItems, int _TYPE) {
	this->TYPE = _TYPE;
	this->iItemsCount = nItems;
	this->strItemsArr = new std::string[nItems];
	FORi(0, nItems) this->strItemsArr[i] = _menuItems[i];
}
Menu::~Menu() {
	delete[] this->strItemsArr;
}
int Menu::SelectItem(int numStudents = -1) const {
	if (this->TYPE == MENUTYPE_ARROWS && this->iItemsCount > 0) {
		int cursorPosition = 0, ready = 0;
		while (!ready) {
			if (numStudents != -1) {
				std::cout << "В программу загружено студентов: " << numStudents << std::endl << std::endl;
			}
			FORi(0, this->iItemsCount) {
				if (cursorPosition == i) std::cout << " > " << this->strItemsArr[i] << std::endl;
				else std::cout << "   " << this->strItemsArr[i] << std::endl;
			}
			switch (_getch()) {
			case KEY_LOWER_W:
			case KEY_ARROW_UP:
				cursorPosition -= 1;
				if (cursorPosition < 0) cursorPosition = 0;
				system("cls");
				break;
			case KEY_LOWER_S:
			case KEY_ARROW_DOWN:
				cursorPosition += 1;
				if (cursorPosition > this->iItemsCount - 1) cursorPosition = this->iItemsCount - 1;
				system("cls");
				break;
			case 13:
				ready = 1;
				// system("cls");
				break;
			default:
				system("cls");
				break;
			}
		}
		return cursorPosition;
	}
	else if (this->TYPE == MENUTYPE_KEYS && this->iItemsCount > 0) {
		if (numStudents != -1) {
			std::cout << "В программу загружено студентов: " << numStudents << std::endl << std::endl;
		}
		FORi(0, this->iItemsCount) std::cout << this->strItemsArr[i] << std::endl;
		int selectedItem = 0;
		selectedItem = std::stoi(GetValidString(STR_DIGITS).substr(0, 3));
		return selectedItem;
	}
	else {
		std::cout << "Выбран неверный тип меню." << std::endl;
	}
	return -1;
}