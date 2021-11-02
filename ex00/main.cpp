/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:06:27 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/02 15:26:57 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int		main()
{
	{
		Bureaucrat	a_1;
		std::cout << a_1 << std::endl;

		Bureaucrat	b_2("b_2");
		std::cout << b_2 << std::endl;

		Bureaucrat	c_3("c_3", 42);
		std::cout << c_3 << std::endl;
	}
}
