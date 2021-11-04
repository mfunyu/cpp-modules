/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:19:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 12:36:45 by mfunyu           ###   ########.fr       */
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

std::string	createFormString(std::string name, int gradeToSign, int gradeToExec, bool isSigned = false)
{
	std::string signStatus = (isSigned ? "true" : "false");

	return "Form(name=" + name + ", gradeToSign=" + std::to_string(gradeToSign) +\
								 ", gradeToExec=" + std::to_string(gradeToExec) +\
								 ", isSigned=" + signStatus + ")";
}

std::string	createBureaucratString(std::string name, int grade)
{
	return "Bureaucrat(name=" + name + ", grade=" + std::to_string(grade) + ")";
}

void	printExecTestInfo(std::string f_name, int gradeToSign, int gradeToExec, bool isSigned, std::string b_name, int grade)
{
	std::cout << SET_COLOR "// " << createFormString(f_name, gradeToSign, gradeToExec, isSigned) <<\
				 ".execute(" << createBureaucratString(b_name, grade) << ")" << RESET_COLOR << std::endl;
}

void	printFormTestInfo(std::string name, int gradeToSign, int gradeToExec, bool isSigned = false, std::string append = "")
{
	std::cout << SET_COLOR "// " << createFormString(name, gradeToSign, gradeToExec, isSigned) <<\
				 append << RESET_COLOR << std::endl;
}

void	printBureaucratTestInfo(std::string name, int grade, std::string append = "")
{
	std::cout << SET_COLOR "// " << createBureaucratString(name, grade) <<\
				 append << RESET_COLOR << std::endl;
}

/******************************** TESTS ********************************/

void	testShrubberyCreationForm(int bureaucreatGrade, bool isSigned)
{
	std::string		target = "home";
	std::string		b_name = "Cathy";

	printExecTestInfo("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC, isSigned, b_name, bureaucreatGrade);

	try
	{
		ShrubberyCreationForm	s(target);
		/* signing the form */
		if (isSigned) {
			s.beSigned(Bureaucrat(b_name, bureaucreatGrade));
		}

		s.execute(Bureaucrat(b_name, bureaucreatGrade));
		std::cout << "Successfully executed. Check file " + target + "_shrubbery" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int		main()
{
	/*
	*/
	printTestName("Shrubbery Creation Form");
	testShrubberyCreationForm(1, true);
	testShrubberyCreationForm(140, true);
	testShrubberyCreationForm(150, true);
}
