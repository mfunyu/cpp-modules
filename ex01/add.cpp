/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:52 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 01:36:45 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

Contact	create(void) {
	Contact new_contact;

	std::cout << "Enter first name: ";
	std::cin >> new_contact.first_name;
	std::cout << "Enter last name: ";
	std::cin >> new_contact.last_name;
	std::cout << "Enter nickname: ";
	std::cin >> new_contact.nickname;
	std::cout << "Enter phone number: ";
	std::cin >> new_contact.phone_number;
	std::cout << "Enter darkest secret: ";
	std::cin >> new_contact.darkest_secret;
	return (new_contact);
}

void	add() {
	std::cout << "Input a new contact’s information" << std::endl;
	create();
}
