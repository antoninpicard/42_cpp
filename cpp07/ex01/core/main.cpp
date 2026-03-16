#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const &element)
{
    std::cout << element << std::endl;
}

template <typename T>
void doubleValue(T &element)
{
    element *= 2;
}

int main()
{
    std::cout << "---- int array ----" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print<int>);

    std::cout << "---- double values ----" << std::endl;
    iter(arr, 5, doubleValue<int>);
    iter(arr, 5, print<int>);

    std::cout << "---- string array ----" << std::endl;
    std::string strs[] = {"hello", "world", "42"};
    iter(strs, 3, print<std::string>);

    return (0);
}