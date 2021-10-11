/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 17:03: by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>

#define SPACER "|"
#define SEPARATOR ": "

static void	print_one_column(std::string str, bool add_spacer)
{
	if (str.size() > 10) {
		str.replace(str.begin() + 9, str.end(), 1, '.');
	}
	std::cout << std::setw(10) << str;
	if (add_spacer) {
		std::cout << SPACER;
	}
}

void	PhoneBook::print_header(void)
{
	print_one_column("index", true);
	print_one_column("first_name", true);
	print_one_column("last_name", true);
	print_one_column("nickname", false);
	std::cout << std::endl;
}

void	PhoneBook::print_table()
{
	print_header();
	for (int i = 0; contact_lst[i].is_filled; i++) {
		std::cout << std::setw(10) << i << SPACER;
		print_one_column(contact_lst[i].first_name, true);
		print_one_column(contact_lst[i].last_name, true);
		print_one_column(contact_lst[i].nickname, false);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::search()
{
	if (!contact_lst[0].is_filled) {
		std::cout << "Error: No available contact" << std::endl;
		return ;
	}

	print_table();

	std::cout << "Enter index of the desired entry: ";
	int	index;
	std::cin >> index;
	if (std::cin.fail()) {
		std::cout << "Error: Invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if (contact_lst[index].is_filled) {
		contact_lst[index].print();
	} else {
		std::cout << "Error: Index out of range" << std::endl;
	}
}

