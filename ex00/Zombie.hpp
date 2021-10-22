/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:03:06 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/22 23:14:44 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie( std::string name );
		Zombie();
		~Zombie();
		void	nameZombie( std::string name );
		void	announce( void ) const;

	private:
		std::string	_name;
};

#endif
