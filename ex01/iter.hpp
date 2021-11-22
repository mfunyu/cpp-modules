/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:27:25 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/22 14:41:37 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T* addr, std::size_t len, void (*func)(T&))
{
	for (std::size_t i = 0; i < len; i++) {
		func(addr[i]);
	}
}

template <typename T>
void iter(const T* addr, std::size_t len, void (*func)(const T&))
{
	for (std::size_t i = 0; i < len; i++) {
		func(addr[i]);
	}
}

#endif /* ITER_HPP */
