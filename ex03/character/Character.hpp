/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:55:52 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 22:55:53 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define MAX_MATERIALS 4

class AMateria;

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_inventory[MAX_MATERIALS];
		Character();

	public:
		~Character();
		Character(Character const &other);
		Character	&operator=(Character const &other);

		Character(std::string name);

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		static bool			is_idx_in_range(int idx);
};

#endif /* CHARACTER_HPP */
