#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span() : _maxSize(0), _number(0)
{}

Span::Span(unsigned int n) : _maxSize(n)
{}

Span::Span(const Span& other) : _maxSize(other._maxSize), _number(other._number)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_number = other._number;
		_maxSize = other._maxSize;
	}
	return (*this);
}

Span::~Span()
{}

const char* Span::SpanFullException::what() const throw()
{
    return "Span is full";
}

void Span::addNumber(int n)
{
	if (_number.size() == _maxSize)
		throw Span::SpanFullException();
	_number.push_back(n);
}

int Span::shortestSpan()
{
    if (_number.size() < 2)
        throw std::runtime_error("Not enough elements to compute span (need at least 2)");
    
    std::vector<int> sorted = _number;
    std::sort(sorted.begin(), sorted.end());
    
    long minDiff = (long)sorted[1] - (long)sorted[0];
    for (size_t i = 1; i < sorted.size(); i++)
    {
        long diff = (long)sorted[i] - (long)sorted[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    return (static_cast<int>(minDiff));
}

int Span::longestSpan()
{
    if (_number.size() < 2)
        throw std::runtime_error("Not enough elements to compute span (need at least 2)");
    
    int min = *std::min_element(_number.begin(), _number.end());
    int max = *std::max_element(_number.begin(), _number.end());
    return (static_cast<int>((long)max - (long)min));
}
