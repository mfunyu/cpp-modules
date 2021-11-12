/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:22:18 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/12 22:14:06 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <limits>

/* ------------------------------- formatting ------------------------------- */

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

template <typename T>
void	printSubHeader(T content)
{
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " ]" <<\
				 COLOR_RESET << std::endl;
}

void	printWarning(std::string content)
{
	std::cout << COLOR_YELLOW << content <<\
				 COLOR_RESET << std::endl;}

void	printLine()
{
	std::cout << std::endl << "------------------------------" << std::endl;
}

} // namespace

/* -------------------------------------------------------------------------- */

void	subject_main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	printSubHeader("test operator <<");
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	printSubHeader("test toInt()");
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void	testToInt(int nb)
{
	printSubHeader<int>(nb);
	Fixed	value(nb);
	std::cout << "value = " << value << std::endl;
	int	ret = value.toInt();
	std::cout << "value.toInt() = " << ret << std::endl;
	if (ret != nb) {
		if (INT_MAX >> 8 < nb || INT_MIN >> 8 > nb) {
			printWarning("overflow detected");
		} else {
			printWarning("value differs");
		}
	}
}

void	testToFloat(float nb)
{
	printSubHeader<float>(nb);
	Fixed	value(nb);
	std::cout << "value = " << value << std::endl;
	float	ret = value.toFloat();
	std::cout << "value.toFloat() = " << ret << std::endl;
}

int		main(void)
{
	printHeader("Subject Main");
	subject_main();

	/* -------------------------- */
	std::cout.setf(std::cout.fixed);
	printLine();
	printHeader("toInt()");
	testToInt(0);
	testToInt(1);
	testToInt(-1);
	testToInt(42);
	testToInt(-42);
	testToInt(4194304);
	testToInt(-4194305);
	testToInt(8388607); // 2^23 - 1
	testToInt(-8388608); // -(2^23 - 1) - 1
	testToInt(8388608); // (2^23 - 1) + 1
	testToInt(8388609);
	testToInt(-8388609); // -(2^23 - 1)  1
	testToInt(INT_MAX); //0111 1111 | 1111 1111 | 1111 1111 | 1111 1111
	testToInt(INT_MIN); //1000 0000 | 0000 0000 | 0000 0000 | 0000 0000

	/* -------------------------- */
	printLine();
	printHeader("toFloat()");
	testToFloat(0.0);
	testToFloat(-1.1111111);
}
