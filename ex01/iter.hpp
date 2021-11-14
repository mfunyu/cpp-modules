/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:27:25 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 23:55:21 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T *addr, size_t len, void (*func)(T &))
{
	for (size_t i = 0; i < len; i++) {
		func(addr[i]);
	}
}

template <typename T>
void	iter(const T *addr, size_t len, void (*func)(const T &))
{
	for (size_t i = 0; i < len; i++) {
		func(addr[i]);
	}
}

#endif /* ITER_HPP */
