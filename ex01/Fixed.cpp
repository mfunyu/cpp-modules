/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:58:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/28 17:20:53 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_nbFractionalBit = 8;

/*
** canonical class functions
*/

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed_obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed_obj;
}

Fixed	&Fixed::operator=(const Fixed &fixed_obj)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed_obj)
	{
		_fixedPointValue = fixed_obj.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int int_value)
{
	_fixedPointValue = int_value  * (1 << _nbFractionalBit);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value)
{
	_fixedPointValue = std::roundf(float_value * (1 << _nbFractionalBit));
	std::cout << "Float constructor called" << std::endl;
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


std::ostream	&operator<<(std::ostream& os, const Fixed& fixed_obj)
{
	os << fixed_obj.toFloat();
	return os;
}
