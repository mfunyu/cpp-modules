/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:28:33 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/13 19:34:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::~Point()
{
}

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

Point::Point(float const x, float const y) : _x(x), _y(y) {}
