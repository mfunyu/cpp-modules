/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:06:27 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/03 13:40:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	test_decrement(int grade)
{
	/* display grade */
	std::cout << "[" << grade << "] ";

	/* call decrement in try-catch */
	try
	{
		Bureaucrat bureaucrat_a("bureaucrat_a", grade);
		std::cout << bureaucrat_a << " -> ";
		bureaucrat_a.decrementGrage();
		std::cout << bureaucrat_a.getGrade() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_increment(int grade)
{
	/* display grade */
	std::cout << "[" << grade << "] ";

	/* call increment in try-catch */
	try
	{
		Bureaucrat bureaucrat_a("bureaucrat_a", grade);
		std::cout << bureaucrat_a << " -> ";
		bureaucrat_a.incrementGrage();
		std::cout << bureaucrat_a.getGrade() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_constructionWithGrade(int grade)
{
	/* display grade */
	std::cout << "[" << grade << "] ";

	/* call construction in try-catch */
	try
	{
		Bureaucrat test("test", grade);
		std::cout << test << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_howConstructorWorks()
{
	try
	{
		Bureaucrat	normal_1; /* without a specified name, grade */
		std::cout << normal_1 << std::endl;

		Bureaucrat	normal_2("normal_2"); /* without a specified grade */
		std::cout << normal_2 << std::endl;

		Bureaucrat	normal_3("normal_3", 42);
		std::cout << normal_3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

int		main()
{
	// test_howConstructorWorks();
	std::cout << "==== checking construction with grade ======" << std::endl;
	{
		int		gradelst[10] = {-10000, -1, 0, 1, 2, 50, 149, 150, 151, 100000000};
		for (int i = 0; i < 10; i++)
		{
			test_constructionWithGrade(gradelst[i]);
		}
	}
	std::cout << "==== checking increment grade ======" << std::endl;
	{
		int		gradelst[10] = {-1, 0, 1, 2, 50, 148, 149, 150, 151};
		for (int i = 0; i < 10; i++)
		{
			test_increment(gradelst[i]);
		}
	}
	std::cout << "==== checking decrement grade ======" << std::endl;
	{
		int		gradelst[10] = {-1, 0, 1, 2, 50, 148, 149, 150, 151};
		for (int i = 0; i < 10; i++)
		{
			test_decrement(gradelst[i]);
		}
	}
}
