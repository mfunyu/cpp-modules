/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:27:25 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 19:59:04 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename U, typename F>
void	iter(T *addr, U len, F func)
{
	for (U i = 0; i < len; i++) {
		func(addr[i]);
	}
}

#endif /* ITER_HPP */
