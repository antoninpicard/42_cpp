#include <list>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main()
{
    std::cout << "---- vector test ----" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found: " << e.what() << std::endl;
    }

    std::cout << "---- list test ----" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }

    return (0);
}
