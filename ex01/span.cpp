/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:15:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/26 20:19:44 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : _N(N), _size(0), _shortestSpan(0), _longestSpan(0)
{}

Span::~Span() {}

Span::Span(Span const& other)
{
	*this = other;
}

Span& Span::operator=(Span const& other)
{
	if (this != &other) {
		_N = other._N;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_size >= _N) {
		throw std::length_error("Span is full");
	}
	_array.insert(number);
	_size += 1;
}

unsigned int Span::shortestSpan()
{
	if (_size < 2) {
		throw std::range_error("less than 2 members");
	}
	return _shortestSpan;
}

unsigned int Span::longestSpan()
{
	if (_size < 2) {
		throw std::range_error("less than 2 members");
	}
	return _longestSpan;
}
