/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:44:55 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/06 23:58:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "instance of A created" << std::endl;
			return new A;
		case 1:
			std::cout << "instance of B created" << std::endl;
			return new B;
		default:
			std::cout << "instance of C created" << std::endl;
			return new C;
	}
	return NULL;
}

void	identify(Base* p)
{
	A*	a = dynamic_cast<A *>(p);
	if (a) {
		std::cout << "A" << std::endl;
		return ;
	}

	B*	b = dynamic_cast<B *>(p);
	if (b) {
		std::cout << "B" << std::endl;
		return ;
	}

	C*	c = dynamic_cast<C *>(p);
	if (c) {
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Unknown Type" << std::endl;
}

void	identify(Base& p)
{
	try {
		A	a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast) {
		try {
			B	b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		} catch (std::bad_cast) {
			try {
				C	c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			} catch (std::bad_cast) {
				std::cout << "Unknown Type" << std::endl;
			}
		}
	}
}

int		main()
{
	std::srand(time(NULL));

	Base*	random = generate();

	std::cout << "void identify(Base* p) : ";
	identify(random);

	std::cout << "void identify(Base& p) : ";
	identify(*random);

	delete random;
}
