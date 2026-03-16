#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		const int			_gradeToSigned;
		const int			_gradeToExecute;
		bool 				_isSigned;
	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		int					getGradeToSigned() const;
		int					getGradeToExecute() const;
		bool				getIsSigned() const;

		void beSigned(Bureaucrat const &bureaucrat);

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
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif