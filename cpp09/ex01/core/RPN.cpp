#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <iostream>
#include <climits>

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
    std::stack<long>   stack;
    std::istringstream ss(expression);
    std::string        token;
    long               a;
    long               b;
    long               result;

	while (ss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			stack.push(static_cast<long>(token[0] - '0'));
		else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: not enough operands for operator '" << token[0] << "'" << std::endl;
				return ;
			}
			b = stack.top(); stack.pop();
			a = stack.top(); stack.pop();
			switch (token[0])
			{
				case '+': result = a + b; break;
				case '-': result = a - b; break;
			    case '*': result = a * b; break;
				case '/':
					if (b == 0)
					{
						std::cerr << "Error: division by zero" << std::endl;
						return ;
					}
					result = a / b;
					break;
				default: return ;
			}
			if (result > INT_MAX || result < INT_MIN)
			{
				std::cerr << "Error: overflow in expression" << std::endl;
				return ;
			}
			stack.push(result);
		}
		else
		{
			std::cerr << "Error: invalid token '" << token << "'" << std::endl;
			return ;
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error: invalid expression, too many operands" << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}