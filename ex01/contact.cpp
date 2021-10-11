/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 21:56:10 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>
#include <iomanip>

#define SEPARATOR ": "

static void print_one_line(std::string name, std::string value)
{
	std::cout << name << SEPARATOR << value << std::endl;
}

void	Contact::print(void)
{
	std::cout << "=============" << std::endl;
	print_one_line("first_name", first_name);
	print_one_line("last_name", last_name);
	print_one_line("nickname", nickname);
	print_one_line("phone_number", phone_number);
	print_one_line("darkest_secret", darkest_secret);
	std::cout << "=============" << std::endl;
}

void	Contact::fillout(void)
{
	std::cout << "Enter first name: ";
	std::cin >> first_name;
	std::cout << "Enter last name: ";
	std::cin >> last_name;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	std::cout << "Enter phone number: ";
	std::cin >> phone_number;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkest_secret;
	is_filled = true;
}

