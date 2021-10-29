/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTraprap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:52:38 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 00:46:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class DiamondTrap : public ClapTrap
{
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap	&operator=(const DiamondTrap &other);

		DiamondTrap(std::string name);
};

#endif /* DiamondTrap_HPP */
