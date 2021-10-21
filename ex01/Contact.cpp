/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/21 23:07:18 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void Contact::_print_one_line(std::string name, std::string value) {
	std::cout << std::setw(15) << name << ": " << value << std::endl;
}

void	Contact::print(void) const {
	std::cout.setf(std::ios::left);
	std::cout << "================================" << std::endl;
	_print_one_line("first_name", _first_name);
	_print_one_line("last_name", _last_name);
	_print_one_line("nickname", _nickname);
	_print_one_line("phone_number", _phone_number);
	_print_one_line("darkest_secret", _darkest_secret);
	std::cout << "================================" << std::endl;
	std::cout.unsetf(std::ios::left);
}

void	Contact::fillout(void) {
	std::cout << "-------" << std::endl;
	std::cout << "Input a new contact’s information" << std::endl;
	std::cout.setf(std::ios::left);
	std::cout << std::setw(20) << "Enter first name" << ": ";
	std::cin >> _first_name;
	std::cout << std::setw(20) << "Enter last name" << ": ";
	std::cin >> _last_name;
	std::cout << std::setw(20) << "Enter nickname" << ": ";
	std::cin >> _nickname;
	std::cout << std::setw(20) << "Enter phone number" << ": ";
	std::cin >> _phone_number;
	std::cout <<  std::setw(20) << "Enter darkest secret" << ": ";
	std::cin >> _darkest_secret;
	std::cout.unsetf(std::ios::left);
	_is_filled = true;
}

std::string	Contact::get_first_name(void) const {
	return _first_name;
}

std::string	Contact::get_last_name(void) const {
	return _last_name;
}

std::string	Contact::get_nickname(void) const {
	return _nickname;
}

bool	Contact::is_filled(void) const {
	return _is_filled;
}

Contact::Contact() : _is_filled(false) {
	return ;
}

Contact::~Contact() {
	return ;
}
