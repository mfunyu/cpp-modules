/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:47:54 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/06 13:11:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <climits>
#include "Convert.hpp"

std::string		impossible = "impossible";

Convert::Convert()
{
}

Convert::~Convert()
{
}

Convert::Convert(const Convert &other) : _str(other._str)
{
	*this = other;
}

Convert	&Convert::operator=(const Convert &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Convert::Convert(std::string const & str) : _str(str), _precision(0)
{
}

void	Convert::setImpossible()
{
	_strDouble = impossible;
	_strFloat = impossible;
	_strInt = impossible;
	_strChar = impossible;
}

void	Convert::interpretCurrentType()
{
	if (_str.empty()) {
		setImpossible();
		return ;
	}
	if (_str.length() == 1
			&& !std::isdigit(_str.at(0)) && std::isprint(_str.at(0))) {
		convertStrToChar();
		return ;
	}

	int		strlen = _str.length();
	if (_str.at(strlen - 1) == 'f') {
		strlen -= 1;
	}

	int		point = 0;
	int		zero_tail = 0;
	for (int i = 0; i < strlen; i++) {
		if (i == 0 && _str.at(i) == '-') {
			continue ;
		}
		if (point == 0 && _str.at(i) == '.') {
			point = 1;
			continue ;
		}
		if (point == 1) {
			_precision += 1;
			if (_str.at(i) == '0') {
				zero_tail += 1;
			} else {
				zero_tail = 0;
			}
		}
		if (!std::isdigit(_str.at(i))) {
			setImpossible();
			return ;
		}
	}
	_precision -= zero_tail;
	std::cout << zero_tail << std::endl;
	convertStrToDouble();
}

void	Convert::convertStrToChar()
{
	std::cout << "CHAR" << std::endl;
	_store = static_cast<double>(_str.at(0));
}

void	Convert::convertStrToDouble()
{
	std::cout << "DOUBLE" << std::endl;
	std::istringstream iss(_str);

	iss >> _double;
	_store = _double;
	std::cout << _store << std::endl;
}


void	Convert::solve()
{
	interpretCurrentType();
	convertDoubleToStrType();
}

void	Convert::convertDoubleToStrType()
{
	if (_strDouble == impossible) {
		return ;
	}
	convertDoubleToStrDouble();
	convertDoubleToStrFloat();
	convertDoubleToStrInt();
	convertDoubleToStrChar();
}

void	Convert::convertDoubleToStrChar()
{
	if (_strInt == impossible) {
		_strChar = impossible;
		return ;
	}

	int		i = static_cast<int>(_store);
	if (!std::isprint(i)) {
		_strChar = "Non displayable";
		return ;
	}

	_strChar = static_cast<char>(_store);
	_strChar = "'" + _strChar + "'";
}

void	Convert::convertDoubleToStrInt()
{
	if (_store < INT_MIN || INT_MAX < _store) {
		_strInt = impossible;
		return ;
	}

	int		i = static_cast<int>(_store);

	std::ostringstream oss;
	oss << i << std::flush;
	_strInt = oss.str();
}

void	Convert::convertDoubleToStrFloat()
{
	if (_strDouble == impossible) {
		_strFloat = impossible;
		return ;
	}
	float	f = static_cast<float>(_store);

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(std::max(_precision, 1)) << f << std::flush;
	_strFloat = oss.str() + "f";
}

void	Convert::convertDoubleToStrDouble()
{
	double	d = _store;

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(std::max(_precision, 1)) << d << std::flush;
	_strDouble = oss.str();
}


void	Convert::displayResults() const
{
	std::cout << "char: " << _strChar << std::endl;
	std::cout << "int: " << _strInt << std::endl;
	std::cout << "float: " << _strFloat << std::endl;
	std::cout << "double: " << _strDouble << std::endl;
}
