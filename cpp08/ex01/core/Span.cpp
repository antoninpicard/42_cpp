#include "Span.hpp"
#include <algorithm>

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
        throw std::exception();
    
    std::vector<int> sorted = _number;
    std::sort(sorted.begin(), sorted.end());
    
    int minDiff = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    return (minDiff);
}

int Span::longestSpan()
{
    if (_number.size() < 2)
        throw std::exception();
    
    int min = *std::min_element(_number.begin(), _number.end());
    int max = *std::max_element(_number.begin(), _number.end());
    return (max - min);
}
