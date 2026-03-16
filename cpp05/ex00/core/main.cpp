#include "Bureaucrat.hpp"

int main()
{
    // ---- Valid construction ----
    try
    {
        Bureaucrat bob("Bob", 75);
        std::cout << bob.getName() << ", grade " << bob.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    // ---- Grade too low (> 150) ----
    try
    {
        Bureaucrat bad("Bad", 151);
        std::cout << "Should not print" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "GradeTooLow caught: " << e.what() << std::endl;
    }

    // ---- Grade too high (< 1) ----
    try
    {
        Bureaucrat bad("Bad", 0);
        std::cout << "Should not print" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "GradeTooHigh caught: " << e.what() << std::endl;
    }

    // ---- Increment at max grade ----
    try
    {
        Bureaucrat alice("Alice", 1);
        alice.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Increment at grade 1: " << e.what() << std::endl;
    }

    // ---- Decrement at min grade ----
    try
    {
        Bureaucrat alice("Alice", 150);
        alice.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Decrement at grade 150: " << e.what() << std::endl;
    }

    // ---- Normal increment / decrement ----
    try
    {
        Bureaucrat charlie("Charlie", 50);
        std::cout << charlie.getName() << ", grade " << charlie.getGrade() << std::endl;
        charlie.incrementGrade();
        std::cout << "After increment: " << charlie.getGrade() << std::endl;
        charlie.decrementGrade();
        charlie.decrementGrade();
        std::cout << "After 2 decrements: " << charlie.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    return (0);
}