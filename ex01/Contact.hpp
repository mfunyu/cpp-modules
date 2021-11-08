/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 13:33:04 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# include "Format.hpp"

class Contact
{
	private:
		bool		_isFilled;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

		Format		_format;

		static void	_print_one_line(std::string name, std::string value);

	public:
		Contact();
		~Contact();

		void	print(void) const;
		void	fillout(void);
		bool	isFilled(void) const;

		std::string const &	getFirstName(void) const;
		std::string const &	getLastName(void) const;
		std::string const &	getNickname(void) const;
};

#endif /* CONTACT_HPP */
