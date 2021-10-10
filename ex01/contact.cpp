/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 01:45:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>
#include <iomanip>

#define SPACER "|"
#define SEPARATOR ": "

static void	print_single_column(std::string str, bool last)
{
	std::cout << std::setw(10);
	std::cout << str;
	if (!last) {
		std::cout << SPACER;
	} else {
		std::cout << std::endl;
	}
}

void	Contact::print_header(void)
{
	print_single_column("index", false);
	print_single_column("first_name", false);
	print_single_column("last_name", false);
	print_single_column("nickname", true);
}

void	Contact::print_table(int index)
{
	// print_single_column(index, false);
	std::cout << std::setw(10);
	std::cout << index << SPACER;
	print_single_column(first_name, false);
	print_single_column(last_name, false);
	print_single_column(nickname, true);
}

void	Contact::print()
{
	// print_single_column(index, false);
	std::cout << "first_name" << SEPARATOR << first_name << std::endl;
	std::cout << "last_name" << SEPARATOR << last_name << std::endl;
	std::cout << "nickname" << SEPARATOR << nickname << std::endl;
}


