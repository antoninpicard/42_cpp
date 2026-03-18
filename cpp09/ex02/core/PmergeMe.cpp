#include <iomanip>
#include <algorithm>
#include <sys/time.h>
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


// --------------------Ford-Johnson--------------------

void PmergeMe::mergeInsertVec(std::vector<int>& seq)
{
	// base case: 0 or 1 element is already sorted
	if (seq.size() <= 1)
		return ;

	int		orphan = 0;
	bool	hasOrphan = false;

	// odd size: save last element aside
	if (seq.size() % 2 != 0)
	{
		hasOrphan = true;
		orphan = seq.back();
		seq.pop_back();
	}

	// build pairs: largest element first, smallest second
	std::vector<std::pair<int,int> > pairs;
	int i = 0;
	while (i < (int)seq.size())
	{
		int a = seq[i];
		int b = seq[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		i += 2;
	}

	// extract winners and recurse
	std::vector<int> winners;
	int j = 0;
	while (j < (int)pairs.size())
	{
		winners.push_back(pairs[j].first);
		j++;
	}
	mergeInsertVec(winners);

	// rebuild pairs in the new sorted order of winners
	// each winner keeps its original loser
	std::vector<std::pair<int,int> > sortedPairs;
	j = 0;
	while (j < (int)winners.size())
	{
		int k = 0;
		while (k < (int)pairs.size())
		{
			if (pairs[k].first == winners[j])
			{
				sortedPairs.push_back(pairs[k]);
				pairs[k].first = -1;
				break ;
			}
			k++;
		}
		j++;
	}

	// build main from sorted winners, pend from their losers
	std::vector<int> main_seq;
	std::vector<int> pend;
	j = 0;
	while (j < (int)sortedPairs.size())
	{
		main_seq.push_back(sortedPairs[j].first);
		pend.push_back(sortedPairs[j].second);
		j++;
	}

	// pend[0] is smaller than all winners: insert at front
	main_seq.insert(main_seq.begin(), pend[0]);

	// insert remaining pend elements using Jacobsthal order
	if (pend.size() > 1)
	{
		std::vector<int> idx = buildJacobsthal(pend.size() - 1);
		int jj = 0;
		while (jj < (int)idx.size())
		{
			// search is bounded by the position of the associated winner
			std::vector<int>::iterator bound = std::find(main_seq.begin(), main_seq.end(), sortedPairs[idx[jj]].first);
			std::vector<int>::iterator pos = std::upper_bound(main_seq.begin(), bound, pend[idx[jj]]);
			main_seq.insert(pos, pend[idx[jj]]);
			jj++;
		}
	}

	// insert orphan with no bound restriction
	if (hasOrphan)
	{
		std::vector<int>::iterator pos = std::upper_bound(main_seq.begin(), main_seq.end(), orphan);
		main_seq.insert(pos, orphan);
	}

	seq = main_seq;
}


// ----------------------Jacobsthal-----------------------------

std::vector<int> PmergeMe::buildJacobsthal(int size)
{
	// generate Jacobsthal sequence up to size
	std::vector<int>	jacob;
	int					next;

	jacob.push_back(1);
	jacob.push_back(3);
	next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
	while (next <= size)
	{
		jacob.push_back(next);
		next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
	}

	// build insertion order: groups in Jacobsthal order, descending within each group
	std::vector<int> result;
	result.push_back(1);
	int i = 1;
	while (i < (int)jacob.size())
	{
		int j = std::min(jacob[i], size);
		while (j >= jacob[i - 1] + 1)
		{
			result.push_back(j);
			j--;
		}
		i++;
	}

	// cover any remaining indices not reached by jacobsthal groups
	int remaining = size;
	while (remaining > jacob.back())
	{
		result.push_back(remaining);
		remaining--;
	}
	return (result);
}

// --------------------------Methods--------------------------

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
	printSequence();

	struct timeval start, end;

	gettimeofday(&start, NULL);
	mergeInsertVec(_vec);
	gettimeofday(&end, NULL);

	double time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	std::cout << "After: ";
	printSequence();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}
