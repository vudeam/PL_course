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
	int SelectItem(int) const;
	// void PrintMenu() const;
};