/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:35:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/13 20:20:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

void	printPoint(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN <<\
				 "[ " <<\
				 "(" << a.getX() << ", " << a.getY() << ")" <<\
				 "(" << b.getX() << ", " << b.getY() << ")" <<\
				 "(" << c.getX() << ", " << c.getY() << ")" <<\
				 " <- "
				 "(" << point.getX() << ", " << point.getY() << ")" <<\
				 " ]" <<\
				 COLOR_RESET << std::endl;
}

void	test(Point const a, Point const b, Point const c, Point const point)
{
	printPoint(a, b, c, point);
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << c << std::endl;
	// std::cout << point << std::endl;
	std::cout << "result: " << bsp(a, b, c, point) << std::endl;
}

int		main()
{
	Point	a(0, 0);
	Point	b(0, 1);
	Point	c(1, 0);
	Point	point1(0.5, 0.5);
	Point	point2(1.5, 0.5);

	test(a, b, c, point1);
	test(a, b, c, point2);
}
