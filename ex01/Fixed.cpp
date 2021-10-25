/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:58:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/25 19:07:12 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_nbFractionalBit = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
	_fixedPointValue = int_value << _nbFractionalBit;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value)
{
	_fixedPointValue = roundf(float_value * ( 1 << _nbFractionalBit));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed&	Fixed::operator =(const Fixed &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	_fixedPointValue = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return _fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
	_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
	return	_fixedPointValue / float(1 << _nbFractionalBit);
;
}

int Fixed::toInt( void ) const
{
	return _fixedPointValue >> _nbFractionalBit;
}
