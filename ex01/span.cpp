/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:15:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/28 18:43:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <iostream>
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
	_array.insert(number);
}

unsigned int Span::shortestSpan()
{
	if (_size < 2) {
		throw std::range_error("shortestSpan: less than 2 members");
	}

	std::multiset<int>::iterator it_now	 = _array.begin();
	std::multiset<int>::iterator it_end	 = _array.end();
	std::multiset<int>::iterator it_next = it_now;
	it_next++;

	unsigned int diff;
	for (; it_next != it_end; it_next++) {
		diff		  = *it_next - *it_now;
		_shortestSpan = std::min(_shortestSpan, diff);
		it_now++;
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

std::ostream& operator<<(std::ostream& os, Span const& span)
{
	os << "< size = " << span.getSize() << ", max_size = " << span.getMaxSize()
	   << " >";
	return os;
}
