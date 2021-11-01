/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:49:00 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/01 17:39:13 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class AMateria;
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string		_type;

	public:
		AMateria();
		virtual ~AMateria();
		AMateria(std::string const & type);

		std::string const&	getType() const; //Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif /* AMATERIA_HPP */
