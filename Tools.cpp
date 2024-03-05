#include "Tools.h"
#include <iostream>

void Tools::ClearConsole()
{
    system("clear");
}

void Tools::SetCursorPosition(size_t x, size_t y)
{
    std::string escapeSequence = "\033[" + std::to_string(x) + ";" + std::to_string(y) + "f";
    std::cout << escapeSequence;
}

void Tools::RemoveZeros(std::string &str)
{
    str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
    str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
}