/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:56:29 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/12 15:17:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/* -------------------------------------------------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {

void	printTestName(std::string name)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN <<\
				 "*** " << name << " ***" <<\
				 COLOR_RESET << std::endl;
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

int		main(void)
{
	printTestName("Subject Main");
	subject_main();

	printTestName("Constructor / getRawBits / setRawBits");
	testConstructor();
}
