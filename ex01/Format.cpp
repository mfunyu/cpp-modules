/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 13:36:29 by mfunyu           ###   ########.fr       */
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

void	Format::printPairLine(std::string key, std::string value, unsigned int keyWidth) const
{
	std::cout.setf(std::ios::left);
	std::cout << std::setw(keyWidth) <<\
				 key << ": " << value << std::endl;
	std::cout.unsetf(std::ios::left);
}

void	Format::printKey(std::string key, unsigned int keyWidth) const
{
	std::cout.setf(std::ios::left);
	std::cout << std::setw(keyWidth) << key << ": " << std::flush;
	std::cout.unsetf(std::ios::left);
}

void	Format::printSeparator(unsigned int width = 30, char ch = '-') const
{
	std::string	separator;

	separator.append(width, ch);
	std::cout << separator << std::endl;
}

void	Format::setKeyWidth(unsigned int keyWidth)
{
	_keyWidth = keyWidth;
}
