/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:54:26 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/24 00:24:42 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>
#include <string>

enum	ComplainType
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	OTHER
};

int	resolveComplainType(std::string level)
{
	if (level.compare("DEBUG") == 0)
		return DEBUG;
	if (level.compare("INFO") == 0)
		return INFO;
	if (level.compare("WARNING") == 0)
		return WARNING;
	if (level.compare("ERROR") == 0)
		return ERROR;
	return -1;
}


int		main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Invalid arguments" << std::endl;
		return 0;
	}

	Karen	karen;

	switch (resolveComplainType(av[1]))
	{
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			karen.complain("DEBUG");
			std::cout << std::endl;
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			karen.complain("INFO");
			std::cout << std::endl;
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			karen.complain("WARNING");
			std::cout << std::endl;
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			karen.complain("ERROR");
			std::cout << std::endl;
	}
}
