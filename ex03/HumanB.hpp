/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:21:18 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 13:05:02 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
	public:
		HumanB(std::string name, std::string type);
		HumanB();
		~HumanB();
		void			attack();

	private:
		Weapon			_weapon;
		std::string		_name;
};

#endif
