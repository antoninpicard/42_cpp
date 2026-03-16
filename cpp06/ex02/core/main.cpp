#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
    int r = rand() % 3;
    if (r == 0)
        return (new A);
    if (r == 1)
        return (new B);
    return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; }
    catch (std::exception&) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; }
    catch (std::exception&) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; }
    catch (std::exception&) {}
}

int main()
{
    srand(time(NULL));

    std::cout << "---- identify with pointer ----" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        identify(obj);
        delete obj;
    }

    std::cout << "---- identify with reference ----" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        identify(*obj);
        delete obj;
    }

    return (0);
}