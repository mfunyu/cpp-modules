/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:45:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/06 20:45:35 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _content("empty")
{
}

Data::~Data()
{
}

Data::Data(const Data &other)
{
	*this = other;
}

Data	&Data::operator=(const Data &other)
{
	if (this != &other)
	{
		_content = other._content;
	}
	return *this;
}

Data::Data(std::string const & content) : _content(content)
{
}

std::string const&	Data::getContent()
{
	return _content;
}
