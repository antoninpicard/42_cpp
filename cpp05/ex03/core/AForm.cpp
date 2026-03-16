#include "AForm.hpp"
#include "Bureaucrat.hpp"
// --------------Construction----------------
AForm::AForm() : _target("Default"),_name("Default"), _gradeToSigned(150), _gradeToExecute(150)
{}

AForm::AForm(std::string const &target, std::string const &name, int gradeToSign, int gradeToExecute) : _target(target), _name(name), _gradeToSigned(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSigned < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSigned > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :_target(other._target), _name(other._name), _gradeToSigned(other._gradeToSigned), _gradeToExecute(other._gradeToExecute)
{
	if (_gradeToSigned < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSigned > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{}

// -----------------Getter-------------------

const std::string& AForm::getTarget() const
{
	return (_target);
}

const std::string& AForm::getName() const
{
	return (_name);
}

int AForm::getGradeToSigned() const
{
	return (_gradeToSigned);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

// -----------------Methods-------------------

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSigned)
		throw Bureaucrat::GradeTooLowException();
	_isSigned = true;
}

void AForm::checkExecution(Bureaucrat const &executor) const
{
	if (_isSigned == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

// -----------------Display-------------------

std::ostream& operator<<(std::ostream& os, AForm const& form)
{
    os << "Form: " << form.getName() << " | Signed: " << form.getIsSigned() << " | Grade to sign: " << form.getGradeToSigned() << " | Grade to execute: " << form.getGradeToExecute();
    return (os);
}

// -------------Grade Exception--------------

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is'nt signed";
}