/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 11:36:50 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void	Contact::_print_one_line(std::string name, std::string value)
{
	std::cout << std::setw(15) << name << ": " << value << std::endl;
}

void	Contact::print(void) const
{
	std::cout.setf(std::ios::left);
	std::cout << "================================" << std::endl;
	_print_one_line("first_name", _firstName);
	_print_one_line("last_name", _lastName);
	_print_one_line("nickname", _nickname);
	_print_one_line("phone_number", _phoneNumber);
	_print_one_line("darkest_secret", _darkestSecret);
	std::cout << "================================" << std::endl;
	std::cout.unsetf(std::ios::left);
}

void	Contact::fillout(void)
{
	std::cout << "-------" << std::endl;
	std::cout << "Input a new contact’s information" << std::endl;
	std::cout.setf(std::ios::left);
	std::cout << std::setw(20) << "Enter first name"
			  << ": ";
	std::cin >> _firstName;
	std::cout << std::setw(20) << "Enter last name"
			  << ": ";
	std::cin >> _lastName;
	std::cout << std::setw(20) << "Enter nickname"
			  << ": ";
	std::cin >> _nickname;
	std::cout << std::setw(20) << "Enter phone number"
			  << ": ";
	std::cin >> _phoneNumber;
	std::cout << std::setw(20) << "Enter darkest secret" << ": ";
	std::cin >> _darkestSecret;
	std::cout.unsetf(std::ios::left);
	_isFilled = true;
}

std::string const & Contact::getFirstName(void) const
{
	return _firstName;
}

std::string const & Contact::getLastName(void) const
{
	return _lastName;
}

std::string const &	Contact::getNickname(void) const
{
	return _nickname;
}

bool	Contact::isFilled(void) const
{
	return _isFilled;
}

Contact::Contact() : _isFilled(false)
{
	return;
}

Contact::~Contact()
{
	return;
}
