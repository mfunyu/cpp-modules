/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:52:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/19 17:12:09 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "address: &str = " << &str << std::endl;
	std::cout << "address: stringPTR = " << stringPTR << std::endl;
	std::cout << "address: &stringREF = " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "content: str = " << str << std::endl;
	std::cout << "content: *stringPTR = " << *stringPTR << std::endl;
	std::cout << "content: stringREF = " << stringREF << std::endl;
	std::cout << std::endl;

	*stringPTR = "reset prt";
	std::cout << "content: str = " << str << std::endl;
	std::cout << "content: *stringPTR = " << *stringPTR << std::endl;
	std::cout << "content: stringREF = " << stringREF << std::endl;
	std::cout << std::endl;

	stringREF = "reset ref";
	std::cout << "content: str = " << str << std::endl;
	std::cout << "content: *stringPTR = " << *stringPTR << std::endl;
	std::cout << "content: stringREF = " << stringREF << std::endl;
	std::cout << std::endl;

	return 0;
}
