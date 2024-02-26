#include "Tools.h"

double Tools::Eval(std::string expr)
{
    std::string xxx; // Get Rid of Spaces
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] != ' ')
        {
            xxx += expr[i];
        }
    }

    std::string tok = ""; // Do parantheses first
    for (int i = 0; i < xxx.length(); i++)
    {
        if (xxx[i] == '(')
        {
            int iter = 1;
            std::string token;
            i++;
            while (true)
            {
                if (xxx[i] == '(')
                {
                    iter++;
                } else if (xxx[i] == ')')
                {
                    iter--;
                    if (iter == 0)
                    {
                        i++;
                        break;
                    }
                }
                token += xxx[i];
                i++;
            }
            tok += std::to_string(Eval(token));
        }
        tok += xxx[i];
    }

    for (int i = 0; i < tok.length(); i++)
    {
        if (tok[i] == '+')
        {
            return Eval(tok.substr(0, i)) + Eval(tok.substr(i+1, tok.length()-i-1));
        } else if (tok[i] == '-')
        {
            return Eval(tok.substr(0, i)) - Eval(tok.substr(i+1, tok.length()-i-1));
        }
    }

    for (int i = 0; i < tok.length(); i++)
    {
        if (tok[i] == '*')
        {
            return Eval(tok.substr(0, i)) * Eval(tok.substr(i+1, tok.length()-i-1));
        } else if (tok[i] == '/')
        {
            return Eval(tok.substr(0, i)) / Eval(tok.substr(i+1, tok.length()-i-1));
        }
    }

    return std::stod(tok.c_str()); // Return the value...
}

void Tools::ClearConsole()
{
    system("clear");
}

