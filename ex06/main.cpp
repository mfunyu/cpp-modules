/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:54:26 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 15:39:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>
#include <string>

/* -------------------------------------------------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

void	print(std::string typeLevel)
{
	std::cout << COLOR_CYAN << "[ " << typeLevel << " ]"
				<< COLOR_RESET << std::endl;
}

/* -------------------------------------------------------------------------- */

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
		case DEBUG:
			print("DEBUG");
			karen.complain("DEBUG");
			std::cout << std::endl;
		case INFO:
			print("INFO");
			karen.complain("INFO");
			std::cout << std::endl;
		case WARNING:
			print("WARNING");
			karen.complain("WARNING");
			std::cout << std::endl;
		case ERROR:
			print("ERROR");
			karen.complain("ERROR");
			break ;
		default:
			print("Probably complaining about insignificant problems");
	}
}
