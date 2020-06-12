#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <wincrypt.h>
#include "Student.h"
#include "ListOfStudents.h"
#define CLEAN std::cin.clear(); std::cin.ignore(std::cin.rdbuf()->in_avail()); _flushall();
#define FORi(start, stop) for (int i = start; i < stop; i++)
#define FORj(start, stop) for (int j = start; j < stop; j++)
#define MENUTYPE_ARROWS 1
#define MENUTYPE_KEYS   2
#define STR_ENG         0x01
#define STR_RUS         0x02
#define STR_DIGITS      0x04
#define STR_PATH        0x08
#define STR_SUBJ        0x10
#define KEY_LOWER_W     'w'
#define KEY_LOWER_S     's'
#define KEY_ARROW_UP    72
#define KEY_ARROW_DOWN  80
#define PASSWORD_LEN    64

std::string GetValidString(int);
Student*    InputStudent();
int         FileExists(std::string&);
int         CryptExportToFile(ListOfStudents&, std::string&);
int         CryptLoadFromFile(ListOfStudents&, std::string&);