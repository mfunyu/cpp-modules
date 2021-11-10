/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:31:07 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 19:58:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "iter.hpp"

namespace {
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

void	strToUpper(std::string const & str)
{
	std::locale	locale;

	for (int i = 0; str[i]; i++) {
		std::cout << std::toupper(str[i], locale);
	}
	std::cout << std::endl;
}

void	printLst(std::string const* lst)
{
	for (int i = 0; !lst[i].empty(); i++) {
		std::cout << "[" << i << "]: " << lst[i] << std::endl;
	}
}

void	print(std::string testName)
{
	std::cout << COLOR_CYAN << testName
				<< COLOR_RESET << std::endl;
}
} /* namespace */

int		main()
{
	{
		std::string		str[4] = { "aaaaaaaaa",
									"bbbbbbbbb",
									"ccccccccc",
								};
		print("[ Before ]");
		printLst(str);
		print("** Call func **");
		iter<std::string>(str, 3, strToUpper);
		print("[ After ]");
		printLst(str);
	}
	std::cout << std::endl;
	{
		const std::string	const_str[4] = { "aaaaaaaaa",
									"bbbbbbbbb",
									"ccccccccc",
								};

		print("[ Before ]");
		printLst(const_str);
		print("** Call func **");
		iter<const std::string>(const_str, 3, strToUpper);
		print("[ After ]");
		printLst(const_str);
	}
}
