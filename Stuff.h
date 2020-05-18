#pragma once
#include <iostream>
#include <string>
#define CLEAN std::cin.clear(); std::cin.ignore(std::cin.rdbuf()->in_avail()); _flushall();
#define FORi(start, stop) for (int i = start; i < stop; i++)
#define MENUTYPE_ARROWS 1
#define MENUTYPE_KEYS 2
#define STR_ENG 0x01
#define STR_RUS 0x02
#define STR_DIGITS 0x04
#define STR_PATH 0x08

std::string GetValidString(int _strtype = STR_ENG | STR_RUS | STR_DIGITS | STR_PATH) {
	std::string _input = "";
	//int ready = 0;
	if (_strtype == STR_DIGITS) {
		do {
			CLEAN
			std::getline(std::cin, _input);
			CLEAN
			if (_input.empty()) continue;
			if (_input.find_first_not_of("+-0123456789") == std::string::npos) break;
		} while (87);
		//return _input;
	}
	if (_strtype == STR_ENG) {
		do {
			CLEAN
			std::getline(std::cin, _input);
			CLEAN
			if (_input.empty()) continue;
			if (_input.find_first_not_of("-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) break;
		} while (87);
	}
	if (_strtype == STR_RUS) {
		do {
			CLEAN
			std::getline(std::cin, _input);
			CLEAN
			if (_input.empty()) continue;
			if (_input.find_first_not_of("-àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß") == std::string::npos) break;
		} while (87);
	}
	if (_strtype ==( STR_ENG | STR_RUS)) {
		do {
			CLEAN
			std::getline(std::cin, _input);
			CLEAN
			if (_input.empty()) continue;
			if (_input.find_first_not_of("-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZàáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß") == std::string::npos) break;
		} while (87);
	}
	if (_strtype == (STR_ENG | STR_RUS | STR_DIGITS)) {
		do {
			CLEAN
			std::getline(std::cin, _input);
			CLEAN
			if (_input.empty()) continue;
			if (_input.find_first_not_of("-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZàáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß") == std::string::npos) break;
		} while (87);
	}
	if (_strtype == STR_PATH) {
		do {
			CLEAN
			std::getline(std::cin, _input);
			CLEAN
			if (_input.empty()) continue;
			if (_input.find_first_not_of(".-_0123456789()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) break;
		} while (87);
	}
	return _input;
}