/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:47:54 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/05 22:17:30 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Convert.hpp"

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

Convert::Convert(std::string const & str) : _str(str)
{
}

void	Convert::interpretCurrentType()
{
	if (_str.length() == 1
			&& !std::isdigit(_str.at(0)) && std::isprint(_str.at(0))) {
		convertStrToChar();
	}

	int		strlen = _str.length();
	if (_str.at(strlen - 1) == 'f') {
		strlen -= 1;
	}

	int		point = 0;
	for (int i = 0; i < strlen; i++) {
		if (point == 0 && _str.at(i) == '.') {
			point = 1;
			continue ;
		}
		if (!std::isdigit(_str.at(i))) {
			return ;
		}
	}
	convertStrToDouble();
}

void	Convert::convertStrToChar()
{
	std::cout << "CHAR" << std::endl;
	std::istringstream iss(_str);

	iss >> _char;
	_store = static_cast<double>(_char);
}

void	Convert::convertStrToInt()
{
	std::cout << "INT" << std::endl;
	std::istringstream iss(_str);

	iss >> _int;
	_store = static_cast<double>(_int);
}

void	Convert::convertStrToFloat()
{
	std::cout << "FLOAT" << std::endl;
	std::string		str_no_f = _str;
	str_no_f.pop_back();
	std::istringstream iss(str_no_f);

	iss >> _float;
	_store = static_cast<double>(_float);
}

void	Convert::convertStrToDouble()
{
	std::cout << "DOUBLE" << std::endl;
	std::istringstream iss(_str);

	iss >> _double;
	_store = _double;
}


void	Convert::solve()
{
	interpretCurrentType();
	convertDoubleToStrChar();
	convertDoubleToStrInt();
	convertDoubleToStrFloat();
	convertDoubleToStrDouble();
}

void	Convert::convertDoubleToStrChar()
{
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
	int		i = static_cast<int>(_store);

	std::ostringstream oss;
	oss << i << std::flush;
	_strInt = oss.str();
}

void	Convert::convertDoubleToStrFloat()
{
	float	f = static_cast<float>(_store);

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << f << std::flush;
	_strFloat = oss.str() + "f";
}

void	Convert::convertDoubleToStrDouble()
{
	double	d = _store;

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << d << std::flush;
	_strDouble = oss.str();
}


void	Convert::displayResults() const
{
	std::cout << "char: " << _strChar << std::endl;
	std::cout << "int: " << _strInt << std::endl;
	std::cout << "float: " << _strFloat << std::endl;
	std::cout << "double: " << _strDouble << std::endl;
}
