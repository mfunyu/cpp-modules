/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:47 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 14:03:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_HPP
# define FORMAT_HPP

# include <string>

class Format
{
	private:
		unsigned int	_keyWidth;

	public:
		Format();
		~Format();
		Format(Format const &other);
		Format	&operator=(Format const &other);

		Format(unsigned int keyWidth);

		void	printPairLine(std::string const & key, std::string const & value, unsigned int keyWidth = 0) const;
		void	printInfoLine(std::string const & info) const;
		void	printKey(std::string const & key, unsigned int keyWidth = 0) const;
		void	printSeparator(unsigned int width, char ch) const;

		void	setKeyWidth(unsigned int keyWidth);

		std::string	promptGetInput(std::string key);
};

#endif /* FORMAT_HPP */
