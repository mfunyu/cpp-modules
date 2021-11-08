/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 14:57:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Format.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : _contactIndex(0)
{
	Format	_format(15);
	return ;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	_contactList[_contactIndex].fillout();
	_updateContactIndex();
}

void	PhoneBook::search() const
{
	if (!_contactList[0].isFilled()) {
		_format.printSeparator(10, '-');
		_format.printInfoLine("Error: No available contact");
		return ;
	}

	_printTable();

	std::cout << "Enter index of the desired entry: ";
	unsigned int	index;
	std::cin >> index;

	if (std::cin.fail()) {
		_format.printInfoLine("Error: Invalid input");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}

	if (index < MAX_CONTACTS && _contactList[index].isFilled()) {
		_contactList[index].print();
	} else {
		_format.printInfoLine("Error: Index out of range");
	}
}

void	PhoneBook::_printTable() const {
	std::string		header[4] = {"index", "first_name", "last_name", "nickname"};

	_format.printTableHeader(header);
	for (int i = 0; _contactList[i].isFilled(); i++) {
		std::string	content[4] = {
									std::to_string(i),
									_contactList[i].getFirstName(),
									_contactList[i].getLastName(),
									_contactList[i].getNickname()
								};
		_format.printTableRow(content);
	}
	_format.printTableBorder('+', '-');
	std::cout << std::endl;
}

void	PhoneBook::_updateContactIndex(void) {
	_contactIndex += 1;
	if (_contactIndex == MAX_CONTACTS)
		_contactIndex = 0;
}
