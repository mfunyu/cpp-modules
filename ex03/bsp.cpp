/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:39:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/13 23:38:19 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ab;
	Fixed	bc;
	Fixed	ca;

	ab = (point - a).crossP(b - a);
	bc = (point - b).crossP(c - b);
	ca = (point - c).crossP(a - c);

	if (ab < 0 && bc < 0 && ca < 0) {
		return true;
	} else if (ab > 0 && bc > 0 && ca > 0) {
		return true;
	}
	return false;
}
