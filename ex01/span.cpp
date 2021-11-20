/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:15:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/20 13:28:04 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <stdexcept>

Span::~Span()
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Span::Span(unsigned int N) : _lst(N), _size(N), _last(0)
{
}

void	Span::addNumber(int number)
{
	if (_last == _size) {
		return ;
	}
	_lst[_last] = number;
	_last += 1;
}

int Span::shortestSpan()
{
	if (_size < 2) {
		throw std::range_error("no span to find");
	}
	int		diff = std::numeric_limits<int>::max();
	std::sort(_lst.begin(), _lst.end());
	for (unsigned int i = 1; i < _last; i++) {
		diff = std::min(diff, _lst[i] - _lst[i - 1]);
	}
	return diff;
}

int Span::longestSpan()
{
	if (_size < 2) {
		throw std::range_error("no span to find");
	}
	// std::vector<int>::iterator smallest = min_element(_lst.begin(), _lst.end());
	// std::vector<int>::iterator largest = min_element(_lst.begin(), _lst.end());
	// return largest - smallest;

	std::sort(_lst.begin(), _lst.begin() + _last);
	return _lst[_last - 1] - _lst[0];
}
