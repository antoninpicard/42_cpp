#include "PresidentialPardonForm.hpp"

// -------------Construction--------------

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, "PresidentialPardonForm", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

// ---------------Methods-----------------

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}