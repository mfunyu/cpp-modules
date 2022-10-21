/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/09 21:48:53 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Format.hpp"

#define INVERT "\033[7m"
#define RESET_INVERT "\033[0m"

Format::Format() : _keyWidth(15), _numCols(4), _colWidth(10)
{
}

Format::~Format()
{
}

Format::Format(unsigned int keyWidth) :
	_keyWidth(keyWidth)
{
}

/****************************** print lines ***********************************/

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
	std::cout << INVERT << std::setw(keyWidth) << key <<\
				 ":" << RESET_INVERT << " " << std::flush;
	std::cout.unsetf(std::ios::left);
}

void	Format::printPairLine(std::string const & key, std::string const & value,
								unsigned int keyWidth) const
{
	printKey(key, keyWidth);
	std::cout << value << std::endl;
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
	if (col.size() > _colWidth) {
		col.replace(_colWidth - 1, col.size(), 1, '.');
	}
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

/****************************** set & input ***********************************/

void	Format::setKeyWidth(unsigned int keyWidth)
{
	_keyWidth = keyWidth;
}

std::string	Format::promptGetStrInput(std::string key) const
{
	printKey("Enter " + key);

	std::string		input;
	while (1)
	{
		std::cin >> input;

		if (std::cin.eof() || std::cin.bad()) {
			std::exit(EXIT_FAILURE);
		}
		if (std::cin.fail()) {
			printInfoLine("Error: Invalid input");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		break ;
	}
	return input;
}

unsigned int	Format::promptGetUIntInput(std::string key) const
{
	unsigned int	input;
	while (1)
	{
		std::cout << "Enter " + key + ": ";
		std::cin >> input;

		if (std::cin.eof() || std::cin.bad()) {
			std::exit(EXIT_FAILURE);
		}
		if (std::cin.fail()) {
			printInfoLine("Error: Invalid input");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		break ;
	}
	return input;
}
