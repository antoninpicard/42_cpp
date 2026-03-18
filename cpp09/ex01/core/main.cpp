#include <iostream>
#include "RPN.hpp"

int main()
{
    std::cout << "---- Tests from subject ----" << std::endl;
    RPN::calculate("8 9 * 9 - 9 - 9 - 4 - 1 +");
    RPN::calculate("7 7 * 7 -");
    RPN::calculate("1 2 * 2 / 2 * 2 4 - +");

    std::cout << "---- Error tests ----" << std::endl;
    RPN::calculate("(1 + 1)");
    RPN::calculate("1 1");
    RPN::calculate("/ 1 2");
    RPN::calculate("1 0 /");

    return (0);
}