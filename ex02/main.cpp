/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:19:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 13:50:26 by mfunyu           ###   ########.fr       */
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

	printTestName("Robotomy Request Form gradeToSign=72, gradeToExec=45");
	testRobotomyRequestForm(1, true);
	testRobotomyRequestForm(20, true);
	testRobotomyRequestForm(70, false);
	testRobotomyRequestForm(70, true);
	testRobotomyRequestForm(140, true);
}
