/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:30 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/06 13:05:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "Convert.hpp"

void	print_error(std::string const &err_msg)
{
	std::cerr << "Error: " << err_msg << std::endl;
	std::exit(1);
}

void	test(std::string arg)
{
	Convert converter(arg);
	converter.solve();
	converter.displayResults();
}

void	test(double arg, int precision)
{
	std::cout << std::endl;

	std::ostringstream	oss;
	oss << std::fixed << std::setprecision(precision) << arg << std::flush;

	std::string		str = oss.str();
	std::cout << "---- " << str << " ----" << std::endl;

	Convert converter(str);
	converter.solve();
	converter.displayResults();
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		print_error("Invalid Arguments");
	}

	test(av[1]);

	#ifdef LIMIT
	test(std::numeric_limits<int>::max(), 0);
	test(std::numeric_limits<int>::min(), 0);
	test(std::numeric_limits<float>::max(), 1);
	test(std::numeric_limits<float>::min(), 150);
	test(std::numeric_limits<double>::max(), 1);
	test(std::numeric_limits<double>::min(), 1050);
	#endif

	return 0;
}
