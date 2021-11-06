/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:45:38 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/06 20:45:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
	private:
		std::string		_content;

	public:
		Data();
		~Data();
		Data(Data const &other);
		Data	&operator=(Data const &other);

		Data(std::string const & content);

		std::string const&	getContent();
};

#endif /* DATA_HPP */
