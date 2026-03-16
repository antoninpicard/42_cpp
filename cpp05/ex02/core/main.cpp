#include <ctime>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "---- Bureaucrat with grade too low to sign ----" << std::endl;
    try
    {
        Bureaucrat low("Low", 150);
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;
        low.signForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "---- Execute without signing ----" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("home");
        boss.executeForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "---- ShrubberyCreationForm ----" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("home");
        boss.signForm(shrub);
        boss.executeForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "---- RobotomyRequestForm ----" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Bender");
        boss.signForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "---- PresidentialPardonForm ----" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm pardon("Arthur");
        boss.signForm(pardon);
        boss.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "---- PresidentialPardonForm grade too low to execute ----" << std::endl;
    try
    {
        Bureaucrat low("Low", 10);
        PresidentialPardonForm pardon("Arthur");
        low.signForm(pardon);
        low.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    return (0);
}