/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:08:57 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:09:15 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*		_brain;

	public:
		Dog();
		virtual ~Dog();
		Dog(Dog const &other);
		Dog	&operator=(Dog const &other);

		virtual void	makeSound() const;

		std::string const &	getBrainIdea(unsigned int i) const;
		void				setBrainIdea(unsigned int i, std::string idea);
};

#endif /* DOG_HPP */
