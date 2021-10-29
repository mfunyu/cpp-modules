/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:52:38 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 13:16:53 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

# define ST_HIT_P 100
# define ST_ENERGY_P 50
# define ST_ATTACK_D 20

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap	&operator=(const ScavTrap &other);

		ScavTrap(std::string name);

		void	attack(std::string const &target);
		void	guardGate();
};

#endif /* SCAVTRAP_HPP */
