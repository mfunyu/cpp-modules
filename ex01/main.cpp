/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:52 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 22:51:42 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

# define SET_COLOR "\033[36m"
# define RESET_COLOR "\033[m"

namespace {
	void	printInstruction(std::string cmd)
	{
		std::cout << "Invalid input: " << cmd << std::endl;
		std::cout << "available commands [ADD/SEARCH/EXIT]" << std::endl;
	}

	void	printPrompt()
	{
		std::cout << "Enter a command" << std::endl;
		std::cout << SET_COLOR << "$> " << RESET_COLOR;
	}
} /* namespace */

int	main(void)
{
	PhoneBook	phonebook;

	while (1)
	{
		printPrompt();
		std::string cmd;
		std::cin >> cmd;

		if (std::cin.eof()) {
			std::exit(EXIT_FAILURE);
		}

		if (cmd == "EXIT") {
			std::cout << "Bye!" << std::endl;
			return 0;
		} else if (cmd == "ADD") {
			phonebook.add();
		} else if (cmd == "SEARCH") {
			phonebook.search();
		} else {
			printInstruction(cmd);
		}
		std::cout << std::endl;
	}
	return 0;
}
