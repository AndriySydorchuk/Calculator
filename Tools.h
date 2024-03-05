#pragma once
#include <string>

class Tools
{
public:
    static void ClearConsole();
    static void SetCursorPosition(size_t x, size_t y);
    static void RemoveZeros(std::string& str);
};
