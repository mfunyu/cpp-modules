/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:08:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/28 20:54:25 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN	   "\033[36m"
#define COLOR_CYAN_T   "\033[1;36m"
#define COLOR_CYAN_D   "\033[2;36m"
#define COLOR_RESET	   "\033[0m"
#define THROWEXCEPTION -1
#define EMPTY		   -2

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
	if (expected_value < 0 && expected_value != THROWEXCEPTION)
		return;
	std::cout << COLOR_CYAN_D << "expected: ";
	if (expected_value == THROWEXCEPTION) {
		std::cout << "throw exception" << COLOR_RESET << std::endl;
	} else {
		std::cout << expected_value << COLOR_RESET << std::endl;
	}
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

void shortestSpanTest(Span test, ssize_t expected_value = EMPTY)
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

void longestSpanTest(Span test, size_t expected_value = EMPTY)
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

namespace spanTest {
void singleShort()
{
	{
		printHeader("shortestSpan()");

		/* exceptions thrown */
		shortestSpanTest(Span(3), THROWEXCEPTION);
		shortestSpanTest(Span(2), THROWEXCEPTION);
		shortestSpanTest(Span(1), THROWEXCEPTION);

		/* span returned */
		Span nonEmpty = Span(3);
		nonEmpty.addNumber(42); // 42
		shortestSpanTest(nonEmpty, THROWEXCEPTION);
		nonEmpty.addNumber(12); // 42, 12
		shortestSpanTest(nonEmpty, 42 - 12);
		nonEmpty.addNumber(1); // 42, 12 ,1
		shortestSpanTest(nonEmpty, 12 - 1);
	}
}

void singleLong()
{
	{
		printHeader("longestSpan()");

		/* exceptions thrown */
		longestSpanTest(Span(3), THROWEXCEPTION);
		longestSpanTest(Span(2), THROWEXCEPTION);
		longestSpanTest(Span(1), THROWEXCEPTION);

		/* span returned */
		Span nonEmpty = Span(3);
		nonEmpty.addNumber(42); // 42
		longestSpanTest(nonEmpty, THROWEXCEPTION);
		nonEmpty.addNumber(0); // 42, 0
		longestSpanTest(nonEmpty, 42);
		nonEmpty.addNumber(100); // 42, 0, 100
		longestSpanTest(nonEmpty, 100);
	}
}

void edgeCases()
{
	printHeader("edge cases");
	{
		Span edge = Span(10);

		printSubHeader("result over INT_MAX");
		edge.addNumber(INT_MAX);
		edge.addNumber(-42);
		shortestSpanTest(edge, static_cast<ssize_t>(INT_MAX) - -42);
		longestSpanTest(edge, static_cast<ssize_t>(INT_MAX) - -42);
	}
	{
		Span edge = Span(10);

		printSubHeader("INT_MIN and INT_MAX");
		edge.addNumber(INT_MAX);
		edge.addNumber(INT_MIN);
		shortestSpanTest(edge, static_cast<ssize_t>(INT_MAX) - INT_MIN);
		longestSpanTest(edge, static_cast<ssize_t>(INT_MAX) - INT_MIN);
	}
	{
		Span zeros = Span(10);

		printSubHeader("0 and 0");
		zeros.addNumber(0);
		zeros.addNumber(0);
		shortestSpanTest(zeros, 0);
		longestSpanTest(zeros, 0);
	}
}

void basicCases()
{
	printHeader("basic cases");
	{
		printSubHeader("same values");

		Span zeros = Span(10);
		zeros.addNumber(0);
		zeros.addNumber(0);
		zeros.addNumber(0);
		zeros.addNumber(0);
		zeros.addNumber(0);
		shortestSpanTest(zeros, 0);
		longestSpanTest(zeros, 0);

		Span forty_twos = Span(10);
		forty_twos.addNumber(42);
		forty_twos.addNumber(42);
		forty_twos.addNumber(42);
		forty_twos.addNumber(42);
		forty_twos.addNumber(42);
		shortestSpanTest(forty_twos, 0);
		longestSpanTest(forty_twos, 0);
	}
	{
		printSubHeader("sequenced values");

		Span minus = Span(10);
		minus.addNumber(-40);
		minus.addNumber(-41);
		minus.addNumber(-42);
		minus.addNumber(-43);
		minus.addNumber(-44);
		shortestSpanTest(minus, -40 - -41);
		longestSpanTest(minus, -40 - -44);

		Span pluses = Span(10);
		pluses.addNumber(120);
		pluses.addNumber(121);
		pluses.addNumber(122);
		pluses.addNumber(123);
		pluses.addNumber(124);
		pluses.addNumber(125);
		shortestSpanTest(pluses, 121 - 120);
		longestSpanTest(pluses, 125 - 120);
	}
	{
		printSubHeader("random values");

		Span minus = Span(10);
		minus.addNumber(-1);
		minus.addNumber(98);
		minus.addNumber(76);
		minus.addNumber(24);
		minus.addNumber(-52);
		shortestSpanTest(minus, 98 - 76);
		longestSpanTest(minus, 98 - -52);

		Span pluses = Span(10);
		pluses.addNumber(7);
		pluses.addNumber(1000005);
		pluses.addNumber(-5);
		pluses.addNumber(INT_MIN + 1);
		shortestSpanTest(pluses, 7 - -5);
		longestSpanTest(pluses, static_cast<ssize_t>(1000005) - (INT_MIN + 1));
	}
}
} // namespace spanTest

int main(int ac, char** av)
{
	try {
		std::string test = (ac > 1 ? av[1] : "");

		if (test.empty()) {
			subject::test();
		} else if (test == "short") {
			spanTest::singleShort();
		} else if (test == "long") {
			spanTest::singleLong();
		} else if (test == "1") {
			spanTest::basicCases();
		} else if (test == "2") {
			spanTest::edgeCases();
		} else if (test == "all") {
			spanTest::singleShort();
			spanTest::singleLong();
			spanTest::basicCases();
			spanTest::edgeCases();
		}

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
