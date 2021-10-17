/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:03:06 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/17 18:10:42 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
	Zombie( std::string name );
	~Zombie();
	void	announce( void );

private:
	std::string	_zombie_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
