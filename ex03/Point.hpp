/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:28:25 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/13 20:01:03 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		~Point();
		Point(Point const &other);
		Point	&operator=(Point const &other);

		Point(float const x, float const y);

		Fixed const &	getX() const;
		Fixed const &	getY() const;
};


std::ostream &	operator<<(std::ostream& os, const Point& point);

#endif /* POINT_HPP */
