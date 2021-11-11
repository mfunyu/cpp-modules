/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:54:26 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 16:50:09 by mfunyu           ###   ########.fr       */
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
	ERROR
};

int	resolveComplainType(std::string level)
{
	std::string	level_lst[4] = {};
	level_lst[DEBUG] = "DEBUG";
	level_lst[INFO] = "INFO";
	level_lst[WARNING] = "WARNING";
	level_lst[ERROR] = "ERROR";

	int	i = 0;
	while (i < 4 && level != level_lst[i]) {
		i++;
	}
	return i;
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
