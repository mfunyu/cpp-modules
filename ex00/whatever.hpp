/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:02:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/07 18:14:09 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& x, T& y)
{
	T	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const &	min(T const & x, T const & y)
{
	return (x < y ? x : y);
}

template <typename T>
T const &	max(T const & x, T const & y)
{
	return (x > y ? x : y);
}

#endif /* WHATEVER_HPP */
