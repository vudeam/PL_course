#pragma once
#include "Stuff.h"
#include <string>
#include <iostream>
#include <conio.h>

class Menu {
private:
	int iItemsCount;
	int TYPE;
	std::string* strItemsArr;
public:
	Menu();
	Menu(std::string*, int, int);
	~Menu();
	int SelectItem() const;
	void PrintMenu() const;
};
