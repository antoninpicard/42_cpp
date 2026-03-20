#include <iomanip>
#include <algorithm>
#include <time.h>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vec(), _deq()
{}

PmergeMe::PmergeMe(const std::vector<int>& values) : _vec(values), _deq(values.begin(), values.end())
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

// --------------------Ford-Johnson-For-Vector--------------------

void PmergeMe::mergeInsertDeq(std::deque<int>& seq)
{
	if (seq.size() <= 1)
		return ;

	int		orphan = 0;
	bool	hasOrphan = false;

	if (seq.size() % 2 != 0)
	{
		hasOrphan = true;
		orphan = seq.back();
		seq.pop_back();
	}

	std::deque<std::pair<int,int> > pairs;
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

	std::deque<int> winners;
	int j = 0;
	while (j < (int)pairs.size())
	{
		winners.push_back(pairs[j].first);
		j++;
	}
	mergeInsertDeq(winners);
	std::deque<std::pair<int,int> > sortedPairs;
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
	std::deque<int> main_seq;
	std::deque<int> pend;
	j = 0;
	while (j < (int)sortedPairs.size())
	{
		main_seq.push_back(sortedPairs[j].first);
		pend.push_back(sortedPairs[j].second);
		j++;
	}
	main_seq.insert(main_seq.begin(), pend[0]);

	if (pend.size() > 1)
	{
		std::deque<int> idx = buildJacobsthalDeque(pend.size() - 1);
		int jj = 0;
		while (jj < (int)idx.size())
		{
			std::deque<int>::iterator bound = std::find(main_seq.begin(), main_seq.end(), sortedPairs[idx[jj]].first);
			std::deque<int>::iterator pos = std::upper_bound(main_seq.begin(), bound, pend[idx[jj]]);
			main_seq.insert(pos, pend[idx[jj]]);
			jj++;
		}
	}
	if (hasOrphan)
	{
		std::deque<int>::iterator pos = std::upper_bound(main_seq.begin(), main_seq.end(), orphan);
		main_seq.insert(pos, orphan);
	}

	seq = main_seq;
}

// --------------------Ford-Johnson-For-Vector--------------------

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


// ------------------------Jacobsthal-For-Vector-----------------------------

std::vector<int> PmergeMe::buildJacobsthal(int size)
{
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

// --------------------Jacobsthal-For-Deque-------------------

std::deque<int> PmergeMe::buildJacobsthalDeque(int size)
{
	std::deque<int>	jacob;
	int				next;

	jacob.push_back(1);
	jacob.push_back(3);
	next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
	while (next <= size)
	{
		jacob.push_back(next);
		next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
	}

	std::deque<int> result;
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

    struct timespec start, end;

    // --- Vector ---
    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeInsertVec(_vec);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;

    // --- Deque ---
    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeInsertDeq(_deq);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;

    std::cout << "After:  ";
    printSequence();

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " µs" << std::endl;

    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " µs" << std::endl;
}
