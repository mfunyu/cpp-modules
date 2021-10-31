/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:48:50 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 14:50:21 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class IMateriaSource
{
	public:
		IMateriaSource();
		virtual ~IMateriaSource() {}
		IMateriaSource(IMateriaSource const &other);
		IMateriaSource	&operator=(IMateriaSource const &other);

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif /* IMATERIASOURCE_HPP */
