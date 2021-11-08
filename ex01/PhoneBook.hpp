/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 14:58:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# define MAX_CONTACTS 8
# define NUM_COLS 4
# define COL_WIDTH 10

class PhoneBook
{
	private:
		Format			_format;
		Contact			_contactList[MAX_CONTACTS + 1];
		unsigned int	_contactIndex;

	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search() const;

	private:
		void	_printTable(void) const;
		void	_updateContactIndex(void);
};

#endif /* PHONEBOOK_HPP */
