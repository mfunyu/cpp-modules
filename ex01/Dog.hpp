/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:08:57 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 13:09:53 by mfunyu           ###   ########.fr       */
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
		~Dog();
		Dog(Dog const &other);
		Dog	&operator=(Dog const &other);

		virtual void	makeSound() const;

		std::string		getBrainIdea(unsigned int i) const;
		void			setBrainIdea(unsigned int i, std::string idea);
};

#endif /* DOG_HPP */
