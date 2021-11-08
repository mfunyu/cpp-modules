/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 13:35:01 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Format.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void	Contact::print(void) const
{
	_format.printSeparator(30, '=');
	_format.printPairLine("first_name", _firstName, 15);
	_format.printPairLine("last_name", _lastName, 15);
	_format.printPairLine("nickname", _nickname, 15);
	_format.printPairLine("phone_number", _phoneNumber, 15);
	_format.printPairLine("darkest_secret", _darkestSecret, 15);
	_format.printSeparator(30, '=');
}

void	Contact::fillout(void)
{
	_format.printSeparator(10, '-');
	_format.setKeyWidth(20);
	std::cout << "Input a new contact’s information" << std::endl;
	_format.printKey("Enter first name", 20);
	std::cin >> _firstName;
	_format.printKey("Enter last name", 20);
	std::cin >> _lastName;
	_format.printKey("Enter nickname", 20);
	std::cin >> _nickname;
	_format.printKey("Enter phone number", 20);
	std::cin >> _phoneNumber;
	_format.printKey("Enter darkest secret", 20);
	std::cin >> _darkestSecret;
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
