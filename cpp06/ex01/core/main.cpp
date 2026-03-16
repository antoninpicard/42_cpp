#include "Data.hpp"
#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.name = "test";
    data.value = 42;

    std::cout << "---- Serialization test ----" << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;

    std::cout << "---- Pointer comparison ----" << std::endl;
    if (ptr == &data)
        std::cout << "Success: pointers are equal" << std::endl;
    else
        std::cout << "Failure: pointers are different" << std::endl;

    std::cout << "---- Data check ----" << std::endl;
    std::cout << "name: " << ptr->name << std::endl;
    std::cout << "value: " << ptr->value << std::endl;

    return (0);
}
