/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:31:07 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/22 14:42:55 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstddef>

/* ---------------------------------- print --------------------------------- */

#define COLOR_CYAN	"\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void printLst(std::string const* lst)
{
	for (int i = 0; !lst[i].empty(); i++) {
		std::cout << "[" << i << "]: " << lst[i] << std::endl;
	}
}

void print(std::string testName)
{
	std::cout << COLOR_CYAN << testName << COLOR_RESET << std::endl;
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

void original_main()
{
	std::string str[4] = { "aaaaa", "bbbbbbbbb", "cc" };
	print("[ Before ]");
	printLst(str);
	print("** Call func **");
	iter<std::string>(str, 3, printLen);
	print("[ After ]");
	printLst(str);
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
