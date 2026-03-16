#include <cmath>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include "ScalarConverter.hpp"

enum eType { CHAR, INT, FLOAT, DOUBLE, PSEUDO };

// -----------------Constructor----------------------

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const&)
{
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

//---------------------Writer-----------------------

static void writeChar(std::string const &literal)
{
	char c = literal[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void writeInt(std::string const &literal)
{
	long nb = strtol(literal.c_str(), NULL, 10);
	
	if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	int i = static_cast<int>(nb);
	char c = static_cast<char>(i);
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void writeFloat(std::string const &literal)
{
	float nb = strtof(literal.c_str(), NULL);

	if (literal.size() < 3)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	else if (std::isnan(nb) || std::isinf(nb))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(nb);
		if (nb < 0 || nb > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nb) << std::endl;
	}
	if (nb == static_cast<int>(nb))
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << nb << std::endl;
	}
	else
	{
		std::cout << "float: " << nb << "f" << std::endl;
		std::cout << "double: " << nb << std::endl;
	}
}

static void writeDouble(std::string const &literal)
{
	double nb = strtod(literal.c_str(), NULL);

	if (std::isnan(nb) || std::isinf(nb))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(nb);
		if (nb < 0 || nb > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nb) << std::endl;
	}
	if (nb == static_cast<int>(nb))
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << nb << std::endl;
	}
	else
	{
		std::cout << "float: " << nb << "f" << std::endl;
		std::cout << "double: " << nb << std::endl;
	}
}

static void writePseudo(std::string const &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
	else
	{
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
	}
}

// ------------------Converter-----------------------

static eType detectType(std::string const &literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
        return (PSEUDO);
	else if (literal.size() == 1 && !isdigit(literal[0]))
        return (CHAR);
	else if (literal.find('.') != std::string::npos && literal[literal.size() - 1] == 'f')
        return (FLOAT);
	else if (literal.find('.') != std::string::npos)
        return (DOUBLE);
	return (INT);
}

void ScalarConverter::convert(std::string const &literal)
{
    eType type = detectType(literal);

    if (type == CHAR)
		writeChar(literal);
    else if (type == INT)
		writeInt(literal);
    else if (type == FLOAT)
		writeFloat(literal);
    else if (type == DOUBLE)
		writeDouble(literal);
    else
		writePseudo(literal);
}