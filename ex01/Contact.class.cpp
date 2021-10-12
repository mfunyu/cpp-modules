/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/12 16:16:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

#define SEPARATOR ": "

static void print_one_line(std::string name, std::string value)
{
	std::cout << std::setw(15) << name << SEPARATOR << value << std::endl;
}

void	Contact::print(void) const
{
	std::cout.setf(std::ios::left);
	std::cout << "================================" << std::endl;
	print_one_line("first_name", first_name);
	print_one_line("last_name", last_name);
	print_one_line("nickname", nickname);
	print_one_line("phone_number", phone_number);
	print_one_line("darkest_secret", darkest_secret);
	std::cout << "================================" << std::endl;
	std::cout.unsetf(std::ios::left);
}

void	Contact::fillout(void)
{
	std::cout.setf(std::ios::left);
	std::cout << std::setw(20) << "Enter first name" << SEPARATOR;
	std::cin >> first_name;
	std::cout << std::setw(20) << "Enter last name" << SEPARATOR;
	std::cin >> last_name;
	std::cout << std::setw(20) << "Enter nickname" << SEPARATOR;
	std::cin >> nickname;
	std::cout << std::setw(20) << "Enter phone number" << SEPARATOR;
	std::cin >> phone_number;
	std::cout <<  std::setw(20) << "Enter darkest secret" << SEPARATOR;
	std::cin >> darkest_secret;
	std::cout.unsetf(std::ios::left);
	is_filled = true;
}

std::string	Contact::get_first_name(void) const {
	return (first_name);
}

std::string	Contact::get_last_name(void) const {
	return (last_name);
}

std::string	Contact::get_nickname(void) const {
	return (nickname);
}

bool	Contact::get_is_filled(void) const {
	return (is_filled);
}
