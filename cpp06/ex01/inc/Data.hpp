#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
    public:
        std::string name;
        int         value;

        Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
};

#endif