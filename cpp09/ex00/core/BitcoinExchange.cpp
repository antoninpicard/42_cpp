#include <fstream>
#include <cstdlib>
#include <iostream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

bool BitcoinExchange::validateDate(const std::string& date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    long year = strtol(date.substr(0, 4).c_str(), NULL, 10);
    long month = strtol(date.substr(5, 2).c_str(), NULL, 10);
    long day = strtol(date.substr(8, 2).c_str(), NULL, 10);

    if (year < 2009)
        return (false);
    if (month < 1 || month > 12)
        return (false);

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return (false);

    return (true);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::string line;
    std::string date;
    size_t      pos;
    float       price;

    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    std::getline(file, line);
    if (line.find("date,exchange_rate") == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        pos = line.find(',');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = line.substr(0, pos);
        price = strtof(line.substr(pos + 1).c_str(), NULL);
        _database[date] = price;
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename) const
{
    std::string line;
    std::string date;
    size_t      pos;
    float       price;

    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    std::getline(file, line);
    if (line.find("date | value") == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        pos = line.find(" | ");
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = line.substr(0, pos);
        std::string priceStr = line.substr(pos + 3);
        char*       endptr;
        price = strtof(priceStr.c_str(), &endptr);
        if (*endptr != '\0')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!validateDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (price < 0)
            std::cerr << "Error: not a positive number." << std::endl;
        else if (price > 1000)
            std::cerr << "Error: too large a number." << std::endl;
        else
        {
            std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
            if (it == _database.end() || it->first != date)
            {
                if (it == _database.begin())
                {
                    std::cerr << "Error: date out of range => " << date << std::endl;
                    continue;
                }
                --it;
            }
            std::cout << date << " => " << price << " = " << price * it->second << std::endl;
        }
    }
}
