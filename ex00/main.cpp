/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:30 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/05 22:10:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Convert.hpp"

void print_error(std::string const &err_msg)
{
	std::cerr << "Error: " << err_msg << std::endl;
	std::exit(1);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		print_error("Invalid Arguments");
	}

	Convert converter(av[1]);
	converter.solve();
	converter.displayResults();

	return 0;
}
