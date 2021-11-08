/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 14:46:16 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Format.hpp"

Format::Format() : _keyWidth(15), _numCols(4), _colWidth(10)
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

/****************************** print lines ***********************************/

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

/****************************** print table ***********************************/

void	Format::printTableSingleColumn(std::string col) const
{
	std::cout << std::setw(_colWidth) << col << "|";
}

void	Format::printTableRow(std::string *lst) const
{
	printTableBorder('+', '-');
	std::cout << "|";
	for (int i = 0; i < _numCols; i++) {
		printTableSingleColumn(lst[i]);
	}
	std::cout << std::endl;
}

void	Format::printTableHeader(std::string *lst) const
{
	printTableRow(lst);
}

void	Format::printTableBorder(char charCorner, char charLine) const
{
	std::string		line(_colWidth, charLine);

	std::cout << charCorner;
	for (int i = 0; i < _numCols; i++) {
		std::cout << line << charCorner;
	}
	std::cout << std::endl;
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
