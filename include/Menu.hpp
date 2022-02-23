#ifndef MENU_HPP
#define MENU_HPP

#include <string>


class Menu
{
public:

    Menu ();
    Menu (std::string * menuItems, int nItems, int menuType);

    ~Menu ();

    int
    SelectItem (int num = -1) const;


private:

    int nItems;
    int type;
    std::string * arrItems;
};


#endif        /* MENU_HPP */

