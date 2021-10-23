/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:07:12 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 16:42:21 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	replace(std::string filename, std::string s1, std::string s2);

int		main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "filename required" << std::endl;
		return 0;
	}

	std::string		filename = av[1];
	std::string		s1;
	std::string		s2;

	if (ac > 3) {
		/* from argv */
		s1 = av[2];
		s2 = av[3];
	} else {
		s1 = ")\n";
		s2 = "\t0000000000000000\t";
	}

	replace(filename, s1, s2);
	return 0;
}
