#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Stuff.h"

class Menu {
private:
	int iItemsCount;
	int TYPE;
	std::string* strItemsArr;
public:
	Menu();
	Menu(std::string*, int, int);
	~Menu();
	int SelectItem(int) const; // display menu and select item. int to display number of students in the list
	// void PrintMenu() const;
};