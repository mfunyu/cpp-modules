/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:16 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/05 17:01:35 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>

class Convert
{
	private:
		std::string const	_str;
		double				_store;
		char				_char;
		int					_int;
		float				_float;
		double				_double;
		std::string			_strChar;
		std::string			_strInt;
		std::string			_strFloat;
		std::string			_strDouble;
		Convert();
		void	interpretCurrentType();
		void	convertStrToChar();
		void	convertStrToInt();
		void	convertStrToFloat();
		void	convertStrToDouble();
		void	convertDoubleToStrChar();
		void	convertDoubleToStrInt();
		void	convertDoubleToStrFloat();
		void	convertDoubleToStrDouble();

	public:
		~Convert();
		Convert(Convert const &other);
		Convert	&operator=(Convert const &other);

		Convert(std::string const & str);

		void	solve();

		void	displayResults() const;
};

#endif /* CONVERT_HPP */
