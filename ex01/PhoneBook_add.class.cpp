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

void	PhoneBook::add() {
	std::cout << "-------" << std::endl;
	std::cout << "Input a new contact’s information" << std::endl;
	if (_contacts_total == MAX_CONTACTS)
		_contacts_total = 0;
	_contact_lst[_contacts_total].fillout();
	_contacts_total += 1;
}
