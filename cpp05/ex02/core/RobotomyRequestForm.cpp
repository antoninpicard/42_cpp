#include <cstdlib>
#include "RobotomyRequestForm.hpp"

// -------------Construction--------------

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, "RobotomyRequestForm", 145, 137)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

// ---------------Methods----------------

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);
	std::cout << "Drrrrrrrrrrrrrrrrrr..." << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized with success" << std::endl;
	else
		std::cout << getTarget() << " robotomy failed" << std::endl;
}