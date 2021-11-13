/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:15:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/13 19:21:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#include <exception>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {

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
} // namespace

/* -------------------------------------------------------------------------- */

void	division(Fixed const &a, Fixed const &b)
{
	std::cout << a << " / " << b << " " << std::flush;

	Fixed	ans = a / b;
	std::cout << "= " << ans << "\t";

	float	diff = a.toFloat() / b.toFloat() - ans.toFloat() ;

	if (!diff) {
		std::cout << ": " << COLOR_GREEN << "OK" << COLOR_RESET << std::endl;
	} else {
		std::cout << ": " << COLOR_YELLOW << "DIFF" << COLOR_RESET;
		std::cout << " diff " << diff << std::endl;
	}
}

template <typename T1, typename T2>
void	test_division(T1 lhs, T2 rhs)
{
	Fixed	a(lhs);
	Fixed	b(rhs);
	division(a , b);
}

void	test_arithmatics(Fixed const &a, Fixed const &b)
{
	printSubHeader("arithmatics");
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;
}

void	test_comparisons(Fixed const &a, Fixed const &b)
{
	printSubHeader("comparisons");
	std::cout << a << " < " << b << ": " << (a < b) << std::endl;
	std::cout << a << " > " << b << ": " << (a > b) << std::endl;
	std::cout << a << " >= " << b << ": " << (a >= b) << std::endl;
	std::cout << a << " <= " << b << ": " << (a <= b) << std::endl;
	std::cout << a << " == " << b << ": " << (a == b) << std::endl;
	std::cout << a << " != " << b << ": " << (a != b) << std::endl;
}

void	test_inc_dec(Fixed &a)
{
	printSubHeader("inc / dec");
	std::cout << "a  : " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a  : " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a  : " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a  : " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a  : " << a << std::endl;
}

void	test_min_max(Fixed a, Fixed b)
{
	printSubHeader("min / max");
	std::cout << "min: " << Fixed::min(a, b) <<\
				 "	(a = " << a << " b = " << b << ")" << std::endl;
	std::cout << "max: " << Fixed::max(a, b) <<\
				 "	(a = " << a << " b = " << b << ")" << std::endl;
}

void	test_min_max_const(Fixed const a, Fixed const b)
{
	std::cout << "const min: " << Fixed::min(a, b) <<\
				 "	(a = " << a << " b = " << b << ")" << std::endl;
	std::cout << "const max: " << Fixed::max(a, b) <<\
				 "	(a = " << a << " b = " << b << ")" << std::endl;
}

void	test_all(Fixed a, Fixed b)
{
	test_arithmatics(a, b);
	test_comparisons(a, b);
	test_inc_dec(a);
	test_inc_dec(b);
	test_min_max(a, b);
	test_min_max_const(a, b);
}

void	subject_main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}

int		main(void)
{
	try
	{
		printHeader("Subject Main");
		subject_main();

		std::cout << std::setprecision(20);
		printHeader("Division");
		test_division(10, 5);
		test_division(5, 10);
		test_division(50, 10);
		test_division(52, 7);
		test_division(-42.42f, 42.42f);
		test_division(42.6f, 7.2f);
		test_division(42.6f, 7);

		printHeader("Test All");
		test_all(Fixed(10), Fixed(5));
		test_all(Fixed(20), Fixed(20));
		test_all(Fixed(0), Fixed(200));
		test_all(Fixed(-42.3f), Fixed(42.3f));
		test_all(Fixed(-10.004f), Fixed(0.8f));
		test_all(Fixed(-214748364), Fixed(2147483647));
		test_all(Fixed(570), Fixed(0.456f));
		test_all(Fixed(200), Fixed(0));

		printHeader("Zero Division");
		test_division(200, 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	};

	return 0;
}
