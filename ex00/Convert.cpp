/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:47:54 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/21 12:24:36 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

std::string Convert::impossible = "impossible";

Convert::Convert(std::string const& str) : _str(str), _precision(0) {}

Convert::~Convert() {}

Convert::Convert(const Convert& other) : _str(other._str)
{
	*this = other;
}

Convert& Convert::operator=(const Convert& other)
{
	if (this != &other) {
		_stored	   = other._stored;
		_precision = other._precision;
		_charStr   = other._charStr;
		_intStr	   = other._intStr;
		_floatStr  = other._floatStr;
		_doubleStr = other._doubleStr;
	}
	return *this;
}

void Convert::convertDoubleToStr_char()
{
	if (_intStr == impossible) {
		_charStr = impossible;
		return;
	}

	int i = static_cast<int>(_stored);
	if (!std::isprint(i)) {
		_charStr = "Non displayable";
		return;
	}

	_charStr = static_cast<char>(_stored);
	_charStr = "'" + _charStr + "'";
}

void Convert::convertDoubleToStr_int()
{
	if (_stored < INT_MIN || INT_MAX < _stored) {
		_intStr = impossible;
		return;
	}

	int i = static_cast<int>(_stored);

	std::ostringstream oss;
	oss << i << std::flush;
	_intStr = oss.str();
}

void Convert::convertDoubleToStr_float()
{
	if (_doubleStr == impossible) {
		_floatStr = impossible;
		return;
	}
	float f = static_cast<float>(_stored);

	int max_precision = std::max(_precision, 1);
	if (f == 0) {
		max_precision = 1;
	}

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(max_precision) << f << std::flush;
	_floatStr = oss.str() + "f";
}

void Convert::convertDoubleToStr_double()
{
	double d = _stored;

	int max_precision = std::max(_precision, 1);
	if (d == 0) {
		max_precision = 1;
	}

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(max_precision) << d << std::flush;
	_doubleStr = oss.str();
}

void Convert::convertDoubleToStr_types()
{
	if (!_doubleStr.empty()) {
		return;
	}
	convertDoubleToStr_double();
	convertDoubleToStr_float();
	convertDoubleToStr_int();
	convertDoubleToStr_char();
}

void Convert::convertStrToChar()
{
	_stored = static_cast<double>(_str.at(0));
}

void Convert::convertStrToDouble()
{
	std::string str = _str;
	if (str.at(str.length() - 1) == 'f') {
		str.erase(str.length() - 1, 1);
	}
	std::istringstream iss(str);

	iss >> _stored;
}

bool Convert::isNonNumericChar()
{
	return (_str.length() == 1 && !std::isdigit(_str.at(0))
			&& std::isprint(_str.at(0)));
}

void Convert::setImpossible()
{
	_doubleStr = impossible;
	_floatStr  = impossible;
	_intStr	   = impossible;
	_charStr   = impossible;
}

void Convert::setPseudoLiteral()
{
	_intStr	 = impossible;
	_charStr = impossible;

	if (_str.find("nan") != std::string::npos) {
		_doubleStr = "nan";
		_floatStr  = "nanf";
		return;
	}
	if (_str.find("inf") != std::string::npos) {
		if (_str.at(0) == '+' || _str.at(0) == '-') {
			_doubleStr = _str.at(0);
			_floatStr  = _str.at(0);
		}
		_doubleStr += "inf";
		_floatStr += "inff";
	}
}

void Convert::setNumericIndexes(int& numeric_head, int& numeric_tail)
{
	if (_str.at(0) == '-' || _str.at(0) == '+') {
		numeric_head += 1;
	}
	if (_str.at(numeric_tail - 1) == 'f') {
		numeric_tail -= 1;
	}
}

bool Convert::isNumeric()
{
	int numeric_head = 0;
	int numeric_tail = _str.length();
	setNumericIndexes(numeric_head, numeric_tail);

	bool fraction  = false;
	int	 zero_tail = 0;
	for (int i = numeric_head; i < numeric_tail; i++) {
		if (!fraction && _str.at(i) == '.') {
			fraction = true;
			continue;
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

bool Convert::isPseudoLiteral()
{
	std::string str = _str;
	if (str == "nan" || str == "nanf") {
		return true;
	}
	if (str.at(0) == '-' || str.at(0) == '+') {
		str.erase(0, 1);
	}
	return (str == "inf" || str == "inff");
}

void Convert::interpretCurrentType()
{
	if (_str.empty()) {
		setImpossible();
		return;
	}
	if (isPseudoLiteral()) {
		setPseudoLiteral();
		return;
	}

	if (isNonNumericChar()) {
		convertStrToChar();
		return;
	}

	if (!isNumeric()) {
		setImpossible();
		return;
	}

	convertStrToDouble();
}

void Convert::solve()
{
	interpretCurrentType();
	convertDoubleToStr_types();
}

std::string const& Convert::getCharStr() const
{
	return _charStr;
}

std::string const& Convert::getIntStr() const
{
	return _intStr;
}

std::string const& Convert::getFloatStr() const
{
	return _floatStr;
}

std::string const& Convert::getDoubleStr() const
{
	return _doubleStr;
}

std::ostream& operator<<(std::ostream& os, Convert const& value)
{
	os << "char: " << value.getCharStr() << std::endl;
	os << "int: " << value.getIntStr() << std::endl;
	os << "float: " << value.getFloatStr() << std::endl;
	os << "double: " << value.getDoubleStr();
	return os;
}
