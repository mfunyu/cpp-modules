/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:09:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 12:37:50 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*		_brain;

	public:
		Cat();
		~Cat();
		Cat(Cat const &other);
		Cat	&operator=(Cat const &other);

		virtual void	makeSound() const;

		std::string		getBrainIdea(unsigned int i) const;
		void			setBrainIdea(unsigned int i, std::string idea);
};

#endif /* CAT_HPP */
