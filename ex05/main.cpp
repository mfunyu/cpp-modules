/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:51:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/24 00:17:55 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main(void)
{
	Karen	karen;

	karen.complain("ERROR");
	karen.complain("INFO");
	karen.complain("KO");
	karen.complain("WARNING");
	karen.complain("DEBUG");
	karen.complain("ok");
	return 0;
}
