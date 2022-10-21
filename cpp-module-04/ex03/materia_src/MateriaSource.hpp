/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:14 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 23:08:38 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);

		void		learnMateria(AMateria* a);
		AMateria*	createMateria(std::string const & type);

		static const int	kMaxMaterials = 4;

	private:
		AMateria*	_memory[kMaxMaterials];
};

#endif /* MATERIASOURCE_HPP */
