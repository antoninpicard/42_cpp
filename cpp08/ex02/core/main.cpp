#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "---- Subject test ----" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "---- Copy test ----" << std::endl;
    MutantStack<int> copy(mstack);
    copy.push(999);
    std::cout << "original size: " << mstack.size() << std::endl;
    std::cout << "copy size: " << copy.size() << std::endl;

    std::cout << "---- String stack ----" << std::endl;
    MutantStack<std::string> sstack;
    sstack.push("hello");
    sstack.push("world");
    sstack.push("42");
    MutantStack<std::string>::iterator sit = sstack.begin();
    while (sit != sstack.end())
    {
        std::cout << *sit << std::endl;
        ++sit;
    }

    std::cout << "---- Same test with std::list ----" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    while (lit != lst.end())
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return (0);
}