#ifndef STUFF_HPP
#define STUFF_HPP


#include <iostream>
#include <string>


/* completely clear input (in the bad & hard way) */
#define CLEAN                                      \
    std::cin.clear();                              \
    std::cin.ignore(std::cin.rdbuf()->in_avail());

#define STR_ENG       0x01
#define STR_RUS       0x02
#define STR_DIGITS    0x04
#define STR_PATH      0x08
#define STR_SUBJ      0x0A

#define MENUTYPE_ARROWS    0x01
#define MENUTYPE_KEYS      0x02

#define KEY_LOWER_W       'w'
#define KEY_LOWER_S       's'
#define KEY_ARROW_UP      72
#define KEY_ARROW_DOWN    80
#define ASCII_LF          0x0A
#define ASCII_CR          0x0D


std::string
GetValidString (int option = STR_ENG | STR_RUS | STR_DIGITS | STR_PATH | STR_SUBJ);


#endif        /* STUFF_HPP */

