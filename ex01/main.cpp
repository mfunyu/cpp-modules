/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:31:07 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/23 13:30:40 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstddef>
#include <iostream>
#include <string>

/* ---------------------------------- print --------------------------------- */

#define COLOR_CYAN	"\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
template <typename T>
void printLst(T const* lst, int len)
{
	for (int i = 0; i < len; i++) {
		std::cout << "[" << i << "]: " << lst[i] << std::endl;
	}
}

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

void printHelp()
{
	std::cout << "usage: ./a.out [testname]" << '\n'
			  << '\n'
			  << "  \"testnames\"" << '\n'
			  << "\tnone\t-> run the original test" << '\n'
			  << "\t\"review\"-> run tests for review (using class Awesome)"
			  << '\n'
			  << "\t\"all\"\t-> run all tests" << std::endl;
}
} /* namespace */

/* --------------------------------- review --------------------------------- */

namespace review {
class Awesome
{
  public:
	Awesome(void) : _n(42)
	{
		return;
	}
	int get(void) const
	{
		return this->_n;
	}

  private:
	int _n;
};

std::ostream& operator<<(std::ostream& o, Awesome const& rhs)
{
	o << rhs.get();
	return o;
}

template <typename T>
void print(T const& x)
{
	std::cout << x << std::endl;
	return;
}

int review_main()
{
	printHeader("Review test");

	int		tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);
	return 0;
}
} // namespace review

/* ------------------------------ original test ----------------------------- */

namespace {
template <typename T>
void printLen(T const& x)
{
	std::size_t len = 0;
	for (; x[len]; len++) {}
	std::cout << len << std::endl;
}
template <typename T>
void increment(T& x)
{
	x += 1;
}

void original_main()
{
	{
		int len = 3;
		printHeader("const test <std::string>");
		std::string str[4] = { "aaaaa", "bbbbbbbbb", "cc" };

		printSubHeader("Array");
		printLst(str, len);

		printSubHeader("* iter<std::string>(str, len, printLen); *");
		iter<std::string>(str, len, printLen);
	}
	{
		int len = 4;
		printHeader("non const test <float>");
		float farray[5] = { 123.0f, 456.1f, 789.2f, 1000 };

		printSubHeader("Array");
		printLst(farray, len);

		printSubHeader("* iter<float>(farray, len, increment); *");
		iter<float>(farray, len, increment);
		std::cout << "result: " << std::endl;
		printLst(farray, len);
	}
}
} // namespace

int main(int ac, char** av)
{
	std::string test = (ac > 1 ? av[1] : "");

	if (test.empty()) {
		original_main();
	} else if (test == "review") {
		review::review_main();
	} else if (test == "all") {
		original_main();
		review::review_main();
	} else {
		printHelp();
	}
}
