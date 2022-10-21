/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:56:17 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 23:22:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>

/* --------------------------- print & formatting --------------------------- */

#define SET_COLOR	"\033[36m"
#define RESET_COLOR "\033[m"

void printTestName(std::string testName)
{
	std::cout << SET_COLOR "\n/*** Test " << testName << " ***/" RESET_COLOR
			  << std::endl;
}

/* -------------------------------------------------------------------------- */

int main()
{
	{
		printTestName("Robotomy Request Form");
		Intern		someRandomIntern;
		Form*		rrf;
		std::string target = "Bender";

		rrf = someRandomIntern.makeForm("robotomy request", target);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	{
		printTestName("Presidential Pardon Form");
		Intern		someRandomIntern;
		Form*		rrf;
		std::string target = "Lucy";

		rrf = someRandomIntern.makeForm("presidential pardon", target);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	{
		printTestName("Shrubbery Creation Form");
		Intern		someRandomIntern;
		Form*		rrf;
		std::string target = "Sum";

		rrf = someRandomIntern.makeForm("shrubbery creation", target);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	{
		printTestName("Wrong Form");
		Intern		someRandomIntern;
		Form*		rrf;
		std::string target = "Bender";
		try {
			rrf = someRandomIntern.makeForm("non", target);
			std::cout << rrf << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}
