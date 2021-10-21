/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:52 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/20 21:59:03 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static void	print_instruction(std::string cmd)
{
	std::cout << "Invalid input: " << cmd << std::endl;
	std::cout << "available commands [ADD/SEARCH/EXIT]" << std::endl;
}

int	main()
{
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Please enter a command: ";
		std::string cmd;
		std::cin >> cmd;

		if (std::cin.eof()) {
			std::cin.clear();
			std::clearerr(stdin);
			continue ;
		}

		if (cmd.compare("EXIT") == 0) {
			return (0);
		} else if (cmd.compare("ADD") == 0) {
			phonebook.add();
		} else if (cmd.compare("SEARCH") == 0) {
			phonebook.search();
		} else {
			print_instruction(cmd);
		}
		std::cout << std::endl;
	}

}
