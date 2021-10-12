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

static void	print_one_column(std::string str)
{
	if (str.size() > 10) {
		str.replace(str.begin() + 9, str.end(), 1, '.');
	}
	std::cout << std::setw(10) << str << SPACER;
}

void	PhoneBook::print_header(void)
{
	std::cout << SPACER;
	print_one_column("index");
	print_one_column("first_name");
	print_one_column("last_name");
	print_one_column("nickname");
	std::cout << std::endl;
}

void	PhoneBook::print_border(int num_cols)
{
	std::cout << '+';
	for (int i = 0; i < num_cols; i++) {
		std::cout << std::string(10, '-') << '+';
	}
	std::cout << std::endl;
}

void	PhoneBook::print_table() const
{
	print_border(4);
	print_header();
	for (int i = 0; contact_lst[i].get_is_filled(); i++) {
		print_border(4);
		std::cout << SPACER;
		print_one_column(std::to_string(i));
		print_one_column(contact_lst[i].get_first_name());
		print_one_column(contact_lst[i].get_last_name());
		print_one_column(contact_lst[i].get_nickname());
		std::cout << std::endl;
	}
	print_border(4);
	std::cout << std::endl;
}

void	PhoneBook::search() const
{
	if (!contact_lst[0].get_is_filled()) {
		std::cout << "-------" << std::endl;
		std::cout << "Error: No available contact" << std::endl;
		return ;
	}

	print_table();

	std::cout << "Enter index of the desired entry: ";
	unsigned int	index;
	std::cin >> index;
	if (std::cin.fail()) {
		std::cout << "Error: Invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}

	if (index < MAX_CONTACTS && contact_lst[index].get_is_filled()) {
		contact_lst[index].print();
	} else {
		std::cout << "Error: Index out of range" << std::endl;
	}
}

