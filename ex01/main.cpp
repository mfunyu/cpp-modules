/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:06:27 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/03 20:10:13 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

# define SET_COLOR "\033[36m"
# define RESET_COLOR "\033[m"

void	printTestName(std::string testName)
{
	std::cout << SET_COLOR "\n/*** Test Form " << testName <<\
				" ***/" RESET_COLOR << std::endl;
}

void	printTestInfo(std::string name, int gradeToSign, int gradeToExec, std::string append = "")
{
	std::cout << SET_COLOR "// Form(name=" << name <<\
				 ", gradeToSign=" << std::to_string(gradeToSign) <<\
				 ", gradeToExec=" << std::to_string(gradeToExec) <<\
				 ")" << append <<\
				 RESET_COLOR << std::endl;
}

void	testFormConstructor(int gradeToSign, int gradeToExec)
{
	std::string		name = "RandomForm";

	printTestInfo(name, gradeToSign, gradeToExec);

	try
	{
		Form f(name, gradeToSign, gradeToExec);
		std::cout << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int		main()
{
	printTestName("Constructor");
	testFormConstructor(1, 2);
	testFormConstructor(2, 2);
	testFormConstructor(42, 2);
	testFormConstructor(150, 2);
	testFormConstructor(151, 2);
}
