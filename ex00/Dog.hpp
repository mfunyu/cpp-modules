/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:08:57 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 17:02:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:

	public:
		Dog();
		~Dog();
		Dog(Dog const &other);
		Dog	&operator=(Dog const &other);

		virtual void	makeSound() const;
};

#endif /* DOG_HPP */
