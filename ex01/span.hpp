/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:05:20 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/29 14:47:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <iterator>

class Span
{
	std::multiset<int> _array;
	unsigned int	   _N;
	unsigned int	   _size;
	unsigned int	   _shortestSpan;
	unsigned int	   _longestSpan;

  public:
	Span(unsigned int N);
	~Span();
	Span(Span const& other);
	Span& operator=(Span const& other);

	void addNumber(int number);
	template <class RandomAccessIterator>
	void addNumber(RandomAccessIterator first, RandomAccessIterator last);

	unsigned int shortestSpan();
	unsigned int longestSpan();

	unsigned int			  getSize() const;
	unsigned int			  getMaxSize() const;
	std::multiset<int> const& getValues() const;

  private:
	Span();
};

template <class RandomAccessIterator>
void Span::addNumber(RandomAccessIterator first, RandomAccessIterator last)
{
	if (_size >= _N) {
		throw std::length_error("Span is full");
	}
	unsigned int len = std::distance(first, last);
	if (_size + len > _N) {
		throw std::length_error("Out of limits");
	}
	_size += len;
	_array.insert(first, last);
}


std::ostream& operator<<(std::ostream& os, Span const& span);

#endif /* SPAN_HPP */
