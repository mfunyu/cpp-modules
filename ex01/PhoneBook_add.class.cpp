/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:28:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 17:03: by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>

int	PhoneBook::_get_contacts_total(void) const {
	return (_contacts_total);
}

void	PhoneBook::_reset_contacts_total(void) {
	_contacts_total = 0;
}

void	PhoneBook::_increment_contacts_total(void) {
	_contacts_total += 1;
}

void	PhoneBook::add() {
	std::cout << "-------" << std::endl;
	std::cout << "Input a new contact’s information" << std::endl;

	if (_get_contacts_total() == MAX_CONTACTS)
		_reset_contacts_total();
	_contact_lst[_get_contacts_total()].fillout();
	_increment_contacts_total();
}
