/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:16 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/06 14:15:27 by mfunyu           ###   ########.fr       */
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
		int					_precision;
		Convert();
		void	interpretCurrentType();
		void	convertStrToChar();
		void	convertStrToInt();
		void	convertStrToFloat();
		void	convertStrToDouble();
		void	convertDoubleToStrType();
		void	convertDoubleToStrChar();
		void	convertDoubleToStrInt();
		void	convertDoubleToStrFloat();
		void	convertDoubleToStrDouble();
		void	setImpossible();
		void	setNumericIndexes(int & numeric_head, int & numeric_tail);

	public:
		~Convert();
		Convert(Convert const &other);
		Convert	&operator=(Convert const &other);

		Convert(std::string const & str);

		void	solve();

		void	displayResults() const;
};

#endif /* CONVERT_HPP */
