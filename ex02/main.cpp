/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:33:07 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/29 23:17:41 by mfunyu           ###   ########.fr       */
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

void SubHeader(std::string const content)
{
	std::cout << COLOR_CYAN_T << "\n*** " << content << " ***" << COLOR_RESET
			  << std::endl;
}

void Comment(std::string const content)
{
	std::cout << COLOR_CYAN_D << "--- " << content << " ---" << COLOR_RESET
			  << std::endl;
}

template <typename T>
void StackContents(MutantStack<T> const& stack, std::string const& msg,
	std::string color = COLOR_CYAN_D)
{
	typename MutantStack<T>::const_iterator it	   = stack.begin();
	typename MutantStack<T>::const_iterator it_end = stack.end();

	std::cout << color << std::left << std::setw(8) << msg << ": ";
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

template <typename T>
MutantStack<T> createAStack(unsigned int size)
{
	MutantStack<T> newStack;

	for(unsigned int i = 0; i < size; i++)
	{
		newStack.push(std::rand() % 100);
	}
	return newStack;
}

namespace memberFuncs {
template <typename T>
void checkPop(MutantStack<T> & testStack)
{
	print::StackContents(testStack, "before");
	testStack.pop();
	print::Comment("pop()");
	print::StackContents(testStack, "after", COLOR_CYAN);
}

template <typename T>
void checkPush(MutantStack<T> & testStack, int value)
{
	print::StackContents(testStack, "before");
	testStack.push(value);
	print::Comment("push(value)");
	print::StackContents(testStack, "after", COLOR_CYAN);
}

template <typename T>
void checkSize(MutantStack<T> const & testStack)
{
	print::StackContents(testStack, "instance");
	std::cout << testStack.size() << std::endl;
}

template <typename T>
void checkEmpty(MutantStack<T> const & testStack)
{
	print::StackContents(testStack, "instance");
	std::cout << testStack.empty() << std::endl;
}

template <typename T>
void checkTop(MutantStack<T> const & testStack)
{
	print::StackContents(testStack, "before");
	std::cout << testStack.top() << std::endl;
}

template <typename T>
void checkCopy(MutantStack<T> const & testStack)
{
	MutantStack<int> testStack_copy;
	testStack_copy = testStack;
	print::StackContents(testStack, "original", COLOR_CYAN);
	print::StackContents(testStack_copy, "copy", COLOR_CYAN);
	testStack_copy.push(0);
	print::Comment("alterated copied object");
	print::StackContents(testStack, "original", COLOR_CYAN);
	print::StackContents(testStack_copy, "copy", COLOR_CYAN);
}

template <typename T>
void checkConstructor()
{
	MutantStack<int> intStack;
	print::StackContents(intStack, "initial", COLOR_CYAN);
}

void test()
{
	print::Header("stack member functions");

	MutantStack<int> intStack = createAStack<int>(5);
	MutantStack<int> emptyStack = createAStack<int>(0);

	print::SubHeader("check constructor");
	checkConstructor<int>();

	print::SubHeader("check operator=");
	checkCopy(intStack);

	print::SubHeader("check top()");
	checkTop(intStack);

	print::SubHeader("check empty()");
	checkEmpty(intStack);
	checkEmpty(emptyStack);

	print::SubHeader("check size()");
	checkSize(intStack);
	checkSize(emptyStack);

	print::SubHeader("check push()");
	checkPush(intStack, 100);
	checkPush(intStack, 100000);
	checkPush(emptyStack, -20);

	print::SubHeader("check pop()");
	checkPop(intStack);
	checkPop(intStack);
	checkPop(intStack);
}
} // namespace memberFuncs

namespace iterators {

template <typename T, typename Inputiterator>
void checkContent(MutantStack<T> const& intStack, Inputiterator it)
{
	print::StackContents(intStack, "instance");
	std::cout << "*it: " << *it << std::endl;
}

template <typename T, typename Inputiterator>
void assignValue(MutantStack<T> const& intStack, Inputiterator it, int value)
{
	print::StackContents(intStack, "before");
	*it = value;
	print::Comment("*ite = value");
	print::StackContents(intStack, "after", COLOR_CYAN);
}

void test()
{
	print::Header("iterator test");
	MutantStack<int> intStack = createAStack<int>(7);

	print::SubHeader("check begin()");
	checkContent(intStack, intStack.begin());
	checkContent(intStack, ++intStack.begin());
	checkContent(intStack, intStack.begin() + 2);
	assignValue(intStack, intStack.begin(), 42);

	print::SubHeader("check end()");
	checkContent(intStack, --intStack.end());
	checkContent(intStack, intStack.end() - 2);
	checkContent(intStack, intStack.end() - 3);
	assignValue(intStack, --intStack.end(), 1000);

	print::SubHeader("check rbegin()");
	checkContent(intStack, intStack.rbegin());
	checkContent(intStack, ++intStack.rbegin());
	checkContent(intStack, intStack.rbegin() + 2);
	assignValue(intStack, intStack.rbegin(), -2);

	print::SubHeader("check rend()");
	checkContent(intStack, --intStack.rend());
	checkContent(intStack, intStack.rend() - 2);
	checkContent(intStack, intStack.rend() - 3);
	assignValue(intStack, --intStack.rend(), 0);

	print::SubHeader("check const begin()");
	MutantStack<int>::const_iterator begin = intStack.begin();
	checkContent(intStack, begin);
	checkContent(intStack, ++begin);
	checkContent(intStack, ++begin);
	// assignValue(intStack, begin, 42);

	print::SubHeader("check const end()");
	MutantStack<int>::const_iterator end = intStack.end();
	checkContent(intStack, --end);
	checkContent(intStack, --end);
	checkContent(intStack, --end);
	// assignValue(intStack, --end, 1000);

	print::SubHeader("check const rbegin()");
	MutantStack<int>::const_reverse_iterator rbegin = intStack.rbegin();
	checkContent(intStack, rbegin);
	checkContent(intStack, ++rbegin);
	checkContent(intStack, ++rbegin);
	// assignValue(intStack, rbegin, 42);

	print::SubHeader("check const rend()");
	MutantStack<int>::const_reverse_iterator rend = intStack.rend();
	checkContent(intStack, --rend);
	checkContent(intStack, --rend);
	checkContent(intStack, --rend);
	// assignValue(intStack, rend, 42);
}
} // namespace iterators

int main(int ac, char** av)
{
	try {
		std::srand(time(NULL));
		std::string test = (ac > 1 ? av[1] : "");

		if (test.empty()) {
			subject_main();
		} else if (test == "all") {
			subject_main();
			memberFuncs::test();
			iterators::test();
		} else {
			print::Help();
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
