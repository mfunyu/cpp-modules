/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:52:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 14:39:19 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/* -------------------------------------------------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

void	print(std::string testName)
{
	std::cout << std::endl << COLOR_CYAN
				<< "** " << testName << " **"
				<< COLOR_RESET << std::endl;
}

/* -------------------------------------------------------------------------- */

int		main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	print("Address of each variables");
	std::cout << "address: &str = " << &str << std::endl;
	std::cout << "address: stringPTR = " << stringPTR << std::endl;
	std::cout << "address: &stringREF = " << &stringREF << std::endl;

	print("Content of each variables");
	std::cout << "content: str = " << str << std::endl;
	std::cout << "content: *stringPTR = " << *stringPTR << std::endl;
	std::cout << "content: stringREF = " << stringREF << std::endl;

	print("Change: *stringPTR = \"reset prt\"");
	*stringPTR = "reset prt";
	std::cout << "content: str = " << str << std::endl;
	std::cout << "content: *stringPTR = " << *stringPTR << std::endl;
	std::cout << "content: stringREF = " << stringREF << std::endl;

	print("Change: stringPTR = \"reset ref\"");
	stringREF = "reset ref";
	std::cout << "content: str = " << str << std::endl;
	std::cout << "content: *stringPTR = " << *stringPTR << std::endl;
	std::cout << "content: stringREF = " << stringREF << std::endl;

	return 0;
}
