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

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

# define NUM_COLS 4
# define COL_WIDTH 10

void	PhoneBook::_print_one_column(std::string str) {
	if (str.size() > COL_WIDTH) {
		str.replace(str.begin() + COL_WIDTH - 1, str.end(), 1, '.');
	}
	std::cout << std::setw(10) << str << "|";
}

void	PhoneBook::_print_header(void) {
	std::cout << "|";
	_print_one_column("index");
	_print_one_column("first_name");
	_print_one_column("last_name");
	_print_one_column("nickname");
	std::cout << std::endl;
}

void	PhoneBook::_print_border() {
	std::cout << '+';
	for (int i = 0; i < NUM_COLS; i++) {
		std::cout << std::string(COL_WIDTH, '-') << '+';
	}
	std::cout << std::endl;
}

void	PhoneBook::_print_table() const {
	_print_border();
	_print_header();
	for (int i = 0; _contact_lst[i].is_filled(); i++) {
		_print_border();
		std::cout << "|";
		_print_one_column(std::to_string(i));
		_print_one_column(_contact_lst[i].get_first_name());
		_print_one_column(_contact_lst[i].get_last_name());
		_print_one_column(_contact_lst[i].get_nickname());
		std::cout << std::endl;
	}
	_print_border();
	std::cout << std::endl;
}

void	PhoneBook::search() const {
	if (!_contact_lst[0].is_filled()) {
		std::cout << "-------" << std::endl;
		std::cout << "Error: No available contact" << std::endl;
		return ;
	}

	_print_table();

	std::cout << "Enter index of the desired entry: ";
	unsigned int	index;
	std::cin >> index;
	if (std::cin.fail()) {
		std::cout << "Error: Invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}

	if (index < MAX_CONTACTS && _contact_lst[index].is_filled()) {
		_contact_lst[index].print();
	} else {
		std::cout << "Error: Index out of range" << std::endl;
	}
}

int	PhoneBook::_get_contacts_total(void) const {
	return _contacts_total;
}

void	PhoneBook::_reset_contacts_total(void) {
	_contacts_total = 0;
}

void	PhoneBook::_increment_contacts_total(void) {
	_contacts_total += 1;
}

void	PhoneBook::add() {
	std::cout << "-------" << std::endl;
	std::cout << "Input a new contact’s information" << std::endl;

	int		index = _get_contacts_total();
	if (index == MAX_CONTACTS)
		_reset_contacts_total();
	_contact_lst[index].fillout();
	_increment_contacts_total();
}

PhoneBook::PhoneBook() : _contacts_total(0){
	return ;
}
