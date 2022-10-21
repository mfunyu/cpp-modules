#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <string>

class Form;
#include "Bureaucrat.hpp"

class Form
{
  private:
	std::string const _name;
	bool			  _isSigned;
	int const		  _gradeToSign;
	int const		  _gradeToExec;
	int				  validateGrade(int grade);
	Form();

  public:
	~Form();
	Form(Form const& other);
	Form& operator=(Form const& other);

	Form(std::string name, int gradeToSign, int gradeToExec);

	std::string const& getName() const;
	bool			   getIsSigned() const;
	int				   getGradeToSign() const;
	int				   getGradeToExec() const;

	void beSigned(Bureaucrat const& bureaucrat);

	static bool isGradeTooHigh(int grade);
	static bool isGradeTooLow(int grade);

	class GradeTooHighException : public std::domain_error {
	  public:
		GradeTooHighException();
	};
	class GradeTooLowException : public std::domain_error {
	  public:
		GradeTooLowException();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif /* FORM_HPP */
