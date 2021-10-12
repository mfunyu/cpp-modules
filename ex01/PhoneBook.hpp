/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/13 00:03:55 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

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
	int			_get_contacts_total(void) const;
	void		_reset_contacts_total(void);
	void		_increment_contacts_total(void);
};

#endif
