/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/22 16:15:15 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void	PhoneBook::_print_one_column(std::string str) {
	if (str.size() > COL_WIDTH) {
		str.replace(str.begin() + COL_WIDTH - 1, str.end(), 1, '.');
	}
	std::cout << std::setw(10) << str << "|";
}

void	PhoneBook::_print_contents() const {
	for (int i = 0; _contact_lst[i].is_filled(); i++) {
		_print_border();
		std::cout << "|";
		_print_one_column(std::to_string(i));
		_print_one_column(_contact_lst[i].get_first_name());
		_print_one_column(_contact_lst[i].get_last_name());
		_print_one_column(_contact_lst[i].get_nickname());
		std::cout << std::endl;
	}
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
	_print_contents();
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

PhoneBook::PhoneBook() : _contact_index(0){
	return ;
}

PhoneBook::~PhoneBook() {
	return ;
}
