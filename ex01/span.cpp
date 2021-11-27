/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:15:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/27 14:14:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) :
	_N(N), _size(0), _shortestSpan(std::numeric_limits<unsigned int>::max()),
	_longestSpan(0)
{}

Span::~Span() {}

Span::Span(Span const& other) :
	_N(other._N), _size(other._size), _shortestSpan(other._shortestSpan),
	_longestSpan(other._longestSpan)
{
	_array = other._array;
}

Span& Span::operator=(Span const& other)
{
	if (this != &other) {
		_array		  = other._array;
		_N			  = other._N;
		_size		  = other._size;
		_shortestSpan = other._shortestSpan;
		_longestSpan  = other._longestSpan;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_size >= _N) {
		throw std::length_error("Span is full");
	}
	_size += 1;

	if (_size >= 2) {
		std::multiset<int>::iterator next_value = _array.lower_bound(number);
		if (next_value != _array.end()) {
			unsigned int diff = *next_value;
			diff -= number;
			_shortestSpan
				= std::min(_shortestSpan, static_cast<unsigned int>(diff));
		}
	}
	_array.insert(number);
}

unsigned int Span::shortestSpan()
{
	if (_size < 2) {
		throw std::range_error("shortestSpan: less than 2 members");
	}
	return _shortestSpan;
}

unsigned int Span::longestSpan()
{
	if (_size < 2) {
		throw std::range_error("lengestSpan: less than 2 members");
	}
	_longestSpan = *(_array.rbegin()) - *(_array.begin());
	return _longestSpan;
}

unsigned int Span::getSize() const
{
	return _size;
}

unsigned int Span::getMaxSize() const
{
	return _N;
}
