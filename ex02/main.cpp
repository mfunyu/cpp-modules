/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:15:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/27 00:35:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	#ifdef ADVANCED
	{
		test_all(Fixed(10), Fixed(5));
		test_all(Fixed(20), Fixed(20));
		test_all(Fixed(0), Fixed(200));
		test_all(Fixed(200), Fixed(0));
		test_all(Fixed(-42.3f), Fixed(42.3f));
		test_all(Fixed(-214748364), Fixed(2147483647));
	}
	#endif

	return 0;
}
