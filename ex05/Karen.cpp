/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:50:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 15:32:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

Karen::Karen() {}

Karen::~Karen() {}

void	Karen::complain( std::string level ) {
	struct complain_types	type_lst[5] = {
		{"DEBUG", &Karen::debug},
		{"INFO", &Karen::info},
		{"WARNING", &Karen::warning},
		{"ERROR", &Karen::error},
		{"", &Karen::nop},
	};

	int	i = 0;
	while (i < 4 && level != type_lst[i].level) {
		i++;
	}
	(this->*type_lst[i].FuncPtr)();
}

void	Karen::debug( void ) {
	std::cout << "DEBUG I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info( void ) {
	std::cout << "INFO I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning( void ) {
	std::cout << "WARNING I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error( void ) {
	std::cout << "ERROR This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::nop( void ) {
	return ;
}
