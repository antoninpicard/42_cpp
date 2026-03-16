#include "Form.hpp"
#include "Bureaucrat.hpp"

// --------------Construction----------------

Form::Form() : _name("Default"), _gradeToSigned(150), _gradeToExecute(150)
{}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSigned(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSigned < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSigned > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _gradeToSigned(other._gradeToSigned), _gradeToExecute(other._gradeToExecute)
{
	if (_gradeToSigned < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSigned > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{}

// -----------------Getter-------------------

const std::string& Form::getName() const
{
	return (_name);
}

int Form::getGradeToSigned() const
{
	return (_gradeToSigned);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

// -----------------Methods-------------------

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSigned)
		throw Bureaucrat::GradeTooLowException();
	_isSigned = true;
}

// -----------------Display-------------------

std::ostream& operator<<(std::ostream& os, Form const& form)
{
    os << "Form: " << form.getName() << " | Signed: " << form.getIsSigned() << " | Grade to sign: " << form.getGradeToSigned() << " | Grade to execute: " << form.getGradeToExecute();
    return (os);
}

// -------------Grade Exception--------------

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}