/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:10:50 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/07 00:02:14 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <cstdint>
#include <iostream>

/****************** FOR PRINT and FORMATTING ******************/

# define SET_COLOR "\033[36m"
# define RESET_COLOR "\033[m"

void	printTestInfo(std::string testContent)
{
	std::cout << SET_COLOR "/*** Test: " << testContent <<\
				" ***/" RESET_COLOR << std::endl;
}

/******************    Requied Functions    ******************/

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int		main()
{
	{
		printTestInfo("Data test(\"test\");");

		Data	test("test");

		std::cout << "Ptr Before: " << &test << std::endl;

		uintptr_t	ptr = serialize(&test);
		Data*		deserialized = deserialize(ptr);

		std::cout << "Ptr After : " << deserialized << std::endl;

		std::cout << "func getContent() : " << \
					 deserialized->getContent() << std::endl;
	}
	std::cout << std::endl;
	{
		printTestInfo("Data* test = new Data(\"content\");");

		Data*	test = new Data("content");

		std::cout << "Ptr Before: " << test << std::endl;

		uintptr_t	ptr = serialize(test);
		Data*		deserialized = deserialize(ptr);

		std::cout << "Ptr After : " << deserialized << std::endl;

		std::cout << "func getContent() : " << \
					 deserialized->getContent() << std::endl;

		delete test;
	}
}
