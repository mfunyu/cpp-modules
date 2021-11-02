/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:06:27 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/02 15:44:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int		main()
{
	try
	{
		Bureaucrat	normal_1; /* without a specified name, grade */
		std::cout << normal_1 << std::endl;

		Bureaucrat	normal_2("normal_2"); /* without a specified grade */
		std::cout << normal_2 << std::endl;

		Bureaucrat	normal_3("normal_3", 42);
		std::cout << normal_3 << std::endl;

		Bureaucrat	e_tooHigh("e_tooHigh", 0); /* gradeTooHigh  0 < 1 */
		std::cout << e_tooHigh << std::endl;

		Bureaucrat	x_neverReachesHere("x_neverReachesHere", 42);
		std::cout << x_neverReachesHere << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException)
	{
		std::cout << "Exception" << std::endl;
	}
}
