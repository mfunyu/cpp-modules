/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:19:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 15:13:59 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/****************** FOR PRINT and FORMATTING ******************/

# define SET_COLOR "\033[36m"
# define RESET_COLOR "\033[m"

void	printTestName(std::string testName)
{
	std::cout << SET_COLOR "\n/*** Test " << testName <<\
				" ***/" RESET_COLOR << std::endl;
}

std::string	createFormString(std::string f_name, std::string target)
{
	return f_name + "(target=" + target +\
								//  ", isSigned=" + signStatus +
					")";
}

std::string	createBureaucratString(std::string name, int grade)
{
	return "Bureaucrat(name=" + name + ", grade=" + std::to_string(grade) + ")";
}

void	printExecTestInfo(std::string f_name, std::string target, std::string b_name, int grade)
{
	std::cout << SET_COLOR "// " << createFormString(f_name, target) <<\
				 ".execute(" << createBureaucratString(b_name, grade) << ") " <<\
				 RESET_COLOR;
}

void	printFormTestInfo(std::string f_name, std::string target, std::string append = "")
{
	std::cout << SET_COLOR "// " << createFormString(f_name, target) <<\
				 append << " " << RESET_COLOR;
}

void	printBureaucratTestInfo(std::string name, int grade, std::string append = "")
{
	std::cout << SET_COLOR "// " << createBureaucratString(name, grade) <<\
				 append << RESET_COLOR << std::endl;
}

/******************************** TESTS ********************************/

void	signForm(bool sign, Form *f, Bureaucrat &b)
{
	if (!sign)
	{
		std::cout << std::endl;
		return ;
	}
	try
	{
		f->beSigned(b);
		std::cout << SET_COLOR << "signed" << RESET_COLOR << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << SET_COLOR << "sign failed" << RESET_COLOR << std::endl;
		std::cout << e.what() << std::endl;
	}
}

void	testShrubberyCreationForm(int bureaucreatGrade, bool sign)
{
	std::string		target = "home";
	std::string		b_name = "Cathy";

	printExecTestInfo("ShrubberyCreationForm", target, b_name, bureaucreatGrade);

	try
	{
		ShrubberyCreationForm	s(target);
		Bureaucrat				b(b_name, bureaucreatGrade);

		signForm(sign, &s, b);

		s.execute(b);
		std::cout << "Successfully executed. Check file " + target + "_shrubbery" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testRobotomyRequestForm(int bureaucreatGrade, bool sign)
{
	std::string		target = "ROB";
	std::string		b_name = "Nick";

	printExecTestInfo("RobotomyRequestForm", target, b_name, bureaucreatGrade);

	try
	{
		RobotomyRequestForm	r(target);
		Bureaucrat			b(b_name, bureaucreatGrade);

		signForm(sign, &r, b);

		r.execute(b);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testPresidentialPardonForm(int bureaucreatGrade, bool sign)
{
	std::string		target = "Ford";
	std::string		b_name = "Nancy";

	printExecTestInfo("PresidentialPardonForm", target, b_name, bureaucreatGrade);

	try
	{
		PresidentialPardonForm	p(target);
		Bureaucrat				b(b_name, bureaucreatGrade);

		signForm(sign, &p, b);

		p.execute(b);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCopy(bool sign)
{
	std::string		target = "August";
	Bureaucrat		b("tmp", GRADE_HIGHEST);

	printFormTestInfo("RobotomyRequestForm", target);

	try
	{
		RobotomyRequestForm	f(target);
		signForm(sign, &f, b);
		Form*	f_copy = new RobotomyRequestForm(f);

		std::cout << "Original: " << f << std::endl;
		std::cout << "Copied  : " << *f_copy << std::endl;

		delete f_copy;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testAssignation(bool sign)
{
	std::string		target = "Kitty";
	Bureaucrat		b("tmp", GRADE_HIGHEST);

	printFormTestInfo("ShrubberyCreationForm", target);

	try
	{
		ShrubberyCreationForm	f_src(target);
		ShrubberyCreationForm	f_dst(target + '2');
		signForm(sign, &f_src, b);

		std::cout << "src before copy: " << f_src << std::endl;
		std::cout << "dst before copy: " << f_dst << std::endl;

		f_dst = f_src;
		std::cout << "dst after copy : " << f_dst << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int		main()
{
	std::srand(time(NULL));
	/*
	*/
	printTestName("Shrubbery Creation Form [gradeToSign=145, gradeToExec=137]");
	testShrubberyCreationForm(1, true);
	testShrubberyCreationForm(2, false);
	testShrubberyCreationForm(140, true);
	testShrubberyCreationForm(150, true);

	printTestName("Robotomy Request Form [gradeToSign=72, gradeToExec=45]");
	testRobotomyRequestForm(1, true);
	testRobotomyRequestForm(20, true);
	testRobotomyRequestForm(70, false);
	testRobotomyRequestForm(70, true);
	testRobotomyRequestForm(140, true);

	printTestName("Presidential Pardon Form [gradeToSign=25, gradeToExec=5]");
	testPresidentialPardonForm(1, true);
	testPresidentialPardonForm(5, true);
	testPresidentialPardonForm(4, false);
	testPresidentialPardonForm(70, true);

	printTestName("Copy");
	testCopy(true);
	testCopy(false);

	printTestName("Assignation");
	testAssignation(true);
	testAssignation(false);
}
