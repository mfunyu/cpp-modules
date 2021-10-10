/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:52 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 01:41:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

void	search(Contact *contact_lst) {
	contact_lst[0].print_header();
	for (int i = 0; i < 8; i++) {
		contact_lst[i].print_table(i);
	}

	int	index;
	std::cout << "Enter index of the desired entry: ";
	std::cin >> index;

	contact_lst[index].print();
}
