/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:42:16 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/21 19:21:13 by mfunyu           ###   ########.fr       */
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

  private:
	static std::string impossible;

	void storeStrAsDouble();

	void setCharStr();
	void setIntStr();
	void setFloatStr();
	void setDoubleStr();

	void setNumericIndexes(int& numeric_head, int& numeric_tail);

	void setImpossible();
	void setPseudoLiteral();

	static bool isPseudoLiteral(std::string s);
	static bool isNonNumericChar(std::string const& s);
	static bool isNumeric(std::string const& s);

	Convert();
};

std::ostream& operator<<(std::ostream& os, Convert const& value);

#endif /* CONVERT_HPP */
