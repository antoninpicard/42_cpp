#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <iostream>

RPN::RPN()
{}

RPN::RPN(const RPN&)
{}

RPN& RPN::operator=(const RPN&)
{	
	return (*this);
}

RPN::~RPN()
{}

void RPN::calculate(const std::string &expression)
{
    std::stack<int>    stack;
    std::istringstream ss(expression);
    std::string        token;
    int                a;
    int                b;

	while (ss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			stack.push(static_cast<int>(token[0] - '0'));
		else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			b = stack.top(); stack.pop();
			a = stack.top(); stack.pop();
			switch (token[0])
			{
				case '+': stack.push(a + b);
					break;
				case '-': stack.push(a - b);
					break;
			    case '*': stack.push(a * b);
					break;
				case '/':
				if (b == 0)
				{
					std::cerr << "Error" << std::endl;
					return ;
				}
				stack.push(a / b);
					break;
			}
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}