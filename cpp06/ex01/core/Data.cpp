#include "Data.hpp"

Data::Data() : name(""), value(0)
{}

Data::Data(const Data& other) : name(other.name), value(other.value)
{}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        name = other.name;
        value = other.value;
    }
    return (*this);
}

Data::~Data()
{}