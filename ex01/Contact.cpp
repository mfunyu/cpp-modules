/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 14:11:10 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Contact.hpp"
#include "Format.hpp"

Contact::Contact() : _isFilled(false)
{
}

Contact::~Contact()
{
}

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
	_format.printInfoLine("Input a new contact’s information");
	_firstName = _format.promptGetInput("first name");
	_lastName = _format.promptGetInput("last name");
	_nickname = _format.promptGetInput("nickname");
	_phoneNumber = _format.promptGetInput("phone number");
	_darkestSecret = _format.promptGetInput("darkest secret");
	_isFilled = true;
}

bool	Contact::isFilled(void) const
{
	return _isFilled;
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
