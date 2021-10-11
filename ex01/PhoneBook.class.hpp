/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/12 00:15:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

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
		return ;
	};

	void	add();
	void	search();

private:
	void	print_table(void);
	static void	print_header(void);
};


// PhoneBook::PhoneBook()
// {
// 	contacts_total = 0;
// }

#endif
