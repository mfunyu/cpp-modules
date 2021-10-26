/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:58:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/26 00:16:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_nbFractionalBit = 8;

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int int_value)
{
	_fixedPointValue = int_value << _nbFractionalBit;
}

Fixed::Fixed(const float float_value)
{
	_fixedPointValue = roundf(float_value * ( 1 << _nbFractionalBit));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed_obj)
{
	//if not the same ?
	*this = fixed_obj;
}

Fixed	&Fixed::operator=(const Fixed &fixed_obj)
{
	_fixedPointValue = fixed_obj.getRawBits();
	return *this;
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

Fixed	Fixed::operator+(Fixed const &rhs)
{
	Fixed	ret;
	ret.setRawBits(_fixedPointValue + rhs._fixedPointValue);
	return ret;
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	long long	tmp = _fixedPointValue;
	long long	tmp2 = rhs._fixedPointValue;
	long long	new_fixed = tmp * tmp2 >> _nbFractionalBit;

	Fixed	ret;
	ret.setRawBits(new_fixed);

	return ret;
}


Fixed	&Fixed::operator++()
{
	_fixedPointValue += 1;
	return *this;
}

Fixed	Fixed::operator++(int i)
{
	Fixed	prev = *this;

	(void)i;
	_fixedPointValue += 1;
	return prev;
}

const Fixed		&Fixed::max (Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1 >= fixed2)
		return fixed1;
	return fixed2;
}
