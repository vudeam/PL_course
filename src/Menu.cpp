#include "../include/Menu.hpp"
#include "../include/stuff.hpp"

#include <cstddef>
#include <cstdlib>
#include <iostream>


#if ! __has_include("conio.h")
#include <stdio.h>
/**
 * apperently there is no _getch on Linux
 * https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
 */
#include <termios.h>

static termios old;
static termios cur;

/**
 * initialize new terminal I/O settings
 */
void
init_termios (int echo)
{
    tcgetattr(0, &old);
    cur = old;
    cur.c_lflag &= ~ICANON;

    if (echo)
    {
        cur.c_lflag |= ECHO;
    }
    else
    {
        cur.c_lflag &= ~ECHO;
    }

    tcsetattr(0, TCSANOW, &cur);
}

/**
 * restore old terminal I/O settings
 */
void
reset_termios ()
{
    tcsetattr(0, TCSANOW, &old);
}

/**
 * read 1 character
 * echo defines echo mode
 */
char
getch_ (int echo)
{
    char ch;

    init_termios(echo);
    ch = getchar();
    reset_termios();

    return ch;
}

/**
 * read 1 character without echo
 */
char
getch ()
{
    return getch_(0);
}

/**
 * read 1 character with echo
 */
char
getche ()
{
    return getch_(1);
}
#endif

Menu::Menu ()
    : nItems{-1}
    , type{0}
    , arrItems{new std::string[2]}
{
    /**
     * TBH, this ctor does not look good to me
     * but I try not to change the code too much
     */
    arrItems[0] = "[Меню не инициализировано]";
    arrItems[1] = "[Menu is not initialized]";
}

Menu::Menu (std::string * menuItems, int nItems, int menuType)
    : type{menuType}
    , nItems{nItems}
    , arrItems{new std::string[nItems]}
{
    for (std::size_t i = 0; i < nItems; i++) arrItems[i] = menuItems[i];
}

Menu::~Menu ()
{
    delete[] arrItems;
}

int
Menu::SelectItem (int nStudents) const
{
    using std::cout;

    if (type == MENUTYPE_ARROWS && nItems > 0)
    {
        int cursPos = 0;
        bool ready = false;

        while (!ready)
        {
            if (nStudents != -1) cout << "В программу загружено студентов: "
                                      << nStudents
                                      << "\n\n";

            for (std::size_t i = 0; i < nItems; i++)
            {
                /**
                 * print arrow if current printed line
                 * is in cursor's postion
                 */
                cout << (cursPos == i ? " > " : "   ")
                     << arrItems[i]
                     << "\n";
            }

#           if ! __has_include("conio.h")
            switch (getch())
#           else
            switch (_getch())
#           endif
            {
                case KEY_LOWER_W:
                case KEY_ARROW_UP:
                    cursPos -= 1;
                    if (cursPos < 0) cursPos = 0;
                    if (std::system("cls")) std::system("clear");
                    break;

                case KEY_LOWER_S:
                case KEY_ARROW_DOWN:
                    cursPos += 1;
                    if (cursPos > nItems - 1) cursPos = nItems - 1;
                    if (std::system("cls")) std::system("clear");
                    break;

                case ASCII_LF:
                case ASCII_CR:
                    ready = true;
                    break;

                default:
                    if (std::system("cls")) std::system("clear");
            }    /* switch (getch) */
        }    /* while (!ready) */

        return cursPos;
    }
    else if (type == MENUTYPE_KEYS && nItems > 0)
    {
        if (nStudents != -1) cout << "В программу загружено студентов: "
                                  << nStudents
                                  << "\n\n";

        for (std::size_t i = 0; i < nItems; i++) cout << arrItems[i] << "\n";

        return std::stoi(GetValidString(STR_DIGITS).substr(0, 3));
    }
    else
    {
        cout << "Выбран неверный тип меню" << "\n";
    }

    return -1;
}

