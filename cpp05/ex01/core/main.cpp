#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout <<  "---- Form with grade not valid ----" << std::endl;
    try
    {
        Form bad("BadForm", 0, 50);
    }
    catch (std::exception& e)
    {
        std::cout << "Form grade too high: " << e.what() << std::endl;
    }

    try
    {
        Form bad("BadForm", 151, 50);
    }
    catch (std::exception& e)
    {
        std::cout << "Form grade too low: " << e.what() << std::endl;
    }

    std::cout <<  "---- Bureaucrat with grade too low ----" << std::endl;
    try
    {
        Bureaucrat low("Low", 100);
        Form form("Form28", 50, 25);
        std::cout << form << std::endl;
        low.signForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "---- Bureaucrat with a good grade ----" << std::endl;
    try
    {
        Bureaucrat high("High", 10);
        Form form("Form42", 50, 25);
        std::cout << form << std::endl;
        high.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    
    return (0);
}