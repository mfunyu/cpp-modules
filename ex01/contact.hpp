/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:12:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 01:42:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
public:
	Contact()
	{

	}
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	int			phone_number;
	std::string	darkest_secret;

	void	print();
	void	print_table(int index);
	void	print_header(void);
};

#endif
