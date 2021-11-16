/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 22:56:02 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		~Cure();
		Cure(Cure const &other);
		Cure	&operator=(Cure const &other);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif /* CURE_HPP */
