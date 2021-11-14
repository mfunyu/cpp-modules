/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:52:38 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 16:47:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{
	private:
		static const unsigned int	_initialHitPoints = 100;
		static const unsigned int	_initialEnergyPoints = 50;
		static const unsigned int	_initialAttackDamage = 20;

	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap	&operator=(const ScavTrap &other);

		ScavTrap(std::string name);

		void	attack(std::string const &target);
		void	guardGate();

		void	showStatus(void);
};

#endif /* SCAVTRAP_HPP */
