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
		void 				printSequence();
		std::vector<int> 	buildJacobsthal(int size);
		void 				mergeInsertVec(std::vector<int>& seq);
	public:
		PmergeMe();
		PmergeMe(const std::vector<int>& vec);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sort();
};


#endif