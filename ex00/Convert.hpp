/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:16 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/06 16:44:36 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>

class Convert
{
	private:
		std::string const	_str;
		double				_stored;
		int					_precision;

		std::string			_strChar;
		std::string			_strInt;
		std::string			_strFloat;
		std::string			_strDouble;

		static std::string	impossible;

		Convert();

		void	convertDoubleToStr_char();
		void	convertDoubleToStr_int();
		void	convertDoubleToStr_float();
		void	convertDoubleToStr_double();

		void	convertDoubleToStr_types();

		void	convertStrToChar();
		void	convertStrToDouble();

		void	setNumericIndexes(int & numeric_head, int & numeric_tail);

		bool	isNonNumericChar();

		void	setImpossible();
		void	setPseudoLiteral();
		bool	isNumeric();
		bool	isPseudoLiteral();

		void	interpretCurrentType();

	public:
		~Convert();
		Convert(Convert const &other);
		Convert	&operator=(Convert const &other);

		Convert(std::string const & str);

		void	solve();

		void	displayResults() const;
};

#endif /* CONVERT_HPP */
