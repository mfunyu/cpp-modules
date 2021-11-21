/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:16 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/21 13:22:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

class Convert
{
	std::string const _str;
	double			  _stored;
	int				  _precision;

	std::string _charStr;
	std::string _intStr;
	std::string _floatStr;
	std::string _doubleStr;

  public:
	Convert(std::string const& str);
	~Convert();
	Convert(Convert const& other);
	Convert& operator=(Convert const& other);

	std::string const& getCharStr() const;
	std::string const& getIntStr() const;
	std::string const& getFloatStr() const;
	std::string const& getDoubleStr() const;

	void solve();

  private:

	static std::string impossible;

	void convertDoubleToStr_char();
	void convertDoubleToStr_int();
	void convertDoubleToStr_float();
	void convertDoubleToStr_double();

	void convertDoubleToStr_types();

	void convertStrToChar();
	void convertStrToDouble();

	void setNumericIndexes(int& numeric_head, int& numeric_tail);

	bool isNonNumericChar();

	void setImpossible();
	void setPseudoLiteral();
	bool isNumeric();
	bool isPseudoLiteral();

	void interpretCurrentType();

	Convert();
};

std::ostream& operator<<(std::ostream& os, Convert const& value);

#endif /* CONVERT_HPP */
