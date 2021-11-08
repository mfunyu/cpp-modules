/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:45:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/08 09:43:09 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

namespace {
	void	strToUpper(std::string const & str)
	{
		std::locale	locale;

		for (int i = 0; str[i]; i++) {
			std::cout << std::toupper(str[i], locale);
		}
	}
} /* namespace */

int main(int ac, char **av)
{
	if (ac <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; av[i]; i++) {
		strToUpper(av[i]);
	}
	std::cout << std::endl;

	return 0;
}
