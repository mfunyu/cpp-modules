/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:35:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/13 22:48:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

/* ------------------------------- formatting ------------------------------- */

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void	printPoints(Point const a, Point const b, Point const c, Point const point)
{
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

void	printHeader(std::string content)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN <<\
				 "*** " << content << " ***" <<\
				 COLOR_RESET << std::endl;
}

void	printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " ]" <<\
				 COLOR_RESET << std::endl;
}
} //namespace

/* -------------------------------------------------------------------------- */

void	testCopy()
{
	{
		printSubHeader("Copy Constructor");
		Point	original(13.5, 52.1);
		Point	copy(original);
		std::cout << "original: " << original << std::endl;
		std::cout << "copy	: " << copy << std::endl;
	}
	{
		printSubHeader("Assignation Operator =");
		Point	original(13.5, 52.1);
		Point	copy(42.1, 98.0);
		std::cout << "before copy	: " << copy << std::endl;
		std::cout << "before original	: " << original << std::endl;
		copy = original;
		std::cout << "after copy	: " << copy << std::endl;
	}
}

void	test(Point const a, Point const b, Point const c, Point const point)
{
	printPoints(a, b, c, point);

	std::cout << "result: " <<\
				 (bsp(a, b, c, point) ? "true" : "false") << std::endl;
}

int		main()
{
	printHeader("On edge");
	test(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.5, 0.5));

	printHeader("At vertex");
	test(Point(0, 0), Point(0, 1), Point(1, 0), Point(0, 0));
	test(Point(1, 1), Point(0, 1), Point(1, 0), Point(0, 1));

	printHeader("Outside");
	test(Point(0, 0), Point(0, 1), Point(1, 0), Point(1.2, 0.7));

	printHeader("Inside");
	test(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.4, 0.3));

	printHeader("Copies");
	testCopy();
}
