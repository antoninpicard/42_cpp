#include <fstream>
#include "ShrubberyCreationForm.hpp"

// -------------Construction--------------

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, "ShrubberyCreationForm", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

// ---------------Methods----------------

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);
    std::ofstream file((getTarget() + "_shrubbery").c_str());
    file << "    *" << std::endl;
    file << "   ***" << std::endl;
    file << "  *****" << std::endl;
    file << "   ***" << std::endl;
    file << "    *" << std::endl;
	file << "    *" << std::endl;
	file << "    *" << std::endl;
}
