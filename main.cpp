#include <iostream>
#include "Tools.h"

int main()
{
    char num1, num2, operation;
    std::string expression, resultStr;

    while(true)
    {
        if(num1)
        {
            std::cin.ignore();
            std::cin.clear();
        }
        else
        {
            std::cin.get(num1);
        }


        if(!resultStr.empty())
        {
            expression = resultStr;
        }
        else
        {
            expression = num1;
        }

        std::cin.get(operation);
        std::cin.get(num2);

        std::cout << std::endl;

        expression += operation;
        expression += num2;

        double result = Tools::Eval(expression);

        Tools::ClearConsole();
        std::cout << result << std::endl;
        std::cout << result << std::endl;

        resultStr = std::to_string(result);
        Tools::RemoveZeros(resultStr);
        Tools::SetCursorPosition(0, resultStr.length() + 1);
    }

    return 0;
}
