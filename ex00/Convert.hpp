/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:16 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 19:57:27 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>

class Convert
{
	private:
		std::string const	_str;
		Convert();

	public:
		~Convert();
		Convert(Convert const &other);
		Convert	&operator=(Convert const &other);

		Convert(std::string const & str);

		void	displayResults() const;
};

#endif /* CONVERT_HPP */
