/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:03:06 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 11:32:21 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		~Zombie();
		Zombie( std::string name );
		void	nameZombie( std::string name );
		void	announce( void ) const;
};

#endif /* ZOMBIE_HPP */
