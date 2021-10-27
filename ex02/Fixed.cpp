/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:58:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/27 23:09:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_nbFractionalBit = 8;

/*
** canonical class functions
*/

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
		_fixedPointValue = fixed_obj.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int int_value)
{
	_fixedPointValue = int_value << _nbFractionalBit;
}

Fixed::Fixed(const float float_value)
{
	_fixedPointValue = roundf(float_value * ( 1 << _nbFractionalBit));
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
	return _fixedPointValue >> _nbFractionalBit;
}

float	Fixed::toFloat(void) const
{
	return	_fixedPointValue / float(1 << _nbFractionalBit);
}

/*
** comparison operator overloadings
*/

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

/*
**  arithmetic operator overloadings
*/

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
	int64_t	lhs_value = _fixedPointValue;
	int64_t	mul_value = lhs_value * rhs._fixedPointValue;

	Fixed	ret;
	ret.setRawBits(mul_value >> _nbFractionalBit);

	return ret;
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	if (rhs._fixedPointValue == 0)
		throw "floating point exception";

	int64_t	lhs_value = _fixedPointValue;
	int64_t	mul_value = lhs_value / rhs._fixedPointValue;

	Fixed	ret;
	ret.setRawBits(mul_value << _nbFractionalBit);

	return ret;
}


/*
** increment / decrement operator overloadings
*/

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

/*
** static member function overloadings
*/

Fixed		&Fixed::min (Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 <= fixed2)
		return fixed1;
	return fixed2;
}

const Fixed		&Fixed::min (Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1 <= fixed2)
		return fixed1;
	return fixed2;
}

Fixed		&Fixed::max (Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return fixed1;
	return fixed2;
}

const Fixed		&Fixed::max (Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1 >= fixed2)
		return fixed1;
	return fixed2;
}


std::ostream	&operator<<(std::ostream& os, const Fixed& fixed_obj)
{
	os << fixed_obj.toFloat();
	return os;
}
