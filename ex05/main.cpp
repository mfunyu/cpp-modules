/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:51:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 17:01:13 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main(void)
{
	Karen	karen;

	karen.complain("error");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("debug");

	karen.complain("warning");
	karen.complain("info");
	karen.complain("error");
	karen.complain("debug");
	return 0;
}
