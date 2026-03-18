#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
	private:
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();
	public:
		static void calculate(const std::string &expression); 
};

#endif