/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:30 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/21 19:22:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void	printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " ]" <<\
				 COLOR_RESET << std::endl;
}

} // namespace

/* -------------------------------------------------------------------------- */

void test(std::string arg)
{
	printSubHeader(arg);

	Convert converter(arg);
	std::cout << converter << std::endl;
}

void limits_test(double arg, int precision)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << arg << std::flush;

	std::string str = oss.str();

	test(str);
}

int main(int ac, char** av)
{
	if (ac != 2) {
		print_error("Invalid Arguments");
	}

	std::string str = av[1];

	if (str == "limits") {
		limits_test(std::numeric_limits<int>::max(), 0);
		limits_test(std::numeric_limits<int>::min(), 0);
		limits_test(std::numeric_limits<float>::min(), 150);
		limits_test(std::numeric_limits<float>::max(), 1);
		limits_test(std::numeric_limits<double>::max(), 1);
		limits_test(std::numeric_limits<double>::min(), 1050);
	} else if (str == "nan") {
		test("nan");
		test("nanf");
		test("inf");
		test("inff");
		test("-inf");
		test("-inff");
		test("+inf");
		test("+inff");
	} else {
		test(str);
	}

	return 0;
}
