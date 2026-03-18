#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vec(0)
{}

PmergeMe::PmergeMe(std::vector<int>& vec) : _vec(vec)
{}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
		_vec = other._vec;
	return (*this);
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::sort()
{
	
}