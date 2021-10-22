/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/22 16:13:03 by mfunyu           ###   ########.fr       */
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
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search() const;

	private:
		Contact			_contact_lst[MAX_CONTACTS + 1];
		unsigned int	_contact_index;
		unsigned int	_get_contact_index(void) const;
		void			_update_contact_index(void);

		void			_print_table(void) const;
		void			_print_contents() const;
		static void		_print_one_column(std::string str);
		static void		_print_header(void);
		static void		_print_border();
};

#endif /* PHONEBOOK_HPP */
