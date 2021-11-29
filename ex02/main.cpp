/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:33:07 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/29 16:47:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iomanip>
#include <iostream>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN	 "\033[36m"
#define COLOR_CYAN_T "\033[1;36m"
#define COLOR_CYAN_D "\033[2;36m"
#define COLOR_RESET	 "\033[0m"

namespace print {
void Header(std::string content)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN_T << "------------------ " << content
			  << " ------------------" << COLOR_RESET << std::endl;
}

void SubHeader(std::string content)
{
	std::cout << COLOR_CYAN_T << "\n*** " << content << " ***" << COLOR_RESET
			  << std::endl;
}

template <typename T>
void StackContents(MutantStack<T> const& stack, std::string const& msg)
{
	typename MutantStack<T>::const_iterator it	   = stack.begin();
	typename MutantStack<T>::const_iterator it_end = stack.end();

	std::cout << COLOR_CYAN_D << std::left << std::setw(7) << msg << ": ";
	for (; it != it_end; it++) {
		std::cout << "[" << *it << "]";
	}
	std::cout << COLOR_RESET << std::endl;
}

void Help()
{
	std::cout << "usage: ./a.out [testname]\n" << std::endl;
	std::cout << "  \"testnames\"" << std::endl;
	std::cout << "\tnone\t -> run the test on subject" << std::endl;
	std::cout << "\t\"all\"\t -> run all tests" << std::endl;
}
} // namespace print

/* -------------------------------------------------------------------------- */

int subject_main()
{
	print::Header("subject test");
	MutantStack<int> mstack;

	mstack.push(5); //[5]
	mstack.push(17); //[17] [5]

	std::cout << mstack.top() << std::endl; //[17] [5] -> 17

	mstack.pop(); // [5]

	std::cout << mstack.size() << std::endl; // 1

	mstack.push(3); //[3] [5]
	mstack.push(5); //[5] [3] [5]
	mstack.push(737); //[737] [5] [3] [5]
	//[...]
	mstack.push(0); //[0] [737] [5] [3] [5]

	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

namespace memberFuncs {
void test()
{
	print::Header("stack member functions");

	MutantStack<int> emptyStack;
	print::SubHeader("check constructor");
	MutantStack<int> intStack;
	print::StackContents(intStack, "initial");

	print::SubHeader("check operator=");
	MutantStack<int> intStack_copy;
	// intStack_copy = intStack;

	intStack.push(1);
	intStack.push(2);
	intStack.push(42);
	intStack.push(62);

	print::SubHeader("check operator=");
	MutantStack<int> intStack_copy;
	intStack_copy = intStack;
	print::SubHeader("check top()");
	print::StackContents(intStack, "before");
	std::cout << intStack.top() << std::endl;

	print::SubHeader("check empty()");
	print::StackContents(intStack, "instance");
	std::cout << intStack.empty() << std::endl;
	print::StackContents(emptyStack, "instance");
	std::cout << emptyStack.empty() << std::endl;

	print::SubHeader("check size()");
	print::StackContents(intStack, "instance");
	std::cout << intStack.size() << std::endl;
	print::StackContents(emptyStack, "instance");
	std::cout << emptyStack.empty() << std::endl;

	print::SubHeader("check push()");
	print::StackContents(intStack, "before");
	intStack.push(12);
	print::StackContents(intStack, "after");
	print::StackContents(intStack, "before");
	intStack.push(100000);
	print::StackContents(intStack, "after");
	print::StackContents(emptyStack, "before");
	emptyStack.push(-55);
	print::StackContents(emptyStack, "after");

	print::SubHeader("check pop()");
	print::StackContents(intStack, "before");
	intStack.pop();
	print::StackContents(intStack, "after");
	print::StackContents(intStack, "before");
	intStack.pop();
	print::StackContents(intStack, "after");
}
} // namespace memberFuncs

int main(int ac, char** av)
{
	try {
		std::string test = (ac > 1 ? av[1] : "");

		if (test.empty()) {
			subject_main();
		} else if (test == "all") {
			subject_main();
			memberFuncs::test();
		} else {
			print::Help();
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
