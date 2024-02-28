#include <iostream>
#include "Tools.h"

int main()
{
    std::string expressionToStore, expressionToCalc, resultStr;

    while(true)
    {
        if (!resultStr.empty())
        {
            expressionToCalc = resultStr;
            std::getline(std::cin, expressionToStore);
            expressionToCalc += expressionToStore;
        }
        else
        {
            std::getline(std::cin, expressionToCalc);
        }

        std::cout << std::endl;

        double result = Tools::Eval(expressionToCalc);

        Tools::ClearConsole();
        std::cout << result << std::endl;
        std::cout << result << std::endl;

        resultStr = std::to_string(result);
        Tools::RemoveZeros(resultStr);
        Tools::SetCursorPosition(0, resultStr.length() + 1);
    }

    return 0;
}
