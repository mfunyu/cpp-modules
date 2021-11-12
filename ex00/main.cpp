/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:56:29 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/12 19:57:10 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// #define OPERATOR

/* ------------------------------- formatting ------------------------------- */

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
	std::cout << std::endl;
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " ]" <<\
				 COLOR_RESET << std::endl;
}

void	printLine()
{
	std::cout << std::endl << "------------------------------" << std::endl;
}

} // namespace

/* -------------------------------------------------------------------------- */


void	subject_main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

void	testConstructor()
{
	Fixed test;

	std::cout << std::endl;

	int ret = test.getRawBits();
	std::cout << "result: test.getRawBits() = " << ret << '\n' << std::endl;

	int		n = 42;
	std::cout << " * test.setRawBits(" << n << "); *" << std::endl;
	test.setRawBits(n);
	std::cout << std::endl;

	ret = test.getRawBits();
	std::cout << "result: test.getRawBits() = " << ret << '\n' << std::endl;
}

void	testCopy()
{
	printSubHeader("Set original instance");
	Fixed original;

	std::cout << std::endl;

	int ret = original.getRawBits();
	std::cout << "result: original.getRawBits() = " << ret << '\n' << std::endl;

	int		n = 42;
	std::cout << " * original.setRawBits(" << n << "); *" << std::endl;
	original.setRawBits(n);

	/* ------------------------- */
	printLine();

	# ifdef OPERATOR
	printSubHeader("Assignment Operator=");
	Fixed copy;
	copy = original;
	# else
	printSubHeader("Copy Constructor");
	Fixed copy(original);
	# endif
	std::cout << std::endl;

	ret = copy.getRawBits();
	std::cout << "result: copy.getRawBits() = " << ret << std::endl;

	/* ------------------------- */
	printLine();
	printSubHeader("Check independency");

	ret = original.getRawBits();
	std::cout << "result: original.getRawBits() = " << ret << '\n' << std::endl;

	int		m = 100;
	std::cout << " * copy.setRawBits(" << m << "); *" << std::endl;
	copy.setRawBits(m);
	std::cout << std::endl;

	ret = copy.getRawBits();
	std::cout << "result: copy.getRawBits() = " << ret << '\n' << std::endl;
	ret = original.getRawBits();
	std::cout << "result: original.getRawBits() = " << ret << '\n' << std::endl;
}

int		main(void)
{
	printHeader("Subject Main");
	subject_main();

	printHeader("Constructor / getRawBits / setRawBits");
	testConstructor();

	printHeader("Copy Constructor / Assignment Operator = ");
	testCopy();
}
