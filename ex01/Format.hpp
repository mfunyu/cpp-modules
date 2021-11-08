/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:47 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 13:32:15 by mfunyu           ###   ########.fr       */
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

		void	printPairLine(std::string key, std::string value, unsigned int keyWidth) const;
		void	printKey(std::string key, unsigned int keyWidth) const;
		void	printSeparator(unsigned int width, char ch) const;

		void	setKeyWidth(unsigned int keyWidth);
};

#endif /* FORMAT_HPP */
