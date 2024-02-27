#include <iostream>
#include "Tools.h"

int main()
{
    char num1, num2, operation;

    std::cin.get(num1);
    std::cin.get(operation);
    std::cin.get(num2);

    std::cout << std::endl;

    std::string expression(1, num1);
    expression += operation;
    expression += num2;

    std::cout << expression << std::endl;

    double result = Tools::Eval(expression);
    Tools::ClearConsole();
    std::cout << result << std::endl;
    std::cout << result << std::endl;

    std::string resultStr = std::to_string(result);
    Tools::RemoveZeros(resultStr);

    Tools::SetCursorPosition(0, resultStr.length() + 1);

    std::cin.ignore();
    std::cin.get();

    return 0;
}
