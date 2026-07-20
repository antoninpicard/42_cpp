#include <cerrno>
#include <climits>
#include <cstdlib>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: no arguments provided. Usage: ./PmergeMe <positive integers>" << std::endl;
		return (1);
	}
	std::vector<int> 	values;
	int 				i = 1;
	long				valuesOfReturn;

	while (i < argc)
	{
		errno = 0;
		char* endptr;

		valuesOfReturn = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || errno == ERANGE || valuesOfReturn <= 0 || valuesOfReturn > INT_MAX)
		{
			std::cerr << "Error: invalid argument '" << argv[i] << "': must be a positive integer" << std::endl;
			return (1);
		}
		values.push_back(static_cast<int>(valuesOfReturn));
		i++;
	}
	PmergeMe pm(values);
	pm.sort();
	return (0);
}