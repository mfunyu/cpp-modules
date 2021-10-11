/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 20:42:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
private:
	/* data */
public:
	Contact	contact_lst[MAX_CONTACTS];
	int		contacts_total;

	PhoneBook() {
		contacts_total = 0;
	};

	void	add();
	void	search();

private:
	void	print_header(void);
	void	print_table(void);
};


// PhoneBook::PhoneBook()
// {
// 	contacts_total = 0;
// }

#endif
