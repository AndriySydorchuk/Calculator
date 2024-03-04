#include <iostream>
#include "Tools.h"
#include <exprtk/exprtk.hpp>

int main()
{
    typedef double T; // numeric type (float, double, mpfr etc...)

    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T> expression_t;
    typedef exprtk::parser<T> parser_t;

    std::string resultStr, expressionToStore, expressionToCalc;
    T result;

    while (true)
    {
        if (!resultStr.empty())
        {
            std::getline(std::cin, expressionToStore);
            expressionToCalc = resultStr + expressionToStore;
        }
        else
        {
            std::getline(std::cin, expressionToCalc);
        }
        std::cout << std::endl;

        const std::string expression_string = "r := " + expressionToCalc;

        T r = T(0.0);

        symbol_table_t symbol_table;
        symbol_table.add_variable("r", r);

        expression_t expression;
        expression.register_symbol_table(symbol_table);

        parser_t parser;

        if (!parser.compile(expression_string, expression))
        {
            printf("Compilation error...\n");
            return -1;
        }

        result = expression.value();

        Tools::ClearConsole();
        std::cout << result << std::endl;
        std::cout << result << std::endl;

        resultStr = std::to_string(result);
        Tools::RemoveZeros(resultStr);
        Tools::SetCursorPosition(0, resultStr.length() + 1);

    }

    return 0;
}
