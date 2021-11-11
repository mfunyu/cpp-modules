/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:07:12 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 12:26:56 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

int		main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Error: invalid arguments" << std::endl;
		std::exit(1);
	}
	
	Replace	replace(av[1], av[2], av[3]);
	replace.exec();

	return 0;
}
