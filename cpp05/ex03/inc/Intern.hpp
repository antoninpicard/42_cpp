#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(Intern const&);
		~Intern();

		AForm* makeForm(std::string formName, std::string target);
};

#endif