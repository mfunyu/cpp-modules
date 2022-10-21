/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:44:55 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/21 21:35: by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN	"\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void printHeader(std::string content)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN << "*** " << content << " ***" << COLOR_RESET
			  << std::endl;
}
} // namespace

/* -------------------------------------------------------------------------- */

Base* generate(void)
{
	switch (std::rand() % 3) {
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

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a) {
		std::cout << "A" << std::endl;
		return;
	}

	B* b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << "B" << std::endl;
		return;
	}

	C* c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p)
{
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast) {
		try {
			B b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (std::bad_cast) {
			try {
				C c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::bad_cast) {
				std::cout << "Unknown Type" << std::endl;
			}
		}
	}
}

/* ---------------------------------- tests --------------------------------- */

void call_identifies(Base* anonymised)
{
	std::cout << "void identify(Base* p) : ";
	identify(anonymised);

	std::cout << "void identify(Base& p) : ";
	identify(*anonymised);
}

int main()
{
	std::srand(time(NULL));

	printHeader("Class A");
	Base* a = new A();
	call_identifies(a);
	delete a;

	printHeader("Class B");
	Base* b = new B();
	call_identifies(b);
	delete b;

	printHeader("Class C");
	Base* c = new C();
	call_identifies(c);
	delete c;

	printHeader("random()");
	Base* random = generate();
	call_identifies(random);
	delete random;
}
