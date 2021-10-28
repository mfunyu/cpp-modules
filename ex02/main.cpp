/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:15:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/28 17:34:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

void	division(Fixed const &a, Fixed const &b)
{
	std::cout << std::setprecision(20) << a << " / " << b << " " << std::flush;

	Fixed	ans = a / b;
	std::cout << "= " << ans << "\t";

	float	diff = a.toFloat() / b.toFloat() - ans.toFloat() ;

	if (!diff) {
		std::cout << ": \033[32mOK\033[m" << std::endl;
	} else {
		std::cout << ": \033[33mDIFF\033[m";
		std::cout << " diff " << diff << std::endl;
	}
}

void	test_division(int lhs, int rhs)
{
	Fixed	a(lhs);
	Fixed	b(rhs);
	division(a , b);
}

void	test_division(float lhs, int rhs)
{
	Fixed	a(lhs);
	Fixed	b(rhs);
	division(a , b);
}

void	test_division(float lhs, float rhs)
{
	Fixed	a(lhs);
	Fixed	b(rhs);
	division(a , b);
}

void	test_division(int lhs, float rhs)
{
	Fixed	a(lhs);
	Fixed	b(rhs);
	division(a , b);
}

void	test_arithmatics(Fixed const &a, Fixed const &b)
{
	std::cout << "====== arithmatics ========" << std::endl;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;
}

void	test_comparisons(Fixed const &a, Fixed const &b)
{
	std::cout << "====== comparisons ========" << std::endl;
	std::cout << a << " < " << b << ": " << (a < b) << std::endl;
	std::cout << a << " > " << b << ": " << (a > b) << std::endl;
	std::cout << a << " >= " << b << ": " << (a >= b) << std::endl;
	std::cout << a << " <= " << b << ": " << (a <= b) << std::endl;
	std::cout << a << " == " << b << ": " << (a == b) << std::endl;
	std::cout << a << " != " << b << ": " << (a != b) << std::endl;
}

void	test_inc_dec(Fixed &a)
{
	std::cout << "====== inc / dec ========" << std::endl;
	std::cout << std::setprecision(20) << "a  : " << a << std::endl;
	std::cout << std::setprecision(20) << "++a: " << ++a << std::endl;
	std::cout << std::setprecision(20) << "a  : " << a << std::endl;
	std::cout << std::setprecision(20) << "a++: " << a++ << std::endl;
	std::cout << std::setprecision(20) << "a  : " << a << std::endl;
	std::cout << std::setprecision(20) << "--a: " << --a << std::endl;
	std::cout << std::setprecision(20) << "a  : " << a << std::endl;
	std::cout << std::setprecision(20) << "a--: " << a-- << std::endl;
	std::cout << std::setprecision(20) << "a  : " << a << std::endl;
}

void	test_min_max(Fixed a, Fixed b)
{
	std::cout << "====== min / max ========" << std::endl;
	std::cout << "min " << Fixed::min(a, b) << "	(a = " << a << " b = " << b << std::endl;
	std::cout << "max " << Fixed::max(a, b) << "	(a = " << a << " b = " << b << std::endl;
}

void	test_min_max_const(Fixed const a, Fixed const b)
{
	std::cout << "const min " << Fixed::min(a, b) << "	(a = " << a << " b = " << b << std::endl;
	std::cout << "const max " << Fixed::max(a, b) << "	(a = " << a << " b = " << b << std::endl;
}

void	test_all(Fixed a, Fixed b)
{
	test_arithmatics(a, b);
	test_comparisons(a, b);
	test_inc_dec(a);
	test_inc_dec(b);
	test_min_max(a, b);
	test_min_max_const(a, b);
	std::cout << std::endl;
}

int		main(void)
{
	#ifdef TEST
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	#else
	try
	{
		test_division(10, 5);
		test_division(5, 10);
		test_division(50, 10);
		test_division(52, 7);
		test_division(-42.42f, 42.42f);
		test_division(42.6f, 7.2f);
		test_division(42.6f, 7);
		test_division(200, 0);

		/*
		test_all(Fixed(10), Fixed(5));
		test_all(Fixed(20), Fixed(20));
		test_all(Fixed(0), Fixed(200));
		test_all(Fixed(-42.3f), Fixed(42.3f));
		test_all(Fixed(-214748364), Fixed(2147483647));
		test_all(Fixed(570), Fixed(0.456f));
		test_all(Fixed(200), Fixed(0));
		*/
	}
	catch (char const* error_msg)
	{
		std::cout << error_msg << std::endl;
	};
	#endif

	return 0;
}
