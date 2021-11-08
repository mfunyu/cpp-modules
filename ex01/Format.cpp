/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 14:07:38 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Format.hpp"

Format::Format() : _keyWidth(15)
{
}

Format::~Format()
{
}

Format::Format(const Format &other)
{
	*this = other;
}

Format	&Format::operator=(const Format &other)
{
	if (this != &other)
	{
		_keyWidth = other._keyWidth;
	}
	return *this;
}

Format::Format(unsigned int keyWidth) :
	_keyWidth(keyWidth)
{
}

/************************ Print related funcs *****************************/

void	Format::printPairLine(std::string const & key, std::string const & value, unsigned int keyWidth) const
{
	std::cout.setf(std::ios::left);
	std::cout << std::setw(keyWidth) <<\
				 key << ": " << value << std::endl;
	std::cout.unsetf(std::ios::left);
}

void	Format::printInfoLine(std::string const & info) const
{
	std::cout << info << std::endl;
}

void	Format::printKey(std::string const & key, unsigned int keyWidth) const
{
	if (!keyWidth) {
		keyWidth = _keyWidth;
	}
	std::cout.setf(std::ios::left);
	std::cout << std::setw(keyWidth) << key << ": " << std::flush;
	std::cout.unsetf(std::ios::left);
}

void	Format::printSeparator(unsigned int width, char ch) const
{
	std::string	separator;

	separator.append(width, ch);
	std::cout << separator << std::endl;
}

void	Format::setKeyWidth(unsigned int keyWidth)
{
	_keyWidth = keyWidth;
}

std::string	Format::promptGetInput(std::string key)
{
	std::string		input;

	printKey("Enter" + key);
	std::cin >> input;
	return input;
}
