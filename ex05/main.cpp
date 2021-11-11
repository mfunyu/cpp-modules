/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:51:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 15:35:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

/* -------------------------------------------------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

void	print(std::string testName)
{
	std::cout << COLOR_CYAN << "[ " << testName << " ]"
				<< COLOR_RESET << std::endl;
}

/* -------------------------------------------------------------------------- */

int		main(void)
{
	Karen	karen;

	print("ERROR");
	karen.complain("ERROR");
	print("INFO");
	karen.complain("INFO");
	print("KO");
	karen.complain("KO");
	print("WARNING");
	karen.complain("WARNING");
	print("DEBUG");
	karen.complain("DEBUG");
	print("ok");
	karen.complain("ok");
	return 0;
}
