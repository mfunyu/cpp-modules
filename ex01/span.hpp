/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:05:20 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/20 12:39:49 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	private:
		std::vector<int> _lst;
		unsigned int _size;
		unsigned int _last;
		Span();

	public:
		~Span();
		Span(Span const &other);
		Span	&operator=(Span const &other);

		Span(unsigned int N);

		void	addNumber(int number);

		int		shortestSpan();
		int		longestSpan();
};

#endif /* SPAN_HPP */
