/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:08:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/26 00:06:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN	"\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void printHeader(std::string content)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN << "*** " << content << " ***" << COLOR_RESET
			  << std::endl;
}

void printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN << "[ " << content << " ]" << COLOR_RESET
			  << std::endl;
}
} // namespace

/* -------------------------------------------------------------------------- */

namespace subject {
void test(void)
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
} // namespace subject

void exception_tests()
{
	printHeader("Exception Tests");
	try {
		std::cout << tooShort.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	tooShort.addNumber(21);
	try {
		printSubHeader("size = 1");
		std::cout << tooShort.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	tooShort.addNumber(42);
	try {
		printSubHeader("size = 2");
		std::cout << tooShort.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	tooShort.addNumber(-42);
	try {
		printSubHeader("size = 3");
		std::cout << tooShort.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(int ac, char** av)
{
	try {
	std::string test = (ac > 1 ? av[1] : "");

	if (test.empty()) {
			subject::test();
		} else if (test == "all") {
			exception_tests();
		}

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
