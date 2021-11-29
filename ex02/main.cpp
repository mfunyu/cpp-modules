/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:33:07 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/29 15:29:56 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
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

/*
void	SubHeader(std::string content)
{
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " ]" <<\
				 COLOR_RESET << std::endl;
}
*/

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

int main(int ac, char** av)
{
	std::string test = (ac > 1 ? av[1] : "");

	if (test.empty()) {
		subject_main();
	} else if (test == "all") {
		subject_main();
	} else {
		print::Help();
	}
}
