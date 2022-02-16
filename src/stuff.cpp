#include "../include/stuff.hpp"


std::string
GetValidString (int option)
{
    using namespace std;

    string input;

    do
    {
        CLEAN
        getline(cin, input);
        CLEAN
        if (input.empty()) continue;

        switch (option)
        {
            case STR_DIGITS:
                if (input.find_first_not_of("+-0123456789") == string::npos) goto finish;
                break;

            case STR_ENG:
                if (input.find_first_not_of("-.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) goto finish;
                break;

            case STR_RUS:
                if (input.find_first_not_of("-.абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == string::npos) goto finish;
                break;

            case STR_ENG | STR_RUS:
                if (input.find_first_not_of("-.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == string::npos) goto finish;
                break;

            case STR_ENG | STR_RUS | STR_DIGITS:
                if (input.find_first_not_of("-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == string::npos) goto finish;
                break;

            case STR_PATH:
                if (input.find_first_not_of(".-_0123456789()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) goto finish;
                break;

            case STR_SUBJ:
                if (input.find_first_not_of("- .абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == string::npos) goto finish;
                break;

            default:
                goto finish;
        }
    } while (87);

finish:
    return input;
}

