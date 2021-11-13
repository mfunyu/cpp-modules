/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:28:33 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/13 22:36:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::~Point() {}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	*this = other;
}

Point	&Point::operator=(const Point &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Fixed const & Fx, Fixed const & Fy) : _x(Fx), _y(Fy) {}

Fixed const &	Point::getX() const
{
	return _x;
}

Fixed const &	Point::getY() const
{
	return _y;
}

Fixed	Point::crossP(Point const & rhs)
{
	return (_x * rhs._y) - (_y * rhs._x);
}

Point	Point::operator-(Point const &rhs) const
{
	return Point(_x - rhs._x, _y - rhs._y);
}

std::ostream	&operator<<(std::ostream& os, const Point& point)
{
	os << "Point(x = " << point.getX() << ", y = " << point.getY() << ")";
	return os;
}
