#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    std::cout << "---- Basic test from subject ----" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---- Span full exception ----" << std::endl;
    try
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---- Not enough elements ----" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(1);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---- 10000 numbers ----" << std::endl;
    try
    {
        Span sp(10000);
        for (int i = 0; i < 10000; i++)
            sp.addNumber(i);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	std::cout << "---- addRange test ----" << std::endl;
	try
	{
		Span sp(10);
		std::vector<int> v;
		v.push_back(5);
		v.push_back(3);
		v.push_back(8);
		v.push_back(1);
		v.push_back(9);
		sp.addRange(v.begin(), v.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
    return (0);
}
