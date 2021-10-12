/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/12 23:00:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
public:
	PhoneBook();

	void	add();
	void	search() const;

private:
	Contact		_contact_lst[MAX_CONTACTS];
	int			_contacts_total;
	void		_print_table(void) const;
	static void	_print_header(void);
	static void	_print_border(int num_col);
};

#endif
