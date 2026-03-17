#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	private:
		unsigned int        _maxSize;
		std::vector<int> 	_number;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void 	addNumber(int n);
		int 	shortestSpan();
		int 	longestSpan();

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}
		class SpanFullException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};



#endif