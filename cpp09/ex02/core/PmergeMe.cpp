#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vec(), _deq()
{}

PmergeMe::PmergeMe(const std::vector<int>& vec) : _vec(vec), _deq(vec.begin(), vec.end())
{}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}


// --------------------Methods--------------------


std::vector<int> PmergeMe::buildJacobsthal(int size)
{
	std::vector<int> 	jacob;
	int					next;
	jacob.push_back(1);
	jacob.push_back(1);
	next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
	jacob.push_back(next);
	return (jacob);
}

void PmergeMe::printSequence()
{
	std::vector<int>::iterator it = _vec.begin();
	while (it != _vec.end())
	{
		std::cout << *it;
		if (it + 1 != _vec.end())
			std::cout << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::sort()
{
	std::cout << "Before: ";
	PmergeMe::printSequence();
}