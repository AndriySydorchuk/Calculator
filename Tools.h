#pragma once
#include <string>

class Tools
{
public:
    static double Eval(std::string expr);
    static void ClearConsole();
    static void SetCursorPosition(size_t x, size_t y);
};
