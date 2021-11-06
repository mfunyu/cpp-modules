/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:47:54 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/06 16:53:56 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <climits>
#include <limits>
#include "Convert.hpp"

std::string	Convert::impossible = "impossible";

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

void	Convert::convertDoubleToStr_char()
{
	if (_strInt == impossible) {
		_strChar = impossible;
		return ;
	}

	int		i = static_cast<int>(_stored);
	if (!std::isprint(i)) {
		_strChar = "Non displayable";
		return ;
	}

	_strChar = static_cast<char>(_stored);
	_strChar = "'" + _strChar + "'";
}

void	Convert::convertDoubleToStr_int()
{
	if (_stored < INT_MIN || INT_MAX < _stored) {
		_strInt = impossible;
		return ;
	}

	int		i = static_cast<int>(_stored);

	std::ostringstream oss;
	oss << i << std::flush;
	_strInt = oss.str();
}

void	Convert::convertDoubleToStr_float()
{
	if (_strDouble == impossible) {
		_strFloat = impossible;
		return ;
	}
	float	f = static_cast<float>(_stored);

	int		max_precision = std::max(_precision, 1);
	if (f == 0) {
		max_precision = 1;
	}

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(max_precision) << f << std::flush;
	_strFloat = oss.str() + "f";
}

void	Convert::convertDoubleToStr_double()
{
	double	d = _stored;

	int		max_precision = std::max(_precision, 1);
	if (d == 0) {
		max_precision = 1;
	}

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(max_precision) << d << std::flush;
	_strDouble = oss.str();
}


void	Convert::convertDoubleToStr_types()
{
	if (!_strDouble.empty()) {
		return ;
	}
	convertDoubleToStr_double();
	convertDoubleToStr_float();
	convertDoubleToStr_int();
	convertDoubleToStr_char();
}


void	Convert::convertStrToChar()
{
	std::cout << "CHAR" << std::endl;
	_stored = static_cast<double>(_str.at(0));
}

void	Convert::convertStrToDouble()
{
	std::cout << "DOUBLE" << std::endl;
	std::string		str = _str;
	if (str.at(str.length() - 1) == 'f') {
		str.erase(str.length() - 1, 1);
	}
	std::istringstream iss(str);

	iss >> _stored;
}

bool	Convert::isNonNumericChar()
{
	return ( _str.length() == 1
			&& !std::isdigit(_str.at(0))
			&& std::isprint(_str.at(0)) );
}

void	Convert::setImpossible()
{
	_strDouble = impossible;
	_strFloat = impossible;
	_strInt = impossible;
	_strChar = impossible;
}

void	Convert::setPseudoLiteral()
{
	_strInt = impossible;
	_strChar = impossible;

	if (_str.find("nan") != std::string::npos) {
		_strDouble = "nan";
		_strFloat = "nanf";
		return ;
	}
	if (_str.find("inf") != std::string::npos) {
		if (_str.at(0) == '+' || _str.at(0) == '-') {
			_strDouble = _str.at(0);
			_strFloat = _str.at(0);
		}
		_strDouble += "inf";
		_strFloat += "inff";
	}
}

void	Convert::setNumericIndexes(int & numeric_head, int & numeric_tail)
{
	if (_str.at(0) == '-' || _str.at(0) == '+') {
		numeric_head += 1;
	}
	if (_str.at(numeric_tail - 1) == 'f') {
		numeric_tail -= 1;
	}
}

bool	Convert::isNumeric()
{
	int		numeric_head = 0;
	int		numeric_tail = _str.length();
	setNumericIndexes(numeric_head, numeric_tail);

	bool	fraction = false;
	int		zero_tail = 0;
	for (int i = numeric_head; i < numeric_tail; i++) {
		if (!fraction && _str.at(i) == '.') {
			fraction = true;
			continue ;
		}
		if (!std::isdigit(_str.at(i))) {
			return false;
		}
		if (fraction) {
			_precision += 1;
			zero_tail = (_str.at(i) == '0' ? ++zero_tail : 0);
		}
	}
	_precision -= zero_tail;
	return true;
}

bool	Convert::isPseudoLiteral()
{
	std::string		str = _str;
	if (str == "nan" || str == "nanf") {
		return true;
	}
	if (str.at(0) == '-' || str.at(0) == '+') {
		str.erase(0, 1);
	}
	return (str == "inf" || str == "inff");
}

void	Convert::interpretCurrentType()
{
	if (_str.empty()) {
		setImpossible();
		return ;
	}
	if (isPseudoLiteral()) {
		setPseudoLiteral();
		return ;
	}

	if (isNonNumericChar()) {
		convertStrToChar();
		return ;
	}

	if (!isNumeric()) {
		setImpossible();
		return ;
	}

	convertStrToDouble();
}

void	Convert::solve()
{
	interpretCurrentType();
	convertDoubleToStr_types();
}

void	Convert::displayResults() const
{
	std::cout << "char: " << _strChar << std::endl;
	std::cout << "int: " << _strInt << std::endl;
	std::cout << "float: " << _strFloat << std::endl;
	std::cout << "double: " << _strDouble << std::endl;
}
