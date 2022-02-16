#include "../include/stuff.hpp"

#include <iostream>
#include <string>


int
main ()
{
    std::string inp = GetValidString(STR_RUS);
    std::cout << "Hello world" << "\n" << inp << "\n";

    return 0;
}

