#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// -------------Construction--------------

Intern::Intern()
{}

Intern::Intern(const Intern&)
{}

Intern& Intern::operator=(Intern const&)
{
    return (*this);
}

Intern::~Intern()
{}

// ---------------Methods----------------

static AForm* createShrub(std::string target) { return new ShrubberyCreationForm(target); }
static AForm* createRobot(std::string target) { return new RobotomyRequestForm(target); }
static AForm* createPardon(std::string target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*creators[3])(std::string) = {&createShrub, &createRobot, &createPardon};

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Error: form '" << formName << "' does not exist" << std::endl;
    return NULL;
}