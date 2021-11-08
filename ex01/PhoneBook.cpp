/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 21:58:10 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Format.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

unsigned int	PhoneBook::_maxContacts = MAX_CONTACTS;

PhoneBook::PhoneBook() : _contactIndex(0)
{
	Format	_format(15);
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
		_format.printInfoLine("Error: No available contact");
		return ;
	}

	_printTable();

	unsigned int index = _format.promptGetUIntInput("index of the desired entry");

	if (index >= _maxContacts || !_contactList[index].isFilled()) {
		_format.printInfoLine("Error: Index out of range");
		return ;
	}

	_contactList[index].print();
}

void	PhoneBook::_printTable() const
{
	std::string		header[4] = {"index", "first_name", "last_name", "nickname"};

	_format.printTableHeader(header);
	for (int i = 0; _contactList[i].isFilled(); i++) {
		std::ostringstream	oss;
		oss << i;

		std::string	content[4] = {
			oss.str(),
			_contactList[i].getFirstName(),
			_contactList[i].getLastName(),
			_contactList[i].getNickname()
		};
		_format.printTableRow(content);
	}
	_format.printTableBorder('+', '-');
	std::cout << std::endl;
}

void	PhoneBook::_updateContactIndex(void)
{
	_contactIndex += 1;
	if (_contactIndex == _maxContacts) {
		_contactIndex = 0;
	}
}
