/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:10:50 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/21 21:15:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <cstdint>
#include <iostream>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void	printHeader(std::string content)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN <<\
				 "*** " << content << " ***" <<\
				 COLOR_RESET << std::endl;
}

void	printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " ]" <<\
				 COLOR_RESET << std::endl;
}
} // namespace

/* -------------------------------------------------------------------------- */

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
		printHeader("Data test(\"test\");");

		Data	test("test");

		std::cout << "Ptr Before: " << &test << std::endl;
		std::cout << "func getContent() : " << \
					 test.getContent() << std::endl;

		printSubHeader("* serialize and deserialize *");
		uintptr_t	ptr = serialize(&test);
		Data*		deserialized = deserialize(ptr);

		std::cout << "Ptr After : " << deserialized << std::endl;
		std::cout << "func getContent() : " << \
					 deserialized->getContent() << std::endl;
	}
	{
		printHeader("Data* test = new Data(\"content\");");

		Data*	test = new Data("content");

		std::cout << "Ptr Before: " << test << std::endl;
		std::cout << "func getContent() : " << \
					 test->getContent() << std::endl;

		printSubHeader("* serialize and deserialize *");
		uintptr_t	ptr = serialize(test);
		Data*		deserialized = deserialize(ptr);

		std::cout << "Ptr After : " << deserialized << std::endl;
		std::cout << "func getContent() : " << \
					 deserialized->getContent() << std::endl;

		delete test;
	}
}
