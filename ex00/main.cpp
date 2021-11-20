/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:34:26 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/20 16:28:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

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

void	printSubHeader(std::string content, int nbr)
{
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " " << nbr << " ]" <<\
				 COLOR_RESET << std::endl;
}
} // namespace

/* -------------------------------------------------------------------------- */

void lst_test(int nbr)
{
	printSubHeader("int_lst", nbr);

	int		max_len = 500;
	std::list<int> int_lst(max_len);
	for (int i = 0; i < max_len; i++) {
		int_lst.push_back(i);
	}

	std::cout << "result : ";
	try {
		std::cout << easyfind(int_lst, nbr) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void vec_test(int nbr)
{
	printSubHeader("int_vec", nbr);

	int		max_len = 500;
	std::vector<int> int_vec(max_len);
	for (int i = 0; i < max_len; i++) {
		int_vec[i] = i;
	}

	std::cout << "result : ";
	try {
		std::cout << easyfind(int_vec, nbr) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	printHeader("List Tests");
	lst_test(1);
	lst_test(5);
	lst_test(1000);

	printHeader("Vector Tests");
	vec_test(12);
	vec_test(100);
	vec_test(-1);
}
