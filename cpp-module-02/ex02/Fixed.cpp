/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:58:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/13 19:19:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

const int	Fixed::_nbFractionalBit = 8;

/* -------------------- canonical class / basic functions ------------------- */

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed_obj)
{
	*this = fixed_obj;
}

Fixed	&Fixed::operator=(const Fixed &fixed_obj)
{
	if (this != &fixed_obj)
	{
		_fixedPointValue = fixed_obj._fixedPointValue;
	}
	return *this;
}

Fixed::Fixed(const int int_value)
{
	_fixedPointValue = int_value * (1 << _nbFractionalBit);
}

Fixed::Fixed(const float float_value)
{
	_fixedPointValue = static_cast<int>(std::roundf(float_value * (1 << _nbFractionalBit)));
}

int		Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

int		Fixed::toInt(void) const
{
	int		int_value = _fixedPointValue;
	int_value >>= _nbFractionalBit;

	if (_fixedPointValue < 0)
	{
		int		recovered_fixedpoint = int_value << _nbFractionalBit;
		if (recovered_fixedpoint != _fixedPointValue)
		{
			int_value += 1;
		}
	}
	return int_value;
}

float	Fixed::toFloat(void) const
{
	float	float_value = _fixedPointValue;
	float_value /= 1 << _nbFractionalBit;
	return float_value;
}

std::string		Fixed::toBitString(int i) const
{
	int	fixed_copy = _fixedPointValue;
	fixed_copy >>= i;

	std::string ret;
	if (i < 32 - 1) {
		ret = toBitString(++i);
	}
	if (i % 4 == 0) {
		ret += ' ';
	}
	ret += '0' + (fixed_copy & 0x1);
	return ret;
}

/* -------------------- comparison operator overloadings -------------------- */

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (_fixedPointValue > rhs._fixedPointValue);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (_fixedPointValue < rhs._fixedPointValue);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (_fixedPointValue >= rhs._fixedPointValue);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (_fixedPointValue <= rhs._fixedPointValue);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (_fixedPointValue == rhs._fixedPointValue);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (_fixedPointValue != rhs._fixedPointValue);
}

/* -------------------- arithmetic operator overloadings -------------------- */

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	ret;
	ret.setRawBits(_fixedPointValue + rhs._fixedPointValue);
	return ret;
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	ret;
	ret.setRawBits(_fixedPointValue - rhs._fixedPointValue);
	return ret;
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	long	new_raw_value = _fixedPointValue;
	new_raw_value *= rhs._fixedPointValue;
	new_raw_value /= (1 << _nbFractionalBit);

	Fixed	ret;
	ret.setRawBits(static_cast<int>(new_raw_value));
	return ret;
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	if (rhs._fixedPointValue == 0) {
		throw std::logic_error("floating point exception");
	}

	long	new_raw_value = _fixedPointValue;
	new_raw_value <<= _nbFractionalBit;
	new_raw_value /= rhs._fixedPointValue;

	Fixed	ret;
	ret.setRawBits(static_cast<int>(new_raw_value));
	return ret;
}


/* --------------- increment / decrement operator overloadings -------------- */

Fixed	&Fixed::operator++()
{
	_fixedPointValue += 1;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	prev = *this;

	_fixedPointValue += 1;
	return prev;
}

Fixed	&Fixed::operator--()
{
	_fixedPointValue -= 1;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	prev = *this;

	_fixedPointValue -= 1;
	return prev;
}

/* ------------------- static member function overloadings ------------------ */

Fixed	&Fixed::min (Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}

Fixed	&Fixed::max (Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

const Fixed		&Fixed::min (Fixed const &fixed1, Fixed const &fixed2)
{
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}

const Fixed		&Fixed::max (Fixed const &fixed1, Fixed const &fixed2)
{
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

std::ostream	&operator<<(std::ostream& os, const Fixed& fixed_obj)
{
	os << fixed_obj.toFloat();
	return os;
}
