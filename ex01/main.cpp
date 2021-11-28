/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:08:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/28 13:29:37 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN	 "\033[36m"
#define COLOR_CYAN_T "\033[1;36m"
#define COLOR_CYAN_D "\033[2;36m"
#define COLOR_RESET	 "\033[0m"

namespace {
void printHeader(std::string content)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN_T << "------------------ " << content
			  << " ------------------" << COLOR_RESET << std::endl;
}

void printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN_T << "\n*** " << content << " ***" << COLOR_RESET
			  << std::endl;
}

void printExpectedValue(ssize_t expected_value)
{
	if (expected_value < 0)
		return;
	std::cout << COLOR_CYAN_D << "expected: " << expected_value << COLOR_RESET
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

void shortestSpanTest(Span test, ssize_t expected_value = -1)
{
	std::cout << COLOR_CYAN << test << COLOR_RESET << std::endl;
	printExpectedValue(expected_value);

	std::cout << "shortest: ";
	try {
		std::cout << test.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void longestSpanTest(Span test, size_t expected_value = -1)
{
	std::cout << COLOR_CYAN << test << COLOR_RESET << std::endl;
	printExpectedValue(expected_value);

	std::cout << "longest : ";
	try {
		std::cout << test.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void testAll()
{
	{
		printHeader("test shortestSpan()");

		/* exceptions thrown */
		shortestSpanTest(Span(3));
		shortestSpanTest(Span(2));
		shortestSpanTest(Span(1));

		/* span returned */
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

		/* exceptions thrown */
		longestSpanTest(Span(3));
		longestSpanTest(Span(2));
		longestSpanTest(Span(1));

		/* span returned */
		Span nonEmpty = Span(3);
		nonEmpty.addNumber(42); // 42
		longestSpanTest(nonEmpty);
		nonEmpty.addNumber(0); // 42, 0
		longestSpanTest(nonEmpty);
		nonEmpty.addNumber(100); // 42, 0, 100
		longestSpanTest(nonEmpty);
	}
}
} // namespace spanTest


int main(int ac, char** av)
{
	try {
		std::string test = (ac > 1 ? av[1] : "");

		if (test.empty()) {
			subject::test();
		} else if (test == "all") {
			spanTest::testAll();
		}

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
