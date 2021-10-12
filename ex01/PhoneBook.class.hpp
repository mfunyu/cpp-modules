/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/12 22:54:17 by mfunyu           ###   ########.fr       */
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
	Contact		contact_lst[MAX_CONTACTS];
	int			contacts_total;
	void		print_table(void) const;
	static void	print_header(void);
	static void	print_border(int num_col);
};

#endif
