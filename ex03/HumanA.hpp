/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:21:18 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 13:03:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
	public:
		HumanA(std::string name, std::string type);
		HumanA();
		~HumanA();
		void			attack();

	private:
		Weapon			_weapon;
		std::string		_name;
};

#endif
