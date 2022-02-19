#include "../include/Menu.hpp"

#include <cstddef>


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

