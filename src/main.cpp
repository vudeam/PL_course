#include "../include/Menu.hpp"
#include "../include/stuff.hpp"

#include <array>
#include <iostream>
#include <string>


static std::array<std::string, 9> mainMenuItems
{
    "0. Выход",
    "1. Загрузка данных из файла",
    "2. Распечатка данных о студентах",
    "3. Добавление нового студента",
    "4. Редактирование данных о студенте",
    "5. Удаление студента",
    "6. Синхронизировать с файлом",
    "7. [Вариант 87]",
    "8. Загрузка данных из зашифрованного файла",
};

int
main ()
{
    /*
    std::string inp = GetValidString(STR_RUS);
    std::cout << "Hello world" << "\n" << inp << "\n";
    */

    Menu menuKeys{mainMenuItems.data(), mainMenuItems.size(), MENUTYPE_KEYS};
    std::cout << menuKeys.SelectItem();

    Menu menuArrows{mainMenuItems.data(), mainMenuItems.size(), MENUTYPE_ARROWS};
    std::cout << menuArrows.SelectItem(123);

    return 0;
}

