/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 14:48:18 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Format.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void	PhoneBook::_print_table() const {
	std::string		header[4] = {"index", "first_name", "last_name", "nickname"};

	_format.printTableHeader(header);
	for (int i = 0; _contact_lst[i].isFilled(); i++) {
		std::string	content[4] = {
									std::to_string(i),
									_contact_lst[i].getFirstName(),
									_contact_lst[i].getLastName(),
									_contact_lst[i].getNickname()
								};
		_format.printTableRow(content);
	}
	_format.printTableBorder('+', '-');
	std::cout << std::endl;
}

void	PhoneBook::search() const {
	if (!_contact_lst[0].isFilled()) {
		_format.printSeparator(10, '-');
		_format.printInfoLine("Error: No available contact");
		return ;
	}

	_print_table();

	std::cout << "Enter index of the desired entry: ";
	unsigned int	index;
	std::cin >> index;

	if (std::cin.fail()) {
		_format.printInfoLine("Error: Invalid input");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}

	if (index < MAX_CONTACTS && _contact_lst[index].isFilled()) {
		_contact_lst[index].print();
	} else {
		_format.printInfoLine("Error: Index out of range");
	}
}

unsigned int	PhoneBook::_get_contact_index(void) const {
	return _contact_index;
}

void	PhoneBook::_update_contact_index(void) {
	_contact_index += 1;
	if (_contact_index == MAX_CONTACTS)
		_contact_index = 0;
}

void	PhoneBook::add() {
	unsigned int	new_contact_index = _get_contact_index();

	_contact_lst[new_contact_index].fillout();
	_update_contact_index();
}

PhoneBook::PhoneBook() : _contact_index(0) {
	Format	_format(15);
	return ;
}

PhoneBook::~PhoneBook() {
	return ;
}
