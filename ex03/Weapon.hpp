/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:19:11 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 14:47:15 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		std::string&	getType();
		void			setType(std::string type);

	private:
		std::string		_type;

};


#endif
