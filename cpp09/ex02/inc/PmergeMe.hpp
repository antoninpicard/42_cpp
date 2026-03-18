#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>
#include <iostream>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
	public:
		PmergeMe();
		PmergeMe(std::vector<int>& vec);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sort();
};

#endif