/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:05:20 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/28 18:19:09 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

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

	unsigned int shortestSpan();
	unsigned int longestSpan();

	unsigned int getSize() const;
	unsigned int getMaxSize() const;

  private:
	Span();
};


std::ostream& operator<<(std::ostream & os, Span const& span);

#endif /* SPAN_HPP */
