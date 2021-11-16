/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:51:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 23:00:47 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	private:

	public:
		Ice();
		~Ice();
		Ice(Ice const &other);
		Ice	&operator=(Ice const &other);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif /* ICE_HPP */
