/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:52:38 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/15 23:24:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public virtual ClapTrap
{
	protected:
		static const unsigned int	_initialHitPoints = 100;
		static const unsigned int	_initialEnergyPoints = 100;
		static const unsigned int	_initialAttackDamage = 30;

	public:
		FragTrap();
		virtual ~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);

		FragTrap(std::string name);

		void			highFivesGuys(void);

		virtual void	showStatus(void);
};

#endif /* FragTrap_HPP */
