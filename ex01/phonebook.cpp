/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:52 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 01:36:02 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>


int	main()
{
	Contact	contact_lst[8];

	while (42)
	{
		std::string	cmd;
		std::cout << "Please enter a command: ";
		std::cin >> cmd;


		if (cmd.compare("EXIT") == 0) {
			return (0);
		} else if (cmd.compare("ADD") == 0) {
			contact_lst[0] = create();
		} else if (cmd.compare("SEARCH") == 0) {
			search(contact_lst);
		}
		std::cout << std::endl;
	}

}
