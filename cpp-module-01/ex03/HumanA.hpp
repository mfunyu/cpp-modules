/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:21:18 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 14:52:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;
		HumanA();

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void	attack();
};

#endif /* HUMANA_HPP */
