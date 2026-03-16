#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "---- Intern creates valid forms ----" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm* shrub = intern.makeForm("shrubbery creation", "home");
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;

        AForm* robot = intern.makeForm("robotomy request", "Bender");
        boss.signForm(*robot);
        boss.executeForm(*robot);
        boss.executeForm(*robot);
        delete robot;

        AForm* pardon = intern.makeForm("presidential pardon", "Arthur");
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "---- Intern creates unknown form ----" << std::endl;
    try
    {
        Intern intern;
        AForm* unknown = intern.makeForm("unknown form", "target");
        delete unknown;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    return (0);
}