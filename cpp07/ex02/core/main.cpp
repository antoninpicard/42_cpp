#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "---- Empty array ----" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "---- Int array ----" << std::endl;
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 2;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;

    std::cout << "---- Copy array ----" << std::endl;
    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "original[0]: " << arr[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;

    std::cout << "---- Assignment operator ----" << std::endl;
    Array<int> assigned;
    assigned = arr;
    assigned[1] = 888;
    std::cout << "original[1]: " << arr[1] << std::endl;
    std::cout << "assigned[1]: " << assigned[1] << std::endl;

    std::cout << "---- String array ----" << std::endl;
    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "42";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << std::endl;

    std::cout << "---- Out of bounds ----" << std::endl;
    try
    {
        std::cout << arr[999] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}