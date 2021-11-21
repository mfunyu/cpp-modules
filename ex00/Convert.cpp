/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:47:54 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/21 19:16:48 by mfunyu           ###   ########.fr       */
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

void Convert::solve()
{
	if (_str.empty()) {
		setImpossible();
		return;
	}
	if (isPseudoLiteral(_str)) {
		setPseudoLiteral();
		return;
	}

	if (!isNumeric(_str) && !isNonNumericChar(_str)) {
		setImpossible();
		return;
	}

	storeStrAsDouble();
	
	convertDoubleToDoubleStr();
	convertDoubleToFloatStr();
	convertDoubleToIntStr();
	convertDoubleToCharStr();
}

void Convert::storeStrAsDouble()
{
	if (isNonNumericChar(_str)) {
		_stored = static_cast<double>(_str.at(0));
		return;
	}
	std::string strcopy = _str;
	if (strcopy.at(strcopy.length() - 1) == 'f') {
		strcopy.erase(strcopy.length() - 1, 1);
	}
	std::istringstream iss(strcopy);

	iss >> _stored;
}

void Convert::convertDoubleToCharStr()
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

void Convert::convertDoubleToIntStr()
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

void Convert::convertDoubleToFloatStr()
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

void Convert::convertDoubleToDoubleStr()
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

bool Convert::isPseudoLiteral(std::string s)
{
	if (s == "nan" || s == "nanf") {
		return true;
	}
	if (s.at(0) == '-' || s.at(0) == '+') {
		s.erase(0, 1);
	}
	return (s == "inf" || s == "inff");
}

bool Convert::isNonNumericChar(std::string const & s)
{
	return (s.length() == 1 && !std::isdigit(s.at(0))
			&& std::isprint(s.at(0)));
}

bool Convert::isNumeric(std::string const & s)
{
	int head = 0;

	if (s.at(0) == '-' || s.at(0) == '+') {
		head += 1;
	}
	if (s.find('.', 0) != s.rfind('.', std::string::npos)) {
		return false;
	}
	int tail = s.length();
	for (int i = head; i < tail; i++) {
		if (s.at(i) != '.' && !std::isdigit(s.at(i))) {
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, Convert const& value)
{
	os << "char: " << value.getCharStr() << std::endl;
	os << "int: " << value.getIntStr() << std::endl;
	os << "float: " << value.getFloatStr() << std::endl;
	os << "double: " << value.getDoubleStr();
	return os;
}
