/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:08:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/27 14:10:25 by mfunyu           ###   ########.fr       */
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

/*
void printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN << "[ " << content << " ]" << COLOR_RESET
			  << std::endl;
}
*/

void printSize(Span const& test)
{
	std::cout << COLOR_CYAN << "[ size = " << test.getSize() << ", "
			  << "maxsize = " << test.getMaxSize() << " ]" << COLOR_RESET
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

void shortestSpanTest(Span test)
{
	try {
		printSize(test);
		std::cout << test.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void longestSpanTest(Span test)
{
	try {
		printSize(test);
		std::cout << test.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void exception_tests()
{
	{
		printHeader("test shortestSpan()");

		shortestSpanTest(Span(3));
		shortestSpanTest(Span(2));
		shortestSpanTest(Span(1));

		Span nonEmpty = Span(3);
		nonEmpty.addNumber(42); // 42
		shortestSpanTest(nonEmpty);
		nonEmpty.addNumber(12); // 42, 12
		shortestSpanTest(nonEmpty);
		nonEmpty.addNumber(1); // 42, 12 ,1
		shortestSpanTest(nonEmpty);
	}
	{
		printHeader("test longestSpan()");

		longestSpanTest(Span(3));
		longestSpanTest(Span(2));
		longestSpanTest(Span(1));

		Span nonEmpty = Span(3);
		nonEmpty.addNumber(42); // 42
		longestSpanTest(nonEmpty);
		nonEmpty.addNumber(12); // 42, 0
		longestSpanTest(nonEmpty);
		nonEmpty.addNumber(1); // 42, 0 ,1
		longestSpanTest(nonEmpty);
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
