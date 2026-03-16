#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_target;
		const std::string 	_name;
		const int			_gradeToSigned;
		const int			_gradeToExecute;
		bool 				_isSigned;
	public:
		AForm();
		AForm(std::string const &_target, std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getTarget() const;
		const std::string&	getName() const;
		int					getGradeToSigned() const;
		int					getGradeToExecute() const;
		bool				getIsSigned() const;

		void beSigned(Bureaucrat const &bureaucrat);
		void checkExecution(Bureaucrat const &executor) const;
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif