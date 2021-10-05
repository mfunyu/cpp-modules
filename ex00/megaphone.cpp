/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:45:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/05 21:41:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int	i = 1;
		while (av[i])
		{
			std::cout << av[i] << std::endl;
			for (int j = 0; av[i][j]; j++)
				std::cout << std::toupper(av[i][j], std::locale());
			i++;
		}
		std::cout << std::endl;
	}
}
