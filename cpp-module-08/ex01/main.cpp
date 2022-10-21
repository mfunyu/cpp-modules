/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:08:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/29 14:57:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN	   "\033[36m"
#define COLOR_CYAN_T   "\033[1;36m"
#define COLOR_CYAN_D   "\033[2;36m"
#define COLOR_RESET	   "\033[0m"
#define THROWEXCEPTION -1
#define EMPTY		   -2

namespace print {
void Header(std::string content)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN_T << "------------------ " << content
			  << " ------------------" << COLOR_RESET << std::endl;
}

void SubHeader(std::string content)
{
	std::cout << COLOR_CYAN_T << "\n*** " << content << " ***" << COLOR_RESET
			  << std::endl;
}

void ExpectedValue(ssize_t expected_value)
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

void SpanDetail(Span const& sp)
{
	std::cout << COLOR_CYAN << sp << COLOR_RESET << std::endl;
}

void Help()
{
	std::cout << "usage: ./a.out [testname]\n" << std::endl;
	std::cout << "  \"testnames\"" << std::endl;
	std::cout << "\tnone\t-> run the short test on subject" << std::endl;
	std::cout << "\t\"1\"\t-> shortestSpan()" << std::endl;
	std::cout << "\t\"2\"\t-> longestSpan()" << std::endl;
	std::cout << "\t\"3\"\t-> run basic cases" << std::endl;
	std::cout << "\t\"4\"\t-> run edge cases" << std::endl;
	std::cout << "\t\"5\"\t-> run large cases" << std::endl;
}
} // namespace print

/* -------------------------------------------------------------------------- */

namespace subject {
void test(void)
{
	print::Header("subject main");
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
	print::SpanDetail(test);
	print::ExpectedValue(expected_value);

	std::cout << "shortest: ";
	try {
		std::cout << test.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void longestSpanTest(Span test, size_t expected_value = EMPTY)
{
	print::SpanDetail(test);
	print::ExpectedValue(expected_value);

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
		print::Header("shortestSpan()");

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
		print::Header("longestSpan()");

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
	print::Header("edge cases");
	{
		Span edge = Span(10);

		print::SubHeader("result over INT_MAX");
		edge.addNumber(INT_MAX);
		edge.addNumber(-42);
		shortestSpanTest(edge, static_cast<ssize_t>(INT_MAX) - -42);
		longestSpanTest(edge, static_cast<ssize_t>(INT_MAX) - -42);
	}
	{
		Span edge = Span(10);

		print::SubHeader("INT_MIN and INT_MAX");
		edge.addNumber(INT_MAX);
		edge.addNumber(INT_MIN);
		shortestSpanTest(edge, static_cast<ssize_t>(INT_MAX) - INT_MIN);
		longestSpanTest(edge, static_cast<ssize_t>(INT_MAX) - INT_MIN);
	}
	{
		Span zeros = Span(10);

		print::SubHeader("0 and 0");
		zeros.addNumber(0);
		zeros.addNumber(0);
		shortestSpanTest(zeros, 0);
		longestSpanTest(zeros, 0);
	}
}

void basicCases()
{
	print::Header("basic cases");
	{
		print::SubHeader("same values");

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
		print::SubHeader("sequenced values");

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
		print::SubHeader("random values");

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

size_t current;
size_t increment()
{
	return ++current;
}

void largeCases()
{
	print::Header("large cases");

	long			  varray_len = 10000;
	std::vector<long> vector_array(varray_len + 1);
	std::generate_n(vector_array.begin(), varray_len, increment);
	Span large = Span(varray_len + 1);

	long			  larray_len = 1000000;
	std::list<long> list_array(larray_len + 1);
	current = 0;
	std::generate_n(list_array.begin(), larray_len, increment);

	{
		print::SubHeader("classic");
		large.addNumber(vector_array.begin(), vector_array.end());

		shortestSpanTest(large, 1 - 0);
		longestSpanTest(large, varray_len - 0);
	}
	{
		print::SubHeader("even more");
		Span large = Span(larray_len + 1);
		large.addNumber(list_array.begin(), list_array.end());

		shortestSpanTest(large, 1 - 0);
		longestSpanTest(large, larray_len - 0);
	}
	{
		print::SubHeader("not enough space");
		Span large = Span(50000);
		try {
			large.addNumber(list_array.begin(), list_array.end());
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		large.addNumber(vector_array.begin(), vector_array.end());
		shortestSpanTest(large, 1 - 0);
		longestSpanTest(large, varray_len - 0);
	}
}
} // namespace spanTest

int main(int ac, char** av)
{
	try {
		std::string test = (ac > 1 ? av[1] : "");

		if (test.empty()) {
			subject::test();
		} else if (test == "1") {
			spanTest::singleShort();
		} else if (test == "2") {
			spanTest::singleLong();
		} else if (test == "3") {
			spanTest::basicCases();
		} else if (test == "4") {
			spanTest::edgeCases();
		} else if (test == "5") {
			spanTest::largeCases();
		} else if (test == "all") {
			subject::test();
			spanTest::singleShort();
			spanTest::singleLong();
			spanTest::basicCases();
			spanTest::edgeCases();
			spanTest::largeCases();
		} else {
			print::Help();
		}

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
