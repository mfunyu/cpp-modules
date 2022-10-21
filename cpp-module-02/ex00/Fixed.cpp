/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:58:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/12 15:12:48 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

const int	Fixed::_nbFractionalBit = 8;

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
		_fixedPointValue = fixed_obj._fixedPointValue;
	}
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	_fixedPointValue = raw;
}

